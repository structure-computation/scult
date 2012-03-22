//
// C++ Interface: FieldStructure
//
// Description: 
//
//
// Author: Jeremie Bellec <j.bellec@structure-computation.com>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//


#include <Metil/BasicVec.h>
#include <Metil/StructCompactor.h>

#include "FieldStructureUser.h"

using namespace Metil;


// fonctions d'initialisation ----------------------------------------------------------------------------------------------------------------------------

FieldStructureUser::FieldStructureUser(){};

FieldStructureUser::FieldStructureUser(GeometryUser &geometry_){
    num_level = geometry_.num_level;
    dim = geometry_.dim;
    nb_group_elements =  geometry_.group_elements.size();
    nb_group_interfaces =  geometry_.group_interfaces.size();
    
    group_elements.resize(nb_group_elements);
    group_interfaces.resize(nb_group_interfaces);
    
    for(int i_group=0; i_group<nb_group_elements; i_group++){
        group_elements[i_group].initialize(geometry_, i_group, properties);
    }
    
    for(int i_group=0; i_group<nb_group_interfaces; i_group++){
        group_interfaces[i_group].initialize(geometry_, i_group, properties);
    }
    
};

// FieldStructureUser::FieldStructureUser(GeometryUser &geometry_, Sst<DIM,TYPE> &S){
//     FieldStructureUser(geometry_);
//     
//     for(int i_group=0; i_group<nb_group_elements; i_group++){
//         group_elements[i_group].nb_elements_skin=S[i_group].mesh->skin.elem_list.size();
//         group_elements[i_group].nb_nodes_skin=S[i_group].mesh->skin.node_list.size();
//     }
//     
// };


//Methode génériques **************************************************************************************************************************************
FieldStructureGroupElementsUser* FieldStructureUser::find_group_elements(int id_) {
    for (int i_group=0; i_group<group_elements.size(); i_group++) {
        if (group_elements[i_group].id == id_) {
            return &group_elements[i_group];
            break;
        }
    }
}

int FieldStructureUser::find_index_group_elements(int id_) {
    for (int i_group=0; i_group<group_elements.size(); i_group++) {
        if (group_elements[i_group].id == id_) {
            return i_group;
            break;
        }
    }
}

//recherche d'un group_interfaces particulier avec son id---------------
FieldStructureGroupInterfacesUser* FieldStructureUser::find_group_interfaces(int id_) {
    for (int i_group=0; i_group<group_interfaces.size(); i_group++) {
        if (group_interfaces[i_group].id == id_) {
            return &group_interfaces[i_group];
            break;
        }
    }
}

int FieldStructureUser::find_index_group_interfaces(int id_) {
    for (int i_group=0; i_group<group_interfaces.size(); i_group++) {
        if (group_interfaces[i_group].id == id_) {
            return i_group;
            break;
        }
    }
}

//recherche d'un group_interfaces type edge : 0 particulier avec son edge_id---------------
BasicVec< FieldStructureGroupInterfacesUser* > FieldStructureUser::find_group_edges(int edge_id_) {
    BasicVec< FieldStructureGroupInterfacesUser* > group_edges_temp;
    for (int i_group=0; i_group<group_interfaces.size(); i_group++) {
        if (group_interfaces[i_group].edge_id == edge_id_) {
            group_edges_temp.push_back(&group_interfaces[i_group]);
        }
    }
    return group_edges_temp;
}

BasicVec< int > FieldStructureUser::find_index_group_edges(int edge_id_) {
    BasicVec< int > group_edges_temp;
    for (int i_group=0; i_group<group_interfaces.size(); i_group++) {
        if (group_interfaces[i_group].edge_id == edge_id_) {
            group_edges_temp.push_back(i_group);
        }
    }
    return group_edges_temp;
}


// méthodes d'assignation **************************************************************************************************************************************
void FieldStructureUser::assign_material_id_to_group_elements(DataUser &data_user) {
    for(int i_data_group=0; i_data_group<data_user.group_elements.size(); i_data_group++){
        for(int i_mat=0; i_mat<data_user.behaviour_materials.size(); i_mat++){
            if(data_user.group_elements[i_data_group].id_material==data_user.behaviour_materials[i_mat].id){
                find_group_elements(data_user.group_elements[i_data_group].id)->material_id =  i_mat;
                break;
            }
        }
    }
}

