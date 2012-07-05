//
// C++ Interface: utils
//
// Description: 
//
//
// Author: David Violeau <d.violeau@structure-computation.com>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef UTILS_2_H
#define UTILS_2_H
#include <iostream>
#include <exception>
#include <fstream>
#include <cassert>
#include <Metil/BasicVec.h>
#include <Metil/MathBasicVec.h>
#include <math.h>

#include "Sc2String.h"
//1#include "PARAMETERS/Parameters.h"
#include "../../LMT/include/io/ioexception.h"
#include "../../LMT/include/containers/vec.h"
#include "../../LMT/include/codegen/codegen.h"
#include "../../LMT/include/containers/basicops.h"

using namespace Metil;
using namespace LMT;

/* Penser a creer un test pour HDF5
void compare_hdfS(const Sc2String& name_file_hdf5_1, const Sc2String& name_file_hdf5_2){
    BasicVec<Sc2String> tags_hdf5;
    BasicVec<TYPE> results1;
    BasicVec<TYPE> results2;
    
    if (FileExists(name_file_hdf5_1.c_str())==0) {
        std::cerr << "Le fichier hdf5 "<< name_file_hdf5_1 << " n'existe pas " << std::endl;
        assert(0);
    }
    std::cout << " - Ouverture de " << name_file_hdf5_1 << std::endl;
    Hdf hdf_1( name_file_hdf5_1.c_str(),false,true );
    
    if (FileExists(name_file_hdf5_2.c_str())==0) {
        std::cerr << "Le fichier hdf5 "<< name_file_hdf5_2 << " n'existe pas " << std::endl;
        assert(0);
    }
    std::cout << " - Ouverture de " << name_file_hdf5_2 << std::endl;
    Hdf hdf_2( name_file_hdf5_2.c_str(),false,true );
    
    dim=DIM;
    
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_0/global_connectivities_0");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_0/global_connectivities_1");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_0/global_connectivities_2");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_0/global_connectivities_3");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_0/id_adjacent_groups");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_0/id_group_interface_edges");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_0/id_group_interface_interiors");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_0/id_group_interface_links");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_0/local_connectivities_0");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_0/local_connectivities_1");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_0/local_connectivities_2");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_0/local_connectivities_3");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_0/local_nodes/x");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_0/local_nodes/y");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_0/local_nodes/z");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_0/map_global_nodes");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_0/sides/side_0/interface_group_id");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_0/sides/side_0/num_in_group");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_0/sides/side_1/interface_group_id");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_0/sides/side_1/num_in_group");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_0/sides/side_2/interface_group_id");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_0/sides/side_2/num_in_group");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_0/sides/side_3/interface_group_id");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_0/sides/side_3/num_in_group");
    
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_1/global_connectivities_0");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_1/global_connectivities_1");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_1/global_connectivities_2");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_1/global_connectivities_3");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_1/id_adjacent_groups");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_1/id_group_interface_edges");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_1/id_group_interface_interiors");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_1/id_group_interface_links");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_1/local_connectivities_0");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_1/local_connectivities_1");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_1/local_connectivities_2");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_1/local_connectivities_3");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_1/local_nodes/x");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_1/local_nodes/y");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_1/local_nodes/z");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_1/map_global_nodes");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_1/sides/side_0/interface_group_id");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_1/sides/side_0/num_in_group");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_1/sides/side_1/interface_group_id");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_1/sides/side_1/num_in_group");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_1/sides/side_2/interface_group_id");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_1/sides/side_2/num_in_group");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_1/sides/side_3/interface_group_id");
    tag_hdf5.push_back("/Level_0/Geometry/elements_0/list_1/sides/side_3/num_in_group");
    
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_0/global_connectivities_0");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_0/global_connectivities_1");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_0/global_connectivities_2");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_0/local_connectivities_0");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_0/local_connectivities_1");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_0/local_connectivities_2");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_0/local_nodes/x");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_0/local_nodes/y");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_0/local_nodes/z");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_0/map_global_nodes");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_0/sides/side_0/interface_group_id");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_0/sides/side_0/num_in_group");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_0/sides/side_1/interface_group_id");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_0/sides/side_1/num_in_group");
    
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_1/global_connectivities_0");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_1/global_connectivities_1");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_1/global_connectivities_2");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_1/local_connectivities_0");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_1/local_connectivities_1");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_1/local_connectivities_2");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_1/local_nodes/x");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_1/local_nodes/y");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_1/local_nodes/z");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_1/map_global_nodes");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_1/sides/side_0/interface_group_id");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_1/sides/side_0/num_in_group");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_1/sides/side_1/interface_group_id");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_1/sides/side_1/num_in_group");
    
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_2/global_connectivities_0");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_2/global_connectivities_1");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_2/global_connectivities_2");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_2/local_connectivities_0");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_2/local_connectivities_1");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_2/local_connectivities_2");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_2/local_nodes/x");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_2/local_nodes/y");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_2/local_nodes/z");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_2/map_global_nodes");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_2/sides/side_0/interface_group_id");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_2/sides/side_0/num_in_group");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_2/sides/side_1/interface_group_id");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_2/sides/side_1/num_in_group");
    
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_3/global_connectivities_0");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_3/global_connectivities_1");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_3/global_connectivities_2");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_3/local_connectivities_0");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_3/local_connectivities_1");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_3/local_connectivities_2");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_3/local_nodes/x");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_3/local_nodes/y");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_3/local_nodes/z");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_3/map_global_nodes");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_3/sides/side_0/interface_group_id");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_3/sides/side_0/num_in_group");
    
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_4/global_connectivities_0");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_4/global_connectivities_1");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_4/global_connectivities_2");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_4/local_connectivities_0");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_4/local_connectivities_1");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_4/local_connectivities_2");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_4/local_nodes/x");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_4/local_nodes/y");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_4/local_nodes/z");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_4/map_global_nodes");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_4/sides/side_0/interface_group_id");
    tag_hdf5.push_back("/Level_0/Geometry/elements_1/list_4/sides/side_0/num_in_group");
    
    tag_hdf5.push_back("/Level_0/Geometry/nodes/x");
    tag_hdf5.push_back("/Level_0/Geometry/nodes/y");
    tag_hdf5.push_back("/Level_0/Geometry/nodes/z");
    
    for(int i_tag = 0; i < tags_hdf5.size(); i++){
        Sc2String tag = tags_hdf5[i];
        results1.read_from(hdf_1,tag);
        results1.read_from(hdf_2,tag);
        if(results1.size()!=results2.size()){
            std::cerr << std::endl << "Tailles differentes dans " << tag << std::endl;
        }
        for(int i = 0; i < results1.size(); i++){
            if(std::abs(results1[i]-results2[i]) > 1.e-6){
                std::cerr << std::endl << "Valeurs differentes dans " << tag << "   ligne " << i << std::endl;
                break;
            }
        }
    }
}
*/

