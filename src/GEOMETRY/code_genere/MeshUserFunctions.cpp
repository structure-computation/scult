//
// Description: fichier généré par GEOM_MESH_USER_FUNCTIONS.met 
//
//
// Author: Jeremie Bellec <j.bellec@structure-computation.com>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "MeshUser.h"

using namespace Metil;

// changement de la connectivité d'un element du maillage ---------------------------------------------------------------
void MeshUser::change_mesh_connectivity(int i_elem) { 
    switch (list_elements[i_elem].pattern_base_id){
        //pour le element PATTERN_Triangle
        case 0 :{
            list_elements[i_elem].jacobien = (mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[1]]-mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[0]])*(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[2]]-mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[0]])-(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[2]]-mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[0]])*(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[1]]-mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[0]]) ;
        }
        break;
        //pour le element PATTERN_Triangle_6
        case 1 :{
            list_elements[i_elem].jacobien = (1.0/3.0*(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[1]]-mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[0]])-4.0/3.0*(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[5]]-mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[4]]))*(1.0/3.0*(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[2]]-mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[0]])-4.0/3.0*(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[3]]-mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[4]]))-(-4.0/3.0*(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[3]]-mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[4]])-1.0/3.0*(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[0]]-mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[2]]))*(-4.0/3.0*(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[5]]-mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[4]])-1.0/3.0*(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[0]]-mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[1]])) ;
        }
        break;
        //pour le element PATTERN_Tetra
        case 2 :{
            list_elements[i_elem].jacobien = (mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[3]]-mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[0]])*((mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[1]]-mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[0]])*(mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[2]]-mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[0]])-(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[2]]-mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[0]])*(mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[1]]-mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[0]]))+(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[1]]-mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[0]])*((mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[2]]-mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[0]])*(mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[3]]-mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[0]])-(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[3]]-mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[0]])*(mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[2]]-mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[0]]))-(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[2]]-mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[0]])*((mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[1]]-mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[0]])*(mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[3]]-mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[0]])-(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[3]]-mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[0]])*(mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[1]]-mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[0]])) ;
        }
        break;
        //pour le element PATTERN_Tetra_10
        case 3 :{
            list_elements[i_elem].jacobien = (-(mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[7]]+mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[6]]-mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[5]]-mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[8]])*(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[6]]+mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[4]]-mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[9]]-mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[8]])-(mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[8]]+mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[9]]-mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[6]]-mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[4]])*(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[6]]+mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[7]]-mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[5]]-mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[8]]))*(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[7]]+mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[4]]-mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[5]]-mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[9]])+(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[9]]+mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[8]]-mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[6]]-mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[4]])*((mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[7]]+mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[6]]-mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[5]]-mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[8]])*(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[5]]+mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[9]]-mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[4]]-mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[7]])-(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[6]]+mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[7]]-mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[5]]-mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[8]])*(mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[9]]+mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[5]]-mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[4]]-mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[7]]))-(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[6]]+mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[7]]-mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[8]]-mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[5]])*((mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[6]]+mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[4]]-mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[9]]-mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[8]])*(mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[9]]+mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[5]]-mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[4]]-mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[7]])+(mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[8]]+mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[9]]-mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[6]]-mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[4]])*(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[5]]+mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[9]]-mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[4]]-mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[7]])) ;
        }
        break;
    }
    if(list_elements[i_elem].jacobien<0){
        BasicVec<int> current_connectivity;
        current_connectivity.resize(list_elements[i_elem].mesh_connectivity.size(),-1);
        //PRINT(list_elements[i_elem].mesh_connectivity.size());
        //PRINT(patterns.find_type(list_elements[i_elem].pattern_base_id).permutation);
        for(int i=0; i<list_elements[i_elem].mesh_connectivity.size(); i++){
            current_connectivity[i] = list_elements[i_elem].mesh_connectivity[patterns.find_type(list_elements[i_elem].pattern_base_id).permutation[i]]; 
        }
        list_elements[i_elem].mesh_connectivity = current_connectivity;
    }
}
// création des interfaces par comparaison des numéro des noeuds des children ---------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------------------
void MeshUser::create_list_interfaces(int i_elem) { 
    switch (list_elements[i_elem].pattern_base_id){
        //pour le element PATTERN_Triangle ----------------------------
        case 0 :{
            BasicVec<int,2> num_node;    
            int num_side;
            bool add_I;

    
            num_side = 0;
            num_node[0] = list_elements[i_elem].mesh_connectivity[0];
            num_node[1] = list_elements[i_elem].mesh_connectivity[1];
            add_I = true;
            //for(int i=0; i<list_interfaces.size(); i++){
            for(int ii=0; ii<list_interfaces_type_0.size(); ii++){
                int i = list_interfaces_type_0[ii];
                //if(list_interfaces[i].mesh_type != 0){}
                //else{
                    bool find_inter = true;
                    BasicVec<int> current_repnode;
                    for(int i_node=0; i_node<2; i_node++){
                        bool find_node = false;
                        for(int i_connect=0; i_connect<2; i_connect++){
                            if(num_node[i_node] == list_interfaces[i].mesh_connectivity[i_connect]){
                                current_repnode.push_back(i_connect);
                                find_node = true;
                                break;
                            }
                        }
                        if(!find_node){
                            find_inter = false;
                            break;
                        }
                    }
                    if(find_inter){
                        add_I = false;
                        list_interfaces[i].add_side(i_elem, num_side, list_elements);
                        list_elements[i_elem].interfaces_global_num[num_side] = list_interfaces[i].id;

                        list_interfaces_type_0.remove_unordered(ii);
                        break;
                    }
                //}
            }
            if(add_I){
                BasicVec<int, 3> repnode(1,2,0);
                EntityInterfaceUser current_interface(nb_interfaces, -1, num_node, i_elem, num_side, list_elements[i_elem].num_piece_in_mesh, repnode);
                list_interfaces.push_back(current_interface);
                list_elements[i_elem].interfaces_global_num[num_side] = nb_interfaces;
                list_interfaces_type_0.push_back(nb_interfaces);
                nb_interfaces = nb_interfaces + 1;
            } 
    
            num_side = 1;
            num_node[0] = list_elements[i_elem].mesh_connectivity[1];
            num_node[1] = list_elements[i_elem].mesh_connectivity[2];
            add_I = true;
            //for(int i=0; i<list_interfaces.size(); i++){
            for(int ii=0; ii<list_interfaces_type_0.size(); ii++){
                int i = list_interfaces_type_0[ii];
                //if(list_interfaces[i].mesh_type != 0){}
                //else{
                    bool find_inter = true;
                    BasicVec<int> current_repnode;
                    for(int i_node=0; i_node<2; i_node++){
                        bool find_node = false;
                        for(int i_connect=0; i_connect<2; i_connect++){
                            if(num_node[i_node] == list_interfaces[i].mesh_connectivity[i_connect]){
                                current_repnode.push_back(i_connect);
                                find_node = true;
                                break;
                            }
                        }
                        if(!find_node){
                            find_inter = false;
                            break;
                        }
                    }
                    if(find_inter){
                        add_I = false;
                        list_interfaces[i].add_side(i_elem, num_side, list_elements);
                        list_elements[i_elem].interfaces_global_num[num_side] = list_interfaces[i].id;

                        list_interfaces_type_0.remove_unordered(ii);
                        break;
                    }
                //}
            }
            if(add_I){
                BasicVec<int, 3> repnode(1,2,0);
                EntityInterfaceUser current_interface(nb_interfaces, -1, num_node, i_elem, num_side, list_elements[i_elem].num_piece_in_mesh, repnode);
                list_interfaces.push_back(current_interface);
                list_elements[i_elem].interfaces_global_num[num_side] = nb_interfaces;
                list_interfaces_type_0.push_back(nb_interfaces);
                nb_interfaces = nb_interfaces + 1;
            } 
    
            num_side = 2;
            num_node[0] = list_elements[i_elem].mesh_connectivity[2];
            num_node[1] = list_elements[i_elem].mesh_connectivity[0];
            add_I = true;
            //for(int i=0; i<list_interfaces.size(); i++){
            for(int ii=0; ii<list_interfaces_type_0.size(); ii++){
                int i = list_interfaces_type_0[ii];
                //if(list_interfaces[i].mesh_type != 0){}
                //else{
                    bool find_inter = true;
                    BasicVec<int> current_repnode;
                    for(int i_node=0; i_node<2; i_node++){
                        bool find_node = false;
                        for(int i_connect=0; i_connect<2; i_connect++){
                            if(num_node[i_node] == list_interfaces[i].mesh_connectivity[i_connect]){
                                current_repnode.push_back(i_connect);
                                find_node = true;
                                break;
                            }
                        }
                        if(!find_node){
                            find_inter = false;
                            break;
                        }
                    }
                    if(find_inter){
                        add_I = false;
                        list_interfaces[i].add_side(i_elem, num_side, list_elements);
                        list_elements[i_elem].interfaces_global_num[num_side] = list_interfaces[i].id;

                        list_interfaces_type_0.remove_unordered(ii);
                        break;
                    }
                //}
            }
            if(add_I){
                BasicVec<int, 3> repnode(1,2,0);
                EntityInterfaceUser current_interface(nb_interfaces, -1, num_node, i_elem, num_side, list_elements[i_elem].num_piece_in_mesh, repnode);
                list_interfaces.push_back(current_interface);
                list_elements[i_elem].interfaces_global_num[num_side] = nb_interfaces;
                list_interfaces_type_0.push_back(nb_interfaces);
                nb_interfaces = nb_interfaces + 1;
            } 
        }
        break;
        //pour le element PATTERN_Triangle_6 ----------------------------
        case 1 :{
            BasicVec<int,3> num_node;    
            int num_side;
            bool add_I;

    
            num_side = 0;
            num_node[0] = list_elements[i_elem].mesh_connectivity[0];
            num_node[1] = list_elements[i_elem].mesh_connectivity[1];
            num_node[2] = list_elements[i_elem].mesh_connectivity[3];
            add_I = true;
            //for(int i=0; i<list_interfaces.size(); i++){
            for(int ii=0; ii<list_interfaces_type_0.size(); ii++){
                int i = list_interfaces_type_0[ii];
                //if(list_interfaces[i].mesh_type != 0){}
                //else{
                    bool find_inter = true;
                    BasicVec<int> current_repnode;
                    for(int i_node=0; i_node<3; i_node++){
                        bool find_node = false;
                        for(int i_connect=0; i_connect<3; i_connect++){
                            if(num_node[i_node] == list_interfaces[i].mesh_connectivity[i_connect]){
                                current_repnode.push_back(i_connect);
                                find_node = true;
                                break;
                            }
                        }
                        if(!find_node){
                            find_inter = false;
                            break;
                        }
                    }
                    if(find_inter){
                        add_I = false;
                        list_interfaces[i].add_side(i_elem, num_side, list_elements);
                        list_elements[i_elem].interfaces_global_num[num_side] = list_interfaces[i].id;

                        list_interfaces_type_0.remove_unordered(ii);
                        break;
                    }
                //}
            }
            if(add_I){
                BasicVec<int, 3> repnode(1,2,0);
                EntityInterfaceUser current_interface(nb_interfaces, -1, num_node, i_elem, num_side, list_elements[i_elem].num_piece_in_mesh, repnode);
                list_interfaces.push_back(current_interface);
                list_elements[i_elem].interfaces_global_num[num_side] = nb_interfaces;
                list_interfaces_type_0.push_back(nb_interfaces);
                nb_interfaces = nb_interfaces + 1;
            } 
    
            num_side = 1;
            num_node[0] = list_elements[i_elem].mesh_connectivity[1];
            num_node[1] = list_elements[i_elem].mesh_connectivity[2];
            num_node[2] = list_elements[i_elem].mesh_connectivity[4];
            add_I = true;
            //for(int i=0; i<list_interfaces.size(); i++){
            for(int ii=0; ii<list_interfaces_type_0.size(); ii++){
                int i = list_interfaces_type_0[ii];
                //if(list_interfaces[i].mesh_type != 0){}
                //else{
                    bool find_inter = true;
                    BasicVec<int> current_repnode;
                    for(int i_node=0; i_node<3; i_node++){
                        bool find_node = false;
                        for(int i_connect=0; i_connect<3; i_connect++){
                            if(num_node[i_node] == list_interfaces[i].mesh_connectivity[i_connect]){
                                current_repnode.push_back(i_connect);
                                find_node = true;
                                break;
                            }
                        }
                        if(!find_node){
                            find_inter = false;
                            break;
                        }
                    }
                    if(find_inter){
                        add_I = false;
                        list_interfaces[i].add_side(i_elem, num_side, list_elements);
                        list_elements[i_elem].interfaces_global_num[num_side] = list_interfaces[i].id;

                        list_interfaces_type_0.remove_unordered(ii);
                        break;
                    }
                //}
            }
            if(add_I){
                BasicVec<int, 3> repnode(1,2,0);
                EntityInterfaceUser current_interface(nb_interfaces, -1, num_node, i_elem, num_side, list_elements[i_elem].num_piece_in_mesh, repnode);
                list_interfaces.push_back(current_interface);
                list_elements[i_elem].interfaces_global_num[num_side] = nb_interfaces;
                list_interfaces_type_0.push_back(nb_interfaces);
                nb_interfaces = nb_interfaces + 1;
            } 
    
            num_side = 2;
            num_node[0] = list_elements[i_elem].mesh_connectivity[2];
            num_node[1] = list_elements[i_elem].mesh_connectivity[0];
            num_node[2] = list_elements[i_elem].mesh_connectivity[5];
            add_I = true;
            //for(int i=0; i<list_interfaces.size(); i++){
            for(int ii=0; ii<list_interfaces_type_0.size(); ii++){
                int i = list_interfaces_type_0[ii];
                //if(list_interfaces[i].mesh_type != 0){}
                //else{
                    bool find_inter = true;
                    BasicVec<int> current_repnode;
                    for(int i_node=0; i_node<3; i_node++){
                        bool find_node = false;
                        for(int i_connect=0; i_connect<3; i_connect++){
                            if(num_node[i_node] == list_interfaces[i].mesh_connectivity[i_connect]){
                                current_repnode.push_back(i_connect);
                                find_node = true;
                                break;
                            }
                        }
                        if(!find_node){
                            find_inter = false;
                            break;
                        }
                    }
                    if(find_inter){
                        add_I = false;
                        list_interfaces[i].add_side(i_elem, num_side, list_elements);
                        list_elements[i_elem].interfaces_global_num[num_side] = list_interfaces[i].id;

                        list_interfaces_type_0.remove_unordered(ii);
                        break;
                    }
                //}
            }
            if(add_I){
                BasicVec<int, 3> repnode(1,2,0);
                EntityInterfaceUser current_interface(nb_interfaces, -1, num_node, i_elem, num_side, list_elements[i_elem].num_piece_in_mesh, repnode);
                list_interfaces.push_back(current_interface);
                list_elements[i_elem].interfaces_global_num[num_side] = nb_interfaces;
                list_interfaces_type_0.push_back(nb_interfaces);
                nb_interfaces = nb_interfaces + 1;
            } 
        }
        break;
        //pour le element PATTERN_Tetra ----------------------------
        case 2 :{
            BasicVec<int,3> num_node;    
            int num_side;
            bool add_I;

    
            num_side = 0;
            num_node[0] = list_elements[i_elem].mesh_connectivity[0];
            num_node[1] = list_elements[i_elem].mesh_connectivity[2];
            num_node[2] = list_elements[i_elem].mesh_connectivity[1];
            add_I = true;
            //for(int i=0; i<list_interfaces.size(); i++){
            for(int ii=0; ii<list_interfaces_type_0.size(); ii++){
                int i = list_interfaces_type_0[ii];
                //if(list_interfaces[i].mesh_type != 0){}
                //else{
                    bool find_inter = true;
                    BasicVec<int> current_repnode;
                    for(int i_node=0; i_node<3; i_node++){
                        bool find_node = false;
                        for(int i_connect=0; i_connect<3; i_connect++){
                            if(num_node[i_node] == list_interfaces[i].mesh_connectivity[i_connect]){
                                current_repnode.push_back(i_connect);
                                find_node = true;
                                break;
                            }
                        }
                        if(!find_node){
                            find_inter = false;
                            break;
                        }
                    }
                    if(find_inter){
                        add_I = false;
                        list_interfaces[i].add_side(i_elem, num_side, list_elements);
                        list_elements[i_elem].interfaces_global_num[num_side] = list_interfaces[i].id;

                        BasicVec<int, 6> repnode_test(0,1,2,3,4,5);
                        BasicVec<int, 6> repnode_0(0,2,1,5,4,3);
                        BasicVec<int, 6> repnode_1(1,0,2,3,5,4);
                        BasicVec<int, 6> repnode_2(2,1,0,4,3,5);
                        
                        BasicVec<int, 6> repnode;
                        if(current_repnode[0]==0){repnode = repnode_0;}
                        if(current_repnode[0]==1){repnode = repnode_1;}
                        if(current_repnode[0]==2){repnode = repnode_2;}
                        list_interfaces[i].correspondance_between_nodes=repnode;

                        list_interfaces_type_0.remove_unordered(ii);
                        break;
                    }
                //}
            }
            if(add_I){
                BasicVec<int, 6> repnode(0,2,1,5,4,3);
                EntityInterfaceUser current_interface(nb_interfaces, -1, num_node, i_elem, num_side, list_elements[i_elem].num_piece_in_mesh, repnode);
                list_interfaces.push_back(current_interface);
                list_elements[i_elem].interfaces_global_num[num_side] = nb_interfaces;
                list_interfaces_type_0.push_back(nb_interfaces);
                nb_interfaces = nb_interfaces + 1;
            } 
    
            num_side = 1;
            num_node[0] = list_elements[i_elem].mesh_connectivity[0];
            num_node[1] = list_elements[i_elem].mesh_connectivity[1];
            num_node[2] = list_elements[i_elem].mesh_connectivity[3];
            add_I = true;
            //for(int i=0; i<list_interfaces.size(); i++){
            for(int ii=0; ii<list_interfaces_type_0.size(); ii++){
                int i = list_interfaces_type_0[ii];
                //if(list_interfaces[i].mesh_type != 0){}
                //else{
                    bool find_inter = true;
                    BasicVec<int> current_repnode;
                    for(int i_node=0; i_node<3; i_node++){
                        bool find_node = false;
                        for(int i_connect=0; i_connect<3; i_connect++){
                            if(num_node[i_node] == list_interfaces[i].mesh_connectivity[i_connect]){
                                current_repnode.push_back(i_connect);
                                find_node = true;
                                break;
                            }
                        }
                        if(!find_node){
                            find_inter = false;
                            break;
                        }
                    }
                    if(find_inter){
                        add_I = false;
                        list_interfaces[i].add_side(i_elem, num_side, list_elements);
                        list_elements[i_elem].interfaces_global_num[num_side] = list_interfaces[i].id;

                        BasicVec<int, 6> repnode_test(0,1,2,3,4,5);
                        BasicVec<int, 6> repnode_0(0,2,1,5,4,3);
                        BasicVec<int, 6> repnode_1(1,0,2,3,5,4);
                        BasicVec<int, 6> repnode_2(2,1,0,4,3,5);
                        
                        BasicVec<int, 6> repnode;
                        if(current_repnode[0]==0){repnode = repnode_0;}
                        if(current_repnode[0]==1){repnode = repnode_1;}
                        if(current_repnode[0]==2){repnode = repnode_2;}
                        list_interfaces[i].correspondance_between_nodes=repnode;

                        list_interfaces_type_0.remove_unordered(ii);
                        break;
                    }
                //}
            }
            if(add_I){
                BasicVec<int, 6> repnode(0,2,1,5,4,3);
                EntityInterfaceUser current_interface(nb_interfaces, -1, num_node, i_elem, num_side, list_elements[i_elem].num_piece_in_mesh, repnode);
                list_interfaces.push_back(current_interface);
                list_elements[i_elem].interfaces_global_num[num_side] = nb_interfaces;
                list_interfaces_type_0.push_back(nb_interfaces);
                nb_interfaces = nb_interfaces + 1;
            } 
    
            num_side = 2;
            num_node[0] = list_elements[i_elem].mesh_connectivity[0];
            num_node[1] = list_elements[i_elem].mesh_connectivity[3];
            num_node[2] = list_elements[i_elem].mesh_connectivity[2];
            add_I = true;
            //for(int i=0; i<list_interfaces.size(); i++){
            for(int ii=0; ii<list_interfaces_type_0.size(); ii++){
                int i = list_interfaces_type_0[ii];
                //if(list_interfaces[i].mesh_type != 0){}
                //else{
                    bool find_inter = true;
                    BasicVec<int> current_repnode;
                    for(int i_node=0; i_node<3; i_node++){
                        bool find_node = false;
                        for(int i_connect=0; i_connect<3; i_connect++){
                            if(num_node[i_node] == list_interfaces[i].mesh_connectivity[i_connect]){
                                current_repnode.push_back(i_connect);
                                find_node = true;
                                break;
                            }
                        }
                        if(!find_node){
                            find_inter = false;
                            break;
                        }
                    }
                    if(find_inter){
                        add_I = false;
                        list_interfaces[i].add_side(i_elem, num_side, list_elements);
                        list_elements[i_elem].interfaces_global_num[num_side] = list_interfaces[i].id;

                        BasicVec<int, 6> repnode_test(0,1,2,3,4,5);
                        BasicVec<int, 6> repnode_0(0,2,1,5,4,3);
                        BasicVec<int, 6> repnode_1(1,0,2,3,5,4);
                        BasicVec<int, 6> repnode_2(2,1,0,4,3,5);
                        
                        BasicVec<int, 6> repnode;
                        if(current_repnode[0]==0){repnode = repnode_0;}
                        if(current_repnode[0]==1){repnode = repnode_1;}
                        if(current_repnode[0]==2){repnode = repnode_2;}
                        list_interfaces[i].correspondance_between_nodes=repnode;

                        list_interfaces_type_0.remove_unordered(ii);
                        break;
                    }
                //}
            }
            if(add_I){
                BasicVec<int, 6> repnode(0,2,1,5,4,3);
                EntityInterfaceUser current_interface(nb_interfaces, -1, num_node, i_elem, num_side, list_elements[i_elem].num_piece_in_mesh, repnode);
                list_interfaces.push_back(current_interface);
                list_elements[i_elem].interfaces_global_num[num_side] = nb_interfaces;
                list_interfaces_type_0.push_back(nb_interfaces);
                nb_interfaces = nb_interfaces + 1;
            } 
    
            num_side = 3;
            num_node[0] = list_elements[i_elem].mesh_connectivity[1];
            num_node[1] = list_elements[i_elem].mesh_connectivity[2];
            num_node[2] = list_elements[i_elem].mesh_connectivity[3];
            add_I = true;
            //for(int i=0; i<list_interfaces.size(); i++){
            for(int ii=0; ii<list_interfaces_type_0.size(); ii++){
                int i = list_interfaces_type_0[ii];
                //if(list_interfaces[i].mesh_type != 0){}
                //else{
                    bool find_inter = true;
                    BasicVec<int> current_repnode;
                    for(int i_node=0; i_node<3; i_node++){
                        bool find_node = false;
                        for(int i_connect=0; i_connect<3; i_connect++){
                            if(num_node[i_node] == list_interfaces[i].mesh_connectivity[i_connect]){
                                current_repnode.push_back(i_connect);
                                find_node = true;
                                break;
                            }
                        }
                        if(!find_node){
                            find_inter = false;
                            break;
                        }
                    }
                    if(find_inter){
                        add_I = false;
                        list_interfaces[i].add_side(i_elem, num_side, list_elements);
                        list_elements[i_elem].interfaces_global_num[num_side] = list_interfaces[i].id;

                        BasicVec<int, 6> repnode_test(0,1,2,3,4,5);
                        BasicVec<int, 6> repnode_0(0,2,1,5,4,3);
                        BasicVec<int, 6> repnode_1(1,0,2,3,5,4);
                        BasicVec<int, 6> repnode_2(2,1,0,4,3,5);
                        
                        BasicVec<int, 6> repnode;
                        if(current_repnode[0]==0){repnode = repnode_0;}
                        if(current_repnode[0]==1){repnode = repnode_1;}
                        if(current_repnode[0]==2){repnode = repnode_2;}
                        list_interfaces[i].correspondance_between_nodes=repnode;

                        list_interfaces_type_0.remove_unordered(ii);
                        break;
                    }
                //}
            }
            if(add_I){
                BasicVec<int, 6> repnode(0,2,1,5,4,3);
                EntityInterfaceUser current_interface(nb_interfaces, -1, num_node, i_elem, num_side, list_elements[i_elem].num_piece_in_mesh, repnode);
                list_interfaces.push_back(current_interface);
                list_elements[i_elem].interfaces_global_num[num_side] = nb_interfaces;
                list_interfaces_type_0.push_back(nb_interfaces);
                nb_interfaces = nb_interfaces + 1;
            } 
        }
        break;
        //pour le element PATTERN_Tetra_10 ----------------------------
        case 3 :{
            BasicVec<int,6> num_node;    
            int num_side;
            bool add_I;

    
            num_side = 0;
            num_node[0] = list_elements[i_elem].mesh_connectivity[0];
            num_node[1] = list_elements[i_elem].mesh_connectivity[2];
            num_node[2] = list_elements[i_elem].mesh_connectivity[1];
            num_node[3] = list_elements[i_elem].mesh_connectivity[6];
            num_node[4] = list_elements[i_elem].mesh_connectivity[5];
            num_node[5] = list_elements[i_elem].mesh_connectivity[4];
            add_I = true;
            //for(int i=0; i<list_interfaces.size(); i++){
            for(int ii=0; ii<list_interfaces_type_0.size(); ii++){
                int i = list_interfaces_type_0[ii];
                //if(list_interfaces[i].mesh_type != 0){}
                //else{
                    bool find_inter = true;
                    BasicVec<int> current_repnode;
                    for(int i_node=0; i_node<6; i_node++){
                        bool find_node = false;
                        for(int i_connect=0; i_connect<6; i_connect++){
                            if(num_node[i_node] == list_interfaces[i].mesh_connectivity[i_connect]){
                                current_repnode.push_back(i_connect);
                                find_node = true;
                                break;
                            }
                        }
                        if(!find_node){
                            find_inter = false;
                            break;
                        }
                    }
                    if(find_inter){
                        add_I = false;
                        list_interfaces[i].add_side(i_elem, num_side, list_elements);
                        list_elements[i_elem].interfaces_global_num[num_side] = list_interfaces[i].id;

                        list_interfaces[i].correspondance_between_nodes=current_repnode;
                        list_interfaces_type_0.remove_unordered(ii);
                        break;
                    }
                //}
            }
            if(add_I){
                BasicVec<int, 6> repnode(0,2,1,5,4,3);
                EntityInterfaceUser current_interface(nb_interfaces, -1, num_node, i_elem, num_side, list_elements[i_elem].num_piece_in_mesh, repnode);
                list_interfaces.push_back(current_interface);
                list_elements[i_elem].interfaces_global_num[num_side] = nb_interfaces;
                list_interfaces_type_0.push_back(nb_interfaces);
                nb_interfaces = nb_interfaces + 1;
            } 
    
            num_side = 1;
            num_node[0] = list_elements[i_elem].mesh_connectivity[0];
            num_node[1] = list_elements[i_elem].mesh_connectivity[1];
            num_node[2] = list_elements[i_elem].mesh_connectivity[3];
            num_node[3] = list_elements[i_elem].mesh_connectivity[4];
            num_node[4] = list_elements[i_elem].mesh_connectivity[8];
            num_node[5] = list_elements[i_elem].mesh_connectivity[7];
            add_I = true;
            //for(int i=0; i<list_interfaces.size(); i++){
            for(int ii=0; ii<list_interfaces_type_0.size(); ii++){
                int i = list_interfaces_type_0[ii];
                //if(list_interfaces[i].mesh_type != 0){}
                //else{
                    bool find_inter = true;
                    BasicVec<int> current_repnode;
                    for(int i_node=0; i_node<6; i_node++){
                        bool find_node = false;
                        for(int i_connect=0; i_connect<6; i_connect++){
                            if(num_node[i_node] == list_interfaces[i].mesh_connectivity[i_connect]){
                                current_repnode.push_back(i_connect);
                                find_node = true;
                                break;
                            }
                        }
                        if(!find_node){
                            find_inter = false;
                            break;
                        }
                    }
                    if(find_inter){
                        add_I = false;
                        list_interfaces[i].add_side(i_elem, num_side, list_elements);
                        list_elements[i_elem].interfaces_global_num[num_side] = list_interfaces[i].id;

                        list_interfaces[i].correspondance_between_nodes=current_repnode;
                        list_interfaces_type_0.remove_unordered(ii);
                        break;
                    }
                //}
            }
            if(add_I){
                BasicVec<int, 6> repnode(0,2,1,5,4,3);
                EntityInterfaceUser current_interface(nb_interfaces, -1, num_node, i_elem, num_side, list_elements[i_elem].num_piece_in_mesh, repnode);
                list_interfaces.push_back(current_interface);
                list_elements[i_elem].interfaces_global_num[num_side] = nb_interfaces;
                list_interfaces_type_0.push_back(nb_interfaces);
                nb_interfaces = nb_interfaces + 1;
            } 
    
            num_side = 2;
            num_node[0] = list_elements[i_elem].mesh_connectivity[0];
            num_node[1] = list_elements[i_elem].mesh_connectivity[3];
            num_node[2] = list_elements[i_elem].mesh_connectivity[2];
            num_node[3] = list_elements[i_elem].mesh_connectivity[7];
            num_node[4] = list_elements[i_elem].mesh_connectivity[9];
            num_node[5] = list_elements[i_elem].mesh_connectivity[6];
            add_I = true;
            //for(int i=0; i<list_interfaces.size(); i++){
            for(int ii=0; ii<list_interfaces_type_0.size(); ii++){
                int i = list_interfaces_type_0[ii];
                //if(list_interfaces[i].mesh_type != 0){}
                //else{
                    bool find_inter = true;
                    BasicVec<int> current_repnode;
                    for(int i_node=0; i_node<6; i_node++){
                        bool find_node = false;
                        for(int i_connect=0; i_connect<6; i_connect++){
                            if(num_node[i_node] == list_interfaces[i].mesh_connectivity[i_connect]){
                                current_repnode.push_back(i_connect);
                                find_node = true;
                                break;
                            }
                        }
                        if(!find_node){
                            find_inter = false;
                            break;
                        }
                    }
                    if(find_inter){
                        add_I = false;
                        list_interfaces[i].add_side(i_elem, num_side, list_elements);
                        list_elements[i_elem].interfaces_global_num[num_side] = list_interfaces[i].id;

                        list_interfaces[i].correspondance_between_nodes=current_repnode;
                        list_interfaces_type_0.remove_unordered(ii);
                        break;
                    }
                //}
            }
            if(add_I){
                BasicVec<int, 6> repnode(0,2,1,5,4,3);
                EntityInterfaceUser current_interface(nb_interfaces, -1, num_node, i_elem, num_side, list_elements[i_elem].num_piece_in_mesh, repnode);
                list_interfaces.push_back(current_interface);
                list_elements[i_elem].interfaces_global_num[num_side] = nb_interfaces;
                list_interfaces_type_0.push_back(nb_interfaces);
                nb_interfaces = nb_interfaces + 1;
            } 
    
            num_side = 3;
            num_node[0] = list_elements[i_elem].mesh_connectivity[1];
            num_node[1] = list_elements[i_elem].mesh_connectivity[2];
            num_node[2] = list_elements[i_elem].mesh_connectivity[3];
            num_node[3] = list_elements[i_elem].mesh_connectivity[5];
            num_node[4] = list_elements[i_elem].mesh_connectivity[9];
            num_node[5] = list_elements[i_elem].mesh_connectivity[8];
            add_I = true;
            //for(int i=0; i<list_interfaces.size(); i++){
            for(int ii=0; ii<list_interfaces_type_0.size(); ii++){
                int i = list_interfaces_type_0[ii];
                //if(list_interfaces[i].mesh_type != 0){}
                //else{
                    bool find_inter = true;
                    BasicVec<int> current_repnode;
                    for(int i_node=0; i_node<6; i_node++){
                        bool find_node = false;
                        for(int i_connect=0; i_connect<6; i_connect++){
                            if(num_node[i_node] == list_interfaces[i].mesh_connectivity[i_connect]){
                                current_repnode.push_back(i_connect);
                                find_node = true;
                                break;
                            }
                        }
                        if(!find_node){
                            find_inter = false;
                            break;
                        }
                    }
                    if(find_inter){
                        add_I = false;
                        list_interfaces[i].add_side(i_elem, num_side, list_elements);
                        list_elements[i_elem].interfaces_global_num[num_side] = list_interfaces[i].id;

                        list_interfaces[i].correspondance_between_nodes=current_repnode;
                        list_interfaces_type_0.remove_unordered(ii);
                        break;
                    }
                //}
            }
            if(add_I){
                BasicVec<int, 6> repnode(0,2,1,5,4,3);
                EntityInterfaceUser current_interface(nb_interfaces, -1, num_node, i_elem, num_side, list_elements[i_elem].num_piece_in_mesh, repnode);
                list_interfaces.push_back(current_interface);
                list_elements[i_elem].interfaces_global_num[num_side] = nb_interfaces;
                list_interfaces_type_0.push_back(nb_interfaces);
                nb_interfaces = nb_interfaces + 1;
            } 
        }
        break;
    } 
} 

