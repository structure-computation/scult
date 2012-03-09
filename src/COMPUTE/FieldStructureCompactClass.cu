#include "FieldStructureCompactClass.h"

BEG_METIL_NAMESPACE

void FieldStructureCompactClass::update_ptr_cpu_load( ST off ) {
    (char *&)patterns.types.data_ += off;
    for( ST i = 0; i < patterns.types.size_; ++i ) {
        (char *&)patterns.types.data_[ i ].permutation.data_ += off;
        (char *&)patterns.types.data_[ i ].sides.data_ += off;
        for( ST j = 0; j < patterns.types.data_[ i ].sides.size_; ++j ) {
            (char *&)patterns.types.data_[ i ].sides.data_[ j ].data_ += off;
        }
    }
    (char *&)group_elements.data_ += off;
    for( ST i = 0; i < group_elements.size_; ++i ) {
        (char *&)group_elements.data_[ i ].pt.data_ += off;
        for( ST j = 0; j < group_elements.data_[ i ].pt.size_; ++j ) {
            (char *&)group_elements.data_[ i ].pt.data_[ j ].data_ += off;
        }
        (char *&)group_elements.data_[ i ].mat_prop.data_ += off;
        for( ST j = 0; j < group_elements.data_[ i ].mat_prop.size_; ++j ) {
            (char *&)group_elements.data_[ i ].mat_prop.data_[ j ].data_ += off;
        }
        (char *&)group_elements.data_[ i ].volumic_force.data_ += off;
        for( ST j = 0; j < group_elements.data_[ i ].volumic_force.size_; ++j ) {
            (char *&)group_elements.data_[ i ].volumic_force.data_[ j ].data_ += off;
        }
        (char *&)group_elements.data_[ i ].mat_elem.data_ += off;
        for( ST j = 0; j < group_elements.data_[ i ].mat_elem.size_; ++j ) {
            (char *&)group_elements.data_[ i ].mat_elem.data_[ j ].data_ += off;
        }
        (char *&)group_elements.data_[ i ].size.data_ += off;
    }
    (char *&)group_interfaces.data_ += off;
    for( ST i = 0; i < group_interfaces.size_; ++i ) {
        (char *&)group_interfaces.data_[ i ].pt.data_ += off;
        for( ST j = 0; j < group_interfaces.data_[ i ].pt.size_; ++j ) {
            (char *&)group_interfaces.data_[ i ].pt.data_[ j ].data_ += off;
        }
        (char *&)group_interfaces.data_[ i ].link_prop.data_ += off;
        for( ST j = 0; j < group_interfaces.data_[ i ].link_prop.size_; ++j ) {
            (char *&)group_interfaces.data_[ i ].link_prop.data_[ j ].data_ += off;
        }
        (char *&)group_interfaces.data_[ i ].BC_step_prop.data_ += off;
        for( ST j = 0; j < group_interfaces.data_[ i ].BC_step_prop.size_; ++j ) {
            (char *&)group_interfaces.data_[ i ].BC_step_prop.data_[ j ].data_ += off;
        }
        (char *&)group_interfaces.data_[ i ].bc.data_ += off;
        for( ST j = 0; j < group_interfaces.data_[ i ].bc.size_; ++j ) {
            (char *&)group_interfaces.data_[ i ].bc.data_[ j ].data_ += off;
        }
    }
}

