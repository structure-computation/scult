#include "GeometryCompactClass.h"

BEG_METIL_NAMESPACE

void GeometryCompactClass::update_ptr_cpu_load( ST off ) {
    (char *&)patterns.types.data_ += off;
    for( ST i = 0; i < patterns.types.size_; ++i ) {
        (char *&)patterns.types.data_[ i ].permutation.data_ += off;
        (char *&)patterns.types.data_[ i ].sides.data_ += off;
        for( ST j = 0; j < patterns.types.data_[ i ].sides.size_; ++j ) {
            (char *&)patterns.types.data_[ i ].sides.data_[ j ].data_ += off;
        }
    }
    (char *&)mesh_nodes.data_ += off;
    for( ST i = 0; i < mesh_nodes.size_; ++i ) {
        (char *&)mesh_nodes.data_[ i ].data_ += off;
    }
    (char *&)nodes.data_ += off;
    for( ST i = 0; i < nodes.size_; ++i ) {
        (char *&)nodes.data_[ i ].data_ += off;
    }
    (char *&)group_elements.data_ += off;
    for( ST i = 0; i < group_elements.size_; ++i ) {
        (char *&)group_elements.data_[ i ].mesh_connectivities.data_ += off;
        for( ST j = 0; j < group_elements.data_[ i ].mesh_connectivities.size_; ++j ) {
            (char *&)group_elements.data_[ i ].mesh_connectivities.data_[ j ].data_ += off;
        }
        (char *&)group_elements.data_[ i ].connectivities.data_ += off;
        for( ST j = 0; j < group_elements.data_[ i ].connectivities.size_; ++j ) {
            (char *&)group_elements.data_[ i ].connectivities.data_[ j ].data_ += off;
        }
        (char *&)group_elements.data_[ i ].interface_group_id.data_ += off;
        for( ST j = 0; j < group_elements.data_[ i ].interface_group_id.size_; ++j ) {
            (char *&)group_elements.data_[ i ].interface_group_id.data_[ j ].data_ += off;
        }
        (char *&)group_elements.data_[ i ].interface_num_in_group.data_ += off;
        for( ST j = 0; j < group_elements.data_[ i ].interface_num_in_group.size_; ++j ) {
            (char *&)group_elements.data_[ i ].interface_num_in_group.data_[ j ].data_ += off;
        }
        (char *&)group_elements.data_[ i ].group_interfaces_id.data_ += off;
        for( ST j = 0; j < group_elements.data_[ i ].group_interfaces_id.size_; ++j ) {
            (char *&)group_elements.data_[ i ].group_interfaces_id.data_[ j ].data_ += off;
        }
        (char *&)group_elements.data_[ i ].side_N.data_ += off;
        for( ST j = 0; j < group_elements.data_[ i ].side_N.size_; ++j ) {
            (char *&)group_elements.data_[ i ].side_N.data_[ j ].data_ += off;
            for( ST k = 0; k < group_elements.data_[ i ].side_N.data_[ j ].size_; ++k ) {
                (char *&)group_elements.data_[ i ].side_N.data_[ j ].data_[ k ].data_ += off;
                for( ST l = 0; l < group_elements.data_[ i ].side_N.data_[ j ].data_[ k ].size_; ++l ) {
                    (char *&)group_elements.data_[ i ].side_N.data_[ j ].data_[ k ].data_[ l ].data_ += off;
                }
            }
        }
        (char *&)group_elements.data_[ i ].side_M.data_ += off;
        for( ST j = 0; j < group_elements.data_[ i ].side_M.size_; ++j ) {
            (char *&)group_elements.data_[ i ].side_M.data_[ j ].data_ += off;
            for( ST k = 0; k < group_elements.data_[ i ].side_M.data_[ j ].size_; ++k ) {
                (char *&)group_elements.data_[ i ].side_M.data_[ j ].data_[ k ].data_ += off;
            }
        }
    }
    (char *&)group_interfaces.data_ += off;
    for( ST i = 0; i < group_interfaces.size_; ++i ) {
        (char *&)group_interfaces.data_[ i ].group_elements_id.data_ += off;
        (char *&)group_interfaces.data_[ i ].patterns_id.data_ += off;
        (char *&)group_interfaces.data_[ i ].element_num_in_group.data_ += off;
        for( ST j = 0; j < group_interfaces.data_[ i ].element_num_in_group.size_; ++j ) {
            (char *&)group_interfaces.data_[ i ].element_num_in_group.data_[ j ].data_ += off;
        }
        (char *&)group_interfaces.data_[ i ].element_num_side.data_ += off;
        for( ST j = 0; j < group_interfaces.data_[ i ].element_num_side.size_; ++j ) {
            (char *&)group_interfaces.data_[ i ].element_num_side.data_[ j ].data_ += off;
        }
        (char *&)group_interfaces.data_[ i ].mesh_connectivities.data_ += off;
        for( ST j = 0; j < group_interfaces.data_[ i ].mesh_connectivities.size_; ++j ) {
            (char *&)group_interfaces.data_[ i ].mesh_connectivities.data_[ j ].data_ += off;
        }
        (char *&)group_interfaces.data_[ i ].connectivities.data_ += off;
        for( ST j = 0; j < group_interfaces.data_[ i ].connectivities.size_; ++j ) {
            (char *&)group_interfaces.data_[ i ].connectivities.data_[ j ].data_ += off;
        }
        (char *&)group_interfaces.data_[ i ].correspondance_between_nodes.data_ += off;
        for( ST j = 0; j < group_interfaces.data_[ i ].correspondance_between_nodes.size_; ++j ) {
            (char *&)group_interfaces.data_[ i ].correspondance_between_nodes.data_[ j ].data_ += off;
        }
        (char *&)group_interfaces.data_[ i ].Ne.data_ += off;
        for( ST j = 0; j < group_interfaces.data_[ i ].Ne.size_; ++j ) {
            (char *&)group_interfaces.data_[ i ].Ne.data_[ j ].data_ += off;
        }
        (char *&)group_interfaces.data_[ i ].Me.data_ += off;
    }
}

