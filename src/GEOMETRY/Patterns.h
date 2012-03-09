//
// Description: fichier généré par GEOM_Patterns.met 
//
//
// Author: Jeremie Bellec <j.bellec@structure-computation.com>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef PATTERNS_H
#define PATTERNS_H

#include <Metil/BasicVec.h>

using namespace Metil;

struct Patterns{
    //atributs **********************************************************************************************
    struct Types{
        std::string name, base_xdmf, base_skin_xdmf ;
        int id ;
        int dim ;
        int nb_nodes ;
        int interface_id ;
        int nb_sides ;
        int nb_nodes_by_sides ; 
        int nb_nodes_eq_by_sides ; 
        BasicVec< int > permutation;
        BasicVec< BasicVec< int > > sides;
        
        template<class TB,class TP>
        void apply_bs( TB &res, TP ) const {
            res.set_type( "Types" );
            APPLY_WN( res, id );
            APPLY_WN( res, dim );
            APPLY_WN( res, nb_nodes );
            APPLY_WN( res, interface_id );
            APPLY_WN( res, nb_sides );
            APPLY_WN( res, nb_nodes_by_sides );
            APPLY_WN( res, nb_nodes_eq_by_sides );
            APPLY_WN( res, permutation );
            APPLY_WN( res, sides );
        }
    };
    BasicVec< Types > types;
    
    
    //méthodes **********************************************************************************************
    Types find_type(int id_){
        for(int num_type=0; num_type<4; num_type++){
            if(types[num_type].id == id_){
                return types[num_type];
                break;
            }
        }
    }
    
    int find_index_type(int id_){
        for(int num_type=0; num_type<4; num_type++){
            if(types[num_type].id == id_){
                return num_type ;
                break;
            }
        }
    }
    
    template<class TB,class TP>
    void apply_bs( TB &res, TP ) const {
        res.set_type( "Patterns" );
        APPLY_WN( res, types );
    }
          
