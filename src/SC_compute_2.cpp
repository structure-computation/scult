#ifdef METIL_COMP_DIRECTIVE
    #pragma gpu_flag --compiler-options -fpermissive
#endif


#include <Metil/BasicVec.h>
#include <Metil/StructCompactor.h>
#include <Metil/CudaMetil.h>
#include <Metil/Hdf.h>
using namespace Metil;

#include "GeometryUser.h"
#include "GeometryCompact.h"
#include "FieldStructureUser.h"
#include "FieldStructureCompact.h"
#include "DataUser.h"
#include "DataReader.h"

int main( int argc, char **argv ) {
    if ( argc!=3 ) {
        std::cerr << "usage : SC_compute_2_$arch_$dimension.exe +  numero_du_modele + numero_du_calcul" << std::endl;
        std::cerr << "ex : ./SC_compute_2_GPU_3.exe 10 2 " << std::endl;
        return 1;
    }
    
    // ######################
    // TODO initialisation de MPI
    // ######################
    
    static const int dim = DIM;
    Sc2String id_model = argv[ 1 ];
    Sc2String id_calcul = argv[ 2 ];
     
    // ******************************************************************************************************************
    //lecture des données utilisateur (fichier de calcul .json) et compilation à la volée 
    DataUser data_user(id_model, id_calcul);
    data_user.read_json_calcul();
    DataReader *data_reader;
    data_reader = data_user.NEW_DataReader( );

    // ******************************************************************************************************************
    //lecture des tags de la geometrie equilibrage MPI--------------------------------------------------
    GeometryUser geometry_user(id_model, id_calcul);
    geometry_user.read_hdf5(false, false);                    

    // ######################
    // TODO equilibrage de poid des group element sur chaqe proc pour MPI 
    // TODO MPI barriere 
    // ######################
    
    //lecture des données de la geometrie équilibré / MPI--------------------------------------------------
    geometry_user.read_hdf5(true, true);   
    geometry_user.split_group_edges_within_geometry(data_user);
    //geometry_user.affiche();
    
    //création de la structure compactée de geometrie -------------------------
    geometry_user.initialize_GPU();
    Ps<GeometryCompactClass> geometry_compact_CPU = make_cs( &geometry_user, 1, MachineId::cpu() );
    Ps<GeometryCompactClass> geometry_compact_GPU = strdup( geometry_compact_CPU, MachineId::cpu( 0 )->gpu( 0 ) );
     
    
    // ******************************************************************************************************************
    //creation des field ---------------------------------------------------------------------------------
    FieldStructureUser field_structure_user(geometry_user);
    field_structure_user.assign_material_id_to_group_elements(data_user);
    field_structure_user.assign_link_id_to_group_interfaces(data_user);
    field_structure_user.assign_bc_id_to_group_interfaces(data_user);
    
    //calcul de side_N et side_M pour la strategie micro -------------------------------------------------
//     launch_calculate_side_N_M_CPU(geometry_compact_CPU);
//     launch_calculate_side_N_M_GPU(geometry_compact_CPU, geometry_compact_GPU);
//     memcpy( geometry_compact_CPU, geometry_compact_GPU);
    
    //calcul de Ne et Me pour la strategie multi   -------------------------------------------------------
//     PRINT("calcul N M");
//     launch_calculate_interface_N_M_CPU(geometry_compact_CPU);
    //calcul de la mesure des groupes d'interfaces -------------------------------------------------------
//     calculate_measure( geometry_compact_CPU , geometry_user );    
    //TODO calcul des operateurs macro sur chaque groupe
    

    //création de la structure compactée à partir de FieldStructure --------------------------------------
    field_structure_user.initialize_GPU();
    Ps<FieldStructureCompactClass> field_structure_compact_CPU = make_cs( &field_structure_user, 1, MachineId::cpu() );
    Ps<FieldStructureCompactClass> field_structure_compact_GPU = strdup( field_structure_compact_CPU, MachineId::cpu( 0 )->gpu( 0 ) ); 
   
    // lecture et assignation des proprietes générique des groupes
    launch_calculate_elements_center_GPU(geometry_compact_CPU, geometry_compact_GPU, field_structure_compact_GPU);

    
    
    // ******************************************************************************************************************
    // strategie de résolution itérative ------------------------------------------------------------------
//     PRINT(field_structure_compact_CPU->group_elements[0].mat_prop[0]);
    
    // ######################
    // TODO MPI barriere
    // ######################
    
    // boucle multiresolution ...........................................................................................
    for(int i_res=0; i_res<data_user.options.Multiresolution_nb_cyle; i_res++){         
        // calcul des propriété materiaux et interfaces
        data_reader->launch_read_data_materials_group_elements(field_structure_compact_CPU, field_structure_compact_GPU, i_res, 0);
        data_reader->launch_read_data_links_group_interfaces(field_structure_compact_CPU, field_structure_compact_GPU, i_res, 0);
        // TODO calul des opérateurs élémentaires  --GPU
        // launch_calculate_elements_mat_elem_GPU(geometry_compact_CPU, geometry_compact_GPU, field_structure_compact_GPU);
        // TODO calul desdirections de recherche sur les interfaces  --GPU
        
        // copy CPU <-  GPU
        // memcpy( field_structure_compact_CPU, field_structure_compact_GPU);
        // TODO assemblage de la matrice globale   --CPU
        
        // ######################
        // TODO MPI barriere + copie
        // ######################
        
        // TEST boucle sur step temporels ...............................................................................
        for(int t_step=0; t_step<1; t_step++){    
            // TEST boucle sur les pas de temps : on ne considere que les step 0 en template.............................
            for(int t=0; t<1; t++){                                                     
                // lecture et assignation des conditions limites et efforts volumiques  --GPU
                data_reader->launch_read_data_bc_volume_group_elements(field_structure_compact_CPU, field_structure_compact_GPU, i_res, t_step, t);
                data_reader->launch_read_data_bc_group_interfaces(field_structure_compact_CPU, field_structure_compact_GPU, i_res, t_step, t);
                
                // ######################
                // TODO MPI barriere + copie
                // ######################
                // boucle LATIN..........................................................................................
                TYPE erreur;
                while(erreur > data_user.options.LATIN_crit_error){
                    // etape globale --------------------------------------------------
                    
                    // copy CPU <-  GPU
                    memcpy( field_structure_compact_CPU, field_structure_compact_GPU);
                    // TODO assemblage du second membre  --CPU
                    // TODO résolution du probleme lineaire sur les group_elements --CPU
                    
                    
                    // ######################
                    // TODO MPI barriere + copie
                    // ######################
                    
                    // etape locale ---------------------------------------------------
                    // TODO MPI barriere et mise a jour des champs d'interfaces
                    // copy CPU ->  GPU
                    // memcpy( field_structure_compact_GPU, field_structure_compact_CPU);
                    // TODO projection sur les interfaces  --GPU
                    // TODO calcul des comportements sur les interface micro 1   --GPU
                    // copy CPU <-  GPU
                    // memcpy( field_structure_compact_CPU, field_structure_compact_GPU);
                    // TODO assemblage second membre macro  --CPU
                    // TODO resolution problème macro --CPU
                    // copy CPU ->  GPU
                    // memcpy( field_structure_compact_GPU, field_structure_compact_CPU);
                    // TODO calcul des comportements sur les interface micro 2   --GPU
                    // TODO calcul dede l'erreur LATIN   --GPU
                    
                    // ######################
                    // TODO MPI barriere + copie
                    // ######################
                    
                }
                memcpy( field_structure_compact_CPU, field_structure_compact_GPU);
                // post traitements -----------------------------------------------------
                // TODO postraitement des contraintes --GPU
                // TODO postraitement de l'erreur RDC --GPU
                // copy CPU <-  GPU
                // memcpy( field_structure_compact_CPU, field_structure_compact_GPU);
                
                // ######################
                // TODO MPI barriere + copie de tout sur le node 0
                // ######################
                
                // enregistrement seulement le noeud 0-----------------------------------
                // TODO enregistrement hdf pas de temps t
            }   
        }
    }
//     PRINT(field_structure_compact_CPU->group_elements[0].mat_prop[0]);
//     PRINT(field_structure_compact_CPU->group_elements[0].volumic_force[0]);
//     PRINT(field_structure_compact_CPU->group_interfaces[4].BC_step_prop[0]);
    
    //calcul des directions de recherche sur chaque groupe
//     field_structure_user.calculate_ddr(geometry_user);
//     field_structure_user.calculate_rigidity();
//     field_structure_user.calculate_homogeneised_operator();
    
    
    
    return 0;
}