__global__
void GeometryCompactClass__update_ptr_gpu_load( GeometryCompactClass *obj, ST off ) {
    (char *&)obj->patterns.types.data_ += off;
    for( ST i = 0; i < obj->patterns.types.size_; ++i ) {
        (char *&)obj->patterns.types.data_[ i ].permutation.data_ += off;
        (char *&)obj->patterns.types.data_[ i ].sides.data_ += off;
        for( ST j = 0; j < obj->patterns.types.data_[ i ].sides.size_; ++j ) {
            (char *&)obj->patterns.types.data_[ i ].sides.data_[ j ].data_ += off;
        }
    }
    (char *&)obj->mesh_nodes.data_ += off;
    for( ST i = 0; i < obj->mesh_nodes.size_; ++i ) {
        (char *&)obj->mesh_nodes.data_[ i ].data_ += off;
    }
    (char *&)obj->nodes.data_ += off;
    for( ST i = 0; i < obj->nodes.size_; ++i ) {
        (char *&)obj->nodes.data_[ i ].data_ += off;
    }
    (char *&)obj->group_elements.data_ += off;
    for( ST i = 0; i < obj->group_elements.size_; ++i ) {
        (char *&)obj->group_elements.data_[ i ].mesh_connectivities.data_ += off;
        for( ST j = 0; j < obj->group_elements.data_[ i ].mesh_connectivities.size_; ++j ) {
            (char *&)obj->group_elements.data_[ i ].mesh_connectivities.data_[ j ].data_ += off;
        }
        (char *&)obj->group_elements.data_[ i ].connectivities.data_ += off;
        for( ST j = 0; j < obj->group_elements.data_[ i ].connectivities.size_; ++j ) {
            (char *&)obj->group_elements.data_[ i ].connectivities.data_[ j ].data_ += off;
        }
        (char *&)obj->group_elements.data_[ i ].interface_group_id.data_ += off;
        for( ST j = 0; j < obj->group_elements.data_[ i ].interface_group_id.size_; ++j ) {
            (char *&)obj->group_elements.data_[ i ].interface_group_id.data_[ j ].data_ += off;
        }
        (char *&)obj->group_elements.data_[ i ].interface_num_in_group.data_ += off;
        for( ST j = 0; j < obj->group_elements.data_[ i ].interface_num_in_group.size_; ++j ) {
            (char *&)obj->group_elements.data_[ i ].interface_num_in_group.data_[ j ].data_ += off;
        }
        (char *&)obj->group_elements.data_[ i ].group_interfaces_id.data_ += off;
        for( ST j = 0; j < obj->group_elements.data_[ i ].group_interfaces_id.size_; ++j ) {
            (char *&)obj->group_elements.data_[ i ].group_interfaces_id.data_[ j ].data_ += off;
        }
        (char *&)obj->group_elements.data_[ i ].side_N.data_ += off;
        for( ST j = 0; j < obj->group_elements.data_[ i ].side_N.size_; ++j ) {
            (char *&)obj->group_elements.data_[ i ].side_N.data_[ j ].data_ += off;
            for( ST k = 0; k < obj->group_elements.data_[ i ].side_N.data_[ j ].size_; ++k ) {
                (char *&)obj->group_elements.data_[ i ].side_N.data_[ j ].data_[ k ].data_ += off;
                for( ST l = 0; l < obj->group_elements.data_[ i ].side_N.data_[ j ].data_[ k ].size_; ++l ) {
                    (char *&)obj->group_elements.data_[ i ].side_N.data_[ j ].data_[ k ].data_[ l ].data_ += off;
                }
            }
        }
        (char *&)obj->group_elements.data_[ i ].side_M.data_ += off;
        for( ST j = 0; j < obj->group_elements.data_[ i ].side_M.size_; ++j ) {
            (char *&)obj->group_elements.data_[ i ].side_M.data_[ j ].data_ += off;
            for( ST k = 0; k < obj->group_elements.data_[ i ].side_M.data_[ j ].size_; ++k ) {
                (char *&)obj->group_elements.data_[ i ].side_M.data_[ j ].data_[ k ].data_ += off;
            }
        }
    }
    (char *&)obj->group_interfaces.data_ += off;
    for( ST i = 0; i < obj->group_interfaces.size_; ++i ) {
        (char *&)obj->group_interfaces.data_[ i ].group_elements_id.data_ += off;
        (char *&)obj->group_interfaces.data_[ i ].patterns_id.data_ += off;
        (char *&)obj->group_interfaces.data_[ i ].element_num_in_group.data_ += off;
        for( ST j = 0; j < obj->group_interfaces.data_[ i ].element_num_in_group.size_; ++j ) {
            (char *&)obj->group_interfaces.data_[ i ].element_num_in_group.data_[ j ].data_ += off;
        }
        (char *&)obj->group_interfaces.data_[ i ].element_num_side.data_ += off;
        for( ST j = 0; j < obj->group_interfaces.data_[ i ].element_num_side.size_; ++j ) {
            (char *&)obj->group_interfaces.data_[ i ].element_num_side.data_[ j ].data_ += off;
        }
        (char *&)obj->group_interfaces.data_[ i ].mesh_connectivities.data_ += off;
        for( ST j = 0; j < obj->group_interfaces.data_[ i ].mesh_connectivities.size_; ++j ) {
            (char *&)obj->group_interfaces.data_[ i ].mesh_connectivities.data_[ j ].data_ += off;
        }
        (char *&)obj->group_interfaces.data_[ i ].connectivities.data_ += off;
        for( ST j = 0; j < obj->group_interfaces.data_[ i ].connectivities.size_; ++j ) {
            (char *&)obj->group_interfaces.data_[ i ].connectivities.data_[ j ].data_ += off;
        }
        (char *&)obj->group_interfaces.data_[ i ].correspondance_between_nodes.data_ += off;
        for( ST j = 0; j < obj->group_interfaces.data_[ i ].correspondance_between_nodes.size_; ++j ) {
            (char *&)obj->group_interfaces.data_[ i ].correspondance_between_nodes.data_[ j ].data_ += off;
        }
        (char *&)obj->group_interfaces.data_[ i ].Ne.data_ += off;
        for( ST j = 0; j < obj->group_interfaces.data_[ i ].Ne.size_; ++j ) {
            (char *&)obj->group_interfaces.data_[ i ].Ne.data_[ j ].data_ += off;
        }
        (char *&)obj->group_interfaces.data_[ i ].Me.data_ += off;
    }
}