__global__
void FieldStructureCompactClass__update_ptr_gpu_load( FieldStructureCompactClass *obj, ST off ) {
    (char *&)obj->patterns.types.data_ += off;
    for( ST i = 0; i < obj->patterns.types.size_; ++i ) {
        (char *&)obj->patterns.types.data_[ i ].permutation.data_ += off;
        (char *&)obj->patterns.types.data_[ i ].sides.data_ += off;
        for( ST j = 0; j < obj->patterns.types.data_[ i ].sides.size_; ++j ) {
            (char *&)obj->patterns.types.data_[ i ].sides.data_[ j ].data_ += off;
        }
    }
    (char *&)obj->group_elements.data_ += off;
    for( ST i = 0; i < obj->group_elements.size_; ++i ) {
        (char *&)obj->group_elements.data_[ i ].pt.data_ += off;
        for( ST j = 0; j < obj->group_elements.data_[ i ].pt.size_; ++j ) {
            (char *&)obj->group_elements.data_[ i ].pt.data_[ j ].data_ += off;
        }
        (char *&)obj->group_elements.data_[ i ].mat_prop.data_ += off;
        for( ST j = 0; j < obj->group_elements.data_[ i ].mat_prop.size_; ++j ) {
            (char *&)obj->group_elements.data_[ i ].mat_prop.data_[ j ].data_ += off;
        }
        (char *&)obj->group_elements.data_[ i ].volumic_force.data_ += off;
        for( ST j = 0; j < obj->group_elements.data_[ i ].volumic_force.size_; ++j ) {
            (char *&)obj->group_elements.data_[ i ].volumic_force.data_[ j ].data_ += off;
        }
        (char *&)obj->group_elements.data_[ i ].mat_elem.data_ += off;
        for( ST j = 0; j < obj->group_elements.data_[ i ].mat_elem.size_; ++j ) {
            (char *&)obj->group_elements.data_[ i ].mat_elem.data_[ j ].data_ += off;
        }
        (char *&)obj->group_elements.data_[ i ].size.data_ += off;
    }
    (char *&)obj->group_interfaces.data_ += off;
    for( ST i = 0; i < obj->group_interfaces.size_; ++i ) {
        (char *&)obj->group_interfaces.data_[ i ].pt.data_ += off;
        for( ST j = 0; j < obj->group_interfaces.data_[ i ].pt.size_; ++j ) {
            (char *&)obj->group_interfaces.data_[ i ].pt.data_[ j ].data_ += off;
        }
        (char *&)obj->group_interfaces.data_[ i ].link_prop.data_ += off;
        for( ST j = 0; j < obj->group_interfaces.data_[ i ].link_prop.size_; ++j ) {
            (char *&)obj->group_interfaces.data_[ i ].link_prop.data_[ j ].data_ += off;
        }
        (char *&)obj->group_interfaces.data_[ i ].BC_step_prop.data_ += off;
        for( ST j = 0; j < obj->group_interfaces.data_[ i ].BC_step_prop.size_; ++j ) {
            (char *&)obj->group_interfaces.data_[ i ].BC_step_prop.data_[ j ].data_ += off;
        }
        (char *&)obj->group_interfaces.data_[ i ].bc.data_ += off;
        for( ST j = 0; j < obj->group_interfaces.data_[ i ].bc.size_; ++j ) {
            (char *&)obj->group_interfaces.data_[ i ].bc.data_[ j ].data_ += off;
        }
    }
}

void FieldStructureCompactClass::update_ptr_gpu_load( ST off ) {
    FieldStructureCompactClass__update_ptr_gpu_load<<<1,1>>>( this, off );
}

void FieldStructureCompactClass::update_ptr_cpu_save( ST off ) {
    for( ST i = 0; i < patterns.types.size_; ++i ) {
        (char *&)patterns.types.data_[ i ].permutation.data_ += off;
        for( ST j = 0; j < patterns.types.data_[ i ].sides.size_; ++j ) {
            (char *&)patterns.types.data_[ i ].sides.data_[ j ].data_ += off;
        }
        (char *&)patterns.types.data_[ i ].sides.data_ += off;
    }
    (char *&)patterns.types.data_ += off;
    for( ST i = 0; i < group_elements.size_; ++i ) {
        for( ST j = 0; j < group_elements.data_[ i ].pt.size_; ++j ) {
            (char *&)group_elements.data_[ i ].pt.data_[ j ].data_ += off;
        }
        (char *&)group_elements.data_[ i ].pt.data_ += off;
        for( ST j = 0; j < group_elements.data_[ i ].mat_prop.size_; ++j ) {
            (char *&)group_elements.data_[ i ].mat_prop.data_[ j ].data_ += off;
        }
        (char *&)group_elements.data_[ i ].mat_prop.data_ += off;
        for( ST j = 0; j < group_elements.data_[ i ].volumic_force.size_; ++j ) {
            (char *&)group_elements.data_[ i ].volumic_force.data_[ j ].data_ += off;
        }
        (char *&)group_elements.data_[ i ].volumic_force.data_ += off;
        for( ST j = 0; j < group_elements.data_[ i ].mat_elem.size_; ++j ) {
            (char *&)group_elements.data_[ i ].mat_elem.data_[ j ].data_ += off;
        }
        (char *&)group_elements.data_[ i ].mat_elem.data_ += off;
        (char *&)group_elements.data_[ i ].size.data_ += off;
    }
    (char *&)group_elements.data_ += off;
    for( ST i = 0; i < group_interfaces.size_; ++i ) {
        for( ST j = 0; j < group_interfaces.data_[ i ].pt.size_; ++j ) {
            (char *&)group_interfaces.data_[ i ].pt.data_[ j ].data_ += off;
        }
        (char *&)group_interfaces.data_[ i ].pt.data_ += off;
        for( ST j = 0; j < group_interfaces.data_[ i ].link_prop.size_; ++j ) {
            (char *&)group_interfaces.data_[ i ].link_prop.data_[ j ].data_ += off;
        }
        (char *&)group_interfaces.data_[ i ].link_prop.data_ += off;
        for( ST j = 0; j < group_interfaces.data_[ i ].BC_step_prop.size_; ++j ) {
            (char *&)group_interfaces.data_[ i ].BC_step_prop.data_[ j ].data_ += off;
        }
        (char *&)group_interfaces.data_[ i ].BC_step_prop.data_ += off;
        for( ST j = 0; j < group_interfaces.data_[ i ].bc.size_; ++j ) {
            (char *&)group_interfaces.data_[ i ].bc.data_[ j ].data_ += off;
        }
        (char *&)group_interfaces.data_[ i ].bc.data_ += off;
    }
    (char *&)group_interfaces.data_ += off;
}