template<typename T> void debug(const Sc2String& name, const T& val){
    std::cout << name << " : '";
    try{
        std::cout << val << "'" << std::endl;
    } catch ( const IoException &e ) {
        std::cout << e.what() << std::endl;
    }catch ( const std::exception &e ) {
        std::cout << e.what() << std::endl;
    }
}
/*
template<> void debug(const Sc2String& name, const MainParameter &param){
    std::cout << "MainParameter " << name << "(" << param.symbol << ") = '" << param.value << "'" << std::endl;
}

template<> void debug(const Sc2String& name, const UserParameter &param){
    std::cout << "UserParameter " << name << "(" << param.symbol << ") : '" << param.str_expr << "' = '" << param.value << "'" << std::endl;
}
*/
template<typename T> void debug(const Sc2String& name, const BasicVec<T>& val){
    std::cout << name << " : '";
    try{
        std::cout << val.size() << "'" << std::endl;
        for(int i = 0; i < val.size(); i++){
            std::cout << "    " << i;
            debug<T>("",val[i]);
        }
    } catch ( const IoException &e ) {
        std::cout << e.what() << std::endl;
    }catch ( const std::exception &e ) {
        std::cout << e.what() << std::endl;
    }
}

template<typename T,int dim> void debug(const Sc2String& name, const BasicVec<T,dim>& val){
    std::cout << name << " : '";
    try{
        std::cout << val.size() << "'" << std::endl;
        for(int i = 0; i < val.size(); i++){
            std::cout << "    " << i;
            debug<T>("",val[i]);
        }
    } catch ( const IoException &e ) {
        std::cout << e.what() << std::endl;
    }catch ( const std::exception &e ) {
        std::cout << e.what() << std::endl;
    }
}
template<typename T> void debug(const Sc2String& name, const LMT::Vec<T>& val){
    std::cout << name << " : '";
    try{
        std::cout << val.size() << "'" << std::endl;
        for(int i = 0; i < val.size(); i++){
            std::cout << "    " << i;
            debug<T>("",val[i]);
        }
    } catch ( const IoException &e ) {
        std::cout << e.what() << std::endl;
    }catch ( const std::exception &e ) {
        std::cout << e.what() << std::endl;
    }
}

