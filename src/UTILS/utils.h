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
#ifndef UTILS_U_H
#define UTILS_U_H

#include <iostream>
#include "../../LMT/include/io/ioexception.h"
#include "../../LMT/include/containers/vec.h"
#include "../../LMT/include/codegen/codegen.h"
#include "../../LMT/include/containers/basicops.h"

using namespace LMT;
using namespace Codegen;


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


/**Vérificication si un pt est a l'interieur d'une boite definie par ses deux extremites (rectangle en 2d et parallelepipede en 3d) en testant l'operation suivante :
        \f$ (\vec{MA}.\vec{x})x (\vec{MB}.\vec{x}) <=0 \f$
        \f$ (\vec{MA}.\vec{y})x (\vec{MB}.\vec{y}) <=0 \f$
        \f$ (\vec{MA}.\vec{z})x (\vec{MB}.\vec{z}) <=0 \f$
**/
template<class T> bool pt_in_box(Vec<T,2> &pt, Vec<Vec<T,2> > &box, const double eps=1e-3){
    bool flag=0;
    Vec<T,2> x(1.,0.),y(0.,1.);
    if( (dot(pt-box[0],x)*dot(pt-box[1],x)<=eps) and (dot(pt-box[0],y)*dot(pt-box[1],y)<=eps) )
        flag=1;
    return flag;
}
template<class T> bool pt_in_box(Vec<T,3> &pt, Vec<Vec<T,3> > &box,  const double eps=1e-3){
    bool flag=0;
    Vec<T,3> x(1.,0.,0.),y(0.,1.,0.),z(0.,0.,1.);   
    if( (dot(pt-box[0],x)*dot(pt-box[1],x)<=eps) and (dot(pt-box[0],y)*dot(pt-box[1],y)<=eps) and (dot(pt-box[0],z)*dot(pt-box[1],z)<=eps) )
        flag=1;     
    return flag;
}
template<class T> bool pt_in_box(Vec<T,2> &pt, Vec<Vec<T,2>,2> &box, const double eps=1e-3){
    bool flag=0;
    Vec<T,2> x(1.,0.),y(0.,1.);
    if( (dot(pt-box[0],x)*dot(pt-box[1],x)<=eps) and (dot(pt-box[0],y)*dot(pt-box[1],y)<=eps) )
        flag=1;
    return flag;
}
template<class T> bool pt_in_box(Vec<T,3> &pt, Vec<Vec<T,3>,2> &box,  const double eps=1e-3){
    bool flag=0;
    Vec<T,3> x(1.,0.,0.),y(0.,1.,0.),z(0.,0.,1.);   
    if( (dot(pt-box[0],x)*dot(pt-box[1],x)<=eps) and (dot(pt-box[0],y)*dot(pt-box[1],y)<=eps) and (dot(pt-box[0],z)*dot(pt-box[1],z)<=eps) )
        flag=1;     
    return flag;
}
template<class T> bool pt_in_box(const Vec<T,2> &pt, Vec<Vec<T,2>,2> &box, const double eps=1e-3){
    bool flag=0;
    Vec<T,2> x(1.,0.),y(0.,1.);
    if( (dot(pt-box[0],x)*dot(pt-box[1],x)<=eps) and (dot(pt-box[0],y)*dot(pt-box[1],y)<=eps) )
        flag=1;
    return flag;
}
template<class T> bool pt_in_box(const Vec<T,3> &pt, Vec<Vec<T,3>,2> &box,  const double eps=1e-3){
    bool flag=0;
    Vec<T,3> x(1.,0.,0.),y(0.,1.,0.),z(0.,0.,1.);   
    if( (dot(pt-box[0],x)*dot(pt-box[1],x)<=eps) and (dot(pt-box[0],y)*dot(pt-box[1],y)<=eps) and (dot(pt-box[0],z)*dot(pt-box[1],z)<=eps) )
        flag=1;     
    return flag;
}

