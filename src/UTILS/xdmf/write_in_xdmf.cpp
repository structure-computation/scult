//
// C++ Implementation: write_in_xdmf
//
// Description: 
//
//
// Author: David Violeau <dvioleau@structure-computation.com>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include <Metil/Hdf.h>

using namespace Metil;
#include "struct_geometry_hdf.h"
#include "utils.h"
#include "DATA_USER.h"
#include "LEVEL.h"

#include "write_geometry_xdmf_hdf5.h"
#include "write_geometry_behaviour_xdmf_hdf5.h"

//gpu
//ecriture de la geometrie
void LEVEL::write_geometry_xdmf(DATA_USER &data_user, String type){
    
    string name_hdf =data_user.name_directory + "/MESH/geometry.h5";
    if(FileExists(name_hdf.c_str())==0){ std::cerr << "Le fichier hdf5 n'est pas crée : impossible de créer le fichier xdmf";}

    //ecriture du fichier xdmf pour visualisation par paraview
    string name_xdmf=data_user.name_directory+"/MESH/geometry.xdmf";
#if DIM==2
    std::cout << "sortie xdmf non ecrite pour la dimension 2" << endl;
#else
    if(type=="all"){ //ecriture dans un meme fichier des elements_0 (pieces) et des elements_1 (interfaces)
        write_xdmf_geom_pattern_3(name_xdmf, name_hdf,Geometry, num_level);
    }
#endif
}

void LEVEL::write_geometry_behaviour_xdmf(DATA_USER &data_user, String type){
    
    String name_hdf;
    name_hdf << data_user.name_directory.c_str() <<  "/calcul_"<< data_user.id_calcul.c_str() << "/geometry_behaviour.h5";
    if(FileExists(name_hdf.c_str())==0){ std::cerr << "Le fichier hdf5 n'est pas crée : impossible de créer le fichier xdmf";}

    //ecriture du fichier xdmf pour visualisation par paraview
    String name_xdmf;
    name_xdmf << data_user.name_directory.c_str() <<  "/calcul_"<< data_user.id_calcul.c_str() << "/geometry_behaviour.xdmf";
    
    //correspondance entre les noms des comportements et un numéro d'affichage sous xdmf;
    name_behaviour_elements_1["Perfect"]=0;
    name_behaviour_elements_1["Effort_nul"]=1;  
    name_behaviour_elements_1["Imposed_Effort"]=2;  
    name_behaviour_elements_1["Imposed_Displacement"]=3;  
    name_behaviour_elements_1["Contact"]=4;  
    name_behaviour_elements_1["Symetry"]=5;  
    name_behaviour_elements_1["Gap"]=6;  
    name_behaviour_elements_1["Imposed_Normal_Displacement"]=7;
    
    name_behaviour_elements_0["isotrope elastique"]=0;
    name_behaviour_elements_0["orthotrope elastique"]=1;
    
    //pour les pieces on visualise le numéro du materiau et non pas le type.
//     for(unsigned i=0;i<Geometry.nb_list_elements_0; i++){
//         Geometry.elements_0.num_behaviour[i]=name_behaviour_elements_0[Geometry.elements_0.behaviour[i]];
//     }

    //pour les interfaces on visualise le type et non pas le numéro (qui n'est pas assigné avant)
    Geometry.elements_1_edge.num_behaviour.resize(Geometry.elements_1_edge.behaviour.size());
    for(unsigned i=0;i<Geometry.nb_list_elements_1_edge; i++){
        Geometry.elements_1_edge.num_behaviour[i]=name_behaviour_elements_1[Geometry.elements_1_edge.behaviour[i]];;   
    }
    Geometry.elements_1_interior.num_behaviour.resize(Geometry.elements_1_interior.behaviour.size());
    for(unsigned i=0;i<Geometry.nb_list_elements_1_interior; i++){
        Geometry.elements_1_interior.num_behaviour[i]=name_behaviour_elements_1[Geometry.elements_1_interior.behaviour[i]];;   
    }
    Geometry.elements_1_link.num_behaviour.resize(Geometry.elements_1_link.behaviour.size());
    for(unsigned i=0;i<Geometry.nb_list_elements_1_link; i++){
        Geometry.elements_1_link.num_behaviour[i]=name_behaviour_elements_1[Geometry.elements_1_link.behaviour[i]];;   
    }


    
#if DIM==2
    std::cout << "sortie xdmf non ecrite pour la dimension 2" << endl;
#else
    if(type=="all"){ //ecriture dans un meme fichier des elements_0 (pieces) et des elements_1 (interfaces)
        write_xdmf_geom_behaviour_pattern_3(name_xdmf, name_hdf,Geometry, num_level);
    }
#endif
}



