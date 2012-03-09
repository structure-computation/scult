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
#include "struct_hdf.h"

void write_xdmf_geom_pattern_3(string output_xdmf, string input_hdf5, Geometry_Hdf &Geometry, int num_level)
{
    
    std::ofstream f(output_xdmf.c_str());
    
    int nb_patterns=Geometry.connect_patterns.c0.size();
    int nb_nodes=Geometry.nodes.x.size();
    int nb_inter=Geometry.connect_interfaces.c0.size();

    
f << "<Xdmf Version=\"2.0\">" << endl; 
f << "  <Domain>" << endl;
f <<"           <DataItem Name=\"X\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/nodes/x </DataItem>" << endl;
f <<"           <DataItem Name=\"Y\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/nodes/y </DataItem>" << endl;
f <<"           <DataItem Name=\"Z\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/nodes/z </DataItem>" << endl;
f <<"           <DataItem Name=\"patterns_c0\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_patterns << " 1\">" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/connect_patterns/c0 </DataItem>" << endl;
f <<"           <DataItem Name=\"patterns_c1\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_patterns << " 1\">" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/connect_patterns/c1 </DataItem>" << endl;
f <<"           <DataItem Name=\"patterns_c2\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_patterns << " 1\" >" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/connect_patterns/c2 </DataItem>" << endl;
f <<"           <DataItem Name=\"patterns_c3\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_patterns << " 1\">" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/connect_patterns/c3 </DataItem>" << endl;
f <<"           <DataItem Name=\"inter_c0\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_inter << " 1\">" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/connect_interfaces/c0 </DataItem>" << endl;
f <<"           <DataItem Name=\"inter_c1\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_inter << " 1\">" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/connect_interfaces/c1 </DataItem>" << endl;
f <<"           <DataItem Name=\"inter_c2\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_inter << " 1\" >" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/connect_interfaces/c2 </DataItem>" << endl;
//Attributs
f <<"           <DataItem Name=\"num_group_patterns\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_patterns << " 1\">" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/num_group_patterns </DataItem>" << endl;
f <<"           <DataItem Name=\"type\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_inter << " 1\">" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/type </DataItem>" << endl;
f <<"           <DataItem Name=\"num_group_interfaces\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_inter << " 1\">" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/num_group_interfaces </DataItem>" << endl;

f<< "           <Grid Name=\"Geometry\" GridType=\"Tree\">" << endl;
f<<"                    <Grid Name=\"Tetrahedrons\">" << endl;
f<<"                            <Topology Type=\"Tetrahedron\" NumberOfElements=\" "<< nb_patterns << " \" >" << endl;
f<<"                                    <DataItem Dimensions=\" "<< nb_patterns << "  4 \" ItemType=\"Function\" Function=\"JOIN($0 , $1 , $2  , $3)\"> " <<endl;
f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"patterns_c0\"] </DataItem> " << endl;
f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"patterns_c1\"] </DataItem> " << endl;
f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"patterns_c2\"] </DataItem> " << endl;
f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"patterns_c3\"] </DataItem> " << endl;
f<<"                                     </DataItem> " <<endl;
f<<"                            </Topology>" <<endl;
f<<"                            <Geometry Type=\"X_Y_Z\">"<<endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"X\"] </DataItem> " << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"Y\"] </DataItem> " << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"Z\"] </DataItem> " << endl;
f<<"                            </Geometry>" <<endl;
f<<"                            <Attribute Name=\"Ex num_group\" Center=\"Cell\">" << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"num_group_patterns\"] </DataItem> " << endl;
f<<"                            </Attribute>"<<endl;
f<<"                    </Grid>"<< endl;
f<<"                    <Grid Name=\"Triangles\">" << endl;
f<<"                            <Topology Type=\"Triangle\" NumberOfElements=\" "<< nb_inter << " \" >" << endl;
f<<"                                    <DataItem Dimensions=\" "<< nb_inter << "  3 \" ItemType=\"Function\" Function=\"JOIN($0 , $1 , $2  )\"> " <<endl;
f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"inter_c0\"] </DataItem> " << endl;
f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"inter_c1\"] </DataItem> " << endl;
f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"inter_c2\"] </DataItem> " << endl;
f<<"                                     </DataItem> " <<endl;
f<<"                            </Topology>" <<endl;
f<<"                            <Geometry Type=\"X_Y_Z\">"<<endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"X\"] </DataItem> " << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"Y\"] </DataItem> " << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"Z\"] </DataItem> " << endl;
f<<"                            </Geometry>" <<endl;
f<<"                            <Attribute Name=\"Ex type\" Center=\"Cell\">" << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"type\"] </DataItem> " << endl;
f<<"                            </Attribute>"<<endl;
f<<"                            <Attribute Name=\"Ex num_group\" Center=\"Cell\">" << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"num_group_interfaces\"] </DataItem> " << endl;
f<<"                            </Attribute>"<<endl;
f<<"                    </Grid>"<< endl;
f<<"            </Grid>"<<endl;
f<<"    </Domain>"<< endl;
f<<"</Xdmf>"<<endl;

f.close();
}