///Verification si un fichier existe
inline bool FileExists( const char* FileName )
{
    FILE* fp = NULL;
    fp = fopen( FileName, "rb" );
    if( fp != NULL )
    {
        fclose( fp );
        return true;
    }
    return false;
}

struct GeomTest{
/**Verificication si un pt est a l'interieur d'une boite definie par ses deux extremites (rectangle en 2d et parallelepipede en 3d) en testant l'operation suivante :
        \f$ (\vec{MA}.\vec{x})x (\vec{MB}.\vec{x}) <=0 \f$
        \f$ (\vec{MA}.\vec{y})x (\vec{MB}.\vec{y}) <=0 \f$
        \f$ (\vec{MA}.\vec{z})x (\vec{MB}.\vec{z}) <=0 \f$
**/
static bool pt_in_box(const BasicVec<TYPEREEL,2> &pt, const BasicVec<BasicVec<TYPEREEL,2> > &box, const double eps=1e-3){
    bool flag=0;
    BasicVec<TYPEREEL,2> x(1.,0.),y(0.,1.);
    if( (dot(pt-box[0],x)*dot(pt-box[1],x)<=eps) and (dot(pt-box[0],y)*dot(pt-box[1],y)<=eps) )
        flag=1;
    return flag;
}
static bool pt_in_box(const BasicVec<TYPEREEL,3> &pt, const BasicVec<BasicVec<TYPEREEL,3> > &box,  const double eps=1e-3){
    bool flag=0;
    BasicVec<TYPEREEL,3> x(1.,0.,0.),y(0.,1.,0.),z(0.,0.,1.);   
    if( (dot(pt-box[0],x)*dot(pt-box[1],x)<=eps) and (dot(pt-box[0],y)*dot(pt-box[1],y)<=eps) and (dot(pt-box[0],z)*dot(pt-box[1],z)<=eps) )
        flag=1;     
    return flag;
}
static bool pt_in_box(const BasicVec<TYPEREEL,2> &pt, const BasicVec<BasicVec<TYPEREEL,2>,2 > &box, const double eps=1e-3){
    bool flag=0;
    BasicVec<TYPEREEL,2> x(1.,0.),y(0.,1.);
    if( (dot(pt-box[0],x)*dot(pt-box[1],x)<=eps) and (dot(pt-box[0],y)*dot(pt-box[1],y)<=eps) )
        flag=1;
    return flag;
}
static bool pt_in_box(const BasicVec<TYPEREEL,3> &pt, const BasicVec<BasicVec<TYPEREEL,3>,2> &box,  const double eps=1e-3){
    bool flag=0;
    BasicVec<TYPEREEL,3> x(1.,0.,0.),y(0.,1.,0.),z(0.,0.,1.);   
    if( (dot(pt-box[0],x)*dot(pt-box[1],x)<=eps) and (dot(pt-box[0],y)*dot(pt-box[1],y)<=eps) and (dot(pt-box[0],z)*dot(pt-box[1],z)<=eps) )
        flag=1;     
    return flag;
}


/**V�rificication si un pt est a l'interieur d'un cylyndre definie par ses deux extremites et par son rayon en testant l'operation suivante :
        - r = ||vec(box[0],pt) - <(vec(box[0],pt_in_box),vec(box[0],box[1]))> / ||(vec(box[0],box[1]))||  ||
	- test r < R
**/
static bool pt_in_cylinder(const BasicVec<TYPEREEL,2> &pt, const BasicVec<BasicVec<TYPEREEL,2> > &box, TYPEREEL radius, const double eps=1e-3){
    bool flag=false;
    TYPEREEL dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2_p2(box[1]-box[0]);
    TYPEREEL r = norm_2_p2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2_p2(box[1]-box[0]));
    if( r <= std::abs(radius+eps) && dot_pt_box >=0 && dot_pt_box <= norm_2_p2(box[1]-box[0]) )
        flag=true;
    return flag;
}
static bool pt_in_cylinder(const BasicVec<TYPEREEL,3> &pt, const BasicVec<BasicVec<TYPEREEL,3> > &box, TYPEREEL radius,  const double eps=1e-3){
    bool flag=false;
    TYPEREEL dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2_p2(box[1]-box[0]);
    TYPEREEL r = norm_2_p2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2_p2(box[1]-box[0]));
    if( r <= std::abs(radius+eps) && dot_pt_box >=0 && dot_pt_box <= norm_2_p2(box[1]-box[0]) )
        flag=true;
    return flag;
}
static bool pt_in_cylinder(const BasicVec<TYPEREEL,2> &pt, const BasicVec<BasicVec<TYPEREEL,2>,2> &box, TYPEREEL radius, const double eps=1e-3){
    bool flag=false;
    TYPEREEL dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2_p2(box[1]-box[0]);
    TYPEREEL r = norm_2_p2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2_p2(box[1]-box[0]));
    if( r <= std::abs(radius+eps) && dot_pt_box >=0 && dot_pt_box <= norm_2_p2(box[1]-box[0]) )
        flag=true;
    return flag;
}
static bool pt_in_cylinder(const BasicVec<TYPEREEL,3> &pt, const BasicVec<BasicVec<TYPEREEL,3>,2> &box, TYPEREEL radius,  const double eps=1e-3){
    bool flag=false;
    TYPEREEL dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2_p2(box[1]-box[0]);
    TYPEREEL r = norm_2_p2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2_p2(box[1]-box[0]));
    if( r <= std::abs(radius+eps) && dot_pt_box >=0 && dot_pt_box <= norm_2_p2(box[1]-box[0]) )
        flag=true;
    return flag;
}

