//
// C++ Interface: GEOMETRY
//
// Description:
//
//
// Author: Jeremie Bellec <j.bellec@structure-computation.com>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>

#include "GeometryUser.h"
#include "../UTILS/utils_2.h"
#include "../UTILS/Sc2String.h"
#include "../UTILS/json_spirit/json_spirit.h"

using namespace json_spirit;
using namespace Metil;


//Methode génériques **************************************************************************************************************************************
GroupElementsUser* GeometryUser::find_group_elements(int id_) {
    for (int i_group=0; i_group<group_elements.size(); i_group++) {
        if (group_elements[i_group].id == id_) {
            return &group_elements[i_group];
            break;
        }
    }
}

int GeometryUser::find_index_group_elements(int id_) {
    for (int i_group=0; i_group<group_elements.size(); i_group++) {
        if (group_elements[i_group].id == id_) {
            return i_group;
            break;
        }
    }
}

//recherche d'un group_interfaces particulier avec son id---------------
GroupInterfacesUser* GeometryUser::find_group_interfaces(int id_) {
    for (int i_group=0; i_group<group_interfaces.size(); i_group++) {
        if (group_interfaces[i_group].id == id_) {
            return &group_interfaces[i_group];
            break;
        }
    }
}

int GeometryUser::find_index_group_interfaces(int id_) {
    for (int i_group=0; i_group<group_interfaces.size(); i_group++) {
        if (group_interfaces[i_group].id == id_) {
            return i_group;
            break;
        }
    }
}

//recherche d'un group_interfaces type edge : 0 particulier avec son edge_id---------------
BasicVec< GroupInterfacesUser* > GeometryUser::find_group_edges(int edge_id_) {
    BasicVec< GroupInterfacesUser* > group_edges_temp;
    for (int i_group=0; i_group<group_interfaces.size(); i_group++) {
        if (group_interfaces[i_group].edge_id == edge_id_) {
            group_edges_temp.push_back(&group_interfaces[i_group]);
        }
    }
    return group_edges_temp;
}

BasicVec< int > GeometryUser::find_index_group_edges(int edge_id_) {
    BasicVec< int > group_edges_temp;
    for (int i_group=0; i_group<group_interfaces.size(); i_group++) {
        if (group_interfaces[i_group].edge_id == edge_id_) {
            group_edges_temp.push_back(i_group);
        }
    }
    return group_edges_temp;
}




//Methode d'initialisation*******************************************************
GeometryUser::GeometryUser() {
    dim = DIM;
}

GeometryUser::GeometryUser(Sc2String id_model, Sc2String id_calcul) {
    dim = DIM;
    model_path = "/share/sc2/Developpement/MODEL/";
    mesh_path = model_path + "model_" + id_model + "/MESH";
    calcul_path = model_path + "model_" + id_model + "/calcul_" + id_calcul ;
    calcul_file = calcul_path + "/calcul.json" ;
    name_file_hdf5 << mesh_path << "/visu_geometry.h5";
}

GeometryUser::GeometryUser(MeshUser &mesh_) {
    std::cout << "**********************************************************************************************************************" << std::endl;
    std::cout << "** create geometry_user  *********************************************************************************************" << std::endl;
    std::cout << "**********************************************************************************************************************" << std::endl;
    dim = DIM;

    std::cout << "** create nodes          *********************************************************************************************" << std::endl;
    PRINT( mesh_.scale_factor);
    mesh_nodes.resize(DIM);
    for (int di=0;di<DIM;di++) {
	mesh_nodes[di] = mesh_.scale_factor*mesh_.mesh_pos_nodes[di];
    }    
    //mesh_nodes = mesh_.scale_factor*mesh_.mesh_pos_nodes;
    nodes = mesh_.elements_pos_nodes;

    std::cout << "** create group_elements *********************************************************************************************" << std::endl;
    initialize_group_elements_from_MeshUser(mesh_);

    std::cout << "** create group_interfaces *******************************************************************************************" << std::endl;
    initialize_group_interfaces_from_MeshUser(mesh_);

    std::cout << "** vérification            *******************************************************************************************" << std::endl;
    affiche();
    
    std::cout << "** écriture du json       ********************************************************************************************" << std::endl;
    write_json( mesh_ );
    std::cout << "** écriture du json v2    ********************************************************************************************" << std::endl;
    write_json_v2( mesh_ );

    std::cout << "** écriture du hdf5       ********************************************************************************************" << std::endl;
    Sc2String file_output_hdf5=mesh_.name_visu_hdf;
    write_hdf5( file_output_hdf5 );
/*
    std::cout << "** écriture du xdmf       ********************************************************************************************" << std::endl;
    Sc2String name_geometry_hdf5 = "/Level_0/Geometry";
    Sc2String name_fields_hdf5 = "/Level_0/Structure_Fields";
    write_xdmf(mesh_.name_visu_xdmf, mesh_.name_visu_hdf, name_geometry_hdf5,0, name_fields_hdf5, BasicVec<Sc2String>("none"));*/

    std::cout << "** écriture du xdmf       ********************************************************************************************" << std::endl;
    Sc2String name_geometry_hdf5 = "/Level_0/Geometry";
    //write_xdmf(mesh_.name_visu_xdmf, mesh_.name_visu_hdf, name_geometry_hdf5,0);

}

GeometryUser::GeometryUser(MeshUser &mesh_, Sc2String path_hdf) {
    std::cout << "**********************************************************************************************************************" << std::endl;
    std::cout << "** create geometry_user  *********************************************************************************************" << std::endl;
    std::cout << "**********************************************************************************************************************" << std::endl;
    dim = DIM;

    std::cout << "** create nodes          *********************************************************************************************" << std::endl;
    mesh_nodes = mesh_.mesh_pos_nodes;
    nodes = mesh_.elements_pos_nodes;

    std::cout << "** create group_elements *********************************************************************************************" << std::endl;
    initialize_group_elements_from_MeshUser(mesh_);

    std::cout << "** create group_interfaces *******************************************************************************************" << std::endl;
    initialize_group_interfaces_from_MeshUser(mesh_);
    
    std::cout << "** vérification            *******************************************************************************************" << std::endl;
    affiche();
}

void GeometryUser::initialisation(MeshUser &mesh_, Sc2String path_hdf) {
    std::cout << "**********************************************************************************************************************" << std::endl;
    std::cout << "** create geometry_user  *********************************************************************************************" << std::endl;
    std::cout << "**********************************************************************************************************************" << std::endl;
    dim = DIM;

    std::cout << "** create nodes          *********************************************************************************************" << std::endl;
    mesh_nodes = mesh_.mesh_pos_nodes;
    nodes = mesh_.elements_pos_nodes;

    std::cout << "** create group_elements *********************************************************************************************" << std::endl;
    initialize_group_elements_from_MeshUser(mesh_);

    std::cout << "** create group_interfaces *******************************************************************************************" << std::endl;
    initialize_group_interfaces_from_MeshUser(mesh_);
    
    std::cout << "** vérification            *******************************************************************************************" << std::endl;
    affiche();
}


void GeometryUser::initialisation(Sc2String id_model, Sc2String id_calcul) {
    dim = DIM;
    model_path = "/share/sc2/Developpement/MODEL/";
    mesh_path = model_path + "model_" + id_model + "/MESH";
    calcul_path = model_path + "model_" + id_model + "/calcul_" + id_calcul ;
    calcul_file = calcul_path + "/calcul.json" ;
    name_file_hdf5 << mesh_path << "/visu_geometry.h5";
}

void GeometryUser::initialisation(Sc2String _name_file_hdf5) {
    dim = DIM;
    name_file_hdf5 = _name_file_hdf5;
}

void GeometryUser::affiche() {
//     PRINT(nb_group_elements);
//     for(int i_group=0; i_group<nb_group_elements; i_group++){
//         group_elements[i_group].affiche();
//     }
   
    PRINT(nb_group_interfaces);
    int nb_group_interfaces_0 = 0;
    int nb_group_interfaces_1 = 0;
    int nb_group_interfaces_2 = 0;
    for(int i_group=0; i_group<nb_group_interfaces; i_group++){
        if(group_interfaces[i_group].type == 0){
            nb_group_interfaces_0 += 1 ;
            group_interfaces[i_group].affiche();
        }
        if(group_interfaces[i_group].type == 1){
            nb_group_interfaces_1 += 1 ;
            group_interfaces[i_group].affiche();
        }
        if(group_interfaces[i_group].type == 2){
            nb_group_interfaces_2 += 1 ;
            group_interfaces[i_group].affiche();
        }
    }
    PRINT(nb_group_interfaces_0);
    PRINT(nb_group_interfaces_1);
    PRINT(nb_group_interfaces_2);
}


void GeometryUser::initialize_GPU() {
    std::cout << "** initialisation pour GPU     ***************************************************************************************" << std::endl;
    for(int i_group=0; i_group < group_elements.size(); i_group++){
        group_elements[i_group].initialize_GPU(patterns);
    }
    for(int i_group=0; i_group < group_interfaces.size(); i_group++){
        group_interfaces[i_group].initialize_GPU(patterns);
    }
    std::cout << "** fin initialisation pour GPU ***************************************************************************************" << std::endl;
}

#include "containers/mat.h"
using namespace LMT;
#include "containers/algo.h"
#include "SCtime.h"

void GeometryUser::mpi_repartition() {

    
}

