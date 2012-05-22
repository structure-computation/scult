#include "DataUser.h"
#include "../UTILS/Sc2String.h"
#include <Metil/BasicVec.h>

#include <iostream>
#include <fstream>

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


//Methode génériques **************************************************************************************************************************************
//recherche d'un group_elements particulier avec son id---------------
DataUser::GroupElements* DataUser::find_group_elements(int id_) {
    for (int i_group=0; i_group<group_elements.size(); i_group++) {
        if (group_elements[i_group].id == id_) {
            return &group_elements[i_group];
            break;
        }
    }
}

int DataUser::find_index_group_elements(int id_) {
    for (int i_group=0; i_group<group_elements.size(); i_group++) {
        if (group_elements[i_group].id == id_) {
            return i_group;
            break;
        }
    }
}

//recherche d'un group_interfaces particulier avec son id---------------
DataUser::GroupInterfaces* DataUser::find_group_interfaces(int id_) {
    for (int i_group=0; i_group<group_interfaces.size(); i_group++) {
        if (group_interfaces[i_group].id == id_) {
            return &group_interfaces[i_group];
            break;
        }
    }
}

int DataUser::find_index_group_interfaces(int id_) {
    for (int i_group=0; i_group<group_interfaces.size(); i_group++) {
        if (group_interfaces[i_group].id == id_) {
            return i_group;
            break;
        }
    }
}

//recherche d'un group_interfaces particulier avec son id---------------
DataUser::GroupEdges* DataUser::find_group_edges(int id_) {
    for (int i_group=0; i_group<group_edges.size(); i_group++) {
        if (group_edges[i_group].id == id_) {
            return &group_edges[i_group];
            break;
        }
    }
}

int DataUser::find_index_group_edges(int id_) {
    for (int i_group=0; i_group<group_edges.size(); i_group++) {
        if (group_edges[i_group].id == id_) {
            return i_group;
            break;
        }
    }
}


//recherche d'un behaviour_materials particulier avec son id---------------
DataUser::BehaviourMaterial* DataUser::find_behaviour_materials(int id_) {
    for (int i_group=0; i_group<behaviour_materials.size(); i_group++) {
        if (behaviour_materials[i_group].id == id_) {
            return &behaviour_materials[i_group];
            break;
        }
    }
}

int DataUser::find_index_behaviour_materials(int id_) {
    for (int i_group=0; i_group<behaviour_materials.size(); i_group++) {
        if (behaviour_materials[i_group].id == id_) {
            return i_group;
            break;
        }
    }
}

//recherche d'un behaviour_links particulier avec son id---------------
DataUser::BehaviourLink* DataUser::find_behaviour_links(int id_) {
    for (int i_group=0; i_group<behaviour_links.size(); i_group++) {
        if (behaviour_links[i_group].id == id_) {
            return &behaviour_links[i_group];
            break;
        }
    }
}

int DataUser::find_index_behaviour_links(int id_) {
    for (int i_group=0; i_group<behaviour_links.size(); i_group++) {
        if (behaviour_links[i_group].id == id_) {
            return i_group;
            break;
        }
    }
}

//recherche d'un behaviour_links particulier avec son id---------------
DataUser::BehavBc* DataUser::find_behaviour_bc(int id_) {
    for (int i_group=0; i_group<behaviour_bc.size(); i_group++) {
        if (behaviour_bc[i_group].id == id_) {
            return &behaviour_bc[i_group];
            break;
        }
    }
}

int DataUser::find_index_behaviour_bc(int id_) {
    for (int i_group=0; i_group<behaviour_bc.size(); i_group++) {
        if (behaviour_bc[i_group].id == id_) {
            return i_group;
            break;
        }
    }
}

//*************************************************************************************************************
// fonction d'initialisation
//*************************************************************************************************************

void DataUser::initialisation(Sc2String id_model_, Sc2String id_calcul_){
        model_path = "/share/sc2/Developpement/MODEL/";
        calcul_path = model_path + "model_" + id_model_ + "/calcul_" + id_calcul_ ;
        result_path = model_path + "model_" + id_model_ + "/calcul_" + id_calcul_ + "/results" ;
        file_calcul = calcul_path + "/calcul.json" ;  
        file_calcul_v2 = result_path + "/calcul.txt" ; 
        id_calcul << id_calcul_;
    }

//*************************************************************************************************************
// fonction de lecture du fichier de calcul
//*************************************************************************************************************
//lecture des groupes d'elements dans un fichier json--------------------------------------
void DataUser::read_json_groups_elements(const Object& gr){
    for(Object::size_type i=0;i != gr.size() ;i++){
        const Pair& pair1 = gr[i];        
        const Value&  value1 = pair1.value_;
        Object obj=value1.get_obj();
        for( Object::size_type j = 0; j != obj.size(); ++j )
        {
            const Pair& pair = obj[j];
            const Sc2String& name  = pair.name_;
            const Value&  value = pair.value_;

            if( name == "id" )
            {
                group_elements[i].id= value.get_int();
            }
            else if( name == "origine" )
            {
                group_elements[i].origine = value.get_str() ;
            }
            else if( name == "identificateur" )
            {
                group_elements[i].num_in_mesh_file = value.get_int() ;
            }
            else if( name == "name" )
            {
                group_elements[i].name = value.get_str();
            }
            else if( name == "group" )
            {
                //TODO
            }
            else if( name == "assigned" )
            {
                //TODO
            }
            else if(name=="id_material")
            {
                group_elements[i].id_material= value.get_int();
            }
            else
            {
                assert( "Donnees groups_elem non implementee" );
            }
        }
    }

}


///lecture des groupes d'interfaces dans un fichier json
void DataUser::read_json_groups_interfaces( const Object& gr ){
    for(Object::size_type i=0;i != gr.size() ;i++){
        const Pair& pair1 = gr[i];        
        const Value&  value1 = pair1.value_;
        Object obj=value1.get_obj();
        for( Object::size_type j = 0; j != obj.size(); ++j )
        {
            const Pair& pair = obj[j];
            const Sc2String& name  = pair.name_;
            const Value&  value = pair.value_;

            if( name == "id" )
            {
                group_interfaces[i].id= value.get_int();
            }
            else if( name == "origine" )
            {
                group_interfaces[i].origine= value.get_str();
            }
            else if( name == "name" )
            {
                group_interfaces[i].name= value.get_str();
            }
            else if( name == "type" )
            {
                group_interfaces[i].type= value.get_str();
            }
            else if( name == "adj_num_group" )
            {
                Sc2String adj=value.get_str();
                std::istringstream s(adj);
                BasicVec<int,2> adjnum;
                for(unsigned k=0;k< 2 ;k++){
                    s>>adjnum[k];
                }
                group_interfaces[i].adj_num_group=adjnum;
            }
            else if( name == "id_link" )
            {
                group_interfaces[i].id_link= value.get_int();
            }
            else if( name == "group" )
            {
                //TODO
            }
            else if( name == "assigned" )
            {
                group_interfaces[i].assigned= value.get_real();
            }
            else
            {
                assert( "Donnee groups_inter non implementee" );
            }
        }
    }
}

///lecture des groupes de bord dans un fichier json
void DataUser::read_json_groups_edges( const Object& gr){
    for(Object::size_type i=0;i != gr.size() ;i++){
        group_edges[i].geom.points.resize(2);
        for(int k=0; k<2; k++){
            group_edges[i].geom.points[k].resize(DIM);
        }
        const Pair& pair1 = gr[i];        
        const Value&  value1 = pair1.value_;
        Object obj=value1.get_obj();
        for( Object::size_type j = 0; j != obj.size(); ++j )
        {

            const Pair& pair = obj[j];
            const Sc2String& name  = pair.name_;
            const Value&  value = pair.value_;
            if( name == "id" )
            {
                group_edges[i].id= value.get_int();
            }
            else if( name == "origine" )
            {
                group_edges[i].geom.origine= value.get_str();
            }
            else if( name == "name" )
            {
                group_edges[i].name= value.get_str();
            }
            else if( name == "type" )
            {
                group_edges[i].geom.type= value.get_str();
            }
            else if( name == "id_CL" )
            {
                group_edges[i].id_CL= value.get_int();
            }
            else if( name == "to_visualize" )
            {
                group_edges[i].to_visualize= value.get_int();
            }
            else if( name == "assigned" )
            {
                group_edges[i].assigned= value.get_real();
            }
            else if(name == "pdirection_x" )
            {
                Sc2String temp=value.get_str();
                std::istringstream s(temp);
                s >> group_edges[i].geom.pdirection[0];
            }
            else if(name == "pdirection_y" )
            {
                Sc2String temp=value.get_str();
                std::istringstream s(temp);
                s >> group_edges[i].geom.pdirection[1];
            }
#if DIM==3
            else if(name == "pdirection_z" )
            {
                Sc2String temp=value.get_str();
                std::istringstream s(temp);
                s >> group_edges[i].geom.pdirection[2];
            }
#endif
            else if( name == "geometry" )
            {
                group_edges[i].geom.nature=value.get_str();
                group_edges[i].geom.points.resize(2);
                for(int k=0; k<2; k++){
                    group_edges[i].geom.points[k].resize(DIM);
                }
            }
            else if(name == "radius" )
            {
                Sc2String temp=value.get_str();
                std::istringstream is(temp);
                is >>group_edges[i].geom.radius;
//                 group_edges[i].geom.radius=value.get_real();
            }
            else if(name == "equation" )
            {
                group_edges[i].geom.equation=value.get_str();
            }
            else if(name == "point_1_x" )
            {
                Sc2String temp=value.get_str();
                std::istringstream s(temp);
                s >> group_edges[i].geom.points[0][0];
            }
            else if(name == "point_1_y" )
            {
                Sc2String temp=value.get_str();
                std::istringstream s(temp);
                s >> group_edges[i].geom.points[0][1];
            }
#if DIM==3
            else if(name == "point_1_z" )
            {
                Sc2String temp=value.get_str();
                std::istringstream s(temp);
                s >> group_edges[i].geom.points[0][2];                
            }
#endif
            else if(name == "point_2_x" )
            {
                Sc2String temp=value.get_str();
                std::istringstream s(temp);
                s >> group_edges[i].geom.points[1][0];
            }
            else if(name == "point_2_y" )
            {
                Sc2String temp=value.get_str();
                std::istringstream s(temp);
                s >> group_edges[i].geom.points[1][1];
            }
#if DIM==3
            else if(name == "point_2_z" )
            {
                Sc2String temp=value.get_str();
                std::istringstream s(temp);
                s >> group_edges[i].geom.points[1][2];
            }
#endif
            else
            {
                std::cout << "WARNING Donnee groups_edge non implementee : " << name << std::endl;
            }
        }
    }
    //Ajout du groupe en fin des groupes d'edge (comportement generique pour tous les edges non assignees
    group_edges[gr.size()].id=-1;
    group_edges[gr.size()].geom.type="all";
    group_edges[gr.size()].id_CL=-1; 
    

}

