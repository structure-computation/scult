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
#include <iostream>
#include <fstream>
#include <cassert>

using namespace Metil;
using namespace std;

void write_nodes_datasets(std::ofstream &f,String input_hdf5, String name_nodes,int nb_nodes, int i_proc) {
    //ecriture des coordonnées des noeuds
    BasicVec<String> dimensions("x","y","z");
    for(unsigned d=0;d<DIM;d++){
        String name_coor_node; name_coor_node << name_nodes.c_str() << "/"<< dimensions[d];
        f <<"           <DataItem Name=\""<< name_coor_node.c_str()<<"_proc_"<<i_proc <<"\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " 1 \">" << input_hdf5.c_str() <<":"<< name_coor_node.c_str() <<" </DataItem>" << endl;
    }
}

void write_nodes_attributs_datasets(std::ofstream &f,String input_hdf5,int nb_nodes,String name_fields, BasicVec<String>  attributs, int time, int i_proc) {
    //ecriture des attributs aux noeuds
    BasicVec<String> dimensions("x","y","z");
    for (unsigned attr=0;attr<attributs.size();attr++) {
        if (attributs[attr]=="displacements" or attributs[attr]=="displacements_skin") 
            for(unsigned d=0;d<DIM;d++){
                String name_field; name_field << name_fields <<"/pt_"<<time<<"/"<<attributs[attr]<<"/"<<dimensions[d];
                f <<"           <DataItem Name=\""<<name_field.c_str()<<"_proc_"<<i_proc<<"\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " 1 \">" << input_hdf5.c_str() <<":"<< name_field.c_str()<< " </DataItem>" << endl;
            }
    }
}

void write_groups_datasets(std::ofstream &f,String input_hdf5, String name_group_elements,int nb_list, int type_element) {
    Hdf hdf(input_hdf5.c_str());

    for (unsigned i=0; i< nb_list; i++) {
        String name_list;
        name_list << name_group_elements <<"/list_" <<  i;
        String name_list_c0=name_list+"/mesh_c0";
        int nb_elems;
        hdf.read_size(name_list_c0,nb_elems);
        int nb_nodes_elem;
        int pattern_id;
        if(type_element==0){
            hdf.read_tag(name_list,"pattern_base_id",pattern_id,1);
            if (pattern_id==0) nb_nodes_elem=3;             // Triangle
            else if (pattern_id==1) nb_nodes_elem=3;        // Triangle_6, on ne prend que les 3 premiers noeuds
            else if (pattern_id==2) nb_nodes_elem=4;        // Tetra
            else if (pattern_id==3) nb_nodes_elem=4;        // Tetra_10,   on ne prend que les 4 premiers noeuds
            else {
                std::cerr << "Type d'element non implementé - voir le tag \"base\" dans le fichier hdf5" ;
                assert(0);
            }
        }else if(type_element==1){ 
            hdf.read_tag(name_list,"interface_base_id",pattern_id,1);
            if (pattern_id==0) nb_nodes_elem=2;             // Bar
            else if (pattern_id==1) nb_nodes_elem=3;        // Bar_3
            else if (pattern_id==2) nb_nodes_elem=3;        // Triangle
            else if (pattern_id==3) nb_nodes_elem=3;        // Triangle_6, on ne prend que les 3 premiers noeuds
            else {
                std::cerr << "Type d'element non implementé - voir le tag \"base\" dans le fichier hdf5" ;
                assert(0);
            }
        }
        for (unsigned j=0;j<nb_nodes_elem ; j++) {
            String data_item;
            data_item << name_list << "/mesh_c" <<j ;
            f <<"           <DataItem Name=\"" << data_item.c_str() << "\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_elems << " 1\">" <<  input_hdf5.c_str() <<":"<< data_item.c_str() <<" </DataItem>" << endl;
        }
    }
}