void GeometryUser::initialize_group_elements_from_MeshUser(MeshUser &mesh) {
    //création des groupe d'element 
    std::cout << mesh.nb_elements << std::endl;
//     TicTac tic1;
//     tic1.init();tic1.start();
//     
//     Vec<int> num_groups;
//     num_groups.resize(mesh.nb_elements);
//     for (int i_elem=0; i_elem<mesh.nb_elements; i_elem++) {
//         num_groups[i_elem]=mesh.list_elements[i_elem].flags[0];
//     }
//     std::map<int,int> correspondance_flag_num_groups_with_group_elements;
//     remove_doubles(num_groups);    
//     for(int i=0 ;i< num_groups.size() ;i++){
//         correspondance_flag_num_groups_with_group_elements[num_groups[i]]=i;
//     }
//     BasicVec<GroupElementsUser> group_elements_2;
//     group_elements_2.resize(num_groups.size());
//     for (int i_elem=0; i_elem<mesh.nb_elements; i_elem++) {
//         int num_group=correspondance_flag_num_groups_with_group_elements[mesh.list_elements[i_elem].flags[0]];
//         group_elements_2[num_group].nb_elements+=1;
//     }
//     tic1.stop();
//     std::cout << "nb_groups " << group_elements_2.size() << std::endl;
//     for(int i=0 ;i< group_elements_2.size() ;i++){
//         std::cout << "nb_elements in groups " << i << " : " << group_elements_2[i].nb_elements << std::endl;
//     }
//     std::cout << std::endl;
//     tic1.start();
    for (int i_elem=0; i_elem<mesh.nb_elements; i_elem++) {
        //test pour l'ajout d'un group_elements
        bool add_group_elements = true;
        for (int i_group=0; i_group<group_elements.size(); i_group++) {
            if (group_elements[i_group].add_entity_element(mesh.list_elements[i_elem])) {
                add_group_elements = false;
                break;
            }
        }
        if (add_group_elements) {
            GroupElementsUser current_group(group_elements.size(), mesh.list_elements[i_elem]);
            group_elements.push_back(current_group);
            nb_group_elements = group_elements.size();
        }
    }
   //tic1.stop();
    //création de la liste de noeud et de la connectivité interne aux groupes
    for(int i_group=0; i_group<group_elements.size(); i_group++) {
        group_elements[i_group].initialize_local_connectivities(mesh_nodes);
    }
    
//     PRINT(group_elements.size());
//     for(int i=0 ;i< group_elements.size() ;i++){
//         std::cout << "nb_elements in groups " << i << " : " << group_elements[i].nb_elements << std::endl;
//     }
//     assert(0);
}

void GeometryUser::initialize_group_interfaces_from_MeshUser(MeshUser &mesh) {
    for (int i_inter=0; i_inter<mesh.nb_interfaces; i_inter++) {
//         PRINT(i_inter);
        mesh.list_interfaces[i_inter].calcul_interface_connectivity(mesh.list_elements, mesh.patterns);
        //test pour l'ajout d'un group_interfaces
        bool add_group_interfaces = true;
        for (int i_group=0; i_group<group_interfaces.size(); i_group++) {
            if (group_interfaces[i_group].add_entity_interface( mesh.list_interfaces[i_inter], mesh.list_elements, group_elements, mesh.patterns )) {
                add_group_interfaces = false;
                break;
            }
        }
        if (add_group_interfaces) {
            GroupInterfacesUser current_group(group_interfaces.size(), mesh.list_interfaces[i_inter], mesh.list_elements, group_elements, mesh.patterns);
            group_interfaces.push_back(current_group);
            nb_group_interfaces = group_interfaces.size();
        }
    }
    
    //création de la liste de noeud et de la connectivité interne aux groupes
    for(int i_group=0; i_group<group_interfaces.size(); i_group++) {
        group_interfaces[i_group].initialize_local_connectivities(mesh_nodes);
        group_interfaces[i_group].to_visualize.resize(group_interfaces[i_group].nb_interfaces,0);
    }
    
    PRINT(group_interfaces.size());
    
        //liste des interfaces adjacentes
        //sauvegarde des id des groupes d'interfaces voisines uniquement
    for(int i_group=0; i_group<group_elements.size(); i_group++) {
        for(unsigned nside_g=0;nside_g<group_elements[i_group].group_interfaces_id.size();nside_g++){
            if( group_elements[i_group].group_interfaces_id[nside_g].size() != 0 and  nside_g!=1 ){
                for(int i_group_inter=0;i_group_inter<group_elements[i_group].group_interfaces_id[nside_g].size();i_group_inter++){
                    group_elements[i_group].id_adjacent_group_interfaces <<  group_elements[i_group].group_interfaces_id[nside_g][i_group_inter];
                }
            }
        }
    }
    
}


//Methode de niveau sup**********************************************************
/* ANCIENNE VERSION (AVANT MODIF DE DATAUSER)
bool GeometryUser::do_respect_geometry(int i_group, int num_edge, Geometry &geom){
    const int size_vertex_point = interfaces.find_type(group_interfaces[i_group].interface_base_id)->nb_vertex_nodes;
    BasicVec< BasicVec<TYPEREEL,DIM> > vertex_point;
    vertex_point.resize(size_vertex_point);
    for(int i_node=0; i_node<size_vertex_point; i_node++){
        for(int d=0; d<DIM; d++){
            vertex_point[i_node][d] = mesh_nodes[d][group_interfaces[i_group].global_connectivities[i_node][num_edge]];
        }
    }
    if(geom.type=="all_temp"){
        return true;
    }else if(geom.type=="is_in"){
        if(geom.nature=="box"){
            for(int num_point=0; num_point<size_vertex_point; num_point++){
                if(!GeomTest::pt_in_box(vertex_point[num_point],geom.points))
                    return false;
            }
            return true;
        }else if(geom.nature=="cylinder"){
            for(int num_point=0; num_point<size_vertex_point; num_point++){
                if(!GeomTest::pt_in_cylinder(vertex_point[num_point],geom.points,geom.radius))
                    return false;
            }
            return true;
        }else if(geom.nature=="sphere"){
            for(int num_point=0; num_point<size_vertex_point; num_point++){
                if(!GeomTest::pt_in_sphere(vertex_point[num_point],geom.points[0],geom.radius))
                    return false;
            }
            return true;
        }
    }else if(geom.type=="is_on"){
        if(geom.nature=="plan"){
            for(int num_point=0; num_point<size_vertex_point; num_point++){
                if(!GeomTest::pt_on_plan(vertex_point[num_point],geom.points[0],geom.pdirection))
                    return false;
            }
            return true;
        }else if(geom.nature=="disc"){
            for(int num_point=0; num_point<size_vertex_point; num_point++){
                if(!GeomTest::pt_on_disc(vertex_point[num_point],geom.points[0],geom.pdirection,geom.radius))
                    return false;
            }
            return true;
        }else if(geom.nature=="cylinder"){
            for(int num_point=0; num_point<size_vertex_point; num_point++){
                if(!GeomTest::pt_on_cylinder(vertex_point[num_point],geom.points,geom.radius))
                    return false;
            }
            return true;
        }else if(geom.nature=="sphere"){
            for(int num_point=0; num_point<size_vertex_point; num_point++){
                if(!GeomTest::pt_on_sphere(vertex_point[num_point],geom.points[0],geom.radius))
                    return false;
            }
            return true;
        }else if(geom.nature=="equation"){
            for(int num_point=0; num_point<size_vertex_point; num_point++){
                if(!GeomTest::pt_match_equation(vertex_point[num_point],geom.equation))
                    return false;
            }
            return true;
        }
    }
    return true;
    //std::cerr << "geom.type '" << geom.type << "' ou geom.nature '" << geom.nature << "' n'est pas valable";
    //assert(0);
};//*/

/*
void GeometryUser::visualize_group_edges_within_geometry(DataUser &data_user) {
    PRINT("Visualisation des bords respectant un critère donné -------");
    Sc2String name_visu_hdf; 
    name_visu_hdf << data_user.mesh_directory << "/visu_geometry.h5";
    Hdf hdf( name_visu_hdf );
    Sc2String name;
    int num_level=0;
    name << "/Level_" << num_level << "/Geometry";
    Sc2String name_group_1;
    name_group_1 << name << "/elements_1";
    
    for(int i_group=0; i_group<nb_group_interfaces; i_group++){
        group_interfaces[i_group].to_visualize.resize(group_interfaces[i_group].nb_interfaces,0);
        if(group_interfaces[i_group].type == 0){ //interfaces de bord
            for(int i_data_group=0; i_data_group<data_user.group_edges.size(); i_data_group++){
                if(data_user.group_edges[i_data_group].to_visualize == 1){ //test uniquement pour le groupe à visualiser
                    for(int i_edge=0; i_edge<group_interfaces[i_group].nb_interfaces; i_edge++){
                        if(do_respect_geometry(i_group, i_edge, data_user.group_edges[i_data_group].geom)){
                            group_interfaces[i_group].to_visualize[i_edge]=1;
                        }
                    }
                    if(sum(group_interfaces[i_group].to_visualize)!=0)
                        std::cout << sum(group_interfaces[i_group].to_visualize) << std::endl;
                    Sc2String name_field ;
                    name_field << name_group_1 << "/list_" << group_interfaces[i_group].id << "/to_visualize";
                    group_interfaces[i_group].to_visualize.write_to( hdf, name_field );
                }
            }
        }
    }
}//*/

/*
void GeometryUser::split_group_edges_within_geometry(DataUser &data_user) {
    std::cout << " - split des interfaces";
    //PRINT(nb_group_interfaces);
    for(int i_group=0; i_group<nb_group_interfaces; i_group++){
        if(group_interfaces[i_group].type == 0){
            //PRINT(i_group);
            BasicVec< int > edge_assigned_;
            edge_assigned_.resize(group_interfaces[i_group].nb_interfaces,-1); /// toute les interface sont assigné par defaut a la condition effort nul
            BasicVec< bool > find_data_group_edge;
            find_data_group_edge.resize(data_user.group_edges.size(),false);
            for(int i_data_group=0; i_data_group<data_user.group_edges.size(); i_data_group++){
                if(data_user.group_edges[i_data_group].assigned != -1){
                    for(int i_edge=0; i_edge<group_interfaces[i_group].nb_interfaces; i_edge++){
                        if(edge_assigned_[i_edge]==-1 and do_respect_geometry(i_group, i_edge, data_user.group_edges[i_data_group].geom)){
                            edge_assigned_[i_edge] = data_user.group_edges[i_data_group].id;
                            find_data_group_edge[i_data_group] = true;
                        }
                    }
                }
            }
            //PRINT(data_user.group_edges.size());
            //PRINT(data_user.group_edges[0].id);
            //PRINT(edge_assigned_);
            for(int i_data_group=0; i_data_group<data_user.group_edges.size()-1; i_data_group++){
                //PRINT(i_data_group);
                if(find_data_group_edge[i_data_group]){
                    //PRINT(group_interfaces[i_group].id);
                    //PRINT(data_user.group_edges[i_data_group].id);
                    //PRINT(data_user.group_edges[i_data_group].assigned);
                    int id = group_interfaces.size();
                    
                    GroupInterfacesUser *group_interface_temp = group_interfaces.push_back();
                    group_interface_temp->split_from_group(group_interfaces[i_group], edge_assigned_, data_user.group_edges[i_data_group].id, id, mesh_nodes, group_elements);
                    //group_interface_temp->affiche();
                    //sleep(10);
                    //GroupInterfacesUser group_interface_temp(group_interfaces[i_group], edge_assigned_, data_user.group_edges[i_data_group].id, id, mesh_nodes, group_elements);
                    //group_interface_temp.affiche();
                    //group_interfaces.push_back(group_interface_temp);
                }
            }
        }
        //PRINT(nb_group_interfaces);
    }
    nb_group_interfaces = group_interfaces.size();
    //PRINT(nb_group_interfaces);
}//*/