/**V?rificication si un pt est a l'interieur d'un cylyndre definie par ses deux extremites et par son rayon en testant l'operation suivante :
        - r = ||vec(box[0],pt) - <(vec(box[0],pt_in_box),vec(box[0],box[1]))> / ||(vec(box[0],box[1]))||  ||
    - test r < R
**/
template<class T> bool pt_in_cylinder(Vec<T,2> &pt, Vec<Vec<T,2> > &box, T radius, const double eps=1e-3){
    bool flag=false;
    T dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2(box[1]-box[0]);
    T r = norm_2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2(box[1]-box[0]));
    if( r <= std::abs(radius+eps) && dot_pt_box >=0 && dot_pt_box <= norm_2(box[1]-box[0]) )
        flag=true;
    return flag;
}
template<class T> bool pt_in_cylinder(Vec<T,3> &pt, Vec<Vec<T,3> > &box, T radius, const double eps=1e-3){
    bool flag=false;
    T dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2(box[1]-box[0]);
    T r = norm_2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2(box[1]-box[0]));
    if( r <= std::abs(radius+eps) && dot_pt_box >=0 && dot_pt_box <= norm_2(box[1]-box[0]) )
        flag=true;
    return flag;
}
template<class T> bool pt_in_cylinder(Vec<T,2> &pt, Vec<Vec<T,2>,2> &box, T radius, const double eps=1e-3){
    bool flag=false;
    T dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2(box[1]-box[0]);
    T r = norm_2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2(box[1]-box[0]));
    if( r <= std::abs(radius+eps) && dot_pt_box >=0 && dot_pt_box <= norm_2(box[1]-box[0]) )
        flag=true;
    return flag;
}
template<class T> bool pt_in_cylinder(Vec<T,3> &pt, Vec<Vec<T,3>,2> &box, T radius,  const double eps=1e-3){
    bool flag=false;
    T dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2(box[1]-box[0]);
    T r = norm_2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2(box[1]-box[0]));
    if( r <= std::abs(radius+eps) && dot_pt_box >=0 && dot_pt_box <= norm_2(box[1]-box[0]) )
        flag=true;
    return flag;
}
template<class T> bool pt_in_cylinder(const Vec<T,2> &pt, Vec<Vec<T,2>,2> &box, T radius, const double eps=1e-3){
    bool flag=false;
    T dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2(box[1]-box[0]);
    T r = norm_2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2(box[1]-box[0]));
    if( r <= std::abs(radius+eps) && dot_pt_box >=0 && dot_pt_box <= norm_2(box[1]-box[0]) )
        flag=true;
    return flag;
}
template<class T> bool pt_in_cylinder(const Vec<T,3> &pt, Vec<Vec<T,3>,2> &box, T radius,  const double eps=1e-3){
    bool flag=false;
    T dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2(box[1]-box[0]);
    T r = norm_2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2(box[1]-box[0]));
    if( r <= std::abs(radius+eps) && dot_pt_box >=0 && dot_pt_box <= norm_2(box[1]-box[0]) )
        flag=true;
    return flag;
}

/**V?rificication si un pt est sur un cylyndre definie par ses deux extremites et par son rayon en testant l'operation suivante :
        - r = ||vec(box[0],pt) - <(vec(box[0],pt_in_box),vec(box[0],box[1]))> / ||(vec(box[0],box[1]))||  ||
    - test r < R
**/
template<class T> bool pt_on_cylinder(Vec<T,2> &pt, Vec<Vec<T,2> > &box, T radius, const double eps=1e-3){
    bool flag=false;
    T dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2(box[1]-box[0]);
    T r = norm_2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2(box[1]-box[0]));
    if( std::abs( r-radius ) <= eps && dot_pt_box >=0 && dot_pt_box <= norm_2(box[1]-box[0]) )
        flag=true;
    return flag;
}
template<class T> bool pt_on_cylinder(Vec<T,3> &pt, Vec<Vec<T,3> > &box, T radius, const double eps=1e-3){
    bool flag=false;
    T dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2(box[1]-box[0]);
    T r = norm_2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2(box[1]-box[0]));
    if( std::abs( r-radius ) <= eps && dot_pt_box >=0 && dot_pt_box <= norm_2(box[1]-box[0]) )
        flag=true;
    return flag;
}
template<class T> bool pt_on_cylinder(Vec<T,2> &pt, Vec<Vec<T,2>,2> &box, T radius, const double eps=1e-3){
    bool flag=false;
    T dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2(box[1]-box[0]);
    T r = norm_2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2(box[1]-box[0]));
    if( std::abs( r-radius ) <= eps && dot_pt_box >=0 && dot_pt_box <= norm_2(box[1]-box[0]) )
        flag=true;
    return flag;
}
template<class T> bool pt_on_cylinder(Vec<T,3> &pt, Vec<Vec<T,3>,2> &box, T radius,  const double eps=1e-3){
    bool flag=false;
    T dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2(box[1]-box[0]);
    T r = norm_2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2(box[1]-box[0]));
    if( std::abs( r-radius ) <= eps && dot_pt_box >=0 && dot_pt_box <= norm_2(box[1]-box[0]) )
        flag=true;
    return flag;
}
template<class T> bool pt_on_cylinder(const Vec<T,2> &pt, Vec<Vec<T,2>,2> &box, T radius, const double eps=1e-3){
    bool flag=false;
    T dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2(box[1]-box[0]);
    T r = norm_2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2(box[1]-box[0]));
    if( std::abs( r-radius ) <= eps && dot_pt_box >=0 && dot_pt_box <= norm_2(box[1]-box[0]) )
        flag=true;
    return flag;
}
template<class T> bool pt_on_cylinder(const Vec<T,3> &pt, Vec<Vec<T,3>,2> &box, T radius,  const double eps=1e-3){
    bool flag=false;
    T dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2(box[1]-box[0]);
    T r = norm_2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2(box[1]-box[0]));
    if( std::abs( r-radius ) <= eps && dot_pt_box >=0 && dot_pt_box <= norm_2(box[1]-box[0]) )
        flag=true;
    return flag;
}


