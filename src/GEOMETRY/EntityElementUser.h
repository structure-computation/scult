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


#include <Metil/BasicVec.h>
#include <Metil/StructCompactor.h>

#include "Patterns.h"
// #include <boost/concept_check.hpp>

using namespace Metil;

#include "../UTILS/Sc2String.h"

#ifndef ENTITY_ELEMENT_USER_H
#define ENTITY_ELEMENT_USER_H

//définition d'une entité élément (utile dans MeshUser)------------------------------------------------------------------------
struct EntityElementUser{
    // attributs element du maillage
    int pattern_base_id;
    int num_in_mesh;
    int num_piece_in_mesh;
    TYPE jacobien;
    BasicVec< int > mesh_connectivity;
    
    //flag de l'element
    BasicVec< int > flags;
    BasicVec< Sc2String > flags_names;
    
    // attributs elements correspondant au pattern
    int id;
    int pattern_id;
    int group_id;
    int num_in_group;
    BasicVec< int > element_connectivity;
    BasicVec< int > interfaces_global_num;
    BasicVec< int > interfaces_group_id;
    BasicVec< int > interfaces_num_in_group;
    
    int nb_sides;
    
    // méthodes
    EntityElementUser(){}
    EntityElementUser(int pattern_base_id_, int num, int num_piece_in_mesh_, BasicVec<int> &mesh_connectivity_, int nb_sides_pattern_){
        pattern_base_id = pattern_base_id_;
        mesh_connectivity.resize(mesh_connectivity_.size());
        num_in_mesh = num;
        num_piece_in_mesh = num_piece_in_mesh_;
        mesh_connectivity = mesh_connectivity_;
        nb_sides = nb_sides_pattern_;
        
        interfaces_global_num.resize(nb_sides_pattern_,-1);
        interfaces_group_id.resize(nb_sides_pattern_,-1);
        interfaces_num_in_group.resize(nb_sides_pattern_,-1);
    }
    void define_element(int id_, BasicVec<int> &element_connectivity_, int pattern_id_){
        id = id_;
        pattern_id = pattern_id_;
        element_connectivity.resize(element_connectivity_.size());
        element_connectivity = element_connectivity_;
        define_flags();
    }
    void define_flags(){
        flags_names.resize(2);
        flags.resize(2);
        flags_names[0] = "num_piece_in_mesh";
        flags_names[1] = "pattern_id";
        flags[0] = num_piece_in_mesh;
        flags[1] = pattern_id;
    }
    int find_flag_index(Sc2String flag_name){
        int num_flag = -1;
        for( int i_flag=0; i_flag<flags.size(); i_flag++){
            if(flags_names[i_flag] == flag_name){
                num_flag = i_flag;
            }
        }
        return num_flag;
    }
    bool valid_flags(BasicVec< int > &flags_test, BasicVec< Sc2String > &flags_test_names){
        bool flags_valid = true;
        for( int i_flag_test=0; i_flag_test<flags_test.size(); i_flag_test++){
            int i_flag = find_flag_index(flags_test_names[i_flag_test]);
            if(i_flag == -1){
                flags_valid = false;
                break;
            }else if(flags_test[i_flag_test] != flags[i_flag]){
                flags_valid = false;
                break; 
            }
        }
        return flags_valid;
    }
    void affiche(){
//         PRINT("element-----------------------------------------------------------");
//         PRINT(id); 
//         PRINT(pattern_base_id);
//         PRINT(num_in_mesh);
//         PRINT(num_piece_in_mesh);
//         PRINT(mesh_connectivity);
//         PRINT(interfaces_global_num);  
//         PRINT("pattern");
//         PRINT(pattern_id); 
//         PRINT(nb_sides);
//         PRINT(element_connectivity);  
//         PRINT(group_id);
//         PRINT(num_in_group);
    }  
};


#endif //ENTITY_ELEMENT_USER_H