void GeometryCompactClass::update_ptr_gpu_load( ST off ) {
    GeometryCompactClass__update_ptr_gpu_load<<<1,1>>>( this, off );
}

void GeometryCompactClass::update_ptr_cpu_save( ST off ) {
    for( ST i = 0; i < patterns.types.size_; ++i ) {
        (char *&)patterns.types.data_[ i ].permutation.data_ += off;
        for( ST j = 0; j < patterns.types.data_[ i ].sides.size_; ++j ) {
            (char *&)patterns.types.data_[ i ].sides.data_[ j ].data_ += off;
        }
        (char *&)patterns.types.data_[ i ].sides.data_ += off;
    }
    (char *&)patterns.types.data_ += off;
    for( ST i = 0; i < mesh_nodes.size_; ++i ) {
        (char *&)mesh_nodes.data_[ i ].data_ += off;
    }
    (char *&)mesh_nodes.data_ += off;
    for( ST i = 0; i < nodes.size_; ++i ) {
        (char *&)nodes.data_[ i ].data_ += off;
    }
    (char *&)nodes.data_ += off;
    for( ST i = 0; i < group_elements.size_; ++i ) {
        for( ST j = 0; j < group_elements.data_[ i ].mesh_connectivities.size_; ++j ) {
            (char *&)group_elements.data_[ i ].mesh_connectivities.data_[ j ].data_ += off;
        }
        (char *&)group_elements.data_[ i ].mesh_connectivities.data_ += off;
        for( ST j = 0; j < group_elements.data_[ i ].connectivities.size_; ++j ) {
            (char *&)group_elements.data_[ i ].connectivities.data_[ j ].data_ += off;
        }
        (char *&)group_elements.data_[ i ].connectivities.data_ += off;
        for( ST j = 0; j < group_elements.data_[ i ].interface_group_id.size_; ++j ) {
            (char *&)group_elements.data_[ i ].interface_group_id.data_[ j ].data_ += off;
        }
        (char *&)group_elements.data_[ i ].interface_group_id.data_ += off;
        for( ST j = 0; j < group_elements.data_[ i ].interface_num_in_group.size_; ++j ) {
            (char *&)group_elements.data_[ i ].interface_num_in_group.data_[ j ].data_ += off;
        }
        (char *&)group_elements.data_[ i ].interface_num_in_group.data_ += off;
        for( ST j = 0; j < group_elements.data_[ i ].group_interfaces_id.size_; ++j ) {
            (char *&)group_elements.data_[ i ].group_interfaces_id.data_[ j ].data_ += off;
        }
        (char *&)group_elements.data_[ i ].group_interfaces_id.data_ += off;
        for( ST j = 0; j < group_elements.data_[ i ].side_N.size_; ++j ) {
            for( ST k = 0; k < group_elements.data_[ i ].side_N.data_[ j ].size_; ++k ) {
                for( ST l = 0; l < group_elements.data_[ i ].side_N.data_[ j ].data_[ k ].size_; ++l ) {
                    (char *&)group_elements.data_[ i ].side_N.data_[ j ].data_[ k ].data_[ l ].data_ += off;
                }
                (char *&)group_elements.data_[ i ].side_N.data_[ j ].data_[ k ].data_ += off;
            }
            (char *&)group_elements.data_[ i ].side_N.data_[ j ].data_ += off;
        }
        (char *&)group_elements.data_[ i ].side_N.data_ += off;
        for( ST j = 0; j < group_elements.data_[ i ].side_M.size_; ++j ) {
            for( ST k = 0; k < group_elements.data_[ i ].side_M.data_[ j ].size_; ++k ) {
                (char *&)group_elements.data_[ i ].side_M.data_[ j ].data_[ k ].data_ += off;
            }
            (char *&)group_elements.data_[ i ].side_M.data_[ j ].data_ += off;
        }
        (char *&)group_elements.data_[ i ].side_M.data_ += off;
    }
    (char *&)group_elements.data_ += off;
    for( ST i = 0; i < group_interfaces.size_; ++i ) {
        (char *&)group_interfaces.data_[ i ].group_elements_id.data_ += off;
        (char *&)group_interfaces.data_[ i ].patterns_id.data_ += off;
        for( ST j = 0; j < group_interfaces.data_[ i ].element_num_in_group.size_; ++j ) {
            (char *&)group_interfaces.data_[ i ].element_num_in_group.data_[ j ].data_ += off;
        }
        (char *&)group_interfaces.data_[ i ].element_num_in_group.data_ += off;
        for( ST j = 0; j < group_interfaces.data_[ i ].element_num_side.size_; ++j ) {
            (char *&)group_interfaces.data_[ i ].element_num_side.data_[ j ].data_ += off;
        }
        (char *&)group_interfaces.data_[ i ].element_num_side.data_ += off;
        for( ST j = 0; j < group_interfaces.data_[ i ].mesh_connectivities.size_; ++j ) {
            (char *&)group_interfaces.data_[ i ].mesh_connectivities.data_[ j ].data_ += off;
        }
        (char *&)group_interfaces.data_[ i ].mesh_connectivities.data_ += off;
        for( ST j = 0; j < group_interfaces.data_[ i ].connectivities.size_; ++j ) {
            (char *&)group_interfaces.data_[ i ].connectivities.data_[ j ].data_ += off;
        }
        (char *&)group_interfaces.data_[ i ].connectivities.data_ += off;
        for( ST j = 0; j < group_interfaces.data_[ i ].correspondance_between_nodes.size_; ++j ) {
            (char *&)group_interfaces.data_[ i ].correspondance_between_nodes.data_[ j ].data_ += off;
        }
        (char *&)group_interfaces.data_[ i ].correspondance_between_nodes.data_ += off;
        for( ST j = 0; j < group_interfaces.data_[ i ].Ne.size_; ++j ) {
            (char *&)group_interfaces.data_[ i ].Ne.data_[ j ].data_ += off;
        }
        (char *&)group_interfaces.data_[ i ].Ne.data_ += off;
        (char *&)group_interfaces.data_[ i ].Me.data_ += off;
    }
    (char *&)group_interfaces.data_ += off;
}

