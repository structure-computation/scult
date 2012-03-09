#ifdef METIL_COMP_DIRECTIVE
    #pragma gpu_flag --compiler-options -fpermissive
#endif


#ifndef FieldStructureCompactClass_H
#define FieldStructureCompactClass_H

#include <Metil/MemoryDriver.h>
#include <Metil/BasicVecRef.h>

BEG_METIL_NAMESPACE

struct FieldStructureCompactClass {
    typedef void HasOffPtr;
    struct Patterns {
        typedef void HasOffPtr;
        struct Types {
            typedef void HasOffPtr;
            template<class T> static Types *copy( MemoryDriver &md, const T *src, ST num = 1 ) {
                Types *dst, *loc;
                ST rese = num * sizeof( Types );
                md.beg_local_data( &dst, &loc, rese, sizeof( ST ) );
                for( ST i = 0; i < num; ++i ) {
                    loc[ i ].id = src[ i ].id;
                    loc[ i ].dim = src[ i ].dim;
                    loc[ i ].nb_nodes = src[ i ].nb_nodes;
                    loc[ i ].interface_id = src[ i ].interface_id;
                    loc[ i ].nb_sides = src[ i ].nb_sides;
                    loc[ i ].nb_nodes_by_sides = src[ i ].nb_nodes_by_sides;
                    loc[ i ].nb_nodes_eq_by_sides = src[ i ].nb_nodes_eq_by_sides;
                    loc[ i ].permutation.size_ = src[ i ].permutation.size();
                    loc[ i ].permutation.rese_ = src[ i ].permutation.size();
                    md.copy( &loc[ i ].permutation.data_, src[ i ].permutation.ptr(), src[ i ].permutation.size() * sizeof( SI32 ), 16 * 4 );
                    loc[ i ].sides.size_ = src[ i ].sides.size();
                    loc[ i ].sides.rese_ = src[ i ].sides.size();
                    BasicVecRef<SI32 > *loc_0;
                    ST rese_0 = src[ i ].sides.size() * sizeof( BasicVecRef<SI32 > );
                    md.beg_local_data( &loc[ i ].sides.data_, &loc_0, rese_0, sizeof( ST ) );
                    for( ST j = 0; j < src[ i ].sides.size(); ++j ) {
                        loc_0[ j ].size_ = src[ i ].sides[ j ].size();
                        loc_0[ j ].rese_ = src[ i ].sides[ j ].size();
                        md.copy( &loc_0[ j ].data_, src[ i ].sides[ j ].ptr(), src[ i ].sides[ j ].size() * sizeof( SI32 ), 16 * 4 );
                    }
                    md.end_local_data( loc[ i ].sides.data_, loc_0, rese_0 );
                }
                md.end_local_data( dst, loc, rese );
                return dst;
            }
            void update_ptr_cpu_load( ST off );
            void update_ptr_cpu_save( ST off );
            void update_ptr_gpu_load( ST off );
            void update_ptr_gpu_save( ST off );

            SI32 id;
            SI32 dim;
            SI32 nb_nodes;
            SI32 interface_id;
            SI32 nb_sides;
            SI32 nb_nodes_by_sides;
            SI32 nb_nodes_eq_by_sides;
            BasicVecRef<SI32 > permutation;
            BasicVecRef<BasicVecRef<SI32 > > sides;
        };
        template<class T> static Patterns *copy( MemoryDriver &md, const T *src, ST num = 1 ) {
            Patterns *dst, *loc;
            ST rese = num * sizeof( Patterns );
            md.beg_local_data( &dst, &loc, rese, sizeof( ST ) );
            for( ST i = 0; i < num; ++i ) {
                loc[ i ].types.size_ = src[ i ].types.size();
                loc[ i ].types.rese_ = src[ i ].types.size();
                loc[ i ].types.data_ = Patterns::Types::copy( md, src[ i ].types.ptr(), src[ i ].types.size() );
            }
            md.end_local_data( dst, loc, rese );
            return dst;
        }
        void update_ptr_cpu_load( ST off );
        void update_ptr_cpu_save( ST off );
        void update_ptr_gpu_load( ST off );
        void update_ptr_gpu_save( ST off );

