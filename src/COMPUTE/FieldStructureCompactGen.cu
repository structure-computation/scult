// generated file
// 
#include "FieldStructureCompactGen.h"

void launch_calculate_elements_center_GPU(Ps<GeometryCompactClass> geometry_compact_CPU, Ps<GeometryCompactClass> geometry_compact_GPU, Ps<FieldStructureCompactClass> field_structure_compact_GPU){
    for(int i_group=0; i_group < geometry_compact_CPU->group_elements.size(); i_group++){
        int threadsPerBlock = THREADSPERBLOCK;
        int sizeGrid = SIZEGRID;
        int nGrids = std::floor( geometry_compact_CPU->group_elements[i_group].connectivities[0].size()  / (sizeGrid*threadsPerBlock) ) + 1 ;  // obtenir l'entier superieur
        int lastGridSize = (geometry_compact_CPU->group_elements[i_group].connectivities[0].size() - (sizeGrid*threadsPerBlock)*(nGrids-1))/threadsPerBlock;
        switch (geometry_compact_CPU->group_elements[i_group].pattern_id){
            //for pattern PATTERN_Triangle
            case 0 :{
                for(int i_grid=0; i_grid < nGrids; i_grid++){
                    int blocksPerGrid;
                    if(i_grid == nGrids-1){
                        blocksPerGrid = lastGridSize;
                    }else{
                        blocksPerGrid = sizeGrid;
                    }
                    global_calculate_elements_center_0<<<blocksPerGrid,threadsPerBlock>>>(geometry_compact_GPU.ptr(), field_structure_compact_GPU.ptr(), i_group, i_grid, sizeGrid, geometry_compact_CPU->group_elements[i_group].nb_elements);
                }
                break;
            }
            //for pattern PATTERN_Triangle_6
            case 1 :{
                for(int i_grid=0; i_grid < nGrids; i_grid++){
                    int blocksPerGrid;
                    if(i_grid == nGrids-1){
                        blocksPerGrid = lastGridSize;
                    }else{
                        blocksPerGrid = sizeGrid;
                    }
                    global_calculate_elements_center_1<<<blocksPerGrid,threadsPerBlock>>>(geometry_compact_GPU.ptr(), field_structure_compact_GPU.ptr(), i_group, i_grid, sizeGrid, geometry_compact_CPU->group_elements[i_group].nb_elements);
                }
                break;
            }
            //for pattern PATTERN_Tetra
            case 2 :{
                for(int i_grid=0; i_grid < nGrids; i_grid++){
                    int blocksPerGrid;
                    if(i_grid == nGrids-1){
                        blocksPerGrid = lastGridSize;
                    }else{
                        blocksPerGrid = sizeGrid;
                    }
                    global_calculate_elements_center_2<<<blocksPerGrid,threadsPerBlock>>>(geometry_compact_GPU.ptr(), field_structure_compact_GPU.ptr(), i_group, i_grid, sizeGrid, geometry_compact_CPU->group_elements[i_group].nb_elements);
                }
                break;
            }
            //for pattern PATTERN_Tetra_10
            case 3 :{
                for(int i_grid=0; i_grid < nGrids; i_grid++){
                    int blocksPerGrid;
                    if(i_grid == nGrids-1){
                        blocksPerGrid = lastGridSize;
                    }else{
                        blocksPerGrid = sizeGrid;
                    }
                    global_calculate_elements_center_3<<<blocksPerGrid,threadsPerBlock>>>(geometry_compact_GPU.ptr(), field_structure_compact_GPU.ptr(), i_group, i_grid, sizeGrid, geometry_compact_CPU->group_elements[i_group].nb_elements);
                }
                break;
            }
            default :{
                std::cerr << "type de pattern non implemente" << std::endl; assert(0);                    
            }
        }
    }
}

void launch_calculate_elements_center_CPU(Ps<GeometryCompactClass> geometry_compact_CPU, Ps<FieldStructureCompactClass> field_structure_compact_CPU){
    for(int i_group=0; i_group < geometry_compact_CPU->group_elements.size(); i_group++){
        switch (geometry_compact_CPU->group_elements[i_group].pattern_id){
            //for pattern PATTERN_Triangle
            case 0 :{
                global_calculate_elements_center_0_CPU(geometry_compact_CPU.ptr(), field_structure_compact_CPU.ptr(), i_group);
                break;
            }
            //for pattern PATTERN_Triangle_6
            case 1 :{
                global_calculate_elements_center_1_CPU(geometry_compact_CPU.ptr(), field_structure_compact_CPU.ptr(), i_group);
                break;
            }
            //for pattern PATTERN_Tetra
            case 2 :{
                global_calculate_elements_center_2_CPU(geometry_compact_CPU.ptr(), field_structure_compact_CPU.ptr(), i_group);
                break;
            }
            //for pattern PATTERN_Tetra_10
            case 3 :{
                global_calculate_elements_center_3_CPU(geometry_compact_CPU.ptr(), field_structure_compact_CPU.ptr(), i_group);
                break;
            }
            default :{
                std::cerr << "type de pattern non implemente" << std::endl; assert(0);
            }
            
        }
    }
}

