#include <Metil/BasicVec.h>
#include <Metil/StructCompactor.h>
#include <Metil/CudaMetil.h>
#include <Metil/Hdf.h>
using namespace Metil;

#include "GeometryUser.h"
#include "MeshUser.h"
#include "GeometryCompact.h"



int main( int argc, char **argv ) {
    if ( argc!=2 ) {
        std::cerr << "usage : SC_create$dimension.exe +  numero_du_modele (ou nom si xml)" << std::endl;
        std::cerr << "ex : ./test2 123 " << std::endl;
        return 1;
    }
    static const int dim = DIM;
    Sc2String id_model = argv[ 1 ];
    Sc2String model_path = "/share/sc2/Developpement/MODEL/";
    Sc2String file = model_path + "model_" + id_model + "/MESH/model_id.json";

    
    
    //lecture du maillage utilisateur -------------------------------------------
    MeshUser mesh_user( model_path, id_model );
    mesh_user.create_mesh( model_path, file );
     
    //Création de la géométrie au format SC -------------------------------------
    GeometryUser geometry_user( mesh_user );
    
    //création de la structure compacté -----------------------------------------

//     geometry_user.initialize_GPU();
//     Ps<GeometryCompactClass> geometry_compact_CPU = make_cs( &geometry_user, 1, MachineId::cpu() );
//     PRINT(geometry_compact_CPU.rese);
//     Ps<GeometryCompactClass> geometry_compact_GPU = strdup( geometry_compact_CPU, MachineId::cpu( 0 )->gpu( 0 ) ); 
//     PRINT(geometry_compact_GPU.rese);
    
    //calcul de side_N et side_M pour la strategie micro -------------------------------------------------

    //launch_calculate_side_N_M_CPU(geometry_compact_CPU);
//     launch_calculate_side_N_M_GPU(geometry_compact_CPU, geometry_compact_GPU);
//     memcpy( geometry_compact_CPU, geometry_compact_GPU);
    
    //calcul de Ne et Me pour la strategie multi   -------------------------
    //launch_calculate_interface_N_M_CPU(geometry_compact_CPU);

    

//     PRINT(geometry_compact_CPU->group_interfaces[0].Ne);
//     
//     PRINT(geometry_compact_CPU->group_elements[0].nb_elements);
//     PRINT(geometry_compact_CPU->group_elements[0].connectivities[0].size());
//     PRINT(geometry_compact_CPU->group_elements[0].pattern_id);

//     for(unsigned i=0;i<geometry_compact_CPU->group_elements[0].side_M.size();i++)
//        PRINT(geometry_compact_CPU->group_elements[0].side_M[i]);
//     PRINT(geometry_compact_CPU->group_elements[0].side_N[0][0][0]);

//     //vérifications  ------------------------------------------------------------
//     PRINT(mesh_user.nb_elements);
//     for(int i_elem=0; i_elem<mesh_user.nb_elements; i_elem++){
//         mesh_user.list_elements[i_elem].affiche();
//     }
//     
//     PRINT(mesh_user.nb_interfaces);
//     for(int i_inter=0; i_inter<mesh_user.nb_interfaces; i_inter++){
//         mesh_user.list_interfaces[i_inter].affiche();
//     }
//     

    



    return 0;
}
