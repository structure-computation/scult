//
// C++ Implementation: read_json
//
// Description: 
//
//
// Author: David Violeau <dvioleau@structure-computation.com>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include <iostream>
#include <fstream>
#include <cassert>

#include <Metil/MathBasicVec.h>
#include <Metil/HashSet.h>

#include "json_spirit.h"                 
#include "mesh_reader/split_bdf.h"

#include "MeshUser.h"

using namespace Metil;
using namespace json_spirit;  

//*************************************************************************************************************
// fonction de MeshUser 
//*************************************************************************************************************

bool MeshUser::FileExists( const char* FileName ){
    FILE* fp = NULL;
    fp = fopen( FileName, "rb" );
    if( fp != NULL )
    {
        fclose( fp );
        return true;
    }
    return false;
}

bool MeshUser::FileExists( Sc2String FileName ){
    FILE* fp = NULL;
    fp = fopen( FileName.c_str(), "rb" );
    if( fp != NULL )
    {
        fclose( fp );
        return true;
    }
    return false;
}

void MeshUser::read_mesh_user(){
    Sc2String name_file_vol = mesh_directory + "/" + name_mesh_user + "_volume.bdf";
    Sc2String name_file_skin = mesh_directory + "/" + name_mesh_user + "_skin.bdf";
    Sc2String file = mesh_directory + "/" + name_mesh_user + extension;
    std::cout << file << std::endl;
    
    if(extension == ".bdf"){
        if(FileExists(name_file_vol.c_str())==false ){
            split_bdf(name_file_vol,name_file_skin,file, dim);
        }
        read_bdf( name_file_vol );
    //  read_bdf( name_file_skin );
    }
    else if(extension == ".unv"){
        read_unv( file );
    }else{
    std::cout << "extension de fichier non reconnue" << std::endl;
    assert(0);
    }
}



void MeshUser::read_json_id(Sc2String file){
  
    std::ifstream json( file.c_str() );
    if(!json){
        std::cout << "cannot open file " << file << std::endl;
        assert(0);
    }
    std::ostringstream stream;
    Sc2String str;
    while( getline( json, str ) ){
        stream << str << std::endl;
    }
    Sc2String json_text(stream.str());
    
    Value value_i;
    read( json_text, value_i );
    std::cout << "dans read_json_id" << std::endl;
    const Object& input = value_i.get_obj();
    for( Object::size_type i = 0; i != input.size(); ++i )
    {
        const Pair& pair_id = input[i];
        const Sc2String& name_id  = pair_id.name_;
        const Value& value_id= pair_id.value_;
        if(name_id=="identite_calcul"){//lecture des donnees de maillage
            Object obj=value_id.get_obj();
            for( Object::size_type i = 0; i != obj.size(); ++i )
            {
                const Pair& pair = obj[i];
                const Sc2String& name  = pair.name_;
                const Value&  value = pair.value_;

                if( name == "id_model" )
                {
                    int id_model= value.get_int();
                    std::stringstream stemp;
                    stemp << model_path << "model_" << id_model;
                    std::cout << name_directory << std::endl;
                }
            }
        }
    }
    for( Object::size_type i = 0; i != input.size(); ++i )
    {
        const Pair& pair_id = input[i];
        const Sc2String& name_id  = pair_id.name_;
        const Value& value_id= pair_id.value_;
        if(name_id=="mesh"){
            Object obj=value_id.get_obj();
            for( Object::size_type i = 0; i != obj.size(); ++i )
            {
                const Pair& pair = obj[i];
                const Sc2String& name  = pair.name_;
                const Value&  value = pair.value_;
                if( name == "extension" )
                {
                    extension= value.get_str();
                }
            }
        }
    }
}


struct EntitySideUser{
    int min_num_node;
    int num_elem;
    int num_side; 
    bool assigned; 
    int pattern_base_id;
    BasicVec< int > mesh_connectivity;
    EntitySideUser(){};
    EntitySideUser(int min_num_node_, int num_elem_, int num_side_ ,bool assigned_, int pattern_base_id_, BasicVec< int > mesh_connectivity_){
        min_num_node = min_num_node_;
        num_elem = num_elem_;
        num_side = num_side_;
        assigned = assigned_;
        pattern_base_id = pattern_base_id_;
        mesh_connectivity = mesh_connectivity_; 
    };
};