bool GeometryUser::do_respect_geometry(int i_group, int num_edge, DataUser::Json_edges &edge){
    const int size_vertex_point = interfaces.find_type(group_interfaces[i_group].interface_base_id)->nb_vertex_nodes;
    BasicVec< BasicVec<TYPEREEL,DIM> > vertex_point;
    vertex_point.resize(size_vertex_point);
    for(int i_node=0; i_node<size_vertex_point; i_node++){
        for(int d=0; d<DIM; d++){
            vertex_point[i_node][d] = mesh_nodes[d][group_interfaces[i_group].global_connectivities[i_node][num_edge]];
        }
    }
    BasicVec< BasicVec<TYPEREEL,DIM> > points;
    points.resize(2);
    points[0][0] = edge.point_1_x;
    points[0][1] = edge.point_1_y;
    points[0][2] = edge.point_1_z;
    points[1][0] = edge.point_2_x;
    points[1][1] = edge.point_2_y;
    points[1][2] = edge.point_2_z;
    BasicVec< TYPEREEL, DIM > pdirection;
    pdirection[0] = edge.direction_x;
    pdirection[1] = edge.direction_y;
    pdirection[2] = edge.direction_z;
    if(edge.criteria=="all_temp"){
        return true;
    }else if(edge.criteria=="volume"){
        if(edge.geometry=="box"){
            for(int num_point=0; num_point<size_vertex_point; num_point++){
                if(!GeomTest::pt_in_box(vertex_point[num_point],points))
                    return false;
            }
            return true;
        }else if(edge.geometry=="cylinder"){
            for(int num_point=0; num_point<size_vertex_point; num_point++){
                if(!GeomTest::pt_in_cylinder(vertex_point[num_point],points,edge.radius))
                    return false;
            }
            return true;
        }else if(edge.geometry=="sphere"){
            for(int num_point=0; num_point<size_vertex_point; num_point++){
                if(!GeomTest::pt_in_sphere(vertex_point[num_point],points[0],edge.radius))
                    return false;
            }
            return true;
        }
    }else if(edge.criteria=="surface"){
        if(edge.geometry=="plan"){
            for(int num_point=0; num_point<size_vertex_point; num_point++){
                if(!GeomTest::pt_on_plan(vertex_point[num_point],points[0],pdirection))
                    return false;
            }
            return true;
        }else if(edge.geometry=="disc"){
            for(int num_point=0; num_point<size_vertex_point; num_point++){
                if(!GeomTest::pt_on_disc(vertex_point[num_point],points[0],pdirection,edge.radius))
                    return false;
            }
            return true;
        }else if(edge.geometry=="cylinder"){
            for(int num_point=0; num_point<size_vertex_point; num_point++){
                if(!GeomTest::pt_on_cylinder(vertex_point[num_point],points,edge.radius))
                    return false;
            }
            return true;
        }else if(edge.geometry=="sphere"){
            for(int num_point=0; num_point<size_vertex_point; num_point++){
                if(!GeomTest::pt_on_sphere(vertex_point[num_point],points[0],edge.radius))
                    return false;
            }
            return true;
        }else if(edge.geometry=="parameterized"){
            for(int num_point=0; num_point<size_vertex_point; num_point++){
                if(!GeomTest::pt_match_equation(vertex_point[num_point],edge.equation))
                    return false;
            }
            return true;
        }
    }
    return true;
//std::cerr << "edge.type '" << edge.type << "' ou edge.nature '" << edge.nature << "' n'est pas valable";
//assert(0);
};

//*
void GeometryUser::visualize_group_edges_within_geometry(DataUser &data_user) {/* A REVOIR
    PRINT("Visualisation des bords respectant un critère donné -------");
    Sc2String name_visu_hdf;
    name_visu_hdf << data_user.mesh_directory << "/visu_geometry.h5";
    Hdf hdf( name_visu_hdf );
    Sc2String name;
    int num_level=0;
    name << "/Level_" << num_level << "/Geometry";
    Sc2String name_group_1;
    name_group_1 << name << "/elements_1";
    BasicVec<bool> edge_to_visualize;
    
    
    for(int i_group=0; i_group<nb_group_interfaces; i_group++){
        group_interfaces[i_group].to_visualize.resize(group_interfaces[i_group].nb_interfaces,0);
        if(group_interfaces[i_group].type == 0){ //interfaces de bord
            for(int i_data_group=0; i_data_group<data_user.edges_vec.size(); i_data_group++){
                if(data_user.edges_vec[i_data_group].to_visualize == 1){ //test uniquement pour le groupe à visualiser
                    for(int i_edge=0; i_edge<group_interfaces[i_group].nb_interfaces; i_edge++){
                        if(do_respect_geometry(i_group, i_edge, data_user.edges_vec[i_data_group].geom)){
                            group_interfaces[i_group].to_visualize[i_edge]=1;
                        }
                    }
                    if(sum(group_interfaces[i_group].to_visualize)!=0)
                        std::cout << sum(group_interfaces[i_group].to_visualize) << std::endl;
                    Sc2String name_field ;
                    name_field << name_group_1 << "/list_" << group_interfaces[i_group].id << "/to_visualize";
                    group_interfaces[i_group].to_visualize.write_to( hdf, name_field );
                }
            }
        }
    }
//*/
}
//*/

//*
void GeometryUser::split_group_edges_within_geometry(DataUser &data_user) {
    std::cout << " - split des interfaces" << std::endl;
    PRINT(nb_group_interfaces);
    /// Pour chaque groupe d'interface du HDF5
    //affiche();
    //PRINT(group_interfaces.size());
    for(int i_group=0; i_group<nb_group_interfaces; i_group++){
        /// si l'interface est sur un bord de la structure
        if(group_interfaces[i_group].type == 0){
            /// on stockera les id des edges (dans le JSON) assignes a une interface du groupe
            BasicVec< int > edge_assigned;
            edge_assigned.resize(group_interfaces[i_group].nb_interfaces,-1); /// -1 signifie "l'ensemble des bords libres" (CL par defaut)
            /// ainsi que le fait d'avoir deja assigne un edge
            BasicVec<bool> edge_found;
            edge_found.resize(data_user.edges_vec.size(),false);
            PRINT(data_user.edges_vec.size());
            //PRINT(data_user.edges_vec[0].id_in_calcul);
            //PRINT(data_user.edges_vec[0].assigned);
            //PRINT(data_user.edges_vec[0].criteria);
            //PRINT(data_user.edges_vec[0].geometry);
            //PRINT(data_user.edges_vec[0].equation);
            //PRINT(data_user.edges_vec[0].boundary_condition_id);
            
            
            /// Pour chaque combinaison {interface,bord}
            for(int i_edge=0; i_edge<data_user.edges_vec.size(); i_edge++){
                PRINT(group_interfaces[i_group].nb_interfaces);
                for(int i_inter=0; i_inter<group_interfaces[i_group].nb_interfaces; i_inter++){
                    if(edge_assigned[i_inter]==-1 and do_respect_geometry(i_group, i_inter, data_user.edges_vec[i_edge])){
                        //PRINT("ok");
                        /// si l'interface 'i_inter' n'est pas encore assigne a un edge...
                        /// et si tous les noeuds de l'interface 'i_inter' (du groupe 'i_group') respectent la condition definie par le bord 'i_edge'
                        edge_assigned[i_inter] = data_user.edges_vec[i_edge].id_in_calcul;
                        edge_found[i_edge] = true;
                    }
                }
            }
            for(int i_edge=0; i_edge<data_user.edges_vec.size()-1; i_edge++){
                if(edge_found[i_edge]){ /// si le bord correspond a une interface, on separe le groupe
                    PRINT(group_interfaces[i_group].id);
                    PRINT(data_user.edges_vec[i_edge].id_in_calcul);
                    int id = group_interfaces.size();
                    GroupInterfacesUser *group_interface_temp = group_interfaces.push_back();
                    group_interface_temp->split_from_group(group_interfaces[i_group], edge_assigned, data_user.edges_vec[i_edge].id_in_calcul, id, mesh_nodes, group_elements);
                }
            }
        }
    }
    //PRINT(group_interfaces.size());
    nb_group_interfaces = group_interfaces.size();
    //affiche();
}//*/


