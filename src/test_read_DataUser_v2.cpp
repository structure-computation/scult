
#include <Metil/BasicVec.h>
#include <Metil/StructCompactor.h>
#include <Metil/CudaMetil.h>
#include <Metil/Hdf.h>
using namespace Metil;

#include "DataUser.h"
#include "DataReader.h"

int main( int argc, char **argv ) {
    if ( argc!=3 ) {
        std::cerr << "usage : SC_compute_2_$arch_$dimension.exe +  numero_du_modele + numero_du_calcul" << std::endl;
        std::cerr << "ex : ./SC_compute_2_GPU_3.exe 10 2 " << std::endl;
        return 1;
    }
    
    static const int dim = DIM;
    Sc2String id_model = argv[ 1 ];
    Sc2String id_calcul = argv[ 2 ];
     
    // ******************************************************************************************************************
    //lecture des données utilisateur (fichier de calcul .json) et compilation à la volée 
    DataUser data_user;
    PRINT("initialisation");
    data_user.initialisation(id_model, id_calcul);
    PRINT("lecture");
    data_user.read_json_calcul_v2();
}