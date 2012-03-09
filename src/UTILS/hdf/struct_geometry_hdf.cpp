#ifndef STRUCT_GEOMETRY_HDF
#define STRUCT_GEOMETRY_HDF

#include "struct_geometry_hdf.h"

using namespace Metil;

void Geometry_Hdf::write_to( Hdf &hdf, const String &name ) {
        nodes.write_to(hdf,name+"/nodes");

        String name_group_0;
        name_group_0 << name << "/elements_0";        
        int nb_list_0=0;
        elements_0.write_to(hdf,name_group_0, nb_list_0);
        nb_list_elements_0=nb_list_0;
        hdf.add_tag(name_group_0,"nb_list",nb_list_0);
        
        String name_group;
        name_group << name << "/elements_1";
        int nb_list_1=0;
        elements_1_edge.write_to(hdf,name_group,nb_list_1);
        nb_list_elements_1_edge=nb_list_1;
        hdf.add_tag(name_group,"nb_list_edge",nb_list_elements_1_edge);  
        elements_1_interior.write_to(hdf,name_group,nb_list_1);
        nb_list_elements_1_interior=nb_list_1-nb_list_elements_1_edge;
        hdf.add_tag(name_group,"nb_list_interior",nb_list_elements_1_interior);         
        elements_1_link.write_to(hdf,name_group,nb_list_1);
        nb_list_elements_1_link=nb_list_1-nb_list_elements_1_edge-nb_list_elements_1_interior;
        hdf.add_tag(name_group,"nb_list_link",nb_list_elements_1_link);
        hdf.add_tag(name_group,"nb_list",nb_list_1);
                         
    }
    
void Geometry_Hdf::read_from( Hdf &hdf, const String &name ) {
        nodes.read_from(hdf,name+"/nodes");
/*        elements_0.read_from(hdf,name+"/elements_0");
        elements_1.read_from(hdf,name+"/elements_1");
        connect_interfaces.read_from(hdf,name+"/connect_interfaces");
        num_group_patterns.read_from(hdf, name+"/num_group_patterns");
        num_group_interfaces.read_from(hdf, name+"/num_group_interfaces");
        type.read_from(hdf,name+"/type");
        nb_sst.read_from(hdf,name+"/nb_sst");
        nb_inter.read_from(hdf,name+"/nb_inter");
        interfaces_num_pattern_0.read_from(hdf,name+"/interfaces_num_pattern_0");     
        interfaces_num_pattern_1.read_from(hdf,name+"/interfaces_num_pattern_1");
        patterns_num_interfaces.read_from(hdf,name+"/patterns_num_interfaces");*/
    }

#endif