void write_groups_datasets_2(std::ofstream &f,String input_hdf5, String name_group_elements){
    //lecture des noms des listes d'elements
//     int nb_elems_tot=0;
//     int nb_nodes_elem_glob=4;
    Hdf hdf(input_hdf5.c_str());
    BasicVec<String> lists;
    lists=hdf.list_dir(name_group_elements);
    for (unsigned i=0; i< lists.size(); i++) {
        String name_list; name_list << name_group_elements << "/"<<lists[i];
        String name_list_c0=name_list+"/mesh_c0";
        int nb_elems;
        hdf.read_size(name_list_c0,nb_elems); //lecture du nombre d'elements dans la liste
        //lecture du type d'elements
        int nb_nodes_elem;
        String base;
        hdf.read_tag(name_list,"base",base,1);
        if (base=="Bar") nb_nodes_elem=2;               //Bar
        else if (base=="Bar_3") nb_nodes_elem=2;             // Bar_3, on ne prend que les 2 premiers noeuds
        else if (base=="Triangle") nb_nodes_elem=3;             // Triangle
        else if (base=="Triangle_6") nb_nodes_elem=3;        // Triangle_6, on ne prend que les 3 premiers noeuds
        else if (base=="Quadrilateral") nb_nodes_elem=4;             // quad
        else if (base=="Tetrahedron") nb_nodes_elem=4;        // Tetra
        else if (base=="Tetrahedron_10") nb_nodes_elem=10;        // Tetra_10,   on ne prend que les 4 premiers noeuds
        else if (base=="Hexahedron") nb_nodes_elem=8;             // quad
        else { std::cerr << "Type d'element non implementé - voir le tag \"base\" dans le fichier hdf5" ; assert(0);}
        
        for (unsigned j=0;j<nb_nodes_elem ; j++) {
            String data_item;
            data_item << name_list << "/mesh_c" <<j ;
            f <<"           <DataItem Name=\"" << data_item.c_str() << "\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_elems << " 1\">" <<  input_hdf5.c_str() <<":"<< data_item.c_str() <<" </DataItem>" << endl;
        }
//         if(i<50)
//             nb_elems_tot+=nb_elems;
        
//         nb_nodes_elem_glob=nb_nodes_elem;
    }
    
//     int nb_list=50;
//     String JOIN="JOIN(";
//     for (unsigned i=0; i< nb_list-1; i++) {
//         JOIN<<"$"<<i<<" ; ";
//     }
//     JOIN << "$"<<nb_list-1 <<")";
//     
//     for (unsigned j=0;j<nb_nodes_elem_glob ; j++) {
//         f<<"                <DataItem Name=\" c" <<j<<"\" Dimensions=\" "<< nb_elems_tot <<" \" ItemType=\"Function\" Function=\""<<JOIN.c_str()<<"\"> " <<endl;
//         for (unsigned i=0; i< nb_list; i++) {
//         String name_list; name_list << name_group_elements << "/"<<lists[i];   
//         String data_item;
//         data_item << name_list << "/mesh_c" <<j ;
//         f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\""<< data_item.c_str() <<"\"] </DataItem> " << endl;
//         }
//         f<<"                                     </DataItem> " <<endl;
//     }

}

template<class VB> BasicVec<unsigned> find_with_index(const VB &to_check) {
    BasicVec<unsigned> res; res.reserve( to_check.size() );
    for(unsigned i=0;i<to_check.size();++i)
        if ( to_check[i] )
            res.push_back( i );
    return res;
}

BasicVec<int> find_with_index(String name, BasicVec<String> list){
    BasicVec<int> res; res.reserve(list.size());
    for(unsigned i=0;i<list.size();i++){
        if(name==list[i]){res.push_back(i);}
    }
    return res;
}

bool find(String name, BasicVec<String> list){
    bool res=0; 
    for(unsigned i=0;i<list.size();i++){
        if(name==list[i]){res=1; break;}
    }
    return res;
}

