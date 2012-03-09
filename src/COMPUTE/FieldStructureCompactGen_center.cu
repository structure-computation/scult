// generated file
// 
#include "FieldStructureCompactGen_center.h"

__inline__ void calculate_elements_center0(GeometryCompactClass *geometry_compact, FieldStructureCompactClass *field_structure_compact ,int i_group, int i_elem){  
        double R0 = 0.3333333333333333; double R1 = geometry_compact->nodes[0][geometry_compact->group_elements[i_group].connectivities[0][i_elem]]; double R2 = geometry_compact->nodes[0][geometry_compact->group_elements[i_group].connectivities[1][i_elem]]; double R3 = geometry_compact->nodes[0][geometry_compact->group_elements[i_group].connectivities[2][i_elem]]; double R4 = R1+R2+R3; double R5 = R0*R4; 
    field_structure_compact->group_elements[i_group].pt[0][i_elem] = R5; double R6 = geometry_compact->nodes[1][geometry_compact->group_elements[i_group].connectivities[2][i_elem]]; double R7 = geometry_compact->nodes[1][geometry_compact->group_elements[i_group].connectivities[1][i_elem]]; double R8 = geometry_compact->nodes[1][geometry_compact->group_elements[i_group].connectivities[0][i_elem]]; double R9 = R6+R7+R8; double R10 = R0*R9; 
    field_structure_compact->group_elements[i_group].pt[1][i_elem] = R10;  /* 6 instructions */
}

__global__ void global_calculate_elements_center_0(GeometryCompactClass *geometry_compact_GPU, FieldStructureCompactClass *field_structure_compact_GPU, int i_group, int i_grid, int sizeGrid, int nb_elements){
    int i_elem = i_grid * sizeGrid * blockDim.x + blockIdx.x * blockDim.x + threadIdx.x;
    if(i_elem <nb_elements){
        calculate_elements_center0(geometry_compact_GPU, field_structure_compact_GPU, i_group, i_elem);
    }
}

void global_calculate_elements_center_0_CPU(GeometryCompactClass *geometry_compact_CPU, FieldStructureCompactClass *field_structure_compact_CPU, int i_group){
    for(int i_elem=0; i_elem<geometry_compact_CPU->group_elements[i_group].nb_elements ; i_elem++)
        calculate_elements_center0(geometry_compact_CPU, field_structure_compact_CPU, i_group, i_elem);
}

__inline__ void calculate_elements_center1(GeometryCompactClass *geometry_compact, FieldStructureCompactClass *field_structure_compact ,int i_group, int i_elem){  
        double R0 = 0.4444444444444444; double R1 = geometry_compact->nodes[0][geometry_compact->group_elements[i_group].connectivities[5][i_elem]]; double R2 = geometry_compact->nodes[0][geometry_compact->group_elements[i_group].connectivities[3][i_elem]]; double R3 = geometry_compact->nodes[0][geometry_compact->group_elements[i_group].connectivities[4][i_elem]]; double R4 = R1+R2+R3; double R5 = R0*R4; 
    double R6 = -0.1111111111111111; double R7 = geometry_compact->nodes[0][geometry_compact->group_elements[i_group].connectivities[1][i_elem]]; double R8 = geometry_compact->nodes[0][geometry_compact->group_elements[i_group].connectivities[0][i_elem]]; double R9 = geometry_compact->nodes[0][geometry_compact->group_elements[i_group].connectivities[2][i_elem]]; double R10 = R7+R8+R9; double R11 = R6*R10; 
    double R12 = R5+R11; field_structure_compact->group_elements[i_group].pt[0][i_elem] = R12; double R13 = geometry_compact->nodes[1][geometry_compact->group_elements[i_group].connectivities[5][i_elem]]; double R14 = geometry_compact->nodes[1][geometry_compact->group_elements[i_group].connectivities[4][i_elem]]; double R15 = geometry_compact->nodes[1][geometry_compact->group_elements[i_group].connectivities[3][i_elem]]; double R16 = R13+R14+R15; 
    double R17 = R0*R16; double R18 = geometry_compact->nodes[1][geometry_compact->group_elements[i_group].connectivities[2][i_elem]]; double R19 = geometry_compact->nodes[1][geometry_compact->group_elements[i_group].connectivities[1][i_elem]]; double R20 = geometry_compact->nodes[1][geometry_compact->group_elements[i_group].connectivities[0][i_elem]]; double R21 = R18+R19+R20; double R22 = R6*R21; 
    double R23 = R17+R22; field_structure_compact->group_elements[i_group].pt[1][i_elem] = R23;  /* 14 instructions */
}

