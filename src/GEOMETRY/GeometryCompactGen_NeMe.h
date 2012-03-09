// generated file
// 
#include <iostream>
#include <fstream>
#include <cassert> 
#include <Metil/BasicVec.h>
#include <Metil/StructCompactor.h>
#include <Metil/CudaMetil.h>
#include "GeometryCompactClass.h"
using namespace Metil;
/// Fonctions inline (travaillant sur un motif) et global (travaillant sur une liste de motif sur GPU) permettant de calculer l'opérateur side_M sur chaque côté d'un motif. Cet opérateur permet de faire le lien entre les données sur les côtés et les données sur les interfaces

//for pattern Bar
__inline__ void calculate_interface_NeMe_0(GeometryCompactClass *geometry_compact, int i_group, int i_elem);
__global__ void global_calculate_interface_NeMe_0(GeometryCompactClass *geometry_compact_GPU, int i_group, int i_block, int sizeBlock, int nb_elements);
void global_calculate_interface_NeMe_0_CPU(GeometryCompactClass *geometry_compact_CPU, int i_group);

//for pattern Bar_3
__inline__ void calculate_interface_NeMe_1(GeometryCompactClass *geometry_compact, int i_group, int i_elem);
__global__ void global_calculate_interface_NeMe_1(GeometryCompactClass *geometry_compact_GPU, int i_group, int i_block, int sizeBlock, int nb_elements);
void global_calculate_interface_NeMe_1_CPU(GeometryCompactClass *geometry_compact_CPU, int i_group);

//for pattern Triangle
__inline__ void calculate_interface_NeMe_2(GeometryCompactClass *geometry_compact, int i_group, int i_elem);
__global__ void global_calculate_interface_NeMe_2(GeometryCompactClass *geometry_compact_GPU, int i_group, int i_block, int sizeBlock, int nb_elements);
void global_calculate_interface_NeMe_2_CPU(GeometryCompactClass *geometry_compact_CPU, int i_group);

//for pattern Triangle_6
__inline__ void calculate_interface_NeMe_3(GeometryCompactClass *geometry_compact, int i_group, int i_elem);
__global__ void global_calculate_interface_NeMe_3(GeometryCompactClass *geometry_compact_GPU, int i_group, int i_block, int sizeBlock, int nb_elements);
void global_calculate_interface_NeMe_3_CPU(GeometryCompactClass *geometry_compact_CPU, int i_group);

