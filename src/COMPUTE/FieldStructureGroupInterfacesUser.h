//
// C++ Interface: Définition des field structure pour les group_interfaces
//
// Description: 
//
//
// Author: Jeremie Bellec <j.bellec@structure-computation.com>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//


#include <Metil/BasicVec.h>
#include <Metil/StructCompactor.h>

#include "Patterns.h"
#include "Properties.h"
#include "GeometryUser.h"
//#include "containers/mat.h"

using namespace Metil;
//using namespace LMT;

#ifndef FIELD_STRUCTURE_GROUP_INTERFACES_USER_H
#define FIELD_STRUCTURE_GROUP_INTERFACES_USER_H
              
//group_interfaces---------------------------------------------------------------------------------------------------------------------------
struct FieldStructureGroupInterfacesUser{ 
    // attributs du groupe------------------------------------------
    int id;                                                          //identité du group
    int edge_id;                                                     //identité du edge si c'est un bord issu d'un split (-1 sinon)
    int type;                                                        // type de comportement d'interface (0 deplacement impose, 1 effort impose, 2 symetrie, 3 deplacement normal, 4 parfaite, 5 contact avec ou sans jeu/epaisseur, 6 parfaite avec jeu impose, 7 periodique, 8 autre )
    int link_id;                                                     //identite de la liaison (-1 si c'est un bord)
    int bc_id;                                                       //identite de la CL (-1 si c'est une liaison)
    int nb_interfaces;
    int nb_interfaces_for_GPU;

    BasicVec< BasicVec< TYPE > > pt;                    // centre des elements (taille DIM, taille nb_interfaces)
    
    //champs de propriétés liaison ou edge      
    BasicVec< BasicVec< TYPE > > link_prop;             // liste des propriétés dans l'ordre de Properties
    BasicVec< BasicVec< TYPE > > BC_step_prop;          // liste des propriétés dans l'ordre de Properties
    
    //Operateurs du groupe
    TYPE ddr;                                           // scalaire pour l'operateur de direction de recherche
    BasicVec< BasicVec< TYPE > > eM;                    // operateur d'extraction macro (taille nb_fct_macro (4 ou 9) x nb_interfaces
    
    //champs du groupe
    BasicVec< BasicVec< TYPE > > bc;                    // champs des valeur de la condition limites sur chaque interface pour type 0
    BasicVec< BasicVec< BasicVec<TYPE>, DIM > > F, W; // champs de déplacement et contrainte normale sur les elements d'interface
    
    // méthodes du groupe------------------------------------------
    template<class TB,class TP>
    void apply_bs( TB &res, TP ) const {
        res.set_type( "FieldStructureGroupInterfaces" );
        APPLY_WN( res, id    );
        APPLY_WN( res, edge_id    );
        APPLY_WN( res, type    );
        APPLY_WN( res, link_id    );
        APPLY_WN( res, bc_id    );
        APPLY_WN( res, nb_interfaces  );
        APPLY_WN( res, nb_interfaces_for_GPU  );
        APPLY_WN( res, pt  );
        APPLY_WN( res, link_prop  );
        APPLY_WN( res, BC_step_prop  );
        
        APPLY_WN( res, bc  );
    }
    
    FieldStructureGroupInterfacesUser(){   
    } 
    void initialize(GeometryUser &geometry_, int i_group_, Properties &properties_){
        //std::cout << "ajout d'un group_interfaces n° " << id_ << std::endl;
        id = geometry_.group_interfaces[i_group_].id;
        edge_id = geometry_.group_interfaces[i_group_].edge_id;
        link_id = -1;
        bc_id = -1;
        nb_interfaces = geometry_.group_interfaces[i_group_].nb_interfaces;
        type = geometry_.group_interfaces[i_group_].type;
        pt.resize(DIM);
        for(int i=0; i<DIM; i++){
            pt[i].resize(nb_interfaces,0);
        }
        
        int nb_sides=0;
        if(type == 0){//bord
            BC_step_prop.resize(properties_.BC_step_prop_name.size());
            for(int i_prop=0; i_prop<BC_step_prop.size(); i_prop++){
                BC_step_prop[i_prop].resize(nb_interfaces, 0);
            }   
            bc.resize(DIM);
            for(int d=0; d<DIM; d++){
                bc[d].resize(nb_interfaces,0);
            }
            nb_sides=1;
        }else if(type == 1 or type == 2){//interieur ou liaison
            bc.resize(0);
            link_prop.resize(properties_.link_prop_name.size());
            for(int i_prop=0; i_prop<link_prop.size(); i_prop++){
                link_prop[i_prop].resize(nb_interfaces, 0);
            }
            nb_sides=2;
        }  
        F.resize(nb_sides); W.resize(nb_sides);
        for(unsigned i_side=0;i_side<nb_sides;i_side++){
            for(int d=0;d<DIM;d++){
                F[i_side][d].resize(nb_interfaces,0);
                W[i_side][d].resize(nb_interfaces,0);
            }
        }        
    }
    // resize des liste pour GPU
    void initialize_GPU(Patterns &patterns){
        int threadsPerBlock = 48;
        int n_group_blocks = std::ceil( nb_interfaces / threadsPerBlock );  // obtenir l'entier superieur
        nb_interfaces_for_GPU = (n_group_blocks + 1) * threadsPerBlock;
        for(int i=0; i<DIM; i++){
            pt[i].resize(nb_interfaces_for_GPU,0);
        }
        int nb_sides=0;
        if(type == 0){//bord
            for(int i_prop=0; i_prop<BC_step_prop.size(); i_prop++){
                BC_step_prop[i_prop].resize(nb_interfaces_for_GPU, 0);
            } 
            for(int d=0; d<DIM; d++){
                bc[d].resize(nb_interfaces_for_GPU,0);
            }
            nb_sides=1;
        }else if(type == 1 or type == 2){//interieur ou liaison
            for(int i_prop=0; i_prop<link_prop.size(); i_prop++){
                link_prop[i_prop].resize(nb_interfaces_for_GPU, 0);
            }
            nb_sides=2;
        }  
        F.resize(nb_sides); W.resize(nb_sides);
        for(unsigned i_side=0;i_side<nb_sides;i_side++){
            for(int d=0;d<DIM;d++){
                F[i_side][d].resize(nb_interfaces_for_GPU,0);
                W[i_side][d].resize(nb_interfaces_for_GPU,0);
            }
        }
    }
    // affichage pour vérification
    void affiche(){
        PRINT("group_interfaces-----------------------------------------------------------");
        PRINT(id);
        PRINT(edge_id);
        PRINT(type);
        PRINT(link_id);
        PRINT(bc_id);
        PRINT(nb_interfaces);
        
    }
    
    void write_hdf5(Hdf &hdf_file, Sc2String name_fields, int side, int pt_cur, TYPE val_time); //ecriture des champs sur les groupes d'interfaces dans un fichier hdf5
};

#endif //FIELD_STRUCTURE_GROUP_INTERFACES_USER_H


