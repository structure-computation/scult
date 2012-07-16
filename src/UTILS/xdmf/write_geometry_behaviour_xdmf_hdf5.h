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

#include "containers/vec.h"
#include "struct_geometry_hdf.h"

void write_xdmf_geom_behaviour_pattern_3(Sc2String output_xdmf, Sc2String input_hdf5, Geometry_Hdf &Geometry, int num_level)
{
    
    std::ofstream f(output_xdmf.c_str());
    Sc2String name_geometry, name_elements_0;
    name_geometry << ":/Level_" << num_level << "/Geometry" ;
    name_elements_0 << name_geometry << "/elements_0" ;
   
    int nb_nodes=Geometry.nodes.x.size();
    f << "<Xdmf Version=\"2.0\">" << endl; 
    f << "  <Domain>" << endl;
    //ecriture des donnees de noeuds
    f <<"           <DataItem Name=\"X\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " \">" << input_hdf5 << name_geometry << "/nodes/x </DataItem>" << endl;
    f <<"           <DataItem Name=\"Y\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " \">" << input_hdf5 << name_geometry << "/nodes/y </DataItem>" << endl;
    f <<"           <DataItem Name=\"Z\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " \">" << input_hdf5 << name_geometry << "/nodes/z </DataItem>" << endl;

    //ecriture des donnees de connectivites des elements_0
    for(unsigned i=0; i< Geometry.nb_list_elements_0; i++){
        Sc2String name_list;
        name_list << name_elements_0 <<"/list_" <<  i;
        int nb_elems=Geometry.elements_0.list_tetra[i].c0.size();
        for(unsigned j=0;j<4 ; j++){
            Sc2String name_data_item;
            name_data_item << "piece_" << i << "_c" << j;
            Sc2String data_item;
            data_item << name_list << "/c" <<j ;
            f <<"           <DataItem Name=\"" << name_data_item << "\" Format=\"HDF\"  Dimensions=\" "<< nb_elems << " 1\">" << input_hdf5 << data_item <<" </DataItem>" << endl;
        }
        Sc2String name_behaviour;
        name_behaviour << "behaviour_0_" <<i;
        int num_behaviour=Geometry.elements_0.num_behaviour[i];
        f <<"           <DataItem Name=\"" << name_behaviour << "\" Dimensions=\" "<< nb_elems << " 1\"> " ; 
        for(unsigned j=0;j<nb_elems; j++){
            f << num_behaviour << " ";
        }
        f <<" </DataItem>" << endl;
        
    }

    //ecriture des donnees de connectivites des elements_1 (bords et liaisons uniquement)
    Sc2String name_elements_1;     
    name_elements_1 << name_geometry << "/elements_1" ;
    for(unsigned i=0; i< Geometry.nb_list_elements_1_edge; i++){
        Sc2String name_list;
        name_list << name_elements_1 <<"/list_" <<  i;
        int nb_elems=Geometry.elements_1_edge.list_triangle[i].c0.size();
        for(unsigned j=0;j<3 ; j++){
            Sc2String name_data_item;
            name_data_item << "edge_" <<  i << "_c" << j;
            Sc2String data_item;
            data_item << name_list << "/c" <<j ;
            f <<"           <DataItem Name=\"" << name_data_item << "\" Format=\"HDF\"  Dimensions=\" "<< nb_elems << " 1\">" << input_hdf5 << data_item <<" </DataItem>" << endl;
        }
        Sc2String name_behaviour;
        name_behaviour << "behaviour_1_edge_" <<i;
        int num_behaviour=Geometry.elements_1_edge.num_behaviour[i];
        f <<"           <DataItem Name=\"" << name_behaviour << "\"  Dimensions=\" "<< nb_elems << " 1\"> " ; 
        for(unsigned j=0;j<nb_elems; j++){
            f << num_behaviour << " ";
        }
        f <<" </DataItem>" << endl;
        
    }
    for(unsigned i=0; i< Geometry.nb_list_elements_1_link; i++){
        Sc2String name_list;
        name_list << name_elements_1 <<"/list_" <<  i+Geometry.nb_list_elements_1_edge+Geometry.nb_list_elements_1_interior;
        int nb_elems=Geometry.elements_1_link.list_triangle[i].c0.size();    
        for(unsigned j=0;j<3 ; j++){
            Sc2String name_data_item;
            name_data_item << "link_" << i << "_c" << j;
            Sc2String data_item;
            data_item << name_list << "/c" << j;
            f <<"           <DataItem Name=\"" << name_data_item << "\" Format=\"HDF\"  Dimensions=\" "<< nb_elems << " 1\">" << input_hdf5 << data_item <<" </DataItem>" << endl;
        }
        Sc2String name_behaviour;
        name_behaviour << "behaviour_1_link_" <<i;
        int num_behaviour=Geometry.elements_1_link.num_behaviour[i];
        f <<"           <DataItem Name=\"" << name_behaviour << "\"  Dimensions=\" "<< nb_elems << " 1\"> " ; 
        for(unsigned j=0;j<nb_elems; j++){
            f << num_behaviour << " ";
        }
        f <<" </DataItem>" << endl;    
    }

//    f <<"           <DataItem Name=\"num_group_patterns\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_patterns << " 1\">" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/num_group_patterns </DataItem>" << endl;
// f <<"           <DataItem Name=\"type\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_inter << " 1\">" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/type </DataItem>" << endl;
// f <<"           <DataItem Name=\"num_group_interfaces\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_inter << " 1\">" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/num_group_interfaces </DataItem>" << endl;

    //ecriture de la geometrie_0 (pieces)
    f<< "           <Grid Name=\"Geometry_0\" GridType=\"Tree\">" << endl;
    for(unsigned i=0; i< Geometry.nb_list_elements_0; i++){
        Sc2String name_list;
        name_list << "piece_" <<  i;
        int nb_elems=Geometry.elements_0.list_tetra[i].c0.size();
        Sc2String name_behaviour;
        name_behaviour << "behaviour_0_" <<i;
        f<<"                    <Grid Name=\""<< name_list <<"\">" << endl;
        f<<"                            <Topology Type=\"Tetrahedron\" NumberOfElements=\" "<< nb_elems << " \" >" << endl;
        f<<"                                    <DataItem Dimensions=\" "<< nb_elems << "  4 \" ItemType=\"Function\" Function=\"JOIN($0 , $1 , $2  , $3)\"> " <<endl;
        for(unsigned j=0;j<4 ; j++){
            Sc2String name_data_item;
            name_data_item << "piece_" << i << "_c" << j;
            f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\""<< name_data_item <<"\"] </DataItem> " << endl;
        }
        f<<"                                     </DataItem> " <<endl;
        f<<"                            </Topology>" <<endl;
        f<<"                            <Geometry Type=\"X_Y_Z\">"<<endl;
        f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"X\"] </DataItem> " << endl;
        f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"Y\"] </DataItem> " << endl;
        f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"Z\"] </DataItem> " << endl;
        f<<"                            </Geometry>" <<endl;
        f<<"                            <Attribute Name=\"Materiau\" Center=\"Cell\" AttributeType=\"Scalar\" Dimensions=\" "<< nb_elems << " 1 \">" << endl;
        f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\""<< name_behaviour << "\"] </DataItem> " << endl;
        f<<"                            </Attribute>"<<endl;
        f<<"                    </Grid>"<< endl;
    }
    f<<"            </Grid>"<<endl;
    
    //ecriture de la geometrie_1 (interfaces)
    f<< "           <Grid Name=\"Geometry_1\" GridType=\"Tree\">" << endl;
        f<< "           <Grid Name=\"Edges\" GridType=\"Tree\">" << endl;
        for(unsigned i=0; i< Geometry.nb_list_elements_1_edge; i++){
            Sc2String name_list;
            name_list << "edge_" <<  i;
            int nb_elems=Geometry.elements_1_edge.list_triangle[i].c0.size();
            Sc2String name_behaviour;
            name_behaviour << "behaviour_1_edge_" <<i;

            f<<"                    <Grid Name=\""<< name_list <<"\">" << endl;
            f<<"                            <Topology Type=\"Triangle\" NumberOfElements=\" "<< nb_elems << " \" >" << endl;
            f<<"                                    <DataItem Dimensions=\" "<< nb_elems << "  3 \" ItemType=\"Function\" Function=\"JOIN($0 , $1 , $2  )\"> " <<endl;
            for(unsigned j=0;j<3 ; j++){
                Sc2String name_data_item;
                name_data_item << "edge_" << i << "_c" << j;
                f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\""<< name_data_item <<"\"] </DataItem> " << endl;
            }
            f<<"                                     </DataItem> " <<endl;
            f<<"                            </Topology>" <<endl;
            f<<"                            <Geometry Type=\"X_Y_Z\">"<<endl;
            f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"X\"] </DataItem> " << endl;
            f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"Y\"] </DataItem> " << endl;
            f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"Z\"] </DataItem> " << endl;
            f<<"                            </Geometry>" <<endl;
            f<<"                            <Attribute Name=\"Comportement\" Center=\"Cell\" AttributeType=\"Scalar\" Dimensions=\" "<< nb_elems << " 1 \">" << endl;
            f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\""<< name_behaviour << "\"] </DataItem> " << endl;
            f<<"                            </Attribute>"<<endl;
            f<<"                    </Grid>"<< endl;
        }
        f<<"                </Grid>"<< endl;
    f<< "               <Grid Name=\"Links\" GridType=\"Tree\">" << endl;
    
    for(unsigned i=0; i< Geometry.nb_list_elements_1_link; i++){
        Sc2String name_list;
        name_list << "link_" <<  i;
        int nb_elems=Geometry.elements_1_link.list_triangle[i].c0.size();
        int num_behaviour=Geometry.elements_1_link.num_behaviour[i];
        Sc2String name_behaviour;
        name_behaviour << "behaviour_1_link_" <<i;

        f<<"                    <Grid Name=\" "<< name_list <<"\">" << endl;
        f<<"                            <Topology Type=\"Triangle\" NumberOfElements=\" "<< nb_elems << " \" >" << endl;
        f<<"                                    <DataItem Dimensions=\" "<< nb_elems << "  3 \" ItemType=\"Function\" Function=\"JOIN($0 , $1 , $2  )\"> " <<endl;
        for(unsigned j=0;j<3 ; j++){
            Sc2String name_data_item;
            name_data_item << "link_" << i << "_c" << j;
            f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\""<< name_data_item <<"\"] </DataItem> " << endl;
        }
        f<<"                                     </DataItem> " <<endl;
        f<<"                            </Topology>" <<endl;
        f<<"                            <Geometry Type=\"X_Y_Z\">"<<endl;
        f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"X\"] </DataItem> " << endl;
        f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"Y\"] </DataItem> " << endl;
        f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"Z\"] </DataItem> " << endl;
        f<<"                            </Geometry>" <<endl;
        f<<"                            <Attribute Name=\"Comportement\" Center=\"Cell\" AttributeType=\"Scalar\" Dimensions=\" "<< nb_elems << " 1 \">" << endl;
        f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\""<< name_behaviour << "\"] </DataItem> " << endl;
        f<<"                            </Attribute>"<<endl;
        f<<"                    </Grid>"<< endl;
    }
    f<<"                </Grid>"<< endl;
    f<<"            </Grid>"<<endl;
    f<<"    </Domain>"<< endl;
    f<<"</Xdmf>"<<endl;

f.close();
}