///lecture des proprietes materiaux donnees dans un fichier json
void DataUser::read_json_behaviour_materials(const Object& gr){

    for(Object::size_type i=0;i != gr.size() ;i++){
        //Object obj=pr[j].get_obj();;
    
        const Pair& pair1 = gr[i];        
        const Value&  value1 = pair1.value_;
        Object obj=value1.get_obj();  
                
        for( Object::size_type j = 0; j != obj.size(); ++j ){
            const Pair& pair = obj[j];
            const Sc2String& name  = pair.name_;
            const Value&  value = pair.value_;
            if( name == "id" )
            {
                behaviour_materials[i].id= value.get_int();
            }
            else if( name == "mtype" )
            {
                behaviour_materials[i].type= value.get_str();
            }
            else if( name == "type_num" )
            {
                behaviour_materials[i].type_num= value.get_int();
            }
            else if( name == "comp" )
            {
                behaviour_materials[i].comp= value.get_str();
            }
            else if( name == "type_plast" )
            {
                //behaviour_materials[i].type_plast = value.get_str();
                behaviour_materials[i].type_plast= value.get_str();
            }
            else if( name == "type_endo" )
            {
                //behaviour_materials[i].type_plast = value.get_str();
                behaviour_materials[i].type_endo= value.get_str();
            }
            else if( name == "resolution" )
            {
                behaviour_materials[i].resolution= value.get_str();
            }
            else if( name == "elastic_modulus" )
            {
                //behaviour_materials[i].elastic_modulus=value.get_str();
                behaviour_materials[i].mat_prop[0]=value.get_str();
            }
            else if( name == "poisson_ratio" )
            {
                //behaviour_materials[i].poisson_ratio=value.get_str();
                behaviour_materials[i].mat_prop[1]=value.get_str();
            }
            else if( name == "alpha" )
            {
                //behaviour_materials[i].alpha=value.get_str();
                behaviour_materials[i].mat_prop[2]=value.get_str();
            }
            else if( name == "rho" )
            {
                //behaviour_materials[i].rho=value.get_str();
                behaviour_materials[i].mat_prop[3]=value.get_str();
            }
            else if( name == "viscosite" )
            {
                //behaviour_materials[i].viscosite=value.get_str();
                behaviour_materials[i].mat_prop[4]=value.get_str();
            }
            else if( name == "dir_1_x" )
            {
                //behaviour_materials[i].dir_1_x = value.get_str();
                behaviour_materials[i].mat_prop[5]=value.get_str();
            }
            else if( name == "dir_1_y" )
            {
                //behaviour_materials[i].dir_1_y  = value.get_str();
                behaviour_materials[i].mat_prop[6]=value.get_str();
            }
#if DIM==3
            else if( name == "dir_1_z" )
            {
                //behaviour_materials[i].dir_1_z  = value.get_str();
                behaviour_materials[i].mat_prop[7]=value.get_str();
            }
#endif
            else if( name == "dir_2_x" )
            {
                //behaviour_materials[i].dir_2_x = value.get_str();
                behaviour_materials[i].mat_prop[8]=value.get_str();
            }
            else if( name == "dir_2_y" )
            {
                //behaviour_materials[i].dir_2_y = value.get_str();
                behaviour_materials[i].mat_prop[9]=value.get_str();
            }
#if DIM==3
            else if( name == "dir_2_z" )
            {
                //behaviour_materials[i].dir_2_z = value.get_str();
                behaviour_materials[i].mat_prop[10]=value.get_str();
            }
#endif
            else if( name == "dir_3_x" )
            {
                //behaviour_materials[i].dir_3_x = value.get_str();
                behaviour_materials[i].mat_prop[11]=value.get_str();
            }
            else if( name == "dir_3_y" )
            {
                //behaviour_materials[i].dir_3_y = value.get_str();
                behaviour_materials[i].mat_prop[12]=value.get_str();
            }
#if DIM==3
            else if( name == "dir_3_z" )
            {
                //behaviour_materials[i].dir_3_z = value.get_str();
                behaviour_materials[i].mat_prop[13]=value.get_str();
            }
#endif
            else if( name == "E1" )
            {
                //behaviour_materials[i].E1=value.get_str();
                behaviour_materials[i].mat_prop[14]=value.get_str();
            }
            else if( name == "E2" )
            {
                //behaviour_materials[i].E2=value.get_str();
                behaviour_materials[i].mat_prop[15]=value.get_str();
            }
            else if( name == "E3" )
            {
                //behaviour_materials[i].E3=value.get_str();
                behaviour_materials[i].mat_prop[16]=value.get_str();
            }
            else if( name == "G12" )
            {
                //behaviour_materials[i].G12=value.get_str();
                behaviour_materials[i].mat_prop[17]=value.get_str();
            }
            else if( name == "G23" )
            {
                //behaviour_materials[i].G23=value.get_str();
                behaviour_materials[i].mat_prop[18]=value.get_str();
            }
            else if( name == "G13" )
            {
                //behaviour_materials[i].G13=value.get_str();
                behaviour_materials[i].mat_prop[19]=value.get_str();
            }
            else if( name == "nu12" )
            {
                //behaviour_materials[i].nu12=value.get_str();
                behaviour_materials[i].mat_prop[20]=value.get_str();
            }
            else if( name == "nu23" )
            {
                //behaviour_materials[i].nu23=value.get_str();
                behaviour_materials[i].mat_prop[21]=value.get_str();
            }
            else if( name == "nu13" )
            {
                //behaviour_materials[i].nu13=value.get_str();
                behaviour_materials[i].mat_prop[22]=value.get_str();
            }
            else if( name == "alpha_1" )
            {
                //behaviour_materials[i].alpha_1=value.get_str();
                behaviour_materials[i].mat_prop[23]=value.get_str();
            }
            else if( name == "alpha_2" )
            {
                //behaviour_materials[i].alpha_2=value.get_str();
                behaviour_materials[i].mat_prop[24]=value.get_str();
            }
            else if( name == "alpha_3" )
            {
                //behaviour_materials[i].alpha_3=value.get_str();
                behaviour_materials[i].mat_prop[25]=value.get_str();
            }
            else if( name == "R0" )
            {
                //behaviour_materials[i].RO = value.get_str();
                behaviour_materials[i].mat_prop[26]=value.get_str();
            }
            else if( name == "k_p" )
            {
                //behaviour_materials[i].k_p = value.get_str();
                behaviour_materials[i].mat_prop[27]=value.get_str();
            }
            else if( name == "m_p" )
            {
                //behaviour_materials[i].m_p = value.get_str();
                behaviour_materials[i].mat_prop[28]=value.get_str();
            }
            else if( name == "c_p" or name == "couplage")   // COUPLAGE EST CONSERVE JUSQU A MAJ DE L INTERFACE
            {
                //behaviour_materials[i].Yc = value.get_str();
                behaviour_materials[i].mat_prop[29]=value.get_str();
            }
            else if( name == "Yo" )
            {
                //behaviour_materials[i].Ycp = value.get_str();
                behaviour_materials[i].mat_prop[30]=value.get_str();
            }
            else if( name == "Yc" )
            {
                //behaviour_materials[i].b = value.get_str();
                behaviour_materials[i].mat_prop[31]=value.get_str();
            }
            else if( name == "Ycf" )
            {
                //behaviour_materials[i].Yop = value.get_str();
                behaviour_materials[i].mat_prop[32]=value.get_str();
            }
            else if( name == "dmax" )
            {
                //behaviour_materials[i].Yc = value.get_str();
                behaviour_materials[i].mat_prop[33]=value.get_str();
            }
            else if( name == "b_c" )
            {
                //behaviour_materials[i].Ycp = value.get_str();
                behaviour_materials[i].mat_prop[34]=value.get_str();
            }
            else if( name == "effet_retard" )
            {
                //behaviour_materials[i].b = value.get_str();
                behaviour_materials[i].mat_prop[35]=value.get_str();
            }
            else if( name == "a" )
            {
                //behaviour_materials[i].b = value.get_str();
                behaviour_materials[i].mat_prop[36]=value.get_str();
            }
            else if( name == "tau_c" )
            {
                //behaviour_materials[i].b = value.get_str();
                behaviour_materials[i].mat_prop[37]=value.get_str();
            }
            else
            {
                std::cerr << "WARNING Donnee materials non implementee : " << name << std::endl;
            }
        }
    }
}

