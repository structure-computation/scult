#ifndef GeometryCompactClass_H
#define GeometryCompactClass_H

#include <Metil/MemoryDriver.h>
#include <Metil/BasicVecRef.h>

BEG_METIL_NAMESPACE

struct GeometryCompactClass {
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
                loc[ i ].types.data_ = Types::copy( md, src[ i ].types.ptr(), src[ i ].types.size() );
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
    struct GroupElementsCompactClass {
        typedef void HasOffPtr;
        template<class T> static GroupElementsCompactClass *copy( MemoryDriver &md, const T *src, ST num = 1 ) {
            GroupElementsCompactClass *dst, *loc;
            ST rese = num * sizeof( GroupElementsCompactClass );
            md.beg_local_data( &dst, &loc, rese, sizeof( ST ) );
            for( ST i = 0; i < num; ++i ) {
                loc[ i ].id = src[ i ].id;
                loc[ i ].nb_elements = src[ i ].nb_elements;
                loc[ i ].pattern_id = src[ i ].pattern_id;
                loc[ i ].pattern_base_id = src[ i ].pattern_base_id;
                loc[ i ].mesh_connectivities.size_ = src[ i ].mesh_connectivities.size();
                loc[ i ].mesh_connectivities.rese_ = src[ i ].mesh_connectivities.size();
                BasicVecRef<SI32 > *loc_0;
                ST rese_0 = src[ i ].mesh_connectivities.size() * sizeof( BasicVecRef<SI32 > );
                md.beg_local_data( &loc[ i ].mesh_connectivities.data_, &loc_0, rese_0, sizeof( ST ) );
                for( ST j = 0; j < src[ i ].mesh_connectivities.size(); ++j ) {
                    loc_0[ j ].size_ = src[ i ].mesh_connectivities[ j ].size();
                    loc_0[ j ].rese_ = src[ i ].mesh_connectivities[ j ].size();
                    md.copy( &loc_0[ j ].data_, src[ i ].mesh_connectivities[ j ].ptr(), src[ i ].mesh_connectivities[ j ].size() * sizeof( SI32 ), 16 * 4 );
                }
                md.end_local_data( loc[ i ].mesh_connectivities.data_, loc_0, rese_0 );
                loc[ i ].connectivities.size_ = src[ i ].connectivities.size();
                loc[ i ].connectivities.rese_ = src[ i ].connectivities.size();
                BasicVecRef<SI32 > *loc_1;
                ST rese_1 = src[ i ].connectivities.size() * sizeof( BasicVecRef<SI32 > );
                md.beg_local_data( &loc[ i ].connectivities.data_, &loc_1, rese_1, sizeof( ST ) );
                for( ST j = 0; j < src[ i ].connectivities.size(); ++j ) {
                    loc_1[ j ].size_ = src[ i ].connectivities[ j ].size();
                    loc_1[ j ].rese_ = src[ i ].connectivities[ j ].size();
                    md.copy( &loc_1[ j ].data_, src[ i ].connectivities[ j ].ptr(), src[ i ].connectivities[ j ].size() * sizeof( SI32 ), 16 * 4 );
                }
                md.end_local_data( loc[ i ].connectivities.data_, loc_1, rese_1 );
                loc[ i ].interface_group_id.size_ = src[ i ].interface_group_id.size();
                loc[ i ].interface_group_id.rese_ = src[ i ].interface_group_id.size();
                BasicVecRef<SI32 > *loc_2;
                ST rese_2 = src[ i ].interface_group_id.size() * sizeof( BasicVecRef<SI32 > );
                md.beg_local_data( &loc[ i ].interface_group_id.data_, &loc_2, rese_2, sizeof( ST ) );
                for( ST j = 0; j < src[ i ].interface_group_id.size(); ++j ) {
                    loc_2[ j ].size_ = src[ i ].interface_group_id[ j ].size();
                    loc_2[ j ].rese_ = src[ i ].interface_group_id[ j ].size();
                    md.copy( &loc_2[ j ].data_, src[ i ].interface_group_id[ j ].ptr(), src[ i ].interface_group_id[ j ].size() * sizeof( SI32 ), 16 * 4 );
                }
                md.end_local_data( loc[ i ].interface_group_id.data_, loc_2, rese_2 );
                loc[ i ].interface_num_in_group.size_ = src[ i ].interface_num_in_group.size();
                loc[ i ].interface_num_in_group.rese_ = src[ i ].interface_num_in_group.size();
                BasicVecRef<SI32 > *loc_3;
                ST rese_3 = src[ i ].interface_num_in_group.size() * sizeof( BasicVecRef<SI32 > );
                md.beg_local_data( &loc[ i ].interface_num_in_group.data_, &loc_3, rese_3, sizeof( ST ) );
                for( ST j = 0; j < src[ i ].interface_num_in_group.size(); ++j ) {
                    loc_3[ j ].size_ = src[ i ].interface_num_in_group[ j ].size();
                    loc_3[ j ].rese_ = src[ i ].interface_num_in_group[ j ].size();
                    md.copy( &loc_3[ j ].data_, src[ i ].interface_num_in_group[ j ].ptr(), src[ i ].interface_num_in_group[ j ].size() * sizeof( SI32 ), 16 * 4 );
                }
                md.end_local_data( loc[ i ].interface_num_in_group.data_, loc_3, rese_3 );
                loc[ i ].group_interfaces_id.size_ = src[ i ].group_interfaces_id.size();
                loc[ i ].group_interfaces_id.rese_ = src[ i ].group_interfaces_id.size();
                BasicVecRef<SI32 > *loc_4;
                ST rese_4 = src[ i ].group_interfaces_id.size() * sizeof( BasicVecRef<SI32 > );
                md.beg_local_data( &loc[ i ].group_interfaces_id.data_, &loc_4, rese_4, sizeof( ST ) );
                for( ST j = 0; j < src[ i ].group_interfaces_id.size(); ++j ) {
                    loc_4[ j ].size_ = src[ i ].group_interfaces_id[ j ].size();
                    loc_4[ j ].rese_ = src[ i ].group_interfaces_id[ j ].size();
                    md.copy( &loc_4[ j ].data_, src[ i ].group_interfaces_id[ j ].ptr(), src[ i ].group_interfaces_id[ j ].size() * sizeof( SI32 ), 16 * 4 );
                }
                md.end_local_data( loc[ i ].group_interfaces_id.data_, loc_4, rese_4 );
                loc[ i ].side_N.size_ = src[ i ].side_N.size();
                loc[ i ].side_N.rese_ = src[ i ].side_N.size();
                BasicVecRef<BasicVecRef<BasicVecRef<FP64 > > > *loc_5;
                ST rese_5 = src[ i ].side_N.size() * sizeof( BasicVecRef<BasicVecRef<BasicVecRef<FP64 > > > );
                md.beg_local_data( &loc[ i ].side_N.data_, &loc_5, rese_5, sizeof( ST ) );
                for( ST j = 0; j < src[ i ].side_N.size(); ++j ) {
                    loc_5[ j ].size_ = src[ i ].side_N[ j ].size();
                    loc_5[ j ].rese_ = src[ i ].side_N[ j ].size();
                    BasicVecRef<BasicVecRef<FP64 > > *loc_6;
                    ST rese_6 = src[ i ].side_N[ j ].size() * sizeof( BasicVecRef<BasicVecRef<FP64 > > );
                    md.beg_local_data( &loc_5[ j ].data_, &loc_6, rese_6, sizeof( ST ) );
                    for( ST k = 0; k < src[ i ].side_N[ j ].size(); ++k ) {
                        loc_6[ k ].size_ = src[ i ].side_N[ j ][ k ].size();
                        loc_6[ k ].rese_ = src[ i ].side_N[ j ][ k ].size();
                        BasicVecRef<FP64 > *loc_7;
                        ST rese_7 = src[ i ].side_N[ j ][ k ].size() * sizeof( BasicVecRef<FP64 > );
                        md.beg_local_data( &loc_6[ k ].data_, &loc_7, rese_7, sizeof( ST ) );
                        for( ST l = 0; l < src[ i ].side_N[ j ][ k ].size(); ++l ) {
                            loc_7[ l ].size_ = src[ i ].side_N[ j ][ k ][ l ].size();
                            loc_7[ l ].rese_ = src[ i ].side_N[ j ][ k ][ l ].size();
                            md.copy( &loc_7[ l ].data_, src[ i ].side_N[ j ][ k ][ l ].ptr(), src[ i ].side_N[ j ][ k ][ l ].size() * sizeof( FP64 ), 16 * 4 );
                        }
                        md.end_local_data( loc_6[ k ].data_, loc_7, rese_7 );
                    }
                    md.end_local_data( loc_5[ j ].data_, loc_6, rese_6 );
                }
                md.end_local_data( loc[ i ].side_N.data_, loc_5, rese_5 );
                loc[ i ].side_M.size_ = src[ i ].side_M.size();
                loc[ i ].side_M.rese_ = src[ i ].side_M.size();
                BasicVecRef<BasicVecRef<FP64 > > *loc_8;
                ST rese_8 = src[ i ].side_M.size() * sizeof( BasicVecRef<BasicVecRef<FP64 > > );
                md.beg_local_data( &loc[ i ].side_M.data_, &loc_8, rese_8, sizeof( ST ) );
                for( ST j = 0; j < src[ i ].side_M.size(); ++j ) {
                    loc_8[ j ].size_ = src[ i ].side_M[ j ].size();
                    loc_8[ j ].rese_ = src[ i ].side_M[ j ].size();
                    BasicVecRef<FP64 > *loc_9;
                    ST rese_9 = src[ i ].side_M[ j ].size() * sizeof( BasicVecRef<FP64 > );
                    md.beg_local_data( &loc_8[ j ].data_, &loc_9, rese_9, sizeof( ST ) );
                    for( ST k = 0; k < src[ i ].side_M[ j ].size(); ++k ) {
                        loc_9[ k ].size_ = src[ i ].side_M[ j ][ k ].size();
                        loc_9[ k ].rese_ = src[ i ].side_M[ j ][ k ].size();
                        md.copy( &loc_9[ k ].data_, src[ i ].side_M[ j ][ k ].ptr(), src[ i ].side_M[ j ][ k ].size() * sizeof( FP64 ), 16 * 4 );
                    }
                    md.end_local_data( loc_8[ j ].data_, loc_9, rese_9 );
                }
                md.end_local_data( loc[ i ].side_M.data_, loc_8, rese_8 );
            }
            md.end_local_data( dst, loc, rese );
            return dst;
        }
        void update_ptr_cpu_load( ST off );
        void update_ptr_cpu_save( ST off );
        void update_ptr_gpu_load( ST off );
        void update_ptr_gpu_save( ST off );