void write_xdmf_geometry_behaviours_pattern_3(string output_xdmf, string input_hdf5, Geometry_Hdf &Geometry, Behaviours_Hdf &Behaviours, int num_level)
{
    
    std::ofstream f(output_xdmf.c_str());
    
    int nb_patterns=Geometry.connect_patterns.c0.size();
    int nb_nodes=Geometry.nodes.x.size();
    int nb_inter=Geometry.connect_interfaces.c0.size();

    
f << "<Xdmf Version=\"2.0\">" << endl; 
f << "  <Domain>" << endl;
f <<"           <DataItem Name=\"X\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/nodes/x </DataItem>" << endl;
f <<"           <DataItem Name=\"Y\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/nodes/y </DataItem>" << endl;
f <<"           <DataItem Name=\"Z\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/nodes/z </DataItem>" << endl;
f <<"           <DataItem Name=\"patterns_c0\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_patterns << " 1\">" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/connect_patterns/c0 </DataItem>" << endl;
f <<"           <DataItem Name=\"patterns_c1\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_patterns << " 1\">" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/connect_patterns/c1 </DataItem>" << endl;
f <<"           <DataItem Name=\"patterns_c2\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_patterns << " 1\" >" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/connect_patterns/c2 </DataItem>" << endl;
f <<"           <DataItem Name=\"patterns_c3\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_patterns << " 1\">" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/connect_patterns/c3 </DataItem>" << endl;
f <<"           <DataItem Name=\"inter_c0\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_inter << " 1\">" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/connect_interfaces/c0 </DataItem>" << endl;
f <<"           <DataItem Name=\"inter_c1\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_inter << " 1\">" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/connect_interfaces/c1 </DataItem>" << endl;
f <<"           <DataItem Name=\"inter_c2\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_inter << " 1\" >" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/connect_interfaces/c2 </DataItem>" << endl;
//Attributs
f <<"           <DataItem Name=\"num_group_patterns\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_patterns << " 1\">" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/num_group_patterns </DataItem>" << endl;
f <<"           <DataItem Name=\"behaviour_patterns\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_patterns << " 1\">" << input_hdf5 << ":/Level_" <<num_level <<"/Behaviours/patterns </DataItem>" << endl;
f <<"           <DataItem Name=\"type\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_inter << " 1\">" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/type </DataItem>" << endl;
f <<"           <DataItem Name=\"num_group_interfaces\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_inter << " 1\">" << input_hdf5 << ":/Level_" <<num_level <<"/Geometry/num_group_interfaces </DataItem>" << endl;
f <<"           <DataItem Name=\"behaviour_interfaces\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_inter << " 1\">" << input_hdf5 << ":/Level_" <<num_level <<"/Behaviours/interfaces </DataItem>" << endl;

f<< "           <Grid Name=\"Geometry\" GridType=\"Tree\">" << endl;
f<<"                    <Grid Name=\"Tetrahedrons\">" << endl;
f<<"                            <Topology Type=\"Tetrahedron\" NumberOfElements=\" "<< nb_patterns << " \" >" << endl;
f<<"                                    <DataItem Dimensions=\" "<< nb_patterns << "  4 \" ItemType=\"Function\" Function=\"JOIN($0 , $1 , $2  , $3)\"> " <<endl;
f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"patterns_c0\"] </DataItem> " << endl;
f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"patterns_c1\"] </DataItem> " << endl;
f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"patterns_c2\"] </DataItem> " << endl;
f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"patterns_c3\"] </DataItem> " << endl;
f<<"                                     </DataItem> " <<endl;
f<<"                            </Topology>" <<endl;
f<<"                            <Geometry Type=\"X_Y_Z\">"<<endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"X\"] </DataItem> " << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"Y\"] </DataItem> " << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"Z\"] </DataItem> " << endl;
f<<"                            </Geometry>" <<endl;
f<<"                            <Attribute Name=\"Ex num_group\" Center=\"Cell\">" << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"num_group_patterns\"] </DataItem> " << endl;
f<<"                            </Attribute>"<<endl;
f<<"                            <Attribute Name=\"Ex behaviour\" Center=\"Cell\">" << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"behaviour_patterns\"] </DataItem> " << endl;
f<<"                            </Attribute>"<<endl;
f<<"                    </Grid>"<< endl;
f<<"                    <Grid Name=\"Triangles\">" << endl;
f<<"                            <Topology Type=\"Triangle\" NumberOfElements=\" "<< nb_inter << " \" >" << endl;
f<<"                                    <DataItem Dimensions=\" "<< nb_inter << "  3 \" ItemType=\"Function\" Function=\"JOIN($0 , $1 , $2  )\"> " <<endl;
f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"inter_c0\"] </DataItem> " << endl;
f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"inter_c1\"] </DataItem> " << endl;
f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"inter_c2\"] </DataItem> " << endl;
f<<"                                     </DataItem> " <<endl;
f<<"                            </Topology>" <<endl;
f<<"                            <Geometry Type=\"X_Y_Z\">"<<endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"X\"] </DataItem> " << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"Y\"] </DataItem> " << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"Z\"] </DataItem> " << endl;
f<<"                            </Geometry>" <<endl;
f<<"                            <Attribute Name=\"Ex type\" Center=\"Cell\">" << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"type\"] </DataItem> " << endl;
f<<"                            </Attribute>"<<endl;
f<<"                            <Attribute Name=\"Ex num_group\" Center=\"Cell\">" << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"num_group_interfaces\"] </DataItem> " << endl;
f<<"                            </Attribute>"<<endl;
f<<"                            <Attribute Name=\"Ex behaviour\" Center=\"Cell\">" << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"behaviour_interfaces\"] </DataItem> " << endl;
f<<"                            </Attribute>"<<endl;
f<<"                    </Grid>"<< endl;
f<<"            </Grid>"<<endl;
f<<"    </Domain>"<< endl;
f<<"</Xdmf>"<<endl;

f.close();
}

