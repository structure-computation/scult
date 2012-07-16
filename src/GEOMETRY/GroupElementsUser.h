//
// C++ Interface: Définition des group_elements et group_interfaces
//
// Description: 
//
//
// Author: Jeremie Bellec <j.bellec@structure-computation.com>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef GROUP_ELEMENTS_USER_H
#define GROUP_ELEMENTS_USER_H


#include <cmath>
#include <Metil/BasicVec.h>
#include <Metil/StructCompactor.h>
#include <Metil/String.h>

#include "Patterns.h"
// #include <boost/concept_check.hpp>
#include <boost/concept_check.hpp>

using namespace Metil;


///group elements---------------------------------------------------------------------------------------------------------------------------
struct GroupElementsUser{
    ///flag du group
    BasicVec< int > flags;
    BasicVec< Sc2String > flags_names;
  
    /// attributs du groupe------------------------------------------
    int id;
    int processor_rank;         //numero du processeur sur lequel est traite le groupe d'element (sst)
    int nb_elements;
    int nb_nodes;
    int nb_elements_skin;
    int nb_nodes_skin;
    int nb_elements_for_GPU;
    int pattern_id;
    int pattern_base_id;
    
    /// attributs des elements du groupe
    BasicVec< int > map_global_nodes;                               ///map entre les noeuds locaux et globaux locale du groupe
    BasicVec< BasicVec< TYPE > > local_nodes;                       ///liste des noeuds du groupe(DIM, nb_nodes)  
    BasicVec< BasicVec< int > > local_connectivities;               ///liste des connectivité des elements par rapport aux noeuds locaux(nb_node_by_pattern de base, nb_elements)  
    BasicVec< BasicVec< int > > local_connectivities_skin;          ///liste des connectivité des elements par rapport aux noeuds locaux(nb_node_by_pattern de base, nb_elements)  
    BasicVec< BasicVec< int > > global_connectivities;              ///liste des connectivité des elements dans le maillage de base (nb_node_by_pattern de base, nb_elements)  
    BasicVec< BasicVec< int > > global_connectivities_skin;         ///liste des connectivité des elements de peau dans le maillage de base (nb_node_by_pattern de base skin, nb_elements_on_skin)  
    BasicVec< BasicVec< int > > connectivities;                     ///liste des connectivité des elements (nb_node_by_pattern, nb_elements)  
    BasicVec< BasicVec< int > > interface_group_id;                 ///numero local du groupe des interfaces adjactentes à chaque motif rangés dans l'ordre des sides (nb_side_by_pattern, nb_elements)
    BasicVec< BasicVec< int > > interface_num_in_group;             ///numero local des interfaces adjactentes à chaque motif dans leur groupe rangés dans l'ordre des sides (nb_side_by_pattern, nb_elements)
    
    /// attributs des groupes d'interfaces adjacents au groupe
    BasicVec< BasicVec< int > > group_interfaces_id;                ///identité des groupes d'interfaces adjactents taille 3 * nb_group_interfaces adjacents en fonction du type : 0 : bord | 1 : interieur au group_elements  |  2 : entre deux group_elements
    BasicVec<int> id_adjacent_group_interfaces;                     ///identite des groupes d'interfaces adjacents a un groupe d'elements (uniquement des groupes d'interfaces de bord ou des liaisons)
    BasicVec<int> side_adjacent_group_interfaces;                   ///numero (0 ou 1) indiquant le coté adjacent des groupes d'interfaces 
    
    
    /// operateur geometrique des elements 
    BasicVec< BasicVec< BasicVec< BasicVec< TYPE > > > > side_N;    /// operateur de passage entre W et U(nb_node_side,nb_node_eq_side,nb_side,nb_elements)  
    BasicVec< BasicVec< BasicVec< TYPE > > > side_M;                /// operateur pour l'intégration sur un side entre W et F (nb_node_eq_side,nb_side,nb_elements)  
    
    /// méthodes du groupe------------------------------------------
    
    ///Méthode permettant de spécifier les champs à inclure dans la structure compactée dont le nom est donné par set_type. Cette méthode est appelée lors de la génération des classes compactées.
    template<class TB,class TP>
    void apply_bs( TB &res, TP ) const {
        res.set_type( "GroupElementsCompactClass" );
        APPLY_WN( res, id    );
//         APPLY_WN( res, flags );
//         APPLY_WN( res, flags_names );
        APPLY_WN( res, nb_elements  );
        APPLY_WN( res, pattern_id  );
        APPLY_WN( res, pattern_base_id  );
        APPLY_WN( res, global_connectivities    );
        APPLY_WN( res, connectivities    );
        APPLY_WN( res, interface_group_id    );
        APPLY_WN( res, interface_num_in_group    );
        APPLY_WN( res, group_interfaces_id    );
        APPLY_WN( res, side_N    );
        APPLY_WN( res, side_M    );
    }
    
