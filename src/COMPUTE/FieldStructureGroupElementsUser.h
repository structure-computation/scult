//
// C++ Interface: Définition des field structure pour les group_elements
//
// Description: 
//
//
// Author: Jeremie Bellec <j.bellec@structure-computation.com>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef FIELD_STRUCTURE_GROUP_ELEMENTS_USER_H
#define FIELD_STRUCTURE_GROUP_ELEMENTS_USER_H

#include <cmath>
#include <Metil/BasicVec.h>
#include <Metil/StructCompactor.h>

#include "Patterns.h"
#include "Properties.h"
#include "GeometryUser.h"
#include <boost/concept_check.hpp>

using namespace Metil;



//group elements---------------------------------------------------------------------------------------------------------------------------
struct FieldStructureGroupElementsUser{
    // attributs du groupe------------------------------------------
    int id;
    int pattern_id;
    int material_id;
    int nb_nodes;                                       //nombre de noeuds du groupe
    int nb_nodes_skin;                                  //nombre de noeuds sur la peau du groupe
    int nb_nodes_for_GPU;                               //nombre de noeuds du groupe multiple de la taille acceptee par le GPU
    int nb_elements;                                    //nombre d'elements du groupe (taille des vecteurs definis aux elements)
    int nb_elements_skin;                               //nombre d'elements de peau du groupe 
    int nb_elements_for_GPU;                            //nombre d'elements multiple de la taille acceptee par le GPU
    int nb_elements_skin_for_GPU;                       //nombre d'elements de peau multiple de la taille acceptee par le GPU
       
    BasicVec< BasicVec< TYPE > > pt;                    // centre de l'element
    BasicVec< TYPE > size;                              // volume de l'element
    
    BasicVec< BasicVec< TYPE > > volumic_force;         // force volumique sur cet element
    
    // champs de propriétés materiau      
    BasicVec< BasicVec< TYPE > > mat_prop;              // liste des propriété dans l'ordre de DataUser::BehaviourMaterial
    
    // champs de matrice élémentaire     
    BasicVec< BasicVec< TYPE > > mat_elem;              // liste des composantes des matrices élémentaires stockés en symétrique : mat_elem[i*(i+1)/2+j][i_elem] permet d'accéder au terme (i,j) de la matrice de rigidité de l'élément i_elem.
    
    //champs issus de calcul
    BasicVec<BasicVec<TYPE>,DIM > displacement_local_nodes;                     ///< deplacements aux noeuds
    BasicVec<BasicVec<TYPE>,DIM > explode_displacement_local_nodes;             ///< deplacements pour l'éclaté aux noeuds
    BasicVec<BasicVec< TYPE > , DIM*(DIM+1)/2 > sigma;                          ///< vecteur contrainte du maillage
    BasicVec<BasicVec< TYPE > , DIM*(DIM+1)/2 > epsilon;                        ///< vecteur deformation du maillage
    BasicVec< TYPE > sigma_mises;                                               ///< vecteur contrainte de von mises du maillage    
    BasicVec< TYPE > material_behaviour;                                        ///< numero du materiau assigné à la pièce
    BasicVec< TYPE > num_processor;                                             ///< numero du processeur traitant la pièce
    BasicVec<BasicVec<TYPE>,DIM > displacement_local_nodes_skin;                ///< deplacements aux noeuds de peau 
    BasicVec<BasicVec<TYPE>,DIM > explode_displacement_local_nodes_skin;        ///< deplacements pour l'éclaté aux noeuds de peau 
    BasicVec<BasicVec< TYPE > , DIM*(DIM+1)/2 > sigma_skin;                     ///< vecteur contrainte du maillage de peau 
    BasicVec<BasicVec< TYPE > , DIM*(DIM+1)/2 > epsilon_skin;                   ///< vecteur deformation du maillage de peau 
    BasicVec< TYPE > sigma_mises_skin;                                          ///< vecteur contrainte de von mises du maillage de peau 
    BasicVec< TYPE > material_behaviour_skin;                                   ///< numero du materiau assigné à la pièce (peau)
    BasicVec< TYPE > num_processor_skin;                                        ///<  numero du processuer traitant la pièce (peau)
    
    // méthodes du groupe------------------------------------------
    
