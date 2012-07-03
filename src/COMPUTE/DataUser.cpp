#include "DataUser.h"
#include "../UTILS/Sc2String.h"
#include <Metil/BasicVec.h>

#include <iostream>
#include <fstream>
#include <stdlib.h>

#include <Metil/Level1/CompilationEnvironment.h>
#include <Metil/DynamicLibrary.h>
#include <Metil/MathBasicVec.h>
#include <Metil/System.h>
#include <Metil/Math.h>
#include <Metil/Md5.h>
#include <set>
#include <map>

using namespace Metil;
using namespace json_spirit;  


//*************************************************************************************************************
// fonctions d'initialisation
//*************************************************************************************************************
DataUser::DataUser(Sc2String model_path_, Sc2String calcul_path_, Sc2String id_calcul_)/*:
ScJsonReader(),
nb_ddl(mesh.nb_ddl),
nb_sst(mesh.nb_sst),
nb_inter(mesh.nb_inter),
nb_groups_elem(mesh.nb_groups_elem),
nb_groups_inter(mesh.nb_groups_inter),
group_elements(pieces_vec),
group_edges(edges_vec),
group_interfaces(interfaces_vec),
behaviour_materials(materials_vec),
behaviour_links(links_vec)*/
{
    id_calcul << id_calcul_;
    model_path = model_path_;
    calcul_path = calcul_path_;
}

DataUser::DataUser(Sc2String id_model_, Sc2String id_calcul_)/*:
ScJsonReader(),
nb_ddl(mesh.nb_ddl),
nb_sst(mesh.nb_sst),
nb_inter(mesh.nb_inter),
nb_groups_elem(mesh.nb_groups_elem),
nb_groups_inter(mesh.nb_groups_inter),
group_elements(pieces_vec),
group_edges(edges_vec),
group_interfaces(interfaces_vec),
behaviour_materials(materials_vec),
behaviour_links(links_vec)*/
{
    initialisation(id_model_,id_calcul_);
}

DataUser::DataUser()/*:
ScJsonReader(),
nb_ddl(mesh.nb_ddl),
nb_sst(mesh.nb_sst),
nb_inter(mesh.nb_inter),
nb_groups_elem(mesh.nb_groups_elem),
nb_groups_inter(mesh.nb_groups_inter),
group_elements(pieces_vec),
group_edges(edges_vec),
group_interfaces(interfaces_vec),
behaviour_materials(materials_vec),
behaviour_links(links_vec)*/
{
}

void DataUser::initialisation(Sc2String id_model_, Sc2String id_calcul_){
    model_path = "/share/sc2/Developpement/MODEL/";
    calcul_path = model_path + "model_" + id_model_ + "/calcul_" + id_calcul_ ;
    result_path = model_path + "model_" + id_model_ + "/calcul_" + id_calcul_ + "/results" ;
    file_calcul = result_path + "/calcul.txt" ; // MODIFIE POUR NOUVELLE INTERFACE
    id_calcul << id_calcul_;
}

//*************************************************************************************************************
// fonction de lecture du fichier de calcul
//*************************************************************************************************************
void DataUser::read_json_calcul(){
    read_json(file_calcul); /// Appel a la fonction de lecture generee
}

