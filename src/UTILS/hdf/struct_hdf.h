#ifndef STRUCT_HDF
#define STRUCT_HDF


#include <Metil/String.h>

#include <Metil/BasicVec.h>
#include <Metil/CudaMetil.h>
#include <Metil/BasicVecGpu.h>
#include <Metil/Hdf.h>
#include <fstream>
#include <sstream>
#include <boost/concept_check.hpp>

using namespace Metil;


struct Nodes_pattern_Hdf{
    template<class Hdf> void write_to( Hdf &hdf, const String &name ) {
        x.write_to( hdf, name + "/x" );
        y.write_to( hdf, name + "/y" );
#if DIM==3
        z.write_to( hdf, name + "/z" );
#endif
    }
    template<class Hdf> void read_from( Hdf &hdf, const String &name ) {
        x.read_from( hdf, name + "/x" );
        y.read_from( hdf, name + "/y" );
#if DIM==3
        z.read_from( hdf, name + "/z" );
#endif
    }
    BasicVec<double> x, y, z; //coordonnees des noeuds
};

struct Elements_pattern_Hdf{
    template<class Hdf> void write_to( Hdf &hdf, const String &name ) {
        c0.write_to( hdf, name + "/c0" );
        c1.write_to( hdf, name + "/c1" );
        c2.write_to( hdf, name + "/c2" );
#if DIM==3       
        c3.write_to( hdf, name + "/c3" );
#endif
    }
    template<class Hdf> void read_from( Hdf &hdf, const String &name ) {
        c0.read_from( hdf, name + "/c0" );
        c1.read_from( hdf, name + "/c1" );
        c2.read_from( hdf, name + "/c2" );
#if DIM==3       
        c3.read_from( hdf, name + "/c3" );
#endif
    }
    BasicVec<int> c0, c1, c2, c3; //connectivites
};


struct Displacements_Hdf{
    template<class Hdf> void write_to( Hdf &hdf, const String &name ) {
        x.write_to( hdf, name + "/x" );
        y.write_to( hdf, name + "/y" );
#if DIM==3       
        z.write_to( hdf, name + "/z" );
#endif
    }    
    BasicVec<TYPE> x, y, z;
};

struct Tensor6_Hdf{
    template<class Hdf> void write_to( Hdf &hdf, const String &name ) {
        xx.write_to( hdf, name + "/xx" );
        yy.write_to( hdf, name + "/yy" );
        xy.write_to( hdf, name + "/xy" );
#if DIM==3       
        zz.write_to( hdf, name + "/zz" );
        xz.write_to( hdf, name + "/xz" );
        yz.write_to( hdf, name + "/yz" );
#endif
    }    
    BasicVec<TYPE> xx, yy, zz, xy, xz, yz;
};


class Behaviours_Hdf{ 
    template<class Hdf> void write_to( Hdf &hdf, const String &name ) {   
        interfaces.write_to(hdf, name+"/interfaces");
        patterns.write_to(hdf, name+"/patterns");
    }
    template<class Hdf> void read_from( Hdf &hdf, const String &name ) {   
        interfaces.read_from(hdf, name+"/interfaces");
        patterns.read_from(hdf, name+"/patterns");
    }     
    BasicVec<int> interfaces;
    BasicVec<int> patterns;
};


class Fields_Hdf{
    template<class Hdf> void write_to( Hdf &hdf, const String &name ) {
        nodes_in_patterns.write_to(hdf,name+"/nodes");
        elements_in_patterns.write_to(hdf,name+"/elements");
        sigma.write_to(hdf,name+"/sigma");
        epsilon.write_to(hdf,name+"/epsilon");
        displacements.write_to(hdf,name+"/displacements");
        sigma_von_mises.write_to(hdf,name+"/sigma_von_mises");
    }        

    Nodes_pattern_Hdf nodes_in_patterns;
    Elements_pattern_Hdf elements_in_patterns;
    Tensor6_Hdf sigma;
    Tensor6_Hdf epsilon;
    Displacements_Hdf displacements;
    BasicVec<TYPE> sigma_von_mises;
};



#endif