__global__ void global_calculate_elements_center_1(GeometryCompactClass *geometry_compact_GPU, FieldStructureCompactClass *field_structure_compact_GPU, int i_group, int i_grid, int sizeGrid, int nb_elements){
    int i_elem = i_grid * sizeGrid * blockDim.x + blockIdx.x * blockDim.x + threadIdx.x;
    if(i_elem <nb_elements){
        calculate_elements_center1(geometry_compact_GPU, field_structure_compact_GPU, i_group, i_elem);
    }
}

void global_calculate_elements_center_1_CPU(GeometryCompactClass *geometry_compact_CPU, FieldStructureCompactClass *field_structure_compact_CPU, int i_group){
    for(int i_elem=0; i_elem<geometry_compact_CPU->group_elements[i_group].nb_elements ; i_elem++)
        calculate_elements_center1(geometry_compact_CPU, field_structure_compact_CPU, i_group, i_elem);
}

__inline__ void calculate_elements_center2(GeometryCompactClass *geometry_compact, FieldStructureCompactClass *field_structure_compact ,int i_group, int i_elem){  
        double R0 = 0.25; double R1 = geometry_compact->nodes[0][geometry_compact->group_elements[i_group].connectivities[0][i_elem]]; double R2 = geometry_compact->nodes[0][geometry_compact->group_elements[i_group].connectivities[2][i_elem]]; double R3 = geometry_compact->nodes[0][geometry_compact->group_elements[i_group].connectivities[1][i_elem]]; double R4 = geometry_compact->nodes[0][geometry_compact->group_elements[i_group].connectivities[3][i_elem]]; double R5 = R1+R2+R3+R4; 
    double R6 = R0*R5; field_structure_compact->group_elements[i_group].pt[0][i_elem] = R6; double R7 = geometry_compact->nodes[1][geometry_compact->group_elements[i_group].connectivities[3][i_elem]]; double R8 = geometry_compact->nodes[1][geometry_compact->group_elements[i_group].connectivities[0][i_elem]]; double R9 = geometry_compact->nodes[1][geometry_compact->group_elements[i_group].connectivities[1][i_elem]]; double R10 = geometry_compact->nodes[1][geometry_compact->group_elements[i_group].connectivities[2][i_elem]]; 
    double R11 = R7+R8+R9+R10; double R12 = R0*R11; field_structure_compact->group_elements[i_group].pt[1][i_elem] = R12; double R13 = geometry_compact->nodes[2][geometry_compact->group_elements[i_group].connectivities[3][i_elem]]; double R14 = geometry_compact->nodes[2][geometry_compact->group_elements[i_group].connectivities[0][i_elem]]; double R15 = geometry_compact->nodes[2][geometry_compact->group_elements[i_group].connectivities[1][i_elem]]; 
    double R16 = geometry_compact->nodes[2][geometry_compact->group_elements[i_group].connectivities[2][i_elem]]; double R17 = R13+R14+R15+R16; double R18 = R0*R17; field_structure_compact->group_elements[i_group].pt[2][i_elem] = R18;  /* 12 instructions */
}

__global__ void global_calculate_elements_center_2(GeometryCompactClass *geometry_compact_GPU, FieldStructureCompactClass *field_structure_compact_GPU, int i_group, int i_grid, int sizeGrid, int nb_elements){
    int i_elem = i_grid * sizeGrid * blockDim.x + blockIdx.x * blockDim.x + threadIdx.x;
    if(i_elem <nb_elements){
        calculate_elements_center2(geometry_compact_GPU, field_structure_compact_GPU, i_group, i_elem);
    }
}

void global_calculate_elements_center_2_CPU(GeometryCompactClass *geometry_compact_CPU, FieldStructureCompactClass *field_structure_compact_CPU, int i_group){
    for(int i_elem=0; i_elem<geometry_compact_CPU->group_elements[i_group].nb_elements ; i_elem++)
        calculate_elements_center2(geometry_compact_CPU, field_structure_compact_CPU, i_group, i_elem);
}

