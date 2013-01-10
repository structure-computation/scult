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

#ifndef MESH_USER_H
#define MESH_USER_H

#ifdef METIL_COMP_DIRECTIVE
    #pragma src_file mesh_reader/read_bdf.cpp
    #pragma src_file mesh_reader/read_unv.cpp
    #pragma src_file code_genere/MeshUserFunctions.cpp
#endif

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
        Sc2String model_path;            //chemin d'acces au repertoire model
        Sc2String name_mesh_user;        //nom du fichier mesh utilisateur
        Sc2String extension;             //extention pour le nom du fichier de mesh
        Sc2String name_directory;        //nom du repertoire pour sauvegarder le motif
        Sc2String mesh_directory;        //nom du repertoire pour sauvegarder les meshs
        Sc2String name_json;             //nom du fichier json de sauvegarde apres create
        Sc2String name_visu_hdf;
        Sc2String name_structure_fields_hdf;
        Sc2String name_visu_xdmf;
        Sc2String name_structure_field_xdmf;
        
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
        MeshUser(Sc2String model_path_, Sc2String model_id_){
            model_path =  model_path_;            
            name_mesh_user = "mesh";                               
            name_directory =  model_path + "model_"+model_id_;             
            mesh_directory =  model_path + "model_"+model_id_+"/MESH";            
            name_json =  model_path + "model_"+model_id_+"/MESH/model_id.json";     
            name_visu_hdf << mesh_directory << "/visu_geometry.h5";
            name_visu_xdmf << mesh_directory << "/visu_geometry";

            mesh_pos_nodes.resize(3);
            elements_pos_nodes.resize(3);
            
            nb_elements = 0;
            nb_interfaces = 0;
        }
        void read_bdf(const Sc2String fic_name); 	 //Lecture du mesh donne par l'utilisateur
        void read_unv(const Sc2String fic_name);       //Lecture du mesh donne par l'utilisateur
        void read_json_id(Sc2String file);		 //Lecture du fichier json donne par l'utilisateur
        bool FileExists( const char* FileName );     //vérification de l'existance d'un fichier
        bool FileExists( Sc2String FileName );     //vérification de l'existance d'un fichier
        void read_mesh_user();                       //lecture du fichier de maillage utilisateur
        void read_mesh_user(Sc2String path);         //lecture du fichier de maillage file
        void change_mesh_connectivity( int i_elem ); //modification de la connetivité d'un élément si le jacobien est négatif
        void create_list_interfaces( int i_elem );   //création des interface
        void create_list_elements( int i_elem );     //création des elements relatif au patterns à partir des élements
        void create_list_interfaces();               ///< la boucle for est dedans
        void test_create_list_interfaces();               ///< la boucle for est dedans

        void create_mesh( Sc2String model_path, Sc2String file ); //étape de création du maillage
        
        void create_mesh_unv(Sc2String path, Sc2String extention_);   //pour read_unv dans scwal 
        void create_mesh_scwal(Sc2String path, Sc2String extention_); //pour scult dans scwal
};

#endif //MESH_USER_H