//Methode de niveau courrant ****************************************************
//ecriture du fichier json pour l'interface utilisateur javascript---------------
void GeometryUser::write_json(MeshUser &mesh_user) {
    //ecriture du nom du fichier json
    Sc2String path=mesh_user.name_directory+"/MESH/mesh.txt";
    std::ofstream os( path.c_str() );
    //ecriture du debut du fichier------------------
    Object mesh;
    mesh.push_back(Pair( "model_directory", mesh_user.name_directory ));
    mesh.push_back(Pair( "mesh_directory", mesh_user.mesh_directory ));
    mesh.push_back(Pair( "mesh_name", mesh_user.name_mesh_user ));
    mesh.push_back(Pair( "extension", mesh_user.extension ));

    mesh.push_back(Pair( "nb_sst", mesh_user.nb_elements ));
    mesh.push_back(Pair( "nb_inter", mesh_user.nb_interfaces ));
    mesh.push_back(Pair( "nb_groups_elem", nb_group_elements ));
    mesh.push_back(Pair( "nb_groups_inter", nb_group_interfaces ));

    Object mesh_o;
    mesh_o.push_back( Pair( "mesh", mesh ) );

    //ecriture des groupes d'elements---------------
    Array group_elem_a;
    //Object group_elem_a;
    for (int i_group=0; i_group< nb_group_elements; i_group++) {
        Object group;
        group.push_back(Pair( "id", group_elements[i_group].id ));
        group.push_back(Pair( "origine", "from_bulkdata" ));
        group.push_back(Pair( "identificateur", group_elements[i_group].id ));
        Sc2String name_group;
        name_group << "piece " << group_elements[i_group].id;
        group.push_back(Pair( "name", name_group ));
        group.push_back(Pair( "assigned", -1 ));
        group.push_back(Pair( "group", -1 ));

        std::ostringstream num;
        num << i_group;
        //group_elem_a.push_back(Pair(num.str(),group));
        group_elem_a.push_back(group);
    }
    Object group_elem_o;
    group_elem_o.push_back( Pair( "groups_elem", group_elem_a ) );

    //ecriture des groupes d'interfaces------------
    Array group_inter_a;
    //Object group_inter_a;
    for (int i_group=0; i_group< nb_group_interfaces; i_group++) {
        if (group_interfaces[i_group].type==2) {
            Object group;
            group.push_back(Pair( "id", group_interfaces[i_group].id ));
            group.push_back(Pair( "origine", "from_bulkdata" ));
            group.push_back(Pair( "type", "between_group_elem" ));
            std::ostringstream name_group;
            name_group << "interface " << group_interfaces[i_group].id;
            group.push_back(Pair( "name", Sc2String(name_group.str()) ));
            group.push_back(Pair( "assigned", -1 ));
            group.push_back(Pair( "group", -1 ));
            std::ostringstream adj;
            adj << group_interfaces[i_group].group_elements_id[0] << " " << group_interfaces[i_group].group_elements_id[1];
            group.push_back(Pair( "adj_num_group", Sc2String(adj.str()) ));
            std::ostringstream num;
            num << i_group;
            //group_inter_a.push_back(Pair(num.str(),group));
            group_inter_a.push_back(group);
        }
    }
    Object group_inter_o;
    group_inter_o.push_back( Pair( "groups_inter", group_inter_a ) );

    //ecriture des proprietes_interfaces par defaut---------------
    Array prop_inter_a;
    //Object prop_inter_a;
    for (unsigned i=0;i< 1;i++) {
        Object prop;
        prop.push_back(Pair( "id", 0 ));
        prop.push_back(Pair( "type", "parfait" ));
        prop.push_back(Pair( "coef_frottement", 0. ));
        std::ostringstream num;
        num << i;
        //prop_inter_a.push_back(Pair(num.str(),prop));
        prop_inter_a.push_back(prop);
    }
    Object prop_inter_o;
    prop_inter_o.push_back( Pair( "proprietes_interfaces", prop_inter_a ) );


    //ecriture des CL par defaut-------------------------------
    Array cl_a;
    //Object cl_a;
    for (unsigned i=0;i< 1;i++) {
        Object cl;
        cl.push_back(Pair( "id", 0 ));
        cl.push_back(Pair( "type", "effort" ));
        cl.push_back(Pair( "fcts_spatiales", "0 0" ));
        cl.push_back(Pair( "fcts_temporelles", "0 0" ));
        std::ostringstream num;
        num << i;
        //cl_a.push_back(Pair(num.str(),cl));
        cl_a.push_back(cl);
    }
    Object cl_o;
    cl_o.push_back( Pair( "CL", cl_a ) );

    //regroupement des donnees pour ecriture du fichier de sortie
    Array output;
    output.push_back(mesh_o);
    output.push_back(group_elem_o);
    output.push_back(group_inter_o);
    output.push_back(prop_inter_o);
    output.push_back(cl_o);

    write_formatted( output, os );

    os.close();

}


void GeometryUser::write_json_v2(MeshUser &mesh_user) {
    //ecriture du nom du fichier json
    Sc2String path=mesh_user.name_directory+"/MESH/mesh_v2.txt";
    std::ofstream os( path.c_str() );
    //ecriture du debut du fichier------------------
    Object mesh;
    mesh.push_back(Pair( "model_directory", mesh_user.name_directory ));
    mesh.push_back(Pair( "mesh_directory", mesh_user.mesh_directory ));
    mesh.push_back(Pair( "mesh_name", mesh_user.name_mesh_user ));
    mesh.push_back(Pair( "extension", mesh_user.extension ));

    int nb_ddl = mesh_user.mesh_num_nodes.size() * DIM;
    mesh.push_back(Pair( "nb_ddl", nb_ddl));
    mesh.push_back(Pair( "nb_sst", mesh_user.nb_elements ));
    mesh.push_back(Pair( "nb_inter", mesh_user.nb_interfaces ));
    mesh.push_back(Pair( "nb_groups_elem", nb_group_elements ));
    mesh.push_back(Pair( "nb_groups_inter", nb_group_interfaces ));

    Object mesh_o;
    mesh_o.push_back( Pair( "mesh", mesh ) );

    //ecriture des groupes d'elements---------------
    Array group_elem_a;
    //Object group_elem_a;
    for (int i_group=0; i_group< nb_group_elements; i_group++) {
        Object group;
        group.push_back(Pair( "id", group_elements[i_group].id ));
        group.push_back(Pair( "id_in_calcul", group_elements[i_group].id ));
        group.push_back(Pair( "origine", "from_bulkdata" ));
        group.push_back(Pair( "identificateur", group_elements[i_group].id ));
        Sc2String name_group;
        name_group << "piece " << group_elements[i_group].id;
        group.push_back(Pair( "name", name_group ));
        group.push_back(Pair( "assigned", -1 ));
        group.push_back(Pair( "group", -1 ));

        std::ostringstream num;
        num << i_group;
        //group_elem_a.push_back(Pair(num.str(),group));
        group_elem_a.push_back(group);
    }
    Object group_elem_o;
    group_elem_o.push_back( Pair( "pieces", group_elem_a ) );

    //ecriture des groupes d'interfaces------------
    Array group_inter_a;
    //Object group_inter_a;
    for (int i_group=0; i_group< nb_group_interfaces; i_group++) {
        if (group_interfaces[i_group].type==2) {
            Object group;
            group.push_back(Pair( "id", group_interfaces[i_group].id ));
            group.push_back(Pair( "id_in_calcul", group_interfaces[i_group].id ));
            group.push_back(Pair( "origine", "from_bulkdata" ));
            group.push_back(Pair( "type", "between_group_elem" ));
            std::ostringstream name_group;
            name_group << "interface " << group_interfaces[i_group].id;
            group.push_back(Pair( "name", Sc2String(name_group.str()) ));
            group.push_back(Pair( "assigned", -1 ));
            group.push_back(Pair( "group", -1 ));
            std::ostringstream adj;
            adj << group_interfaces[i_group].group_elements_id[0] << " " << group_interfaces[i_group].group_elements_id[1];
            group.push_back(Pair( "adj_num_group", Sc2String(adj.str()) ));
            std::ostringstream num;
            num << i_group;
            //group_inter_a.push_back(Pair(num.str(),group));
            group_inter_a.push_back(group);
        }
    }
    Object group_inter_o;
    group_inter_o.push_back( Pair( "interfaces", group_inter_a ) );

    //ecriture des proprietes_interfaces par defaut---------------
    Array prop_inter_a;
    //Object prop_inter_a;
//     for (unsigned i=0;i< 1;i++) {
//         Object prop;
//         prop.push_back(Pair( "id", 0 ));
//         prop.push_back(Pair( "type", "parfait" ));
//         prop.push_back(Pair( "coef_frottement", 0. ));
//         std::ostringstream num;
//         num << i;
//         //prop_inter_a.push_back(Pair(num.str(),prop));
//         prop_inter_a.push_back(prop);
//     }
    Object prop_inter_o;
    prop_inter_o.push_back( Pair( "links", prop_inter_a ) );


    //ecriture des CL par defaut-------------------------------
    Array cl_a;
    //Object cl_a;
//     for (unsigned i=0;i< 1;i++) {
//         Object cl;
//         cl.push_back(Pair( "id", 0 ));
//         cl.push_back(Pair( "type", "effort" ));
//         cl.push_back(Pair( "fcts_spatiales", "0 0" ));
//         cl.push_back(Pair( "fcts_temporelles", "0 0" ));
//         std::ostringstream num;
//         num << i;
//         //cl_a.push_back(Pair(num.str(),cl));
//         cl_a.push_back(cl);
//     }
    Object cl_o;
    cl_o.push_back( Pair( "boundary_condition", cl_a ) );
    
    //ecriture des materiaux, time step, edges...-------------------------------
    Array edge_a;
    Array materials_a;
    Array volumic_forces;
    

    //regroupement des donnees pour ecriture du fichier de sortie
    Object output;
    output.push_back(Pair( "mesh", mesh ));
    output.push_back(Pair( "pieces", group_elem_a ));
    output.push_back(Pair( "interfaces", group_inter_a ));
    output.push_back(Pair( "edges", edge_a ));
    output.push_back(Pair( "materials", materials_a ));
    output.push_back(Pair( "links", prop_inter_a ));
    output.push_back(Pair( "boundary_condition", cl_a ));

    write_formatted( output, os );

    os.close();

}