__inline__ void calculate_elements_center3(GeometryCompactClass *geometry_compact, FieldStructureCompactClass *field_structure_compact ,int i_group, int i_elem){  
        double R0 = -0.125; double R1 = geometry_compact->nodes[0][geometry_compact->group_elements[i_group].connectivities[3][i_elem]]; double R2 = geometry_compact->nodes[0][geometry_compact->group_elements[i_group].connectivities[0][i_elem]]; double R3 = geometry_compact->nodes[0][geometry_compact->group_elements[i_group].connectivities[1][i_elem]]; double R4 = geometry_compact->nodes[0][geometry_compact->group_elements[i_group].connectivities[2][i_elem]]; double R5 = R1+R2+R3+R4; 
    double R6 = R0*R5; double R7 = 0.25; double R8 = geometry_compact->nodes[0][geometry_compact->group_elements[i_group].connectivities[4][i_elem]]; double R9 = geometry_compact->nodes[0][geometry_compact->group_elements[i_group].connectivities[9][i_elem]]; double R10 = geometry_compact->nodes[0][geometry_compact->group_elements[i_group].connectivities[8][i_elem]]; double R11 = geometry_compact->nodes[0][geometry_compact->group_elements[i_group].connectivities[7][i_elem]]; 
    double R12 = geometry_compact->nodes[0][geometry_compact->group_elements[i_group].connectivities[5][i_elem]]; double R13 = geometry_compact->nodes[0][geometry_compact->group_elements[i_group].connectivities[6][i_elem]]; double R14 = R8+R9+R10+R11+R12+R13; double R15 = R7*R14; double R16 = R6+R15; field_structure_compact->group_elements[i_group].pt[0][i_elem] = R16; 
    double R17 = geometry_compact->nodes[1][geometry_compact->group_elements[i_group].connectivities[3][i_elem]]; double R18 = geometry_compact->nodes[1][geometry_compact->group_elements[i_group].connectivities[0][i_elem]]; double R19 = geometry_compact->nodes[1][geometry_compact->group_elements[i_group].connectivities[2][i_elem]]; double R20 = geometry_compact->nodes[1][geometry_compact->group_elements[i_group].connectivities[1][i_elem]]; double R21 = R17+R18+R19+R20; double R22 = R0*R21; 
    double R23 = geometry_compact->nodes[1][geometry_compact->group_elements[i_group].connectivities[9][i_elem]]; double R24 = geometry_compact->nodes[1][geometry_compact->group_elements[i_group].connectivities[8][i_elem]]; double R25 = geometry_compact->nodes[1][geometry_compact->group_elements[i_group].connectivities[7][i_elem]]; double R26 = geometry_compact->nodes[1][geometry_compact->group_elements[i_group].connectivities[6][i_elem]]; double R27 = geometry_compact->nodes[1][geometry_compact->group_elements[i_group].connectivities[4][i_elem]]; double R28 = geometry_compact->nodes[1][geometry_compact->group_elements[i_group].connectivities[5][i_elem]]; 
    double R29 = R23+R24+R25+R26+R27+R28; double R30 = R7*R29; double R31 = R22+R30; field_structure_compact->group_elements[i_group].pt[1][i_elem] = R31; double R32 = geometry_compact->nodes[2][geometry_compact->group_elements[i_group].connectivities[3][i_elem]]; double R33 = geometry_compact->nodes[2][geometry_compact->group_elements[i_group].connectivities[2][i_elem]]; 
    double R34 = geometry_compact->nodes[2][geometry_compact->group_elements[i_group].connectivities[1][i_elem]]; double R35 = geometry_compact->nodes[2][geometry_compact->group_elements[i_group].connectivities[0][i_elem]]; double R36 = R32+R33+R34+R35; double R37 = R0*R36; double R38 = geometry_compact->nodes[2][geometry_compact->group_elements[i_group].connectivities[9][i_elem]]; double R39 = geometry_compact->nodes[2][geometry_compact->group_elements[i_group].connectivities[8][i_elem]]; 
    double R40 = geometry_compact->nodes[2][geometry_compact->group_elements[i_group].connectivities[7][i_elem]]; double R41 = geometry_compact->nodes[2][geometry_compact->group_elements[i_group].connectivities[6][i_elem]]; double R42 = geometry_compact->nodes[2][geometry_compact->group_elements[i_group].connectivities[4][i_elem]]; double R43 = geometry_compact->nodes[2][geometry_compact->group_elements[i_group].connectivities[5][i_elem]]; double R44 = R38+R39+R40+R41+R42+R43; double R45 = R7*R44; 
    double R46 = R37+R45; field_structure_compact->group_elements[i_group].pt[2][i_elem] = R46;  /* 33 instructions */
}

__global__ void global_calculate_elements_center_3(GeometryCompactClass *geometry_compact_GPU, FieldStructureCompactClass *field_structure_compact_GPU, int i_group, int i_grid, int sizeGrid, int nb_elements){
    int i_elem = i_grid * sizeGrid * blockDim.x + blockIdx.x * blockDim.x + threadIdx.x;
    if(i_elem <nb_elements){
        calculate_elements_center3(geometry_compact_GPU, field_structure_compact_GPU, i_group, i_elem);
    }
}

void global_calculate_elements_center_3_CPU(GeometryCompactClass *geometry_compact_CPU, FieldStructureCompactClass *field_structure_compact_CPU, int i_group){
    for(int i_elem=0; i_elem<geometry_compact_CPU->group_elements[i_group].nb_elements ; i_elem++)
        calculate_elements_center3(geometry_compact_CPU, field_structure_compact_CPU, i_group, i_elem);
}

