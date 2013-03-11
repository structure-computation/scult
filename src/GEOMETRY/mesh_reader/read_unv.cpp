//
// Description:
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_READ_UNV_HEADER
#define LMT_READ_UNV_HEADER

#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <Metil/BasicVec.h>

#include "MeshUser.h"
// #include <boost/concept_check.hpp>

using namespace Metil;
using namespace std;


/// read nodes
void read_unv_nodes(BasicVec<int> &mesh_num_nodes, BasicVec< BasicVec< TYPE > > &mesh_pos_nodes, std::istream &is) {

    int exp_coord_sys_num,disp_coord_sys_num,color,number;
    string str;
    while (true) {
        getline(is,str);
        istringstream s(str);
        s >> number;
        if (number==-1)
            break;

        mesh_num_nodes.push_back(number-1);
        s >> exp_coord_sys_num       // (not supported yet)
        >> disp_coord_sys_num      // (not supported yet)
        >> color;                   // (not supported yet)

        getline(is,str);

        // on remplace le 'D' par 'e' dans le format scientifique....
        for (unsigned i=0;i<str.size();++i) {
            if (str[i]=='D' or str[i]=='d') str[i]='e';
        }

        s.clear();
        s.str(str);
        BasicVec<TYPE,DIM> vec;
        for (int di=0;di<DIM;di++) {
            s >> vec[di];
            mesh_pos_nodes[di].push_back(vec[di]);
        }
    }
}

///read elements
void read_unv_elements(BasicVec< EntityElementUser > &list_elements, std::istream &is, Patterns &patterns, map<int,int> &map_num_element) {

#if DIM==2
    BasicVec<int> supported_FE_descriptor(41,91);
#else
    BasicVec<int> supported_FE_descriptor(111);
#endif
            
  int num_element,fe_descriptor_id,phys_prop_tab_num,mat_prop_tab_num,color,n_nodes;
  string str;

  while (true) {
    getline(is,str);
    istringstream s(str);
    s >> num_element;
    if (num_element==-1)
      return;
    
    //stockage uniquement des elements parents
    bool save_FE=0;      
    s >> fe_descriptor_id;        // read FE descriptor id
    for(int i=0;i<supported_FE_descriptor.size();i++){
        if(fe_descriptor_id==supported_FE_descriptor[i]){ save_FE=1; break;}
    }
    if(save_FE==0){getline(is,str); if(fe_descriptor_id==11){getline(is,str);} continue;}
    
    s >> phys_prop_tab_num       // (not supported yet)
      >> mat_prop_tab_num        // (not supported yet)
      >> color                   // (not supported yet)
      >> n_nodes;                // read number of nodes on element
      
    getline(is,str);

    s.clear();
    s.str(str);
    int pattern_base_id;
    if(n_nodes==3 and (fe_descriptor_id==41 or fe_descriptor_id==91)){pattern_base_id = 0;}
    else if(n_nodes==6){pattern_base_id = 1;}
    else if(n_nodes==4 and fe_descriptor_id==111){pattern_base_id = 2;}
    int nb_sides_pattern = patterns.find_type(pattern_base_id).nb_sides;
    BasicVec< int > mesh_connectivity;
    mesh_connectivity.resize(n_nodes);

    for(int i=0;i<n_nodes;i++){
        s >>  mesh_connectivity[i];
        mesh_connectivity[i] = mesh_connectivity[i]-1;
    }
    EntityElementUser current_element(pattern_base_id, num_element, 0, mesh_connectivity, nb_sides_pattern); //numero de groupe a assigner plus tard si necessaire
    list_elements.push_back(current_element);
    map_num_element[num_element]=list_elements.size()-1;
  }
  return;
}


void read_unv_groups(BasicVec< EntityElementUser > &list_elements, std::istream &is, map<int,int> &map_num_element, map<int,Sc2String> &map_num_group_name_group) {
    string str;
   
    while (true) {
        getline(is,str);
        istringstream s(str);
        int num_group;
        s >> num_group;
        if (num_group==-1)
          return;

    //     PRINT(num_group);
        int temp;
        for(unsigned i=0;i<6;i++)
            s >> temp;
        int nb_elements;
        s >> nb_elements;
        getline(is,str);
        Sc2String name_group;
        name_group << str;
        //PRINT(name_group);
        map_num_group_name_group[num_group] = name_group;
        
        int nb=0;
        while(nb!=nb_elements){
            getline(is,str);
            istringstream s(str);
            int num;
            BasicVec<int> data;
            while ( s ) {
                    s >> num;
                    data.push_back(num);
            }
            if(data.size()==9){
                nb+=2;
                int rep1=map_num_element[data[1]]; 
                int rep2=map_num_element[data[5]]; 
                list_elements[rep1].num_piece_in_mesh=num_group; 
                list_elements[rep2].num_piece_in_mesh=num_group;
            } 
            else if(data.size()==5){
                nb+=1;            
                int rep1=map_num_element[data[1]]; 
                list_elements[rep1].num_piece_in_mesh=num_group; 
            }
            else {std::cerr << "probleme de lecture des groupes" << std::endl; }
        }
        if(nb!=nb_elements){std::cerr << "probleme de lecture des groupes : taille assignée différente de la taille donnée "<< std::endl;}
   } 
}

/// lire un fichier .unv généré par Salomé contenant ou non des groupes d'éléments
void MeshUser::read_unv(const Sc2String fic_name) {
    std::ifstream is( fic_name.c_str() );
    if ( ! is.is_open() ) {
        throw std::runtime_error( "opening of "+fic_name+" has failed.");
    }
    map<int,int> map_num_element;
    //map<int,std::string> map_num_group_name_group;
    /*  int old,news=0;*/
    while (true) {
        Sc2String str;
        int news=0;
        getline(is,str);
        if ( not is )
            break;
        istringstream s(str);
        s >> news;
        switch (news) {
        case (2411):
            std::cout<<"\tLecture des noeuds"<<endl;
            read_unv_nodes(mesh_num_nodes,mesh_pos_nodes,is);
            break;
        case (2412):
            std::cout<<"\tLecture des elements"<<endl;
            read_unv_elements(list_elements,is,patterns,map_num_element);
            for(unsigned i=0;i<list_elements.size();i++){change_mesh_connectivity(i);}
            break;
        case (2467):
            std::cout <<"\tLecture des groupes" << endl;
            read_unv_groups(list_elements,is,map_num_element, map_num_group_name_group);
            break;
        }
    }
//     list_elements[0].affiche();
    PRINT(list_elements.size());
    nb_elements = list_elements.size();
    nb_interfaces = list_interfaces.size();
    PRINT(mesh_pos_nodes[0].size());
    //for(unsigned i=0;i<list_elements.size();i++){std::cout << list_elements[i].num_piece_in_mesh << endl;}
    
}


#endif // LMT_READ_UNV_HEADER