/**V?rificication si un pt est a l'interieur d'une sphere definie par son centre et par son rayon en testant l'operation suivante :
        - r = ||vec(box[0],pt)  ||
    - test r < R
**/
template<class T> bool pt_in_sphere(Vec<T,2> &pt, Vec<T,2> &box, T radius, const double eps=1e-3){
    bool flag=false;
    T r = norm_2( pt-box );
    if( r <= std::abs(radius+eps) )
        flag=true;
    return flag;
}
template<class T> bool pt_in_sphere(Vec<T,3> &pt, Vec<T,3> &box, T radius, const double eps=1e-3){
    bool flag=false;
    T r = norm_2( pt-box );
    if( r <= std::abs(radius+eps) )
        flag=true;
    return flag;
}

/**V?rificication si un pt est sur une sphere definie par son centre et par son rayon en testant l'operation suivante :
        - r = ||vec(box[0],pt)  ||
    - test r == R
**/
template<class T> bool pt_on_sphere(Vec<T,2> &pt, Vec<T,2> &box, T radius, const double eps=1e-3){
    bool flag=false;
    T r = norm_2( pt-box );
    if( std::abs( r-radius ) <= eps)
        flag=true;
    return flag;
}
template<class T> bool pt_on_sphere(Vec<T,3> &pt, Vec<T,3> &box, T radius, const double eps=1e-3){
    bool flag=false;
    T r = norm_2( pt-box );
    if( std::abs( r-radius ) <= eps)
        flag=true;
    return flag;
}



/**V?rificication si un pt est sur un plan definie par son centre et par sa normale en testant l'operation suivante :
        - d = || dot(vec(pt,centre),normale) || / ||normale||
    - test d <= eps
**/
template<class T> bool pt_on_plan(Vec<T,2> &pt, Vec<T,2> &box, Vec<T,2> &normal, const double eps=1e-3){
    bool flag=false;
    T d =  dot(pt-box, normal) / norm_2( normal );
    if( std::abs( d ) <= eps) 
        flag=true;
    return flag;
}
template<class T> bool pt_on_plan(Vec<T,3> &pt, Vec<T,3> &box, Vec<T,3> &normal, const double eps=1e-3){
    bool flag=false;
    T d =  dot(pt-box, normal) / norm_2( normal );
    if( std::abs( d ) <= eps)
        flag=true;
    return flag;
}

/**V?rificication si un pt est sur un disc definie par son centre, sa normale et son rayon en testant l'operation suivante :
        - qu'il est sur le plan 
    - que r < R
**/
template<class T> bool pt_on_disc(Vec<T,2> &pt, Vec<T,2> &box, Vec<T,2> &normal, T radius, const double eps=1e-3){
    bool flag=false;
    T r = norm_2( pt-box );
    if( r <= (radius+eps) && pt_on_plan(pt, box, normal))
        flag=true;
    return flag;
}
template<class T> bool pt_on_disc(Vec<T,3> &pt, Vec<T,3> &box, Vec<T,3> &normal, T radius,  const double eps=1e-3){
    bool flag=false;
    T r = norm_2( pt-box );
    if( r <= (radius+eps) && pt_on_plan(pt, box, normal))
        flag=true;
    return flag;
}


