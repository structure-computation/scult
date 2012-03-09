//
// C++ Implementation: write_in_hdf
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

#include "struct_geometry_hdf.h"
/*#include "containers/vec.h"*/
/*using namespace std;*/
using namespace Metil;

/*#include "struct_hdf.h"*/
#include "utils.h"

//#include "write_xdmf_hdf5.h"

#include "DATA_USER.h"
#include "LEVEL.h"

//gpu ?
//ecriture de la geometrie
void LEVEL::write_geometry_hdf(DATA_USER &data_user){
    
    //copie des noeuds
    for(unsigned i=0;i<nodes.size()/DIM; i++){
        Geometry.nodes.x << nodes[i*dim+0];
        Geometry.nodes.y << nodes[i*dim+1];
#if DIM==3            
        Geometry.nodes.z << nodes[i*dim+2];
#endif  
    }

    //copie des connectivites en les classant par type d'element (triangle ou tetra pour l'instant) et par piece
#if DIM == 2
    Geometry.elements_0.list_triangle.resize(data_user.group_elem.size());
    for(unsigned i=0;i<nb.sst; i++){
        Geometry.elements_0.list_triangle[S_num_group[i]].c0  << S_apex[0*nb.sst_s+i];
        Geometry.elements_0.list_triangle[S_num_group[i]].c1  << S_apex[1*nb.sst_s+i];
        Geometry.elements_0.list_triangle[S_num_group[i]].c2  << S_apex[2*nb.sst_s+i];
    }
#else
    Geometry.elements_0.list_tetra.resize(data_user.group_elem.size());
    for(unsigned i=0;i<nb.sst; i++){
        Geometry.elements_0.list_tetra[S_num_group[i]].c0  << S_apex[0*nb.sst_s+i];
        Geometry.elements_0.list_tetra[S_num_group[i]].c1  << S_apex[1*nb.sst_s+i];
        Geometry.elements_0.list_tetra[S_num_group[i]].c2  << S_apex[2*nb.sst_s+i];
        Geometry.elements_0.list_tetra[S_num_group[i]].c3  << S_apex[3*nb.sst_s+i];
    }
        
#endif
    
    //copie des connectivites pour les elements enfants en les classant par localisation (bord, liaison, interieur a une piece),  par type d'elements, par numero de groupe
#if DIM==2
    Geometry.elements_1_interior.list_bar.resize(data_user.group_elem.size());
    Geometry.elements_1_link.list_bar.resize(data_user.group_inter.size());
    BasicVec<int> piece_on_edge;
    for(unsigned i=0;i< nb.inter  ;i++){
        if(I_type[i]==0){//interieur d'une piece
            Geometry.elements_1_interior.list_bar[I_num_group[i]].c0 << I_apex[0*nb.inter_s+i];
            Geometry.elements_1_interior.list_bar[I_num_group[i]].c1 << I_apex[1*nb.inter_s+i];
        }
        else if(I_type[i]==2){//entre deux pieces
            Geometry.elements_1_link.list_bar[I_num_group[i]].c0 << I_apex[0*nb.inter_s+i];
            Geometry.elements_1_link.list_bar[I_num_group[i]].c1 << I_apex[1*nb.inter_s+i];            
        }
        else if(I_type[i]==1){//sur le bord
            int rep; bool found=0;
            for(int j=0;j<piece_on_edge.size();j++){if(I_num_group[i]==piece_on_edge[j]){rep=j; found=1; break;}} //find
            if(found==1){
                Geometry.elements_1_edge.list_bar[rep].c0<< I_apex[0*nb.inter_s+i];
                Geometry.elements_1_edge.list_bar[rep].c1<< I_apex[1*nb.inter_s+i];
            }
            else{
                Element_Bar_Hdf bar;
                bar.c0<< I_apex[0*nb.inter_s+i];
                bar.c1<< I_apex[1*nb.inter_s+i];
                Geometry.elements_1_edge.list_bar.push_back(bar);
                piece_on_edge.push_back(I_num_group[i]);
            }
        }
        else{
            std::cerr << "Type d'element_1 non reconnu";
        }
    }
#else
    Geometry.elements_1_interior.list_triangle.resize(data_user.group_elem.size());
    Geometry.elements_1_link.list_triangle.resize(data_user.group_inter.size());
    BasicVec<int> piece_on_edge;
    for(unsigned i=0;i< nb.inter  ;i++){
        if(I_type[i]==0){//interieur d'une piece
            Geometry.elements_1_interior.list_triangle[I_num_group[i]].c0 << I_apex[0*nb.inter_s+i];
            Geometry.elements_1_interior.list_triangle[I_num_group[i]].c1 << I_apex[1*nb.inter_s+i];
            Geometry.elements_1_interior.list_triangle[I_num_group[i]].c2 << I_apex[2*nb.inter_s+i];
        }
        else if(I_type[i]==2){//entre deux pieces
            Geometry.elements_1_link.list_triangle[I_num_group[i]].c0 << I_apex[0*nb.inter_s+i];
            Geometry.elements_1_link.list_triangle[I_num_group[i]].c1 << I_apex[1*nb.inter_s+i];
            Geometry.elements_1_link.list_triangle[I_num_group[i]].c2 << I_apex[2*nb.inter_s+i];
            
        }
        else if(I_type[i]==1){//sur le bord
            int rep; bool found=0;
            for(int j=0;j<piece_on_edge.size();j++){if(I_num_group[i]==piece_on_edge[j]){rep=j; found=1; break;}} //find
            if(found==1){
                Geometry.elements_1_edge.list_triangle[rep].c0<< I_apex[0*nb.inter_s+i];
                Geometry.elements_1_edge.list_triangle[rep].c1<< I_apex[1*nb.inter_s+i];
                Geometry.elements_1_edge.list_triangle[rep].c2<< I_apex[2*nb.inter_s+i];
            }
            else{
                Element_Triangle_Hdf triangle;
                triangle.c0<< I_apex[0*nb.inter_s+i];
                triangle.c1<< I_apex[1*nb.inter_s+i];
                triangle.c2<< I_apex[2*nb.inter_s+i];
                Geometry.elements_1_edge.list_triangle.push_back(triangle);
                piece_on_edge.push_back(I_num_group[i]);
            }  
        }
        else{
            std::cerr << "Type d'element_1 non reconnu";
        }
    }
#endif           
        
    //ecriture des champs dans le fichier hdf5
    string name_hdf =data_user.name_directory + "/MESH/geometry.h5";

    if(FileExists(name_hdf.c_str())){ string command = "rm -rf "+name_hdf; int syst_rm=system(command.c_str());}
    
    Hdf hdf( name_hdf.c_str() );   
    String name;
    name << "/Level_" << num_level << "/Geometry";
    Geometry.write_to(hdf,name);
    
    //Ecriture des tags pour les elements_0 et les elements_1 regroupant les informations sur les voisins de chaque list d'elements
    //pour les elements_0
    String name_group_0;
    name_group_0 << name << "/elements_0";
    for(unsigned i=0;i<Geometry.nb_list_elements_0; i++){
        String name_list ;
        name_list<< name_group_0 << "/list_" << i ; 
        hdf.add_tag(name_list,"piece",name_list.c_str());
    }
    
    //pour les elements_1
    String name_group_1;
    name_group_1 << name << "/elements_1";
    for(unsigned i=0;i<Geometry.nb_list_elements_1_edge; i++){
        String name_list ;
        name_list<< name_group_1 << "/list_" << i ;
        String name_piece;
        name_piece << name_group_1 << "/list_" << piece_on_edge[i];
        //PRINT(name_piece);
        //PRINT(name_list);
        hdf.add_tag(name_list,"edge_of_0",name_piece.c_str());
        hdf.add_tag(name_list,"edge_of_1","");    
    }   
    for(unsigned i=0;i<Geometry.nb_list_elements_1_interior; i++){
        String name_list ;
        name_list<< name_group_1 << "/list_" << i+Geometry.nb_list_elements_1_edge ;
        String name_piece;
        name_piece << name_group_1 << "/list_" << i;    
        //PRINT(name_piece);
        //PRINT(name_list);
        hdf.add_tag(name_list,"edge_of_0",name_piece.c_str());       
        hdf.add_tag(name_list,"edge_of_1",name_piece.c_str());       
    }
    for(unsigned i=0;i<Geometry.nb_list_elements_1_link; i++){
        String name_list ;
        name_list<< name_group_1 << "/list_" << i+Geometry.nb_list_elements_1_edge+Geometry.nb_list_elements_1_interior;
        String name_piece0, name_piece1;
        name_piece0 << name_group_1 << "/list_" << data_user.group_inter[i].adj_num_group_elem[0];    
        name_piece1 << name_group_1 << "/list_" << data_user.group_inter[i].adj_num_group_elem[1];    
        //PRINT(name_piece0);
        //PRINT(name_piece1);
        //PRINT(name_list);
        hdf.add_tag(name_list,"edge_of_0",name_piece0.c_str());       
        hdf.add_tag(name_list,"edge_of_1",name_piece1.c_str());       
    }
}


