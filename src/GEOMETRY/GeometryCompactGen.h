// generated file
// 
#include <iostream>
#include <fstream>
#include <cassert> 
#include <Metil/BasicVec.h>
#include <Metil/StructCompactor.h>
#include <Metil/CudaMetil.h>
#include "GeometryCompactClass.h"
#include "GeometryCompactGen_N.h"
//#include "GeometryCompactGen_M.h"
#include "GeometryCompactGen_NeMe.h"
using namespace Metil;
// fonction permettant de calculer les opérateurs sur les sides des motifs en réalisant une boucle sur les groupes et en sélectionnant le type de pattern correspondant. Cette fonction appelle les sous-fonctions pour une exécution sous GPU.
void launch_calculate_side_N_M_GPU(Ps<GeometryCompactClass> geometry_compact_CPU, Ps<GeometryCompactClass> geometry_compact_GPU);
// fonction permettant de calculer les opérateurs sur les sides des motifs en réalisant une boucle sur les groupes et en sélectionnant le type de pattern correspondant. Cette fonction appelle les sous-fonctions pour une exécution sous CPU.        
void launch_calculate_side_N_M_CPU(Ps<GeometryCompactClass> geometry_compact_CPU);
// fonction permettant de calculer les opérateurs sur les groupes d'interface en réalisant une boucle sur les groupes et en sélectionnant le type de pattern correspondant. Cette fonction appelle les sous-fonctions pour une exécution sous CPU.        
void launch_calculate_interface_N_M_CPU(Ps<GeometryCompactClass> geometry_compact_CPU);
  