// void launch_calculate_elements_mat_elem_GPU(Ps<GeometryCompactClass> geometry_compact_CPU, Ps<GeometryCompactClass> geometry_compact_GPU, Ps<FieldStructureCompactClass> field_structure_compact_GPU){
//     for(int i_group=0; i_group < geometry_compact_CPU->group_elements.size(); i_group++){
//         int threadsPerBlock = THREADSPERBLOCK;
//         int sizeGrid = SIZEGRID;
//         int nGrids = std::floor( geometry_compact_CPU->group_elements[i_group].connectivities[0].size()  / (sizeGrid*threadsPerBlock) ) + 1 ;  // obtenir l'entier superieur
//         int lastGridSize = (geometry_compact_CPU->group_elements[i_group].connectivities[0].size() - (sizeGrid*threadsPerBlock)*(nGrids-1))/threadsPerBlock;
//         switch (geometry_compact_CPU->group_elements[i_group].pattern_id){
//             //for pattern PATTERN_Triangle
//             case 0 :{
//                 for(int i_grid=0; i_grid < nGrids; i_grid++){
//                     int blocksPerGrid;
//                     if(i_grid == nGrids-1){
//                         blocksPerGrid = lastGridSize;
//                     }else{
//                         blocksPerGrid = sizeGrid;
//                     }
//                     global_calculate_elements_mat_elem_0<<<blocksPerGrid,threadsPerBlock>>>(geometry_compact_GPU.ptr(), field_structure_compact_GPU.ptr(), i_group, i_grid, sizeGrid, geometry_compact_CPU->group_elements[i_group].nb_elements);
//                 }
//                 break;
//             }
//             //for pattern PATTERN_Triangle_6
//             case 1 :{
//                 for(int i_grid=0; i_grid < nGrids; i_grid++){
//                     int blocksPerGrid;
//                     if(i_grid == nGrids-1){
//                         blocksPerGrid = lastGridSize;
//                     }else{
//                         blocksPerGrid = sizeGrid;
//                     }
//                     global_calculate_elements_mat_elem_1<<<blocksPerGrid,threadsPerBlock>>>(geometry_compact_GPU.ptr(), field_structure_compact_GPU.ptr(), i_group, i_grid, sizeGrid, geometry_compact_CPU->group_elements[i_group].nb_elements);
//                 }
//                 break;
//             }
//             //for pattern PATTERN_Tetra
//             case 2 :{
//                 for(int i_grid=0; i_grid < nGrids; i_grid++){
//                     int blocksPerGrid;
//                     if(i_grid == nGrids-1){
//                         blocksPerGrid = lastGridSize;
//                     }else{
//                         blocksPerGrid = sizeGrid;
//                     }
//                     global_calculate_elements_mat_elem_2<<<blocksPerGrid,threadsPerBlock>>>(geometry_compact_GPU.ptr(), field_structure_compact_GPU.ptr(), i_group, i_grid, sizeGrid, geometry_compact_CPU->group_elements[i_group].nb_elements);
//                 }
//                 break;
//             }
//             //for pattern PATTERN_Tetra_10
//             case 3 :{
//                 for(int i_grid=0; i_grid < nGrids; i_grid++){
//                     int blocksPerGrid;
//                     if(i_grid == nGrids-1){
//                         blocksPerGrid = lastGridSize;
//                     }else{
//                         blocksPerGrid = sizeGrid;
//                     }
//                     global_calculate_elements_mat_elem_3<<<blocksPerGrid,threadsPerBlock>>>(geometry_compact_GPU.ptr(), field_structure_compact_GPU.ptr(), i_group, i_grid, sizeGrid, geometry_compact_CPU->group_elements[i_group].nb_elements);
//                 }
//                 break;
//             }
//             default :{
//                 std::cerr << "type de pattern non implemente" << std::endl; assert(0);                    
//             }
//         }
//     }
// }
// 
// void launch_calculate_elements_mat_elem_CPU(Ps<GeometryCompactClass> geometry_compact_CPU, Ps<FieldStructureCompactClass> field_structure_compact_CPU){
//     for(int i_group=0; i_group < geometry_compact_CPU->group_elements.size(); i_group++){
//         switch (geometry_compact_CPU->group_elements[i_group].pattern_id){
//             //for pattern PATTERN_Triangle
//             case 0 :{
//                 global_calculate_elements_mat_elem_0_CPU(geometry_compact_CPU.ptr(), field_structure_compact_CPU.ptr(), i_group);
//                 break;
//             }
//             //for pattern PATTERN_Triangle_6
//             case 1 :{
//                 global_calculate_elements_mat_elem_1_CPU(geometry_compact_CPU.ptr(), field_structure_compact_CPU.ptr(), i_group);
//                 break;
//             }
//             //for pattern PATTERN_Tetra
//             case 2 :{
//                 global_calculate_elements_mat_elem_2_CPU(geometry_compact_CPU.ptr(), field_structure_compact_CPU.ptr(), i_group);
//                 break;
//             }
//             //for pattern PATTERN_Tetra_10
//             case 3 :{
//                 global_calculate_elements_mat_elem_3_CPU(geometry_compact_CPU.ptr(), field_structure_compact_CPU.ptr(), i_group);
//                 break;
//             }
//             default :{
//                 std::cerr << "type de pattern non implemente" << std::endl; assert(0);
//             }
//             
//         }
//     }
// }
// 