        BasicVecRef<Types > types;
    };
    struct GroupFieldStructureElements {
        typedef void HasOffPtr;
        template<class T> static GroupFieldStructureElements *copy( MemoryDriver &md, const T *src, ST num = 1 ) {
            GroupFieldStructureElements *dst, *loc;
            ST rese = num * sizeof( GroupFieldStructureElements );
            md.beg_local_data( &dst, &loc, rese, sizeof( ST ) );
            for( ST i = 0; i < num; ++i ) {
                loc[ i ].id = src[ i ].id;
                loc[ i ].pattern_id = src[ i ].pattern_id;
                loc[ i ].material_id = src[ i ].material_id;
                loc[ i ].nb_elements = src[ i ].nb_elements;
                loc[ i ].nb_elements_for_GPU = src[ i ].nb_elements_for_GPU;
                loc[ i ].pt.size_ = src[ i ].pt.size();
                loc[ i ].pt.rese_ = src[ i ].pt.size();
                BasicVecRef<FP64 > *loc_0;
                ST rese_0 = src[ i ].pt.size() * sizeof( BasicVecRef<FP64 > );
                md.beg_local_data( &loc[ i ].pt.data_, &loc_0, rese_0, sizeof( ST ) );
                for( ST j = 0; j < src[ i ].pt.size(); ++j ) {
                    loc_0[ j ].size_ = src[ i ].pt[ j ].size();
                    loc_0[ j ].rese_ = src[ i ].pt[ j ].size();
                    md.copy( &loc_0[ j ].data_, src[ i ].pt[ j ].ptr(), src[ i ].pt[ j ].size() * sizeof( FP64 ), 16 * 4 );
                }
                md.end_local_data( loc[ i ].pt.data_, loc_0, rese_0 );
                loc[ i ].mat_prop.size_ = src[ i ].mat_prop.size();
                loc[ i ].mat_prop.rese_ = src[ i ].mat_prop.size();
                BasicVecRef<FP64 > *loc_1;
                ST rese_1 = src[ i ].mat_prop.size() * sizeof( BasicVecRef<FP64 > );
                md.beg_local_data( &loc[ i ].mat_prop.data_, &loc_1, rese_1, sizeof( ST ) );
                for( ST j = 0; j < src[ i ].mat_prop.size(); ++j ) {
                    loc_1[ j ].size_ = src[ i ].mat_prop[ j ].size();
                    loc_1[ j ].rese_ = src[ i ].mat_prop[ j ].size();
                    md.copy( &loc_1[ j ].data_, src[ i ].mat_prop[ j ].ptr(), src[ i ].mat_prop[ j ].size() * sizeof( FP64 ), 16 * 4 );
                }
                md.end_local_data( loc[ i ].mat_prop.data_, loc_1, rese_1 );
                loc[ i ].volumic_force.size_ = src[ i ].volumic_force.size();
                loc[ i ].volumic_force.rese_ = src[ i ].volumic_force.size();
                BasicVecRef<FP64 > *loc_2;
                ST rese_2 = src[ i ].volumic_force.size() * sizeof( BasicVecRef<FP64 > );
                md.beg_local_data( &loc[ i ].volumic_force.data_, &loc_2, rese_2, sizeof( ST ) );
                for( ST j = 0; j < src[ i ].volumic_force.size(); ++j ) {
                    loc_2[ j ].size_ = src[ i ].volumic_force[ j ].size();
                    loc_2[ j ].rese_ = src[ i ].volumic_force[ j ].size();
                    md.copy( &loc_2[ j ].data_, src[ i ].volumic_force[ j ].ptr(), src[ i ].volumic_force[ j ].size() * sizeof( FP64 ), 16 * 4 );
                }
                md.end_local_data( loc[ i ].volumic_force.data_, loc_2, rese_2 );
                loc[ i ].mat_elem.size_ = src[ i ].mat_elem.size();
                loc[ i ].mat_elem.rese_ = src[ i ].mat_elem.size();
                BasicVecRef<FP64 > *loc_3;
                ST rese_3 = src[ i ].mat_elem.size() * sizeof( BasicVecRef<FP64 > );
                md.beg_local_data( &loc[ i ].mat_elem.data_, &loc_3, rese_3, sizeof( ST ) );
                for( ST j = 0; j < src[ i ].mat_elem.size(); ++j ) {
                    loc_3[ j ].size_ = src[ i ].mat_elem[ j ].size();
                    loc_3[ j ].rese_ = src[ i ].mat_elem[ j ].size();
                    md.copy( &loc_3[ j ].data_, src[ i ].mat_elem[ j ].ptr(), src[ i ].mat_elem[ j ].size() * sizeof( FP64 ), 16 * 4 );
                }
                md.end_local_data( loc[ i ].mat_elem.data_, loc_3, rese_3 );
                loc[ i ].size.size_ = src[ i ].size.size();
                loc[ i ].size.rese_ = src[ i ].size.size();
                md.copy( &loc[ i ].size.data_, src[ i ].size.ptr(), src[ i ].size.size() * sizeof( FP64 ), 16 * 4 );
            }
            md.end_local_data( dst, loc, rese );
            return dst;
        }
        void update_ptr_cpu_load( ST off );
        void update_ptr_cpu_save( ST off );
        void update_ptr_gpu_load( ST off );
        void update_ptr_gpu_save( ST off );