void FieldStructureUser::assign_material_properties_to_group_elements(DataUser &data_user, BasicVec<BasicVec< TYPE > > &mat_prop) {
    for(int i_group=0; i_group<group_elements.size(); i_group++)
        group_elements[i_group].mat_prop=mat_prop[group_elements[i_group].material_id];
}

void FieldStructureUser::assign_link_id_to_group_interfaces(DataUser &data_user) {
    for(int i_data_group=0; i_data_group<data_user.group_interfaces.size(); i_data_group++){
        for(int i_link=0; i_link<data_user.behaviour_links.size(); i_link++){
            if(data_user.group_interfaces[i_data_group].id_link==data_user.behaviour_links[i_link].id){
                find_group_interfaces(data_user.group_interfaces[i_data_group].id)->link_id =  i_link;
                break;
            }
        }
    }
}

void FieldStructureUser::assign_link_properties_to_group_interfaces(DataUser &data_user, BasicVec<BasicVec< TYPE > > &link_prop) {
    for(int i_group=0; i_group<group_interfaces.size(); i_group++)
        if(group_interfaces[i_group].link_id!=-1)
            group_interfaces[i_group].link_prop=link_prop[group_interfaces[i_group].link_id];
}

void FieldStructureUser::assign_bc_id_to_group_interfaces(DataUser &data_user) {
    for(int i_data_group=0; i_data_group<data_user.group_edges.size(); i_data_group++){
        for(int i_bc=0; i_bc<data_user.behaviour_bc.size(); i_bc++){
            if(data_user.group_edges[i_data_group].id_CL==data_user.behaviour_bc[i_bc].id){
                BasicVec< FieldStructureGroupInterfacesUser* > group_edges_to_assign;
                group_edges_to_assign = find_group_edges(data_user.group_edges[i_data_group].id);
                for(int i=0 ; i<group_edges_to_assign.size(); i++){
                    group_edges_to_assign[i]->bc_id = i_bc;
                }
                break;
            }
        }
    }
}







// fonctions d'initialisation GPU ----------------------------------------------------------------------------------------------------------------------------

void FieldStructureUser::initialize_GPU() {
    std::cout << "** initialisation pour GPU   FieldStructure  ***************************************************************************************" << std::endl;
    for(int i_group=0; i_group < group_elements.size(); i_group++){
        group_elements[i_group].initialize_GPU(patterns);
    }
    for(int i_group=0; i_group < group_interfaces.size(); i_group++){
        group_interfaces[i_group].initialize_GPU(patterns);
    }
    std::cout << "** fin initialisation pour GPU FieldStructure ***************************************************************************************" << std::endl;
}

// void FieldStructureUser::calculate_ddr(GeometryUser &geometry){
//     for(int i_group=0; i_group < group_interfaces.size(); i_group++){
//         TYPE L=0;
//         //calcul de la longueur de l'interface à prendre en compte pour la determination automatique du scalaire de ddr
// #if DIM==2
//         L =geometry.group_interfaces[i_group].measure;
// #else
//         L= ::sqrt(geometry.group_interfaces[i_group].measure);
// #endif
//         //calcul du scalaire pour la ddr (moyenne de young/L)
//         group_interfaces[i_group].ddr=0;
//         for(int i_side=0;i_side<geometry.group_interfaces[i_group].group_elements_id.size();i_side++){
//             int num_group_elem=geometry.group_interfaces[i_group].group_elements_id[i_side];
//             #warning Utilisation de mat_prop[0][0] pour le module d'young, revoir la declaration de mat_prop
//             group_interfaces[i_group].ddr+=(group_elements[num_group_elem].mat_prop[0][0])/L;
//         }
//         if(geometry.group_interfaces[i_group].group_elements_id.size()==2) 
//             group_interfaces[i_group].ddr=group_interfaces[i_group].ddr/2;
//     }  
// };

