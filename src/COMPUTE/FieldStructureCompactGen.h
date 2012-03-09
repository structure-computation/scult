// generated file
// 
#include <iostream>
#include <fstream>
#include <cassert> 
#include <Metil/BasicVec.h>
#include <Metil/StructCompactor.h>
#include <Metil/CudaMetil.h>
#include "GeometryCompactClass.h"
#include "FieldStructureCompactClass.h"
#include "FieldStructureCompactGen_center.h"
/*#include "FieldStructureCompactGen_elements_mat_elem.h"*/
using namespace Metil;
// fonction permettant de calculer les centre des elements sur GPU
void launch_calculate_elements_center_GPU(Ps<GeometryCompactClass> geometry_compact_CPU, Ps<GeometryCompactClass> geometry_compact_GPU, Ps<FieldStructureCompactClass> field_structure_compact_GPU);
void launch_calculate_elements_center_CPU(Ps<GeometryCompactClass> geometry_compact_CPU, Ps<FieldStructureCompactClass> field_structure_compact_CPU);
// fonction permettant de calculer les matrices elementaires sur GPU
void launch_calculate_elements_mat_elem_GPU(Ps<GeometryCompactClass> geometry_compact_CPU, Ps<GeometryCompactClass> geometry_compact_GPU, Ps<FieldStructureCompactClass> field_structure_compact_GPU);
void launch_calculate_elements_mat_elem_CPU(Ps<GeometryCompactClass> geometry_compact_CPU, Ps<FieldStructureCompactClass> field_structure_compact_CPU);
  