///Lecture des proprietes des interfaces donnees dans un fichier json
void DataUser::read_json_behaviour_interfaces(const Object& gr){
   
    for(Object::size_type i=0;i != gr.size() ;i++){
        //Object obj=pr[i].get_obj();;
        const Pair& pair1 = gr[i];        
        const Value&  value1 = pair1.value_;
        Object obj=value1.get_obj();
        for( Object::size_type j = 0; j != obj.size(); ++j )
        {
            const Pair& pair = obj[j];
            const Sc2String& name  = pair.name_;
            const Value&  value = pair.value_;

            if( name == "id" )
            {
                behaviour_links[i].id= value.get_int();
            }
            else if( name == "id_select" )
            {
                behaviour_links[i].id_select= value.get_int();
            }
            else if( name == "type_num" )
            {
                behaviour_links[i].type_num= value.get_int();
            }
            else if( name == "type" )
            {
                behaviour_links[i].type= value.get_str();
            }
            else if( name == "comp_complexe" )
            {
                behaviour_links[i].comp_complexe= value.get_str();
            }
            else if( name == "coef_frottement" )
            {
                //behaviour_links[i].coef_frottement= value.get_str();
                behaviour_links[i].link_prop[0]=value.get_str();
            }
            else if( name == "Ep" )
            {
                //behaviour_links[i].Ep= value.get_str();
                behaviour_links[i].link_prop[1]=value.get_str();
            }
            else if( name == "jeux" )
            {
                //behaviour_links[i].jeux= value.get_str();
                behaviour_links[i].link_prop[2]=value.get_str();
            }
            else if( name == "R" )
            {
                //behaviour_links[i].R= value.get_str();
                behaviour_links[i].link_prop[3]=value.get_str();
            }
            else if( name == "Lp" )
            {
                //behaviour_links[i].Lp= value.get_str();
                behaviour_links[i].link_prop[4]=value.get_str();
            }
            else if( name == "Dp" )
            {
                //behaviour_links[i].Dp= value.get_str();
                behaviour_links[i].link_prop[5]=value.get_str();
            }
            else if( name == "p" )
            {
                //behaviour_links[i].p= value.get_str();
                behaviour_links[i].link_prop[6]=value.get_str();
            }
            else if( name == "Lr" )
            {
                //behaviour_links[i].Lr= value.get_str();
                behaviour_links[i].link_prop[7]=value.get_str();
            }
            else
            {
                std::cout << "WARNING Champ proprietes_interface non implementee" << std::endl;
            }
        }
    }  
    //Ajout du comportement parfait en fin des groupes d'interface (comportement generique pour toutes les interfaces non assignees
    behaviour_links[gr.size()].type="Parfait";
    behaviour_links[gr.size()].id=-1; 
    behaviour_links[gr.size()].type_num=0; 
    for(int i_prop=0; i_prop < behaviour_links[gr.size()].link_prop.size(); i_prop++){
        behaviour_links[gr.size()].link_prop[i_prop] = "0";
    }
}

void DataUser::read_step_bc_volume(const Object& gr, BasicVec<StepBcVolume> &step){
    for( Object::size_type k = 0; k != gr.size(); ++k )
    {
        const Pair& pair1 = gr[k];
        //const Sc2String& name1  = pair1.name_;
        const Value&  value1 = pair1.value_;
        Object obj=value1.get_obj();
        for( Object::size_type l = 0; l != obj.size(); ++l )
        {
            const Pair& pair = obj[l];
            const Sc2String& name  = pair.name_;
            const Value&  value = pair.value_;
            
            if( name == "pdirection_x" )
            {
                step[k].CLv_step_prop[0]=value.get_str();
            }
            else if( name == "pdirection_y" )
            {
                step[k].CLv_step_prop[1]=value.get_str();
            }
            else if( name == "pdirection_z" )
            {
                step[k].CLv_step_prop[2]=value.get_str();
            }
            else if( name == "point_1_x" )
            {
                step[k].CLv_step_prop[3]=value.get_str();
            }
            else if( name == "point_1_y" )
            {
                step[k].CLv_step_prop[4]=value.get_str();
            }            
            else if( name == "point_1_z" )
            {
                step[k].CLv_step_prop[5]=value.get_str();
            }
            else if( name == "gravity" )
            {
                step[k].CLv_step_prop[6]=value.get_str();
            }
            else if( name == "wrotation" )
            {
                step[k].CLv_step_prop[7]=value.get_str();
            }
        }
    }
}

///lecture des CL volumiques dans un fichier json
void DataUser::read_json_behaviour_bc_volume(const Object& gr){
    for(Object::size_type i=0;i != gr.size() ;i++){
        const Pair& pair1 = gr[i];        
        const Value&  value1 = pair1.value_;
        Object obj=value1.get_obj();
        for( Object::size_type j = 0; j != obj.size(); ++j )
        {
            const Pair& pair = obj[j];
            const Sc2String& name  = pair.name_;
            const Value&  value = pair.value_;

            if( name == "name" )
            {
                behaviour_bc_volume[i].name= value.get_str();
            }
            else if( name == "type" )
            {
                behaviour_bc_volume[i].type = value.get_str() ;
            }
            else if( name == "select" )
            {
                Sc2String temp=value.get_str() ;             
		if(temp == "true"){behaviour_bc_volume[i].select = true;}
		//std::istringstream s(temp);
                //s >> behaviour_bc_volume[i].select;
            }
            else if( name == "ref" )
            {
                behaviour_bc_volume[i].ref = value.get_int();
            }
            else if( name == "step" )
            {
                Object obj2=value.get_obj();
                behaviour_bc_volume[i].step.resize(obj2.size());
                read_step_bc_volume(obj2,behaviour_bc_volume[i].step);
            }
            else
            {
                assert( "Donnee behaviour_bc_volume non implementee" );
            }
        }
    }

}


void DataUser::read_step_bc(const Object& gr, BasicVec<StepBc> &step){
    for( Object::size_type k = 0; k != gr.size(); ++k )
    {
        const Pair& pair1 = gr[k];
        //const Sc2String& name1  = pair1.name_;
        const Value&  value1 = pair1.value_;
        Object obj=value1.get_obj();
        for( Object::size_type l = 0; l != obj.size(); ++l )
        {
            const Pair& pair = obj[l];
            const Sc2String& name  = pair.name_;
            const Value&  value = pair.value_;
            if( name == "fct_spatiale_x" )
            {
                step[k].CL_step_prop[0]=value.get_str();
            }
            else if( name == "fct_spatiale_y" )
            {
                step[k].CL_step_prop[1]=value.get_str();
            }
            else if( name == "fct_spatiale_z" )
            {
                step[k].CL_step_prop[2]=value.get_str();
            }
            else if( name == "fct_temporelle_x" )
            {
                step[k].CL_step_prop[3]=value.get_str();
            }
            else if( name == "fct_temporelle_y" )
            {
                step[k].CL_step_prop[4]=value.get_str();
            }
            else if( name == "fct_temporelle_z" )
            {
                step[k].CL_step_prop[5]=value.get_str();
            }
        }
    }
}
///lecture des CL donnees dans un fichier json
void DataUser::read_json_behaviour_bc(const Object& gr){
    for(Object::size_type i=0;i != gr.size() ;i++){
        //Object obj=pr[i].get_obj();;
    const Pair& pair1 = gr[i];        
        const Value&  value1 = pair1.value_;
    Object obj=value1.get_obj();

        for( Object::size_type j = 0; j != obj.size(); ++j )
        {
            const Pair& pair = obj[j];
            const Sc2String& name  = pair.name_;
            const Value&  value = pair.value_;

            if( name == "id" )
            {
                behaviour_bc[i].id= value.get_int();
            }
            else if( name == "type" )
            {
                behaviour_bc[i].type= value.get_str();
            }
            else if( name == "step" )
            {
                Object obj2=value.get_obj();
                behaviour_bc[i].step.resize(obj2.size());
                read_step_bc(obj2,behaviour_bc[i].step);
            }
            else
            {
                std::cout << "WARNING Champ CL non implementee : " << name << std::endl;
            }        
        }
    }   
    //Ajout d'une CL en effort nul pour les interfaces non assignees sur les cotes
    behaviour_bc[gr.size()].type="effort";
    behaviour_bc[gr.size()].id=-1;
    
    StepBc step_0;
    step_0.CL_step_prop[0] = "0";
    step_0.CL_step_prop[1] = "0";
    step_0.CL_step_prop[2] = "0";
    step_0.CL_step_prop[3] = "1";
    step_0.CL_step_prop[4] = "1";
    step_0.CL_step_prop[5] = "1";

    int nb_step_temp = behaviour_bc[0].step.size();
    behaviour_bc[gr.size()].step.resize(nb_step_temp);
    behaviour_bc[gr.size()].step[0] = step_0;
}


