//
// C++ Interface: LEVEL
//
// Description: 
//
//
// Author: Jeremie Bellec <j.bellec@structure-computation.com>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifdef METIL_COMP_DIRECTIVE
    #pragma src_file mesh_reader/read_bdf.cpp
    #pragma src_file mesh_reader/read_unv.cpp
    #pragma src_file code_genere/MeshUserFunctions.cpp
#endif

#ifndef MESH_USER_H
#define MESH_USER_H

#include <Metil/BasicVec.h>
#include <Metil/StructCompactor.h>

#include "Patterns.h"
#include "EntityElementUser.h"
#include "EntityInterfaceUser.h"
#include "GroupElementsUser.h"
#include "GroupInterfacesUser.h"

using namespace Metil;

class MeshUser{
    public:
        //******************************************************************************************
        //Attributs
        //******************************************************************************************
        static const int dim=DIM;
        Patterns patterns;

        //nom et chemins de fichier--------------------------------
        std::string model_path; 		//chemin d'acces au repertoire model
        std::string name_mesh_user; 		//nom du fichier mesh utilisateur
        std::string extension; 		        //extention pour le nom du fichier de mesh
        std::string name_directory; 		//nom du repertoire pour sauvegarder le motif
        std::string mesh_directory; 		//nom du repertoire pour sauvegarder les meshs
        std::string name_json;		        //nom du fichier json de sauvegarde apres create
        String name_visu_hdf;
        String name_structure_fields_hdf;
        String name_visu_xdmf;
        String name_structure_field_xdmf;
        
        //mesh de base, seulement pour le level[0]----------------
        BasicVec<int> mesh_num_nodes;	                        //liste des numero des noeuds du mesh 
        BasicVec< BasicVec< TYPE > > mesh_pos_nodes;	        //liste des coordonnées des noeuds du mesh 
        BasicVec< BasicVec< TYPE > > elements_pos_nodes;        //liste des coordonnées des noeuds du maillage transformé en patterns
        
        
        //liste des elements du maillage
        BasicVec< EntityElementUser > list_elements;
        int nb_elements; ///< question : est-ce que c'est != de list_elements.size() ?
        
        //liste des interfaces du maillage
        BasicVec< EntityInterfaceUser > list_interfaces;
        int nb_interfaces;
        BasicVec< int > list_interfaces_type_0;                 // on boucle sur cette liste pour la création des interfaces
        
        //***********************************************************************************
        //Methode pour compacter la class
        //*********************************************************************************** 
        template<class TB,class TP>
            void apply_bs( TB &res, TP ) const {
                res.set_type( "MESH" );
                //LEVEL
                APPLY_WN( res, mesh_num_nodes );
                APPLY_WN( res, mesh_pos_nodes );                
            }
        
        //***********************************************************************************
        //Methode
        //*********************************************************************************** 
        MeshUser(std::string model_path_, std::string model_id_){
            model_path =  model_path_;            
            name_mesh_user = "mesh";                               
            name_directory =  model_path + "model_"+model_id_;             
            mesh_directory =  model_path + "model_"+model_id_+"/MESH";            
            name_json =  model_path + "model_"+model_id_+"/MESH/model_id.json";     
            name_visu_hdf << mesh_directory.c_str() << "/visu_geometry.h5";
            name_visu_xdmf << mesh_directory.c_str() << "/visu_geometry";

            mesh_pos_nodes.resize(3);
            elements_pos_nodes.resize(3);
            
            nb_elements = 0;
            nb_interfaces = 0;
        }
        void read_bdf(const std::string fic_name); 	 //Lecture du mesh donne par l'utilisateur
        void read_unv(const std::string fic_name);       //Lecture du mesh donne par l'utilisateur
        void read_json_id(std::string file);		 //Lecture du fichier json donne par l'utilisateur
        bool FileExists( const char* FileName );     //vérification de l'existance d'un fichier
        void read_mesh_user();                       //lecture du fichier de maillage utilisateur
        void change_mesh_connectivity( int i_elem ); //modification de la connetivité d'un élément si le jacobien est négatif
        void create_list_interfaces( int i_elem );   //création des interface
        void create_list_elements( int i_elem );     //création des elements relatif au patterns à partir des élements
        void create_list_interfaces();               ///< la boucle for est dedans
        void test_create_list_interfaces();               ///< la boucle for est dedans

        void create_mesh( std::string model_path, std::string file ); //étape de création du maillage
};

#endif //MESH_USER_H