/**V�rificication si un pt est sur un cylyndre definie par ses deux extremites et par son rayon en testant l'operation suivante :
        - r = ||vec(box[0],pt) - <(vec(box[0],pt_in_box),vec(box[0],box[1]))> / ||(vec(box[0],box[1]))||  ||
	- test r < R
**/
static bool pt_on_cylinder(const BasicVec<TYPEREEL,2> &pt, const BasicVec<BasicVec<TYPEREEL,2> > &box, TYPEREEL radius, const double eps=1e-3){
    bool flag=false;
    TYPEREEL dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2_p2(box[1]-box[0]);
    TYPEREEL r = norm_2_p2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2_p2(box[1]-box[0]));
    if( std::abs( r-radius ) <= eps && dot_pt_box >=0 && dot_pt_box <= norm_2_p2(box[1]-box[0]) )
        flag=true;
    return flag;
}
static bool pt_on_cylinder(const BasicVec<TYPEREEL,3> &pt, const BasicVec<BasicVec<TYPEREEL,3> > &box, TYPEREEL radius,  const double eps=1e-3){
    bool flag=false;
    TYPEREEL dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2_p2(box[1]-box[0]);
    TYPEREEL r = norm_2_p2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2_p2(box[1]-box[0]));
    if( std::abs( r-radius ) <= eps && dot_pt_box >=0 && dot_pt_box <= norm_2_p2(box[1]-box[0]) )
        flag=true;
    return flag;
}
static bool pt_on_cylinder(const BasicVec<TYPEREEL,2> &pt, const BasicVec<BasicVec<TYPEREEL,2>,2> &box, TYPEREEL radius, const double eps=1e-3){
    bool flag=false;
    TYPEREEL dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2_p2(box[1]-box[0]);
    TYPEREEL r = norm_2_p2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2_p2(box[1]-box[0]));
    if( std::abs( r-radius ) <= eps && dot_pt_box >=0 && dot_pt_box <= norm_2_p2(box[1]-box[0]) )
        flag=true;
    return flag;
}
static bool pt_on_cylinder(const BasicVec<TYPEREEL,3> &pt, const BasicVec<BasicVec<TYPEREEL,3>,2> &box, TYPEREEL radius,  const double eps=1e-3){
    bool flag=false;
    TYPEREEL dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2_p2(box[1]-box[0]);
    TYPEREEL r = norm_2_p2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2_p2(box[1]-box[0]));
    if( std::abs( r-radius ) <= eps && dot_pt_box >=0 && dot_pt_box <= norm_2_p2(box[1]-box[0]) )
        flag=true;
    return flag;
}


/**V�rificication si un pt est a l'interieur d'une sphere definie par son centre et par son rayon en testant l'operation suivante :
        - r = ||vec(box[0],pt)  ||
	- test r < R
**/
static bool pt_in_sphere(const BasicVec<TYPEREEL,2> &pt, const BasicVec<TYPEREEL,2> &box, TYPEREEL radius, const double eps=1e-3){
    bool flag=false;
    TYPEREEL r = std::sqrt(norm_2_p2( pt-box ));
    if( r <= std::abs(radius+eps) )
        flag=true;
    return flag;
}
static bool pt_in_sphere(const BasicVec<TYPEREEL,3> &pt, const BasicVec<TYPEREEL,3> &box, TYPEREEL radius, const double eps=1e-3){
    bool flag=false;
    TYPEREEL r = std::sqrt(norm_2_p2( pt-box ));
    if( r <= std::abs(radius+eps) )
        flag=true;
    return flag;
}