void DataUser::read_step_calcul(const Object& gr){
    for( Object::size_type k = 0; k != gr.size(); ++k )
    {
        const Pair& pair1 = gr[k];
        const Sc2String& name1  = pair1.name_;
        const Value&  value1 = pair1.value_;
        Object obj=value1.get_obj();
        for( Object::size_type l = 0; l != obj.size(); ++l )
        {
            const Pair& pair = obj[l];
            const Sc2String& name  = pair.name_;
            const Value&  value = pair.value_;
            if( name == "PdT" )
            {
                Sc2String temp=value.get_str() ;
                std::istringstream s(temp);
                s >> time_step[k].dt;
            }
            else if( name == "name" )
            {
                time_step[k].name=value.get_str();
            }
            else if( name == "nb_PdT" )
            {
                Sc2String temp=value.get_str() ;
                std::istringstream s(temp);
                s >> time_step[k].nb_time_step;
            }
            else if( name == "Tf" )
            {
                time_step[k].tf=value.get_real();
            }
            else if( name == "Ti" )
            {
                time_step[k].ti=value.get_real();
            }
        }
    }
}

void DataUser::read_multiresolution(const Object& gr){
    for( Object::size_type k = 0; k != gr.size(); ++k )
    {
        const Pair& pair1 = gr[k];
        const Sc2String& name1  = pair1.name_;
        const Value&  value1 = pair1.value_;
        Object obj=value1.get_obj();
        for( Object::size_type l = 0; l != obj.size(); ++l )
        {
            const Pair& pair = obj[l];
            const Sc2String& name  = pair.name_;
            const Value&  value = pair.value_;
            if( name == "name" )
            {
                Multiresolution_parameters[k].name=value.get_str();
            }
            else if( name == "nb_values" )
            {
                Sc2String temp=value.get_str() ;
                std::istringstream s(temp);
                s >> Multiresolution_parameters[k].nb_values;
            }
            else if( name == "min_value" )
            {
                Sc2String temp=value.get_str() ;
                std::istringstream s(temp);
                s >> Multiresolution_parameters[k].min_value;
            }
            else if( name == "max_value" )
            {
                Sc2String temp=value.get_str() ;
                std::istringstream s(temp);
                s >> Multiresolution_parameters[k].max_value;
            }
            else if( name == "nominal_value" )
            {
                Sc2String temp=value.get_str() ;
                std::istringstream s(temp);
                s >> Multiresolution_parameters[k].nominal_value;
                Multiresolution_parameters[k].current_value=Multiresolution_parameters[k].nominal_value;
            }
        }
    }
}

void DataUser::read_json_calcul(){
    std::ifstream is( file_calcul.c_str() );
    Value value_i;

    read( is, value_i );
    const Object& input = value_i.get_obj();
    
    for( Object::size_type i = 0; i != input.size(); ++i )
    {
        const Pair& pair_groups = input[i];
        const Sc2String& name_groups  = pair_groups.name_;
        const Value& value_groups= pair_groups.value_;
        
        if(name_groups=="mesh"){//lecture des donnees de maillage
            const Object obj=value_groups.get_obj();
            for( Object::size_type j = 0; j != obj.size(); ++j ){
                const Pair& pair = obj[j];
                const Sc2String& name  = pair.name_;
                const Value&  value = pair.value_;
                if( name == "model_directory" )     {name_directory=value.get_str();}
                else if( name == "mesh_directory" ) {mesh_directory=value.get_str();}
                else if( name == "mesh_name" )      {name_mesh_user= value.get_str();}
                else if( name == "extension" )      {extension= value.get_str();}
                else if( name == "nb_sst" )         {std::cout << "Nombre de sous-structures     : " <<  value.get_int() << std::endl;}
                else if( name == "nb_inter" )       {std::cout << "Nombre d'interface            : " <<  value.get_int() << std::endl;}
                else if( name == "nb_groups_elem" ) {std::cout << "Nombre de groupe d'elements   : " <<  value.get_int() << std::endl;}
                else if( name == "nb_groups_inter" ){std::cout << "Nombre de groupe d'interfaces : " <<  value.get_int() << std::endl;}
                else{assert( false );}
            }        
        }
        
        if(name_groups=="groups_elem"){//lecture des groupes d'elements
            std::cout << "reading groups_elem " <<  std::endl;
            const Object& gr = value_groups.get_obj();
            group_elements.resize(gr.size());
            read_json_groups_elements(gr);
        }
        
        if(name_groups=="groups_inter"){//lecture des groupes d'interfaces
            std::cout << "reading groups_inter " <<  std::endl;
            const Object& gr = value_groups.get_obj();
            group_interfaces.resize(gr.size());
            read_json_groups_interfaces(gr);
        }
        
        if(name_groups=="groups_edge"){//lecture des groupes de bords
            std::cout << "reading groups_edge " <<  std::endl;
            const Object& gr = value_groups.get_obj();
            group_edges.resize(gr.size()+1);
            read_json_groups_edges( gr);
        }
        
        if(name_groups=="links"){//lecture des proprietes d'interfaces et creation de behaviour_links
            std::cout << "reading links " <<  std::endl;
            const Object& gr = value_groups.get_obj();
            behaviour_links.resize(gr.size()+1);
            read_json_behaviour_interfaces(gr);
        }
        
        if(name_groups=="materials"){//lecture des caracteristiques materiaux et creation de behaviour_materials
            std::cout << "reading materials " <<  std::endl;
            const Object& mat = value_groups.get_obj();
            behaviour_materials.resize(mat.size());
            read_json_behaviour_materials(mat);
        }
        
        if(name_groups=="CL"){//lecture des proprietes d'interfaces et creation de behaviour_links
            std::cout << "reading CL " <<  std::endl;
            const Object& cl = value_groups.get_obj();
            behaviour_bc.resize(cl.size()+1);
            read_json_behaviour_bc(cl);
        }
        if(name_groups=="CLvolume"){//lecture des proprietes d'interfaces et creation de behaviour_links
            std::cout << "reading CLvolume " <<  std::endl;
            const Object& clvol = value_groups.get_obj();
            behaviour_bc_volume.resize(clvol.size());
            read_json_behaviour_bc_volume(clvol);
        }
        if(name_groups=="time_step"){//lecture des proprietes pour les steps temporels
            std::cout << "reading time_step " <<  std::endl;
            const Object& timestep = value_groups.get_obj();
            time_step.resize(timestep.size());
            read_step_calcul(timestep);
        }
        if(name_groups=="multiresolution"){//lecture des proprietes pour les steps temporels
            std::cout << "reading multiresolution " <<  std::endl;
            const Object& multiresolution = value_groups.get_obj();
            Multiresolution_parameters.resize(multiresolution.size());
            read_multiresolution(multiresolution);
        }
        if(name_groups=="options"){//lecture des donnees de maillage
            std::cout << "--------------options--------------" << std::endl;
            const Object obj=value_groups.get_obj();
            for( Object::size_type j = 0; j != obj.size(); ++j ){
                const Pair& pair = obj[j];
                const Sc2String& name  = pair.name_;
                std::cout << name << std::endl;
                const Value&  value = pair.value_;
                if     ( name == "dissipation" )       {Sc2String temp=value.get_str();std::istringstream s(temp); s>>options.dissipation;}
                else if( name == "nb_options" )        {options.nb_option=value.get_int();}
                else if( name == "PREC_nb_niveaux" )   {Sc2String temp=value.get_str();std::istringstream s(temp); s>>options.nb_level;}
                else if( name == "Temp_statique" )     {options.Temp_statique=value.get_str();}
                else if( name == "LATIN_nb_iter" )     {Sc2String temp=value.get_str();std::istringstream s(temp); s>>options.LATIN_nb_iter_max;}
                else if( name == "LATIN_conv" )        {Sc2String temp=value.get_str();std::istringstream s(temp); s>>options.LATIN_crit_error;}
                else if( name == "LATIN_auto_stop" )   {Sc2String temp=value.get_str();std::istringstream s(temp); s>>options.LATIN_crit_error_auto_stop;}
                else if( name == "LATIN_multiechelle" ){Sc2String temp=value.get_str();std::istringstream s(temp); s>>options.multiechelle;}
                else if( name == "trac_ener_imp" )     {Sc2String temp=value.get_str();std::istringstream s(temp); s>>options.trac_ener_imp;}
                else if( name == "trac_ener_diss" )    {Sc2String temp=value.get_str();std::istringstream s(temp); s>>options.trac_ener_diss;}
                else if( name == "2D_resolution" )     {Sc2String temp=value.get_str();std::istringstream s(temp); s>>options.resolution_2D;}
                else if( name == "Multiresolution_on" ){
                    Sc2String temp=value.get_str();
                    if(temp=="off") {options.Multiresolution_on=0;options.Multiresolution_type="none";}
                    else if(temp=="fatigue") {options.Multiresolution_on=1;options.Multiresolution_type="fatigue";}
                    else { std::cout << "type de multiresolution non reconnu, revoir les noms" << std::endl; assert( false );}
                }
/*                else if( name == "Multiresolution_nb_cycle" ){options.Multiresolution_nb_cycle=value.get_int();} */
/*                else if( name == "Multiresolution_type" ){options.Multiresolution_type=value.get_str();} */
                else if( name == "mode" ){options.mode=value.get_str();}
            }   
            std::cout << "------------fin options------------" <<  std::endl;
        }
    }
}