/**V?rificication si un pt verifie une equation
**/
template<class T> bool pt_match_equation(Vec<T,2> &pt, Sc2String equation, const double eps=1e-3){
    bool flag=false;
    std::vector<Ex> symbols;
    symbols.push_back("x");
    symbols.push_back("y");

    TYPE data=0.;
    Ex expr;
    expr = read_ex(equation,symbols);
    
    Ex::MapExNum var;
    for(unsigned d2=0;d2<2;++d2)//boucle sur les inconnues possibles (dimension des vecteurs)
    var[symbols[d2]] = pt[d2];
    data = (TYPE)expr.subs_numerical(var);
    
    if( std::abs( data ) <= eps )
        flag=true;
    return flag;
}

template<class T> bool pt_match_equation(Vec<T,3> &pt, Sc2String equation, const double eps=1e-3){
    bool flag=false;
    std::vector<Ex> symbols;
    symbols.push_back("x");
    symbols.push_back("y");
    symbols.push_back("z");

    TYPE data=0.;
    Ex expr;
    expr = read_ex(equation,symbols);
    
    Ex::MapExNum var;
    for(unsigned d2=0;d2<3;++d2)//boucle sur les inconnues possibles (dimension des vecteurs)
    var[symbols[d2]] = pt[d2];
    data = (TYPE)expr.subs_numerical(var);
    
    if( std::abs( data ) <= eps )
        flag=true;
    return flag;
}







#include <Metil/Hdf.h>
using namespace Metil;


/**Vérificication si un pt est a l'interieur d'une boite definie par ses deux extremites (rectangle en 2d et parallelepipede en 3d) en testant l'operation suivante :
        \f$ (\vec{MA}.\vec{x})x (\vec{MB}.\vec{x}) <=0 \f$
        \f$ (\vec{MA}.\vec{y})x (\vec{MB}.\vec{y}) <=0 \f$
        \f$ (\vec{MA}.\vec{z})x (\vec{MB}.\vec{z}) <=0 \f$
**/
template<class T> bool pt_in_box(BasicVec<T,2> &pt, BasicVec<BasicVec<T,2> > &box, const double eps=1e-3){
    bool flag=0;
    BasicVec<T,2> x(1.,0.),y(0.,1.);
    if( (dot(pt-box[0],x)*dot(pt-box[1],x)<=eps) and (dot(pt-box[0],y)*dot(pt-box[1],y)<=eps) )
        flag=1;
    return flag;
}
template<class T> bool pt_in_box(BasicVec<T,3> &pt, BasicVec<BasicVec<T,3> > &box,  const double eps=1e-3){
    bool flag=0;
    BasicVec<T,3> x(1.,0.,0.),y(0.,1.,0.),z(0.,0.,1.);   
    if( (dot(pt-box[0],x)*dot(pt-box[1],x)<=eps) and (dot(pt-box[0],y)*dot(pt-box[1],y)<=eps) and (dot(pt-box[0],z)*dot(pt-box[1],z)<=eps) )
        flag=1;     
    return flag;
}
template<class T> bool pt_in_box(BasicVec<T,2> &pt, BasicVec<BasicVec<T,2>,2> &box, const double eps=1e-3){
    bool flag=0;
    BasicVec<T,2> x(1.,0.),y(0.,1.);
    if( (dot(pt-box[0],x)*dot(pt-box[1],x)<=eps) and (dot(pt-box[0],y)*dot(pt-box[1],y)<=eps) )
        flag=1;
    return flag;
}
template<class T> bool pt_in_box(BasicVec<T,3> &pt, BasicVec<BasicVec<T,3>,2> &box,  const double eps=1e-3){
    bool flag=0;
    BasicVec<T,3> x(1.,0.,0.),y(0.,1.,0.),z(0.,0.,1.);   
    if( (dot(pt-box[0],x)*dot(pt-box[1],x)<=eps) and (dot(pt-box[0],y)*dot(pt-box[1],y)<=eps) and (dot(pt-box[0],z)*dot(pt-box[1],z)<=eps) )
        flag=1;     
    return flag;
}
template<class T> bool pt_in_box(const BasicVec<T,2> &pt, BasicVec<BasicVec<T,2>,2> &box, const double eps=1e-3){
    bool flag=0;
    BasicVec<T,2> x(1.,0.),y(0.,1.);
    if( (dot(pt-box[0],x)*dot(pt-box[1],x)<=eps) and (dot(pt-box[0],y)*dot(pt-box[1],y)<=eps) )
        flag=1;
    return flag;
}
template<class T> bool pt_in_box(const BasicVec<T,3> &pt, BasicVec<BasicVec<T,3>,2> &box,  const double eps=1e-3){
    bool flag=0;
    BasicVec<T,3> x(1.,0.,0.),y(0.,1.,0.),z(0.,0.,1.);   
    if( (dot(pt-box[0],x)*dot(pt-box[1],x)<=eps) and (dot(pt-box[0],y)*dot(pt-box[1],y)<=eps) and (dot(pt-box[0],z)*dot(pt-box[1],z)<=eps) )
        flag=1;     
    return flag;
}