        SI32 id;
        SI32 pattern_id;
        SI32 material_id;
        SI32 nb_elements;
        SI32 nb_elements_for_GPU;
        BasicVecRef<BasicVecRef<FP64 > > pt;
        BasicVecRef<BasicVecRef<FP64 > > mat_prop;
        BasicVecRef<BasicVecRef<FP64 > > volumic_force;
        BasicVecRef<BasicVecRef<FP64 > > mat_elem;
        BasicVecRef<FP64 > size;
    };
    struct GroupFieldStructureInterfaces {
        typedef void HasOffPtr;
        template<class T> static GroupFieldStructureInterfaces *copy( MemoryDriver &md, const T *src, ST num = 1 ) {
            GroupFieldStructureInterfaces *dst, *loc;
            ST rese = num * sizeof( GroupFieldStructureInterfaces );
            md.beg_local_data( &dst, &loc, rese, sizeof( ST ) );
            for( ST i = 0; i < num; ++i ) {
                loc[ i ].id = src[ i ].id;
                loc[ i ].edge_id = src[ i ].edge_id;
                loc[ i ].type = src[ i ].type;
                loc[ i ].link_id = src[ i ].link_id;
                loc[ i ].bc_id = src[ i ].bc_id;
                loc[ i ].nb_interfaces = src[ i ].nb_interfaces;
                loc[ i ].nb_interfaces_for_GPU = src[ i ].nb_interfaces_for_GPU;
                loc[ i ].pt.size_ = src[ i ].pt.size();
                loc[ i ].pt.rese_ = src[ i ].pt.size();
                BasicVecRef<FP64 > *loc_0;
                ST rese_0 = src[ i ].pt.size() * sizeof( BasicVecRef<FP64 > );
                md.beg_local_data( &loc[ i ].pt.data_, &loc_0, rese_0, sizeof( ST ) );
                for( ST j = 0; j < src[ i ].pt.size(); ++j ) {
                    loc_0[ j ].size_ = src[ i ].pt[ j ].size();
                    loc_0[ j ].rese_ = src[ i ].pt[ j ].size();
                    md.copy( &loc_0[ j ].data_, src[ i ].pt[ j ].ptr(), src[ i ].pt[ j ].size() * sizeof( FP64 ), 16 * 4 );
                }
                md.end_local_data( loc[ i ].pt.data_, loc_0, rese_0 );
                loc[ i ].link_prop.size_ = src[ i ].link_prop.size();
                loc[ i ].link_prop.rese_ = src[ i ].link_prop.size();
                BasicVecRef<FP64 > *loc_1;
                ST rese_1 = src[ i ].link_prop.size() * sizeof( BasicVecRef<FP64 > );
                md.beg_local_data( &loc[ i ].link_prop.data_, &loc_1, rese_1, sizeof( ST ) );
                for( ST j = 0; j < src[ i ].link_prop.size(); ++j ) {
                    loc_1[ j ].size_ = src[ i ].link_prop[ j ].size();
                    loc_1[ j ].rese_ = src[ i ].link_prop[ j ].size();
                    md.copy( &loc_1[ j ].data_, src[ i ].link_prop[ j ].ptr(), src[ i ].link_prop[ j ].size() * sizeof( FP64 ), 16 * 4 );
                }
                md.end_local_data( loc[ i ].link_prop.data_, loc_1, rese_1 );
                loc[ i ].BC_step_prop.size_ = src[ i ].BC_step_prop.size();
                loc[ i ].BC_step_prop.rese_ = src[ i ].BC_step_prop.size();
                BasicVecRef<FP64 > *loc_2;
                ST rese_2 = src[ i ].BC_step_prop.size() * sizeof( BasicVecRef<FP64 > );
                md.beg_local_data( &loc[ i ].BC_step_prop.data_, &loc_2, rese_2, sizeof( ST ) );
                for( ST j = 0; j < src[ i ].BC_step_prop.size(); ++j ) {
                    loc_2[ j ].size_ = src[ i ].BC_step_prop[ j ].size();
                    loc_2[ j ].rese_ = src[ i ].BC_step_prop[ j ].size();
                    md.copy( &loc_2[ j ].data_, src[ i ].BC_step_prop[ j ].ptr(), src[ i ].BC_step_prop[ j ].size() * sizeof( FP64 ), 16 * 4 );
                }
                md.end_local_data( loc[ i ].BC_step_prop.data_, loc_2, rese_2 );
                loc[ i ].bc.size_ = src[ i ].bc.size();
                loc[ i ].bc.rese_ = src[ i ].bc.size();
                BasicVecRef<FP64 > *loc_3;
                ST rese_3 = src[ i ].bc.size() * sizeof( BasicVecRef<FP64 > );
                md.beg_local_data( &loc[ i ].bc.data_, &loc_3, rese_3, sizeof( ST ) );
                for( ST j = 0; j < src[ i ].bc.size(); ++j ) {
                    loc_3[ j ].size_ = src[ i ].bc[ j ].size();
                    loc_3[ j ].rese_ = src[ i ].bc[ j ].size();
                    md.copy( &loc_3[ j ].data_, src[ i ].bc[ j ].ptr(), src[ i ].bc[ j ].size() * sizeof( FP64 ), 16 * 4 );
                }
                md.end_local_data( loc[ i ].bc.data_, loc_3, rese_3 );
            }
            md.end_local_data( dst, loc, rese );
            return dst;
        }
        void update_ptr_cpu_load( ST off );
        void update_ptr_cpu_save( ST off );
        void update_ptr_gpu_load( ST off );
        void update_ptr_gpu_save( ST off );