void write_xdmf_fields_pattern_3(string output_xdmf, string input_hdf5, Fields_Hdf &Fields, int num_level)
{
    
    std::ofstream f(output_xdmf.c_str());
    
    int nb_elements=Fields.elements_in_patterns.c0.size();
    int nb_nodes=Fields.nodes_in_patterns.x.size();

    
f << "<Xdmf Version=\"2.0\">" << endl; 
f << "  <Domain>" << endl;
f <<"           <DataItem Name=\"X\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/nodes/x </DataItem>" << endl;
f <<"           <DataItem Name=\"Y\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/nodes/y </DataItem>" << endl;
f <<"           <DataItem Name=\"Z\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/nodes/z </DataItem>" << endl;
f <<"           <DataItem Name=\"patterns_c0\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_elements << " 1\">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/elements/c0 </DataItem>" << endl;
f <<"           <DataItem Name=\"patterns_c1\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_elements << " 1\">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/elements/c1 </DataItem>" << endl;
f <<"           <DataItem Name=\"patterns_c2\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_elements << " 1\" >" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/elements/c2 </DataItem>" << endl;
f <<"           <DataItem Name=\"patterns_c3\" Format=\"HDF\" NumberType=\"Int\" Dimensions=\" "<< nb_elements << " 1\">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/elements/c3 </DataItem>" << endl;
//Attributs
f <<"           <DataItem Name=\"dx\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/displacements/x </DataItem>" << endl;
f <<"           <DataItem Name=\"dy\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/displacements/y </DataItem>" << endl;
f <<"           <DataItem Name=\"dz\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_nodes << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/displacements/z </DataItem>" << endl;
f <<"           <DataItem Name=\"sxx\" Format=\"HDF\" NumberType=\"Float\" Precision=\"8\" Dimensions=\" "<< nb_elements << " \">" << input_hdf5 << ":/Level_" <<num_level <<"/Fields/sigma/xx </DataItem>" << endl;
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

f<< "           <Grid Name=\"Geometry\" GridType=\"Tree\">" << endl;
f<<"                    <Grid Name=\"Tetrahedrons\">" << endl;
f<<"                            <Topology Type=\"Tetrahedron\" NumberOfElements=\" "<< nb_elements << " \" >" << endl;
f<<"                                    <DataItem Dimensions=\" "<< nb_elements << "  4 \" ItemType=\"Function\" Function=\"JOIN($0 , $1 , $2  , $3)\"> " <<endl;
f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"patterns_c0\"] </DataItem> " << endl;
f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"patterns_c1\"] </DataItem> " << endl;
f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"patterns_c2\"] </DataItem> " << endl;
f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"patterns_c3\"] </DataItem> " << endl;
f<<"                                     </DataItem> " <<endl;
f<<"                            </Topology>" <<endl;
f<<"                            <Geometry Type=\"X_Y_Z\">"<<endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"X\"] </DataItem> " << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"Y\"] </DataItem> " << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"Z\"] </DataItem> " << endl;
f<<"                            </Geometry>" <<endl;
f<<"                            <Attribute Name=\"displacements\"  AttributeType=\"Vector\" Center=\"Node\">" << endl;
f<<"                                    <DataItem Dimensions=\" "<< nb_nodes << "  3 \" ItemType=\"Function\" Function=\"JOIN($0 , $1 , $2 )\"> " <<endl;
f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"dx\"] </DataItem> " << endl;
f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"dy\"] </DataItem> " << endl;
f<<"                                            <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"dz\"] </DataItem> " << endl;
f<<"                                     </DataItem> " <<endl;
f<<"                            </Attribute>"<<endl;
f<<"                            <Attribute AttributeType=\"Tensor6\" Name=\"sigma\" Center=\"Cell\">" << endl;
f<<"                                    <DataItem Dimensions=\" "<< nb_elements << "  6 \" ItemType=\"Function\" Function=\"JOIN($0 , $1 , $2, $3 , $4 , $5 )\"> " <<endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"sxx\"] </DataItem> " << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"sxy\"] </DataItem> " << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"sxz\"] </DataItem> " << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"syy\"] </DataItem> " << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"syz\"] </DataItem> " << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"szz\"] </DataItem> " << endl;
f<<"                                    </DataItem> " <<endl;
f<<"                            </Attribute>"<<endl;
f<<"                            <Attribute AttributeType=\"Tensor6\" Name=\"epsilon\" Center=\"Cell\">" << endl;
f<<"                                    <DataItem Dimensions=\" "<< nb_elements << "  6 \" ItemType=\"Function\" Function=\"JOIN($0 , $1 , $2, $3 , $4 , $5 )\"> " <<endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"exx\"] </DataItem> " << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"exy\"] </DataItem> " << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"exz\"] </DataItem> " << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"eyy\"] </DataItem> " << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"eyz\"] </DataItem> " << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"ezz\"] </DataItem> " << endl;
f<<"                                    </DataItem> " <<endl;
f<<"                            </Attribute>"<<endl;
f<<"                            <Attribute AttributeType=\"Scalar\" Name=\"sigma_von_mises\" Center=\"Cell\">" << endl;
f<<"                                    <DataItem Reference=\"XML\"> /Xdmf/Domain/DataItem[@Name=\"smises\"] </DataItem> " << endl;
f<<"                            </Attribute>"<<endl;

f<<"                    </Grid>"<<endl;
f<<"            </Grid>"<<endl;
f<<"    </Domain>"<< endl;
f<<"</Xdmf>"<<endl;

f.close();
}