__global__
void GeometryCompactClass__update_ptr_gpu_save( GeometryCompactClass *obj, ST off ) {
    for( ST i = 0; i < obj->patterns.types.size_; ++i ) {
        (char *&)obj->patterns.types.data_[ i ].permutation.data_ += off;
        for( ST j = 0; j < obj->patterns.types.data_[ i ].sides.size_; ++j ) {
            (char *&)obj->patterns.types.data_[ i ].sides.data_[ j ].data_ += off;
        }
        (char *&)obj->patterns.types.data_[ i ].sides.data_ += off;
    }
    (char *&)obj->patterns.types.data_ += off;
    for( ST i = 0; i < obj->mesh_nodes.size_; ++i ) {
        (char *&)obj->mesh_nodes.data_[ i ].data_ += off;
    }
    (char *&)obj->mesh_nodes.data_ += off;
    for( ST i = 0; i < obj->nodes.size_; ++i ) {
        (char *&)obj->nodes.data_[ i ].data_ += off;
    }
    (char *&)obj->nodes.data_ += off;
    for( ST i = 0; i < obj->group_elements.size_; ++i ) {
        for( ST j = 0; j < obj->group_elements.data_[ i ].mesh_connectivities.size_; ++j ) {
            (char *&)obj->group_elements.data_[ i ].mesh_connectivities.data_[ j ].data_ += off;
        }
        (char *&)obj->group_elements.data_[ i ].mesh_connectivities.data_ += off;
        for( ST j = 0; j < obj->group_elements.data_[ i ].connectivities.size_; ++j ) {
            (char *&)obj->group_elements.data_[ i ].connectivities.data_[ j ].data_ += off;
        }
        (char *&)obj->group_elements.data_[ i ].connectivities.data_ += off;
        for( ST j = 0; j < obj->group_elements.data_[ i ].interface_group_id.size_; ++j ) {
            (char *&)obj->group_elements.data_[ i ].interface_group_id.data_[ j ].data_ += off;
        }
        (char *&)obj->group_elements.data_[ i ].interface_group_id.data_ += off;
        for( ST j = 0; j < obj->group_elements.data_[ i ].interface_num_in_group.size_; ++j ) {
            (char *&)obj->group_elements.data_[ i ].interface_num_in_group.data_[ j ].data_ += off;
        }
        (char *&)obj->group_elements.data_[ i ].interface_num_in_group.data_ += off;
        for( ST j = 0; j < obj->group_elements.data_[ i ].group_interfaces_id.size_; ++j ) {
            (char *&)obj->group_elements.data_[ i ].group_interfaces_id.data_[ j ].data_ += off;
        }
        (char *&)obj->group_elements.data_[ i ].group_interfaces_id.data_ += off;
        for( ST j = 0; j < obj->group_elements.data_[ i ].side_N.size_; ++j ) {
            for( ST k = 0; k < obj->group_elements.data_[ i ].side_N.data_[ j ].size_; ++k ) {
                for( ST l = 0; l < obj->group_elements.data_[ i ].side_N.data_[ j ].data_[ k ].size_; ++l ) {
                    (char *&)obj->group_elements.data_[ i ].side_N.data_[ j ].data_[ k ].data_[ l ].data_ += off;
                }
                (char *&)obj->group_elements.data_[ i ].side_N.data_[ j ].data_[ k ].data_ += off;
            }
            (char *&)obj->group_elements.data_[ i ].side_N.data_[ j ].data_ += off;
        }
        (char *&)obj->group_elements.data_[ i ].side_N.data_ += off;
        for( ST j = 0; j < obj->group_elements.data_[ i ].side_M.size_; ++j ) {
            for( ST k = 0; k < obj->group_elements.data_[ i ].side_M.data_[ j ].size_; ++k ) {
                (char *&)obj->group_elements.data_[ i ].side_M.data_[ j ].data_[ k ].data_ += off;
            }
            (char *&)obj->group_elements.data_[ i ].side_M.data_[ j ].data_ += off;
        }
        (char *&)obj->group_elements.data_[ i ].side_M.data_ += off;
    }
    (char *&)obj->group_elements.data_ += off;
    for( ST i = 0; i < obj->group_interfaces.size_; ++i ) {
        (char *&)obj->group_interfaces.data_[ i ].group_elements_id.data_ += off;
        (char *&)obj->group_interfaces.data_[ i ].patterns_id.data_ += off;
        for( ST j = 0; j < obj->group_interfaces.data_[ i ].element_num_in_group.size_; ++j ) {
            (char *&)obj->group_interfaces.data_[ i ].element_num_in_group.data_[ j ].data_ += off;
        }
        (char *&)obj->group_interfaces.data_[ i ].element_num_in_group.data_ += off;
        for( ST j = 0; j < obj->group_interfaces.data_[ i ].element_num_side.size_; ++j ) {
            (char *&)obj->group_interfaces.data_[ i ].element_num_side.data_[ j ].data_ += off;
        }
        (char *&)obj->group_interfaces.data_[ i ].element_num_side.data_ += off;
        for( ST j = 0; j < obj->group_interfaces.data_[ i ].mesh_connectivities.size_; ++j ) {
            (char *&)obj->group_interfaces.data_[ i ].mesh_connectivities.data_[ j ].data_ += off;
        }
        (char *&)obj->group_interfaces.data_[ i ].mesh_connectivities.data_ += off;
        for( ST j = 0; j < obj->group_interfaces.data_[ i ].connectivities.size_; ++j ) {
            (char *&)obj->group_interfaces.data_[ i ].connectivities.data_[ j ].data_ += off;
        }
        (char *&)obj->group_interfaces.data_[ i ].connectivities.data_ += off;
        for( ST j = 0; j < obj->group_interfaces.data_[ i ].correspondance_between_nodes.size_; ++j ) {
            (char *&)obj->group_interfaces.data_[ i ].correspondance_between_nodes.data_[ j ].data_ += off;
        }
        (char *&)obj->group_interfaces.data_[ i ].correspondance_between_nodes.data_ += off;
        for( ST j = 0; j < obj->group_interfaces.data_[ i ].Ne.size_; ++j ) {
            (char *&)obj->group_interfaces.data_[ i ].Ne.data_[ j ].data_ += off;
        }
        (char *&)obj->group_interfaces.data_[ i ].Ne.data_ += off;
        (char *&)obj->group_interfaces.data_[ i ].Me.data_ += off;
    }
    (char *&)obj->group_interfaces.data_ += off;
}