    Patterns(){
        types.resize(4);

        //
        // type 0 = PATTERN_Triangle --------------------------------------
        types[0].name = "PATTERN_Triangle";
        types[0].base_xdmf = "Triangle";
        types[0].base_skin_xdmf = "Polygon";
        types[0].id = 0;
        types[0].dim = 2;
        types[0].nb_nodes = 3;
        types[0].interface_id = 0; 
        types[0].nb_sides = 3;
        types[0].nb_nodes_by_sides = 2;
        types[0].nb_nodes_eq_by_sides = 1;
        types[0].permutation.resize(types[0].nb_nodes);
        types[0].sides.resize(types[0].nb_sides);
        for(int i_side=0; i_side<types[0].nb_sides; i_side++){
            types[0].sides[i_side].resize(types[0].nb_nodes_by_sides);
        }

        types[0].permutation[0] = 0;
        types[0].permutation[1] = 2;
        types[0].permutation[2] = 1;
        types[0].sides[0][0] = 0;
        types[0].sides[0][1] = 1;
        types[0].sides[1][0] = 1;
        types[0].sides[1][1] = 2;
        types[0].sides[2][0] = 2;
        types[0].sides[2][1] = 0;
        //
        // type 1 = PATTERN_Triangle_6 --------------------------------------
        types[1].name = "PATTERN_Triangle_6";
        types[1].base_xdmf = "Tri_6";
        types[1].base_skin_xdmf = "Edge_3";
        types[1].id = 1;
        types[1].dim = 2;
        types[1].nb_nodes = 6;
        types[1].interface_id = 1; 
        types[1].nb_sides = 3;
        types[1].nb_nodes_by_sides = 3;
        types[1].nb_nodes_eq_by_sides = 2;
        types[1].permutation.resize(types[1].nb_nodes);
        types[1].sides.resize(types[1].nb_sides);
        for(int i_side=0; i_side<types[1].nb_sides; i_side++){
            types[1].sides[i_side].resize(types[1].nb_nodes_by_sides);
        }

        types[1].permutation[0] = 0;
        types[1].permutation[1] = 2;
        types[1].permutation[2] = 1;
        types[1].permutation[3] = 5;
        types[1].permutation[4] = 4;
        types[1].permutation[5] = 3;
        types[1].sides[0][0] = 0;
        types[1].sides[0][1] = 1;
        types[1].sides[0][2] = 3;
        types[1].sides[1][0] = 1;
        types[1].sides[1][1] = 2;
        types[1].sides[1][2] = 4;
        types[1].sides[2][0] = 2;
        types[1].sides[2][1] = 0;
        types[1].sides[2][2] = 5;
        //
        // type 2 = PATTERN_Tetra --------------------------------------
        types[2].name = "PATTERN_Tetra";
        types[2].base_xdmf = "Tetrahedron";
        types[2].base_skin_xdmf = "Triangle";
        types[2].id = 2;
        types[2].dim = 3;
        types[2].nb_nodes = 4;
        types[2].interface_id = 2; 
        types[2].nb_sides = 4;
        types[2].nb_nodes_by_sides = 3;
        types[2].nb_nodes_eq_by_sides = 4;
        types[2].permutation.resize(types[2].nb_nodes);
        types[2].sides.resize(types[2].nb_sides);
        for(int i_side=0; i_side<types[2].nb_sides; i_side++){
            types[2].sides[i_side].resize(types[2].nb_nodes_by_sides);
        }

        types[2].permutation[0] = 0;
        types[2].permutation[1] = 2;
        types[2].permutation[2] = 1;
        types[2].permutation[3] = 3;
        types[2].sides[0][0] = 0;
        types[2].sides[0][1] = 2;
        types[2].sides[0][2] = 1;
        types[2].sides[1][0] = 0;
        types[2].sides[1][1] = 1;
        types[2].sides[1][2] = 3;
        types[2].sides[2][0] = 0;
        types[2].sides[2][1] = 3;
        types[2].sides[2][2] = 2;
        types[2].sides[3][0] = 1;
        types[2].sides[3][1] = 2;
        types[2].sides[3][2] = 3;
        //
        // type 3 = PATTERN_Tetra_10 --------------------------------------
        types[3].name = "PATTERN_Tetra_10";
        types[3].base_xdmf = "Tet_10";
        types[3].base_skin_xdmf = "Tri_6";
        types[3].id = 3;
        types[3].dim = 3;
        types[3].nb_nodes = 10;
        types[3].interface_id = 3; 
        types[3].nb_sides = 4;
        types[3].nb_nodes_by_sides = 6;
        types[3].nb_nodes_eq_by_sides = 4;
        types[3].permutation.resize(types[3].nb_nodes);
        types[3].sides.resize(types[3].nb_sides);
        for(int i_side=0; i_side<types[3].nb_sides; i_side++){
            types[3].sides[i_side].resize(types[3].nb_nodes_by_sides);
        }

        types[3].permutation[0] = 0;
        types[3].permutation[1] = 2;
        types[3].permutation[2] = 1;
        types[3].permutation[3] = 3;
        types[3].permutation[4] = 6;
        types[3].permutation[5] = 5;
        types[3].permutation[6] = 4;
        types[3].permutation[7] = 7;
        types[3].permutation[8] = 9;
        types[3].permutation[9] = 8;
        types[3].sides[0][0] = 0;
        types[3].sides[0][1] = 2;
        types[3].sides[0][2] = 1;
        types[3].sides[0][3] = 6;
        types[3].sides[0][4] = 5;
        types[3].sides[0][5] = 4;
        types[3].sides[1][0] = 0;
        types[3].sides[1][1] = 1;
        types[3].sides[1][2] = 3;
        types[3].sides[1][3] = 4;
        types[3].sides[1][4] = 8;
        types[3].sides[1][5] = 7;
        types[3].sides[2][0] = 0;
        types[3].sides[2][1] = 3;
        types[3].sides[2][2] = 2;
        types[3].sides[2][3] = 7;
        types[3].sides[2][4] = 9;
        types[3].sides[2][5] = 6;
        types[3].sides[3][0] = 1;
        types[3].sides[3][1] = 2;
        types[3].sides[3][2] = 3;
        types[3].sides[3][3] = 5;
        types[3].sides[3][4] = 9;
        types[3].sides[3][5] = 8;
    }
};
#endif //PATTERNS_H
