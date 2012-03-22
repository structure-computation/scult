#include <Metil/BasicVec.h>
#include <Metil/StructCompactor.h>

#include "FieldStructureGroupInterfacesUser.h"

using namespace Metil;

void FieldStructureGroupInterfacesUser::write_hdf5(Hdf &hdf_file, Sc2String name_fields, int side, int pt_cur, TYPE val_time){
#if DIM==2
    BasicVec<Sc2String> name_direction= BasicVec<Sc2String>("/x","/y");
#else
    BasicVec<Sc2String> name_direction= BasicVec<Sc2String>("/x","/y","/z");        
#endif
    BasicVec<Sc2String> list_name_field("F","W","Fchap","Wchap");
    
    Sc2String name_F; name_F<< name_fields << "/F" << side << "/list_" << id ;
    Sc2String name_W; name_W<< name_fields << "/W" << side << "/list_" << id ;
    for (unsigned d=0;d<DIM;d++) {
        Sc2String name_Fdim=name_F+"/"+"xyz"[d]; 
        F[side][d].write_to(hdf_file,name_Fdim);
        Sc2String name_Wdim=name_W+"/"+"xyz"[d]; 
        W[side][d].write_to(hdf_file,name_Wdim);
    }
//     for(unsigned j=0;j<S.edge.size();++j) {
//             unsigned q=S.edge[j].internum;
//             unsigned data=S.edge[j].datanum;
//             Sc2String name_F; name_F<< name_fields << "/F/list_" << q ;
//             Sc2String name_W; name_W<< name_fields << "/W/list_" << q ;
//             Sc2String name_Fchap; name_Fchap<< name_fields << "/Fchap/list_" << q ;
//             Sc2String name_Wchap; name_Wchap<< name_fields << "/Wchap/list_" << q ;
//             if(data==0){
//                 for (unsigned d=0;d<DIM;d++) {
//                     Sc2String name_Fdim=name_F+"/"+name_direction[d]; 
//                     I[q].F[d].write_to(hdf,name_Fdim);
//                     Sc2String name_Wdim=name_W+"/"+name_direction[d]; 
//                     I[q].W[d].write_to(hdf,name_Wdim);
//                     Sc2String name_Fchapdim=name_Fchap+"/"+name_direction[d]; 
//                     I[q].Fchap[d].write_to(hdf,name_Fchapdim);
//                     Sc2String name_Wchapdim=name_Wchap+"/"+name_direction[d]; 
//                     I[q].Wchap[d].write_to(hdf,name_Wchapdim);
//                 }
//             }
//     }

};
