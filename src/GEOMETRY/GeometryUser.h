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

#ifndef GEOMETRYUSER_H
#define GEOMETRYUSER_H

#include <Metil/BasicVec.h>
#include <Metil/StructCompactor.h>
#include <Metil/Hdf.h>

#include "Patterns.h"
#include "Interfaces.h"
#include "EntityElementUser.h"
#include "EntityInterfaceUser.h"
#include "GroupElementsUser.h"
#include "GroupInterfacesUser.h"
#include "MeshUser.h"
#include "DataUser.h"

using namespace Metil;


class GeometryUser{
    public:
      //******************************************************************************************
      //Attributs
      //******************************************************************************************
      //chemin des fichiers---------------------------------------------------------------------------------------------------------------------------
      Sc2String model_path ;
      Sc2String mesh_path;
      Sc2String calcul_path;
      Sc2String calcul_file;
      Sc2String name_file_hdf5; 
      
      //Attributs génériques--------------------------------------------------------------------------------------------------------------------------
      int num_level;
      int dim;
      Patterns patterns;
      Interfaces interfaces;
      //Attributs level sup---------------------------------------------------------------------------------------------------------------------------
      
      //Attributs level courant-----------------------------------------------------------------------------------------------------------------------
      BasicVec< BasicVec< TYPE > > mesh_nodes; //coordonnées des noeuds (dim , nb_nodes)
      BasicVec< BasicVec< TYPE > > nodes; //coordonnées des noeuds (dim , nb_nodes)
      
      //Attributs des elements
      int nb_group_elements;
      BasicVec<BasicVec<int> > repartition_mpi_group_elements;  // repartition des groups d'elements sur chaque processeur pour calcul mpi (taille : nb_processeur, nb_group_elements_by_processor
      BasicVec<GroupElementsUser> group_elements;
          
      //Attributs des interfaces
      int nb_group_interfaces;
      BasicVec< GroupInterfacesUser > group_interfaces;
       
      //***********************************************************************************
      //Methode pour générer la class compacté GEOMETRY.h
      //***********************************************************************************   
      template<class TB,class TP>
      void apply_bs( TB &res, TP ) const {
          res.set_type( "GeometryCompactClass" );
          APPLY_WN( res, num_level );
          APPLY_WN( res, dim );
          APPLY_WN( res, patterns );
          APPLY_WN( res, mesh_nodes );
          APPLY_WN( res, nodes );
          APPLY_WN( res, group_elements );
          APPLY_WN( res, group_interfaces );
          
      }
      //***********************************************************************************
      //Methode pour SC_create
      //*********************************************************************************** 
      //Methode générique  ---------------------------------------------------------------------------------------------------------------------------
      
      GroupElementsUser* find_group_elements(int id_);              // recherche d'un group_elements particulier avec son id
      int find_index_group_elements(int id_);                   // recherche de l'index d'un group_elements particulier avec son id
      
      GroupInterfacesUser* find_group_interfaces(int id_);          // recherche d'un group_interfaces particulier avec son id
      int find_index_group_interfaces(int id_);                 // recherche de l'index d'un group_interfaces particulier avec son id
      
      BasicVec< GroupInterfacesUser* > find_group_edges(int edge_id_); // rechercher tous les group_interface ayant edge_id = edge_id_
      BasicVec< int > find_index_group_edges(int edge_id_);                     // rechercher tous les index des group_interface ayant edge_id = edge_id_

      //Methode d'initialisation----------------------------------------------------------------------------------------------------------------------
      GeometryUser();
      GeometryUser(Sc2String id_model, Sc2String id_calcul);
      GeometryUser(MeshUser &mesh_);
      void initialisation(Sc2String id_model, Sc2String id_calcul);                 // même fonction que le constructeur ayant les mêmes arguments
      void initialize_group_elements_from_MeshUser(MeshUser &mesh_);                    // initialisation à partir des elements du maillage
      void initialize_group_interfaces_from_MeshUser(MeshUser &mesh_);                  // initialisation à partir des interfaces du maillage
      
      void write_json(MeshUser &mesh_user);                                             // ecriture du fichier json pour l'interface
      void write_nodes_hdf5(Hdf &hdf, Sc2String name);             //ecriture des noeuds globaux dans un fichier hdf5
      void write_group_elements_hdf5(Hdf &hdf, Sc2String name, int i_group);             //ecriture des donnees d'un groupe d'elements dans un fichier hdf5
      void write_group_elements_skin_hdf5(Hdf &hdf, Sc2String name, int i_group);             //ecriture des donnees d'un groupe d'elements dans un fichier hdf5
      void write_group_interfaces_hdf5(Hdf &hdf, Sc2String name, int i_group);             //ecriture des donnees d'un groupe d'interfaces dans un fichier hdf5
      void write_side_group_interfaces_hdf5(Hdf &hdf, Sc2String name, int i_group, int i_side);             //ecriture des donnees d'un coté d'un groupe d'interfaces dans un fichier hdf5
      void write_hdf5(Sc2String file_output_hdf5);                                        // ecriture de le geometrie complete dans un fichier hdf5 par processeur
      void write_hdf5_in_parallel(Sc2String file_output_hdf5, int rank);                                        // ecriture de le geometrie complete dans un fichier hdf5 par processeur
      void write_xdmf(Sc2String output_xdmf, Sc2String input_hdf5, Sc2String name_geometry, int skin); //Ecriture du fichier xdmf "output_xdmf" avec références aux données du fichier hdf5 "input_hdf5" 
                                                                                                                                                                                   
      void read_node_hdf5(Hdf &hdf, Sc2String name, bool read_micro);                      // lecture des noeuds dans le hdf                                                                                                                                                                          
      void read_tag_group_elements_hdf5(Hdf &hdf, Sc2String &name, bool read_micro);        // lecture des tag pour les group_elements
      void read_infos_group_elements_hdf5(Hdf &hdf, Sc2String &name, bool read_micro);      // lecture des autres info sur les group_elements
      void read_tag_group_interfaces_hdf5(Hdf &hdf, Sc2String &name, bool read_micro);      // lecture des tag pour les group_interfaces
      void read_infos_group_interfaces_hdf5(Hdf &hdf, Sc2String &name, bool read_micro);    // lecture des autres info sur les group_interfaces  
      void read_hdf5(bool read_micro, bool read_all, Sc2String mode);                                   //lecture des données du fichier hdf5 et assignation des champs de la classe GEOMETRY_USER
      
      void initialize_GPU();                                                            // initialisation pour calcul sur GPU
      void mpi_repartition();                            // repartition des groups d'elements en fonction de la repartition des sst pour mpi
      
      void affiche();                                                                    // affichage des group pour verification

      //Methode de niveau sup-------------------------------------------------------------------------------------------------------------------------
      bool do_respect_geometry(int i_group, int num_edge, DataUser::Geometry &geom);    // repere si un element d'interface est dans une geometry donnée
      void split_group_edges_within_geometry(DataUser &data_user);                      // séparation d'un group_interfaces de type 0 suivant un critère géometrique au moment du calcul
      void visualize_group_edges_within_geometry(DataUser &data_user);                  //modification du champ "to_visualize" pour les interfaces d'un group_interfaces de type 0 (bord) suivant un critère géometrique donné par l'utilisateur

      //Methode de niveau courrant -------------------------------------------------------------------------------------------------------------------
      
      
      
       
};

#endif //GEOMETRY_H


