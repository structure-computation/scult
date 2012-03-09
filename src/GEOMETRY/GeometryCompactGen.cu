// generated file
// 
#include "GeometryCompactGen.h"

void launch_calculate_side_N_M_GPU(Ps<GeometryCompactClass> geometry_compact_CPU, Ps<GeometryCompactClass> geometry_compact_GPU){
    for(int i_group=0; i_group < geometry_compact_CPU->group_elements.size(); i_group++){
        int threadsPerBlock = 48;
        int sizeGrid = 6;
        int nGrids = std::floor( geometry_compact_CPU->group_elements[i_group].connectivities[0].size()  / (sizeGrid*threadsPerBlock) ) + 1 ;  // obtenir l'entier superieur
        int lastGridSize = (geometry_compact_CPU->group_elements[i_group].connectivities[0].size() - (sizeGrid*threadsPerBlock)*(nGrids-1))/threadsPerBlock;
        //PRINT(nGrids);
        //PRINT(lastGridSize);
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
                    //PRINT(i_grid);
                    //PRINT(blocksPerGrid);
                    //global_calculate_side_M_0<<<blocksPerGrid,threadsPerBlock>>>(geometry_compact_GPU.ptr(), i_group, i_grid, sizeGrid, geometry_compact_CPU->group_elements[i_group].nb_elements);
                    global_calculate_side_N_0<<<blocksPerGrid,threadsPerBlock>>>(geometry_compact_GPU.ptr(), i_group, i_grid, sizeGrid, geometry_compact_CPU->group_elements[i_group].nb_elements);
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
                    //PRINT(i_grid);
                    //PRINT(blocksPerGrid);
                    //global_calculate_side_M_1<<<blocksPerGrid,threadsPerBlock>>>(geometry_compact_GPU.ptr(), i_group, i_grid, sizeGrid, geometry_compact_CPU->group_elements[i_group].nb_elements);
                    global_calculate_side_N_1<<<blocksPerGrid,threadsPerBlock>>>(geometry_compact_GPU.ptr(), i_group, i_grid, sizeGrid, geometry_compact_CPU->group_elements[i_group].nb_elements);
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
                    //PRINT(i_grid);
                    //PRINT(blocksPerGrid);
                    //global_calculate_side_M_2<<<blocksPerGrid,threadsPerBlock>>>(geometry_compact_GPU.ptr(), i_group, i_grid, sizeGrid, geometry_compact_CPU->group_elements[i_group].nb_elements);
                    global_calculate_side_N_2<<<blocksPerGrid,threadsPerBlock>>>(geometry_compact_GPU.ptr(), i_group, i_grid, sizeGrid, geometry_compact_CPU->group_elements[i_group].nb_elements);
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
                    //PRINT(i_grid);
                    //PRINT(blocksPerGrid);
                    //global_calculate_side_M_3<<<blocksPerGrid,threadsPerBlock>>>(geometry_compact_GPU.ptr(), i_group, i_grid, sizeGrid, geometry_compact_CPU->group_elements[i_group].nb_elements);
                    global_calculate_side_N_3<<<blocksPerGrid,threadsPerBlock>>>(geometry_compact_GPU.ptr(), i_group, i_grid, sizeGrid, geometry_compact_CPU->group_elements[i_group].nb_elements);
                }
                break;
            }
            default :{
                std::cerr << "type de pattern non implemente" << std::endl; assert(0);                    
            }
        }
    }
}

void launch_calculate_side_N_M_CPU(Ps<GeometryCompactClass> geometry_compact_CPU){
    for(int i_group=0; i_group < geometry_compact_CPU->group_elements.size(); i_group++){
        switch (geometry_compact_CPU->group_elements[i_group].pattern_id){
            //for pattern PATTERN_Triangle
            case 0 :{
                //global_calculate_side_M_0_CPU(geometry_compact_CPU.ptr(), i_group);
                global_calculate_side_N_0_CPU(geometry_compact_CPU.ptr(), i_group);
                break;
            }
            //for pattern PATTERN_Triangle_6
            case 1 :{
                //global_calculate_side_M_1_CPU(geometry_compact_CPU.ptr(), i_group);
                global_calculate_side_N_1_CPU(geometry_compact_CPU.ptr(), i_group);
                break;
            }
            //for pattern PATTERN_Tetra
            case 2 :{
                //global_calculate_side_M_2_CPU(geometry_compact_CPU.ptr(), i_group);
                global_calculate_side_N_2_CPU(geometry_compact_CPU.ptr(), i_group);
                break;
            }
            //for pattern PATTERN_Tetra_10
            case 3 :{
                //global_calculate_side_M_3_CPU(geometry_compact_CPU.ptr(), i_group);
                global_calculate_side_N_3_CPU(geometry_compact_CPU.ptr(), i_group);
                break;
            }
            default :{
                std::cerr << "type de pattern non implemente" << std::endl; assert(0);
            }
            
        }
    }
}

void launch_calculate_interface_N_M_CPU(Ps<GeometryCompactClass> geometry_compact_CPU){
    for(int i_group=0; i_group < geometry_compact_CPU->group_interfaces.size(); i_group++){
        switch (geometry_compact_CPU->group_interfaces[i_group].patterns_id[0]){
            //for pattern Bar
            case 0 :{
                global_calculate_interface_NeMe_0_CPU(geometry_compact_CPU.ptr(), i_group);
                break;
            }
            //for pattern Bar_3
            case 1 :{
                global_calculate_interface_NeMe_1_CPU(geometry_compact_CPU.ptr(), i_group);
                break;
            }
            //for pattern Triangle
            case 2 :{
                global_calculate_interface_NeMe_2_CPU(geometry_compact_CPU.ptr(), i_group);
                break;
            }
            //for pattern Triangle_6
            case 3 :{
                global_calculate_interface_NeMe_3_CPU(geometry_compact_CPU.ptr(), i_group);
                break;
            }
            default :{
                std::cerr << "type de pattern non implemente" << std::endl; assert(0);
            }
            
        }
    }
}

