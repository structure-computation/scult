#ifndef LMT___SRC_UTILS_MESHCARACINTER_MESHCARAC_PY
#define LMT___SRC_UTILS_MESHCARACINTER_MESHCARAC_PY

#include "mesh/triangle.h"
#include "mesh/quad_8.h"
#include "mesh/bar_3.h"
#include "mesh/tetra.h"
#include "mesh/triangle_6.h"
#include "mesh/quad.h"
#include "mesh/nodalelement.h"
#include "mesh/bar.h"
namespace LMT {

template<unsigned nb_dim,unsigned nvi> class Meshcaracinter;


#ifndef IFNDEF_qtrans_DM
#define IFNDEF_qtrans_DM
    struct qtrans_DM {};
#endif // IFNDEF_qtrans_DM

#ifndef IFNDEF_num_group_DM
#define IFNDEF_num_group_DM
    struct num_group_DM {};
#endif // IFNDEF_num_group_DM

#ifndef IFNDEF_dWt_DM
#define IFNDEF_dWt_DM
    struct dWt_DM {};
#endif // IFNDEF_dWt_DM

#ifndef IFNDEF_F_DM
#define IFNDEF_F_DM
    struct F_DM {};
#endif // IFNDEF_F_DM

#ifndef IFNDEF_dWn_DM
#define IFNDEF_dWn_DM
    struct dWn_DM {};
#endif // IFNDEF_dWn_DM

#ifndef IFNDEF_elem_DM
#define IFNDEF_elem_DM
    struct elem_DM {};
#endif // IFNDEF_elem_DM

#ifndef IFNDEF_pos_DM
#define IFNDEF_pos_DM
    struct pos_DM {};
#endif // IFNDEF_pos_DM

#ifndef IFNDEF_num_DM
#define IFNDEF_num_DM
    struct num_DM {};
#endif // IFNDEF_num_DM

#ifndef IFNDEF_W_DM
#define IFNDEF_W_DM
    struct W_DM {};
#endif // IFNDEF_W_DM

#ifndef IFNDEF_dissipation_DM
#define IFNDEF_dissipation_DM
    struct dissipation_DM {};
#endif // IFNDEF_dissipation_DM

#ifndef IFNDEF_type_DM
#define IFNDEF_type_DM
    struct type_DM {};
#endif // IFNDEF_type_DM

#ifndef IFNDEF_d_DM
#define IFNDEF_d_DM
    struct d_DM {};
#endif // IFNDEF_d_DM

template<>
class Meshcaracinter<1,0> { 
public:
    static const unsigned dim = 1;
    typedef double Tpos;
    typedef Vec<double,1> Pvec;
    struct NodalStaticData {
        NodalStaticData():qtrans(0) {}
        typedef Vec<double,1> T0;
        CARACDMEXTNAME(0,T0,qtrans,"");
        CARACDMEXTNAME(1,Pvec,pos,"m");
        static const unsigned nb_params = 2;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    struct GlobalStaticData {
        VOIDDMSET;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    template<unsigned nvi_to_subs,unsigned skin,unsigned num_sub_element,unsigned inner=0>
    struct ElementChoice {
        typedef void NE;
        typedef DefaultBehavior BE;
        typedef VoidDMSet TData;
    };
    struct TCDM0 {
        TCDM0():type(0),num(0),num_group(0),F(0),W(0),dWn(0),dWt(0),dissipation(0),d(0) {}
        CARACDMEXTNAME(0,double,type,"");
        CARACDMEXTNAME(1,unsigned,num,"");
        CARACDMEXTNAME(2,unsigned,num_group,"");
        typedef Vec<unsigned> T3;
        CARACDMEXTNAME(3,T3,elem,"");
        typedef Vec<double,1> T4;
        CARACDMEXTNAME(4,T4,F,"Mpa");
        typedef Vec<double,1> T5;
        CARACDMEXTNAME(5,T5,W,"m/s");
        typedef Vec<double,1> T6;
        CARACDMEXTNAME(6,T6,dWn,"m/s");
        typedef Vec<double,1> T7;
        CARACDMEXTNAME(7,T7,dWt,"m/s");
        typedef Vec<double,1> T8;
        CARACDMEXTNAME(8,T8,dissipation,"J");
        CARACDMEXTNAME(9,double,d,"");
        static const unsigned nb_params = 10;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    template<unsigned inner> struct ElementChoice<0,0,0,inner> {
        typedef NodalElement NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
};

template<>
class Meshcaracinter<2,0> { 
public:
    static const unsigned dim = 2;
    typedef double Tpos;
    typedef Vec<double,2> Pvec;
    struct NodalStaticData {
        NodalStaticData():qtrans(0) {}
        typedef Vec<double,2> T0;
        CARACDMEXTNAME(0,T0,qtrans,"");
        CARACDMEXTNAME(1,Pvec,pos,"m");
        static const unsigned nb_params = 2;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    struct GlobalStaticData {
        VOIDDMSET;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    template<unsigned nvi_to_subs,unsigned skin,unsigned num_sub_element,unsigned inner=0>
    struct ElementChoice {
        typedef void NE;
        typedef DefaultBehavior BE;
        typedef VoidDMSet TData;
    };
    struct TCDM0 {
        TCDM0():type(0),num(0),num_group(0),F(0),W(0),dWn(0),dWt(0),dissipation(0),d(0) {}
        CARACDMEXTNAME(0,double,type,"");
        CARACDMEXTNAME(1,unsigned,num,"");
        CARACDMEXTNAME(2,unsigned,num_group,"");
        typedef Vec<unsigned> T3;
        CARACDMEXTNAME(3,T3,elem,"");
        typedef Vec<double,2> T4;
        CARACDMEXTNAME(4,T4,F,"Mpa");
        typedef Vec<double,2> T5;
        CARACDMEXTNAME(5,T5,W,"m/s");
        typedef Vec<double,2> T6;
        CARACDMEXTNAME(6,T6,dWn,"m/s");
        typedef Vec<double,2> T7;
        CARACDMEXTNAME(7,T7,dWt,"m/s");
        typedef Vec<double,2> T8;
        CARACDMEXTNAME(8,T8,dissipation,"J");
        CARACDMEXTNAME(9,double,d,"");
        static const unsigned nb_params = 10;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    template<unsigned inner> struct ElementChoice<0,0,0,inner> {
        typedef NodalElement NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
};

template<>
class Meshcaracinter<3,0> { 
public:
    static const unsigned dim = 3;
    typedef double Tpos;
    typedef Vec<double,3> Pvec;
    struct NodalStaticData {
        NodalStaticData():qtrans(0) {}
        typedef Vec<double,3> T0;
        CARACDMEXTNAME(0,T0,qtrans,"");
        CARACDMEXTNAME(1,Pvec,pos,"m");
        static const unsigned nb_params = 2;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    struct GlobalStaticData {
        VOIDDMSET;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    template<unsigned nvi_to_subs,unsigned skin,unsigned num_sub_element,unsigned inner=0>
    struct ElementChoice {
        typedef void NE;
        typedef DefaultBehavior BE;
        typedef VoidDMSet TData;
    };
    struct TCDM0 {
        TCDM0():type(0),num(0),num_group(0),F(0),W(0),dWn(0),dWt(0),dissipation(0),d(0) {}
        CARACDMEXTNAME(0,double,type,"");
        CARACDMEXTNAME(1,unsigned,num,"");
        CARACDMEXTNAME(2,unsigned,num_group,"");
        typedef Vec<unsigned> T3;
        CARACDMEXTNAME(3,T3,elem,"");
        typedef Vec<double,3> T4;
        CARACDMEXTNAME(4,T4,F,"Mpa");
        typedef Vec<double,3> T5;
        CARACDMEXTNAME(5,T5,W,"m/s");
        typedef Vec<double,3> T6;
        CARACDMEXTNAME(6,T6,dWn,"m/s");
        typedef Vec<double,3> T7;
        CARACDMEXTNAME(7,T7,dWt,"m/s");
        typedef Vec<double,3> T8;
        CARACDMEXTNAME(8,T8,dissipation,"J");
        CARACDMEXTNAME(9,double,d,"");
        static const unsigned nb_params = 10;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    template<unsigned inner> struct ElementChoice<0,0,0,inner> {
        typedef NodalElement NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
};

template<>
class Meshcaracinter<1,1> { 
public:
    static const unsigned dim = 1;
    typedef double Tpos;
    typedef Vec<double,1> Pvec;
    struct NodalStaticData {
        NodalStaticData():qtrans(0) {}
        typedef Vec<double,1> T0;
        CARACDMEXTNAME(0,T0,qtrans,"");
        CARACDMEXTNAME(1,Pvec,pos,"m");
        static const unsigned nb_params = 2;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    struct GlobalStaticData {
        VOIDDMSET;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    template<unsigned nvi_to_subs,unsigned skin,unsigned num_sub_element,unsigned inner=0>
    struct ElementChoice {
        typedef void NE;
        typedef DefaultBehavior BE;
        typedef VoidDMSet TData;
    };
    struct TCDM0 {
        TCDM0():type(0),num(0),num_group(0),F(0),W(0),dWn(0),dWt(0),dissipation(0),d(0) {}
        CARACDMEXTNAME(0,double,type,"");
        CARACDMEXTNAME(1,unsigned,num,"");
        CARACDMEXTNAME(2,unsigned,num_group,"");
        typedef Vec<unsigned> T3;
        CARACDMEXTNAME(3,T3,elem,"");
        typedef Vec<double,1> T4;
        CARACDMEXTNAME(4,T4,F,"Mpa");
        typedef Vec<double,1> T5;
        CARACDMEXTNAME(5,T5,W,"m/s");
        typedef Vec<double,1> T6;
        CARACDMEXTNAME(6,T6,dWn,"m/s");
        typedef Vec<double,1> T7;
        CARACDMEXTNAME(7,T7,dWt,"m/s");
        typedef Vec<double,1> T8;
        CARACDMEXTNAME(8,T8,dissipation,"J");
        CARACDMEXTNAME(9,double,d,"");
        static const unsigned nb_params = 10;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    template<unsigned inner> struct ElementChoice<0,0,0,inner> {
        typedef Bar NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<0,0,1,inner> {
        typedef Bar_3 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,0,0,inner> {
        typedef NodalElement NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,1,0,inner> {
        typedef NodalElement NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
};

template<>
class Meshcaracinter<2,1> { 
public:
    static const unsigned dim = 2;
    typedef double Tpos;
    typedef Vec<double,2> Pvec;
    struct NodalStaticData {
        NodalStaticData():qtrans(0) {}
        typedef Vec<double,2> T0;
        CARACDMEXTNAME(0,T0,qtrans,"");
        CARACDMEXTNAME(1,Pvec,pos,"m");
        static const unsigned nb_params = 2;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    struct GlobalStaticData {
        VOIDDMSET;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    template<unsigned nvi_to_subs,unsigned skin,unsigned num_sub_element,unsigned inner=0>
    struct ElementChoice {
        typedef void NE;
        typedef DefaultBehavior BE;
        typedef VoidDMSet TData;
    };
    struct TCDM0 {
        TCDM0():type(0),num(0),num_group(0),F(0),W(0),dWn(0),dWt(0),dissipation(0),d(0) {}
        CARACDMEXTNAME(0,double,type,"");
        CARACDMEXTNAME(1,unsigned,num,"");
        CARACDMEXTNAME(2,unsigned,num_group,"");
        typedef Vec<unsigned> T3;
        CARACDMEXTNAME(3,T3,elem,"");
        typedef Vec<double,2> T4;
        CARACDMEXTNAME(4,T4,F,"Mpa");
        typedef Vec<double,2> T5;
        CARACDMEXTNAME(5,T5,W,"m/s");
        typedef Vec<double,2> T6;
        CARACDMEXTNAME(6,T6,dWn,"m/s");
        typedef Vec<double,2> T7;
        CARACDMEXTNAME(7,T7,dWt,"m/s");
        typedef Vec<double,2> T8;
        CARACDMEXTNAME(8,T8,dissipation,"J");
        CARACDMEXTNAME(9,double,d,"");
        static const unsigned nb_params = 10;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    template<unsigned inner> struct ElementChoice<0,0,0,inner> {
        typedef Bar NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<0,0,1,inner> {
        typedef Bar_3 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,0,0,inner> {
        typedef NodalElement NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,1,0,inner> {
        typedef NodalElement NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
};

template<>
class Meshcaracinter<3,1> { 
public:
    static const unsigned dim = 3;
    typedef double Tpos;
    typedef Vec<double,3> Pvec;
    struct NodalStaticData {
        NodalStaticData():qtrans(0) {}
        typedef Vec<double,3> T0;
        CARACDMEXTNAME(0,T0,qtrans,"");
        CARACDMEXTNAME(1,Pvec,pos,"m");
        static const unsigned nb_params = 2;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    struct GlobalStaticData {
        VOIDDMSET;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    template<unsigned nvi_to_subs,unsigned skin,unsigned num_sub_element,unsigned inner=0>
    struct ElementChoice {
        typedef void NE;
        typedef DefaultBehavior BE;
        typedef VoidDMSet TData;
    };
    struct TCDM0 {
        TCDM0():type(0),num(0),num_group(0),F(0),W(0),dWn(0),dWt(0),dissipation(0),d(0) {}
        CARACDMEXTNAME(0,double,type,"");
        CARACDMEXTNAME(1,unsigned,num,"");
        CARACDMEXTNAME(2,unsigned,num_group,"");
        typedef Vec<unsigned> T3;
        CARACDMEXTNAME(3,T3,elem,"");
        typedef Vec<double,3> T4;
        CARACDMEXTNAME(4,T4,F,"Mpa");
        typedef Vec<double,3> T5;
        CARACDMEXTNAME(5,T5,W,"m/s");
        typedef Vec<double,3> T6;
        CARACDMEXTNAME(6,T6,dWn,"m/s");
        typedef Vec<double,3> T7;
        CARACDMEXTNAME(7,T7,dWt,"m/s");
        typedef Vec<double,3> T8;
        CARACDMEXTNAME(8,T8,dissipation,"J");
        CARACDMEXTNAME(9,double,d,"");
        static const unsigned nb_params = 10;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    template<unsigned inner> struct ElementChoice<0,0,0,inner> {
        typedef Bar NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<0,0,1,inner> {
        typedef Bar_3 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,0,0,inner> {
        typedef NodalElement NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,1,0,inner> {
        typedef NodalElement NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
};

template<>
class Meshcaracinter<1,2> { 
public:
    static const unsigned dim = 1;
    typedef double Tpos;
    typedef Vec<double,1> Pvec;
    struct NodalStaticData {
        NodalStaticData():qtrans(0) {}
        typedef Vec<double,1> T0;
        CARACDMEXTNAME(0,T0,qtrans,"");
        CARACDMEXTNAME(1,Pvec,pos,"m");
        static const unsigned nb_params = 2;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    struct GlobalStaticData {
        VOIDDMSET;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    template<unsigned nvi_to_subs,unsigned skin,unsigned num_sub_element,unsigned inner=0>
    struct ElementChoice {
        typedef void NE;
        typedef DefaultBehavior BE;
        typedef VoidDMSet TData;
    };
    struct TCDM0 {
        TCDM0():type(0),num(0),num_group(0),F(0),W(0),dWn(0),dWt(0),dissipation(0),d(0) {}
        CARACDMEXTNAME(0,double,type,"");
        CARACDMEXTNAME(1,unsigned,num,"");
        CARACDMEXTNAME(2,unsigned,num_group,"");
        typedef Vec<unsigned> T3;
        CARACDMEXTNAME(3,T3,elem,"");
        typedef Vec<double,1> T4;
        CARACDMEXTNAME(4,T4,F,"Mpa");
        typedef Vec<double,1> T5;
        CARACDMEXTNAME(5,T5,W,"m/s");
        typedef Vec<double,1> T6;
        CARACDMEXTNAME(6,T6,dWn,"m/s");
        typedef Vec<double,1> T7;
        CARACDMEXTNAME(7,T7,dWt,"m/s");
        typedef Vec<double,1> T8;
        CARACDMEXTNAME(8,T8,dissipation,"J");
        CARACDMEXTNAME(9,double,d,"");
        static const unsigned nb_params = 10;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    template<unsigned inner> struct ElementChoice<0,0,0,inner> {
        typedef Triangle NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<0,0,1,inner> {
        typedef Quad NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<0,0,2,inner> {
        typedef Triangle_6 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<0,0,3,inner> {
        typedef Quad_8 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,0,0,inner> {
        typedef Bar NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,0,1,inner> {
        typedef Bar_3 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,1,0,inner> {
        typedef Bar NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,1,1,inner> {
        typedef Bar_3 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
};

template<>
class Meshcaracinter<2,2> { 
public:
    static const unsigned dim = 2;
    typedef double Tpos;
    typedef Vec<double,2> Pvec;
    struct NodalStaticData {
        NodalStaticData():qtrans(0) {}
        typedef Vec<double,2> T0;
        CARACDMEXTNAME(0,T0,qtrans,"");
        CARACDMEXTNAME(1,Pvec,pos,"m");
        static const unsigned nb_params = 2;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    struct GlobalStaticData {
        VOIDDMSET;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    template<unsigned nvi_to_subs,unsigned skin,unsigned num_sub_element,unsigned inner=0>
    struct ElementChoice {
        typedef void NE;
        typedef DefaultBehavior BE;
        typedef VoidDMSet TData;
    };
    struct TCDM0 {
        TCDM0():type(0),num(0),num_group(0),F(0),W(0),dWn(0),dWt(0),dissipation(0),d(0) {}
        CARACDMEXTNAME(0,double,type,"");
        CARACDMEXTNAME(1,unsigned,num,"");
        CARACDMEXTNAME(2,unsigned,num_group,"");
        typedef Vec<unsigned> T3;
        CARACDMEXTNAME(3,T3,elem,"");
        typedef Vec<double,2> T4;
        CARACDMEXTNAME(4,T4,F,"Mpa");
        typedef Vec<double,2> T5;
        CARACDMEXTNAME(5,T5,W,"m/s");
        typedef Vec<double,2> T6;
        CARACDMEXTNAME(6,T6,dWn,"m/s");
        typedef Vec<double,2> T7;
        CARACDMEXTNAME(7,T7,dWt,"m/s");
        typedef Vec<double,2> T8;
        CARACDMEXTNAME(8,T8,dissipation,"J");
        CARACDMEXTNAME(9,double,d,"");
        static const unsigned nb_params = 10;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    template<unsigned inner> struct ElementChoice<0,0,0,inner> {
        typedef Triangle NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<0,0,1,inner> {
        typedef Quad NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<0,0,2,inner> {
        typedef Triangle_6 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<0,0,3,inner> {
        typedef Quad_8 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,0,0,inner> {
        typedef Bar NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,0,1,inner> {
        typedef Bar_3 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<2,0,0,inner> {
        typedef NodalElement NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,1,0,inner> {
        typedef Bar NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,1,1,inner> {
        typedef Bar_3 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<2,1,0,inner> {
        typedef NodalElement NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
};

template<>
class Meshcaracinter<3,2> { 
public:
    static const unsigned dim = 3;
    typedef double Tpos;
    typedef Vec<double,3> Pvec;
    struct NodalStaticData {
        NodalStaticData():qtrans(0) {}
        typedef Vec<double,3> T0;
        CARACDMEXTNAME(0,T0,qtrans,"");
        CARACDMEXTNAME(1,Pvec,pos,"m");
        static const unsigned nb_params = 2;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    struct GlobalStaticData {
        VOIDDMSET;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    template<unsigned nvi_to_subs,unsigned skin,unsigned num_sub_element,unsigned inner=0>
    struct ElementChoice {
        typedef void NE;
        typedef DefaultBehavior BE;
        typedef VoidDMSet TData;
    };
    struct TCDM0 {
        TCDM0():type(0),num(0),num_group(0),F(0),W(0),dWn(0),dWt(0),dissipation(0),d(0) {}
        CARACDMEXTNAME(0,double,type,"");
        CARACDMEXTNAME(1,unsigned,num,"");
        CARACDMEXTNAME(2,unsigned,num_group,"");
        typedef Vec<unsigned> T3;
        CARACDMEXTNAME(3,T3,elem,"");
        typedef Vec<double,3> T4;
        CARACDMEXTNAME(4,T4,F,"Mpa");
        typedef Vec<double,3> T5;
        CARACDMEXTNAME(5,T5,W,"m/s");
        typedef Vec<double,3> T6;
        CARACDMEXTNAME(6,T6,dWn,"m/s");
        typedef Vec<double,3> T7;
        CARACDMEXTNAME(7,T7,dWt,"m/s");
        typedef Vec<double,3> T8;
        CARACDMEXTNAME(8,T8,dissipation,"J");
        CARACDMEXTNAME(9,double,d,"");
        static const unsigned nb_params = 10;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    template<unsigned inner> struct ElementChoice<0,0,0,inner> {
        typedef Triangle NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<0,0,1,inner> {
        typedef Quad NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<0,0,2,inner> {
        typedef Triangle_6 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<0,0,3,inner> {
        typedef Quad_8 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,0,0,inner> {
        typedef Bar NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,0,1,inner> {
        typedef Bar_3 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<2,0,0,inner> {
        typedef NodalElement NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,1,0,inner> {
        typedef Bar NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,1,1,inner> {
        typedef Bar_3 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<2,1,0,inner> {
        typedef NodalElement NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
};

template<>
class Meshcaracinter<1,3> { 
public:
    static const unsigned dim = 1;
    typedef double Tpos;
    typedef Vec<double,1> Pvec;
    struct NodalStaticData {
        NodalStaticData():qtrans(0) {}
        typedef Vec<double,1> T0;
        CARACDMEXTNAME(0,T0,qtrans,"");
        CARACDMEXTNAME(1,Pvec,pos,"m");
        static const unsigned nb_params = 2;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    struct GlobalStaticData {
        VOIDDMSET;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    template<unsigned nvi_to_subs,unsigned skin,unsigned num_sub_element,unsigned inner=0>
    struct ElementChoice {
        typedef void NE;
        typedef DefaultBehavior BE;
        typedef VoidDMSet TData;
    };
    struct TCDM0 {
        TCDM0():type(0),num(0),num_group(0),F(0),W(0),dWn(0),dWt(0),dissipation(0),d(0) {}
        CARACDMEXTNAME(0,double,type,"");
        CARACDMEXTNAME(1,unsigned,num,"");
        CARACDMEXTNAME(2,unsigned,num_group,"");
        typedef Vec<unsigned> T3;
        CARACDMEXTNAME(3,T3,elem,"");
        typedef Vec<double,1> T4;
        CARACDMEXTNAME(4,T4,F,"Mpa");
        typedef Vec<double,1> T5;
        CARACDMEXTNAME(5,T5,W,"m/s");
        typedef Vec<double,1> T6;
        CARACDMEXTNAME(6,T6,dWn,"m/s");
        typedef Vec<double,1> T7;
        CARACDMEXTNAME(7,T7,dWt,"m/s");
        typedef Vec<double,1> T8;
        CARACDMEXTNAME(8,T8,dissipation,"J");
        CARACDMEXTNAME(9,double,d,"");
        static const unsigned nb_params = 10;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    template<unsigned inner> struct ElementChoice<0,0,0,inner> {
        typedef Tetra NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,0,0,inner> {
        typedef Triangle NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,0,1,inner> {
        typedef Quad NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,0,2,inner> {
        typedef Triangle_6 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,0,3,inner> {
        typedef Quad_8 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,1,0,inner> {
        typedef Triangle NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,1,1,inner> {
        typedef Quad NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,1,2,inner> {
        typedef Triangle_6 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,1,3,inner> {
        typedef Quad_8 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
};

template<>
class Meshcaracinter<2,3> { 
public:
    static const unsigned dim = 2;
    typedef double Tpos;
    typedef Vec<double,2> Pvec;
    struct NodalStaticData {
        NodalStaticData():qtrans(0) {}
        typedef Vec<double,2> T0;
        CARACDMEXTNAME(0,T0,qtrans,"");
        CARACDMEXTNAME(1,Pvec,pos,"m");
        static const unsigned nb_params = 2;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    struct GlobalStaticData {
        VOIDDMSET;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    template<unsigned nvi_to_subs,unsigned skin,unsigned num_sub_element,unsigned inner=0>
    struct ElementChoice {
        typedef void NE;
        typedef DefaultBehavior BE;
        typedef VoidDMSet TData;
    };
    struct TCDM0 {
        TCDM0():type(0),num(0),num_group(0),F(0),W(0),dWn(0),dWt(0),dissipation(0),d(0) {}
        CARACDMEXTNAME(0,double,type,"");
        CARACDMEXTNAME(1,unsigned,num,"");
        CARACDMEXTNAME(2,unsigned,num_group,"");
        typedef Vec<unsigned> T3;
        CARACDMEXTNAME(3,T3,elem,"");
        typedef Vec<double,2> T4;
        CARACDMEXTNAME(4,T4,F,"Mpa");
        typedef Vec<double,2> T5;
        CARACDMEXTNAME(5,T5,W,"m/s");
        typedef Vec<double,2> T6;
        CARACDMEXTNAME(6,T6,dWn,"m/s");
        typedef Vec<double,2> T7;
        CARACDMEXTNAME(7,T7,dWt,"m/s");
        typedef Vec<double,2> T8;
        CARACDMEXTNAME(8,T8,dissipation,"J");
        CARACDMEXTNAME(9,double,d,"");
        static const unsigned nb_params = 10;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    template<unsigned inner> struct ElementChoice<0,0,0,inner> {
        typedef Tetra NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,0,0,inner> {
        typedef Triangle NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,0,1,inner> {
        typedef Quad NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,0,2,inner> {
        typedef Triangle_6 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,0,3,inner> {
        typedef Quad_8 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<2,0,0,inner> {
        typedef Bar NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<2,0,1,inner> {
        typedef Bar_3 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,1,0,inner> {
        typedef Triangle NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,1,1,inner> {
        typedef Quad NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,1,2,inner> {
        typedef Triangle_6 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,1,3,inner> {
        typedef Quad_8 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<2,1,0,inner> {
        typedef Bar NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<2,1,1,inner> {
        typedef Bar_3 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
};

template<>
class Meshcaracinter<3,3> { 
public:
    static const unsigned dim = 3;
    typedef double Tpos;
    typedef Vec<double,3> Pvec;
    struct NodalStaticData {
        NodalStaticData():qtrans(0) {}
        typedef Vec<double,3> T0;
        CARACDMEXTNAME(0,T0,qtrans,"");
        CARACDMEXTNAME(1,Pvec,pos,"m");
        static const unsigned nb_params = 2;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    struct GlobalStaticData {
        VOIDDMSET;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    template<unsigned nvi_to_subs,unsigned skin,unsigned num_sub_element,unsigned inner=0>
    struct ElementChoice {
        typedef void NE;
        typedef DefaultBehavior BE;
        typedef VoidDMSet TData;
    };
    struct TCDM0 {
        TCDM0():type(0),num(0),num_group(0),F(0),W(0),dWn(0),dWt(0),dissipation(0),d(0) {}
        CARACDMEXTNAME(0,double,type,"");
        CARACDMEXTNAME(1,unsigned,num,"");
        CARACDMEXTNAME(2,unsigned,num_group,"");
        typedef Vec<unsigned> T3;
        CARACDMEXTNAME(3,T3,elem,"");
        typedef Vec<double,3> T4;
        CARACDMEXTNAME(4,T4,F,"Mpa");
        typedef Vec<double,3> T5;
        CARACDMEXTNAME(5,T5,W,"m/s");
        typedef Vec<double,3> T6;
        CARACDMEXTNAME(6,T6,dWn,"m/s");
        typedef Vec<double,3> T7;
        CARACDMEXTNAME(7,T7,dWt,"m/s");
        typedef Vec<double,3> T8;
        CARACDMEXTNAME(8,T8,dissipation,"J");
        CARACDMEXTNAME(9,double,d,"");
        static const unsigned nb_params = 10;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<0, 0>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<1, 1>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<2, 2>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<3, 3>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<4, 4>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<5, 5>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Mat<double, LMT::Gen<6, 6>, LMT::Dense<LMT::Col> > &value) { assert(0); /*TODO*/ }
        template<class __G__> __G__ dm_data_get_field( const std::string field_name, StructForType<__G__> ) const { assert( 0 /*TODO*/ ); return __G__( 0.0 );  }
    };
    template<unsigned inner> struct ElementChoice<0,0,0,inner> {
        typedef Tetra NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,0,0,inner> {
        typedef Triangle NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,0,1,inner> {
        typedef Quad NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,0,2,inner> {
        typedef Triangle_6 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,0,3,inner> {
        typedef Quad_8 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<2,0,0,inner> {
        typedef Bar NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<2,0,1,inner> {
        typedef Bar_3 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<3,0,0,inner> {
        typedef NodalElement NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,1,0,inner> {
        typedef Triangle NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,1,1,inner> {
        typedef Quad NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,1,2,inner> {
        typedef Triangle_6 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<1,1,3,inner> {
        typedef Quad_8 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<2,1,0,inner> {
        typedef Bar NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<2,1,1,inner> {
        typedef Bar_3 NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
    template<unsigned inner> struct ElementChoice<3,1,0,inner> {
        typedef NodalElement NE;
        typedef DefaultBehavior BE;
        typedef TCDM0 TData;
        void dm_data_set_field( const std::string field_name, Tpos value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) { assert(0); /*TODO*/ }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) { assert(0); /*TODO*/ }
    };
};



};

#endif // LMT___SRC_UTILS_MESHCARACINTER_MESHCARAC_PY