// création des patterns à partir des éléments du maillage  ---------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------------------
void MeshUser::create_list_elements(int i_elem) { 
    switch (list_elements[i_elem].pattern_base_id){

        //de l'element PATTERN_Triangle vers PATTERN_Triangle_6----------------------------
        case 0 :{
            BasicVec< int > element_connectivity;
            element_connectivity.resize(6);
            element_connectivity[0] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[0]]);

            elements_pos_nodes[1].push_back(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[0]]);

            element_connectivity[1] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[1]]);

            elements_pos_nodes[1].push_back(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[1]]);

            element_connectivity[2] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[2]]);

            elements_pos_nodes[1].push_back(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[2]]);

            element_connectivity[3] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(1.0/2.0*mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[1]]+1.0/2.0*mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[0]]);

            elements_pos_nodes[1].push_back(1.0/2.0*mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[1]]+1.0/2.0*mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[0]]);

            element_connectivity[4] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(1.0/2.0*mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[2]]+1.0/2.0*mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[1]]);

            elements_pos_nodes[1].push_back(1.0/2.0*mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[1]]+1.0/2.0*mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[2]]);

            element_connectivity[5] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(1.0/2.0*mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[2]]+1.0/2.0*mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[0]]);

            elements_pos_nodes[1].push_back(1.0/2.0*mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[0]]+1.0/2.0*mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[2]]);

            list_elements[i_elem].define_element(i_elem, element_connectivity, 1);
        }
        break;
        //de l'element PATTERN_Triangle_6 vers PATTERN_Triangle_6----------------------------
        case 1 :{
            BasicVec< int > element_connectivity;
            element_connectivity.resize(6);
            element_connectivity[0] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[0]]);

            elements_pos_nodes[1].push_back(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[0]]);

            element_connectivity[1] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[1]]);

            elements_pos_nodes[1].push_back(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[1]]);

            element_connectivity[2] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[2]]);

            elements_pos_nodes[1].push_back(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[2]]);

            element_connectivity[3] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[3]]);

            elements_pos_nodes[1].push_back(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[3]]);

            element_connectivity[4] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[4]]);

            elements_pos_nodes[1].push_back(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[4]]);

            element_connectivity[5] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[5]]);

            elements_pos_nodes[1].push_back(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[5]]);

            list_elements[i_elem].define_element(i_elem, element_connectivity, 1);
        }
        break;
        //de l'element PATTERN_Tetra vers PATTERN_Tetra_10----------------------------
        case 2 :{
            BasicVec< int > element_connectivity;
            element_connectivity.resize(10);
            element_connectivity[0] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[0]]);

            elements_pos_nodes[1].push_back(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[0]]);

            elements_pos_nodes[2].push_back(mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[0]]);

            element_connectivity[1] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[1]]);

            elements_pos_nodes[1].push_back(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[1]]);

            elements_pos_nodes[2].push_back(mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[1]]);

            element_connectivity[2] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[2]]);

            elements_pos_nodes[1].push_back(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[2]]);

            elements_pos_nodes[2].push_back(mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[2]]);

            element_connectivity[3] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[3]]);

            elements_pos_nodes[1].push_back(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[3]]);

            elements_pos_nodes[2].push_back(mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[3]]);

            element_connectivity[4] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(1.0/2.0*mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[0]]+1.0/2.0*mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[1]]);

            elements_pos_nodes[1].push_back(1.0/2.0*mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[1]]+1.0/2.0*mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[0]]);

            elements_pos_nodes[2].push_back(1.0/2.0*mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[0]]+1.0/2.0*mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[1]]);

            element_connectivity[5] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(1.0/2.0*mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[2]]+1.0/2.0*mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[1]]);

            elements_pos_nodes[1].push_back(1.0/2.0*mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[1]]+1.0/2.0*mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[2]]);

            elements_pos_nodes[2].push_back(1.0/2.0*mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[2]]+1.0/2.0*mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[1]]);

            element_connectivity[6] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(1.0/2.0*mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[2]]+1.0/2.0*mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[0]]);

            elements_pos_nodes[1].push_back(1.0/2.0*mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[2]]+1.0/2.0*mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[0]]);

            elements_pos_nodes[2].push_back(1.0/2.0*mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[2]]+1.0/2.0*mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[0]]);

            element_connectivity[7] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(1.0/2.0*mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[0]]+1.0/2.0*mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[3]]);

            elements_pos_nodes[1].push_back(1.0/2.0*mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[3]]+1.0/2.0*mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[0]]);

            elements_pos_nodes[2].push_back(1.0/2.0*mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[0]]+1.0/2.0*mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[3]]);

            element_connectivity[8] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(1.0/2.0*mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[3]]+1.0/2.0*mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[1]]);

            elements_pos_nodes[1].push_back(1.0/2.0*mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[3]]+1.0/2.0*mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[1]]);

            elements_pos_nodes[2].push_back(1.0/2.0*mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[1]]+1.0/2.0*mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[3]]);

            element_connectivity[9] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(1.0/2.0*mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[2]]+1.0/2.0*mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[3]]);

            elements_pos_nodes[1].push_back(1.0/2.0*mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[3]]+1.0/2.0*mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[2]]);

            elements_pos_nodes[2].push_back(1.0/2.0*mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[2]]+1.0/2.0*mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[3]]);

            list_elements[i_elem].define_element(i_elem, element_connectivity, 3);
        }
        break;
        //de l'element PATTERN_Tetra_10 vers PATTERN_Tetra_10----------------------------
        case 3 :{
            BasicVec< int > element_connectivity;
            element_connectivity.resize(10);
            element_connectivity[0] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[0]]);

            elements_pos_nodes[1].push_back(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[0]]);

            elements_pos_nodes[2].push_back(mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[0]]);

            element_connectivity[1] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[1]]);

            elements_pos_nodes[1].push_back(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[1]]);

            elements_pos_nodes[2].push_back(mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[1]]);

            element_connectivity[2] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[2]]);

            elements_pos_nodes[1].push_back(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[2]]);

            elements_pos_nodes[2].push_back(mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[2]]);

            element_connectivity[3] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[3]]);

            elements_pos_nodes[1].push_back(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[3]]);

            elements_pos_nodes[2].push_back(mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[3]]);

            element_connectivity[4] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[4]]);

            elements_pos_nodes[1].push_back(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[4]]);

            elements_pos_nodes[2].push_back(mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[4]]);

            element_connectivity[5] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[5]]);

            elements_pos_nodes[1].push_back(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[5]]);

            elements_pos_nodes[2].push_back(mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[5]]);

            element_connectivity[6] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[6]]);

            elements_pos_nodes[1].push_back(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[6]]);

            elements_pos_nodes[2].push_back(mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[6]]);

            element_connectivity[7] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[7]]);

            elements_pos_nodes[1].push_back(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[7]]);

            elements_pos_nodes[2].push_back(mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[7]]);

            element_connectivity[8] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[8]]);

            elements_pos_nodes[1].push_back(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[8]]);

            elements_pos_nodes[2].push_back(mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[8]]);

            element_connectivity[9] = elements_pos_nodes[0].size();
            elements_pos_nodes[0].push_back(mesh_pos_nodes[0][list_elements[i_elem].mesh_connectivity[9]]);

            elements_pos_nodes[1].push_back(mesh_pos_nodes[1][list_elements[i_elem].mesh_connectivity[9]]);

            elements_pos_nodes[2].push_back(mesh_pos_nodes[2][list_elements[i_elem].mesh_connectivity[9]]);

            list_elements[i_elem].define_element(i_elem, element_connectivity, 3);
        }
        break;
        }
}