void GeometryUser::write_nodes_hdf5(Hdf &hdf, Sc2String name_geometry){
    //ecriture des noeuds du maillage
    mesh_nodes[0].write_to( hdf, name_geometry + "/nodes/x" );
    mesh_nodes[1].write_to( hdf, name_geometry + "/nodes/y" );
#if DIM==3
    mesh_nodes[2].write_to( hdf, name_geometry + "/nodes/z" );
    //* AST begin
#else
    BasicVec< TYPE > tmp;
    tmp.resize(mesh_nodes[0].size(),0.0);
    tmp.write_to( hdf, name_geometry + "/nodes/z");
    /// AST end */
#endif
//     //ecriture des noeuds du maillage
//     mesh_nodes[0].write_to( hdf, name + "/mesh_nodes/x" );
//     mesh_nodes[1].write_to( hdf, name + "/mesh_nodes/y" );
// #if DIM==3
//     mesh_nodes[2].write_to( hdf, name + "/mesh_nodes/z" );
// #endif
    
    //ecriture des noeuds vision micro
//     nodes[0].write_to( hdf, name_geometry + "/micro_nodes/x" );
//     nodes[1].write_to( hdf, name_geometry + "/micro_nodes/y" );
// #if DIM==3
//     nodes[2].write_to( hdf, name_geometry + "/micro_nodes/z" );
// #endif 
    
}

void GeometryUser::write_group_elements_hdf5(Hdf &hdf, Sc2String name_geometry, int ng){
    Sc2String name_group_0;
    name_group_0 << name_geometry << "/elements_0";
    
    Sc2String name_list ;
    name_list<< name_group_0 << "/list_" << group_elements[ng].id ;

    //enregistrement des noeuds locaux
    BasicVec < Sc2String , 3 > name_direction("x","y","z");
    for(int d=0; d<DIM; d++){
        Sc2String name_dim;
        name_dim << name_list << "/local_nodes/" << name_direction[d];
        group_elements[ng].local_nodes[d].write_to( hdf, name_dim );
    }
    //* AST Begin
    if(DIM == 2){
        Sc2String name_dim;
        name_dim << name_list << "/local_nodes/z";
        BasicVec< TYPE > tmp;
        tmp.resize(group_elements[ng].local_nodes[0].size(),0.0);
        tmp.write_to( hdf, name_dim);
    }
    /// AST end */
    Sc2String name_map;
    name_map << name_list << "/map_global_nodes" ;
    group_elements[ng].map_global_nodes.write_to( hdf, name_map );
    //enregistrement des connectivités
    for (unsigned nb_connect=0;nb_connect<group_elements[ng].local_connectivities.size();nb_connect++) {
        Sc2String name_connect;
        name_connect << name_list << "/local_connectivities_"<<nb_connect;
        group_elements[ng].local_connectivities[nb_connect].write_to( hdf, name_connect );
    }
    for (unsigned nb_connect=0;nb_connect<group_elements[ng].global_connectivities.size();nb_connect++) {
        Sc2String name_connect;
        name_connect << name_list << "/global_connectivities_"<<nb_connect;
        group_elements[ng].global_connectivities[nb_connect].write_to( hdf, name_connect );
    }

//         for (unsigned nb_connect=0;nb_connect<group_elements[ng].connectivities.size();nb_connect++) {
//             Sc2String name_connect;
//             name_connect << name_list << "/c"<<nb_connect;
//             group_elements[ng].connectivities[nb_connect].write_to( hdf, name_connect );
//         }

    hdf.add_tag(name_list,"piece",name_list);
    Sc2String type_elements="null";       
//         Sc2String type_elements=(patterns.find_type(group_elements[ng].pattern_id)).name;       
    type_elements=(patterns.find_type(group_elements[ng].pattern_base_id)).base_xdmf;
    hdf.add_tag(name_list,"base",type_elements);
    hdf.write_tag(name_list,"pattern_id",group_elements[ng].pattern_id);
    hdf.write_tag(name_list,"pattern_base_id",group_elements[ng].pattern_base_id);
    hdf.write_tag(name_list,"id",group_elements[ng].id);
    hdf.write_tag(name_list,"nb_elements",group_elements[ng].nb_elements);

    //sauvegarde des sides pour chaque element (repere du groupe et du numéro local dans le groupe de l'interface voisine)
    for(unsigned nside=0;nside<group_elements[ng].interface_group_id.size();nside++){
        Sc2String name_side ;
        name_side<< name_group_0 << "/list_" << group_elements[ng].id << "/sides/side_" << nside ;
        Sc2String name_side_group_id;
        name_side_group_id << name_side << "/interface_group_id";
        group_elements[ng].interface_group_id[nside].write_to( hdf, name_side_group_id );
        Sc2String name_side_num_in_group;
        name_side_num_in_group << name_side << "/num_in_group" ;
        group_elements[ng].interface_num_in_group[nside].write_to( hdf, name_side_num_in_group );
    }
    //sauvegarde des id des groupes d'interfaces voisins et du groupe interieur
    BasicVec<Sc2String> name_type("/id_group_interfaces_edges","/id_group_interfaces_interiors","/id_group_interfaces_links");
    for(unsigned nside_g=0;nside_g<group_elements[ng].group_interfaces_id.size();nside_g++){
        if(group_elements[ng].group_interfaces_id[nside_g].size() != 0){
            Sc2String name_side_g ;
            name_side_g<< name_group_0 << "/list_" << group_elements[ng].id << name_type[nside_g] ;
            group_elements[ng].group_interfaces_id[nside_g].write_to( hdf, name_side_g );
        }
    }
    //PRINT(group_elements[ng].id_adjacent_group_interfaces);
    Sc2String name_side_g ;
    name_side_g<< name_group_0 << "/list_" << group_elements[ng].id << "/id_adjacent_groups" ;
    group_elements[ng].id_adjacent_group_interfaces.write_to( hdf, name_side_g );
 
}

void GeometryUser::write_group_elements_skin_hdf5(Hdf &hdf, Sc2String name_geometry, int ng){
    Sc2String id_reformated;
//     if          (ng<10)                         id_reformated<<"00000"<<ng;
//     else if     (ng>=10 and ng<100)             id_reformated<<"0000"<<ng;
//     else if     (ng>=100 and ng<1000)           id_reformated<<"000"<<ng;
//     else if     (ng>=1000 and ng<10000)         id_reformated<<"00"<<ng;
//     else if     (ng>=10000 and ng<100000)       id_reformated<<"0"<<ng;
//     else if     (ng>=100000 and ng<1000000)       id_reformated<< ng;
//     else { std::cout << " Il y aura des problemes dans l'affichage " << std::endl ; }

    id_reformated <<ng;
//PRINT(ng);
//PRINT(group_elements[ng].id);
        Sc2String name_elements="elements_0_skin";
        Sc2String name_list=name_geometry; name_list << "/"<< name_elements <<"/list_" << id_reformated ;
        BasicVec < Sc2String , 3 > name_direction("x","y","z");
        for(int d=0; d<DIM; d++){
            Sc2String name_dim;
            name_dim << name_list << "/local_nodes/" << name_direction[d];
            group_elements[ng].local_nodes[d].write_to( hdf, name_dim );
        }
        //* AST Begin
        if(DIM == 2){
            Sc2String name_dim;
            name_dim << name_list << "/local_nodes/z";
            BasicVec< TYPE > tmp;
            tmp.resize(group_elements[ng].local_nodes[0].size(),0.0);
            tmp.write_to( hdf, name_dim);
        }
        /// AST end */
        for (unsigned i_connect=0;i_connect<group_elements[ng].local_connectivities_skin.size();i_connect++) {
            Sc2String name_connect;
            name_connect << name_list << "/local_connectivities_"<<i_connect;
            group_elements[ng].local_connectivities_skin[i_connect].write_to( hdf, name_connect );
        }
        Sc2String type_elements;
        type_elements=(patterns.find_type(group_elements[ng].pattern_base_id)).base_skin_xdmf;
        hdf.add_tag(name_list,"base",type_elements);
        hdf.write_tag(name_list,"id",group_elements[ng].id);
        hdf.write_tag(name_list,"pattern_base_id",group_elements[ng].pattern_base_id);
        hdf.write_tag(name_list,"nb_elements",group_elements[ng].nb_elements_skin);
        
}