//*************************************************************************************************************
// fonction de generation de .cpp à compiler à la volée pour la lecture de paramètres matériaux
//*************************************************************************************************************
/*  A REVOIR, INUTILE POUR LE MOMENT
void DataUser::write_entete_h( StringWithSepInCppLineMaker &file){
  
    int nb_mat = behaviour_materials.size();
    int nb_link = behaviour_links.size();
    int nb_CL = behaviour_bc.size();
    int nb_CLv = behaviour_bc_volume.size();
    int nb_step = behaviour_bc[0].step.size();
    int Multiresolution_nb_cycle = options.Multiresolution_nb_cycle;
    
//     file << "#ifndef READ_PARAM_H" ;
//     file << "#define READ_PARAM_H" ;
    file << "#ifdef METIL_COMP_DIRECTIVE" ;
    file << "    #pragma gpu_flag --compiler-options -fpermissive" ;
    file << "#endif" ;
    file << "" ;
//     file << "#include <cmath>" ;
    file << "#include <Metil/BasicVec.h>" ;
    file << "#include <Metil/CudaMetil.h>" ;
    file << "#include <Metil/String.h>" ;
    file << "#include \"FieldStructureCompactClass.h\"" ;
    file << "#include \"DataReader.h\"";
//     file << "using namespace json_spirit;" ;
//     file << "#include \"DataUser.h\"" ;
    
//     file << "#define TYPE  double";
//     file << "#define DIM  " << DIM ;
    
    file << "using namespace Metil;" ;
    file << "" ;
    
//     file << "static const int THREADSPERBLOCK = 48;";
//     file << "static const int SIZEGRID = 6;";
    
//     file << "static const int nb_mat_total = "       << nb_mat << ";" ;
//     file << "static const int nb_link_total = "      << nb_link << ";" ;
//     file << "static const int nb_CL_total = "        << nb_CL << ";" ;
//     file << "static const int nb_step_total = "      << nb_step << ";" ;
//     file << "static const int nb_CLv_total = "       << nb_CLv << ";" ;
    
//     file << "END_METIL_NAMESPACE;";
//     file << "";
//     file << "";
//     file << "template< int num_step, int num_mat >";
//     file << "__global__ void global_read_data_group_elements(FieldStructureCompactClass *field_structure_compact_GPU, Number<num_mat>, int i_group, int i_grid, int sizeGrid, int nb_elements, int i_res, Number<num_step>, TYPE t);";
//     file << "";
//     file << "template< int num_step, int num_link >";
//     file << "__global__ void global_read_data_links_group_interfaces(FieldStructureCompactClass *field_structure_compact_GPU, Number<num_link>, int i_group, int i_grid, int sizeGrid, int nb_interfaces, int i_res, Number<num_step>, TYPE t);";
//     file << "";
//     file << "#endif //READ_PARAM_H"; 
//     file << "";
}


void write_entete_cpp( StringWithSepInCppLineMaker &file ){
    //file << "#ifdef METIL_COMP_DIRECTIVE";
    file << "#pragma gpu_flag --compiler-options -fpermissive";
    //file << "#endif";
    file << "#include <Metil/BasicVec.h>" ;
    file << "#include <Metil/CudaMetil.h>" ;
    file << "#include \"ReadParam.h\"" ;
    file << "using namespace Metil;" ;
    file << "" ;
}



// void write_read_mat_prop_h(Sc2String prop_name, StringWithSepInCppLineMaker &file){
//     file << "template< int num_mat > __inline__ TYPE read_mat_" << prop_name << "(FieldStructureCompactClass *field_structure_compact_GPU, Number<num_mat>, int i_group, int i_elem, int i_res, TYPE t);" ;
// }
// 
// void write_read_link_prop_h(Sc2String prop_name, StringWithSepInCppLineMaker &file){
//     file << "template< int num_link > __inline__ TYPE read_link_" << prop_name << "(FieldStructureCompactClass *field_structure_compact_GPU, Number<num_link>,int i_group, int i_link, int i_res,TYPE t);" ;
// }
// 
// void write_read_behaviour_bc_prop_h(Sc2String prop_name, StringWithSepInCppLineMaker &file){
//     file << "template< int num_CL, int num_step > __inline__ TYPE read_CL_" << prop_name << "(FieldStructureCompactClass *field_structure_compact_GPU, Number<num_CL>, Number<num_step>, int i_group, int i_edge, int i_res,TYPE t);" ;
// }
// 
// void write_read_behaviour_bc_volume_prop_h(Sc2String prop_name, StringWithSepInCppLineMaker &file){
//     file << "template< int num_CLv, int num_step > __inline__ TYPE read_behaviour_bc_volume_" << prop_name << "(FieldStructureCompactClass *field_structure_compact_GPU, Number<num_CLv>, Number<num_step>, int i_group, int i_elem, int i_res,TYPE t);" ;
// }




void write_read_mat_prop_cpp(Sc2String prop, Sc2String prop_name, int i_prop, StringWithSepInCppLineMaker &file){
    Sc2String prop_temp;
    prop_temp << prop;
    if(prop_temp=="" or prop_temp==" "){prop="0";}
    file << "        field_structure_compact_GPU->group_elements[i_group].mat_prop["<< i_prop <<"][i_elem] = " << prop << ";" ;
}

void write_read_link_prop_cpp(Sc2String prop, Sc2String prop_name, int i_prop, StringWithSepInCppLineMaker &file){
    Sc2String prop_temp;
    prop_temp << prop;
    if(prop_temp=="" or prop_temp==" "){prop="0";}
    file << "        field_structure_compact_GPU->group_interfaces[i_group].link_prop["<< i_prop <<"][i_inter] = " << prop << ";" ;
}


// ecriture des fonction de lecture de propriété matériaux sur les elements-----------------------------------------------
void DataUser::write_global_read_data_materials_group_elements( int i_mat,  StringWithSepInCppLineMaker &file){
    file << "__global__ void global_read_data_materials_group_elements_" << i_mat << "(FieldStructureCompactClass *field_structure_compact_GPU, int i_group, int i_grid, int sizeGrid, int nb_elements, int i_res, TYPE t){";
    file << "    int i_elem = i_grid * sizeGrid * blockDim.x + blockIdx.x * blockDim.x + threadIdx.x;";
    file << "    if(i_elem <nb_elements){";
    file << "        TYPE x = field_structure_compact_GPU->group_elements[i_group].pt[0][i_elem];" ;
    file << "        TYPE y = field_structure_compact_GPU->group_elements[i_group].pt[1][i_elem];" ;
    file << "        TYPE z = field_structure_compact_GPU->group_elements[i_group].pt[2][i_elem];" ;
    for(int i_prop=0; i_prop<behaviour_materials[i_mat].mat_prop.size(); i_prop++){
        write_read_mat_prop_cpp(behaviour_materials[i_mat].mat_prop[i_prop], behaviour_materials[i_mat].mat_prop_name[i_prop], i_prop, file);
    }
    file << "    }";
    file << "};";
    file << "";
}

void DataUser::write_launch_read_data_materials_group_elements( StringWithSepInCppLineMaker &file ){
    file << "    virtual void launch_read_data_materials_group_elements(Ps<FieldStructureCompactClass> field_structure_compact_CPU, Ps<FieldStructureCompactClass> field_structure_compact_GPU, int i_res, double t){";
    file << "        for(int i_group=0; i_group < field_structure_compact_CPU->group_elements.size(); i_group++){";
    file << "            int threadsPerBlock = THREADSPERBLOCK;";
    file << "            int sizeGrid = SIZEGRID;";
    file << "            int nGrids = std::floor( field_structure_compact_CPU->group_elements[i_group].nb_elements_for_GPU  / (sizeGrid*threadsPerBlock) ) + 1 ;  // obtenir l'entier superieur ";
    file << "            int lastGridSize = (field_structure_compact_CPU->group_elements[i_group].nb_elements_for_GPU  - (sizeGrid*threadsPerBlock)*(nGrids-1))/threadsPerBlock; ";
    file << "            switch (field_structure_compact_CPU->group_elements[i_group].material_id){ ";
    for(int i_mat=0; i_mat<behaviour_materials.size(); i_mat++){
        file << "                case " << behaviour_materials[i_mat].id << " :{";
        file << "                    for(int i_grid=0; i_grid < nGrids; i_grid++){";
        file << "                        int blocksPerGrid;";
        file << "                        if(i_grid == nGrids-1){";
        file << "                            blocksPerGrid = lastGridSize;";
        file << "                        }else{";
        file << "                            blocksPerGrid = sizeGrid;";
        file << "                        }";
        file << "                        global_read_data_materials_group_elements_"<< i_mat <<"<<<blocksPerGrid,threadsPerBlock>>>(field_structure_compact_GPU.ptr(), i_group, i_grid, sizeGrid, field_structure_compact_CPU->group_elements[i_group].nb_elements, i_res, t); ";
        file << "                    }";
        file << "                break;";
        file << "                }";
    }
    file << "            }";
    file << "        }";
    file << "    }";
    file << "";
}


// ecriture des fonction de lecture de propriété des efforts volumiques sur les elements-----------------------------------------------
void DataUser::write_global_read_data_bc_volume_poids_group_elements( int i_CLv, int i_step, StringWithSepInCppLineMaker &file){
    file << "// calcul de " << behaviour_bc_volume[i_CLv].name;
    file << "__global__ void global_read_data_bc_volume_group_elements_poids_" << i_step << "(FieldStructureCompactClass *field_structure_compact_GPU, int i_group, int i_grid, int sizeGrid, int nb_elements, int i_res, TYPE t){";
    file << "    int i_elem = i_grid * sizeGrid * blockDim.x + blockIdx.x * blockDim.x + threadIdx.x;";
    file << "    if(i_elem <nb_elements){";
    file << "        TYPE size = field_structure_compact_GPU->group_elements[i_group].size[i_elem];" ;
    file << "        TYPE rho  = field_structure_compact_GPU->group_elements[i_group].mat_prop[3][i_elem];" ;
    Sc2String norme_pdirection;
    norme_pdirection << "sqrt( float(";
    for(int d=0; d<DIM; d++){
        Sc2String plus;
        if(d==DIM-1)
            plus << ")^2";
        else
            plus << ")^2 + ";
        norme_pdirection << "(" << behaviour_bc_volume[i_CLv].step[i_step].CLv_step_prop[d] << plus ;
    }
    norme_pdirection << "));";
    file << "        TYPE norme_pdirection  = " <<  norme_pdirection ;
    for(int d=0; d<DIM; d++){
        file << "        field_structure_compact_GPU->group_elements[i_group].volumic_force[" << d << "][i_elem] += rho * size / norme_pdirection * " << behaviour_bc_volume[i_CLv].step[i_step].CLv_step_prop[d] << " * " << behaviour_bc_volume[i_CLv].step[i_step].CLv_step_prop[6] <<";";
    }
    file << "    }";
    file << "};";
    file << "";
}

void DataUser::write_global_read_data_bc_volume_acceleration_group_elements( int i_CLv, int i_step, StringWithSepInCppLineMaker &file){
    file << "// calcul de " << behaviour_bc_volume[i_CLv].name;
    file << "__global__ void global_read_data_bc_volume_group_elements_acceleration_" << i_step << "(FieldStructureCompactClass *field_structure_compact_GPU, int i_group, int i_grid, int sizeGrid, int nb_elements, int i_res, TYPE t){";
    file << "    int i_elem = i_grid * sizeGrid * blockDim.x + blockIdx.x * blockDim.x + threadIdx.x;";
    file << "    if(i_elem <nb_elements){";
    file << "        TYPE size = field_structure_compact_GPU->group_elements[i_group].size[i_elem];" ;
    file << "        TYPE rho  = field_structure_compact_GPU->group_elements[i_group].mat_prop[3][i_elem];" ;
    Sc2String norme_pdirection;
    norme_pdirection << "sqrt( float(";
    for(int d=0; d<DIM; d++){
        Sc2String plus;
        if(d==DIM-1)
            plus << ")^2";
        else
            plus << ")^2 + ";
        norme_pdirection << "(" << behaviour_bc_volume[i_CLv].step[i_step].CLv_step_prop[d] << plus ;
    }
    norme_pdirection << "));";
    file << "        TYPE norme_pdirection  = " <<  norme_pdirection ;
    for(int d=0; d<DIM; d++){
        file << "        field_structure_compact_GPU->group_elements[i_group].volumic_force[" << d << "][i_elem] += rho * size / norme_pdirection * " << behaviour_bc_volume[i_CLv].step[i_step].CLv_step_prop[d] << " * " << behaviour_bc_volume[i_CLv].step[i_step].CLv_step_prop[6] <<";";
    }
    file << "    }";
    file << "};";
    file << "";
}

void DataUser::write_launch_read_data_bc_volume_group_elements( StringWithSepInCppLineMaker &file ){
    file << "    virtual void launch_read_data_bc_volume_group_elements(Ps<FieldStructureCompactClass> field_structure_compact_CPU, Ps<FieldStructureCompactClass> field_structure_compact_GPU, int i_res, int num_step, double t){";
    file << "        for(int i_group=0; i_group < field_structure_compact_CPU->group_elements.size(); i_group++){";
    file << "            int threadsPerBlock = THREADSPERBLOCK;";
    file << "            int sizeGrid = SIZEGRID;";
    file << "            int nGrids = std::floor( field_structure_compact_CPU->group_elements[i_group].nb_elements_for_GPU  / (sizeGrid*threadsPerBlock) ) + 1 ;  // obtenir l'entier superieur ";
    file << "            int lastGridSize = (field_structure_compact_CPU->group_elements[i_group].nb_elements_for_GPU  - (sizeGrid*threadsPerBlock)*(nGrids-1))/threadsPerBlock; ";
    file << "            for(int i_grid=0; i_grid < nGrids; i_grid++){";
    file << "                int blocksPerGrid;";
    file << "                if(i_grid == nGrids-1){";
    file << "                    blocksPerGrid = lastGridSize;";
    file << "                }else{";
    file << "                    blocksPerGrid = sizeGrid;";
    file << "                }";
    file << "                switch (num_step){ ";
    for(int i_step=0; i_step<behaviour_bc_volume[0].step.size(); i_step++){
        file << "                    case " << i_step << " :{";
        for(int i_CLv=0; i_CLv<behaviour_bc_volume.size(); i_CLv++){
            //if(behaviour_bc_volume[i_CLv].select){
                file << "                if(i_grid == nGrids-1){";
                if(!behaviour_bc_volume[i_CLv].name.find("poids"))
                    file << "                global_read_data_bc_volume_group_elements_poids_" << i_step << "<<<blocksPerGrid,threadsPerBlock>>>(field_structure_compact_GPU.ptr(), i_group, i_grid, sizeGrid, field_structure_compact_CPU->group_elements[i_group].nb_elements, i_res, t); ";
                else if(!behaviour_bc_volume[i_CLv].name.find("effort d"))
                    file << "                global_read_data_bc_volume_group_elements_acceleration_" << i_step << "<<<blocksPerGrid,threadsPerBlock>>>(field_structure_compact_GPU.ptr(), i_group, i_grid, sizeGrid, field_structure_compact_CPU->group_elements[i_group].nb_elements, i_res, t); ";
//                 else if(!behaviour_bc_volume[i_CLv].name.find("effort c"))
//                     file << "                global_read_data_bc_volume_group_elements_centrifuge_" << i_step << "<<<blocksPerGrid,threadsPerBlock>>>(field_structure_compact_GPU.ptr(), i_group, i_grid, sizeGrid, field_structure_compact_CPU->group_elements[i_group].nb_elements, i_res, t); ";
                file << "                }";
            //}
        }
        file << "                    break;";
        file << "                    }";
    }
    file << "                }";
    file << "            }";
    file << "        }";
    file << "    }";
    file << "";
}


// ecriture des fonction de lecture de propriété liaisons sur les interfaces-----------------------------------------------
void DataUser::write_global_read_data_links_group_interfaces( int i_link, StringWithSepInCppLineMaker &file){
    file << "__global__ void global_read_data_links_group_interfaces_" << i_link << "(FieldStructureCompactClass *field_structure_compact_GPU, int i_group, int i_grid, int sizeGrid, int nb_interfaces, int i_res, TYPE t){";
    file << "    int i_inter = i_grid * sizeGrid * blockDim.x + blockIdx.x * blockDim.x + threadIdx.x;";
    file << "    if(i_inter <nb_interfaces){";
    file << "        TYPE x = field_structure_compact_GPU->group_interfaces[i_group].pt[0][i_inter];" ;
    file << "        TYPE y = field_structure_compact_GPU->group_interfaces[i_group].pt[1][i_inter];" ;
    file << "        TYPE z = field_structure_compact_GPU->group_interfaces[i_group].pt[2][i_inter];" ;
    for(int i_prop=0; i_prop<behaviour_links[i_link].link_prop.size(); i_prop++){
        write_read_link_prop_cpp(behaviour_links[i_link].link_prop[i_prop], behaviour_links[i_link].link_prop_name[i_prop], i_prop, file);
    }
    file << "    }";
    file << "};";
    file << "";
}


void DataUser::write_launch_read_data_links_group_interfaces( StringWithSepInCppLineMaker &file ){
    file << "    virtual void launch_read_data_links_group_interfaces(Ps<FieldStructureCompactClass> field_structure_compact_CPU, Ps<FieldStructureCompactClass> field_structure_compact_GPU, int i_res, double t){";
    file << "        for(int i_group=0; i_group < field_structure_compact_CPU->group_interfaces.size(); i_group++){";
    file << "            if(field_structure_compact_CPU->group_interfaces[i_group].type != 0){";
    file << "                int threadsPerBlock = THREADSPERBLOCK;";
    file << "                int sizeGrid = SIZEGRID;";
    file << "                int nGrids = std::floor( field_structure_compact_CPU->group_interfaces[i_group].nb_interfaces_for_GPU  / (sizeGrid*threadsPerBlock) ) + 1 ;  // obtenir l'entier superieur ";
    file << "                int lastGridSize = (field_structure_compact_CPU->group_interfaces[i_group].nb_interfaces_for_GPU  - (sizeGrid*threadsPerBlock)*(nGrids-1))/threadsPerBlock; ";
    file << "                switch (field_structure_compact_CPU->group_interfaces[i_group].link_id){ ";
    for(int i_link=0; i_link<behaviour_links.size(); i_link++){
        file << "                    case " << behaviour_links[i_link].id << " :{";
        file << "                        for(int i_grid=0; i_grid < nGrids; i_grid++){";
        file << "                            int blocksPerGrid;";
        file << "                            if(i_grid == nGrids-1){";
        file << "                                blocksPerGrid = lastGridSize;";
        file << "                            }else{";
        file << "                                blocksPerGrid = sizeGrid;";
        file << "                            }";
        file << "                            global_read_data_links_group_interfaces_"<< i_link <<"<<<blocksPerGrid,threadsPerBlock>>>(field_structure_compact_GPU.ptr(), i_group, i_grid, sizeGrid, field_structure_compact_CPU->group_interfaces[i_group].nb_interfaces, i_res, t); ";
        file << "                        }";
        file << "                    break;";
        file << "                    }";
    }
    file << "                }";
    file << "            }";
    file << "        }";
    file << "    };";
    file << "";
}


// ecriture des fonction de lecture de propriété liaisons sur les interfaces-----------------------------------------------
void DataUser::write_global_read_data_bc_group_interfaces( int i_bc, int i_step, StringWithSepInCppLineMaker &file){
    file << "__global__ void global_read_data_bc_group_interfaces_" << i_bc << "_" << i_step << "(FieldStructureCompactClass *field_structure_compact_GPU, int i_group, int i_grid, int sizeGrid, int nb_interfaces, int i_res, TYPE t){";
    file << "    int i_inter = i_grid * sizeGrid * blockDim.x + blockIdx.x * blockDim.x + threadIdx.x;";
    file << "    if(i_inter <nb_interfaces){";
    file << "        TYPE x = field_structure_compact_GPU->group_interfaces[i_group].pt[0][i_inter];" ;
    file << "        TYPE y = field_structure_compact_GPU->group_interfaces[i_group].pt[1][i_inter];" ;
    file << "        TYPE z = field_structure_compact_GPU->group_interfaces[i_group].pt[2][i_inter];" ;
    for(int d=0; d<DIM; d++){
        file << "        field_structure_compact_GPU->group_interfaces[i_group].bc[" << d << "][i_inter] = " << behaviour_bc[i_bc].step[i_step].CL_step_prop[d] << " * " << behaviour_bc[i_bc].step[i_step].CL_step_prop[3+d] <<";";
    }
    file << "    }";
    file << "};";
    file << "";
}


void DataUser::write_launch_read_data_bc_group_interfaces( StringWithSepInCppLineMaker &file ){
    file << "    virtual void launch_read_data_bc_group_interfaces(Ps<FieldStructureCompactClass> field_structure_compact_CPU, Ps<FieldStructureCompactClass> field_structure_compact_GPU, int i_res, int num_step, double t){";
    file << "        for(int i_group=0; i_group < field_structure_compact_CPU->group_interfaces.size(); i_group++){";
    file << "            if(field_structure_compact_CPU->group_interfaces[i_group].type == 0){";
    file << "                int threadsPerBlock = THREADSPERBLOCK;";
    file << "                int sizeGrid = SIZEGRID;";
    file << "                int nGrids = std::floor( field_structure_compact_CPU->group_interfaces[i_group].nb_interfaces_for_GPU  / (sizeGrid*threadsPerBlock) ) + 1 ;  // obtenir l'entier superieur ";
    file << "                int lastGridSize = (field_structure_compact_CPU->group_interfaces[i_group].nb_interfaces_for_GPU  - (sizeGrid*threadsPerBlock)*(nGrids-1))/threadsPerBlock; ";
    file << "                switch (num_step){ ";
    for(int i_step=0; i_step<behaviour_bc[0].step.size(); i_step++){
        file << "                    case " << i_step << " :{";
        file << "                        switch (field_structure_compact_CPU->group_interfaces[i_group].bc_id){ ";
        for(int i_bc=0; i_bc<behaviour_bc.size(); i_bc++){
            file << "                        case " << behaviour_bc[i_bc].id << " :{";
            file << "                            for(int i_grid=0; i_grid < nGrids; i_grid++){";
            file << "                                int blocksPerGrid;";
            file << "                                if(i_grid == nGrids-1){";
            file << "                                    blocksPerGrid = lastGridSize;";
            file << "                                }else{";
            file << "                                    blocksPerGrid = sizeGrid;";
            file << "                                }";
            file << "                                global_read_data_bc_group_interfaces_"<< i_bc <<"_" << i_step << "<<<blocksPerGrid,threadsPerBlock>>>(field_structure_compact_GPU.ptr(), i_group, i_grid, sizeGrid, field_structure_compact_CPU->group_interfaces[i_group].nb_interfaces, i_res, t); ";
            file << "                            }";
            file << "                        break;";
            file << "                        }";
        }
        file << "                        }";
        file << "                    break;";
        file << "                    }";
    }
    file << "                }";
    file << "            }";
    file << "        }";
    file << "    };";
    file << "";
}






void DataUser::write_read_prop_cpp( Sc2String &file_cu, Sc2String &file_h ){   
    std::cout << "ecriture de données" << std::endl;
    
    // write
    File fu( file_cu, "w" );
//     File fh( file_h, "w" );
    StringWithSepInCppLineMaker fichier_cu( fu );
//     StringWithSepInCppLineMaker fichier_h( fh );
    
    // ecriture des déclaration des fonctions
    write_entete_h(fichier_cu);
//     write_entete_cpp(fichier_cu);
    
    // ecriture des fonction de lecture des propriétés matériaux
    for(int i_mat=0; i_mat<behaviour_materials.size(); i_mat++){
        write_global_read_data_materials_group_elements( i_mat, fichier_cu);
    }
    
    // ecriture des fonction de lecture des propriétés liaison
    for(int i_link=0; i_link<behaviour_links.size(); i_link++){
        write_global_read_data_links_group_interfaces( i_link, fichier_cu);
    }
    
    // ecriture des fonction de lecture des condition limite, fonctions spatiales et temporelles
    for(int i_bc=0; i_bc<behaviour_bc.size(); i_bc++){
        for(int i_step=0; i_step<behaviour_bc[i_bc].step.size(); i_step++){
            write_global_read_data_bc_group_interfaces( i_bc, i_step, fichier_cu); 
        }
    }
    
    // ecriture des fonction de lecture des CL volumique, fonctions spatiales et temporelles
    for(int i_CLv=0; i_CLv<behaviour_bc_volume.size(); i_CLv++){
        if(!behaviour_bc_volume[i_CLv].name.find("poids")){
            for(int i_step=0; i_step<behaviour_bc_volume[i_CLv].step.size(); i_step++){
                    write_global_read_data_bc_volume_poids_group_elements( i_CLv, i_step, fichier_cu);
            }
        }else if(!behaviour_bc_volume[i_CLv].name.find("effort d")){
            for(int i_step=0; i_step<behaviour_bc_volume[i_CLv].step.size(); i_step++){
                    write_global_read_data_bc_volume_acceleration_group_elements( i_CLv, i_step, fichier_cu);
            }
        }
    }
    
    
    fichier_cu << "struct DataReader_" << id_calcul << " : public DataReader {";
    fichier_cu << "    DataReader_" << id_calcul << "(){};";
    // ecriture de la fonction read_data_group_elements
    write_launch_read_data_materials_group_elements( fichier_cu );
    write_launch_read_data_bc_volume_group_elements( fichier_cu );
    write_launch_read_data_links_group_interfaces( fichier_cu );
    write_launch_read_data_bc_group_interfaces(  fichier_cu );
    fichier_cu << "};";
    fichier_cu << "";
    fichier_cu << "extern \"C\" DataReader *NEW_Reader() { return NEW( DataReader_" << id_calcul <<  " ); }";
    fichier_cu << "";
    fichier_cu << "";
}


DataReader *DataUser::NEW_DataReader( ) {
    
    
    Sc2String base;
    base << "ReadParam_" << id_calcul;
    
    Level1::CompilationEnvironment &ce = Level1::CompilationEnvironment::get_main_compilation_environment();
//     Sc2String calcul_path;
//     calcul_path << data_user.calcul_path;
//     ce.set_comp_dir( calcul_path );
    ce.add_inc_path("./src/COMPUTE/");
    ce.add_inc_path("./src/GEOMETRY/");
    ce.add_inc_path("./src/UTILS/json_spirit/");
    
    Sc2String proc_DIM;
    proc_DIM << "DIM=" << DIM;
    Sc2String proc_TYPE;
    proc_TYPE << "TYPE=" << "double";
    Sc2String proc_THREADSPERBLOCK;
    proc_THREADSPERBLOCK << "THREADSPERBLOCK=" << 48;
    Sc2String proc_SIZEGRID;
    proc_SIZEGRID << "SIZEGRID=" << 6;
    ce.add_def_proc(proc_DIM);
    ce.add_def_proc(proc_TYPE);
    ce.add_def_proc(proc_THREADSPERBLOCK);
    ce.add_def_proc(proc_SIZEGRID);
    Sc2String file_cu = ce.cu_for( base );
    Sc2String file_h = ce.h_for( base );

    write_read_prop_cpp( file_cu,  file_h);

    Sc2String so = ce.lib_for( base, true );
    SI64 date_so = last_modification_time_or_zero_of_file_named( so );
    if ( ce.make_lib( so, file_cu, true ) )
        ERROR( "Pb during compilation of %s", file_cu.c_str() );
// 
    // load lib
    static std::map<String,DynamicLibrary> libs;
    if ( not libs.count( so ) )
        libs[ so ].open( so );
 
//     // find symbol
    DynamicLibrary &dl = libs[ so ];
    typedef DataReader *NewReader();
    NewReader *nr = (NewReader *)dl.get_sym( "NEW_Reader" );
//     PRINT( dl.error() );
    ASSERT( nr, "..." );
    return nr();
}
*/