void DataUser::find_Multiresolution_parameters(){
    for(unsigned i_par=0;i_par< Multiresolution_parameters.size() ;i_par++){
        Sc2String var="V"; var<<i_par; //nom de la variable de multiresolution
        //recherche de cette variable dans les materiaux
        for(unsigned j=0;j< behaviour_materials.size() ;j++){
            for(unsigned i_prop=0;i_prop<behaviour_materials[j].mat_prop.size();i_prop++){
                if(behaviour_materials[j].mat_prop[i_prop].find(var) < behaviour_materials[j].mat_prop[i_prop].size()){
                    Multiresolution_parameters[i_par].materials.push_back(j);
                    options.Multiresolution_material_link_CL_CLvolume[0]=1;
                }
            }
        }
        //recherche de cette variable dans les liaisons
        for(unsigned j=0;j< behaviour_links.size() ;j++){
            for(unsigned i_prop=0;i_prop<behaviour_links[j].link_prop.size();i_prop++){
                if(behaviour_links[j].link_prop[i_prop].find(var) < behaviour_links[j].link_prop[i_prop].size()){
                    Multiresolution_parameters[i_par].links.push_back(j);
                    options.Multiresolution_material_link_CL_CLvolume[1]=1;
                }
            }
        }
        //recherche de cette variable dans les CL
        for(unsigned j=0;j< behaviour_bc.size() ;j++){
            for(unsigned i_step=0;i_step<behaviour_bc[j].step.size();i_step++){
                for(unsigned i_prop=0;i_prop<behaviour_bc[j].step[i_step].CL_step_prop.size();i_prop++){
                    if(behaviour_bc[j].step[i_step].CL_step_prop[i_prop].find(var) < behaviour_bc[j].step[i_step].CL_step_prop[i_prop].size()){
                        Multiresolution_parameters[i_par].CL.push_back(j);
                        options.Multiresolution_material_link_CL_CLvolume[2]=1;
                    }
                }
            }
        }       
        //recherche de cette variable dans les CLvolume
        for(unsigned j=0;j< behaviour_bc_volume.size() ;j++){
            for(unsigned i_step=0;i_step<behaviour_bc_volume[j].step.size();i_step++){
                for(unsigned i_prop=0;i_prop<behaviour_bc_volume[j].step[i_step].CLv_step_prop.size();i_prop++){
                    if(behaviour_bc_volume[j].step[i_step].CLv_step_prop[i_prop].find(var) < behaviour_bc_volume[j].step[i_step].CLv_step_prop[i_prop].size()){
                        Multiresolution_parameters[i_par].CLvolume.push_back(j);
                        options.Multiresolution_material_link_CL_CLvolume[3]=1;
                    }
                }
            }
        }     
    }
    PRINT(options.Multiresolution_material_link_CL_CLvolume);
    
}
//*************************************************************************************************************
// assignation des materiaux et des liaisons aux groupes
//*************************************************************************************************************


void DataUser::assign_num_materials_id_group_elements() {
    int nb_materials = behaviour_materials.size();
    num_materials_id_group_elements.resize(nb_materials);
    for(int i_data_group=0; i_data_group<group_elements.size(); i_data_group++){
        for(int i_mat=0; i_mat<behaviour_materials.size(); i_mat++){
            if(group_elements[i_data_group].id_material==behaviour_materials[i_mat].id){
                num_materials_id_group_elements[i_mat].push_back(group_elements[i_data_group].id);
            }
        }
    }
}


void DataUser::assign_num_links_id_group_interfaces() {
    int nb_links = behaviour_links.size();
    num_links_id_group_interfaces.resize(nb_links);
    for(int i_data_group=0; i_data_group<group_interfaces.size(); i_data_group++){
        for(int i_link=0; i_link<behaviour_links.size(); i_link++){
            if(group_interfaces[i_data_group].id_link==behaviour_links[i_link].id){
                num_links_id_group_interfaces[i_link].push_back(group_interfaces[i_data_group].id);
            }
        }
    }
}







//*************************************************************************************************************
// fonction de lecture du fichier de calcul v2
//*************************************************************************************************************

Sc2String to_string(const Sc2String& name, const Value&  value){
    Sc2String data;
    int typeValue = value.type();
    //PRINT(name);
    //PRINT(typeValue);
    if(typeValue == 2) {data = value.get_str() ; if(data == ""){data = "0";}} 
    else if(typeValue == 4) {int temp = value.get_int() ;std::ostringstream oss; oss << temp; data = oss.str();} 
    else if(typeValue == 5) {float temp = value.get_real() ;std::ostringstream oss; oss << temp; data = oss.str();} 
    else if(typeValue == 6) {data = "0";} 
    else {assert( "Value ne peut pas être convertie en String" );}
    //PRINT(data);
    return data;
}


//lecture des groupes d'elements dans un fichier json--------------------------------------
void DataUser::read_json_groups_elements_v2(const Array& gr){
    for(Object::size_type i=0;i != gr.size() ;i++){
        Object obj=gr[i].get_obj();
        for( Object::size_type j = 0; j != obj.size(); ++j )
        {
            const Pair& pair = obj[j];
            const Sc2String& name  = pair.name_;
            const Value&  value = pair.value_;

            if( name == "id" )                  { group_elements[i].id= value.get_int(); }
            else if( name == "origine" )        { group_elements[i].origine = value.get_str() ;}
            else if( name == "identificateur" ) { group_elements[i].num_in_mesh_file = value.get_int() ; }
            else if( name == "name" )           { group_elements[i].name = value.get_str();}
            else if( name == "group" )          {  } //TODO
            else if( name == "assigned" )       {  } //TODO
            else if(name=="material_id")        { group_elements[i].id_material= value.get_int(); }
            else                                { assert( "Donnees groups_elem non implementee" );}
        }
        group_elements[i].affich();
    }
}


///lecture des groupes d'interfaces dans un fichier json
void DataUser::read_json_groups_interfaces_v2( const Array& gr ){
    for(Object::size_type i=0;i != gr.size() ;i++){
        Object obj=gr[i].get_obj();
        for( Object::size_type j = 0; j != obj.size(); ++j )
        {
            const Pair& pair = obj[j];
            const Sc2String& name  = pair.name_;
            const Value&  value = pair.value_;

            if( name == "id" )                  { group_interfaces[i].id= value.get_int(); }
            else if( name == "origine" )        { group_interfaces[i].origine= value.get_str(); }
            else if( name == "name" )           { group_interfaces[i].name= value.get_str();}
            else if( name == "type" )           { group_interfaces[i].type= value.get_str();}
            else if( name == "adj_num_group" ) {
                Sc2String adj=value.get_str();
                std::istringstream s(adj);
                BasicVec<int,2> adjnum;
                for(unsigned k=0;k< 2 ;k++){
                    s>>adjnum[k];
                }
                group_interfaces[i].adj_num_group=adjnum;
            }
            else if( name == "link_id" )        { group_interfaces[i].id_link= value.get_int(); }
            else if( name == "group" )          {  } //TODO
            else if( name == "assigned" )       { group_interfaces[i].assigned= value.get_real(); }
            else                                { assert( "Donnee groups_inter non implementee" );}
        }
        group_interfaces[i].affich();
    }
}

