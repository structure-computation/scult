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
using namespace Metil;
/// Fonctions inline (travaillant sur un motif) et global (travaillant sur une liste de motif sur GPU) permettant de calculer les matrices élémentaires d'un element dans les group_elements

//for pattern PATTERN_Triangle
__inline__ void calculate_elements_mat_elem_0(GeometryCompactClass *geometry_compact, FieldStructureCompactClass *field_structure_compact ,int i_group, int i_elem);
__global__ void global_calculate_elements_mat_elem_0(GeometryCompactClass *geometry_compact_GPU, FieldStructureCompactClass *field_structure_compact_GPU, int i_group, int i_grid, int sizeGrid, int nb_elements);
void global_calculate_elements_mat_elem_0_CPU(GeometryCompactClass *geometry_compact_CPU, FieldStructureCompactClass *field_structure_compact_CPU, int i_group);

//for pattern PATTERN_Triangle_6
__inline__ void calculate_elements_mat_elem_1(GeometryCompactClass *geometry_compact, FieldStructureCompactClass *field_structure_compact ,int i_group, int i_elem);
__global__ void global_calculate_elements_mat_elem_1(GeometryCompactClass *geometry_compact_GPU, FieldStructureCompactClass *field_structure_compact_GPU, int i_group, int i_grid, int sizeGrid, int nb_elements);
void global_calculate_elements_mat_elem_1_CPU(GeometryCompactClass *geometry_compact_CPU, FieldStructureCompactClass *field_structure_compact_CPU, int i_group);

//for pattern PATTERN_Tetra
__inline__ void calculate_elements_mat_elem_2(GeometryCompactClass *geometry_compact, FieldStructureCompactClass *field_structure_compact ,int i_group, int i_elem);
__global__ void global_calculate_elements_mat_elem_2(GeometryCompactClass *geometry_compact_GPU, FieldStructureCompactClass *field_structure_compact_GPU, int i_group, int i_grid, int sizeGrid, int nb_elements);
void global_calculate_elements_mat_elem_2_CPU(GeometryCompactClass *geometry_compact_CPU, FieldStructureCompactClass *field_structure_compact_CPU, int i_group);

//for pattern PATTERN_Tetra_10
__inline__ void calculate_elements_mat_elem_3(GeometryCompactClass *geometry_compact, FieldStructureCompactClass *field_structure_compact ,int i_group, int i_elem);
__global__ void global_calculate_elements_mat_elem_3(GeometryCompactClass *geometry_compact_GPU, FieldStructureCompactClass *field_structure_compact_GPU, int i_group, int i_grid, int sizeGrid, int nb_elements);
void global_calculate_elements_mat_elem_3_CPU(GeometryCompactClass *geometry_compact_CPU, FieldStructureCompactClass *field_structure_compact_CPU, int i_group);