void GeometryCompactClass::update_ptr_gpu_save( ST off ) {
    GeometryCompactClass__update_ptr_gpu_save<<<1,1>>>( this, off );
}

void GeometryCompactClass::Patterns::update_ptr_cpu_load( ST off ) {
    (char *&)types.data_ += off;
    for( ST i = 0; i < types.size_; ++i ) {
        (char *&)types.data_[ i ].permutation.data_ += off;
        (char *&)types.data_[ i ].sides.data_ += off;
        for( ST j = 0; j < types.data_[ i ].sides.size_; ++j ) {
            (char *&)types.data_[ i ].sides.data_[ j ].data_ += off;
        }
    }
}

__global__
void GeometryCompactClass__Patterns__update_ptr_gpu_load( GeometryCompactClass::Patterns *obj, ST off ) {
    (char *&)obj->types.data_ += off;
    for( ST i = 0; i < obj->types.size_; ++i ) {
        (char *&)obj->types.data_[ i ].permutation.data_ += off;
        (char *&)obj->types.data_[ i ].sides.data_ += off;
        for( ST j = 0; j < obj->types.data_[ i ].sides.size_; ++j ) {
            (char *&)obj->types.data_[ i ].sides.data_[ j ].data_ += off;
        }
    }
}

void GeometryCompactClass::Patterns::update_ptr_gpu_load( ST off ) {
    GeometryCompactClass__Patterns__update_ptr_gpu_load<<<1,1>>>( this, off );
}

void GeometryCompactClass::Patterns::update_ptr_cpu_save( ST off ) {
    for( ST i = 0; i < types.size_; ++i ) {
        (char *&)types.data_[ i ].permutation.data_ += off;
        for( ST j = 0; j < types.data_[ i ].sides.size_; ++j ) {
            (char *&)types.data_[ i ].sides.data_[ j ].data_ += off;
        }
        (char *&)types.data_[ i ].sides.data_ += off;
    }
    (char *&)types.data_ += off;
}

__global__
void GeometryCompactClass__Patterns__update_ptr_gpu_save( GeometryCompactClass::Patterns *obj, ST off ) {
    for( ST i = 0; i < obj->types.size_; ++i ) {
        (char *&)obj->types.data_[ i ].permutation.data_ += off;
        for( ST j = 0; j < obj->types.data_[ i ].sides.size_; ++j ) {
            (char *&)obj->types.data_[ i ].sides.data_[ j ].data_ += off;
        }
        (char *&)obj->types.data_[ i ].sides.data_ += off;
    }
    (char *&)obj->types.data_ += off;
}

void GeometryCompactClass::Patterns::update_ptr_gpu_save( ST off ) {
    GeometryCompactClass__Patterns__update_ptr_gpu_save<<<1,1>>>( this, off );
}

void GeometryCompactClass::Patterns::Types::update_ptr_cpu_load( ST off ) {
    (char *&)permutation.data_ += off;
    (char *&)sides.data_ += off;
    for( ST i = 0; i < sides.size_; ++i ) {
        (char *&)sides.data_[ i ].data_ += off;
    }
}

__global__
void GeometryCompactClass__Patterns__Types__update_ptr_gpu_load( GeometryCompactClass::Patterns::Types *obj, ST off ) {
    (char *&)obj->permutation.data_ += off;
    (char *&)obj->sides.data_ += off;
    for( ST i = 0; i < obj->sides.size_; ++i ) {
        (char *&)obj->sides.data_[ i ].data_ += off;
    }
}