void write_groups_attributs_datasets(std::ofstream &f,String input_hdf5, String name_elements, String name_fields, BasicVec<String>  attributs, int time) {
    Hdf hdf(input_hdf5.c_str());
    BasicVec<String> lists;
    lists=hdf.list_dir(name_elements);

#if DIM==2
    BasicVec<String> tensor_comp("xx","yy","xy");
    BasicVec<String> vector_comp("x","y");    
#else
    BasicVec<String> tensor_comp("xx","yy","zz","xy","xz","yz");
    BasicVec<String> vector_comp("x","y","z");
#endif
    BasicVec<String> list_fields_tensor_time("sigma","epsilon","sigma_skin", "epsilon_skin");
    BasicVec<String> list_fields_vector_time("F", "W", "Fchap", "Wchap");
    BasicVec<String> list_fields_scalar_time("sigma_von_mises","sigma_von_mises_skin");
    BasicVec<String> list_fields_global("num_proc","material","num_group", "number", "nature");
    
    for (unsigned i=0; i< lists.size(); i++) {
        String name_list;
        name_list << name_elements <<"/"<< lists[i];
        String name_list_c0=name_list+"/mesh_c0";
        int nb_elems;
        hdf.read_size(name_list_c0,nb_elems);

        //Ecriture des attributs en fonction de leur nom
        
        for (unsigned attr=0;attr<attributs.size();attr++) {
            if (find(attributs[attr], list_fields_tensor_time) ) {
                for(unsigned d=0;d<tensor_comp.size();d++){
                    String name_field; name_field << name_fields << "/pt_"<<time<<"/"<<attributs[attr]<<"/"<<lists[i]<<"/"<<tensor_comp[d];
                    f <<"           <DataItem Name=\"" << name_field.c_str() <<"\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elems << " \">" << input_hdf5.c_str() <<":"<< name_field.c_str() <<" </DataItem>" << endl;                
                }        
            }
            else if (find(attributs[attr], list_fields_vector_time) ) {
                for(unsigned d=0;d<DIM;d++){
                    String name_field; name_field << name_fields << "/pt_"<<time<<"/"<<attributs[attr]<<"/"<<lists[i]<<"/"<<vector_comp[d];
                    f <<"           <DataItem Name=\"" << name_field.c_str() <<"\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elems << " \">" << input_hdf5.c_str() <<":"<< name_field.c_str() <<" </DataItem>" << endl;                
                }        
            }
            else if (find(attributs[attr], list_fields_scalar_time) ) {
                String name_field; name_field << name_fields << "/pt_"<<time<<"/"<<attributs[attr]<<"/"<<lists[i];
                f <<"           <DataItem Name=\"" << name_field.c_str() <<"\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elems << " \">" << input_hdf5.c_str() <<":"<< name_field.c_str() << " </DataItem>" << endl;
            }
            else if (find(attributs[attr], list_fields_global)) {
                String name_field; name_field << name_elements << "/"<<lists[i]<<"/"<<attributs[attr];
                f <<"           <DataItem Name=\"" << name_field.c_str() <<"\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elems << " \">" << input_hdf5.c_str() <<":"<< name_field.c_str() << " </DataItem>" << endl;
            }
        }
    }
}

