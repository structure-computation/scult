//
// C++ Interface: DataUser
//
// Description: 
//
//
// Author: Jeremie Bellec <j.bellec@structure-computation.com>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef DATA_USER_H
#define DATA_USER_H


#include <iostream>
#include <fstream>

#include <Metil/Level1/CompilationEnvironment.h>
#include <Metil/DynamicLibrary.h>
#include <Metil/BasicVec.h>

#include "DataReader.h"
#include "Patterns.h"
#include "Properties.h"
#include "json_spirit.h"

using namespace json_spirit;  
// using namespace Metil;
BEG_METIL_NAMESPACE;

class DataUser{
    //******************************************************************************************
    //Attributs
    //******************************************************************************************
    public :
    DataUser(std::string model_path_, std::string calcul_path_, const char *id_calcul_){
        id_calcul << id_calcul_;
        model_path = model_path_;
        calcul_path = calcul_path_;
//         PRINT(id_calcul);
    }
    DataUser(std::string id_model_, std::string id_calcul_){
        model_path = "/share/sc2/Developpement/MODEL/";
        calcul_path = model_path + "model_" + id_model_ + "/calcul_" + id_calcul_ ;
        file_calcul = calcul_path + "/calcul.json" ;    
        id_calcul << id_calcul_.c_str();
//         PRINT(id_calcul);
    }
    DataUser(){
    }
    //nom et chemins de fichier--------------------------------
    std::string metil_comp_path;                //chemin vers metil_comp pour la compilation à la volée
    std::string model_path; 		        //chemin d'acces au repertoire model
    std::string name_mesh_user; 		//nom du fichier mesh utilisateur
    std::string extension; 		        //extention pour le nom du fichier de mesh
    std::string name_directory; 		//nom du repertoire pour sauvegarder le motif
    std::string mesh_directory; 		//nom du repertoire pour sauvegarder les meshs  
    std::string calcul_path;                    //chemin d'acces au repertoire calcul
    std::string file_calcul;                    //fichier json pour le calcul
    String id_calcul;                           // id du calcul en cours
    Patterns patterns;
    Properties properties;  
    static const int dim = DIM;
    
    // attribut des groupes ----------------------------------------------------------------
    // DATA pour les groupes d'elements--------------------
    struct GroupElements{
        int id;
        std::string name;
        int num_in_mesh_file;
        std::string origine; //origine du groupe d'element
        int id_material;
        
        template<class TB,class TP>
        void apply_bs( TB &res, TP ) const {
            res.set_type( "GroupElements" );
            //pour SC_create-------------------------
            //info du groupe
            APPLY_WN( res, id    );
//             APPLY_WN( res, name    );
            APPLY_WN( res, num_in_mesh_file    );
            APPLY_WN( res, id_material    );
        }
    };
    BasicVec<GroupElements> group_elements;
    
    // DATA pour les groupes d'interfaces------------------
    struct GroupInterfaces{
        int id;
        std::string name;
        int num_in_mesh_file;
        BasicVec<GroupElements *,2> adj_group_elements;
        BasicVec<int> adj_num_group;
        std::string origine; //origine du groupe d'interface
        std::string type;
        int id_link;
        float assigned;
        
        GroupInterfaces(){
            adj_num_group.resize(2);
        }
        
        template<class TB,class TP>
        void apply_bs( TB &res, TP ) const {
            res.set_type( "GeometryEdges" );
            //pour SC_create-------------------------
            //info du groupe
            APPLY_WN( res, id    );
//             APPLY_WN( res, name    );
            APPLY_WN( res, num_in_mesh_file    );
            APPLY_WN( res, adj_num_group    );
            APPLY_WN( res, id_link    );
        }
    };
    BasicVec<GroupInterfaces> group_interfaces;
    
    // DATA pour les groupes de bords --------------------
    struct Geometry{
        std::string origine;
        std::string type;
        std::string nature;
        double radius;
        BasicVec<BasicVec<double, DIM> > points;
        BasicVec<double, DIM> pdirection;
        std::string equation;
        
        Geometry(){
            points.resize(DIM);
            pdirection.resize(DIM);
        }
        