void write_xdmf_from_hdf5(String output_xdmf, String input_hdf5, String name_geometry, int skin, String name_fields, BasicVec<String> attributs=("none"))
{
    std::ofstream f(output_xdmf.c_str());
    String  name_nodes;
    name_nodes << name_geometry << "/nodes" ;
    Hdf hdf(input_hdf5.c_str());
    int nb_nodes;
    String data_node_x=name_nodes+"/x";
    hdf.read_size(data_node_x,nb_nodes);
    f << "<Xdmf Version=\"2.0\">" << endl; 
    f << "  <Domain>" << endl;
    //ecriture des donnees de noeuds
    f <<"           <DataItem Name=\"X\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " 1 \">" << input_hdf5.c_str() <<":"<< name_geometry.c_str() << "/nodes/x </DataItem>" << endl;
    f <<"           <DataItem Name=\"Y\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " 1 \">" << input_hdf5.c_str() <<":"<< name_geometry.c_str() << "/nodes/y </DataItem>" << endl;
#if DIM==3
    f <<"           <DataItem Name=\"Z\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " 1 \">" << input_hdf5.c_str() <<":"<< name_geometry.c_str() << "/nodes/z </DataItem>" << endl;
#endif
    

    //ecriture des donnees de connectivites des elements_0 et elements_1 : necessite les tags nb_list pour les groupes elements_0 et _1, ainsi que nb_elements, base pour les listes de connectivites
    for(unsigned el=skin;el<2;el++){
        int nb_list;
        String name_elements_el;
        name_elements_el<<name_geometry<<"/elements_"<<el;
        hdf.read_group_size(name_elements_el,nb_list);
        for(unsigned i=0; i< nb_list; i++){
            String name_list;
            name_list << name_elements_el <<"/list_" <<  i;
            String name_list_c0=name_list+"/c0";
            int nb_elems;
            hdf.read_size(name_list_c0,nb_elems);
            int nb_nodes_elem;
            String name_element;
            hdf.read_tag(name_list,"base",name_element,1);
            if(name_element=="Bar"){nb_nodes_elem=2;}
            else if(name_element=="Triangle"){nb_nodes_elem=3;}
            else if(name_element=="Tetra"){nb_nodes_elem=4;}
            else {std::cerr << "Type d'element enfant non implementé" ; assert(0);}
            for(unsigned j=0;j<nb_nodes_elem ; j++){
                String name_data_item;
                name_data_item << "elements_"<<el<<"_list_" << i << "_c" << j;
                String data_item;
                data_item << name_list << "/c" <<j ;
                f <<"           <DataItem Name=\"" << name_data_item.c_str() << "\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_elems << " 1\">" <<  input_hdf5.c_str() <<":"<< data_item.c_str() <<" </DataItem>" << endl;
            }
        }
    }
 
 //Attributs
 for(unsigned attr=0;attr<attributs.size();attr++){
     if(attributs[attr]=="all"){
f <<"           <DataItem Name=\"dx\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " 1 \">" << input_hdf5.c_str() <<":"<< name_fields.c_str() <<"/displacements/x </DataItem>" << endl;
f <<"           <DataItem Name=\"dy\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " 1 \">" << input_hdf5.c_str() <<":"<<  name_fields.c_str() <<"/displacements/y </DataItem>" << endl;
#if DIM==3
f <<"           <DataItem Name=\"dz\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " 1 \">" << input_hdf5.c_str() <<":"<<  name_fields.c_str() <<"/displacements/z </DataItem>" << endl;
#endif
/*f <<"           <DataItem Name=\"sxx\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/sigma/xx </DataItem>" << endl;
f <<"           <DataItem Name=\"syy\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/sigma/yy </DataItem>" << endl;
f <<"           <DataItem Name=\"szz\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/sigma/zz </DataItem>" << endl;
f <<"           <DataItem Name=\"sxy\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/sigma/xy </DataItem>" << endl;
f <<"           <DataItem Name=\"sxz\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/sigma/xz </DataItem>" << endl;
f <<"           <DataItem Name=\"syz\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/sigma/yz </DataItem>" << endl;
f <<"           <DataItem Name=\"smises\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/sigma_von_mises </DataItem>" << endl;
f <<"           <DataItem Name=\"exx\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/epsilon/xx </DataItem>" << endl;
f <<"           <DataItem Name=\"eyy\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/epsilon/yy </DataItem>" << endl;
f <<"           <DataItem Name=\"ezz\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/epsilon/zz </DataItem>" << endl;
f <<"           <DataItem Name=\"exy\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/epsilon/xy </DataItem>" << endl;
f <<"           <DataItem Name=\"exz\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/epsilon/xz </DataItem>" << endl;
f <<"           <DataItem Name=\"eyz\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/epsilon/yz </DataItem>" << endl;*/
    }
 }

 
    //ecriture de la geometrie_0 (elements parents) et geometrie_1 (elements enfants)
    for(unsigned el=skin;el<2;el++){
        f<< "           <Grid Name=\"Geometry_"<<el<<"\" GridType=\"Tree\">" << endl;
        int nb_list;
        String name_elements_el;
        name_elements_el<<name_geometry<<"/elements_"<<el;
        hdf.read_group_size(name_elements_el,nb_list);   
        for(unsigned i=0; i< nb_list; i++){
            String name_list;
            name_list << name_elements_el <<  "/list_" <<  i;        
            String name_list_c0=name_list+"/c0";
            int nb_elems;
            hdf.read_size(name_list_c0,nb_elems);
            int nb_nodes_elem;
            String name_element;
            hdf.read_tag(name_list,"base",name_element);
            String JOIN, name_element_xdmf;
            if(name_element=="Bar"){nb_nodes_elem=2; JOIN="JOIN($0 , $1 )"; name_element_xdmf="Bar"; }
            else if(name_element=="Triangle"){nb_nodes_elem=3;JOIN="JOIN($0 , $1 , $2  )";name_element_xdmf="Triangle";}
            else if(name_element=="Tetra"){nb_nodes_elem=4;JOIN="JOIN($0 , $1 , $2  , $3)";name_element_xdmf="Tetrahedron";}
            else {std::cerr << "Type d'element enfant non implementé" ; assert(0);}        
            f<<"                    <Grid Name=\"list_"<< i <<"\">" << endl;
            f<<"                            <Topology Type=\""<<name_element_xdmf.c_str()<<"\" NumberOfElements=\" "<< nb_elems << " \" >" << endl;
            f<<"                                    <DataItem Dimensions=\" "<< nb_elems << "  " << nb_nodes_elem <<" \" ItemType=\"Function\" Function=\""<<JOIN.c_str()<<"\"> " <<endl;
            for(unsigned j=0;j<nb_nodes_elem ; j++){
                String name_data_item;
                name_data_item << "elements_"<<el<<"_list_" << i << "_c" << j;
                f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\""<< name_data_item.c_str() <<"\"] </DataItem> " << endl;
            }
            f<<"                                     </DataItem> " <<endl;
            f<<"                            </Topology>" <<endl;
#if DIM==2
        f<<"                            <Geometry Type=\"XY_Z\">"<<endl;
#else
        f<<"                            <Geometry Type=\"X_Y_Z\">"<<endl;
#endif
        f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"X\"] </DataItem> " << endl;
        f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"Y\"] </DataItem> " << endl;
#if DIM==3
        f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"Z\"] </DataItem> " << endl;
#endif
            f<<"                            </Geometry>" <<endl;
        for(unsigned attr=0;attr<attributs.size();attr++){
            if(attributs[attr]=="all"){            
                    f<<"                            <Attribute Name=\"displacements\"  AttributeType=\"Vector\" Center=\"Node\">" << endl;
                    f<<"                                    <DataItem Dimensions=\" "<< nb_nodes << " "<< DIM <<" \" ItemType=\"Function\" Function=\""<<JOIN.c_str()<<"\"> " <<endl;
                    f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"dx\"] </DataItem> " << endl;
                    f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"dy\"] </DataItem> " << endl;
        #if DIM==3            
                    f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"dz\"] </DataItem> " << endl;
        #endif            
                    f<<"                                     </DataItem> " <<endl;
                    f<<"                            </Attribute>"<<endl;
            }
        }
            f<<"                    </Grid>"<< endl;
        }
        f<<"            </Grid>"<<endl;
    }
    f<<"    </Domain>"<< endl;
    f<<"</Xdmf>"<<endl;       

f.close();
}
/*
void write_xdmf_from_hdf5_time(String output_xdmf, String input_hdf5, String name_geometry, int skin, String name_fields, BasicVec<String> attributs=("none"), BasicVec<TYPE> time)
{
    std::ofstream f(output_xdmf.c_str());
    String  name_nodes;
    name_nodes << name_geometry << "/nodes" ;
    Hdf hdf(input_hdf5.c_str());
    int nb_nodes;
    String data_node_x=name_nodes+"/x";
    hdf.read_size(data_node_x,nb_nodes);
    f << "<Xdmf Version=\"2.0\">" << endl; 
    f << "  <Domain>" << endl;
    //ecriture des donnees de noeuds
    f <<"           <DataItem Name=\"X\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " 1 \">" << input_hdf5.c_str() <<":"<< name_geometry.c_str() << "/nodes/x </DataItem>" << endl;
    f <<"           <DataItem Name=\"Y\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " 1 \">" << input_hdf5.c_str() <<":"<< name_geometry.c_str() << "/nodes/y </DataItem>" << endl;
#if DIM==3
    f <<"           <DataItem Name=\"Z\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " 1 \">" << input_hdf5.c_str() <<":"<< name_geometry.c_str() << "/nodes/z </DataItem>" << endl;
#endif
    

    //ecriture des donnees de connectivites des elements_0 et elements_1 : necessite les tags nb_list pour les groupes elements_0 et _1, ainsi que nb_elements, base pour les listes de connectivites
    for(unsigned el=skin;el<2;el++){
        int nb_list;
        String name_elements_el;
        name_elements_el<<name_geometry<<"/elements_"<<el;
        hdf.read_group_size(name_elements_el,nb_list);
        for(unsigned i=0; i< nb_list; i++){
            String name_list;
            name_list << name_elements_el <<"/list_" <<  i;
            String name_list_c0=name_list+"/c0";
            int nb_elems;
            hdf.read_size(name_list_c0,nb_elems);
            int nb_nodes_elem;
            String name_element;
            hdf.read_tag(name_list,"base",name_element,1);
            if(name_element=="Bar"){nb_nodes_elem=2;}
            else if(name_element=="Triangle"){nb_nodes_elem=3;}
            else if(name_element=="Tetra"){nb_nodes_elem=4;}
            else {std::cerr << "Type d'element enfant non implementé" ; assert(0);}
            for(unsigned j=0;j<nb_nodes_elem ; j++){
                String name_data_item;
                name_data_item << "elements_"<<el<<"_list_" << i << "_c" << j;
                String data_item;
                data_item << name_list << "/c" <<j ;
                f <<"           <DataItem Name=\"" << name_data_item.c_str() << "\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_elems << " 1\">" <<  input_hdf5.c_str() <<":"<< data_item.c_str() <<" </DataItem>" << endl;
            }
        }
    }
 
 //Attributs
 for(unsigned attr=0;attr<attributs.size();attr++){
     if(attributs[attr]=="all"){
         for(unsigned t=0;t<time.size();t++){
f <<"           <DataItem Name=\"dx_"<<t<<"\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " 1 \">" << input_hdf5.c_str() <<":"<< name_fields.c_str() <<"/displacements_"<<t<<"/x </DataItem>" << endl;
f <<"           <DataItem Name=\"dy_"<<t<<"\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " 1 \">" << input_hdf5.c_str() <<":"<<  name_fields.c_str() <<"/displacements_"<<t<<"/y </DataItem>" << endl;
#if DIM==3
f <<"           <DataItem Name=\"dz_"<<t<<"\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " 1 \">" << input_hdf5.c_str() <<":"<<  name_fields.c_str() <<"/displacements_"<<t<<"/z </DataItem>" << endl;
#endif
/*f <<"           <DataItem Name=\"sxx\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/sigma/xx </DataItem>" << endl;
f <<"           <DataItem Name=\"syy\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/sigma/yy </DataItem>" << endl;
f <<"           <DataItem Name=\"szz\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/sigma/zz </DataItem>" << endl;
f <<"           <DataItem Name=\"sxy\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/sigma/xy </DataItem>" << endl;
f <<"           <DataItem Name=\"sxz\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/sigma/xz </DataItem>" << endl;
f <<"           <DataItem Name=\"syz\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/sigma/yz </DataItem>" << endl;
f <<"           <DataItem Name=\"smises\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/sigma_von_mises </DataItem>" << endl;
f <<"           <DataItem Name=\"exx\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/epsilon/xx </DataItem>" << endl;
f <<"           <DataItem Name=\"eyy\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/epsilon/yy </DataItem>" << endl;
f <<"           <DataItem Name=\"ezz\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/epsilon/zz </DataItem>" << endl;
f <<"           <DataItem Name=\"exy\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/epsilon/xy </DataItem>" << endl;
f <<"           <DataItem Name=\"exz\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/epsilon/xz </DataItem>" << endl;
f <<"           <DataItem Name=\"eyz\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/epsilon/yz </DataItem>" << endl;
     
        }
    }
 }

 
    //ecriture de la geometrie_0 (elements parents) et geometrie_1 (elements enfants)
    for(unsigned el=skin;el<2;el++){
        f<< "           <Grid Name=\"Geometry_"<<el<<"\" GridType=\"Tree\">" << endl;
        int nb_list;
        String name_elements_el;
        name_elements_el<<name_geometry<<"/elements_"<<el;
        hdf.read_group_size(name_elements_el,nb_list);   
        for(unsigned i=0; i< nb_list; i++){
            String name_list;
            name_list << name_elements_el <<  "/list_" <<  i;        
            String name_list_c0=name_list+"/c0";
            int nb_elems;
            hdf.read_size(name_list_c0,nb_elems);
            int nb_nodes_elem;
            String name_element;
            hdf.read_tag(name_list,"base",name_element);
            String JOIN, name_element_xdmf;
            if(name_element=="Bar"){nb_nodes_elem=2; JOIN="JOIN($0 , $1 )"; name_element_xdmf="Bar"; }
            else if(name_element=="Triangle"){nb_nodes_elem=3;JOIN="JOIN($0 , $1 , $2  )";name_element_xdmf="Triangle";}
            else if(name_element=="Tetra"){nb_nodes_elem=4;JOIN="JOIN($0 , $1 , $2  , $3)";name_element_xdmf="Tetrahedron";}
            else {std::cerr << "Type d'element enfant non implementé" ; assert(0);}        
            f<<"                    <Grid Name=\"list_"<< i <<" t="<< time[t] <<"\">" << endl;
            f<<"                            <Topology Type=\""<<name_element_xdmf.c_str()<<"\" NumberOfElements=\" "<< nb_elems << " \" >" << endl;
            f<<"                                    <DataItem Dimensions=\" "<< nb_elems << "  " << nb_nodes_elem <<" \" ItemType=\"Function\" Function=\""<<JOIN.c_str()<<"\"> " <<endl;
            for(unsigned j=0;j<nb_nodes_elem ; j++){
                String name_data_item;
                name_data_item << "elements_"<<el<<"_list_" << i << "_c" << j;
                f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\""<< name_data_item.c_str() <<"\"] </DataItem> " << endl;
            }
            f<<"                                     </DataItem> " <<endl;
            f<<"                            </Topology>" <<endl;
#if DIM==2
        f<<"                            <Geometry Type=\"XY_Z\">"<<endl;
#else
        f<<"                            <Geometry Type=\"X_Y_Z\">"<<endl;
#endif
        f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"X\"] </DataItem> " << endl;
        f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"Y\"] </DataItem> " << endl;
#if DIM==3
        f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"Z\"] </DataItem> " << endl;
#endif
            f<<"                            </Geometry>" <<endl;
        for(unsigned attr=0;attr<attributs.size();attr++){
            if(attributs[attr]=="all"){            
                    f<<"                            <Attribute Name=\"displacements\"  AttributeType=\"Vector\" Center=\"Node\">" << endl;
                    f<<"                                    <DataItem Dimensions=\" "<< nb_nodes << " "<< DIM <<" \" ItemType=\"Function\" Function=\""<<JOIN.c_str()<<"\"> " <<endl;
                    f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"dx\"] </DataItem> " << endl;
                    f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"dy\"] </DataItem> " << endl;
        #if DIM==3            
                    f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"dz\"] </DataItem> " << endl;
        #endif            
                    f<<"                                     </DataItem> " <<endl;
                    f<<"                            </Attribute>"<<endl;
            }
        }
            f<<"                    </Grid>"<< endl;
        }
        f<<"            </Grid>"<<endl;
    }
    f<<"    </Domain>"<< endl;
    f<<"</Xdmf>"<<endl;       

f.close();
}
*/