void MeshUser::test_create_list_interfaces(){
    BasicVec< BasicVec<int> > h;
    h.resize(mesh_pos_nodes[0].size());
//     PRINT(h.size());
    BasicVec< EntitySideUser > list_sides;
    for( int num_elem = 0; num_elem < list_elements.size(); ++num_elem ) {
//         std::cout << "elem " << num_elem << std::endl;
        Patterns::Types current_type = patterns.find_type(list_elements[num_elem].pattern_base_id);
        //PRINT(current_type.nb_sides);
        for( int num_side = 0; num_side < current_type.nb_sides; ++num_side ){
            BasicVec< int > mesh_connectivity_;
            mesh_connectivity_.resize(current_type.nb_nodes_by_sides);
            mesh_connectivity_[0] = list_elements[num_elem].mesh_connectivity[current_type.sides[num_side][0]] ;
            int min_num_node =  mesh_connectivity_[0] ;
//             PRINT(min_num_node);
            for( int num_node_side = 1; num_node_side < current_type.nb_nodes_by_sides; ++num_node_side ){
                mesh_connectivity_[num_node_side] = list_elements[num_elem].mesh_connectivity[current_type.sides[num_side][num_node_side]];
                if(mesh_connectivity_[num_node_side] < min_num_node){
                    min_num_node = mesh_connectivity_[num_node_side];
                }
            }
//             PRINT(mesh_connectivity_);
            h[min_num_node].push_back(list_sides.size());
//             PRINT(min_num_node);
/*            PRINT(h[min_num_node]);*/
            EntitySideUser temp_side(min_num_node, num_elem, num_side,false,list_elements[num_elem].pattern_base_id, mesh_connectivity_);
            list_sides.push_back(temp_side);
        }
    }
    
//     PRINT(nb_elements);
//     for( int  num_node = 0; num_node < mesh_pos_nodes[0].size(); ++num_node ){
//         PRINT(h[num_node]);
//     }
//     for( int  num_side = 0; num_side < list_sides.size(); ++num_side ){
//         PRINT(list_sides[num_side].mesh_connectivity);
//     }

    for( int  num_side = 0; num_side < list_sides.size(); ++num_side ){
//         PRINT(num_side);
//         PRINT(list_sides[num_side].mesh_connectivity);
//          PRINT(list_sides[num_side].assigned);
        if(!list_sides[num_side].assigned){
            Patterns::Types  current_type = patterns.find_type(list_sides[num_side].pattern_base_id);
/*            PRINT(num_side);*/
            // ajout d'une interface
            BasicVec<int> repnode;
            switch ( list_sides[num_side].pattern_base_id ){
                case 0:{ // triangle
                    BasicVec<int, 3> repnode_temp(1,0,2);
                    repnode = repnode_temp;
                }
                case 1:{ // triangle_6
                    BasicVec<int, 3> repnode_temp(1,0,2);
                    repnode = repnode_temp;
                }
                case 2:{ // tetra
                    BasicVec<int, 6> repnode_temp(0,2,1,5,4,3);
                    repnode = repnode_temp;
                }
                case 3:{ // tetra_10
                    BasicVec<int, 6> repnode_temp(0,2,1,5,4,3);
                    repnode = repnode_temp;
                }
            }
            EntityInterfaceUser current_interface(nb_interfaces, -1, list_sides[num_side].mesh_connectivity, list_sides[num_side].num_elem, list_sides[num_side].num_side, list_elements[list_sides[num_side].num_elem].num_piece_in_mesh, repnode);
            list_interfaces.push_back(current_interface);
            list_elements[list_sides[num_side].num_elem].interfaces_global_num[list_sides[num_side].num_side] = nb_interfaces;
            list_sides[num_side].assigned = true;
            
            for( int eq_side = 0; eq_side < h[list_sides[num_side].min_num_node].size(); ++eq_side){
                int num_eq_side = h[list_sides[num_side].min_num_node][eq_side];
                if(num_eq_side != num_side){
                    bool find_inter = true;
                    BasicVec<int> current_repnode;
                    for(int i_node=0; i_node<current_type.nb_nodes_by_sides; i_node++){
                        bool find_node = false;
                        for(int i_connect=0; i_connect<current_type.nb_nodes_by_sides; i_connect++){
                            if(list_sides[num_side].mesh_connectivity[i_node] == list_sides[num_eq_side].mesh_connectivity[i_connect]){
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
//                         PRINT("add_side");
//                         PRINT(num_eq_side);
                        list_interfaces[nb_interfaces].add_side(list_sides[num_eq_side].num_elem, list_sides[num_eq_side].num_side, list_elements);
                        if(list_sides[num_side].pattern_base_id == 2){
                            BasicVec<int, 6> repnode_0(0,2,1,5,4,3);
                            BasicVec<int, 6> repnode_1(1,0,2,3,5,4);
                            BasicVec<int, 6> repnode_2(2,1,0,4,3,5);
                            
                            BasicVec<int, 6> repnode;
                            if(current_repnode[0]==0){repnode = repnode_0;}
                            if(current_repnode[0]==1){repnode = repnode_1;}
                            if(current_repnode[0]==2){repnode = repnode_2;}
                            list_interfaces[nb_interfaces].correspondance_between_nodes=repnode;
                        }else if(list_sides[num_side].pattern_base_id == 3){
                            list_interfaces[nb_interfaces].correspondance_between_nodes=current_repnode;
                        }
                        list_elements[list_sides[num_eq_side].num_elem].interfaces_global_num[list_sides[num_eq_side].num_side] = nb_interfaces;
                        list_sides[num_eq_side].assigned = true;
                        
                        break;
                    } 
                }
            }
            nb_interfaces = nb_interfaces + 1;
        }
/*        else{std::cerr << "list_side["<<num_side<<"] non assigned " << std::endl; assert(0);}*/
    }
}



void MeshUser::create_mesh(Sc2String model_path, Sc2String file){
    model_path = model_path;
    std::cout << "** read_json ***************************************************************************************************" << std::endl;
    read_json_id( file );
    std::cout << "** read_json ok" << std::endl;
    
    std::cout << "** read_mesh_user **********************************************************************************************" << std::endl;
    read_mesh_user();
    std::cout << "** read_mesh_user ok" << std::endl;
    
    std::cout << "** create interfaces *******************************************************************************************" << std::endl;
    test_create_list_interfaces(); 
    PRINT(nb_interfaces);
    PRINT(list_interfaces.size());
    
//     for(int i_inter=0; i_inter<nb_interfaces; i_inter++){
//         list_interfaces[i_inter].affiche();
//     }
    std::cout << "** create interfaces ok" << std::endl;
    
    std::cout << "** create elements *********************************************************************************************" << std::endl;
    for( int i_elem = 0; i_elem < nb_elements; i_elem++ ){
        create_list_elements( i_elem );
    }
    std::cout << "** create elements ok" << std::endl;
    
}

