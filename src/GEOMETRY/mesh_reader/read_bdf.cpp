//
// Description: Lecture d'un fichier bukdata genere par le logiciel gmsh en utilisant l'option FREEFIELDS ou LONGFIELDS
//
//
// Author: %{Violeau} <%{EMAIL}>, (C) %{06/09}
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_READ_BDF_HEADER
#define LMT_READ_BDF_HEADER

#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <Metil/BasicVec.h>

#include "MeshUser.h"

using namespace Metil;

inline void rm_commas_loc( Sc2String &str ) {
    for(unsigned i=0;i<str.size();++i)
        if ( str[i] == ',' )
            str[i] = ' ';
}
/// lire un fichier bdf (bulkdata) genere par gmsh (option freefield ou longfield) dans un mesh LMT note m 

void MeshUser::read_bdf(const Sc2String fic_name) {
    std::ifstream is( fic_name.c_str() );
    if ( ! is.is_open() ){
        throw std::runtime_error( "opening of "+fic_name+" has failed.");
    }
    
    int ctxte=0;
    //bool longfields=0;

    while (1) {
        if (! is )
            throw std::runtime_error("bdf file is corrupted ");

        Sc2String str2;
        getline(is,str2);

        // Evaluation du contexte
        if (str2.find("$")<str2.size() ) {
            ctxte=0;//ligne de commentaire
            continue;
        }
        if (str2.find("ENDDATA")<str2.size()){
            nb_elements = list_elements.size();
            nb_interfaces = list_interfaces.size();
            break;//fin du fichier
        }
        else if(str2.find("GRID*")<str2.size()) {
            ctxte=3;//noeud option longfield
            //modification de la ligne si option LONGFIELDS
            size_t found=str2.find("*N");;
            if(found<str2.size()){
                Sc2String rep=str2.substr(found);//extration de *Ni et effacement
                str2.replace(found,str2.length()," ");
                Sc2String str3;//recherche dans la ligne suivante
                getline(is,str3);
                //verification si *Ni est bien dans la ligne suivante
                if(str3.find(rep)<str3.size()){
                    Sc2String extract=str3.substr (rep.size(),str3.size());//extraction de ce qu'il y a apres *Ni
                    str2.append(extract);
                }
            }
            
        }
        else if(str2.find("GRID")<str2.size()) {
            ctxte=1;//noeud option freefields
            rm_commas_loc(str2);
        }
        
	else
	{
            ctxte=2;//element
            rm_commas_loc(str2);
	}
	
        
        //Separation des cas en fonction du contexte
        if (ctxte==1 or ctxte==3) {
            std::istringstream s(str2);
            Sc2String name;
            s >>name;
            int number;
            s >> number;
	    mesh_num_nodes.push_back(number-1);
            int type;
            s >> type;
	    TYPE pos_x;
	    s >> pos_x;
	    mesh_pos_nodes[0].push_back(pos_x);
	    TYPE pos_y;
	    s >> pos_y;
	    mesh_pos_nodes[1].push_back(pos_y);
	    TYPE pos_z;
	    s >> pos_z;
	    mesh_pos_nodes[2].push_back(pos_z);
            continue;
        }
        if(ctxte==2){
            std::istringstream s(str2);
            //lecture du type d'element, de son numero, de sa caracteristique materiau, de ses noeuds
            Sc2String type;
            int pattern_base_id;
            int num_type_pattern;
            int num;
            int num_piece;
            int nb_nodes_pattern;
            int nb_sides_pattern;
            BasicVec< int > mesh_connectivity;
            
            s>>type;
            if(type=="CTRIA3"){         pattern_base_id = 0;}
            else if(type=="CTRIA6"){    pattern_base_id = 1;}
            else if(type=="CTETRA"){    pattern_base_id = 2;}
            
            nb_nodes_pattern = patterns.find_type(pattern_base_id).nb_nodes;
            nb_sides_pattern = patterns.find_type(pattern_base_id).nb_sides;
            mesh_connectivity.resize(nb_nodes_pattern);
            
            s >> num;
            s >> num_piece;
            for(int i=0;i<nb_nodes_pattern;i++){
                s >>  mesh_connectivity[i];
                mesh_connectivity[i] = mesh_connectivity[i]-1;
            }
            EntityElementUser current_element(pattern_base_id, num, num_piece, mesh_connectivity, nb_sides_pattern);
            list_elements.push_back(current_element);
            change_mesh_connectivity(list_elements.size()-1);
            
            continue;
        }
    }
}


#endif // LMT_READ_BDF_HEADER