/**Vérificication si un pt est a l'interieur d'un cylyndre definie par ses deux extremites et par son rayon en testant l'operation suivante :
        - r = ||vec(box[0],pt) - <(vec(box[0],pt_in_box),vec(box[0],box[1]))> / ||(vec(box[0],box[1]))||  ||
        - test r < R
**/
template<class T> bool pt_in_cylinder(BasicVec<T,2> &pt, BasicVec<BasicVec<T,2> > &box, T radius, const double eps=1e-3){
    bool flag=false;
    T dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2_p2(box[1]-box[0]);
    BasicVec<T,2> vec1 =  dot_pt_box * (box[1]-box[0]);
    T r = norm_2_p2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2_p2(box[1]-box[0]));
    if( r <= std::abs(radius+eps) && dot_pt_box >=0 && dot_pt_box <= norm_2_p2(box[1]-box[0]) )
        flag=true;
    return flag;
}
template<class T> bool pt_in_cylinder(BasicVec<T,3> &pt, BasicVec<BasicVec<T,3> > &box, T radius, const double eps=1e-3){
    bool flag=false;
    T dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2_p2(box[1]-box[0]);
    T r = norm_2_p2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2_p2(box[1]-box[0]));
    if( r <= std::abs(radius+eps) && dot_pt_box >=0 && dot_pt_box <= norm_2_p2(box[1]-box[0]) )
        flag=true;
    return flag;
}
template<class T> bool pt_in_cylinder(BasicVec<T,2> &pt, BasicVec<BasicVec<T,2>,2> &box, T radius, const double eps=1e-3){
    bool flag=false;
    T dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2_p2(box[1]-box[0]);
    T r = norm_2_p2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2_p2(box[1]-box[0]));
    if( r <= std::abs(radius+eps) && dot_pt_box >=0 && dot_pt_box <= norm_2_p2(box[1]-box[0]) )
        flag=true;
    return flag;
}
template<class T> bool pt_in_cylinder(BasicVec<T,3> &pt, BasicVec<BasicVec<T,3>,2> &box, T radius,  const double eps=1e-3){
    bool flag=false;
    T dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2_p2(box[1]-box[0]);
    T r = norm_2_p2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2_p2(box[1]-box[0]));
    if( r <= std::abs(radius+eps) && dot_pt_box >=0 && dot_pt_box <= norm_2_p2(box[1]-box[0]) )
        flag=true;
    return flag;
}
template<class T> bool pt_in_cylinder(const BasicVec<T,2> &pt, BasicVec<BasicVec<T,2>,2> &box, T radius, const double eps=1e-3){
    bool flag=false;
    T dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2_p2(box[1]-box[0]);
    T r = norm_2_p2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2_p2(box[1]-box[0]));
    if( r <= std::abs(radius+eps) && dot_pt_box >=0 && dot_pt_box <= norm_2_p2(box[1]-box[0]) )
        flag=true;
    return flag;
}
template<class T> bool pt_in_cylinder(const BasicVec<T,3> &pt, BasicVec<BasicVec<T,3>,2> &box, T radius,  const double eps=1e-3){
    bool flag=false;
    T dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2_p2(box[1]-box[0]);
    T r = norm_2_p2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2_p2(box[1]-box[0]));
    if( r <= std::abs(radius+eps) && dot_pt_box >=0 && dot_pt_box <= norm_2_p2(box[1]-box[0]) )
        flag=true;
    return flag;
}