void LEVEL::write_geometry_fields_xdmf(DATA_USER &data_user, String type){
    
    if(type=="fields"){ 
        String name_hdf;
        name_hdf << data_user.name_directory.c_str() <<  "/calcul_"<< data_user.id_calcul.c_str() << "/geometry_fields.h5";
        if(FileExists(name_hdf.c_str())==0){ std::cerr << "Le fichier hdf5 n'est pas crée : impossible de créer le fichier xdmf";}

        //ecriture du fichier xdmf pour visualisation par paraview
        String name_xdmf;
        name_xdmf << data_user.name_directory.c_str() <<  "/calcul_"<< data_user.id_calcul.c_str() << "/geometry_fields.xdmf";
        String name_geometry_hdf5 = "/Level_0/Geometry"; 
        String name_fields_hdf5 = "/Level_0/Fields";

        write_xdmf_from_hdf5(name_xdmf, name_hdf, name_geometry_hdf5,1,name_fields_hdf5,BasicVec<String>("all"));
    }
    else if(type=="pattern"){
        String input_hdf5, output_xdmf;
        input_hdf5 << data_user.name_directory.c_str() << "/calcul_" << data_user.id_calcul.c_str()<< "/geometry_pattern.h5";
        output_xdmf << data_user.name_directory.c_str() << "/calcul_" << data_user.id_calcul.c_str()<< "/geometry_pattern.xdmf";
        String name_geometry_hdf5 = "/Level_0/Geometry";
        String name_fields_hdf5 = "/Level_0/Fields";
        write_xdmf_from_hdf5(output_xdmf, input_hdf5, name_geometry_hdf5,0,name_fields_hdf5, BasicVec<String>("none"));
    }

}