void GeometryCompactClass::Patterns::Types::update_ptr_gpu_load( ST off ) {
    GeometryCompactClass__Patterns__Types__update_ptr_gpu_load<<<1,1>>>( this, off );
}

void GeometryCompactClass::Patterns::Types::update_ptr_cpu_save( ST off ) {
    (char *&)permutation.data_ += off;
    for( ST i = 0; i < sides.size_; ++i ) {
        (char *&)sides.data_[ i ].data_ += off;
    }
    (char *&)sides.data_ += off;
}

__global__
void GeometryCompactClass__Patterns__Types__update_ptr_gpu_save( GeometryCompactClass::Patterns::Types *obj, ST off ) {
    (char *&)obj->permutation.data_ += off;
    for( ST i = 0; i < obj->sides.size_; ++i ) {
        (char *&)obj->sides.data_[ i ].data_ += off;
    }
    (char *&)obj->sides.data_ += off;
}

void GeometryCompactClass::Patterns::Types::update_ptr_gpu_save( ST off ) {
    GeometryCompactClass__Patterns__Types__update_ptr_gpu_save<<<1,1>>>( this, off );
}

void GeometryCompactClass::GroupElementsCompactClass::update_ptr_cpu_load( ST off ) {
    (char *&)mesh_connectivities.data_ += off;
    for( ST i = 0; i < mesh_connectivities.size_; ++i ) {
        (char *&)mesh_connectivities.data_[ i ].data_ += off;
    }
    (char *&)connectivities.data_ += off;
    for( ST i = 0; i < connectivities.size_; ++i ) {
        (char *&)connectivities.data_[ i ].data_ += off;
    }
    (char *&)interface_group_id.data_ += off;
    for( ST i = 0; i < interface_group_id.size_; ++i ) {
        (char *&)interface_group_id.data_[ i ].data_ += off;
    }
    (char *&)interface_num_in_group.data_ += off;
    for( ST i = 0; i < interface_num_in_group.size_; ++i ) {
        (char *&)interface_num_in_group.data_[ i ].data_ += off;
    }
    (char *&)group_interfaces_id.data_ += off;
    for( ST i = 0; i < group_interfaces_id.size_; ++i ) {
        (char *&)group_interfaces_id.data_[ i ].data_ += off;
    }
    (char *&)side_N.data_ += off;
    for( ST i = 0; i < side_N.size_; ++i ) {
        (char *&)side_N.data_[ i ].data_ += off;
        for( ST j = 0; j < side_N.data_[ i ].size_; ++j ) {
            (char *&)side_N.data_[ i ].data_[ j ].data_ += off;
            for( ST k = 0; k < side_N.data_[ i ].data_[ j ].size_; ++k ) {
                (char *&)side_N.data_[ i ].data_[ j ].data_[ k ].data_ += off;
            }
        }
    }
    (char *&)side_M.data_ += off;
    for( ST i = 0; i < side_M.size_; ++i ) {
        (char *&)side_M.data_[ i ].data_ += off;
        for( ST j = 0; j < side_M.data_[ i ].size_; ++j ) {
            (char *&)side_M.data_[ i ].data_[ j ].data_ += off;
        }
    }
}

__global__
void GeometryCompactClass__GroupElementsCompactClass__update_ptr_gpu_load( GeometryCompactClass::GroupElementsCompactClass *obj, ST off ) {
    (char *&)obj->mesh_connectivities.data_ += off;
    for( ST i = 0; i < obj->mesh_connectivities.size_; ++i ) {
        (char *&)obj->mesh_connectivities.data_[ i ].data_ += off;
    }
    (char *&)obj->connectivities.data_ += off;
    for( ST i = 0; i < obj->connectivities.size_; ++i ) {
        (char *&)obj->connectivities.data_[ i ].data_ += off;
    }
    (char *&)obj->interface_group_id.data_ += off;
    for( ST i = 0; i < obj->interface_group_id.size_; ++i ) {
        (char *&)obj->interface_group_id.data_[ i ].data_ += off;
    }
    (char *&)obj->interface_num_in_group.data_ += off;
    for( ST i = 0; i < obj->interface_num_in_group.size_; ++i ) {
        (char *&)obj->interface_num_in_group.data_[ i ].data_ += off;
    }
    (char *&)obj->group_interfaces_id.data_ += off;
    for( ST i = 0; i < obj->group_interfaces_id.size_; ++i ) {
        (char *&)obj->group_interfaces_id.data_[ i ].data_ += off;
    }
    (char *&)obj->side_N.data_ += off;
    for( ST i = 0; i < obj->side_N.size_; ++i ) {
        (char *&)obj->side_N.data_[ i ].data_ += off;
        for( ST j = 0; j < obj->side_N.data_[ i ].size_; ++j ) {
            (char *&)obj->side_N.data_[ i ].data_[ j ].data_ += off;
            for( ST k = 0; k < obj->side_N.data_[ i ].data_[ j ].size_; ++k ) {
                (char *&)obj->side_N.data_[ i ].data_[ j ].data_[ k ].data_ += off;
            }
        }
    }
    (char *&)obj->side_M.data_ += off;
    for( ST i = 0; i < obj->side_M.size_; ++i ) {
        (char *&)obj->side_M.data_[ i ].data_ += off;
        for( ST j = 0; j < obj->side_M.data_[ i ].size_; ++j ) {
            (char *&)obj->side_M.data_[ i ].data_[ j ].data_ += off;
        }
    }
}

void GeometryCompactClass::GroupElementsCompactClass::update_ptr_gpu_load( ST off ) {
    GeometryCompactClass__GroupElementsCompactClass__update_ptr_gpu_load<<<1,1>>>( this, off );
}