    ///Constructeur
    GroupElementsUser(int id_, EntityElementUser &entity_element){
        //std::cout << "ajout d'un group_elements n° " << id_ << std::endl;
        id = id_;
        nb_elements = 0;
        flags = entity_element.flags;
        flags_names = entity_element.flags_names;
        for( int i_flag=0; i_flag<flags_names.size(); i_flag++){
            if(flags_names[i_flag] == "pattern_id"){
                pattern_id = flags[i_flag];
            }
        }
        pattern_base_id = entity_element.pattern_base_id;
        group_interfaces_id.resize(3);
        map_global_nodes.resize(0);
        local_nodes.resize(DIM);
        local_connectivities.resize(entity_element.mesh_connectivity.size());
        global_connectivities.resize(entity_element.mesh_connectivity.size());
        connectivities.resize(entity_element.element_connectivity.size());
        interface_group_id.resize(entity_element.nb_sides);
        interface_num_in_group.resize(entity_element.nb_sides);
        add_entity_element(entity_element);
    }
    ///Constructeur simplifié
    GroupElementsUser(){
        group_interfaces_id.resize(3);
        map_global_nodes.resize(0);
        local_nodes.resize(DIM);
    }
    /// Ajout d'un entity_element au group
    bool add_entity_element(EntityElementUser &entity_element){
        bool entity_element_added = false;
        if(entity_element.valid_flags(flags, flags_names)){
            for(int i_connect=0; i_connect<global_connectivities.size(); i_connect++){
                global_connectivities[i_connect].push_back(entity_element.mesh_connectivity[i_connect]);
            }
            for(int i_connect=0; i_connect<connectivities.size(); i_connect++){
                connectivities[i_connect].push_back(entity_element.element_connectivity[i_connect]);
            }
            for(int i_side=0; i_side<entity_element.nb_sides; i_side++){
                interface_group_id[i_side].push_back(-1);
                interface_num_in_group[i_side].push_back(-1);
            }
            entity_element.group_id = id;
            entity_element.num_in_group = nb_elements;  
            nb_elements += 1;
            entity_element_added = true;
        }
        return entity_element_added;
    }
    
    void initialize_local_connectivities( BasicVec< BasicVec< TYPE > > &mesh_nodes ) {
        for(int i_connect=0; i_connect<local_connectivities.size(); i_connect++){
            local_connectivities[i_connect].resize(nb_elements,-1);
        }
        for(int d=0; d<DIM; d++){
            local_nodes[d].resize(0);            
        }
        for(int i_elem=0; i_elem<nb_elements; i_elem++){
            for(int i_connect=0; i_connect<global_connectivities.size(); i_connect++){
                int num_node = global_connectivities[i_connect][i_elem];
                bool add_node = true;
                for (int i_node=0; i_node<map_global_nodes.size(); i_node++){
                    if(num_node == map_global_nodes[i_node]){
                        local_connectivities[i_connect][i_elem] = i_node;
                        add_node = false;
                    }
                }
                if(add_node){
                    local_connectivities[i_connect][i_elem] = map_global_nodes.size();
                    map_global_nodes.push_back(num_node);
                    for(int d=0; d<DIM; d++){
                        local_nodes[d].push_back(mesh_nodes[d][num_node]);
                    }
                }
            }
        }
    }
    
    /// Définition des tailles des listes pour utilisation sous GPU
    void initialize_GPU(Patterns &patterns){
        int threadsPerBlock = 48;
        int n_group_blocks = std::ceil( nb_elements / threadsPerBlock );  // obtenir l'entier superieur
        nb_elements_for_GPU = (n_group_blocks + 1) * threadsPerBlock;
        
        for(int i_connect=0; i_connect<global_connectivities.size(); i_connect++){
            global_connectivities[i_connect].resize(nb_elements_for_GPU);
            local_connectivities[i_connect].resize(nb_elements_for_GPU);
        }
        for(int i_connect=0; i_connect<connectivities.size(); i_connect++){
            connectivities[i_connect].resize(nb_elements_for_GPU);
        }
        for(int i_side=0; i_side<interface_group_id.size(); i_side++){
            interface_group_id[i_side].resize(nb_elements_for_GPU);
            interface_num_in_group[i_side].resize(nb_elements_for_GPU);
        }
        //(nb_node_side,nb_node_eq_side,nb_side,num_motif) 
        int nb_sides = patterns.find_type(pattern_id).nb_sides;
        int nb_nodes_by_sides = patterns.find_type(pattern_id).nb_nodes_by_sides;
        int nb_nodes_eq_by_sides = patterns.find_type(pattern_id).nb_nodes_eq_by_sides;
        
        side_N.resize(nb_nodes_by_sides);
        for(int i_node=0; i_node < nb_nodes_by_sides; i_node++){
            side_N[i_node].resize(nb_nodes_eq_by_sides);
            for(int i_node_eq=0; i_node_eq < nb_nodes_eq_by_sides; i_node_eq++){
                side_N[i_node][i_node_eq].resize(nb_sides);
                for(int i_side=0; i_side < nb_sides; i_side++){
                    side_N[i_node][i_node_eq][i_side].resize(nb_elements_for_GPU,1);
                }
            }
        }
        
        side_M.resize(nb_nodes_eq_by_sides);
        for(int i_node_eq=0; i_node_eq < nb_nodes_eq_by_sides; i_node_eq++){
            side_M[i_node_eq].resize(nb_sides);
            for(int i_side=0; i_side < nb_sides; i_side++){
                side_M[i_node_eq][i_side].resize(nb_elements_for_GPU,1);
            }
        }        
        
    }
    /// Affichage pour vérification
    void affiche(){
        PRINT("group_elements-----------------------------------------------------------");
        PRINT(id);
        PRINT(pattern_id);
        PRINT(pattern_base_id);
        PRINT(nb_elements);

//         PRINT(map_global_nodes);
//         PRINT(local_nodes[0]);
//         PRINT(group_interfaces_id);
//         for(int i = 0; i < interface_group_id.size(); i++){
//             PRINT(interface_group_id[i]);
//             PRINT(interface_num_in_group[i]);
//         }
    }
};


#endif //GROUP_ELEMENTS_USER_H


