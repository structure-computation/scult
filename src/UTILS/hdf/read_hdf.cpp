//
// C++ Implementation: write_in_hdf
//
// Description: 
//
//
// Author: David Violeau <dvioleau@structure-computation.com>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "../Sc2String.h"

#include "containers/vec.h"

#include <Metil/BasicVec.h>
#include <Metil/CudaMetil.h>
#include <Metil/BasicVecGpu.h>
#include <Metil/Hdf.h>
#include <fstream>
#include <sstream>
#include <boost/concept_check.hpp>


using namespace Metil;

#include "struct_geometry_hdf.h"

#include "struct_hdf.h"

using namespace std;

#include "DATA_USER.h"
#include "LEVEL.h"

//ecriture de la geometry
void LEVEL::read_geometry_hdf(DATA_USER &data_user, string type){
    string name_hdf=data_user.name_directory+"/MESH/mesh.h5";
    Hdf hdf( name_hdf );
    
    //creation des patterns de base
    
    Sc2String name;
    name << "/Level_" << num_level << "/Geometry";
    Geometry.read_from(hdf,name);
/*    nb.sst=Geometry.nb_sst[0];
    nb.sst_s=Geometry.nb_sst[1];
    nb.inter=Geometry.nb_inter[0];
    nb.inter_s=Geometry.nb_inter[1];*/
    
    //copie des noeuds
    nodes.resize(Geometry.nodes.x.size()*DIM);
    for(unsigned i=0;i<nodes.size()/DIM; i++){
        nodes[i*dim+0] = Geometry.nodes.x[i];
        nodes[i*dim+1] = Geometry.nodes.y[i];
#if DIM==3            
        nodes[i*dim+2] = Geometry.nodes.z[i];
#endif  
    }

 /*   
    S_apex.resize(nb.sst_s*nb.apex_sst);
    S_num_group.resize(nb.sst_s);
    S_num_I.resize(nb.sst_s);
    for(unsigned i=0;i<nb.sst; i++){
        //copie des connectivites des patterns
        S_apex[0*nb.sst_s+i] = Geometry.connect_patterns.c0[i];
        S_apex[1*nb.sst_s+i] = Geometry.connect_patterns.c1[i];
        S_apex[2*nb.sst_s+i] = Geometry.connect_patterns.c2[i];
        //copie des numeros d'interfaces voisines
        S_num_I[i].resize(nb.side_sst);
        S_num_I[i][0]=Geometry.patterns_num_interfaces.i0[i];
        S_num_I[i][1]=Geometry.patterns_num_interfaces.i1[i];       
        S_num_I[i][2]=Geometry.patterns_num_interfaces.i2[i]; 
#if DIM==3            
        S_num_I[i][3]=Geometry.patterns_num_interfaces.i3[i]; 
        S_apex[3*nb.sst_s+i] = Geometry.connect_patterns.c3[i];
#endif  
        //copie des numeros de groupe des patterns (pieces)
        S_num_group[i]=Geometry.num_group_patterns[i];
    }

    //copie des connectivites des interfaces
    I_apex.resize(nb.inter_s*nb.apex_inter);
    I_num_group.resize(nb.inter_s);
    I_type.resize(nb.inter_s);
    
    I_side.resize(nb.inter_s*2);
    I_num_sst.resize(nb.inter_s*2);    
    for(unsigned i=0;i< I_side.size() ;i++){
        I_side[i]=-1;
        I_num_sst[i]=-1;
    }
    
    for(unsigned i=0;i< nb.inter  ;i++){
         I_apex[0*nb.inter_s+i] = Geometry.connect_interfaces.c0[i];
         I_apex[1*nb.inter_s+i] = Geometry.connect_interfaces.c1[i];
#if DIM==3 
         I_apex[2*nb.inter_s+i] = Geometry.connect_interfaces.c2[i];
#endif  
         I_num_group[i]=Geometry.num_group_interfaces[i];
         I_type[i]=Geometry.type[i];
        
         I_num_sst[i]=Geometry.interfaces_num_pattern_0[i];
         I_num_sst[i+nb.inter_s]=Geometry.interfaces_num_pattern_1[i];
         
    }
 */   

    
}

//Ecriture du comportement associe aux patterns et aux interfaces
// void LEVEL::read_behaviours_hdf(DATA_USER &data_user, string type){
//     string name_hdf=data_user.name_directory+"/MESH/mesh.h5";
//     Hdf hdf( name_hdf );
// 
//     Sc2String name;
//     name << "/Level_" << num_level << "/Behaviours";
//     Behaviours.read_from(hdf,name);
// 
//     //copie des numeros de groupe des patterns (pieces)
//     for(unsigned i=0;i<nb.sst; i++){
//         S_num_group[i]=Behaviours.patterns[i];
//     }
//     
//     //copie des connectivites des interfaces
//     for(unsigned i=0;i< nb.inter  ;i++){
//          I_comp[i]=Behaviours.interfaces[i];
//     }
//     
// }


