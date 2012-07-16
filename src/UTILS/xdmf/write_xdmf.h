//
// C++ Implementation: write_in_xdmf
//
// Description: 
//
//
// Author: David Violeau <dvioleau@structure-computation.com>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef XDMF_DATASET
#define XDMF_DATASET
// #include <Metil/Hdf.h>
// #include <iostream>
// #include <fstream>
// #include <cassert>

using namespace Metil;

///Ecriture des DataItems noeuds avec références aux données du fichier hdf5
void write_nodes_datasets(std::ofstream &f,Sc2String input_hdf5, Sc2String name_geometry,int nb_nodes, int i_proc);

///Ecriture des DataItems attributs aux noeuds avec références aux données du fichier hdf5 pour un piquet de temps nt donné (mettre 0 si calcul statique) pour le processeur i_proc
void write_nodes_attributs_datasets(std::ofstream &f,Sc2String input_hdf5,int nb_nodes,Sc2String name_fields, BasicVec<Sc2String>  attributs, int nt, int i_proc );

///Ecriture des DataItems groupes d'éléments avec références aux données du fichier hdf5
void write_groups_datasets(std::ofstream &f,Sc2String input_hdf5, Sc2String name_group_elements,int nb_list,int type_element);
void write_groups_datasets_2(std::ofstream &f,Sc2String input_hdf5, Sc2String name_group_elements);

///Ecriture des DataItems attributs des groupes d'éléments avec références aux données du fichier hdf5 pour un piquet de temps donné (mettre 0 si calcul statique)
void write_groups_attributs_datasets(std::ofstream &f,Sc2String input_hdf5, Sc2String name_elements, Sc2String name_fields, BasicVec<Sc2String>  attributs, int nt);

///Ecriture d'une liste de Grid avec références aux DataItems (avec attributs si nécessaire) pour un piquet de temps donné (mettre 0 si calcul statique)
void write_grids(std::ofstream &f,Sc2String input_hdf5, Sc2String name_geometry, Sc2String name_nodes, BasicVec<int> list, int nb_nodes, Sc2String generic_grid_name, Sc2String name_fields,BasicVec<Sc2String>  attributs, int nt, TYPE dt, int type_element, int i_proc);
void write_grids_2(std::ofstream &f,Sc2String name_hdf5, Sc2String name_elements, Sc2String name_nodes, Sc2String name_fields, Sc2String generic_grid_name, BasicVec<Sc2String>  attributs, int time, int i_proc);
#endif //XDMF_DATASET