__global__
void FieldStructureCompactClass__update_ptr_gpu_save( FieldStructureCompactClass *obj, ST off ) {
    for( ST i = 0; i < obj->patterns.types.size_; ++i ) {
        (char *&)obj->patterns.types.data_[ i ].permutation.data_ += off;
        for( ST j = 0; j < obj->patterns.types.data_[ i ].sides.size_; ++j ) {
            (char *&)obj->patterns.types.data_[ i ].sides.data_[ j ].data_ += off;
        }
        (char *&)obj->patterns.types.data_[ i ].sides.data_ += off;
    }
    (char *&)obj->patterns.types.data_ += off;
    for( ST i = 0; i < obj->group_elements.size_; ++i ) {
        for( ST j = 0; j < obj->group_elements.data_[ i ].pt.size_; ++j ) {
            (char *&)obj->group_elements.data_[ i ].pt.data_[ j ].data_ += off;
        }
        (char *&)obj->group_elements.data_[ i ].pt.data_ += off;
        for( ST j = 0; j < obj->group_elements.data_[ i ].mat_prop.size_; ++j ) {
            (char *&)obj->group_elements.data_[ i ].mat_prop.data_[ j ].data_ += off;
        }
        (char *&)obj->group_elements.data_[ i ].mat_prop.data_ += off;
        for( ST j = 0; j < obj->group_elements.data_[ i ].volumic_force.size_; ++j ) {
            (char *&)obj->group_elements.data_[ i ].volumic_force.data_[ j ].data_ += off;
        }
        (char *&)obj->group_elements.data_[ i ].volumic_force.data_ += off;
        for( ST j = 0; j < obj->group_elements.data_[ i ].mat_elem.size_; ++j ) {
            (char *&)obj->group_elements.data_[ i ].mat_elem.data_[ j ].data_ += off;
        }
        (char *&)obj->group_elements.data_[ i ].mat_elem.data_ += off;
        (char *&)obj->group_elements.data_[ i ].size.data_ += off;
    }
    (char *&)obj->group_elements.data_ += off;
    for( ST i = 0; i < obj->group_interfaces.size_; ++i ) {
        for( ST j = 0; j < obj->group_interfaces.data_[ i ].pt.size_; ++j ) {
            (char *&)obj->group_interfaces.data_[ i ].pt.data_[ j ].data_ += off;
        }
        (char *&)obj->group_interfaces.data_[ i ].pt.data_ += off;
        for( ST j = 0; j < obj->group_interfaces.data_[ i ].link_prop.size_; ++j ) {
            (char *&)obj->group_interfaces.data_[ i ].link_prop.data_[ j ].data_ += off;
        }
        (char *&)obj->group_interfaces.data_[ i ].link_prop.data_ += off;
        for( ST j = 0; j < obj->group_interfaces.data_[ i ].BC_step_prop.size_; ++j ) {
            (char *&)obj->group_interfaces.data_[ i ].BC_step_prop.data_[ j ].data_ += off;
        }
        (char *&)obj->group_interfaces.data_[ i ].BC_step_prop.data_ += off;
        for( ST j = 0; j < obj->group_interfaces.data_[ i ].bc.size_; ++j ) {
            (char *&)obj->group_interfaces.data_[ i ].bc.data_[ j ].data_ += off;
        }
        (char *&)obj->group_interfaces.data_[ i ].bc.data_ += off;
    }
    (char *&)obj->group_interfaces.data_ += off;
}