void write_grids(std::ofstream &f,String input_hdf5, String name_group_elements, String name_nodes, BasicVec<int> list, int nb_nodes, String generic_grid_name, String name_fields, BasicVec<String>  attributs, int nt, TYPE val_time, int type_element, int i_proc) {
    Hdf hdf(input_hdf5.c_str());

    for (unsigned i=0; i< list.size(); i++) {
        String name_list;
        name_list << name_group_elements <<  "/list_" <<  list[i];
        String name_list_c0=name_list+"/mesh_c0";
        int nb_elems;
        hdf.read_size(name_list_c0,nb_elems);
        int nb_nodes_elem;
        String JOIN, name_element_xdmf;
        
        if(type_element==0){
            int pattern_id;
            hdf.read_tag(name_list,"pattern_id",pattern_id);
            if (pattern_id==0 or pattern_id==1) {
                nb_nodes_elem=3;
                JOIN="JOIN($0 , $1 , $2  )";
                name_element_xdmf="Triangle";
            }
            else if (pattern_id==2 or pattern_id==3) {
                nb_nodes_elem=4;
                JOIN="JOIN($0 , $1 , $2  , $3)";
                name_element_xdmf="Tetrahedron";
            }
            else {
                std::cerr << "Type d'element enfant non implementé" ;
                assert(0);
            }
        }else if(type_element==1){  
            int interface_id;
            hdf.read_tag(name_list,"interface_id",interface_id);
            if (interface_id==0 or interface_id==1) {
                nb_nodes_elem=2;
                JOIN="JOIN($0 , $1 )";
                name_element_xdmf="Bar";
            }
            else if (interface_id==2 or interface_id==3) {
                nb_nodes_elem=3;
                JOIN="JOIN($0 , $1 , $2  )";
                name_element_xdmf="Triangle";
            }
            else {
                std::cerr << "Type d'element enfant non implementé" ;
                assert(0);
            }
        }
        
        f<<"                    <Grid Name=\""<< generic_grid_name.c_str() << "_" << i <<"\">" << endl;
        f<<"                            <Time Value=\""<<val_time<<"\" />" << endl;
        f<<"                            <Topology Type=\""<<name_element_xdmf.c_str()<<"\" NumberOfElements=\" "<< nb_elems << " \" >" << endl;
        f<<"                                    <DataItem Dimensions=\" "<< nb_elems << "  " << nb_nodes_elem <<" \" ItemType=\"Function\" Function=\""<<JOIN.c_str()<<"\"> " <<endl;
        for (unsigned j=0;j<nb_nodes_elem ; j++) {
            String data_item;
            data_item << name_list << "/mesh_c" <<j ;
            f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\""<< data_item.c_str() <<"\"] </DataItem> " << endl;
        }
        f<<"                                     </DataItem> " <<endl;
        f<<"                            </Topology>" <<endl;
#if DIM==2
        f<<"                            <Geometry Type=\"XY_Z\">"<<endl;
#else
        f<<"                            <Geometry Type=\"X_Y_Z\">"<<endl;
#endif
        BasicVec<String> dimensions("x","y","z");
        for(unsigned d=0;d<DIM;d++){
            String name_coor_node; name_coor_node << name_nodes.c_str() << "/"<< dimensions[d]<<"_proc_"<<i_proc;
            f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\""<<name_coor_node.c_str()<<"\"] </DataItem> " << endl;
        }
        f<<"                            </Geometry>" <<endl;
        for (unsigned attr=0;attr<attributs.size();attr++) {
            if (attributs[attr]=="displacements") {
                f<<"                            <Attribute Name=\"displacements\"  AttributeType=\"Vector\" Center=\"Node\">" << endl;
                f<<"                                    <DataItem Dimensions=\" "<< nb_nodes << " "<< DIM <<" \" ItemType=\"Function\" Function=\""<<JOIN.c_str()<<"\"> " <<endl;
                f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"dx_"<<nt<<"\"] </DataItem> " << endl;
                f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"dy_"<<nt<<"\"] </DataItem> " << endl;
#if DIM==3
                f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"dz_"<<nt<<"\"] </DataItem> " << endl;
#endif
                f<<"                                     </DataItem> " <<endl;
                f<<"                            </Attribute>"<<endl;
            }
            else if(attributs[attr]=="sigma") {
#if DIM==2
                int nb_comp_tensor=3;
                String JOIN_tensor="JOIN($0 , $1 , $2 )";
                BasicVec<String> tensor_comp_sigma=BasicVec<String>("sxx","syy","sxy");
#else
                int nb_comp_tensor=6;
                String JOIN_tensor="JOIN($0 , $1 , $2, $3 , $4 , $5 )";
                BasicVec<String> tensor_comp_sigma=BasicVec<String>("sxx","syy","szz","sxy","sxz","syz");
#endif
                f<<"                            <Attribute AttributeType=\"Tensor6\" Name=\"sigma\" Center=\"Cell\">" << endl;
                f<<"                                    <DataItem Dimensions=\" "<< nb_elems << " " << nb_comp_tensor << " \" ItemType=\"Function\" Function=\""<<JOIN_tensor.c_str()<<"\"> " <<endl;
                for(unsigned nc=0;nc<nb_comp_tensor;nc++)
                    f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\""<< name_group_elements.c_str() << "_"<<tensor_comp_sigma[nc].c_str()<<"_"<<nt<<"\"] </DataItem> " << endl;
                f<<"                                    </DataItem> " <<endl;
                f<<"                            </Attribute>"<<endl;
            }
            else if(attributs[attr]=="epsilon") {
#if DIM==2
                int nb_comp_tensor=3;
                String JOIN_tensor="JOIN($0 , $1 , $2 )";
                BasicVec<String> tensor_comp_sigma=BasicVec<String>("exx","eyy","exy");
#else
                int nb_comp_tensor=6;
                String JOIN_tensor="JOIN($0 , $1 , $2, $3 , $4 , $5 )";
                BasicVec<String> tensor_comp_sigma=BasicVec<String>("exx","eyy","ezz","exy","exz","eyz");
#endif
                f<<"                            <Attribute AttributeType=\"Tensor6\" Name=\"epsilon\" Center=\"Cell\">" << endl;
                f<<"                                    <DataItem Dimensions=\" "<< nb_elems << " " << nb_comp_tensor << " \" ItemType=\"Function\" Function=\""<<JOIN_tensor.c_str()<<"\"> " <<endl;
                for(unsigned nc=0;nc<nb_comp_tensor;nc++)
                    f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\""<< name_group_elements.c_str() << "_"<<tensor_comp_sigma[nc].c_str()<<"_"<<nt<<"\"] </DataItem> " << endl;
                f<<"                                    </DataItem> " <<endl;
                f<<"                            </Attribute>"<<endl;
            }
            else if(attributs[attr]=="sigma_von_mises") {
                f<<"                            <Attribute AttributeType=\"Scalar\" Name=\"sigma_von_mises\" Center=\"Cell\">" << endl;
                f<<"                                    <DataItem Dimensions=\" "<< nb_elems << " 1 \" Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\""<< name_group_elements.c_str() << "_smises_"<< nt<<"\"] </DataItem> " << endl;
                f<<"                            </Attribute>"<<endl;               
            }
        }
        f<<"                    </Grid>"<< endl;
    }
}