void GeometryUser::write_group_interfaces_hdf5(Hdf &hdf, Sc2String name_geometry, int ng){
        Sc2String name_group_1;
        name_group_1 << name_geometry << "/elements_1";
        Sc2String name_list ;
        name_list<< name_group_1 << "/list_" << group_interfaces[ng].id ;
        //enregistrement des noeuds locaux
        BasicVec < Sc2String , 3 > name_direction("x","y","z");
        for(int d=0; d<DIM; d++){
            Sc2String name_dim;
            name_dim << name_list << "/local_nodes/" << name_direction[d];
            group_interfaces[ng].local_nodes[d].write_to( hdf, name_dim );
        }
        //* AST Begin
        if(DIM == 2){
            Sc2String name_dim;
            name_dim << name_list << "/local_nodes/z";
            BasicVec< TYPE > tmp;
            tmp.resize(group_interfaces[ng].local_nodes[0].size(),0.0);
            tmp.write_to( hdf, name_dim);
        }
        /// AST end */

        Sc2String name_map;
        name_map << name_list << "/map_global_nodes" ;
        group_interfaces[ng].map_global_nodes.write_to( hdf, name_map );
 
        //enregistrement du champ pour la visualisation des bords via l'interface utilisateur
//         Sc2String name_field;
//         name_field << name_list << "/to_visualize";
//         group_interfaces[ng].to_visualize.write_to( hdf, name_field );

        //enregistrement des connectivités
        for (unsigned nb_connect=0;nb_connect<group_interfaces[ng].local_connectivities.size();nb_connect++) {
            Sc2String name_connect;
            name_connect << name_list << "/local_connectivities_"<<nb_connect;
            group_interfaces[ng].local_connectivities[nb_connect].write_to( hdf, name_connect );
        }
        for (unsigned nb_connect=0;nb_connect<group_interfaces[ng].global_connectivities.size();nb_connect++) {
            Sc2String name_connect;
            name_connect << name_list << "/global_connectivities_"<<nb_connect;
            group_interfaces[ng].global_connectivities[nb_connect].write_to( hdf, name_connect );
        }
//         for (unsigned nb_connect=0;nb_connect<group_interfaces[ng].connectivities.size();nb_connect++) {

//             Sc2String name_connect;
//             name_connect << name_list << "/c"<<nb_connect;
//             group_interfaces[ng].connectivities[nb_connect].write_to( hdf, name_connect );
//         }
        if (group_interfaces[ng].type==0) {//bord
            //PRINT(name_list);
            Sc2String name_piece;
            name_piece << name_group_1 << name_geometry << "/elements_0/list_" << group_interfaces[ng].group_elements_id[0];
            hdf.add_tag(name_list,"edge_of_0",name_piece);
            hdf.add_tag(name_list,"edge_of_1","");
            hdf.write_tag(name_list,"id_edge_of_0",group_interfaces[ng].group_elements_id[0]);
            hdf.write_tag(name_list,"id_pattern_group_elements_0",group_interfaces[ng].patterns_id[0]);
            hdf.write_tag(name_list,"type",group_interfaces[ng].type);
        }
        else if (group_interfaces[ng].type==1 or group_interfaces[ng].type==2) {//interieur
            Sc2String name_piece_0, name_piece_1;
            name_piece_0 << name_group_1 << name_geometry << "/elements_0/list_" << group_interfaces[ng].group_elements_id[0];
            name_piece_1 << name_group_1 << name_geometry << "/elements_0/list_" << group_interfaces[ng].group_elements_id[1];
            hdf.add_tag(name_list,"edge_of_0",name_piece_0);
            hdf.add_tag(name_list,"edge_of_1",name_piece_1);
            hdf.write_tag(name_list,"id_edge_of_0",group_interfaces[ng].group_elements_id[0]);
            hdf.write_tag(name_list,"id_edge_of_1",group_interfaces[ng].group_elements_id[1]);  
            hdf.write_tag(name_list,"id_pattern_group_elements_0",group_interfaces[ng].patterns_id[0]);
            hdf.write_tag(name_list,"id_pattern_group_elements_1",group_interfaces[ng].patterns_id[1]);
            hdf.write_tag(name_list,"type",group_interfaces[ng].type);
        }

        //ecriture des id des groupes d'elements voisins ainsi que de l'id du pattern des groupes adjacents
        for(unsigned nside_g=0;nside_g<group_interfaces[ng].group_elements_id.size();nside_g++){
            Sc2String name_side ;
            name_side<< name_group_1 << "/list_" << group_interfaces[ng].id << "/sides/side_" << nside_g ;
            Sc2String name_side_elements_id;
            name_side_elements_id << name_side << "/element_num_in_group";
            group_interfaces[ng].element_num_in_group[nside_g].write_to( hdf, name_side_elements_id );
            Sc2String name_side_num_side;
            name_side_num_side << name_side << "/element_num_side";
            group_interfaces[ng].element_num_side[nside_g].write_to( hdf, name_side_num_side );
            Sc2String name_id="id_group_elements_";
            name_id << nside_g;
            hdf.add_tag(name_side,name_id,group_interfaces[ng].group_elements_id[nside_g]);
        } 
        Sc2String type_elements;
        type_elements=(patterns.find_type(group_interfaces[ng].patterns_base_id[0])).base_skin_xdmf;
        
        hdf.add_tag(name_list,"base",type_elements);
        hdf.write_tag(name_list,"interface_id",group_interfaces[ng].interface_id);
        hdf.write_tag(name_list,"interface_base_id",group_interfaces[ng].interface_base_id);
        hdf.write_tag(name_list,"id",group_interfaces[ng].id);
        hdf.write_tag(name_list,"nb_interfaces",group_interfaces[ng].nb_interfaces);
    
}

void GeometryUser::write_side_group_interfaces_hdf5(Hdf &hdf, Sc2String name_geometry, int ng, int nside_g){
        Sc2String name_group_1;
        name_group_1 << name_geometry << "/elements_1";
        Sc2String name_side ;
        name_side<< name_group_1 << "/list_" << group_interfaces[ng].id << "/sides/side_" << nside_g ;
        Sc2String name_side_elements_id;
        name_side_elements_id << name_side << "/element_num_in_group";
        group_interfaces[ng].element_num_in_group[nside_g].write_to( hdf, name_side_elements_id );
        Sc2String name_side_num_side;
        name_side_num_side << name_side << "/element_num_side";
        group_interfaces[ng].element_num_side[nside_g].write_to( hdf, name_side_num_side );
        Sc2String name_id="id_group_elements_";
        name_id << nside_g;
        hdf.add_tag(name_side,name_id,group_interfaces[ng].group_elements_id[nside_g]);    
}

void GeometryUser::write_hdf5_in_parallel(Sc2String file_output_hdf5, int rank) {
    if (FileExists(file_output_hdf5.c_str())) {
        Sc2String command = "rm -rf "; command << file_output_hdf5;
        int syst_rm=system(command.c_str());
    }

    Hdf hdf( file_output_hdf5 );
    Sc2String name_geometry;
    int num_level=0;
    name_geometry << "/Level_" << num_level << "/Geometry";
    //ecriture des noeuds (necessaire pour chaque processeur
    write_nodes_hdf5(hdf,name_geometry);
    
    //ecriture des groupes d'elements specifiques a chaque processeur    
    for (unsigned i_group=0;i_group<repartition_mpi_group_elements[rank].size();i_group++){
    //for (unsigned i_group=0;i_group<2;i_group++){
        //ecriture des groupes d'elements specifiques a chaque processeur    
        int ng=repartition_mpi_group_elements[rank][i_group];
        int id=find_group_elements(ng)->id;
       // PRINT(group_elements[ng].id);
        //PRINT(group_elements[id].id);
        write_group_elements_hdf5(hdf,name_geometry,id);
        write_group_elements_skin_hdf5(hdf,name_geometry,id);
//     std::cout << i_group << std::endl;

        //ecriture des groupes d'interfaces specifiques a chaque processeur (voisines des groupes d'elements)
//         for(unsigned i_side=0;i_side<group_elements[repartition_mpi_group_elements[rank][i_group]].id_adjacent_group_interfaces.size();i_side++){
//             int id_group_inter=group_elements[repartition_mpi_group_elements[rank][i_group]].id_adjacent_group_interfaces[i_side];
//             int side_group_inter=group_elements[repartition_mpi_group_elements[rank][i_group]].side_adjacent_group_interfaces[i_side];
//             std::cout <<id_group_inter<< " " << side_group_inter << std::endl;   
//            
//             if(side_group_inter==0){
//                 write_group_interfaces_hdf5(hdf,name_geometry,id_group_inter);
//             }
//             
//         }
    }
    for (unsigned i_group_inter=0;i_group_inter<group_interfaces.size();i_group_inter++){
/*        std::cout << i_group_inter << " " <<group_interfaces[i_group_inter].type << std::endl;*/
        if(group_interfaces[i_group_inter].type!=1)
            write_group_interfaces_hdf5(hdf,name_geometry,i_group_inter);
    }
    std::cout << "Ecriture d'un HDF5 sous : " << file_output_hdf5 << std::endl;
}

void GeometryUser::write_hdf5(Sc2String file_output_hdf5) {
    if (FileExists(file_output_hdf5.c_str())) {
        Sc2String command = "rm -rf "; command << file_output_hdf5;
        int syst_rm=system(command.c_str());
    }

    Hdf hdf( file_output_hdf5 );
    Sc2String name_geometry;
    int num_level=0;
    name_geometry << "/Level_" << num_level << "/Geometry";

    PRINT("write_nodes");
    //ecriture des noeuds (necessaire pour chaque processeur
    write_nodes_hdf5(hdf,name_geometry);
    PRINT("write_pieces");

    //ecriture des groupes d'elements
    for (unsigned i_group=0;i_group<group_elements.size();i_group++)
        write_group_elements_hdf5(hdf,name_geometry,i_group);
    
    PRINT("write_interfaces");
    //ecriture des groupes d'interfaces
    for (unsigned i_group_inter=0;i_group_inter<group_interfaces.size();i_group_inter++)
        write_group_interfaces_hdf5(hdf,name_geometry,i_group_inter);
    
}


void GeometryUser::read_node_hdf5(Hdf &hdf, Sc2String name, bool read_micro) {    
    //lecture des noeuds du maillage
    mesh_nodes.resize(DIM);
    mesh_nodes[0].read_from( hdf, (name + "/nodes/x") );
    mesh_nodes[1].read_from( hdf, (name + "/nodes/y") );
#if DIM==3
    mesh_nodes[2].read_from( hdf, (name + "/nodes/z") );
#endif
    
/*    //lecture des noeuds du maillage
    mesh_nodes.resize(DIM);
    mesh_nodes[0].read_from( hdf, name + "/mesh_nodes/x" );
    mesh_nodes[1].read_from( hdf, name + "/mesh_nodes/y" );
#if DIM==3
    mesh_nodes[2].read_from( hdf, name + "/mesh_nodes/z" );
#endif*/
    
    if(read_micro){

        //lecture des noeuds micro
        nodes.resize(DIM);
        nodes[0].read_from( hdf, (name + "/micro_nodes/x") );
        nodes[1].read_from( hdf, (name + "/micro_nodes/y") );
#if DIM==3
        nodes[2].read_from( hdf, (name + "/micro_nodes/z") );
#endif
    }else{
        nodes.resize(DIM);
        nodes[0].resize(0);
        nodes[1].resize(0);
#if DIM==3
        nodes[2].resize(0);
#endif
    }
}


void GeometryUser::read_tag_group_elements_hdf5(Hdf &hdf, Sc2String &name, bool read_micro) { 
    Sc2String name_group_0; name_group_0 << name << "/elements_0";
    BasicVec<Sc2String> list_groups;
    list_groups=hdf.list_dir( name_group_0 );
    for (unsigned ng=0;ng<group_elements.size();ng++) { 
        Sc2String name_list ;
        name_list<< name_group_0 << "/"<< list_groups[ng];
        int id;
        hdf.read_tag(name_list.c_str(),"id",id,1);
        group_elements[id].id=id;
        hdf.read_tag(name_list.c_str(),"pattern_id",group_elements[id].pattern_id,1);
        hdf.read_tag(name_list.c_str(),"pattern_base_id",group_elements[id].pattern_base_id,1);
        hdf.read_tag(name_list.c_str(),"nb_elements",group_elements[id].nb_elements,1);
    }
}


