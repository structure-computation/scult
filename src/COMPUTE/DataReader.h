#ifndef DATA_READER_H
#define DATA_READER_H

// #include "DataUser.h"
#include "FieldStructureCompactClass.h"

BEG_METIL_NAMESPACE;

class DataReader {
public:
    virtual ~DataReader() = 0;
    virtual void launch_read_data_materials_group_elements(Ps<FieldStructureCompactClass> field_structure_compact_CPU, Ps<FieldStructureCompactClass> field_structure_compact_GPU, int i_res, double t) = 0; 
    virtual void launch_read_data_bc_volume_group_elements(Ps<FieldStructureCompactClass> field_structure_compact_CPU, Ps<FieldStructureCompactClass> field_structure_compact_GPU, int i_res, int num_step, double t) = 0;
    virtual void launch_read_data_links_group_interfaces(Ps<FieldStructureCompactClass> field_structure_compact_CPU, Ps<FieldStructureCompactClass> field_structure_compact_GPU, int i_res, double t) = 0;
    virtual void launch_read_data_bc_group_interfaces(Ps<FieldStructureCompactClass> field_structure_compact_CPU, Ps<FieldStructureCompactClass> field_structure_compact_GPU, int i_res, int num_step, double t) = 0;
};

// DataReader *NEW_DataReader( DataUser &data_user );

END_METIL_NAMESPACE;

#endif // DATA_READER_H