/**Vérificication si un pt est sur un cylyndre definie par ses deux extremites et par son rayon en testant l'operation suivante :
        - r = ||vec(box[0],pt) - <(vec(box[0],pt_in_box),vec(box[0],box[1]))> / ||(vec(box[0],box[1]))||  ||
        - test r < R
**/
template<class T> bool pt_on_cylinder(BasicVec<T,2> &pt, BasicVec<BasicVec<T,2> > &box, T radius, const double eps=1e-3){
    bool flag=false;
    T dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2_p2(box[1]-box[0]);
    T r = norm_2_p2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2_p2(box[1]-box[0]));
    if( std::abs( r-radius ) <= eps && dot_pt_box >=0 && dot_pt_box <= norm_2_p2(box[1]-box[0]) )
        flag=true;
    return flag;
}
template<class T> bool pt_on_cylinder(BasicVec<T,3> &pt, BasicVec<BasicVec<T,3> > &box, T radius, const double eps=1e-3){
    bool flag=false;
    T dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2_p2(box[1]-box[0]);
    T r = norm_2_p2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2_p2(box[1]-box[0]));
    if( std::abs( r-radius ) <= eps && dot_pt_box >=0 && dot_pt_box <= norm_2_p2(box[1]-box[0]) )
        flag=true;
    return flag;
}
template<class T> bool pt_on_cylinder(BasicVec<T,2> &pt, BasicVec<BasicVec<T,2>,2> &box, T radius, const double eps=1e-3){
    bool flag=false;
    T dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2_p2(box[1]-box[0]);
    T r = norm_2_p2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2_p2(box[1]-box[0]));
    if( std::abs( r-radius ) <= eps && dot_pt_box >=0 && dot_pt_box <= norm_2_p2(box[1]-box[0]) )
        flag=true;
    return flag;
}
template<class T> bool pt_on_cylinder(BasicVec<T,3> &pt, BasicVec<BasicVec<T,3>,2> &box, T radius,  const double eps=1e-3){
    bool flag=false;
    T dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2_p2(box[1]-box[0]);
    T r = norm_2_p2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2_p2(box[1]-box[0]));
    if( std::abs( r-radius ) <= eps && dot_pt_box >=0 && dot_pt_box <= norm_2_p2(box[1]-box[0]) )
        flag=true;
    return flag;
}
template<class T> bool pt_on_cylinder(const BasicVec<T,2> &pt, BasicVec<BasicVec<T,2>,2> &box, T radius, const double eps=1e-3){
    bool flag=false;
    T dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2_p2(box[1]-box[0]);
    T r = norm_2_p2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2_p2(box[1]-box[0]));
    if( std::abs( r-radius ) <= eps && dot_pt_box >=0 && dot_pt_box <= norm_2_p2(box[1]-box[0]) )
        flag=true;
    return flag;
}
template<class T> bool pt_on_cylinder(const BasicVec<T,3> &pt, BasicVec<BasicVec<T,3>,2> &box, T radius,  const double eps=1e-3){
    bool flag=false;
    T dot_pt_box =  dot(pt-box[0],box[1]-box[0]) / norm_2_p2(box[1]-box[0]);
    T r = norm_2_p2((pt-box[0]) - dot_pt_box * (box[1]-box[0]) / norm_2_p2(box[1]-box[0]));
    if( std::abs( r-radius ) <= eps && dot_pt_box >=0 && dot_pt_box <= norm_2_p2(box[1]-box[0]) )
        flag=true;
    return flag;
}


/**Vérificication si un pt est a l'interieur d'une sphere definie par son centre et par son rayon en testant l'operation suivante :
        - r = ||vec(box[0],pt)  ||
        - test r < R
**/
template<class T> bool pt_in_sphere(BasicVec<T,2> &pt, BasicVec<T,2> &box, T radius, const double eps=1e-3){
    bool flag=false;
    T r = norm_2_p2( pt-box );
    if( r <= std::abs(radius+eps) )
        flag=true;
    return flag;
}
template<class T> bool pt_in_sphere(BasicVec<T,3> &pt, BasicVec<T,3> &box, T radius, const double eps=1e-3){
    bool flag=false;
    T r = norm_2_p2( pt-box );
    if( r <= std::abs(radius+eps) )
        flag=true;
    return flag;
}