        SI32 id;
        SI32 edge_id;
        SI32 type;
        SI32 link_id;
        SI32 bc_id;
        SI32 nb_interfaces;
        SI32 nb_interfaces_for_GPU;
        BasicVecRef<BasicVecRef<FP64 > > pt;
        BasicVecRef<BasicVecRef<FP64 > > link_prop;
        BasicVecRef<BasicVecRef<FP64 > > BC_step_prop;
        BasicVecRef<BasicVecRef<FP64 > > bc;
    };
    template<class T> static FieldStructureCompactClass *copy( MemoryDriver &md, const T *src, ST num = 1 ) {
        FieldStructureCompactClass *dst, *loc;
        ST rese = num * sizeof( FieldStructureCompactClass );
        md.beg_local_data( &dst, &loc, rese, sizeof( ST ) );
        for( ST i = 0; i < num; ++i ) {
            loc[ i ].num_level = src[ i ].num_level;
            loc[ i ].dim = src[ i ].dim;
            loc[ i ].patterns.types.size_ = src[ i ].patterns.types.size();
            loc[ i ].patterns.types.rese_ = src[ i ].patterns.types.size();
            loc[ i ].patterns.types.data_ = Patterns::Types::copy( md, src[ i ].patterns.types.ptr(), src[ i ].patterns.types.size() );
            loc[ i ].group_elements.size_ = src[ i ].group_elements.size();
            loc[ i ].group_elements.rese_ = src[ i ].group_elements.size();
            loc[ i ].group_elements.data_ = GroupFieldStructureElements::copy( md, src[ i ].group_elements.ptr(), src[ i ].group_elements.size() );
            loc[ i ].group_interfaces.size_ = src[ i ].group_interfaces.size();
            loc[ i ].group_interfaces.rese_ = src[ i ].group_interfaces.size();
            loc[ i ].group_interfaces.data_ = GroupFieldStructureInterfaces::copy( md, src[ i ].group_interfaces.ptr(), src[ i ].group_interfaces.size() );
        }
        md.end_local_data( dst, loc, rese );
        return dst;
    }
    void update_ptr_cpu_load( ST off );
    void update_ptr_cpu_save( ST off );
    void update_ptr_gpu_load( ST off );
    void update_ptr_gpu_save( ST off );

    SI32 num_level;
    SI32 dim;
    Patterns patterns;
    BasicVecRef<GroupFieldStructureElements > group_elements;
    BasicVecRef<GroupFieldStructureInterfaces > group_interfaces;
};

END_METIL_NAMESPACE

#endif // FieldStructureCompactClass_H