void FieldStructureUser::write_hdf5_in_parallel(Sc2String file_output, GeometryUser &geometry_user, Sc2String name_group_fields, int pt_cur, TYPE val_time, int rank){

    Hdf hdf_file( file_output );
   
    //write_fields_global_nodes_hdf5(hdf_file,name_fields,pt_cur);

    Sc2String name_fields; name_fields << name_group_fields <<"/pt_"<< pt_cur;    
//     for(unsigned i_group=0;i_group<geometry_user.group_elements.size();i_group++){
//         PRINT(geometry_user.find_index_group_elements(i_group));
//         PRINT(find_index_group_elements(i_group));
//         
//         PRINT(i_group);
//     }
//     PRINT("and");
    for(unsigned i_group=0;i_group<geometry_user.repartition_mpi_group_elements[rank].size();i_group++){
        int ng=geometry_user.repartition_mpi_group_elements[rank][i_group];
        //PRINT(ng);
        //int id=geometry_user.find_index_group_elements(ng);
        int id=find_group_elements(ng)->id;
        //PRINT(id);
        group_elements[id].write_hdf5(hdf_file,name_fields,pt_cur, val_time);
        group_elements[id].write_skin_hdf5(hdf_file,name_fields, pt_cur, val_time);        
        
/*        for(unsigned i_side=0;i_side<geometry_user.group_elements[ng].id_adjacent_group_interfaces.size();i_side++){
            int id_group_inter=geometry_user.group_elements[ng].id_adjacent_group_interfaces[i_side];
            int side_group_inter=geometry_user.group_elements[ng].side_adjacent_group_interfaces[i_side];
            group_interfaces[id_group_inter].write_hdf5(hdf_file,name_fields, side_group_inter, pt_cur, val_time);
        }*/
    }
    //tag de la valeur temporelle courante
    
    hdf_file.write_tag(name_fields,"time",val_time);
    hdf_file.add_tag(name_fields+"/elements_0/displacements","type","Node");
    hdf_file.add_tag(name_fields+"/elements_0_skin/displacements","type","Node");
    hdf_file.write_tag(name_fields+"/elements_0/displacements","nb_comp",DIM);
    hdf_file.write_tag(name_fields+"/elements_0_skin/displacements","nb_comp",DIM);
    hdf_file.add_tag(name_fields+"/elements_0/explode_displacements","type","Node");
    hdf_file.add_tag(name_fields+"/elements_0_skin/explode_displacements","type","Node");
    hdf_file.write_tag(name_fields+"/elements_0/explode_displacements","nb_comp",DIM);
    hdf_file.write_tag(name_fields+"/elements_0_skin/explode_displacements","nb_comp",DIM);
    int nb_comp_tensor=DIM*(DIM+1)/2, nb_comp_vector=DIM;
    BasicVec< BasicVec<Sc2String>, 3 > list_name_field_elements;
    BasicVec<BasicVec<int>, 3 > list_nb_comp;
    for(int i=0;i<2;i++){
        list_name_field_elements[i]=BasicVec<Sc2String>("sigma","epsilon","sigma_von_mises","material_behaviour","num_processor");
        list_nb_comp[i]=BasicVec<int>(nb_comp_tensor,nb_comp_tensor,1,1,1);
    }
    list_name_field_elements[2]=BasicVec<Sc2String>("F","W","Fchap","Wchap");
    list_nb_comp[2]=BasicVec<int>(nb_comp_vector,nb_comp_vector,nb_comp_vector);
    BasicVec<Sc2String,3> group_type("elements_0","elements_0_skin");
    for(int i=0;i<2;i++){
        for(int j=0;j<list_name_field_elements[i].size();j++){
            Sc2String name_field=name_fields+"/"+group_type[i]+"/"+list_name_field_elements[i][j];
            //PRINT(name_field);
            hdf_file.add_tag(name_field,"type","Elem");
            hdf_file.write_tag(name_field,"nb_comp",list_nb_comp[i][j]);
            
        }
    }


    
};

/*void FieldStructureUser::calculate_rigidity(){
    
};

void FieldStructureUser::calculate_homogeneised_operator(){
    
}*/;