/**Vérificication si un pt est sur une sphere definie par son centre et par son rayon en testant l'operation suivante :
        - r = ||vec(box[0],pt)  ||
        - test r == R
**/
template<class T> bool pt_on_sphere(BasicVec<T,2> &pt, BasicVec<T,2> &box, T radius, const double eps=1e-3){
    bool flag=false;
    T r = norm_2_p2( pt-box );
    if( std::abs( r-radius ) <= eps)
        flag=true;
    return flag;
}
template<class T> bool pt_on_sphere(BasicVec<T,3> &pt, BasicVec<T,3> &box, T radius, const double eps=1e-3){
    bool flag=false;
    T r = norm_2_p2( pt-box );
    if( std::abs( r-radius ) <= eps)
        flag=true;
    return flag;
}



/**Vérificication si un pt est sur un plan definie par son centre et par sa normale en testant l'operation suivante :
        - d = || dot(vec(pt,centre),normale) || / ||normale||
        - test d <= eps
**/
template<class T> bool pt_on_plan(BasicVec<T,2> &pt, BasicVec<T,2> &box, BasicVec<T,2> &normal, const double eps=1e-3){
    bool flag=false;
    T d =  dot(pt-box, normal) / norm_2_p2( normal );
    if( std::abs( d ) <= eps) 
        flag=true;
    return flag;
}
template<class T> bool pt_on_plan(BasicVec<T,3> &pt, BasicVec<T,3> &box, BasicVec<T,3> &normal, const double eps=1e-3){
    bool flag=false;
    T d =  dot(pt-box, normal) / norm_2_p2( normal );
    if( std::abs( d ) <= eps)
        flag=true;
    return flag;
}

/**Vérificication si un pt est sur un disc definie par son centre, sa normale et son rayon en testant l'operation suivante :
        - qu'il est sur le plan 
        - que r < R
**/
template<class T> bool pt_on_disc(BasicVec<T,2> &pt, BasicVec<T,2> &box, BasicVec<T,2> &normal, T radius, const double eps=1e-3){
    bool flag=false;
    T r = norm_2_p2( pt-box );
    if( r <= (radius+eps) && pt_on_plan(pt, box, normal))
        flag=true;
    return flag;
}
template<class T> bool pt_on_disc(BasicVec<T,3> &pt, BasicVec<T,3> &box, BasicVec<T,3> &normal, T radius,  const double eps=1e-3){
    bool flag=false;
    T r = norm_2_p2( pt-box );
    if( r <= (radius+eps) && pt_on_plan(pt, box, normal))
        flag=true;
    return flag;
}


/**Vérificication si un pt verifie une equation
**/
template<class T> bool pt_match_equation(BasicVec<T,2> &pt, Sc2String equation, const double eps=1e-3){
    bool flag=false;
    std::vector<Ex> symbols;
    symbols.push_back("x");
    symbols.push_back("y");

    TYPE data=0.;
    Ex expr;
    expr = read_ex(equation,symbols);
    
    Ex::MapExNum var;
    for(unsigned d2=0;d2<2;++d2)//boucle sur les inconnues possibles (dimension des vecteurs)
        var[symbols[d2]] = pt[d2];
    data = (TYPE)expr.subs_numerical(var);
    
    if( std::abs( data ) <= eps )
        flag=true;
    return flag;
}

template<class T> bool pt_match_equation(BasicVec<T,3> &pt, Sc2String equation, const double eps=1e-3){
    bool flag=false;
    std::vector<Ex> symbols;
    symbols.push_back("x");
    symbols.push_back("y");
    symbols.push_back("z");

    TYPE data=0.;
    Ex expr;
    expr = read_ex(equation,symbols);
    
    Ex::MapExNum var;
    for(unsigned d2=0;d2<3;++d2)//boucle sur les inconnues possibles (dimension des vecteurs)
        var[symbols[d2]] = pt[d2];
    data = (TYPE)expr.subs_numerical(var);
    
    if( std::abs( data ) <= eps )
        flag=true;
    return flag;
}


#endif // UTILS_H