void GeometryCompactClass::GroupElementsCompactClass::update_ptr_cpu_save( ST off ) {
    for( ST i = 0; i < mesh_connectivities.size_; ++i ) {
        (char *&)mesh_connectivities.data_[ i ].data_ += off;
    }
    (char *&)mesh_connectivities.data_ += off;
    for( ST i = 0; i < connectivities.size_; ++i ) {
        (char *&)connectivities.data_[ i ].data_ += off;
    }
    (char *&)connectivities.data_ += off;
    for( ST i = 0; i < interface_group_id.size_; ++i ) {
        (char *&)interface_group_id.data_[ i ].data_ += off;
    }
    (char *&)interface_group_id.data_ += off;
    for( ST i = 0; i < interface_num_in_group.size_; ++i ) {
        (char *&)interface_num_in_group.data_[ i ].data_ += off;
    }
    (char *&)interface_num_in_group.data_ += off;
    for( ST i = 0; i < group_interfaces_id.size_; ++i ) {
        (char *&)group_interfaces_id.data_[ i ].data_ += off;
    }
    (char *&)group_interfaces_id.data_ += off;
    for( ST i = 0; i < side_N.size_; ++i ) {
        for( ST j = 0; j < side_N.data_[ i ].size_; ++j ) {
            for( ST k = 0; k < side_N.data_[ i ].data_[ j ].size_; ++k ) {
                (char *&)side_N.data_[ i ].data_[ j ].data_[ k ].data_ += off;
            }
            (char *&)side_N.data_[ i ].data_[ j ].data_ += off;
        }
        (char *&)side_N.data_[ i ].data_ += off;
    }
    (char *&)side_N.data_ += off;
    for( ST i = 0; i < side_M.size_; ++i ) {
        for( ST j = 0; j < side_M.data_[ i ].size_; ++j ) {
            (char *&)side_M.data_[ i ].data_[ j ].data_ += off;
        }
        (char *&)side_M.data_[ i ].data_ += off;
    }
    (char *&)side_M.data_ += off;
}

__global__
void GeometryCompactClass__GroupElementsCompactClass__update_ptr_gpu_save( GeometryCompactClass::GroupElementsCompactClass *obj, ST off ) {
    for( ST i = 0; i < obj->mesh_connectivities.size_; ++i ) {
        (char *&)obj->mesh_connectivities.data_[ i ].data_ += off;
    }
    (char *&)obj->mesh_connectivities.data_ += off;
    for( ST i = 0; i < obj->connectivities.size_; ++i ) {
        (char *&)obj->connectivities.data_[ i ].data_ += off;
    }
    (char *&)obj->connectivities.data_ += off;
    for( ST i = 0; i < obj->interface_group_id.size_; ++i ) {
        (char *&)obj->interface_group_id.data_[ i ].data_ += off;
    }
    (char *&)obj->interface_group_id.data_ += off;
    for( ST i = 0; i < obj->interface_num_in_group.size_; ++i ) {
        (char *&)obj->interface_num_in_group.data_[ i ].data_ += off;
    }
    (char *&)obj->interface_num_in_group.data_ += off;
    for( ST i = 0; i < obj->group_interfaces_id.size_; ++i ) {
        (char *&)obj->group_interfaces_id.data_[ i ].data_ += off;
    }
    (char *&)obj->group_interfaces_id.data_ += off;
    for( ST i = 0; i < obj->side_N.size_; ++i ) {
        for( ST j = 0; j < obj->side_N.data_[ i ].size_; ++j ) {
            for( ST k = 0; k < obj->side_N.data_[ i ].data_[ j ].size_; ++k ) {
                (char *&)obj->side_N.data_[ i ].data_[ j ].data_[ k ].data_ += off;
            }
            (char *&)obj->side_N.data_[ i ].data_[ j ].data_ += off;
        }
        (char *&)obj->side_N.data_[ i ].data_ += off;
    }
    (char *&)obj->side_N.data_ += off;
    for( ST i = 0; i < obj->side_M.size_; ++i ) {
        for( ST j = 0; j < obj->side_M.data_[ i ].size_; ++j ) {
            (char *&)obj->side_M.data_[ i ].data_[ j ].data_ += off;
        }
        (char *&)obj->side_M.data_[ i ].data_ += off;
    }
    (char *&)obj->side_M.data_ += off;
}

void GeometryCompactClass::GroupElementsCompactClass::update_ptr_gpu_save( ST off ) {
    GeometryCompactClass__GroupElementsCompactClass__update_ptr_gpu_save<<<1,1>>>( this, off );
}

void GeometryCompactClass::GroupInterfacesCompactClass::update_ptr_cpu_load( ST off ) {
    (char *&)group_elements_id.data_ += off;
    (char *&)patterns_id.data_ += off;
    (char *&)element_num_in_group.data_ += off;
    for( ST i = 0; i < element_num_in_group.size_; ++i ) {
        (char *&)element_num_in_group.data_[ i ].data_ += off;
    }
    (char *&)element_num_side.data_ += off;
    for( ST i = 0; i < element_num_side.size_; ++i ) {
        (char *&)element_num_side.data_[ i ].data_ += off;
    }
    (char *&)mesh_connectivities.data_ += off;
    for( ST i = 0; i < mesh_connectivities.size_; ++i ) {
        (char *&)mesh_connectivities.data_[ i ].data_ += off;
    }
    (char *&)connectivities.data_ += off;
    for( ST i = 0; i < connectivities.size_; ++i ) {
        (char *&)connectivities.data_[ i ].data_ += off;
    }
    (char *&)correspondance_between_nodes.data_ += off;
    for( ST i = 0; i < correspondance_between_nodes.size_; ++i ) {
        (char *&)correspondance_between_nodes.data_[ i ].data_ += off;
    }
    (char *&)Ne.data_ += off;
    for( ST i = 0; i < Ne.size_; ++i ) {
        (char *&)Ne.data_[ i ].data_ += off;
    }
    (char *&)Me.data_ += off;
}

