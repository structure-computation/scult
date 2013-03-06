#ifndef DATA_USER_H
#define DATA_USER_H


#include "../UTILS/ScJsonReader.h"

#include <Metil/Level1/CompilationEnvironment.h>
#include <Metil/DynamicLibrary.h>
#include <Metil/BasicVec.h>

#include "DataReader.h"
#include "../GEOMETRY/Patterns.h"
#include "Properties.h"
#include "../UTILS/json_spirit/json_spirit.h"
#include "../UTILS/Sc2String.h"

#include "../UTILS/Sc2String.h"

using namespace json_spirit;  
using namespace Metil;
BEG_METIL_NAMESPACE;

class DataUser: public ScJsonReader{
    //******************************************************************************************
    //Attributs
    //******************************************************************************************
    public :
    //nom et chemins de fichier--------------------------------
    Sc2String metil_comp_path;        /// chemin vers metil_comp pour la compilation à la volée
    Sc2String model_path;             /// chemin d'acces au repertoire model
    Sc2String name_mesh_user;         /// nom du fichier mesh utilisateur
    Sc2String extension;              /// extention pour le nom du fichier de mesh
    Sc2String name_directory;         /// nom du repertoire pour sauvegarder le motif
    Sc2String mesh_directory;         /// nom du repertoire pour sauvegarder les meshs  
    Sc2String name_calcul;         /// nom du calcul donne dans l'interface
    Sc2String calcul_path;            /// chemin d'acces au repertoire model
    Sc2String result_path;            /// chemin d'acces au repertoire model
    Sc2String file_calcul;            /// fichier json pour le calcul
    Sc2String id_calcul;              /// id du calcul en cours

    Patterns patterns;
    Properties properties;  
    static const int dim = DIM;
    

    /// Defini une interface pour les autres classes (GeometryUser et FieldStructureUser)  A REVOIR
    int nb_ddl;
    int nb_sst;
    int nb_inter;
    int nb_groups_elem;

    int nb_groups_inter;/*
    BasicVec<Json_pieces>     &group_elements;
    BasicVec<Json_edges>      &group_edges;
    BasicVec<Json_interfaces> &group_interfaces;
    BasicVec<Json_materials>  &behaviour_materials;
    BasicVec<Json_links>      &behaviour_links;*/
 
    //******************************************************************************************
    //Méthodes
    //******************************************************************************************
    
    ///initialisation des données------------------------------------------------------------------------------------------
    DataUser(Sc2String model_path_, Sc2String calcul_path_, Sc2String id_calcul_);
    DataUser(Sc2String id_model_, Sc2String id_calcul_);
    DataUser();
    void initialisation(Sc2String id_model_, Sc2String id_calcul_);         /// même fonction que le constructeur ayant les mêmes arguments
    
    ///lecture du json pour les differente structure de données------------------------------------------------------------
    void read_json_calcul();

    
    ///ecriture des .cpp read_prop pour compilation à la volée------------------------------------------------------------
    void write_entete_h( StringWithSepInCppLineMaker &file);
    
    void write_global_read_data_materials_group_elements( int i_mat,  StringWithSepInCppLineMaker &file);   // ecriture de la fonction globale pour les calcul des propriété materiaux        
    void write_launch_read_data_materials_group_elements( StringWithSepInCppLineMaker &file );        // boucle sur les groupes d'elements pour l'appel de la fonction globale
    
    void write_global_read_data_links_group_interfaces( int i_link, StringWithSepInCppLineMaker &file);           // ecriture de la fonction globale pour les calcul des propriété liaisons
    void write_launch_read_data_links_group_interfaces( StringWithSepInCppLineMaker &file );          // boucle sur les groupes d'interface de type 1 ou 2 pour l'appel de la fonction globale
    
    void write_global_read_data_bc_group_interfaces( int i_bc, int i_step, StringWithSepInCppLineMaker &file);              // ecriture de la fonction globale pour les calcul des propriété edge
    void write_launch_read_data_bc_group_interfaces( StringWithSepInCppLineMaker &file );             // boucle sur les groupes d'interface de type 0 pour l'appel de la fonction globale
    
    void write_global_read_data_bc_volume_poids_group_elements( int i_CLv, int i_step, StringWithSepInCppLineMaker &file);   // ecriture de la fonction globale qui calcul l'effort du au poid sur un element
    void write_global_read_data_bc_volume_acceleration_group_elements( int i_CLv, int i_step, StringWithSepInCppLineMaker &file);   // ecriture de la fonction globale qui calcul l'effort d'acceleration sur un element
    void write_launch_read_data_bc_volume_group_elements( StringWithSepInCppLineMaker &file );          // boucle sur les groupes d'elements pour l'appel de la fonction globale sur les effort volumiques
    
    void write_read_prop_cpp(Sc2String &file_cu, Sc2String &file_h);
    DataReader *NEW_DataReader( );
    
};

END_METIL_NAMESPACE;

#endif //DATA_USER_H