        SI32 id;
        SI32 nb_elements;
        SI32 pattern_id;
        SI32 pattern_base_id;
        BasicVecRef<BasicVecRef<SI32 > > mesh_connectivities;
        BasicVecRef<BasicVecRef<SI32 > > connectivities;
        BasicVecRef<BasicVecRef<SI32 > > interface_group_id;
        BasicVecRef<BasicVecRef<SI32 > > interface_num_in_group;
        BasicVecRef<BasicVecRef<SI32 > > group_interfaces_id;
        BasicVecRef<BasicVecRef<BasicVecRef<BasicVecRef<FP64 > > > > side_N;
        BasicVecRef<BasicVecRef<BasicVecRef<FP64 > > > side_M;
    };
    struct GroupInterfacesCompactClass {
        typedef void HasOffPtr;
        template<class T> static GroupInterfacesCompactClass *copy( MemoryDriver &md, const T *src, ST num = 1 ) {
            GroupInterfacesCompactClass *dst, *loc;
            ST rese = num * sizeof( GroupInterfacesCompactClass );
            md.beg_local_data( &dst, &loc, rese, sizeof( ST ) );
            for( ST i = 0; i < num; ++i ) {
                loc[ i ].id = src[ i ].id;
                loc[ i ].nb_group_elements = src[ i ].nb_group_elements;
                loc[ i ].nb_interfaces = src[ i ].nb_interfaces;
                loc[ i ].group_elements_id.size_ = src[ i ].group_elements_id.size();
                loc[ i ].group_elements_id.rese_ = src[ i ].group_elements_id.size();
                md.copy( &loc[ i ].group_elements_id.data_, src[ i ].group_elements_id.ptr(), src[ i ].group_elements_id.size() * sizeof( SI32 ), 16 * 4 );
                loc[ i ].patterns_id.size_ = src[ i ].patterns_id.size();
                loc[ i ].patterns_id.rese_ = src[ i ].patterns_id.size();
                md.copy( &loc[ i ].patterns_id.data_, src[ i ].patterns_id.ptr(), src[ i ].patterns_id.size() * sizeof( SI32 ), 16 * 4 );
                loc[ i ].element_num_in_group.size_ = src[ i ].element_num_in_group.size();
                loc[ i ].element_num_in_group.rese_ = src[ i ].element_num_in_group.size();
                BasicVecRef<SI32 > *loc_0;
                ST rese_0 = src[ i ].element_num_in_group.size() * sizeof( BasicVecRef<SI32 > );
                md.beg_local_data( &loc[ i ].element_num_in_group.data_, &loc_0, rese_0, sizeof( ST ) );
                for( ST j = 0; j < src[ i ].element_num_in_group.size(); ++j ) {
                    loc_0[ j ].size_ = src[ i ].element_num_in_group[ j ].size();
                    loc_0[ j ].rese_ = src[ i ].element_num_in_group[ j ].size();
                    md.copy( &loc_0[ j ].data_, src[ i ].element_num_in_group[ j ].ptr(), src[ i ].element_num_in_group[ j ].size() * sizeof( SI32 ), 16 * 4 );
                }
                md.end_local_data( loc[ i ].element_num_in_group.data_, loc_0, rese_0 );
                loc[ i ].element_num_side.size_ = src[ i ].element_num_side.size();
                loc[ i ].element_num_side.rese_ = src[ i ].element_num_side.size();
                BasicVecRef<SI32 > *loc_1;
                ST rese_1 = src[ i ].element_num_side.size() * sizeof( BasicVecRef<SI32 > );
                md.beg_local_data( &loc[ i ].element_num_side.data_, &loc_1, rese_1, sizeof( ST ) );
                for( ST j = 0; j < src[ i ].element_num_side.size(); ++j ) {
                    loc_1[ j ].size_ = src[ i ].element_num_side[ j ].size();
                    loc_1[ j ].rese_ = src[ i ].element_num_side[ j ].size();
                    md.copy( &loc_1[ j ].data_, src[ i ].element_num_side[ j ].ptr(), src[ i ].element_num_side[ j ].size() * sizeof( SI32 ), 16 * 4 );
                }
                md.end_local_data( loc[ i ].element_num_side.data_, loc_1, rese_1 );
                loc[ i ].mesh_connectivities.size_ = src[ i ].mesh_connectivities.size();
                loc[ i ].mesh_connectivities.rese_ = src[ i ].mesh_connectivities.size();
                BasicVecRef<SI32 > *loc_2;
                ST rese_2 = src[ i ].mesh_connectivities.size() * sizeof( BasicVecRef<SI32 > );
                md.beg_local_data( &loc[ i ].mesh_connectivities.data_, &loc_2, rese_2, sizeof( ST ) );
                for( ST j = 0; j < src[ i ].mesh_connectivities.size(); ++j ) {
                    loc_2[ j ].size_ = src[ i ].mesh_connectivities[ j ].size();
                    loc_2[ j ].rese_ = src[ i ].mesh_connectivities[ j ].size();
                    md.copy( &loc_2[ j ].data_, src[ i ].mesh_connectivities[ j ].ptr(), src[ i ].mesh_connectivities[ j ].size() * sizeof( SI32 ), 16 * 4 );
                }
                md.end_local_data( loc[ i ].mesh_connectivities.data_, loc_2, rese_2 );
                loc[ i ].connectivities.size_ = src[ i ].connectivities.size();
                loc[ i ].connectivities.rese_ = src[ i ].connectivities.size();
                BasicVecRef<SI32 > *loc_3;
                ST rese_3 = src[ i ].connectivities.size() * sizeof( BasicVecRef<SI32 > );
                md.beg_local_data( &loc[ i ].connectivities.data_, &loc_3, rese_3, sizeof( ST ) );
                for( ST j = 0; j < src[ i ].connectivities.size(); ++j ) {
                    loc_3[ j ].size_ = src[ i ].connectivities[ j ].size();
                    loc_3[ j ].rese_ = src[ i ].connectivities[ j ].size();
                    md.copy( &loc_3[ j ].data_, src[ i ].connectivities[ j ].ptr(), src[ i ].connectivities[ j ].size() * sizeof( SI32 ), 16 * 4 );
                }
                md.end_local_data( loc[ i ].connectivities.data_, loc_3, rese_3 );
                loc[ i ].correspondance_between_nodes.size_ = src[ i ].correspondance_between_nodes.size();
                loc[ i ].correspondance_between_nodes.rese_ = src[ i ].correspondance_between_nodes.size();
                BasicVecRef<SI32 > *loc_4;
                ST rese_4 = src[ i ].correspondance_between_nodes.size() * sizeof( BasicVecRef<SI32 > );
                md.beg_local_data( &loc[ i ].correspondance_between_nodes.data_, &loc_4, rese_4, sizeof( ST ) );
                for( ST j = 0; j < src[ i ].correspondance_between_nodes.size(); ++j ) {
                    loc_4[ j ].size_ = src[ i ].correspondance_between_nodes[ j ].size();
                    loc_4[ j ].rese_ = src[ i ].correspondance_between_nodes[ j ].size();
                    md.copy( &loc_4[ j ].data_, src[ i ].correspondance_between_nodes[ j ].ptr(), src[ i ].correspondance_between_nodes[ j ].size() * sizeof( SI32 ), 16 * 4 );
                }
                md.end_local_data( loc[ i ].correspondance_between_nodes.data_, loc_4, rese_4 );
                loc[ i ].Ne.size_ = src[ i ].Ne.size();
                loc[ i ].Ne.rese_ = src[ i ].Ne.size();
                BasicVecRef<FP64 > *loc_5;
                ST rese_5 = src[ i ].Ne.size() * sizeof( BasicVecRef<FP64 > );
                md.beg_local_data( &loc[ i ].Ne.data_, &loc_5, rese_5, sizeof( ST ) );
                for( ST j = 0; j < src[ i ].Ne.size(); ++j ) {
                    loc_5[ j ].size_ = src[ i ].Ne[ j ].size();
                    loc_5[ j ].rese_ = src[ i ].Ne[ j ].size();
                    md.copy( &loc_5[ j ].data_, src[ i ].Ne[ j ].ptr(), src[ i ].Ne[ j ].size() * sizeof( FP64 ), 16 * 4 );
                }
                md.end_local_data( loc[ i ].Ne.data_, loc_5, rese_5 );
                loc[ i ].Me.size_ = src[ i ].Me.size();
                loc[ i ].Me.rese_ = src[ i ].Me.size();
                md.copy( &loc[ i ].Me.data_, src[ i ].Me.ptr(), src[ i ].Me.size() * sizeof( FP64 ), 16 * 4 );
                loc[ i ].measure = src[ i ].measure;
            }
            md.end_local_data( dst, loc, rese );
            return dst;
        }
        void update_ptr_cpu_load( ST off );
        void update_ptr_cpu_save( ST off );
        void update_ptr_gpu_load( ST off );
        void update_ptr_gpu_save( ST off );