void write_grids_2(std::ofstream &f,String name_hdf5, String name_elements, String name_nodes, String name_fields, String generic_grid_name, BasicVec<String>  attributs, int time, int i_proc) {
    String input_hdf5; input_hdf5 << name_hdf5 <<"_"<<i_proc<<".h5";
    Hdf hdf(input_hdf5.c_str());
    int nb_nodes;
    String data_node_x = name_nodes + "/x";
    hdf.read_size(data_node_x,nb_nodes);
    BasicVec<String> lists;
    lists=hdf.list_dir(name_elements);

    BasicVec<String> list_fields_tensor_time("sigma","epsilon","sigma_skin", "epsilon_skin");
    BasicVec<String> list_fields_vector_time("F", "W", "Fchap", "Wchap");
    BasicVec<String> list_fields_scalar_time("sigma_von_mises","sigma_von_mises_skin");
    BasicVec<String> list_fields_global("num_proc","material","num_group", "number", "nature");

    for (unsigned i=0; i< lists.size(); i++) {
        String name_list; name_list << name_elements <<  "/" <<lists[i];

        String num_list=lists[i].end_from(5);
        
        String name_list_c0=name_list+"/mesh_c0";
        int nb_elems;
        hdf.read_size(name_list_c0,nb_elems);
        int nb_nodes_elem;
        String JOIN, name_element_xdmf;
        
        String base;
        hdf.read_tag(name_list,"base",base);
        if (base=="Bar" or base=="Bar_3") {
            nb_nodes_elem=2;
            JOIN="JOIN($0 , $1 )";
            name_element_xdmf="Bar";
        }
        else if (base=="Triangle" or base=="Triangle_6") {
            nb_nodes_elem=3;
            JOIN="JOIN($0 , $1 , $2  )";
            name_element_xdmf="Triangle";
        }
        else if (base=="Quadrilateral" ) {
            nb_nodes_elem=4;
            JOIN="JOIN($0 , $1 , $2, $3  )";
            name_element_xdmf="Quadrilateral";
        }
        else if (base=="Tetrahedron" or base=="Tetrahedron_10") {
            nb_nodes_elem=4;
            JOIN="JOIN($0 , $1 , $2  , $3)";
            name_element_xdmf="Tetrahedron";
        }
        else if (base=="Hexahedron" ) {
            nb_nodes_elem=8;
            JOIN="JOIN($0 , $1 , $2  , $3, $4 , $5 , $6  , $7 )";
            name_element_xdmf="Hexahedron";
        }
        else {
            std::cerr << "Type d'element non implementé - creation grids xdmf" ;
            assert(0);
        }
        
        f<<"                    <Grid Name=\""<< generic_grid_name.c_str() << "_" << num_list.c_str() <<"\">" << endl;
        //reference a la topology (connectivites)
        f<<"                            <Topology Type=\""<<name_element_xdmf.c_str()<<"\" NumberOfElements=\" "<< nb_elems << " \" >" << endl;
        f<<"                                    <DataItem Dimensions=\" "<< nb_elems << "  " << nb_nodes_elem <<" \" ItemType=\"Function\" Function=\""<<JOIN.c_str()<<"\"> " <<endl;
        for (unsigned j=0;j<nb_nodes_elem ; j++) {
            String data_item;
            data_item << name_list << "/mesh_c" <<j ;
            f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\""<< data_item.c_str() <<"\"] </DataItem> " << endl;
        }
        f<<"                                     </DataItem> " <<endl;
        f<<"                            </Topology>" <<endl;
        //reference aux noeuds
#if DIM==2
        f<<"                            <Geometry Type=\"XY_Z\">"<<endl;
        String JOIN_vector="JOIN($0 , $1 )";
#else
        f<<"                            <Geometry Type=\"X_Y_Z\">"<<endl;
        String JOIN_vector="JOIN($0 , $1 , $2)";
#endif
        BasicVec<String> dimensions("x","y","z");
        for(unsigned d=0;d<DIM;d++){
            String name_coor_node; name_coor_node << name_nodes.c_str() << "/"<< dimensions[d]<<"_proc_"<<i_proc;
            f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\""<<name_coor_node.c_str()<<"\"] </DataItem> " << endl;
        }
        f<<"                            </Geometry>" <<endl;
        //reference aux attributs
        for (unsigned attr=0;attr<attributs.size();attr++) {
            if (attributs[attr]=="displacements" or attributs[attr]=="displacements_skin") {
                f<<"                            <Attribute Name=\""<<attributs[attr].c_str()<<"\"  AttributeType=\"Vector\" Center=\"Node\">" << endl;
                f<<"                                    <DataItem Dimensions=\" "<< nb_nodes << " "<< DIM <<" \" ItemType=\"Function\" Function=\""<<JOIN_vector.c_str()<<"\"> " <<endl;
                for(unsigned d=0;d<DIM;d++){
                    String name_field; name_field << name_fields.c_str() <<"/pt_"<<time<<"/"<<attributs[attr]<<"/"<<dimensions[d]<<"_proc_"<<i_proc;
                    f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\""<<name_field.c_str()<<"\"] </DataItem> " << endl;
                }
                f<<"                                     </DataItem> " <<endl;
                f<<"                            </Attribute>"<<endl;
            }
            else if (find(attributs[attr], list_fields_vector_time)) {
                f<<"                            <Attribute Name=\""<<attributs[attr].c_str()<<"\"  AttributeType=\"Vector\" Center=\"Cell\">" << endl;
                f<<"                                    <DataItem Dimensions=\" "<< nb_elems << " "<< DIM <<" \" ItemType=\"Function\" Function=\""<<JOIN_vector.c_str()<<"\"> " <<endl;
                for(unsigned d=0;d<DIM;d++){
                    String name_field; name_field << name_fields.c_str() <<"/pt_"<<time<<"/"<<attributs[attr]<<"/"<<lists[i]<<"/"<<dimensions[d];
                    f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\""<<name_field.c_str()<<"\"] </DataItem> " << endl;
                }
                f<<"                                     </DataItem> " <<endl;
                f<<"                            </Attribute>"<<endl;
            }
            else if(find(attributs[attr], list_fields_tensor_time)) {
#if DIM==2
                int nb_comp_tensor=3;
                String JOIN_tensor="JOIN($0 , $1 , $2 )";
                BasicVec<String> tensor_comp=("xx","yy","xy");
#else
                int nb_comp_tensor=6;
                String JOIN_tensor="JOIN($0 , $1 , $2, $3 , $4 , $5 )";
                BasicVec<String> tensor_comp("xx","yy","zz","xy","xz","yz");
#endif
                f<<"                            <Attribute AttributeType=\"Tensor6\" Name=\""<<attributs[attr].c_str() <<"\" Center=\"Cell\">" << endl;
                f<<"                                    <DataItem Dimensions=\" "<< nb_elems << " " << tensor_comp.size() << " \" ItemType=\"Function\" Function=\""<<JOIN_tensor.c_str()<<"\"> " <<endl;
                
                for(unsigned d=0;d<tensor_comp.size();d++){
                    String name_field; name_field << name_fields << "/pt_"<<time<<"/"<<attributs[attr]<<"/"<<lists[i]<<"/"<<tensor_comp[d];
                    f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\""<< name_field.c_str() <<"\"] </DataItem> " << endl;
                }
                f<<"                                    </DataItem> " <<endl;
                f<<"                            </Attribute>"<<endl;
            }
            else if(find(attributs[attr], list_fields_scalar_time)) {
                f<<"                            <Attribute AttributeType=\"Scalar\" Name=\""<<attributs[attr].c_str()<<"\" Center=\"Cell\">" << endl;
                String name_field; name_field << name_fields << "/pt_"<<time<<"/"<<attributs[attr]<<"/"<<lists[i];
                                    PRINT(name_field);

                f<<"                                    <DataItem Dimensions=\" "<< nb_elems << " 1 \" Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\""<< name_field.c_str() <<"\"] </DataItem> " << endl;
                f<<"                            </Attribute>"<<endl;               
            }
            else if(find(attributs[attr], list_fields_global)) {
                f<<"                            <Attribute AttributeType=\"Scalar\" Name=\""<<attributs[attr].c_str()<<"\" Center=\"Cell\">" << endl;
                String name_field; name_field << name_elements << "/"<<lists[i]<<"/"<<attributs[attr];
                f<<"                                    <DataItem Dimensions=\" "<< nb_elems << " 1 \" Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\""<< name_field.c_str() <<"\"] </DataItem> " << endl;
                f<<"                            </Attribute>"<<endl;               
            }        
        }
        f<<"                    </Grid>"<< endl;
    }
}