        template<class TB,class TP>
        void apply_bs( TB &res, TP ) const {
            res.set_type( "GeometryEdges" );
            //pour SC_create-------------------------
            //info du groupe
//             APPLY_WN( res, origine    );
//             APPLY_WN( res, type    );
//             APPLY_WN( res, nature    );
            APPLY_WN( res, radius    );
            APPLY_WN( res, points    );
            APPLY_WN( res, pdirection    );
//             APPLY_WN( res, equation    );
        }
        
    };
    struct GroupEdges{
        int id;
        std::string name;
        int num_in_mesh_file;
        BasicVec<GroupElements *> adj_group_elements;
        BasicVec<int> adj_num_group;
        Geometry geom;
        int id_CL;
        float assigned;
        int to_visualize;
        
        GroupEdges(){
            adj_num_group.resize(1);
        }
        
        template<class TB,class TP>
        void apply_bs( TB &res, TP ) const {
            res.set_type( "GroupEdges" );
            //pour SC_create-------------------------
            //info du groupe
            APPLY_WN( res, id    );
//             APPLY_WN( res, name    );
            APPLY_WN( res, num_in_mesh_file    );
            APPLY_WN( res, adj_num_group    );
            APPLY_WN( res, id_CL    );
            APPLY_WN( res, assigned    );
            APPLY_WN( res, geom    );
        }
    };
    BasicVec<GroupEdges> group_edges;
    
    
    // DATA pour les comportement materiaux --------------------
    struct BehaviourMaterial {
        BehaviourMaterial(){
            mat_prop.resize(properties.mat_prop_name.size(),"0");
            mat_prop_name = properties.mat_prop_name;
        }
	std::string name;
	std::string familly;
	std::string name_select;
	std::string description;
	std::string type;
	std::string comp;
        std::string resolution;
	int    type_num;
	int    id;
    
        Properties properties;
        BasicVec< std::string > mat_prop;
        BasicVec< std::string > mat_prop_name;
        
        template<class TB,class TP>
        void apply_bs( TB &res, TP ) const {
            res.set_type( "BehaviourMaterial" );
            //pour SC_create-------------------------
            //info du groupe
            APPLY_WN( res, id    );
//             APPLY_WN( res, name    );
//             APPLY_WN( res, familly    );
//             APPLY_WN( res, type    );
//             APPLY_WN( res, comp    );
            APPLY_WN( res, type_num    );
//             APPLY_WN( res, resolution    );
        }
	
    };
    BasicVec<BehaviourMaterial > behaviour_materials;
    BasicVec< BasicVec< int > > num_materials_id_group_elements;
    
    
    // DATA pour les comportement liaison --------------------
    struct BehaviourLink {
        BehaviourLink(){
            link_prop.resize(properties.link_prop_name.size(),"0");
            link_prop_name = properties.link_prop_name;
        }
        int id;
        std::string  name;
        std::string  familly;
        int  company_id;
        int  reference;
        int  id_select;
        std::string  name_select;
        std::string  type;
        std::string  comp_complexe;
        int  type_num;

        Properties properties;
        BasicVec< std::string > link_prop;
        BasicVec< std::string > link_prop_name;
        
        template<class TB,class TP>
        void apply_bs( TB &res, TP ) const {
            res.set_type( "BehaviourLink" );
            //pour SC_create-------------------------
            //info du groupe
            APPLY_WN( res, id    );
//             APPLY_WN( res, name    );
//             APPLY_WN( res, familly    );
            APPLY_WN( res, id_select    );
//             APPLY_WN( res, type    );
//             APPLY_WN( res, comp_complexe    );
            APPLY_WN( res, type_num    );
        }
        
    };
    BasicVec<BehaviourLink > behaviour_links;
    BasicVec< BasicVec< int > > num_links_id_group_interfaces;
    
    
    // DATA pour les condition limite --------------------
    struct StepBc{
        StepBc(){
            CL_step_prop.resize(properties.BC_step_prop_name.size(),"0");
            CL_step_prop_name = properties.BC_step_prop_name;
        }
        
        Properties properties;
        BasicVec< std::string > CL_step_prop;
        BasicVec< std::string > CL_step_prop_name;   
    };
    struct BehavBc {
        int id;
        std::string type;
        BasicVec<StepBc> step;
        
