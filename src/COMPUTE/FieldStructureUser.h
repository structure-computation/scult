//
// C++ Interface: FieldStructure
//
// Description: 
//
//
// Author: Jeremie Bellec <j.bellec@structure-computation.com>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef FIELDSTRUCTUREUSER_H
#define FIELDSTRUCTUREUSER_H

#ifdef METIL_COMP_DIRECTIVE
    #pragma gpu_flag --compiler-options -fpermissive
#endif

#include <Metil/BasicVec.h>
#include <Metil/StructCompactor.h>

#include "Patterns.h"
#include "Properties.h"
#include "GeometryUser.h"
#include "DataUser.h"
#include "FieldStructureGroupElementsUser.h"
#include "FieldStructureGroupInterfacesUser.h"

using namespace Metil;

class FieldStructureUser{
    public:
      //******************************************************************************************
      //Attributs
      //******************************************************************************************
      //Attributs génériques--------------------------------------------------------------------------------------------------------------------------
      int num_level;
      int dim;
      Patterns patterns;
      Properties properties;
      //Attributs level sup---------------------------------------------------------------------------------------------------------------------------
      
      //Attributs level courant-----------------------------------------------------------------------------------------------------------------------
      
      //Attributs des elements
      int nb_group_elements;
      BasicVec<FieldStructureGroupElementsUser> group_elements;
          
      //Attributs des interfaces
      int nb_group_interfaces;
      BasicVec< FieldStructureGroupInterfacesUser > group_interfaces;
       
      //***********************************************************************************
      //Methode pour générer la class compacté GEOMETRY.h
      //***********************************************************************************   
      template<class TB,class TP>
      void apply_bs( TB &res, TP ) const {
          res.set_type( "FieldStructureCompactClass" );
          APPLY_WN( res, num_level );
          APPLY_WN( res, dim );
          APPLY_WN( res, patterns );
          APPLY_WN( res, group_elements );
          APPLY_WN( res, group_interfaces );
          
      }
      //***********************************************************************************
      //Methode pour SC_create
      //*********************************************************************************** 
      //Methode générique  ---------------------------------------------------------------------------------------------------------------------------
      
      FieldStructureGroupElementsUser* find_group_elements(int id_);              // renvoi d'un group_elements particulier a partir de son id
      int find_index_group_elements(int id_);                                   // recherche de l'index d'un group_elements particulier avec son id
      
      FieldStructureGroupInterfacesUser* find_group_interfaces(int id_);          // renvoi d'un group_interfaces particulier a partir de son id
      int find_index_group_interfaces(int id_);                                 // recherche de l'index d'un group_interfaces particulier avec son id
      
      BasicVec< FieldStructureGroupInterfacesUser* > find_group_edges(int edge_id_); // renvoi de tous les group_interface de bord à partir d'un edge_id_
      BasicVec< int > find_index_group_edges(int edge_id_);                     // recherche de tous les index des group_interface ayant edge_id = edge_id_

      //Methode d'initialisation----------------------------------------------------------------------------------------------------------------------
      FieldStructureUser();
      FieldStructureUser(GeometryUser &geometry_);
      void load_geometry_user(GeometryUser &geometry_);
      
      void assign_material_id_to_group_elements(DataUser &data_user);                  // assignation des id des materiaux aux group_elements
      void assign_material_properties_to_group_elements(DataUser &data_user, BasicVec<BasicVec<TYPE> > &mat_prop);      // assignation des proprietes materiaux aux group_elements
      void assign_link_id_to_group_interfaces(DataUser &data_user);                    // assignation des id des liaisons aux group_interfaces
      void assign_link_properties_to_group_interfaces(DataUser &data_user, BasicVec<BasicVec<TYPE> > &link_prop);       // assignation des proprietes des liaisons aux group_interfaces
      void assign_bc_id_to_group_interfaces(DataUser &data_user);                      // assignation des condition limites aux group_interfaces de type 0 edge

      void initialize_GPU();                                                           // initialisation pour calcul sur GPU
      
      void write_hdf5_in_parallel(Sc2String file_output, GeometryUser &geometry_user, Sc2String name_fields, int pt_cur, TYPE val_time, int rank); //ecriture des champs de structure dans un fichier hdf5 specifie sur un processeur
      
      //Methode de niveau sup-------------------------------------------------------------------------------------------------------------------------
//       void  calculate_ddr(GeometryUser &geometry_);              //calcul des directions de recherche pour la strategie de type multi (sur les groupes d'interfaces)
//       void  calculate_rigidity();                                //calcul des operateurs de rigidite (rigidite EF + ddr) pour la strategie de type multi (sur les groupes d'elements)
//       void  calculate_homogeneised_operator();                   //calcul des operateurs homogénéisés pour la strategie de type multi (sur les groupes d'elements)


      //Methode de niveau courrant -------------------------------------------------------------------------------------------------------------------
      //void convert_fields_from_SST(Sst<DIM,TYPE> &S, DataUser &data_user);      //conversion des champs des SST en donnees exploitables sous GPU (group_elements)
      
      
       
};

#endif //FIELDSTRUCTUREUSER_H