/**V�rificication si un pt est sur une sphere definie par son centre et par son rayon en testant l'operation suivante :
        - r = ||vec(box[0],pt)  ||
	- test r == R
**/
static bool pt_on_sphere(const BasicVec<TYPEREEL,2> &pt, const BasicVec<TYPEREEL,2> &box, TYPEREEL radius, const double eps=1e-3){
    bool flag=false;
    TYPEREEL r = std::sqrt(norm_2_p2( pt-box ));
    if( std::abs( r-radius ) <= eps)
        flag=true;
    return flag;
}
static bool pt_on_sphere(const BasicVec<TYPEREEL,3> &pt, const BasicVec<TYPEREEL,3> &box, TYPEREEL radius, const double eps=1e-3){
    bool flag=false;
    TYPEREEL r = std::sqrt(norm_2_p2( pt-box ));
    if( std::abs( r-radius ) <= eps)
        flag=true;
    return flag;
}



/**Vérificication si un pt est sur un plan definie par son centre et par sa normale en testant l'operation suivante :
        - d = || dot(vec(pt,centre),normale) || / ||normale||
	- test d <= eps
**/
static bool pt_on_plan(const BasicVec<TYPEREEL,2> &pt, const BasicVec<TYPEREEL,2> &box, const BasicVec<TYPEREEL,2> &normal, const double eps=1e-3){
    bool flag=false;
    TYPEREEL d =  dot(pt-box, normal) / norm_2_p2( normal );
    if( std::abs( d ) <= eps) 
        flag=true;
    return flag;
}
static bool pt_on_plan(const BasicVec<TYPEREEL,3> &pt, const BasicVec<TYPEREEL,3> &box, const BasicVec<TYPEREEL,3> &normal, const double eps=1e-3){
    bool flag=false;
    TYPEREEL d =  dot(pt-box, normal) / norm_2_p2( normal );
    if( std::abs( d ) <= eps)
        flag=true;
    return flag;
}

/**Vérificication si un pt est sur un disc definie par son centre, sa normale et son rayon en testant l'operation suivante :
        - qu'il est sur le plan 
	- que r < R
**/
static bool pt_on_disc(const BasicVec<TYPEREEL,2> &pt, const BasicVec<TYPEREEL,2> &box, const BasicVec<TYPEREEL,2> &normal, TYPEREEL radius, const double eps=1e-3){
    bool flag=false;
    TYPEREEL r = std::sqrt(norm_2_p2( pt-box ));
    if( r <= (radius+eps) && pt_on_plan(pt, box, normal))
        flag=true;
    return flag;
}
static bool pt_on_disc(const BasicVec<TYPEREEL,3> &pt, const BasicVec<TYPEREEL,3> &box, const BasicVec<TYPEREEL,3> &normal, TYPEREEL radius,  const double eps=1e-3){
    bool flag=false;
    TYPEREEL r = std::sqrt(norm_2_p2( pt-box ));
    if( r <= (radius+eps) && pt_on_plan(pt, box, normal))
        flag=true;
    return flag;
}




/**V�rificication si un pt verifie une equation
**/
static bool pt_match_equation(const BasicVec<TYPEREEL,2> &pt, const Sc2String &equation, const double eps=1e-3){
    bool flag=false;
    std::vector<Codegen::Ex> symbols;
    symbols.push_back("x");
    symbols.push_back("y");

    TYPEREEL data=0.;
    Codegen::Ex expr;
    expr = read_ex(equation,symbols);
    
    Codegen::Ex::MapExNum var;
    for(unsigned d2=0;d2<2;++d2)//boucle sur les inconnues possibles (dimension des vecteurs)
	var[symbols[d2]] = pt[d2];
    data = (TYPEREEL)expr.subs_numerical(var);
    
    if( std::abs( data ) <= eps )
        flag=true;
    return flag;
}

static bool pt_match_equation(const BasicVec<TYPEREEL,3> &pt, const Sc2String &equation, const double eps=1e-3){
    bool flag=false;
    std::vector<Codegen::Ex> symbols;
    symbols.push_back("x");
    symbols.push_back("y");
    symbols.push_back("z");

    TYPEREEL data=0.;
    Codegen::Ex expr;
    expr = read_ex(equation,symbols);
    
    Codegen::Ex::MapExNum var;
    for(unsigned d2=0;d2<3;++d2)//boucle sur les inconnues possibles (dimension des vecteurs)
	var[symbols[d2]] = pt[d2];
    data = (TYPEREEL)expr.subs_numerical(var);
    
    if( std::abs( data ) <= eps )
        flag=true;
    return flag;
}
};

#endif // UTILS_H
