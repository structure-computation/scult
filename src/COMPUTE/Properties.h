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
    BasicVec< Sc2String > mat_prop_name;
    // propriétés liaisons --------------------
    BasicVec< Sc2String > link_prop_name;
    // propriétés BC_step --------------------
    BasicVec< Sc2String > BC_step_prop_name; 
    // propriétés BC_step --------------------
    BasicVec< Sc2String > BCv_step_prop_name; 
    
    Properties(){

        mat_prop_name.resize(39);
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

        ///plasticite : f(s,p) = seq - R(p) - R0 avec R(p) = k_p * p ^ m_p et seq = von_mises(s)
        mat_prop_name[26] = "R0";           /// Limite d'elasticite
        mat_prop_name[27] = "k_p";          /// Coefficient multiplicateur de la loi d'ecrouissage
        mat_prop_name[28] = "m_p";          /// Coefficient multiplicateur de la loi d'ecrouissage
        mat_prop_name[29] = "coeff_plast_cinematique";     /// Coefficient de plasticité cinématique
        //endommagement et mesomodele
        mat_prop_name[30] = "Yo";       /// Seuil d'endommagement du matériau (de la matrice)
        mat_prop_name[31] = "Yc";       /// Seuil d'endommagement critique du matériau (de la matrice)
        mat_prop_name[32] = "Ycf";      /// Seuil d'endommagement critique des fibres
        mat_prop_name[33] = "dmax";     /// Endommagement maximal atteint
        mat_prop_name[34] = "b_c";      /// Couplage entre micro-fissuration et decohesion fibres/matrice
        mat_prop_name[35] = "effet_retard";     /// Booleen "effet retard active?"
        mat_prop_name[36] = "a";                /// Parametre de l'effet retard
        mat_prop_name[37] = "tau_c";            /// Parametre de l'effet retard
        mat_prop_name[38] = "couplage";         /// Coefficient de couplage pour le calcul de la contrainte equivalente
        
        
        link_prop_name.resize(8);
        link_prop_name[0] = "coef_frottement";      /// coefficient de frottement
        link_prop_name[1] = "Ep";                   /// epaisseur
        link_prop_name[2] = "jeux";                 /// jeux
        link_prop_name[3] = "R";                    /// raideur pour les liaisons elastiques  
        link_prop_name[4] = "Lp";                   /// pour la plasticité
        link_prop_name[5] = "Dp";
        link_prop_name[6] = "p";
        link_prop_name[7] = "Lr";
        
        
        BC_step_prop_name.resize(7);
        BC_step_prop_name[0] = "fct_spatiale_x";      
        BC_step_prop_name[1] = "fct_spatiale_y";                   
        BC_step_prop_name[2] = "fct_spatiale_z";                 
        BC_step_prop_name[3] = "fct_temporelle_x";            
        BC_step_prop_name[4] = "fct_temporelle_y";               
        BC_step_prop_name[5] = "fct_temporelle_z";
        BC_step_prop_name[6] = "normal_function";
        
        
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
