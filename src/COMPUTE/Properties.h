//
// C++ Interface: Properties
//
// Description: définition globale des propriété matériau, link, edge...
//
//
// Author: Jeremie Bellec <j.bellec@structure-computation.com>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <Metil/BasicVec.h>

using namespace Metil;

class Properties{
    
public:
    // propriétés materiaux --------------------
    BasicVec< std::string > mat_prop_name;
    // propriétés liaisons --------------------
    BasicVec< std::string > link_prop_name;
    // propriétés BC_step --------------------
    BasicVec< std::string > BC_step_prop_name; 
    // propriétés BC_step --------------------
    BasicVec< std::string > BCv_step_prop_name; 
    
    Properties(){
        mat_prop_name.resize(36);
        mat_prop_name[0] =  "elastic_modulus";
        mat_prop_name[1] =  "poisson_ratio";
        mat_prop_name[2] =  "alpha";
        mat_prop_name[3] =  "rho";
        mat_prop_name[4] =  "viscosite";
        mat_prop_name[5] =  "dir_1_x";
        mat_prop_name[6] =  "dir_1_y";
        mat_prop_name[7] =  "dir_1_z";
        mat_prop_name[8] =  "dir_2_x";
        mat_prop_name[9] =  "dir_2_y";
        mat_prop_name[10] = "dir_2_z";
        mat_prop_name[11] = "dir_3_x"; 
        mat_prop_name[12] = "dir_3_y";          
        mat_prop_name[13] = "dir_3_z";
        mat_prop_name[14] = "E1";
        mat_prop_name[15] = "E2";
        mat_prop_name[16] = "E3";
        mat_prop_name[17] = "G12";
        mat_prop_name[18] = "G23";
        mat_prop_name[19] = "G13";
        mat_prop_name[20] = "nu12";
        mat_prop_name[21] = "nu23";
        mat_prop_name[22] = "nu13";
        mat_prop_name[23] = "alpha_1";
        mat_prop_name[24] = "alpha_2";
        mat_prop_name[25] = "alpha_3";
        //endomagement
        mat_prop_name[26] = "Yo"; 
        mat_prop_name[27] = "Ysp";
        mat_prop_name[28] = "Yop";
        mat_prop_name[29] = "Yc";
        mat_prop_name[30] = "Ycp";
        mat_prop_name[31] = "b";
        //plasticite kp, mp, R0 et c
        mat_prop_name[32] = "kp";
        mat_prop_name[33] = "mp";
        mat_prop_name[34] = "R0";
        mat_prop_name[35] = "c";
        
        
        link_prop_name.resize(8);
        link_prop_name[0] = "coef_frottement";      // coefficient de frottement
        link_prop_name[1] = "Ep";                   // epaisseur
        link_prop_name[2] = "jeux";                 // jeux
        link_prop_name[3] = "R";                    // raideur pour les liaisons elastiques  
        link_prop_name[4] = "Lp";                   // pour la plasticité
        link_prop_name[5] = "Dp";
        link_prop_name[6] = "p";
        link_prop_name[7] = "Lr";
        
        
        BC_step_prop_name.resize(6);
        BC_step_prop_name[0] = "fct_spatiale_x";      
        BC_step_prop_name[1] = "fct_spatiale_y";                   
        BC_step_prop_name[2] = "fct_spatiale_z";                 
        BC_step_prop_name[3] = "fct_temporelle_x";            
        BC_step_prop_name[4] = "fct_temporelle_y";               
        BC_step_prop_name[5] = "fct_temporelle_z";
        
        
        BCv_step_prop_name.resize(8);
        BCv_step_prop_name[0] = "pdirection_x";      
        BCv_step_prop_name[1] = "pdirection_y";                   
        BCv_step_prop_name[2] = "pdirection_z";                 
        BCv_step_prop_name[3] = "point_1_x";            
        BCv_step_prop_name[4] = "point_1_y";               
        BCv_step_prop_name[5] = "point_1_z";
        BCv_step_prop_name[6] = "gravity";
        BCv_step_prop_name[7] = "wrotation";   
    };
  
};

#endif // PROPERTIES_H