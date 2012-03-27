//
// C++ Interface: Définition des group_elements et group_interfaces
//
// Description: 
//
//
// Author: Jeremie Bellec <j.bellec@structure-computation.com>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//


#ifndef ENTITY_INTERFACE_USER_H
#define ENTITY_INTERFACE_USER_H

#include <Metil/BasicVec.h>
#include <Metil/StructCompactor.h>
#include <Metil/String.h>

#include "Patterns.h"
// #include <boost/concept_check.hpp>

using namespace Metil;


//définition d'une entité interface (utile dans MeshUser)------------------------------------------------------------------------
struct EntityInterfaceUser{
    // attributs
    int id;
    int mesh_type;
    int nb_sides;
    int group_id;
    int num_in_group;
    
    BasicVec< int > mesh_connectivity;
    BasicVec< int > elements_num_piece_in_mesh;
    
    BasicVec< int > interface_connectivity;                   // connectivité de l'interface / nodes de geometry
    BasicVec< int > elements_global_num;                      // numéro global pour dans le maillage chaque element adjacent 
    BasicVec< int > elements_num_side;                        // numéro du side pour chaque element adjacent
    BasicVec< int > elements_group_id;                        // id du groupe pour chaque element adjacent
    BasicVec< int > elements_num_in_group;                    // numéro local dans leur groupe pour chaque element adjacent
    BasicVec< int > correspondance_between_nodes;
    
    // méthodes
    EntityInterfaceUser(){
        nb_sides = 1;
        elements_num_piece_in_mesh.resize(nb_sides,-1);
        elements_global_num.resize(nb_sides,-1);
        elements_num_side.resize(nb_sides,-1);
        elements_group_id.resize(nb_sides,-1);
        elements_num_in_group.resize(nb_sides,-1);
    }
    EntityInterfaceUser(int id_, int group_id_, BasicVec< int > mesh_connectivity_, int first_elem, int num_side, int first_elements_num_piece_in_mesh, BasicVec< int > correspondance_between_nodes_){
        id = id_;
        nb_sides = 1;
        mesh_type = 0 ;
        group_id = group_id_;
        mesh_connectivity = mesh_connectivity_;
        elements_num_piece_in_mesh.resize(nb_sides,-1);
        elements_global_num.resize(nb_sides,-1);
        elements_num_side.resize(nb_sides,-1);
        elements_group_id.resize(nb_sides,-1);
        elements_num_in_group.resize(nb_sides,-1);
        elements_global_num[0] = first_elem;
        elements_num_side[0] = num_side;
        elements_num_piece_in_mesh[0] = first_elements_num_piece_in_mesh;
        correspondance_between_nodes.resize(correspondance_between_nodes_.size());
        correspondance_between_nodes = correspondance_between_nodes_;
    }
    // ajout d'un side au moment de la création des listes d'interface-----------------
    void add_side(int i_elem, int num_side, BasicVec< EntityElementUser > &list_elements){
        nb_sides = 2;
        elements_num_piece_in_mesh.resize(nb_sides);
        elements_global_num.resize(nb_sides);
        elements_num_side.resize(nb_sides);
        elements_group_id.resize(nb_sides);
        elements_num_in_group.resize(nb_sides);
        elements_global_num[1] = i_elem ;
        elements_num_side[1] = num_side ;      
        elements_num_piece_in_mesh[1] = list_elements[i_elem].num_piece_in_mesh ;
        elements_group_id[1] = -1 ;
        mesh_type = 1;
    }
    // validation des flags des deux entity_element adjacents par rapport aux flags de deux group_elements
    bool valid_group_elements( BasicVec< EntityElementUser > &list_elements, BasicVec< int > &group_elements_id, Patterns &patterns ){
        bool group_elements_valid = true;
        //test du type d'interface
        if(group_elements_id.size() != elements_global_num.size()){
            group_elements_valid = false;
        }else if(group_elements_id.size() == 1){
            if(list_elements[elements_global_num[0]].group_id == group_elements_id[0]){
                elements_group_id[0] = list_elements[elements_global_num[0]].group_id;
                elements_num_in_group[0] = list_elements[elements_global_num[0]].num_in_group;
            }else{
                group_elements_valid = false;
            }
        }else{
            if(list_elements[elements_global_num[0]].group_id == group_elements_id[0] && list_elements[elements_global_num[1]].group_id == group_elements_id[1]){
                elements_group_id[0] = list_elements[elements_global_num[0]].group_id;
                elements_num_in_group[0] = list_elements[elements_global_num[0]].num_in_group;  
                elements_group_id[1] = list_elements[elements_global_num[1]].group_id;
                elements_num_in_group[1] = list_elements[elements_global_num[1]].num_in_group;
            }else if(list_elements[elements_global_num[0]].group_id == group_elements_id[1] && list_elements[elements_global_num[1]].group_id == group_elements_id[0]){
                elements_group_id[0] = list_elements[elements_global_num[0]].group_id;
                elements_num_in_group[0] = list_elements[elements_global_num[0]].num_in_group;  
                elements_group_id[1] = list_elements[elements_global_num[1]].group_id;
                elements_num_in_group[1] = list_elements[elements_global_num[1]].num_in_group;
                // on réordonne les connectivité avec les éléments pour les mettre dans le même ordre que le group
                BasicVec< int, 2 > temp_elements_global_num;
                BasicVec< int, 2 > temp_elements_num_side;
                BasicVec< int, 2 > temp_elements_group_id;
                BasicVec< int, 2 > temp_elements_num_in_group;
                for(int i_elem=0; i_elem<elements_global_num.size(); i_elem++){
                    temp_elements_global_num[i_elem]   = elements_global_num[1-i_elem];
                    temp_elements_num_side[i_elem]     = elements_num_side[1-i_elem];
                    temp_elements_group_id[i_elem]    = elements_group_id[1-i_elem];
                    temp_elements_num_in_group[i_elem] = elements_num_in_group[1-i_elem];
                }
                elements_global_num    = temp_elements_global_num;
                elements_num_side      = temp_elements_num_side;
                elements_group_id      = temp_elements_group_id;
                elements_num_in_group  = temp_elements_num_in_group;
            }else{
                group_elements_valid = false;
            }
        }
        return group_elements_valid;
        
    }
    void calcul_interface_connectivity(BasicVec< EntityElementUser > &list_elements, Patterns &patterns){
        int pattern_id = list_elements[elements_global_num[0]].pattern_id;
        int nb_node_by_side_pattern = patterns.find_type(pattern_id).nb_nodes_by_sides;
        int num_side = elements_num_side[0];
        BasicVec< int > order_nodes = patterns.find_type(pattern_id).sides[num_side];
        interface_connectivity.resize(nb_node_by_side_pattern);
        for(int i_node=0; i_node<nb_node_by_side_pattern; i_node++){
            interface_connectivity[i_node] = list_elements[elements_global_num[0]].element_connectivity[order_nodes[i_node]];
        }
    }
    void affiche(){
        PRINT("interface-----------------------------------------------------------");
        PRINT(id);
        PRINT(mesh_type);
        PRINT(group_id);
//         PRINT(elements_num_piece_in_mesh);
//         PRINT(elements_global_num);
//         PRINT(elements_group_id);
//         PRINT(elements_num_in_group);
//         PRINT(elements_num_side);
//         PRINT(mesh_connectivity);
//         PRINT(interface_connectivity);
    }
    
};

#endif //ENTITY_INTERFACE_USER_H