//ecriture de la geometrie
void LEVEL::write_geometry_behaviour_hdf(DATA_USER &data_user){
    

    //copie des noeuds
    for(unsigned i=0;i<nodes.size()/DIM; i++){
        Geometry.nodes.x << nodes[i*dim+0];
        Geometry.nodes.y << nodes[i*dim+1];
#if DIM==3            
        Geometry.nodes.z << nodes[i*dim+2];
#endif  
    }

//copie des connectivites en les classant par type d'element (triangle ou tetra pour l'instant) et par piece
    BasicVec<String> behaviour_pattern;
    behaviour_pattern.resize(data_user.group_elem.size());
    Geometry.elements_0.num_behaviour.resize(data_user.group_elem.size());
#if DIM == 2
    Geometry.elements_0.list_triangle.resize(data_user.group_elem.size());
    for(unsigned i=0;i<nb.sst; i++){
        Geometry.elements_0.list_triangle[S_num_group[i]].c0  << S_apex[0*nb.sst_s+i];
        Geometry.elements_0.list_triangle[S_num_group[i]].c1  << S_apex[1*nb.sst_s+i];
        Geometry.elements_0.list_triangle[S_num_group[i]].c2  << S_apex[2*nb.sst_s+i];
        int rep=data_user.group_elem[S_num_group[i]].id_material;
        Geometry.elements_0.num_behaviour[i]=rep;
        String name_behaviour;
        name_behaviour << data_user.Behaviour_pattern[rep].type << " " << data_user.Behaviour_pattern[rep].comp;
        behaviour_pattern[S_num_group[i]]=name_behaviour;
    }
#else
    Geometry.elements_0.list_tetra.resize(data_user.group_elem.size());
    for(unsigned i=0;i<nb.sst; i++){
        Geometry.elements_0.list_tetra[S_num_group[i]].c0  << S_apex[0*nb.sst_s+i];
        Geometry.elements_0.list_tetra[S_num_group[i]].c1  << S_apex[1*nb.sst_s+i];
        Geometry.elements_0.list_tetra[S_num_group[i]].c2  << S_apex[2*nb.sst_s+i];
        Geometry.elements_0.list_tetra[S_num_group[i]].c3  << S_apex[3*nb.sst_s+i];
        int rep=data_user.group_elem[S_num_group[i]].id_material;
        Geometry.elements_0.num_behaviour[S_num_group[i]]=rep;
        String name_behaviour;
        name_behaviour << data_user.Behaviour_pattern[rep].type.c_str() << " " << data_user.Behaviour_pattern[rep].comp.c_str();
        behaviour_pattern[S_num_group[i]]=name_behaviour;
    }
#endif

    //copie des connectivites pour les elements enfants en les classant par localisation (bord, liaison, interieur a une piece),  par type d'elements, par numero de groupe
#if DIM==2
    Geometry.elements_1_interior.list_bar.resize(data_user.group_elem.size());
    Geometry.elements_1_link.list_bar.resize(data_user.group_inter.size());
    BasicVec<int> piece_on_edge, num_CL;
    BasicVec<String> behaviour_edge, behaviour_interior, behaviour_link;
    behaviour_interior.resize(data_user.group_elem.size());
    behaviour_link.resize(data_user.group_inter.size());
    
    for(unsigned i=0;i< nb.inter  ;i++){
        if(I_type[i]==0){//interieur d'une piece
            Geometry.elements_1_interior.list_bar[I_num_group[i]].c0 << I_apex[0*nb.inter_s+i];
            Geometry.elements_1_interior.list_bar[I_num_group[i]].c1 << I_apex[1*nb.inter_s+i];
            behaviour_interior[I_num_group[i]]=I_comp[i];
            
        }
        else if(I_type[i]==2){//entre deux pieces
            Geometry.elements_1_link.list_bar[I_num_group[i]].c0 << I_apex[0*nb.inter_s+i];
            Geometry.elements_1_link.list_bar[I_num_group[i]].c1 << I_apex[1*nb.inter_s+i];
            behaviour_link[I_num_group[i]]=I_comp[i];
        }
        else if(I_type[i]==1){//sur le bord
            int rep; bool found=0;
            for(int j=0;j<piece_on_edge.size();j++){if((I_num_group[i]==piece_on_edge[j]) and (I_num_CL[i]==num_CL[j])){rep=j; found=1; break;}} //find
            if(found==1){                
                Geometry.elements_1_edge.list_bar[rep].c0<< I_apex[0*nb.inter_s+i];
                Geometry.elements_1_edge.list_bar[rep].c1<< I_apex[1*nb.inter_s+i];
                behaviour_edge[rep]=I_comp[i];
            }
            else{
                Element_Bar_Hdf bar;
                bar.c0<< I_apex[0*nb.inter_s+i];
                bar.c1<< I_apex[1*nb.inter_s+i];
                Geometry.elements_1_edge.list_bar.push_back(bar);
                piece_on_edge.push_back(I_num_group[i]);
                num_CL.push_back(I_num_CL[i]);
                behaviour_edge.push_back(I_comp[i]);
            }
        }
        else{
            std::cerr << "Type d'element_1 non reconnu";
        }
    }
#else
    Geometry.elements_1_interior.list_triangle.resize(data_user.group_elem.size());
    Geometry.elements_1_link.list_triangle.resize(data_user.group_inter.size());
    BasicVec<int> piece_on_edge, num_CL;
    BasicVec<String> behaviour_edge, behaviour_interior, behaviour_link;
    behaviour_interior.resize(data_user.group_elem.size());
    behaviour_link.resize(data_user.group_inter.size());
    for(unsigned i=0;i< nb.inter  ;i++){
        if(I_type[i]==0){//interieur d'une piece
            Geometry.elements_1_interior.list_triangle[I_num_group[i]].c0 << I_apex[0*nb.inter_s+i];
            Geometry.elements_1_interior.list_triangle[I_num_group[i]].c1 << I_apex[1*nb.inter_s+i];
            Geometry.elements_1_interior.list_triangle[I_num_group[i]].c2 << I_apex[2*nb.inter_s+i];
            behaviour_interior[I_num_group[i]]=I_comp[i];
        }
        else if(I_type[i]==2){//entre deux pieces
            Geometry.elements_1_link.list_triangle[I_num_group[i]].c0 << I_apex[0*nb.inter_s+i];
            Geometry.elements_1_link.list_triangle[I_num_group[i]].c1 << I_apex[1*nb.inter_s+i];
            Geometry.elements_1_link.list_triangle[I_num_group[i]].c2 << I_apex[2*nb.inter_s+i];
            behaviour_link[I_num_group[i]]=I_comp[i];       
        }
        else if(I_type[i]==1){//sur le bord
            int rep; bool found=0;
            for(int j=0;j<piece_on_edge.size();j++){if((I_num_group[i]==piece_on_edge[j]) and (I_num_CL[i]==num_CL[j])){rep=j; found=1; break;}} //find
            if(found==1){
                Geometry.elements_1_edge.list_triangle[rep].c0<< I_apex[0*nb.inter_s+i];
                Geometry.elements_1_edge.list_triangle[rep].c1<< I_apex[1*nb.inter_s+i];
                Geometry.elements_1_edge.list_triangle[rep].c2<< I_apex[2*nb.inter_s+i];
                behaviour_edge[rep]=I_comp[i];
            }
            else{
                Element_Triangle_Hdf triangle;
                triangle.c0<< I_apex[0*nb.inter_s+i];
                triangle.c1<< I_apex[1*nb.inter_s+i];
                triangle.c2<< I_apex[2*nb.inter_s+i];
                Geometry.elements_1_edge.list_triangle.push_back(triangle);
                piece_on_edge.push_back(I_num_group[i]);
                num_CL.push_back(I_num_CL[i]);
                behaviour_edge.push_back(I_comp[i]);
            }  
        }
        else{
            std::cerr << "Type d'element_1 non reconnu";
        }
    }
#endif           

    //ecriture des champs dans le fichier hdf5
    String name_hdf;
    name_hdf << data_user.name_directory.c_str() << "/calcul_" << data_user.id_calcul.c_str()<< "/geometry_behaviour.h5";
    if(FileExists(name_hdf.c_str())){ String command = "rm -rf "+name_hdf; int syst_rm=system(command.c_str());}
    
    Hdf hdf( name_hdf.c_str() );   
    String name;
    name << "/Level_" << num_level << "/Geometry";
    Geometry.write_to(hdf,name);
    
    //Ecriture des tags pour les elements_0 et les elements_1 regroupant les informations sur les voisins de chaque list d'elements
    //pour les elements_0
    String name_group_0;
    name_group_0 << name << "/elements_0";
    Geometry.elements_0.behaviour.resize(Geometry.nb_list_elements_0); 
    int size;
    hdf.read_group_size(name_group_0, size ) ;

    for(unsigned i=0;i<Geometry.nb_list_elements_0; i++){
        String name_list ;
        name_list<< name_group_0 << "/list_" << i ;
        hdf.add_tag(name_list,"piece",name_list.c_str());
        hdf.add_tag(name_list,"behaviour",behaviour_pattern[i].c_str());
        hdf.add_tag(name_list,"behaviour_reference", Geometry.elements_0.num_behaviour[i]);
        Geometry.elements_0.behaviour[i]=behaviour_pattern[i];
    }

    //pour les elements_1
    String name_group_1;
    name_group_1 << name << "/elements_1";
    Geometry.elements_1_edge.behaviour.resize(Geometry.nb_list_elements_1_edge); 
    for(unsigned i=0;i<Geometry.nb_list_elements_1_edge; i++){
        String name_list ;
        name_list<< name_group_1 << "/list_" << i ;
        String name_piece;
        name_piece << name_group_1 << name << "/elements_0/list_" << piece_on_edge[i];
        hdf.add_tag(name_list,"edge_of_0",name_piece.c_str());
        hdf.add_tag(name_list,"edge_of_1",""); 
        hdf.add_tag(name_list,"behaviour",behaviour_edge[i].c_str());
/*        hdf.add_tag(name_list,"behaviour_reference",Geometry.elements_1_edge.num_behaviour[i]);*/
        Geometry.elements_1_edge.behaviour[i]=behaviour_edge[i];
    }
    

    Geometry.elements_1_interior.behaviour.resize(Geometry.nb_list_elements_1_interior); 
    for(unsigned i=0;i<Geometry.nb_list_elements_1_interior; i++){
        String name_list ;
        name_list<< name_group_1 << "/list_" << i+Geometry.nb_list_elements_1_edge ;
        String name_piece;
        name_piece << name_group_1 << name << "/elements_0/list_" << i;    
        hdf.add_tag(name_list,"edge_of_0",name_piece.c_str());       
        hdf.add_tag(name_list,"edge_of_1",name_piece.c_str());       
        hdf.add_tag(name_list,"behaviour",behaviour_interior[i].c_str());
/*        hdf.add_tag(name_list,"behaviour_reference",Geometry.elements_1_interior.num_behaviour[i]);*/
        Geometry.elements_1_interior.behaviour[i]=behaviour_interior[i];
    }

    Geometry.elements_1_link.behaviour.resize(Geometry.nb_list_elements_1_link); 

    for(unsigned i=0;i<Geometry.nb_list_elements_1_link; i++){
        String name_list ;
        name_list<< name_group_1 << "/list_" << i+Geometry.nb_list_elements_1_edge+Geometry.nb_list_elements_1_interior;  
        String name_piece0, name_piece1;
        name_piece0 << name_group_1 << name << "/elements_0/list_" << data_user.group_inter[i].adj_num_group_elem[0];    
        name_piece1 << name_group_1 << name << "/elements_0/list_" << data_user.group_inter[i].adj_num_group_elem[1];   
        hdf.add_tag(name_list,"edge_of_0",name_piece0.c_str());       
        hdf.add_tag(name_list,"edge_of_1",name_piece1.c_str());    
        hdf.add_tag(name_list,"behaviour",behaviour_link[i].c_str());
//         hdf.add_tag(name_list,"behaviour_reference",Geometry.elements_1_link.num_behaviour[i]);
        Geometry.elements_1_link.behaviour[i]=behaviour_link[i];
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



#include "code_genere/write_quantities_hdf.h"
// #include "write_xdmf_hdf5.h"
// 
// 

void LEVEL::write_geometry_for_fields(DATA_USER &data_user){
    String name_hdf;
    name_hdf << data_user.name_directory.c_str() <<  "/calcul_"<< data_user.id_calcul.c_str() << "/geometry_fields.h5";
    if(FileExists(name_hdf.c_str())){ String command = "rm -rf "+name_hdf; int syst_rm=system(command.c_str()); std::cout << syst_rm << endl;}
    Hdf hdf( name_hdf.c_str() );
    BasicVec<BasicVec<TYPE>, DIM> nodes_hdf;
#if DIM==2
    BasicVec<BasicVec<int>, 2> elements_side_hdf;    
#else
    BasicVec<BasicVec<int>, 3> elements_side_hdf;
#endif
    //gpu
    int nb_nodes_tot=0;
    for(unsigned i=0;i< nb.i_eff  ;i++){
        int repside=I_eff_side[i];
        int numS=side_rep[repside];
        int numside=side_rep[repside+nb.side_s];
#if DIM==2
      write_mesh_2(numS, numside, nb.sst_s, S_apex.ptr(), nodes.ptr(), nb_nodes_tot , elements_side_hdf, nodes_hdf);  
#else
      write_mesh_3(numS, numside, nb.sst_s, S_apex.ptr(), nodes.ptr(), nb_nodes_tot , elements_side_hdf, nodes_hdf); 
#endif
    }

    for(unsigned i=0;i< nb.i_depl  ;i++){
        int repside=I_depl_side[i];
        int numS=side_rep[repside];
        int numside=side_rep[repside+nb.side_s];
#if DIM==2
      write_mesh_2(numS, numside, nb.sst_s, S_apex.ptr(), nodes.ptr(), nb_nodes_tot , elements_side_hdf, nodes_hdf);  
#else
      write_mesh_3(numS, numside, nb.sst_s, S_apex.ptr(), nodes.ptr(), nb_nodes_tot , elements_side_hdf, nodes_hdf); 
#endif
    }

    for(unsigned i=0;i< nb.i_depl_normal  ;i++){
        int repside=I_depl_normal_side[i];
        int numS=side_rep[repside];
        int numside=side_rep[repside+nb.side_s];      
#if DIM==2
      write_mesh_2(numS, numside, nb.sst_s, S_apex.ptr(), nodes.ptr(), nb_nodes_tot , elements_side_hdf, nodes_hdf);  
#else
      write_mesh_3(numS, numside, nb.sst_s, S_apex.ptr(), nodes.ptr(), nb_nodes_tot , elements_side_hdf, nodes_hdf);   
#endif
    }

    for(unsigned i=0;i< nb.i_sym  ;i++){
        int repside=I_sym_side[i];
        int numS=side_rep[repside];
        int numside=side_rep[repside+nb.side_s];     
#if DIM==2
      write_mesh_2(numS, numside, nb.sst_s, S_apex.ptr(), nodes.ptr(), nb_nodes_tot , elements_side_hdf, nodes_hdf);  
#else
      write_mesh_3(numS, numside, nb.sst_s, S_apex.ptr(), nodes.ptr(), nb_nodes_tot , elements_side_hdf, nodes_hdf);      
#endif
    }
    
#if DIM==2
    nodes_hdf[0].write_to(hdf,"/Level_0/Geometry/nodes/x");
    nodes_hdf[1].write_to(hdf,"/Level_0/Geometry/nodes/y");
    elements_side_hdf[0].write_to(hdf,"/Level_0/Geometry/elements_1/list_0/c0");
    elements_side_hdf[1].write_to(hdf,"/Level_0/Geometry/elements_1/list_0/c1");
    String name_el="/Level_0/Geometry/elements_1/list_0";
    hdf.add_tag(name_el,"base","Bar");
#else    
    nodes_hdf[0].write_to(hdf,"/Level_0/Geometry/nodes/x");
    nodes_hdf[1].write_to(hdf,"/Level_0/Geometry/nodes/y");
    nodes_hdf[2].write_to(hdf,"/Level_0/Geometry/nodes/z");
    elements_side_hdf[0].write_to(hdf,"/Level_0/Geometry/elements_1/list_0/c0");
    elements_side_hdf[1].write_to(hdf,"/Level_0/Geometry/elements_1/list_0/c1");
    elements_side_hdf[2].write_to(hdf,"/Level_0/Geometry/elements_1/list_0/c2");
    String name_el="/Level_0/Geometry/elements_1/list_0";
    hdf.add_tag(name_el,"base","Triangle");
    hdf.add_tag(name_el,"type","none");
#endif
}

void LEVEL::write_fields(DATA_USER &data_user, Vec<TYPE> &q, int nt_total, TYPE val_time){
    String name_hdf;
    name_hdf << data_user.name_directory.c_str() <<  "/calcul_"<< data_user.id_calcul.c_str() << "/geometry_fields.h5";
    Hdf hdf( name_hdf.c_str() );
    BasicVec<BasicVec<TYPE>, DIM> displacements_hdf;
#if DIM==2
    BasicVec<BasicVec<TYPE>, 3> sigma_hdf;
    BasicVec<BasicVec<TYPE>, 3> epsilon_hdf;  
#else
    BasicVec<BasicVec<TYPE>, 6> sigma_hdf;
    BasicVec<BasicVec<TYPE>, 6> epsilon_hdf;
#endif
    BasicVec<TYPE> sigma_von_mises_hdf;
    //gpu
    int nb_nodes_tot=0;
    for(unsigned i=0;i< nb.i_eff  ;i++){
        int repside=I_eff_side[i];
        int numS=side_rep[repside];
        int numside=side_rep[repside+nb.side_s];
#if DIM==2
#else
/*        write_fields_3(numS, nb.sst_s, S_apex.ptr(), nodes.ptr(), q.ptr(), displacements_hdf, sigma_hdf, epsilon_hdf, sigma_von_mises_hdf, S_E.ptr(), S_nu.ptr());*/
    write_fields_3(numS, nb.sst_s, S_apex.ptr(), nodes.ptr(), q.ptr(), displacements_hdf);
#endif
    }

    for(unsigned i=0;i< nb.i_depl  ;i++){
        int repside=I_depl_side[i];
        int numS=side_rep[repside];
        int numside=side_rep[repside+nb.side_s];
#if DIM==2
#else
/*        write_fields_3(numS, nb.sst_s, S_apex.ptr(), nodes.ptr(), q.ptr(), displacements_hdf, sigma_hdf, epsilon_hdf, sigma_von_mises_hdf, S_E.ptr(), S_nu.ptr());*/
            write_fields_3(numS, nb.sst_s, S_apex.ptr(), nodes.ptr(), q.ptr(), displacements_hdf);

#endif
    }

    for(unsigned i=0;i< nb.i_depl_normal  ;i++){
        int repside=I_depl_normal_side[i];
        int numS=side_rep[repside];
        int numside=side_rep[repside+nb.side_s];      
#if DIM==2

#else
/*        write_fields_3(numS, nb.sst_s, S_apex.ptr(), nodes.ptr(), q.ptr(), displacements_hdf, sigma_hdf, epsilon_hdf, sigma_von_mises_hdf, S_E.ptr(), S_nu.ptr());*/
            write_fields_3(numS, nb.sst_s, S_apex.ptr(), nodes.ptr(), q.ptr(), displacements_hdf);
#endif
    }

    for(unsigned i=0;i< nb.i_sym  ;i++){
        int repside=I_sym_side[i];
        int numS=side_rep[repside];
        int numside=side_rep[repside+nb.side_s];     
#if DIM==2

#else
/*        write_fields_3(numS, nb.sst_s, S_apex.ptr(), nodes.ptr(), q.ptr(), displacements_hdf, sigma_hdf, epsilon_hdf, sigma_von_mises_hdf, S_E.ptr(), S_nu.ptr());*/
      write_fields_3(numS, nb.sst_s, S_apex.ptr(), nodes.ptr(), q.ptr(), displacements_hdf);

#endif
    }
    
#if DIM==2
      
#else    
        String name_fields ="/Level_0/Fields";
        //sauvegarde des champs par noeuds
        String name_displacements;
        name_displacements<<name_fields<<"/displacements/pt_"<<nt_total;
        BasicVec<String> displacements_coor= BasicVec<String>("/x","/y","/z");
        for(unsigned d=0;d<DIM;d++){
            String name_displacement_coor;
            name_displacement_coor=name_displacements+displacements_coor[d];
            displacements_hdf[d].write_to(hdf,name_displacement_coor.c_str());
        } 
        hdf.write_tag(name_displacements,"time",val_time);
        
        //sauvegarde des champs par elements
        String name_sigma, name_epsilon;
        name_sigma<<name_fields<<"/sigma/pt_"<<nt_total;
        name_epsilon<<name_fields<<"/epsilon/pt_"<<nt_total; 
#if DIM==2
        BasicVec<String> tensor_fields= BasicVec<String>("/xx","/yy","/xy");
#else
        BasicVec<String> tensor_fields= BasicVec<String>("/xx","/yy","/zz","/xy","/xz","/yz");        
#endif
        for(unsigned nf=0;nf<tensor_fields.size();nf++){
            String name_sigma_field, name_epsilon_field;
            name_sigma_field=name_sigma+tensor_fields[nf];
            name_epsilon_field=name_epsilon+tensor_fields[nf];
            sigma_hdf[nf].write_to(hdf,name_sigma_field.c_str());
            epsilon_hdf[nf].write_to(hdf,name_epsilon_field.c_str());
        }
        String name_smises;
        name_smises <<name_fields<<"/sigma_von_mises/pt_"<<nt_total;
        //PRINT(sigma_von_mises_hdf);
        sigma_von_mises_hdf.write_to(hdf,name_smises.c_str());
        hdf.write_tag(name_sigma,"time",val_time);
        hdf.write_tag(name_epsilon,"time",val_time);
#endif

}



