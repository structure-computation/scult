#include <Metil/BasicVec.h>
#include <Metil/StructCompactor.h>
#include <Metil/CudaMetil.h>
#include <Metil/Hdf.h>
using namespace Metil;

#include "GEOMETRY/GeometryUser.h"
#include "DataReader.h"
//#include "GEOMETRY/GeometryCompact.h"
//#include "COMPUTE/FieldStructureUser.h"



int main( int argc, char **argv ) {
    if ( argc!=3 ) {
        std::cerr << "usage : SC_compute_2_$arch_$dimension.exe +  numero_du_modele + numero_du_calcul" << std::endl;
        std::cerr << "ex : ./SC_compute_2_GPU_3.exe 10 2 " << std::endl;
        return 1;
    }
    static const int dim = DIM;
    Sc2String id_model = argv[ 1 ];
    Sc2String id_calcul = argv[ 2 ];
    Sc2String model_path = "/share/sc2/Developpement/MODEL/";
    Sc2String mesh_path = model_path + "model_" + id_model + "/MESH";
    Sc2String calcul_path = model_path + "model_" + id_model + "/calcul_" + id_calcul ;
    Sc2String calcul_file = calcul_path + "/calcul.json" ;
    Sc2String code_path = "/home/jbellec/code_dev/SC_code";
    
    Sc2String name_visu_hdf; 
    name_visu_hdf << mesh_path << "/visu_geometry.h5";
        
    //lecture de la geometrie ----------------------------------------------------------------------------
    //GeometryUser geometry_user;
    //geometry_user.read_hdf5(name_visu_hdf);

    //lecture des données utilisateur (fichier de calcul .json) ------------------------------------------
    DataUser data_user(model_path, calcul_path, id_calcul);
    data_user.read_json_calcul(calcul_file);
    data_user.assign_num_materials_id_group_elements();
    data_user.assign_num_links_id_group_interfaces();
    
    DataReader *data_reader;
    data_reader = NEW_DataReader( data_user );
    
    
    
    //compilation à la volé du fichier-------------------------------------------------------------------------------------------------------------
    //Sc2String comp = metil_comp_path + "/metil_comp -shared -o " + calcul_path + "/read_prop.so " + calcul_path + "/read_prop.cu";
    std::ostringstream osdim;
    osdim << DIM;
    Sc2String comp =  "metil_comp -ne -o " + calcul_path + "/SC_compute_2_cpu_" + osdim.str() + ".exe -O0 -ILMT -ILMT/include -Isrc/UTILS/hdf -Isrc/UTILS/xdmf -I/usr/include/libxml2 -ffast-math  -fexpensive-optimizations -DDIM=" + osdim.str() + " -DTYPE=double -DTHREADSPERBLOCK=48  -DSIZEGRID=6  -Iusr/include/suitesparse -Isrc/COMPUTE -Isrc/GEOMETRY -Isrc/UTILS -Isrc/UTILS/json_spirit -I"+ calcul_path +" "+ code_path +"/src/SC_compute_2.cpp "+ id_model +" "+ id_calcul ;
    std::cout << std::endl;
    std::cout << "comp : system(" << comp << ");" << std::endl;
    std::cout << std::endl;
    //system(comp);
    //vérifications  -------------------------------------------------------------------------------------
//     PRINT(geometry_user.nb_group_elements);
//     for(int i_group=0; i_group<geometry_user.nb_group_elements; i_group++){
//         geometry_user.group_elements[i_group].affiche();
//     }
//     
//     PRINT(geometry_user.nb_group_interfaces);
//     for(int i_group=0; i_group<geometry_user.nb_group_interfaces; i_group++){
//         geometry_user.group_interfaces[i_group].affiche();
//     }
    
    
    return 0;
}