void FieldStructureCompactClass::update_ptr_gpu_save( ST off ) {
    FieldStructureCompactClass__update_ptr_gpu_save<<<1,1>>>( this, off );
}

void FieldStructureCompactClass::Patterns::update_ptr_cpu_load( ST off ) {
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
void FieldStructureCompactClass__Patterns__update_ptr_gpu_load( FieldStructureCompactClass::Patterns *obj, ST off ) {
    (char *&)obj->types.data_ += off;
    for( ST i = 0; i < obj->types.size_; ++i ) {
        (char *&)obj->types.data_[ i ].permutation.data_ += off;
        (char *&)obj->types.data_[ i ].sides.data_ += off;
        for( ST j = 0; j < obj->types.data_[ i ].sides.size_; ++j ) {
            (char *&)obj->types.data_[ i ].sides.data_[ j ].data_ += off;
        }
    }
}

void FieldStructureCompactClass::Patterns::update_ptr_gpu_load( ST off ) {
    FieldStructureCompactClass__Patterns__update_ptr_gpu_load<<<1,1>>>( this, off );
}

void FieldStructureCompactClass::Patterns::update_ptr_cpu_save( ST off ) {
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
void FieldStructureCompactClass__Patterns__update_ptr_gpu_save( FieldStructureCompactClass::Patterns *obj, ST off ) {
    for( ST i = 0; i < obj->types.size_; ++i ) {
        (char *&)obj->types.data_[ i ].permutation.data_ += off;
        for( ST j = 0; j < obj->types.data_[ i ].sides.size_; ++j ) {
            (char *&)obj->types.data_[ i ].sides.data_[ j ].data_ += off;
        }
        (char *&)obj->types.data_[ i ].sides.data_ += off;
    }
    (char *&)obj->types.data_ += off;
}

void FieldStructureCompactClass::Patterns::update_ptr_gpu_save( ST off ) {
    FieldStructureCompactClass__Patterns__update_ptr_gpu_save<<<1,1>>>( this, off );
}

void FieldStructureCompactClass::Patterns::Types::update_ptr_cpu_load( ST off ) {
    (char *&)permutation.data_ += off;
    (char *&)sides.data_ += off;
    for( ST i = 0; i < sides.size_; ++i ) {
        (char *&)sides.data_[ i ].data_ += off;
    }
}

__global__
void FieldStructureCompactClass__Patterns__Types__update_ptr_gpu_load( FieldStructureCompactClass::Patterns::Types *obj, ST off ) {
    (char *&)obj->permutation.data_ += off;
    (char *&)obj->sides.data_ += off;
    for( ST i = 0; i < obj->sides.size_; ++i ) {
        (char *&)obj->sides.data_[ i ].data_ += off;
    }
}

void FieldStructureCompactClass::Patterns::Types::update_ptr_gpu_load( ST off ) {
    FieldStructureCompactClass__Patterns__Types__update_ptr_gpu_load<<<1,1>>>( this, off );
}

void FieldStructureCompactClass::Patterns::Types::update_ptr_cpu_save( ST off ) {
    (char *&)permutation.data_ += off;
    for( ST i = 0; i < sides.size_; ++i ) {
        (char *&)sides.data_[ i ].data_ += off;
    }
    (char *&)sides.data_ += off;
}

__global__
void FieldStructureCompactClass__Patterns__Types__update_ptr_gpu_save( FieldStructureCompactClass::Patterns::Types *obj, ST off ) {
    (char *&)obj->permutation.data_ += off;
    for( ST i = 0; i < obj->sides.size_; ++i ) {
        (char *&)obj->sides.data_[ i ].data_ += off;
    }
    (char *&)obj->sides.data_ += off;
}

void FieldStructureCompactClass::Patterns::Types::update_ptr_gpu_save( ST off ) {
    FieldStructureCompactClass__Patterns__Types__update_ptr_gpu_save<<<1,1>>>( this, off );
}

void FieldStructureCompactClass::GroupFieldStructureElements::update_ptr_cpu_load( ST off ) {
    (char *&)pt.data_ += off;
    for( ST i = 0; i < pt.size_; ++i ) {
        (char *&)pt.data_[ i ].data_ += off;
    }
    (char *&)mat_prop.data_ += off;
    for( ST i = 0; i < mat_prop.size_; ++i ) {
        (char *&)mat_prop.data_[ i ].data_ += off;
    }
    (char *&)volumic_force.data_ += off;
    for( ST i = 0; i < volumic_force.size_; ++i ) {
        (char *&)volumic_force.data_[ i ].data_ += off;
    }
    (char *&)mat_elem.data_ += off;
    for( ST i = 0; i < mat_elem.size_; ++i ) {
        (char *&)mat_elem.data_[ i ].data_ += off;
    }
    (char *&)size.data_ += off;
}

__global__
void FieldStructureCompactClass__GroupFieldStructureElements__update_ptr_gpu_load( FieldStructureCompactClass::GroupFieldStructureElements *obj, ST off ) {
    (char *&)obj->pt.data_ += off;
    for( ST i = 0; i < obj->pt.size_; ++i ) {
        (char *&)obj->pt.data_[ i ].data_ += off;
    }
    (char *&)obj->mat_prop.data_ += off;
    for( ST i = 0; i < obj->mat_prop.size_; ++i ) {
        (char *&)obj->mat_prop.data_[ i ].data_ += off;
    }
    (char *&)obj->volumic_force.data_ += off;
    for( ST i = 0; i < obj->volumic_force.size_; ++i ) {
        (char *&)obj->volumic_force.data_[ i ].data_ += off;
    }
    (char *&)obj->mat_elem.data_ += off;
    for( ST i = 0; i < obj->mat_elem.size_; ++i ) {
        (char *&)obj->mat_elem.data_[ i ].data_ += off;
    }
    (char *&)obj->size.data_ += off;
}

void FieldStructureCompactClass::GroupFieldStructureElements::update_ptr_gpu_load( ST off ) {
    FieldStructureCompactClass__GroupFieldStructureElements__update_ptr_gpu_load<<<1,1>>>( this, off );
}

void FieldStructureCompactClass::GroupFieldStructureElements::update_ptr_cpu_save( ST off ) {
    for( ST i = 0; i < pt.size_; ++i ) {
        (char *&)pt.data_[ i ].data_ += off;
    }
    (char *&)pt.data_ += off;
    for( ST i = 0; i < mat_prop.size_; ++i ) {
        (char *&)mat_prop.data_[ i ].data_ += off;
    }
    (char *&)mat_prop.data_ += off;
    for( ST i = 0; i < volumic_force.size_; ++i ) {
        (char *&)volumic_force.data_[ i ].data_ += off;
    }
    (char *&)volumic_force.data_ += off;
    for( ST i = 0; i < mat_elem.size_; ++i ) {
        (char *&)mat_elem.data_[ i ].data_ += off;
    }
    (char *&)mat_elem.data_ += off;
    (char *&)size.data_ += off;
}

__global__
void FieldStructureCompactClass__GroupFieldStructureElements__update_ptr_gpu_save( FieldStructureCompactClass::GroupFieldStructureElements *obj, ST off ) {
    for( ST i = 0; i < obj->pt.size_; ++i ) {
        (char *&)obj->pt.data_[ i ].data_ += off;
    }
    (char *&)obj->pt.data_ += off;
    for( ST i = 0; i < obj->mat_prop.size_; ++i ) {
        (char *&)obj->mat_prop.data_[ i ].data_ += off;
    }
    (char *&)obj->mat_prop.data_ += off;
    for( ST i = 0; i < obj->volumic_force.size_; ++i ) {
        (char *&)obj->volumic_force.data_[ i ].data_ += off;
    }
    (char *&)obj->volumic_force.data_ += off;
    for( ST i = 0; i < obj->mat_elem.size_; ++i ) {
        (char *&)obj->mat_elem.data_[ i ].data_ += off;
    }
    (char *&)obj->mat_elem.data_ += off;
    (char *&)obj->size.data_ += off;
}

void FieldStructureCompactClass::GroupFieldStructureElements::update_ptr_gpu_save( ST off ) {
    FieldStructureCompactClass__GroupFieldStructureElements__update_ptr_gpu_save<<<1,1>>>( this, off );
}

void FieldStructureCompactClass::GroupFieldStructureInterfaces::update_ptr_cpu_load( ST off ) {
    (char *&)pt.data_ += off;
    for( ST i = 0; i < pt.size_; ++i ) {
        (char *&)pt.data_[ i ].data_ += off;
    }
    (char *&)link_prop.data_ += off;
    for( ST i = 0; i < link_prop.size_; ++i ) {
        (char *&)link_prop.data_[ i ].data_ += off;
    }
    (char *&)BC_step_prop.data_ += off;
    for( ST i = 0; i < BC_step_prop.size_; ++i ) {
        (char *&)BC_step_prop.data_[ i ].data_ += off;
    }
    (char *&)bc.data_ += off;
    for( ST i = 0; i < bc.size_; ++i ) {
        (char *&)bc.data_[ i ].data_ += off;
    }
}

__global__
void FieldStructureCompactClass__GroupFieldStructureInterfaces__update_ptr_gpu_load( FieldStructureCompactClass::GroupFieldStructureInterfaces *obj, ST off ) {
    (char *&)obj->pt.data_ += off;
    for( ST i = 0; i < obj->pt.size_; ++i ) {
        (char *&)obj->pt.data_[ i ].data_ += off;
    }
    (char *&)obj->link_prop.data_ += off;
    for( ST i = 0; i < obj->link_prop.size_; ++i ) {
        (char *&)obj->link_prop.data_[ i ].data_ += off;
    }
    (char *&)obj->BC_step_prop.data_ += off;
    for( ST i = 0; i < obj->BC_step_prop.size_; ++i ) {
        (char *&)obj->BC_step_prop.data_[ i ].data_ += off;
    }
    (char *&)obj->bc.data_ += off;
    for( ST i = 0; i < obj->bc.size_; ++i ) {
        (char *&)obj->bc.data_[ i ].data_ += off;
    }
}

void FieldStructureCompactClass::GroupFieldStructureInterfaces::update_ptr_gpu_load( ST off ) {
    FieldStructureCompactClass__GroupFieldStructureInterfaces__update_ptr_gpu_load<<<1,1>>>( this, off );
}

void FieldStructureCompactClass::GroupFieldStructureInterfaces::update_ptr_cpu_save( ST off ) {
    for( ST i = 0; i < pt.size_; ++i ) {
        (char *&)pt.data_[ i ].data_ += off;
    }
    (char *&)pt.data_ += off;
    for( ST i = 0; i < link_prop.size_; ++i ) {
        (char *&)link_prop.data_[ i ].data_ += off;
    }
    (char *&)link_prop.data_ += off;
    for( ST i = 0; i < BC_step_prop.size_; ++i ) {
        (char *&)BC_step_prop.data_[ i ].data_ += off;
    }
    (char *&)BC_step_prop.data_ += off;
    for( ST i = 0; i < bc.size_; ++i ) {
        (char *&)bc.data_[ i ].data_ += off;
    }
    (char *&)bc.data_ += off;
}

__global__
void FieldStructureCompactClass__GroupFieldStructureInterfaces__update_ptr_gpu_save( FieldStructureCompactClass::GroupFieldStructureInterfaces *obj, ST off ) {
    for( ST i = 0; i < obj->pt.size_; ++i ) {
        (char *&)obj->pt.data_[ i ].data_ += off;
    }
    (char *&)obj->pt.data_ += off;
    for( ST i = 0; i < obj->link_prop.size_; ++i ) {
        (char *&)obj->link_prop.data_[ i ].data_ += off;
    }
    (char *&)obj->link_prop.data_ += off;
    for( ST i = 0; i < obj->BC_step_prop.size_; ++i ) {
        (char *&)obj->BC_step_prop.data_[ i ].data_ += off;
    }
    (char *&)obj->BC_step_prop.data_ += off;
    for( ST i = 0; i < obj->bc.size_; ++i ) {
        (char *&)obj->bc.data_[ i ].data_ += off;
    }
    (char *&)obj->bc.data_ += off;
}

void FieldStructureCompactClass::GroupFieldStructureInterfaces::update_ptr_gpu_save( ST off ) {
    FieldStructureCompactClass__GroupFieldStructureInterfaces__update_ptr_gpu_save<<<1,1>>>( this, off );
}


END_METIL_NAMESPACE
