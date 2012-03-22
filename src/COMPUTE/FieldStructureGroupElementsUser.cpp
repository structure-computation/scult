#include <Metil/BasicVec.h>
#include <Metil/StructCompactor.h>

#include "FieldStructureGroupElementsUser.h"

using namespace Metil;

void FieldStructureGroupElementsUser::write_hdf5(Hdf &hdf_file, Sc2String name_fields, int pt_cur, TYPE val_time){
    
#if DIM==2
    BasicVec<Sc2String> tensor_comp= BasicVec<Sc2String>("/xx","/yy","/xy");
    BasicVec<Sc2String> vector_comp= BasicVec<Sc2String>("/x","/y");
#else
    BasicVec<Sc2String> tensor_comp= BasicVec<Sc2String>("/xx","/yy","/zz","/xy","/xz","/yz");        
    BasicVec<Sc2String> vector_comp= BasicVec<Sc2String>("/x","/y","/z");        
#endif
    //sauvegarde des champs nodaux sur une SST
    Sc2String name_displacements; name_displacements<< name_fields <<"/elements_0/displacements/list_"<< id ;
    Sc2String name_explode_displacements; name_explode_displacements<< name_fields <<"/elements_0/explode_displacements/list_"<< id ;    
    for(unsigned d=0;d<DIM;d++) {
        Sc2String name_displacement_coor; name_displacement_coor=name_displacements+vector_comp[d];
        displacement_local_nodes[d].write_to(hdf_file,name_displacement_coor);
        Sc2String name_explode_displacement_coor; name_explode_displacement_coor=name_explode_displacements+vector_comp[d];
        explode_displacement_local_nodes[d].write_to(hdf_file,name_explode_displacement_coor);
    }
    
    //sauvegarde des champs par elements sur une SST
    Sc2String name_sigma, name_epsilon ;
    name_sigma<< name_fields << "/elements_0/sigma/list_" << id ;
    name_epsilon<< name_fields << "/elements_0/epsilon/list_" << id ;
    for(unsigned i_comp=0;i_comp<tensor_comp.size();i_comp++){
        Sc2String name_sigma_field, name_epsilon_field;
        name_sigma_field=name_sigma+tensor_comp[i_comp];
        name_epsilon_field=name_epsilon+tensor_comp[i_comp];
        sigma[i_comp].write_to(hdf_file,name_sigma_field);
        epsilon[i_comp].write_to(hdf_file,name_epsilon_field);
    }
    Sc2String name_sigma_mises;
    name_sigma_mises <<name_fields<<"/elements_0/sigma_von_mises/list_" << id ;
    sigma_mises.write_to(hdf_file,name_sigma_mises);
    Sc2String name_num_processor;
    name_num_processor <<name_fields<<"/elements_0/num_processor/list_" << id ;
    num_processor.write_to(hdf_file,name_num_processor); 
    Sc2String name_material_behaviour;
    name_material_behaviour <<name_fields<<"/elements_0/material_behaviour/list_" << id ;
    material_behaviour.write_to(hdf_file,name_material_behaviour); 
};

void FieldStructureGroupElementsUser::write_skin_hdf5(Hdf &hdf_file, Sc2String name_fields, int pt_cur, TYPE val_time){
#if DIM==2
    BasicVec<Sc2String> tensor_comp= BasicVec<Sc2String>("/xx","/yy","/xy");
    BasicVec<Sc2String> vector_comp= BasicVec<Sc2String>("/x","/y");
#else
    BasicVec<Sc2String> tensor_comp= BasicVec<Sc2String>("/xx","/yy","/zz","/xy","/xz","/yz");        
    BasicVec<Sc2String> vector_comp= BasicVec<Sc2String>("/x","/y","/z");        
#endif
    Sc2String id_reformated;
    //PRINT(id);
/*    if          (id<10)                         id_reformated<<"00000"<<id;
    else if     (id>=10 and id<100)             id_reformated<<"0000"<<id;
    else if     (id>=100 and id<1000)           id_reformated<<"000"<<id;
    else if     (id>=1000 and id<10000)         id_reformated<<"00"<<id;
    else if     (id>=10000 and id<100000)       id_reformated<<"0"<<id;
    else if     (id>=100000 and id<1000000)       id_reformated<< id;
    else { std::cout << " Il y aura des problemes dans l'affichage " << std::endl ; }*/
    id_reformated << id; 

    //sauvegarde des champs nodaux sur une peau de SST
    Sc2String name_displacements; name_displacements<< name_fields <<"/elements_0_skin/displacements/list_"<< id_reformated;
    Sc2String name_explode_displacements; name_explode_displacements<< name_fields <<"/elements_0_skin/explode_displacements/list_"<< id_reformated;
    for(unsigned d=0;d<DIM;d++) {
        Sc2String name_displacement_coor; name_displacement_coor=name_displacements+vector_comp[d];
        displacement_local_nodes_skin[d].write_to(hdf_file,name_displacement_coor);
        Sc2String name_explode_displacement_coor; name_explode_displacement_coor=name_explode_displacements+vector_comp[d];
        explode_displacement_local_nodes_skin[d].write_to(hdf_file,name_explode_displacement_coor);
    }
     //sauvegarde des champs elementaires de peau
    Sc2String name_sigma_skin, name_epsilon_skin ;
    name_sigma_skin<< name_fields << "/elements_0_skin/sigma/list_" << id_reformated ;
    name_epsilon_skin<< name_fields << "/elements_0_skin/epsilon/list_" << id_reformated ;
    for(unsigned i_comp=0;i_comp<tensor_comp.size();i_comp++){
        Sc2String name_sigma_field, name_epsilon_field;
        name_sigma_field=name_sigma_skin+tensor_comp[i_comp];
        name_epsilon_field=name_epsilon_skin+tensor_comp[i_comp];
        sigma_skin[i_comp].write_to(hdf_file,name_sigma_field);
        epsilon_skin[i_comp].write_to(hdf_file,name_epsilon_field);
    }
    Sc2String name_sigma_mises_skin;
    name_sigma_mises_skin <<name_fields<<"/elements_0_skin/sigma_von_mises/list_" << id_reformated ;
    sigma_mises_skin.write_to(hdf_file,name_sigma_mises_skin); 
    Sc2String name_num_processor_skin;
    name_num_processor_skin <<name_fields<<"/elements_0_skin/num_processor/list_" << id_reformated ;
    num_processor_skin.write_to(hdf_file,name_num_processor_skin); 
    Sc2String name_material_behaviour_skin;
    name_material_behaviour_skin <<name_fields<<"/elements_0_skin/material_behaviour/list_" << id_reformated ;
    material_behaviour_skin.write_to(hdf_file,name_material_behaviour_skin); 
    
};