__global__
void GeometryCompactClass__GroupInterfacesCompactClass__update_ptr_gpu_load( GeometryCompactClass::GroupInterfacesCompactClass *obj, ST off ) {
    (char *&)obj->group_elements_id.data_ += off;
    (char *&)obj->patterns_id.data_ += off;
    (char *&)obj->element_num_in_group.data_ += off;
    for( ST i = 0; i < obj->element_num_in_group.size_; ++i ) {
        (char *&)obj->element_num_in_group.data_[ i ].data_ += off;
    }
    (char *&)obj->element_num_side.data_ += off;
    for( ST i = 0; i < obj->element_num_side.size_; ++i ) {
        (char *&)obj->element_num_side.data_[ i ].data_ += off;
    }
    (char *&)obj->mesh_connectivities.data_ += off;
    for( ST i = 0; i < obj->mesh_connectivities.size_; ++i ) {
        (char *&)obj->mesh_connectivities.data_[ i ].data_ += off;
    }
    (char *&)obj->connectivities.data_ += off;
    for( ST i = 0; i < obj->connectivities.size_; ++i ) {
        (char *&)obj->connectivities.data_[ i ].data_ += off;
    }
    (char *&)obj->correspondance_between_nodes.data_ += off;
    for( ST i = 0; i < obj->correspondance_between_nodes.size_; ++i ) {
        (char *&)obj->correspondance_between_nodes.data_[ i ].data_ += off;
    }
    (char *&)obj->Ne.data_ += off;
    for( ST i = 0; i < obj->Ne.size_; ++i ) {
        (char *&)obj->Ne.data_[ i ].data_ += off;
    }
    (char *&)obj->Me.data_ += off;
}

void GeometryCompactClass::GroupInterfacesCompactClass::update_ptr_gpu_load( ST off ) {
    GeometryCompactClass__GroupInterfacesCompactClass__update_ptr_gpu_load<<<1,1>>>( this, off );
}

void GeometryCompactClass::GroupInterfacesCompactClass::update_ptr_cpu_save( ST off ) {
    (char *&)group_elements_id.data_ += off;
    (char *&)patterns_id.data_ += off;
    for( ST i = 0; i < element_num_in_group.size_; ++i ) {
        (char *&)element_num_in_group.data_[ i ].data_ += off;
    }
    (char *&)element_num_in_group.data_ += off;
    for( ST i = 0; i < element_num_side.size_; ++i ) {
        (char *&)element_num_side.data_[ i ].data_ += off;
    }
    (char *&)element_num_side.data_ += off;
    for( ST i = 0; i < mesh_connectivities.size_; ++i ) {
        (char *&)mesh_connectivities.data_[ i ].data_ += off;
    }
    (char *&)mesh_connectivities.data_ += off;
    for( ST i = 0; i < connectivities.size_; ++i ) {
        (char *&)connectivities.data_[ i ].data_ += off;
    }
    (char *&)connectivities.data_ += off;
    for( ST i = 0; i < correspondance_between_nodes.size_; ++i ) {
        (char *&)correspondance_between_nodes.data_[ i ].data_ += off;
    }
    (char *&)correspondance_between_nodes.data_ += off;
    for( ST i = 0; i < Ne.size_; ++i ) {
        (char *&)Ne.data_[ i ].data_ += off;
    }
    (char *&)Ne.data_ += off;
    (char *&)Me.data_ += off;
}

__global__
void GeometryCompactClass__GroupInterfacesCompactClass__update_ptr_gpu_save( GeometryCompactClass::GroupInterfacesCompactClass *obj, ST off ) {
    (char *&)obj->group_elements_id.data_ += off;
    (char *&)obj->patterns_id.data_ += off;
    for( ST i = 0; i < obj->element_num_in_group.size_; ++i ) {
        (char *&)obj->element_num_in_group.data_[ i ].data_ += off;
    }
    (char *&)obj->element_num_in_group.data_ += off;
    for( ST i = 0; i < obj->element_num_side.size_; ++i ) {
        (char *&)obj->element_num_side.data_[ i ].data_ += off;
    }
    (char *&)obj->element_num_side.data_ += off;
    for( ST i = 0; i < obj->mesh_connectivities.size_; ++i ) {
        (char *&)obj->mesh_connectivities.data_[ i ].data_ += off;
    }
    (char *&)obj->mesh_connectivities.data_ += off;
    for( ST i = 0; i < obj->connectivities.size_; ++i ) {
        (char *&)obj->connectivities.data_[ i ].data_ += off;
    }
    (char *&)obj->connectivities.data_ += off;
    for( ST i = 0; i < obj->correspondance_between_nodes.size_; ++i ) {
        (char *&)obj->correspondance_between_nodes.data_[ i ].data_ += off;
    }
    (char *&)obj->correspondance_between_nodes.data_ += off;
    for( ST i = 0; i < obj->Ne.size_; ++i ) {
        (char *&)obj->Ne.data_[ i ].data_ += off;
    }
    (char *&)obj->Ne.data_ += off;
    (char *&)obj->Me.data_ += off;
}

void GeometryCompactClass::GroupInterfacesCompactClass::update_ptr_gpu_save( ST off ) {
    GeometryCompactClass__GroupInterfacesCompactClass__update_ptr_gpu_save<<<1,1>>>( this, off );
}


END_METIL_NAMESPACE