void GeometryUser::read_infos_group_elements_hdf5(Hdf &hdf, Sc2String &name, bool read_micro) { 
    Sc2String name_group_0; name_group_0 << name << "/elements_0";
    BasicVec<Sc2String> list_groups;
    list_groups=hdf.list_dir( name_group_0 );
    for (unsigned ng=0;ng<group_elements.size();ng++) { 
        Sc2String name_list ;
        name_list<< name_group_0 << "/"<< list_groups[ng];
        int id;
        hdf.read_tag(name_list.c_str(),"id",id,1);
        //lecture des noeuds locaux
        Sc2String name_map;
        name_map << name_list << "/map_global_nodes" ;
        group_elements[id].map_global_nodes.read_from( hdf, name_map.c_str() );
        
        group_elements[id].local_nodes.resize(DIM);
        BasicVec < Sc2String , 3 > name_direction("x","y","z");
        for(int d=0; d<DIM; d++){
            Sc2String name_dim;
            name_dim << name_list << "/local_nodes/" << name_direction[d];
            group_elements[id].local_nodes[d].read_from( hdf, name_dim.c_str() );
        }
        
        //lecture des connectivités
        int nb_mesh_nodes = patterns.find_type(group_elements[id].pattern_base_id).nb_nodes;
        int nb_nodes = patterns.find_type(group_elements[id].pattern_id).nb_nodes;
        int nb_sides = patterns.find_type(group_elements[id].pattern_id).nb_sides;
        
        group_elements[id].local_connectivities.resize(nb_mesh_nodes);
        group_elements[id].global_connectivities.resize(nb_mesh_nodes);
        group_elements[id].connectivities.resize(nb_nodes);
        
        for (unsigned i_connect=0;i_connect<group_elements[id].local_connectivities.size();i_connect++) {
            Sc2String name_connect;
            name_connect << name_list << "/local_connectivities_"<<i_connect;
            group_elements[id].local_connectivities[i_connect].read_from( hdf, name_connect.c_str() );
        }
        for (unsigned i_connect=0;i_connect<group_elements[id].global_connectivities.size();i_connect++) {
            Sc2String name_connect;
            name_connect << name_list << "/global_connectivities_"<<i_connect;
            group_elements[id].global_connectivities[i_connect].read_from( hdf, name_connect.c_str() );
        }
        if(read_micro){
            for (unsigned i_connect=0;i_connect<group_elements[id].connectivities.size();i_connect++) {
                Sc2String name_connect;
                name_connect << name_list << "/micro_connectivities_"<<i_connect;
                group_elements[id].connectivities[i_connect].read_from( hdf, name_connect.c_str() );
            }
        }else{
            for (unsigned i_connect=0;i_connect<group_elements[id].connectivities.size();i_connect++) {
                group_elements[id].connectivities[i_connect].resize(0);
            }
        }
        
        //lecture des sides pour chaque element (repere du groupe et du numéro local dans le groupe de l'interface voisine)
        BasicVec<Sc2String> list_side;
        list_side=hdf.list_dir( name_list + "/sides");
        group_elements[id].interface_group_id.resize(list_side.size());
        group_elements[id].interface_num_in_group.resize(list_side.size());
        for(unsigned nside=0;nside<group_elements[id].interface_group_id.size();nside++){
            Sc2String name_side_group_id;
            name_side_group_id << name_list << "/sides/" << list_side[nside] << "/interface_group_id";
            group_elements[id].interface_group_id[nside].read_from( hdf, name_side_group_id.c_str() );
            
            Sc2String name_side_num_in_group;
            name_side_num_in_group << name_list << "/sides/" << list_side[nside] << "/num_in_group" ;
            group_elements[id].interface_num_in_group[nside].read_from( hdf, name_side_num_in_group.c_str() );
        }
        //lecture des id des groupes d'interfaces voisins
        BasicVec<Sc2String> name_type("/id_group_interfaces_edges","/id_group_interfaces_interiors","/id_group_interfaces_links");
        group_elements[id].group_interfaces_id.resize(3);
        for(unsigned nside_g=0;nside_g<group_elements[id].group_interfaces_id.size();nside_g++){
            Metil::String name_side_g ;
            name_side_g<< name_group_0 << "/list_" << group_elements[id].id << name_type[nside_g] ;
            if ( hdf.dataset_exist(name_side_g) ){
                group_elements[id].group_interfaces_id[nside_g].read_from( hdf, name_side_g.c_str() );
            }
        }
    }
}


void GeometryUser::read_tag_group_interfaces_hdf5(Hdf &hdf, Sc2String &name, bool read_micro) { 
    Sc2String name_group_1;
    name_group_1 << name << "/elements_1";
    BasicVec<Sc2String> list_groups;
    list_groups=hdf.list_dir( name_group_1.c_str() );
    for (unsigned ng=0;ng<group_interfaces.size();ng++) {
        group_interfaces[ng].micro_loaded = read_micro;
        Sc2String name_list ;
        name_list<< name_group_1 << "/"<< list_groups[ng];
        int id;
        hdf.read_tag(name_list.c_str(),"id",id,1);
        group_interfaces[id].micro_loaded = read_micro;
        group_interfaces[id].id=id;
        hdf.read_tag(name_list.c_str(),"type",group_interfaces[id].type,1);
        hdf.read_tag(name_list.c_str(),"interface_id",group_interfaces[id].interface_id,1);
        hdf.read_tag(name_list.c_str(),"interface_base_id",group_interfaces[id].interface_base_id,1);
        hdf.read_tag(name_list.c_str(),"nb_interfaces",group_interfaces[id].nb_interfaces,1);
        
        if (group_interfaces[id].type==0) {//bord
            group_interfaces[id].group_elements_id.resize(1);
            group_interfaces[id].patterns_id.resize(1);
            hdf.read_tag(name_list.c_str(),"id_edge_of_0",group_interfaces[id].group_elements_id[0]);
            hdf.read_tag(name_list.c_str(),"id_pattern_group_elements_0",group_interfaces[id].patterns_id[0]);
            
        }
        else if (group_interfaces[id].type==1 or group_interfaces[id].type==2) {//interieur
            group_interfaces[id].group_elements_id.resize(2);
            group_interfaces[id].patterns_id.resize(2);
            hdf.read_tag(name_list.c_str(),"id_edge_of_0",group_interfaces[id].group_elements_id[0]);
            hdf.read_tag(name_list.c_str(),"id_edge_of_1",group_interfaces[id].group_elements_id[1]);
            hdf.read_tag(name_list.c_str(),"id_pattern_group_elements_0",group_interfaces[id].patterns_id[0]);
            hdf.read_tag(name_list.c_str(),"id_pattern_group_elements_1",group_interfaces[id].patterns_id[1]);
        }
//         group_interfaces[ng].affiche();
    }

}


void GeometryUser::read_infos_group_interfaces_hdf5(Hdf &hdf, Sc2String &name, bool read_micro) { 
    Sc2String name_group_1;
    name_group_1 << name << "/elements_1";
    BasicVec<Sc2String> list_groups;
    list_groups=hdf.list_dir( name_group_1.c_str() );
    for (unsigned ng=0;ng<group_interfaces.size();ng++) {
        Sc2String name_list ;
        name_list<< name_group_1 << "/"<< list_groups[ng];
        int id;
        hdf.read_tag(name_list.c_str(),"id",id,1);
        if(!read_micro and group_interfaces[id].type==1){
            
        }else{
/*            Sc2String name_list ;
            name_list<< name_group_1 << "/"<< list_groups[ng];*/
            
            //lecture des noeuds locaux
            Sc2String name_map;
            name_map << name_list << "/map_global_nodes" ;
            group_interfaces[id].map_global_nodes.read_from( hdf, name_map.c_str() );
            
            group_interfaces[id].local_nodes.resize(DIM);
            BasicVec < Sc2String , 3 > name_direction("x","y","z");
            for(int d=0; d<DIM; d++){
                Sc2String name_dim;
                name_dim << name_list << "/local_nodes/" << name_direction[d];
                group_interfaces[id].local_nodes[d].read_from( hdf, name_dim.c_str() );
            }
            
            //lecture des connectivités
            int nb_nodes_mesh = interfaces.find_type(group_interfaces[id].interface_base_id)->nb_nodes;
            int nb_nodes = interfaces.find_type(group_interfaces[id].interface_id)->nb_nodes;
            int nb_nodes_eq = interfaces.find_type(group_interfaces[id].interface_id)->nb_nodes_eq;
            
            group_interfaces[id].global_connectivities.resize(nb_nodes_mesh);
            group_interfaces[id].local_connectivities.resize(nb_nodes_mesh);
            
            for(unsigned nb_connect=0;nb_connect<group_interfaces[id].global_connectivities.size();nb_connect++) {
                Sc2String name_connect;
                name_connect << name_list << "/local_connectivities_" << nb_connect;
                group_interfaces[id].local_connectivities[nb_connect].read_from( hdf, name_connect.c_str() );
            }
            for(unsigned nb_connect=0;nb_connect<group_interfaces[id].global_connectivities.size();nb_connect++) {
                Sc2String name_connect;
                name_connect << name_list << "/global_connectivities_" << nb_connect;
                group_interfaces[id].global_connectivities[nb_connect].read_from( hdf, name_connect.c_str() );
            }
            if(read_micro){

            group_interfaces[id].connectivities.resize(nb_nodes);
                
                for (unsigned i_connect=0;i_connect<group_interfaces[id].connectivities.size();i_connect++) {
                    Sc2String name_connect;
                    name_connect << name_list << "/micro_connectivities_"<<i_connect;;
                    group_interfaces[id].connectivities[i_connect].read_from( hdf, name_connect.c_str() );
                }
            }else{
                for (unsigned i_connect=0;i_connect<group_interfaces[id].connectivities.size();i_connect++) {
                    group_interfaces[id].connectivities[i_connect].resize(0);
                }
            }

        //lecture du champ pour la visualisation des bords via l'interface utilisateur
//         Sc2String name_field;
//         name_field << name_list << "/to_visualize";
//         
//         group_interfaces[ng].to_visualize.read_from( hdf, name_field );

            //lecture des id des groupes d'elements voisins ainsi que de l'id du pattern des groupes adjacents
            //lecture des sides pour chaque element (repere du groupe et du numéro local dans le groupe de l'interface voisine)
            
            group_interfaces[id].element_num_in_group.resize(group_interfaces[id].group_elements_id.size());
            group_interfaces[id].element_num_side.resize(group_interfaces[id].group_elements_id.size());
            group_interfaces[id].patterns_id.resize(group_interfaces[id].group_elements_id.size());
            group_interfaces[id].nb_group_elements = group_interfaces[id].group_elements_id.size();
            for(unsigned nside_g=0;nside_g<group_interfaces[id].group_elements_id.size();nside_g++){
                Sc2String name_side ;
                name_side<< name_group_1 << "/list_" << group_interfaces[id].id << "/sides/side_" << nside_g ;
                Sc2String name_side_elements_id;
                name_side_elements_id << name_side << "/element_num_in_group";
                group_interfaces[id].element_num_in_group[nside_g].read_from( hdf, name_side_elements_id.c_str() );
                Sc2String name_side_num_side;
                name_side_num_side << name_side << "/element_num_side";            
                group_interfaces[id].element_num_side[nside_g].read_from( hdf, name_side_num_side.c_str() );
            }
        }
    }

}