///lecture des groupes de bord dans un fichier json
void DataUser::read_json_groups_edges_v2( const Array& gr){
    for(Object::size_type i=0;i != gr.size() ;i++){
        group_edges[i].geom.points.resize(2);
        for(int k=0; k<2; k++){
            group_edges[i].geom.points[k].resize(DIM);
        }
        Object obj=gr[i].get_obj();
        for( Object::size_type j = 0; j != obj.size(); ++j )
        {

            const Pair& pair = obj[j];
            const Sc2String& name  = pair.name_;
            const Value&  value = pair.value_;
            if( name == "id_in_calcul" )                { group_edges[i].id= value.get_int(); }
            else if( name == "origine" )                { group_edges[i].geom.origine= value.get_str();}
            else if( name == "name" )                   { group_edges[i].name= value.get_str();}
            else if( name == "criteria" )  // type
            {
                Sc2String temp = value.get_str();
                if(temp == "surface") group_edges[i].geom.type= "is_on";
                else if(temp == "volume") group_edges[i].geom.type= "is_in";
                else std::cout << "WARNING Donnee groups_edge criteria non reconnue : " << temp << std::endl;
                
            }
            else if( name == "boundary_condition_id" )  { group_edges[i].id_CL= value.get_int(); }
            else if( name == "to_visualize" )           { group_edges[i].to_visualize= value.get_int(); }
            else if( name == "assigned" )               { group_edges[i].assigned= value.get_real(); }
            else if(name == "direction_x" )
            {
                Sc2String temp=value.get_str();
                std::istringstream s(temp);
                s >> group_edges[i].geom.pdirection[0];
            }
            else if(name == "direction_y" )
            {
                Sc2String temp=value.get_str();
                std::istringstream s(temp);
                s >> group_edges[i].geom.pdirection[1];
            }
#if DIM==3
            else if(name == "direction_z" )
            {
                Sc2String temp=value.get_str();
                std::istringstream s(temp);
                s >> group_edges[i].geom.pdirection[2];
            }
#endif
            else if( name == "geometry" )
            {
                Sc2String temp = value.get_str();
                if(temp == "plan")  group_edges[i].geom.nature= "plan";
                else if(temp == "disc")  group_edges[i].geom.nature= "disc";
                else if(temp == "cylinder")  group_edges[i].geom.nature= "cylinder";
                else if(temp == "sphere")  group_edges[i].geom.nature= "sphere";
                else if(temp == "parameterized")  group_edges[i].geom.nature= "equation";
                else if(temp == "box")  group_edges[i].geom.nature= "box";
                else std::cout << "WARNING Donnee groups_edge geometry non reconnue : " << temp << std::endl;
            }
            else if(name == "radius" )
            {
                Sc2String temp=value.get_str();
                std::istringstream is(temp);
                is >>group_edges[i].geom.radius;
//                 group_edges[i].geom.radius=value.get_real();
            }
            else if(name == "equation" )
            {
                group_edges[i].geom.equation=value.get_str();
            }
            else if(name == "point_1_x" )
            {
                Sc2String temp=value.get_str();
                std::istringstream s(temp);
                s >> group_edges[i].geom.points[0][0];
            }
            else if(name == "point_1_y" )
            {
                Sc2String temp=value.get_str();
                std::istringstream s(temp);
                s >> group_edges[i].geom.points[0][1];
            }
#if DIM==3
            else if(name == "point_1_z" )
            {
                Sc2String temp=value.get_str();
                std::istringstream s(temp);
                s >> group_edges[i].geom.points[0][2];                
            }
#endif
            else if(name == "point_2_x" )
            {
                Sc2String temp=value.get_str();
                std::istringstream s(temp);
                s >> group_edges[i].geom.points[1][0];
            }
            else if(name == "point_2_y" )
            {
                Sc2String temp=value.get_str();
                std::istringstream s(temp);
                s >> group_edges[i].geom.points[1][1];
            }
#if DIM==3
            else if(name == "point_2_z" )
            {
                Sc2String temp=value.get_str();
                std::istringstream s(temp);
                s >> group_edges[i].geom.points[1][2];
            }
#endif
            else
            {
                std::cout << "WARNING Donnee groups_edge non implementee : " << name << std::endl;
            }
        }
        group_edges[i].affich();
        
    }
    //Ajout du groupe en fin des groupes d'edge (comportement generique pour tous les edges non assignees
    group_edges[gr.size()].id=-1;
    group_edges[gr.size()].geom.type="all";
    group_edges[gr.size()].id_CL=-1; 
    

}

///lecture des proprietes materiaux donnees dans un fichier json
void DataUser::read_json_behaviour_materials_v2(const Array& gr){
    for(Object::size_type i=0;i != gr.size() ;i++){
        Object obj=gr[i].get_obj();  
        for( Object::size_type j = 0; j != obj.size(); ++j ){
            const Pair& pair = obj[j];
            const Sc2String& name  = pair.name_;
            const Value&  value = pair.value_;
            
            if( name == "id_in_calcul" )        { behaviour_materials[i].id= value.get_int(); }
            else if( name == "mtype" )          { behaviour_materials[i].type= to_string(name, value);}
            else if( name == "type_num" )       { behaviour_materials[i].type_num= value.get_int();}
            else if( name == "comp" )           { behaviour_materials[i].comp=       to_string(name, value);}
            else if( name == "type_plast" )     { behaviour_materials[i].type_plast= to_string(name, value);}
            else if( name == "type_endo" )      { behaviour_materials[i].type_endo=  to_string(name, value);}
            else if( name == "resolution" )     { behaviour_materials[i].resolution= to_string(name, value);}
            else if( name == "elastic_modulus" ){ behaviour_materials[i].mat_prop[0]=to_string(name, value);}
            else if( name == "poisson_ratio" )  { behaviour_materials[i].mat_prop[1]=to_string(name, value);}
            else if( name == "alpha" )          { behaviour_materials[i].mat_prop[2]=to_string(name, value);}
            else if( name == "rho" )            { behaviour_materials[i].mat_prop[3]=to_string(name, value);}
            
            else if( name == "viscosite" )      { behaviour_materials[i].mat_prop[4]=to_string(name, value);}
            else if( name == "dir_1_x" )        { behaviour_materials[i].mat_prop[5]=to_string(name, value);}
            else if( name == "dir_1_y" )        { behaviour_materials[i].mat_prop[6]=to_string(name, value);}
            else if( name == "dir_2_x" )        { behaviour_materials[i].mat_prop[8]=to_string(name, value);}
            else if( name == "dir_2_y" )        { behaviour_materials[i].mat_prop[9]=to_string(name, value);}
            else if( name == "dir_3_x" )        { behaviour_materials[i].mat_prop[11]=to_string(name, value);}
            else if( name == "dir_3_y" )        { behaviour_materials[i].mat_prop[12]=to_string(name, value);}
            else if( name == "E_1" )            { behaviour_materials[i].mat_prop[14]=to_string(name, value); behaviour_materials[i].mat_prop[0]=to_string(name, value);}
            else if( name == "E_2" )            { behaviour_materials[i].mat_prop[15]=to_string(name, value);}
            else if( name == "E_3" )            { behaviour_materials[i].mat_prop[16]=to_string(name, value);}
            else if( name == "cis_1" )          { behaviour_materials[i].mat_prop[17]=to_string(name, value);}
            else if( name == "cis_2" )          { behaviour_materials[i].mat_prop[18]=to_string(name, value);}
            else if( name == "cis_3" )          { behaviour_materials[i].mat_prop[19]=to_string(name, value);}
            else if( name == "nu_12" )          { behaviour_materials[i].mat_prop[20]=to_string(name, value); behaviour_materials[i].mat_prop[1]=to_string(name, value);}
            else if( name == "nu_23" )          { behaviour_materials[i].mat_prop[21]=to_string(name, value);}
            else if( name == "nu_13" )          { behaviour_materials[i].mat_prop[22]=to_string(name, value);}
            else if( name == "alpha_1" )        { behaviour_materials[i].mat_prop[23]=to_string(name, value); behaviour_materials[i].mat_prop[2]=to_string(name, value);}
            else if( name == "alpha_2" )        { behaviour_materials[i].mat_prop[24]=to_string(name, value);}
            else if( name == "alpha_3" )        { behaviour_materials[i].mat_prop[25]=to_string(name, value);}
            
            else if( name == "R0" )             { behaviour_materials[i].mat_prop[26]=to_string(name, value);}
            else if( name == "k_p" )            { behaviour_materials[i].mat_prop[27]=to_string(name, value);}
            else if( name == "m_p" )            { behaviour_materials[i].mat_prop[28]=to_string(name, value);}
            else if( name == "coeff_plast_cinematique" ){ behaviour_materials[i].mat_prop[29]=to_string(name, value);}
            
            else if( name == "Yo" )             { behaviour_materials[i].mat_prop[30]=to_string(name, value);}
            else if( name == "Yc" )             { behaviour_materials[i].mat_prop[31]=to_string(name, value);}
            else if( name == "Ycf" )            { behaviour_materials[i].mat_prop[32]=to_string(name, value);}
            else if( name == "dmax" )           { behaviour_materials[i].mat_prop[33]=to_string(name, value);}
            else if( name == "b_c" )            { behaviour_materials[i].mat_prop[34]=to_string(name, value);}
            else if( name == "effet_retard" )   { behaviour_materials[i].mat_prop[35]=to_string(name, value);}
            else if( name == "a" )              { behaviour_materials[i].mat_prop[36]=to_string(name, value);}
            else if( name == "tau_c" )          { behaviour_materials[i].mat_prop[37]=to_string(name, value);}
            else if( name == "couplage")        { behaviour_materials[i].mat_prop[38]=to_string(name, value);}
            
#if DIM==3
            else if( name == "dir_1_z" )        { behaviour_materials[i].mat_prop[7]=to_string(name, value);}
            else if( name == "dir_2_z" )        { behaviour_materials[i].mat_prop[10]=to_string(name, value);}
            else if( name == "dir_3_z" )        { behaviour_materials[i].mat_prop[13]=to_string(name, value);}
#endif
        
            else {  std::cerr << "WARNING Donnee materials non implementee : " << name << std::endl;}
        }
    }
}