        SI32 id;
        SI32 nb_group_elements;
        SI32 nb_interfaces;
        BasicVecRef<SI32 > group_elements_id;
        BasicVecRef<SI32 > patterns_id;
        BasicVecRef<BasicVecRef<SI32 > > element_num_in_group;
        BasicVecRef<BasicVecRef<SI32 > > element_num_side;
        BasicVecRef<BasicVecRef<SI32 > > mesh_connectivities;
        BasicVecRef<BasicVecRef<SI32 > > connectivities;
        BasicVecRef<BasicVecRef<SI32 > > correspondance_between_nodes;
        BasicVecRef<BasicVecRef<FP64 > > Ne;
        BasicVecRef<FP64 > Me;
        FP64 measure;
    };
    template<class T> static GeometryCompactClass *copy( MemoryDriver &md, const T *src, ST num = 1 ) {
        GeometryCompactClass *dst, *loc;
        ST rese = num * sizeof( GeometryCompactClass );
        md.beg_local_data( &dst, &loc, rese, sizeof( ST ) );
        for( ST i = 0; i < num; ++i ) {
            loc[ i ].num_level = src[ i ].num_level;
            loc[ i ].dim = src[ i ].dim;
            loc[ i ].patterns.types.size_ = src[ i ].patterns.types.size();
            loc[ i ].patterns.types.rese_ = src[ i ].patterns.types.size();
            loc[ i ].patterns.types.data_ = Patterns::Types::copy( md, src[ i ].patterns.types.ptr(), src[ i ].patterns.types.size() );
            loc[ i ].mesh_nodes.size_ = src[ i ].mesh_nodes.size();
            loc[ i ].mesh_nodes.rese_ = src[ i ].mesh_nodes.size();
            BasicVecRef<FP64 > *loc_0;
            ST rese_0 = src[ i ].mesh_nodes.size() * sizeof( BasicVecRef<FP64 > );
            md.beg_local_data( &loc[ i ].mesh_nodes.data_, &loc_0, rese_0, sizeof( ST ) );
            for( ST j = 0; j < src[ i ].mesh_nodes.size(); ++j ) {
                loc_0[ j ].size_ = src[ i ].mesh_nodes[ j ].size();
                loc_0[ j ].rese_ = src[ i ].mesh_nodes[ j ].size();
                md.copy( &loc_0[ j ].data_, src[ i ].mesh_nodes[ j ].ptr(), src[ i ].mesh_nodes[ j ].size() * sizeof( FP64 ), 16 * 4 );
            }
            md.end_local_data( loc[ i ].mesh_nodes.data_, loc_0, rese_0 );
            loc[ i ].nodes.size_ = src[ i ].nodes.size();
            loc[ i ].nodes.rese_ = src[ i ].nodes.size();
            BasicVecRef<FP64 > *loc_1;
            ST rese_1 = src[ i ].nodes.size() * sizeof( BasicVecRef<FP64 > );
            md.beg_local_data( &loc[ i ].nodes.data_, &loc_1, rese_1, sizeof( ST ) );
            for( ST j = 0; j < src[ i ].nodes.size(); ++j ) {
                loc_1[ j ].size_ = src[ i ].nodes[ j ].size();
                loc_1[ j ].rese_ = src[ i ].nodes[ j ].size();
                md.copy( &loc_1[ j ].data_, src[ i ].nodes[ j ].ptr(), src[ i ].nodes[ j ].size() * sizeof( FP64 ), 16 * 4 );
            }
            md.end_local_data( loc[ i ].nodes.data_, loc_1, rese_1 );
            loc[ i ].group_elements.size_ = src[ i ].group_elements.size();
            loc[ i ].group_elements.rese_ = src[ i ].group_elements.size();
            loc[ i ].group_elements.data_ = GroupElementsCompactClass::copy( md, src[ i ].group_elements.ptr(), src[ i ].group_elements.size() );
            loc[ i ].group_interfaces.size_ = src[ i ].group_interfaces.size();
            loc[ i ].group_interfaces.rese_ = src[ i ].group_interfaces.size();
            loc[ i ].group_interfaces.data_ = GroupInterfacesCompactClass::copy( md, src[ i ].group_interfaces.ptr(), src[ i ].group_interfaces.size() );
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
    BasicVecRef<BasicVecRef<FP64 > > mesh_nodes;
    BasicVecRef<BasicVecRef<FP64 > > nodes;
    BasicVecRef<GroupElementsCompactClass > group_elements;
    BasicVecRef<GroupInterfacesCompactClass > group_interfaces;
};

END_METIL_NAMESPACE

#endif // GeometryCompactClass_H