    //Méthode permettant de spécifier les champs à inclure dans la structure compactée dont le nom est donné par set_type. Cette méthode est appelée lors de la génération des classes compactées.
    template<class TB,class TP>
    void apply_bs( TB &res, TP ) const {
        res.set_type( "FieldStructureGroupElements" );
        APPLY_WN( res, id    );
        APPLY_WN( res, pattern_id  );
        APPLY_WN( res, material_id  );
        APPLY_WN( res, nb_elements  );
        APPLY_WN( res, nb_elements_for_GPU  );
        APPLY_WN( res, pt  );
        APPLY_WN( res, mat_prop  );
        APPLY_WN( res, volumic_force  );
        APPLY_WN( res, mat_elem  );
        APPLY_WN( res, size  );
        APPLY_WN( res, displacement_local_nodes  );
        APPLY_WN( res, explode_displacement_local_nodes  );
        APPLY_WN( res, sigma  );
        APPLY_WN( res, epsilon  );
        
    }
    //Constructeurs
    FieldStructureGroupElementsUser(){};
    void initialize(GeometryUser &geometry_, int i_group_, Properties &properties_ ){
        id = geometry_.group_elements[i_group_].id;
        pattern_id = geometry_.group_elements[i_group_].pattern_id;
        nb_elements = geometry_.group_elements[i_group_].nb_elements;
        nb_nodes = geometry_.group_elements[i_group_].local_nodes[0].size();
        nb_elements_skin = geometry_.group_elements[i_group_].nb_elements_skin;
        nb_nodes_skin = geometry_.group_elements[i_group_].nb_nodes_skin;
        
        size.resize(nb_elements,0);
        pt.resize(DIM);
        volumic_force.resize(DIM);

        for(int i=0; i<DIM; i++){
            pt[i].resize(nb_elements,0);
            volumic_force[i].resize(nb_elements,0);
        }
        mat_prop.resize(properties_.mat_prop_name.size());
        for(int i_prop=0; i_prop<mat_prop.size(); i_prop++){
            mat_prop[i_prop].resize(nb_elements, 0);
        }
        mat_elem.resize(geometry_.group_elements[i_group_].connectivities.size());
        for(int i_mat=0;i_mat<mat_elem.size();i_mat++){
            mat_elem[i_mat].resize(nb_elements,0);
        }
        //initialisation des tailles des vecteurs champs
        for(int d=0;d<DIM;d++){
            displacement_local_nodes[d].resize(nb_nodes,0);
            displacement_local_nodes_skin[d].resize(nb_nodes,0);
            explode_displacement_local_nodes[d].resize(nb_nodes,0);
            explode_displacement_local_nodes_skin[d].resize(nb_nodes,0);
        }	
        for(int d=0;d<DIM*(DIM+1)/2;d++){
            sigma[d].resize(nb_elements,0);
            epsilon[d].resize(nb_elements,0);
            sigma_skin[d].resize(nb_elements_skin,0);
            epsilon_skin[d].resize(nb_elements_skin,0);
        }
        sigma_mises.resize(nb_elements,0);
        sigma_mises_skin.resize(nb_elements_skin,0);
        material_behaviour.resize(nb_elements,0);
        material_behaviour_skin.resize(nb_elements_skin,0);
        num_processor.resize(nb_elements,0);
        num_processor_skin.resize(nb_elements_skin,0);
    }
    // Définition des tailles des listes pour utilisation sous GPU
    void initialize_GPU(Patterns &patterns){
        int threadsPerBlock = 48;
        int n_group_blocks = std::ceil( nb_elements / threadsPerBlock );  // obtenir l'entier superieur
        nb_elements_for_GPU = (n_group_blocks + 1) * threadsPerBlock;
        int nn_group_blocks = std::ceil( nb_nodes / threadsPerBlock );  // obtenir l'entier superieur
        nb_nodes_for_GPU = (nn_group_blocks + 1) * threadsPerBlock;

        
        size.resize(nb_elements_for_GPU,0);
        for(int i=0; i<DIM; i++){
            pt[i].resize(nb_elements_for_GPU,0);
            volumic_force[i].resize(nb_elements_for_GPU,0);
        }
        for(int i_prop=0; i_prop<mat_prop.size(); i_prop++){
            mat_prop[i_prop].resize(nb_elements_for_GPU,0);
        }
        for(int i_mat=0;i_mat<mat_elem.size();i_mat++){
            mat_elem[i_mat].resize(nb_elements_for_GPU);
        }
        for(int d=0;d<DIM;d++){
            displacement_local_nodes[d].resize(nb_nodes_for_GPU,0);
            explode_displacement_local_nodes[d].resize(nb_nodes_for_GPU,0);
        }       
        for(int d=0;d<DIM*(DIM+1)/2;d++){
            sigma[d].resize(nb_elements_for_GPU,0);
            epsilon[d].resize(nb_elements_for_GPU,0);
        }
    }
    // Affichage pour vérification
    void affiche(){
        PRINT("group_elements-----------------------------------------------------------");
        PRINT(id);
        PRINT(nb_elements);
    }
    
    void write_hdf5(Hdf &hdf_file, Sc2String name_fields, int pt_cur, TYPE val_time);      //ecriture des champs specifies sur les groupes d'elements dans un fichier hdf5
    void write_skin_hdf5(Hdf &hdf_file, Sc2String name_fields, int pt_cur, TYPE val_time);      //ecriture des champs specifies sur la peau (skin) des groupes d'elements dans un fichier hdf5
    
    
};


#endif //FIELD_STRUCTURE_GROUP_ELEMENTS_USER_H


