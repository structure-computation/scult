//
// Description: s�paration d'un fichier bukdata genere par le logiciel gmsh en utilisant l'option FREEFIELDS en deux parties : maillage interne et maillage de peau (les noeuds sont recopies sans tri).
//
//
// Author: %{Violeau} <%{EMAIL}>, (C) %{06/09}
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_SPLIT_BDF_HEADER
#define LMT_SPLIT_BDF_HEADER

#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include <stdexcept>

namespace Metil {

/// lire un fichier bdf (bulkdata) genere par gmsh (option freefield) dans un maillage LMT note m 
inline void split_bdf(std::ofstream &osv,std::ofstream &oss, std::ifstream &is, int &dimension) throw(std::runtime_error) {

    BasicVec<std::string> elem_skin;
    if (dimension==2){elem_skin.resize(1); elem_skin[0]="CBAR";}
    else if (dimension==3){elem_skin.resize(1); elem_skin[0]="CTRIA3"; }
    
    while (1) {
        if (! is )
            throw std::runtime_error("bdf file is corrupted ");

        std::string str2;
        getline(is,str2);
        
        // Evaluation du contexte
        if (str2.find("$")<str2.size() ) {//ligne de commentaire recopiee dans les 2 fichiers
            osv << str2 << std::endl;
            oss << str2 << std::endl;
            continue;
        }
        if (str2.find("ENDDATA")<str2.size()){
            osv << str2 <<std::endl;
            oss << str2 <<std::endl;
            break;
        }
	else if(str2.find("GRID*")<str2.size()) {
            osv << str2 <<std::endl;
            oss << str2 <<std::endl;
            //verification si *N est present sur la ligne, si oui insertion de la ligne suivante
            if(str2.find("*N")<str2.size()){
                std::string str3;
                getline(is,str3);
                osv << str3 <<std::endl;
                oss << str3 <<std::endl;
            }
            continue;
        }
        else if(str2.find("GRID")<str2.size()) {
            osv << str2 <<std::endl;
            oss << str2 <<std::endl;
            continue;
        }
	
        for(int i=0;i<elem_skin.size();i++){
            if(str2.find(elem_skin[i].c_str())<str2.size()){
                oss << str2 <<std::endl;
            }
            else{
                osv << str2 <<std::endl;
            }
        }	
    }
}


/// put bdf file and output filess
inline void split_bdf(const std::string &fic_name_volume, const std::string &fic_name_skin,const std::string &fic_name, int dimension) throw(std::runtime_error) {
    // ouverture du fichier a lire
    std::ifstream my_file_r( fic_name.c_str() );
    //ouverture des fichiers a ecrire
    std::ofstream my_file_v( fic_name_volume.c_str() );
    std::ofstream my_file_s( fic_name_skin.c_str() );

    if ( ! my_file_r.is_open() )
        throw std::runtime_error( "opening of "+fic_name+" has failed.");
    return split_bdf(my_file_v,my_file_s,my_file_r,dimension);
}


};

#endif // LMT_READ_GID_HEADER