///Lecture des proprietes des interfaces donnees dans un fichier json
void DataUser::read_json_behaviour_interfaces_v2(const Array& gr){
    for(Object::size_type i=0;i != gr.size() ;i++){
        Object obj=gr[i].get_obj();
        for( Object::size_type j = 0; j != obj.size(); ++j )
        {
            const Pair& pair = obj[j];
            const Sc2String& name  = pair.name_;
            const Value&  value = pair.value_;

            if( name == "id_in_calcul" )        { behaviour_links[i].id= value.get_int(); }
            //else if( name == "id_select" )      { behaviour_links[i].id_select= value.get_int(); }
            else if( name == "type_num" )       { behaviour_links[i].type_num= value.get_int();  }
            else if( name == "comp_generique" ) { behaviour_links[i].type= to_string(name, value); }
            else if( name == "comp_complexe" )  { behaviour_links[i].comp_complexe= to_string(name, value); }
            else if( name == "f" )              { behaviour_links[i].link_prop[0]=to_string(name, value); }
            else if( name == "Ep" )             { behaviour_links[i].link_prop[1]=to_string(name, value); }
            else if( name == "jeu" )            { behaviour_links[i].link_prop[2]=to_string(name, value); }
            else if( name == "R" )              { behaviour_links[i].link_prop[3]=to_string(name, value); }
            else if( name == "Lp" )             { behaviour_links[i].link_prop[4]=to_string(name, value); }
            else if( name == "Dp" )             { behaviour_links[i].link_prop[5]=to_string(name, value); }
            else if( name == "p" )              { behaviour_links[i].link_prop[6]=to_string(name, value); }
            else if( name == "Lr" )             { behaviour_links[i].link_prop[7]=to_string(name, value); }
            else { std::cout << "WARNING Champ proprietes_interface non implementee : " << name << std::endl; }
        }
    }  
    //Ajout du comportement parfait en fin des groupes d'interface (comportement generique pour toutes les interfaces non assignees
    behaviour_links[gr.size()].type="Parfait";
    behaviour_links[gr.size()].id=-1; 
    behaviour_links[gr.size()].type_num=0; 
    for(int i_prop=0; i_prop < behaviour_links[gr.size()].link_prop.size(); i_prop++){
        behaviour_links[gr.size()].link_prop[i_prop] = "0";
    }
}

void DataUser::read_step_bc_volume_v2(const Object& gr, BasicVec<StepBcVolume> &step){
    for( Object::size_type k = 0; k != gr.size(); ++k )
    {
        const Pair& pair1 = gr[k];
        //const Sc2String& name1  = pair1.name_;
        const Value&  value1 = pair1.value_;
        Object obj=value1.get_obj();
        for( Object::size_type l = 0; l != obj.size(); ++l )
        {
            const Pair& pair = obj[l];
            const Sc2String& name  = pair.name_;
            const Value&  value = pair.value_;
            
            if( name == "pdirection_x" )        { step[k].CLv_step_prop[0]=value.get_str();}
            else if( name == "pdirection_y" )   { step[k].CLv_step_prop[1]=value.get_str();}
            else if( name == "pdirection_z" )   { step[k].CLv_step_prop[2]=value.get_str();}
            else if( name == "point_1_x" )      { step[k].CLv_step_prop[3]=value.get_str();}
            else if( name == "point_1_y" )      { step[k].CLv_step_prop[4]=value.get_str();}            
            else if( name == "point_1_z" )      { step[k].CLv_step_prop[5]=value.get_str();}
            else if( name == "gravity" )        { step[k].CLv_step_prop[6]=value.get_str();}
            else if( name == "wrotation" )      { step[k].CLv_step_prop[7]=value.get_str();}
        }
    }
}

///lecture des CL volumiques dans un fichier json
void DataUser::read_json_behaviour_bc_volume_v2(const Array& gr){
    for(Object::size_type i=0;i != gr.size() ;i++){
        Object obj=gr[i].get_obj();
        
        //initialisation du pas de temps
        StepBcVolume step_0;
        for( Object::size_type j = 0; j != obj.size(); ++j ){
            const Pair& pair = obj[j];
            const Sc2String& name  = pair.name_;
            const Value&  value = pair.value_;
            
            
            if( name == "name" )        {behaviour_bc_volume[i].name = to_string(name, value);}
            else if( name == "type" )   {behaviour_bc_volume[i].type = to_string(name, value);}
            else if( name == "ref" )    {behaviour_bc_volume[i].ref = value.get_int(); }
            else if( name == "dx" )     {step_0.CLv_step_prop[0]=to_string(name, value); }
            else if( name == "dy" )     {step_0.CLv_step_prop[1]=to_string(name, value); }
            else if( name == "dz" )     {step_0.CLv_step_prop[2]=to_string(name, value); }
            else if( name == "gamma" )  {step_0.CLv_step_prop[6]=to_string(name, value); }
            else                        {assert( "Donnee behaviour_bc_volume non implementee" );}
        }
        behaviour_bc_volume[i].select = true;
        behaviour_bc_volume[i].step.resize(time_step.size());
        for(int k=0; k<time_step.size(); k++){
           behaviour_bc_volume[i].step[k] = step_0;
        }
        //read_step_bc_volume(obj2,behaviour_bc_volume[i].step); 
        behaviour_bc_volume[i].affich();
    }

}


void DataUser::read_step_bc_v2(const Array& gr, BasicVec<StepBc> &step){
    for( Object::size_type k = 0; k != gr.size(); ++k ){
        Object obj=gr[k].get_obj();
        for( Object::size_type l = 0; l != obj.size(); ++l ){
            const Pair& pair = obj[l];
            const Sc2String& name  = pair.name_;
            const Value&  value = pair.value_;
            if( name == "spatial_function_x" )          { step[k].CL_step_prop[0]=to_string(name, value);}
            else if( name == "spatial_function_y" )     { step[k].CL_step_prop[1]=to_string(name, value);}
            else if( name == "spatial_function_z" )     { step[k].CL_step_prop[2]=to_string(name, value);}
            else if( name == "temporal_function_t" )    { step[k].CL_step_prop[3]=to_string(name, value);}
        }
    }
}
///lecture des CL donnees dans un fichier json
void DataUser::read_json_behaviour_bc_v2(const Array& gr){
    for(Object::size_type i=0;i != gr.size() ;i++){
        Object obj=gr[i].get_obj();
        behaviour_bc[i].step.resize(time_step.size());
        for( Object::size_type j = 0; j != obj.size(); ++j )
        {
            const Pair& pair = obj[j];
            const Sc2String& name  = pair.name_;
            const Value&  value = pair.value_;

            if( name == "id_in_calcul" )        { behaviour_bc[i].id= value.get_int(); }
            else if( name == "condition_type" ) { behaviour_bc[i].type= to_string(name, value);}
            else if( name == "stepFunctions" ){
                Array obj2=value.get_array();
                read_step_bc_v2(obj2,behaviour_bc[i].step);
            }
            else{std::cout << "WARNING Champ CL non implementee : " << name << std::endl;}        
        }
        behaviour_bc[i].affich();
    }   
    //Ajout d'une CL en effort nul pour les interfaces non assignees sur les cotes
    behaviour_bc[gr.size()].type="effort";
    behaviour_bc[gr.size()].id=-1;
    
//     StepBc step_0;
//     step_0.CL_step_prop[0] = "0";
//     step_0.CL_step_prop[1] = "0";
//     step_0.CL_step_prop[2] = "0";
//     step_0.CL_step_prop[3] = "1";
//     step_0.CL_step_prop[4] = "1";
//     step_0.CL_step_prop[5] = "1";

    int nb_step_temp = time_step.size();
    behaviour_bc[gr.size()].step.resize(nb_step_temp);
    //behaviour_bc[gr.size()].step[0] = step_0;
    behaviour_bc[gr.size()].affich();
}


void DataUser::read_step_calcul_v2(const Array& gr){
    for( Object::size_type k = 0; k != gr.size(); ++k )
    {
        Object obj=gr[k].get_obj();
        for( Object::size_type l = 0; l != obj.size(); ++l )
        {
            const Pair& pair = obj[l];
            const Sc2String& name  = pair.name_;
            const Value&  value = pair.value_;
            if( name == "time_step" )           { time_step[k].dt=value.get_real();}
            else if( name == "name" )           { time_step[k].name=value.get_str(); }
            else if( name == "nb_time_steps" )  { time_step[k].nb_time_step=value.get_real(); }
            else if( name == "final_time" )     { time_step[k].tf=value.get_real();}
            else if( name == "initial_time" )   { time_step[k].ti=value.get_real();}
        }
        time_step[k].affich();
    }
}