        template<class TB,class TP>
        void apply_bs( TB &res, TP ) const {
            res.set_type( "BehaviourBc" );
            //pour SC_create-------------------------
            //info du groupe
            APPLY_WN( res, id    );
//             APPLY_WN( res, type    );
        }
    }; 
    BasicVec<BehavBc > behaviour_bc;
   
    
    // DATA pour les condition limite en volume-----------
    struct StepBcVolume{
        StepBcVolume(){
            CLv_step_prop.resize(properties.BCv_step_prop_name.size(),"0");
            CLv_step_prop_name = properties.BCv_step_prop_name;  
        }
        
        Properties properties;
        BasicVec< std::string > CLv_step_prop;
        BasicVec< std::string > CLv_step_prop_name;   
        
    };
    struct BehavBcVolume{
        std::string name;
        BasicVec<StepBcVolume> step;
        std::string type;
        bool select;
        int ref;
        
        template<class TB,class TP>
        void apply_bs( TB &res, TP ) const {
            res.set_type( "BehaviourBcVolume" );
            //pour SC_create-------------------------
            //info du groupe
//             APPLY_WN( res, name    );
//             APPLY_WN( res, type    );
//             APPLY_WN( res, select    );
            APPLY_WN( res, ref    );
        }
        BehavBcVolume(){
	    select = false;
	}
    };
    BasicVec<BehavBcVolume> behaviour_bc_volume;
    
    struct TimeStep{
        TYPE dt; //pas de temps
        std::string name ; //nom du step
        int nb_time_step; // nombre de pas de temps dans le step
        TYPE tf; //temps final du step
        TYPE ti; //temps initial du step
    }; 
    BasicVec<TimeStep> time_step; // ensemble des données sur les steps
    
    struct MultiresolutionParameters{
        TYPE min_value,max_value,nominal_value, current_value; //données concernant les variations d'un paramètre
        std::string name ; //nom du paramètre donné par l'utilisateur et utilisé dans les expressions
        int nb_values; // nombre de valeurs du paramètre (uniquement en plan d'exp) sinon utilisation de Multiresolution_nb_cycle
        BasicVec<int> materials, links, CL, CLvolume; //liste des numeros des données utilisées pour la multirésolution
    };
    BasicVec<MultiresolutionParameters> Multiresolution_parameters; // ensemble des données pour la multirésolution
    
    // DATA pour les options de calcul-----------------------
    struct OptionsCalcul {
        template<class TB,class TP>
        void apply_bs( TB &res, TP ) const {
            res.set_type( "OptionsCalcul" );
            //pour SC_create-------------------------
            //info du groupe
            APPLY_WN( res, dissipation    );
            APPLY_WN( res, nb_option    );
            APPLY_WN( res, nb_level    );
//             APPLY_WN( res, Temp_statique   );
//             APPLY_WN( res, mode    );
//             APPLY_WN( res, resolution_2D    );
            APPLY_WN( res, LATIN_nb_iter_max    );
            APPLY_WN( res, LATIN_crit_error    );
            APPLY_WN( res, LATIN_crit_error_auto_stop    );
            APPLY_WN( res, PREC_erreur    );
            APPLY_WN( res, multiechelle    );
            APPLY_WN( res, LATIN_current_iter    );
            APPLY_WN( res, save_depl    );
        }
        OptionsCalcul(){
            Multiresolution_on = 0;
            Multiresolution_nb_cycle = 1;
            Multiresolution_type = "fatigue";
            Multiresolution_nb_calcul = 1;
            Multiresolution_material_link_CL_CLvolume=BasicVec<int>(0,0,0,0);
	    LATIN_crit_error_auto_stop = 0;
	    trac_ener_diss=0;
	    trac_ener_imp=0;
        }
        std::string mode;
        std::string resolution_2D;
        int nb_option;
        std::string Temp_statique;
        int LATIN_nb_iter_max;
        TYPE LATIN_crit_error;
        TYPE LATIN_crit_error_auto_stop;
        int PREC_erreur;
        int nb_level;
        int multiechelle;
        int save_depl;        
        int Multiresolution_on;
        std::string Multiresolution_type;
        int Multiresolution_nb_cycle;
        int Multiresolution_current_resolution;
        int Multiresolution_nb_calcul;
        BasicVec<int,4> Multiresolution_material_link_CL_CLvolume;
        int dissipation;
        int LATIN_current_iter;
	int trac_ener_imp;
	int trac_ener_diss;
    };
    OptionsCalcul options;
    
    
    
    
    template<class TB,class TP>
    void apply_bs( TB &res, TP ) const {
        res.set_type( "DataCompactClass" );
        //pour SC_create-------------------------
        //info du groupe
        APPLY_WN( res, options    );
        APPLY_WN( res, group_elements    );
        APPLY_WN( res, group_interfaces    );
        APPLY_WN( res, group_edges    );
        APPLY_WN( res, behaviour_materials    );
        APPLY_WN( res, behaviour_links    );
        APPLY_WN( res, behaviour_bc    );
        APPLY_WN( res, behaviour_bc_volume    );
    }
 