void GeometryUser::read_hdf5(bool read_micro, bool read_all, Sc2String mode) {
    if (FileExists(name_file_hdf5.c_str())==0) {
        std::cerr << "Le fichier hdf5 "<< name_file_hdf5 << " n'existe pas " << std::endl;
        assert(0);
    }
    std::cout << " - Ouverture de " << name_file_hdf5 << std::endl;
    Hdf hdf( name_file_hdf5.c_str(),false,true );
    
    dim=DIM;
    
    Sc2String name;
    num_level=0;
    name << "/Level_" << num_level << "/Geometry";
    
    /// Lecture des noeuds du maillage
    std::cout << " - Lecture des nodes" << std::endl;
    read_node_hdf5(hdf, name.c_str(), read_micro);
    
    /// Lecture des maillages des sous-structures
    BasicVec<Sc2String> list_groups;
    if(mode!="visu_CL"){
        //lecture des groupes d'elements
        std::cout << " - Lecture des group_elements";
        Sc2String name_group_0; name_group_0 << name << "/elements_0";
        BasicVec<Sc2String> list_groups;
        list_groups=hdf.list_dir( name_group_0 );
        group_elements.resize(list_groups.size());
        nb_group_elements=group_elements.size();
        std::cout << " ---- Total : " << nb_group_elements << std::endl;
        
        read_tag_group_elements_hdf5(hdf,  name, read_micro);
        
        if(read_all){
            read_infos_group_elements_hdf5(hdf, name, read_micro);
        }
    }
    
    /// Lecture des maillages des interfaces
    std::cout << " - Lecture des group_interfaces";
    Sc2String name_group_1;
    name_group_1 << name << "/elements_1";
    list_groups=hdf.list_dir( name_group_1 );
    group_interfaces.reserve(list_groups.size()+10);
    group_interfaces.resize(list_groups.size());
    nb_group_interfaces=group_interfaces.size();
    std::cout << " ---- Total : " << nb_group_interfaces << std::endl;

    read_tag_group_interfaces_hdf5(hdf, name, read_micro);
    
    if(read_all)
        read_infos_group_interfaces_hdf5(hdf, name, read_micro);
}

#include "write_xdmf.h"

/** * Ecriture des DataItems : coordonnées des noeuds, connectivités classées par groupes, attributs
* Ecriture des groupes pour les éléemnts parents : Geometrie_0 : pieces_i
* Ecriture des groupes pour les éléments enfants en séparant les groupes de bord (Edges) et les liaisons entre pièces (Liaisons) : Geometrie_1 : Edges/Liaisons : Edge_i/Interface_i)
L'entier skin (0 ou 1) permet de sortir les groupes d'élements parents et enfants (skin=0) ou uniquement les éléments enfants (skin=1) **/
void GeometryUser::write_xdmf(Sc2String output_xdmf, Sc2String input_hdf5, Sc2String name_geometry, int skin){
    //ecriture de 3 fichiers séparés car trop long à lire sinon
    Sc2String output_xdmf_pieces=output_xdmf+"_pieces.xdmf";
    std::ofstream f_pieces(output_xdmf_pieces.c_str());
    Sc2String output_xdmf_pieces_skin=output_xdmf+"_pieces_skin.xdmf";
    std::ofstream f_pieces_skin(output_xdmf_pieces_skin.c_str());
    Sc2String output_xdmf_interfaces=output_xdmf+"_interfaces.xdmf";
    std::ofstream f_interfaces(output_xdmf_interfaces.c_str());

    //lecture des noeuds (commun à tous les fichiers)
    Sc2String  name_nodes = name_geometry + "/mesh_nodes";
    Hdf hdf(input_hdf5);
    int nb_nodes;
    Sc2String data_node_x; data_node_x << name_nodes << "/x";
    hdf.read_size(data_node_x,nb_nodes);
    
    //**********************************
    // ecriture du fichier de pieces
    //**********************************
    f_pieces << "<Xdmf Version=\"2.0\">" << std::endl;
    f_pieces << "  <Domain>" << std::endl;
    //ecriture des dataitems noeuds + attributs
    write_nodes_datasets(f_pieces,input_hdf5, name_nodes,nb_nodes,0);
    int nb_list;
    Sc2String name_group_elements; name_group_elements=name_geometry+"/elements_0";
    hdf.read_group_size(name_group_elements,nb_list);
    write_groups_datasets_2(f_pieces,input_hdf5, name_group_elements);
    
    //ecriture de la geometrie_0 (elements parents)
    BasicVec<Sc2String> attributs=("none");
    Sc2String name_fields="none";
    f_pieces<< "           <Grid Name=\"Geometry_0\" GridType=\"Tree\">" << std::endl;
    Sc2String generic_grid_name="piece";
    BasicVec<int> list;
    list.resize(nb_list);
     
    for(unsigned i=0;i<nb_list;i++) list[i]=i;
    write_grids(f_pieces,input_hdf5, name_group_elements,name_nodes, list,nb_nodes,generic_grid_name,name_fields,attributs,0,0,0,0);
    //write_grids_2(f, input_hdf5, name_elements_0, name_nodes, name_fields, generic_grid_name, attributs, 0, 0);
    f_pieces<<"            </Grid>"<< std::endl;
    f_pieces<<"    </Domain>"<< std::endl;
    f_pieces<<"</Xdmf>"<<std::endl;
    f_pieces.close();
    
//     //ecriture des dataitems list d'elements connectivites + champs par element
//     for (unsigned el=skin;el<2;el++) {
//         int nb_list;
//         Sc2String name_group_elements; name_group_elements<<name_geometry<<"/elements_"<<el;
//         hdf.read_group_size(name_group_elements,nb_list);
// /*        write_groups_datasets(f,input_hdf5, name_group_elements,nb_list,el);*/
//         write_groups_datasets_2(f,input_hdf5, name_group_elements);
//     }
//     
    
    //**********************************
    // ecriture du fichier des interfaces
    //**********************************
    f_interfaces << "<Xdmf Version=\"2.0\">" << std::endl;
    f_interfaces << "  <Domain>" << std::endl;
    //ecriture des dataitems noeuds + attributs
    write_nodes_datasets(f_interfaces,input_hdf5, name_nodes,nb_nodes,0);
    name_group_elements=name_geometry+"/elements_1";
    hdf.read_group_size(name_group_elements,nb_list);
    write_groups_datasets_2(f_interfaces,input_hdf5, name_group_elements);
       
    //ecriture de la geometrie_1 (elements enfants)
    f_interfaces<< "           <Grid Name=\"Geometry_1\" GridType=\"Tree\">" << std::endl;
    Sc2String name_elements_1;
    name_elements_1<<name_geometry<<"/elements_1";
    hdf.read_group_size(name_elements_1,nb_list);

    int nb_links=0, nb_edges=0;
    BasicVec<BasicVec<int>,3 > lists ;
    for (unsigned i=0; i< nb_list; i++) {
        Sc2String name_list;
        name_list << name_elements_1<<  "/list_" <<  i;
        int type=-1;
        hdf.read_tag(name_list,"type",type);
        if (type==0) {//bord
            lists[0].push_back(i);
        }
        else if (type==2) {//liaison entre 2 pièces
            lists[2].push_back(i);
        }
    }
 
    for (unsigned tl=0;tl<lists.size();tl++) {
        Sc2String generic_grid_name;
        if (tl==0) {//bord
            f_interfaces<<"                    <Grid Name=\" Edges \" GridType=\"Tree\">" << std::endl;
            generic_grid_name="Edge";
/*            write_grids_2(f,input_hdf5, name_elements_1, name_nodes, name_fields, generic_grid_name, attributs, 0, 0);*/
            write_grids(f_interfaces,input_hdf5, name_elements_1, name_nodes, lists[tl],nb_nodes,generic_grid_name,name_fields,attributs,0,0,1,0);
        }
        else if (tl==1) {
            continue;
        }
        else if (tl==2) {//liaison entre 2 pièces
            f_interfaces<<"                    <Grid Name=\" Liaisons \" GridType=\"Tree\" >" << std::endl;
            generic_grid_name="Interface";
            write_grids(f_interfaces,input_hdf5, name_elements_1,name_nodes, lists[tl],nb_nodes,generic_grid_name,name_fields,attributs,0,0,1,0);
        }
        
        f_interfaces<<"                 </Grid>"<< std::endl;
    }
    f_interfaces<<"            </Grid>"<<std::endl;
    f_interfaces<<"    </Domain>"<< std::endl;
    f_interfaces<<"</Xdmf>"<<std::endl;
    f_interfaces.close();
}