void DataUser::read_multiresolution_v2(const Array& gr){
    for( Object::size_type k = 0; k != gr.size(); ++k )
    {
        Object obj=gr[k].get_obj();
        for( Object::size_type l = 0; l != obj.size(); ++l )
        {
            const Pair& pair = obj[l];
            const Sc2String& name  = pair.name_;
            const Value&  value = pair.value_;
            if( name == "name" ){ Multiresolution_parameters[k].name=value.get_str();}
            else if( name == "nb_values" ){
                Sc2String temp=value.get_str() ;
                std::istringstream s(temp);
                s >> Multiresolution_parameters[k].nb_values;
            }
            else if( name == "min_value" ){
                Sc2String temp=value.get_str() ;
                std::istringstream s(temp);
                s >> Multiresolution_parameters[k].min_value;
            }
            else if( name == "max_value" ){
                Sc2String temp=value.get_str() ;
                std::istringstream s(temp);
                s >> Multiresolution_parameters[k].max_value;
            }
            else if( name == "nominal_value" ){
                Sc2String temp=value.get_str() ;
                std::istringstream s(temp);
                s >> Multiresolution_parameters[k].nominal_value;
                Multiresolution_parameters[k].current_value=Multiresolution_parameters[k].nominal_value;
            }
        }
    }
}

void DataUser::read_json_calcul_v2(){
    PRINT(file_calcul_v2);
    std::ifstream is( file_calcul_v2.c_str() );
    Value value_i;

    read( is, value_i );
    const Object& input = value_i.get_obj();
    
    // informations sur le maillage
    for( Object::size_type i = 0; i != input.size(); ++i )
    {
        const Pair& pair_groups = input[i];
        const Sc2String& name_groups  = pair_groups.name_;
        const Value& value_groups= pair_groups.value_;
        
        PRINT(name_groups);
        
        if(name_groups=="mesh"){
            const Object obj=value_groups.get_obj();
            for( Object::size_type j = 0; j != obj.size(); ++j ){
                const Pair& pair = obj[j];
                const Sc2String& name  = pair.name_;
                const Value&  value = pair.value_;
                if( name == "model_directory" )     {name_directory=value.get_str();}
                else if( name == "mesh_directory" ) {mesh_directory=value.get_str();}
                else if( name == "mesh_name" )      {name_mesh_user= value.get_str();}
                else if( name == "extension" )      {extension= value.get_str();}
                else if( name == "nb_ddl" )         {nb_ddl=value.get_int();}
                else if( name == "nb_sst" )         {nb_sst=value.get_int();}
                else if( name == "nb_inter" )       {nb_inter=value.get_int();}
                else if( name == "nb_groups_elem" ) {nb_groups_elem=value.get_int();}
                else if( name == "nb_groups_inter" ){nb_groups_inter=value.get_int();}
                else{std::cout << name ; assert( false );}
            }        
        }
        
    }
    
    // lecture des step temporels, de la multirésolution et des options de calcul en premier
    for( Object::size_type i = 0; i != input.size(); ++i )
    {
        const Pair& pair_groups = input[i];
        const Sc2String& name_groups  = pair_groups.name_;
        const Value& value_groups= pair_groups.value_;
        
        PRINT(name_groups);
        // informations sur le maillage
        if(name_groups=="options"){//lecture des donnees de maillage
            std::cout << "--------------options--------------" << std::endl;
            const Object obj=value_groups.get_obj();
            for( Object::size_type j = 0; j != obj.size(); ++j ){
                const Pair& pair = obj[j];
                const Sc2String& name  = pair.name_;
                std::cout << name << std::endl;
                const Value&  value = pair.value_;
                if( name == "convergence_method_LATIN" ){
                    const Object& conv = value.get_obj();
                    for( Object::size_type k = 0; k != conv.size(); ++k ){
                        const Pair& conv_pair = conv[k];
                        const Sc2String& conv_name  = conv_pair.name_;
                        PRINT(conv_name);
                        const Value&  conv_value = conv_pair.value_;
                        if(conv_name == "convergence_rate" )    {Sc2String temp=conv_value.get_str();std::istringstream s(temp); s>>options.LATIN_crit_error;}
                        else if(conv_name == "max_iteration" )  {Sc2String temp=conv_value.get_str();std::istringstream s(temp); s>>options.LATIN_nb_iter_max;}
                        else if(conv_name == "multiscale" )     {Sc2String temp=conv_value.get_str();PRINT(temp);std::istringstream s(temp); s>>options.multiechelle;}
                    }
                }
                else if( name == "mode" )                       {options.mode = to_string(name, value);}
            }  
            if(nb_groups_inter > 3){ options.multiechelle = true;}
            else{ options.multiechelle = false;}
            options.affich();
        }
        if(name_groups=="time_steps"){//lecture des proprietes pour les steps temporels
            std::cout << "reading time_steps " <<  std::endl;
            const Object obj=value_groups.get_obj();
            for( Object::size_type j = 0; j != obj.size(); ++j ){
                const Pair& pair = obj[j];
                const Sc2String& name  = pair.name_;
                std::cout << name << std::endl;
                if( name == "time_scheme" )  { 
                  const Value&  value = pair.value_; 
                  options.Temp_statique=value.get_str();
                }else if( name == "collection" ) {
                  const Array& timestep = pair.value_.get_array();
                  time_step.resize(timestep.size());
                  PRINT(time_step.size());
                  read_step_calcul_v2(timestep);
                }
            }
        }
        if(name_groups=="multiresolution_parameters"){//lecture des proprietes pour les steps de multiresolution TODO
            std::cout << "reading multiresolution " <<  std::endl;
            const Object obj=value_groups.get_obj();
            for( Object::size_type j = 0; j != obj.size(); ++j ){
                const Pair& pair = obj[j];
                const Sc2String& name  = pair.name_;
                std::cout << name << std::endl;
                if( name == "multiresolution_type" )  { 
                    const Value&  value = pair.value_; 
                    Sc2String temp=value.get_str();
                    if(temp=="off")             {options.Multiresolution_on=0; options.Multiresolution_type="none";}
                    else if(temp=="fatigue")    {options.Multiresolution_on=1; options.Multiresolution_type="fatigue";}
                    else                        { std::cout << "type de multiresolution non reconnu, revoir les noms" << std::endl; assert( false );}
                }else if( name == "collection" ) {
                    const Array& multiresolution = pair.value_.get_array();
                    Multiresolution_parameters.resize(multiresolution.size());
                    PRINT(Multiresolution_parameters.size());
                    read_multiresolution_v2(multiresolution);
                }
            }
        }
    }
    
    for( Object::size_type i = 0; i != input.size(); ++i )
    {
        const Pair& pair_groups = input[i];
        const Sc2String& name_groups  = pair_groups.name_;
        const Value& value_groups= pair_groups.value_;
        
        PRINT(name_groups);
        
        if(name_groups=="pieces"){//lecture des groupes d'elements
            std::cout << "reading groups_elem " <<  std::endl;
            const Array& gr = value_groups.get_array();
            group_elements.resize(gr.size());
            read_json_groups_elements_v2(gr);
        }
        
        if(name_groups=="interfaces"){//lecture des groupes d'interfaces
            std::cout << "reading groups_inter " <<  std::endl;
            const Array& gr = value_groups.get_array();
            group_interfaces.resize(gr.size());
            read_json_groups_interfaces_v2(gr);
        }
        
        if(name_groups=="edges"){//lecture des groupes de bords
            std::cout << "reading groups_edge " <<  std::endl;
            const Array& gr = value_groups.get_array();
            group_edges.resize(gr.size()+1);
            PRINT(group_edges.size());
            read_json_groups_edges_v2( gr);
        }
        
        if(name_groups=="links"){//lecture des proprietes d'interfaces et creation de behaviour_links
            std::cout << "reading links " <<  std::endl;
            const Array& gr = value_groups.get_array();
            behaviour_links.resize(gr.size()+1);
            read_json_behaviour_interfaces_v2(gr);
        }
        
        if(name_groups=="materials"){//lecture des caracteristiques materiaux et creation de behaviour_materials
            std::cout << "reading materials " <<  std::endl;
            const Array& mat = value_groups.get_array();
            behaviour_materials.resize(mat.size());
            read_json_behaviour_materials_v2(mat);
        }
        
        if(name_groups=="boundary_condition"){//lecture des proprietes d'interfaces et creation de behaviour_links
            std::cout << "reading CL " <<  std::endl;
            const Array& cl = value_groups.get_array();
            behaviour_bc.resize(cl.size()+1);
            read_json_behaviour_bc_v2(cl);
        }
        if(name_groups=="volumic_forces"){//lecture des proprietes d'interfaces et creation de behaviour_links
            std::cout << "reading CLvolume " <<  std::endl;
            const Array& clvol = value_groups.get_array();
            behaviour_bc_volume.resize(clvol.size());
            read_json_behaviour_bc_volume_v2(clvol);
        }  
    }
}













//*************************************************************************************************************
// fonction de generation de .cpp à compiler à la volée pour la lecture de paramètres matériaux
//*************************************************************************************************************

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