    //******************************************************************************************
    //Méthodes
    //******************************************************************************************
    
    GroupElements* find_group_elements(int id_) ;                       // recherche d'un group_elements particulier avec son id
    GroupInterfaces* find_group_interfaces(int id_);                    // recherche d'un group_interfaces particulier avec son id
    GroupEdges* find_group_edges(int id_);                              // recherche d'un group_edges particulier avec son id
    BehaviourMaterial* find_behaviour_materials(int id_);               // recherche d'un behaviour_materials particulier avec son id
    BehaviourLink* find_behaviour_links(int id_);                       // recherche d'un behaviour_links particulier avec son id
    BehavBc* find_behaviour_bc(int id_);                                // recherche d'un behaviour_bc particulier avec son id
    
    int find_index_group_elements(int id_);                             // recherche de l'indexe d'un group_elements particulier avec son id
    int find_index_group_interfaces(int id_);                           // recherche de l'indexe d'un group_interfaces particulier avec son id
    int find_index_group_edges(int id_);                                // recherche de l'indexe d'un group_edges particulier avec son id
    int find_index_behaviour_materials(int id_);                        // recherche de l'indexe d'un behaviour_materials particulier avec son id
    int find_index_behaviour_links(int id_);                            // recherche de l'indexe d'un behaviour_links particulier avec son id
    int find_index_behaviour_bc(int id_);                               // recherche de l'indexe d'un behaviour_bc particulier avec son id
    
    //initialisation des données------------------------------------------------------------------------------------------
    void initialisation(std::string id_model_, std::string id_calcul_);         // même fonction que le constructeur ayant les mêmes arguments
    
    //lecture du json pour les differente structure de données------------------------------------------------------------
    void read_json_groups_elements(const Object& gr);	                        //lecture des groupes d'elements
    void read_json_groups_interfaces(const Object& gr);	                        //lecture des groupes d'interface
    void read_json_groups_edges(const Object& gr);	                        //lecture des groupes de bord
    
    void read_json_behaviour_materials(const Object& gr);	                //lecture des données matériaux
    void read_json_behaviour_interfaces(const Object& gr);                      //lecture des données liaisons
    
    void read_step_bc_volume(const Object& gr, BasicVec<StepBcVolume> &step);	//lecture des step BCvolumes
    void read_json_behaviour_bc_volume(const Object& gr);		        //lecture des BCvolumes
    
    void read_step_bc(const Object& gr, BasicVec<StepBc> &step);		//lecture des step BC
    void read_json_behaviour_bc(const Object& gr);		                //lecture des BC
    
    void read_step_calcul(const Object& gr);                                    //lecture des time_step
    void read_multiresolution(const Object& gr);                                    //lecture des parametres de multiresolution
    
    void read_json_calcul(); 
    
    void find_Multiresolution_parameters();     //recherche des parametres de multiresolution dans les donnees materiau, liaisons, CL, et CLvolume. Stockage des id dans le vecteur Multiresolution_parameters
    
    void assign_num_materials_id_group_elements();                              //assignation des materiaux au groupe_elements
    void assign_num_links_id_group_interfaces();                                //assignation des materiaux au groupe_elements
    
    //ecriture des .cpp read_prop pour compilation à la volée------------------------------------------------------------
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
    
    void write_read_prop_cpp(String &file_cu, String &file_h);
    DataReader *NEW_DataReader( );
    
};

END_METIL_NAMESPACE;

#endif //DATA_USER_H