//Ecriture du comportement associe aux patterns et aux interfaces
// void LEVEL::write_behaviours_hdf(DATA_USER &data_user, string type){
//     string name_hdf=data_user.name_directory+"/MESH/mesh.h5";
//     Hdf hdf( name_hdf.c_str() );
//     
//     //copie des numeros de groupe des patterns (pieces)
//     for(unsigned i=0;i<nb.sst; i++){
//         Behaviours.patterns  << S_num_group[i];
//     }
//     
//     //copie des connectivites des interfaces
//     for(unsigned i=0;i< nb.inter  ;i++){
//          Behaviours.interfaces << I_comp[i];
//     }
//     
//     String name;
//     name << "/Level_" << num_level << "/Behaviours";
//     Behaviours.write_to(hdf,name);
//     string name_xdmf=data_user.name_directory+"/MESH/geometry_behaviours.xdmf";
// 
// #if DIM==2
//     std::cout << "sortie xdmf non ecrite pour la dimension 2" << endl;
// #else
//     //write_xdmf_geometry_behaviours_pattern_3(name_xdmf, name_hdf,Geometry, Behaviours, num_level);
// #endif
// }
// 

// #include "mesh_utils.h"
// 
// 
// //Ecriture du comportement associe aux patterns et aux interfaces
// void LEVEL::write_fields_hdf(DATA_USER &data_user, string type){
//     string name_hdf=data_user.name_directory+"/MESH/mesh.h5";
//     Hdf hdf( name_hdf.c_str() );
//     
//     //gpu
//     int nb_nodes_tot=0;
//     for(unsigned i=0;i<nb.sst; i++){
//             //creation du maillage global
// 
//         int * elements_sst;
//         TYPE * nodes_sst;
//         nodes_sst=(TYPE*)malloc((DIM*nb.nodes_sst) * sizeof(TYPE));
//         elements_sst=(int*)malloc((nb.nodes_element_sst*nb.elements_sst) * sizeof(int));
//         #if DIM==2
//             create_mesh_tri_2D(S_apex.ptr(),nodes.ptr(), nb.decoup, nodes_sst, elements_sst,nb.sst_s,i); 
//         #else
//             create_mesh_tet(S_apex.ptr(),nodes.ptr(), nb.decoup, nodes_sst, elements_sst,nb.sst_s,nb.apex_sst,i); 
//         #endif
//         for(unsigned n=0;n<nb.nodes_sst; n++){
//             Fields.nodes_in_patterns.x << nodes_sst[n*DIM+0];
//              Fields.nodes_in_patterns.y << nodes_sst[n*DIM+1];
//         #if DIM==3            
//              Fields.nodes_in_patterns.z << nodes_sst[n*DIM+2];
//         #endif  
//         }
//         for(unsigned e=0;e<nb.elements_sst; e++){
//             Fields.elements_in_patterns.c0  << elements_sst[e*nb.nodes_element_sst+0]+nb_nodes_tot;
//             Fields.elements_in_patterns.c1  << elements_sst[e*nb.nodes_element_sst+1]+nb_nodes_tot;
//             Fields.elements_in_patterns.c2  << elements_sst[e*nb.nodes_element_sst+2]+nb_nodes_tot;
//         #if DIM==3            
//             Fields.elements_in_patterns.c3  << elements_sst[e*nb.nodes_element_sst+3]+nb_nodes_tot;
//         #endif  
//         }
//         nb_nodes_tot+=nb.nodes_sst;
// 
//         //assignation des deplacements aux noeuds
//         for(unsigned n=0;n< nb.nodes_sst  ;n++){
//                 Fields.displacements.x << S_q[i+nb.sst_s*(0+n*DIM)];
//                 Fields.displacements.y << S_q[i+nb.sst_s*(1+n*DIM)];
//            #if DIM==3                         
//                 Fields.displacements.z << S_q[i+nb.sst_s*(2+n*DIM)];
//            #endif  
//         }
//     
//         //assignation des contraintes / deformation / contrainte de von mises aux cdg des elements
//         for(unsigned e=0;e<nb.elements_sst; e++){
//         #if DIM==2
//             Fields.sigma.xx  << S_sigma[i+nb.sst_s*(0*nb.elements_sst+e)] ;
//             Fields.sigma.yy  << S_sigma[i+nb.sst_s*(1*nb.elements_sst+e)] ;
//             Fields.sigma.xy  << S_sigma[i+nb.sst_s*(2*nb.elements_sst+e)] ;
//             Fields.epsilon.xx  << S_epsilon[i+nb.sst_s*(0*nb.elements_sst+e)] ;
//             Fields.epsilon.yy  << S_epsilon[i+nb.sst_s*(1*nb.elements_sst+e)] ;
//             Fields.epsilon.xy  << S_epsilon[i+nb.sst_s*(2*nb.elements_sst+e)] ;
//             Fields.sigma_von_mises  << S_sigma_von_mises[i+nb.sst_s*e] ;
//         #else
//             Fields.sigma.xx  << S_sigma[i+nb.sst_s*(0*nb.elements_sst+e)] ;
//             Fields.sigma.yy  << S_sigma[i+nb.sst_s*(1*nb.elements_sst+e)] ;
//             Fields.sigma.zz  << S_sigma[i+nb.sst_s*(2*nb.elements_sst+e)] ;
//             Fields.sigma.xy  << S_sigma[i+nb.sst_s*(3*nb.elements_sst+e)] ;
//             Fields.sigma.xz  << S_sigma[i+nb.sst_s*(4*nb.elements_sst+e)] ;
//             Fields.sigma.yz  << S_sigma[i+nb.sst_s*(5*nb.elements_sst+e)] ;
//             Fields.epsilon.xx  << S_epsilon[i+nb.sst_s*(0*nb.elements_sst+e)] ;
//             Fields.epsilon.yy  << S_epsilon[i+nb.sst_s*(1*nb.elements_sst+e)] ;
//             Fields.epsilon.zz  << S_epsilon[i+nb.sst_s*(2*nb.elements_sst+e)] ;
//             Fields.epsilon.xy  << S_epsilon[i+nb.sst_s*(3*nb.elements_sst+e)] ;
//             Fields.epsilon.xz  << S_epsilon[i+nb.sst_s*(4*nb.elements_sst+e)] ;
//             Fields.epsilon.yz  << S_epsilon[i+nb.sst_s*(5*nb.elements_sst+e)] ;
//             Fields.sigma_von_mises  << S_sigma_von_mises[i+nb.sst_s*e] ;
//         #endif  
//         }
//         
//     }
// 
//     
//     String name;
//     name << "/Level_" << num_level << "/Fields";
//     Fields.write_to(hdf,name);
//     string name_xdmf=data_user.name_directory+"/calcul_"+data_user.id_calcul+"/fields.xdmf";
// #if DIM==2
//     std::cout << "sortie xdmf non ecrite pour la dimension 2" << endl;
// #else
//     //write_xdmf_fields_pattern_3(name_xdmf, name_hdf,Fields, num_level);
// #endif
// }

