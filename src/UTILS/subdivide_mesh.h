//
// C++ Interface: subdivide_mesh
//
// Description: 
//
//
// Author: David Violeau <d.violeau@structure-computation.com>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef subdivide_mesh_HEADER
#define subdivide_mesh_HEADER

#include "util/rectilinear_iterator.h"

namespace LMT {

struct Bar;
struct Triangle;
struct Quad;
struct DefaultBehavior;

template<class TM, class TV>
    void subdivide_mesh(TM &m,const Bar &t, Vec<TV> &apex, int &nb_elem) {
        typedef typename TM::Pvec Pvec;
        for(unsigned i=0;i<= nb_elem ;i++){
            Pvec incr=apex[0]+(apex[1]-apex[0])*i/nb_elem;
            m.add_node(incr);
        }
        for(unsigned i=0;i<nb_elem  ;i++){
            m.add_element( Bar(), DefaultBehavior(),i,i+1);
            }
}

template<class TM, class TV>
    void subdivide_mesh(TM &m,const Triangle &t, Vec<TV> &apex, int &nb_elem) {
    typedef typename TM::Pvec Pvec;
    for(unsigned i=0;i<= nb_elem ;i++){
        for(unsigned j=0;j<= nb_elem-i  ;j++){
            Pvec incr=apex[0]+(apex[1]-apex[0])*j/nb_elem+(apex[2]-apex[0])*i/nb_elem;
            m.add_node(incr);
        }
    }
    unsigned nb_nodes=0;
    for(unsigned i=0;i<nb_elem  ;i++){
         unsigned nb_nodes_lign=nb_elem+1-i;
         for(unsigned j=0;j<nb_elem-i ;j++){
            Vec<unsigned> pts(  j+nb_nodes,j+1+nb_nodes,nb_nodes_lign+j+nb_nodes );
            m.add_element( Triangle(), DefaultBehavior(),pts[0],pts[1],pts[2]);
        }
        for(unsigned j=1;j<nb_elem-i ;j++){
            Vec<unsigned> pts( j+nb_nodes,j+nb_nodes+nb_nodes_lign,j-1+nb_nodes+nb_nodes_lign );
            m.add_element( Triangle(), DefaultBehavior(),pts[0],pts[1],pts[2]);
        }
        nb_nodes+=nb_nodes_lign;
    }
}

template<class TM, class TV>
        void subdivide_mesh(TM &m,const Quad &t, Vec<TV> &apex, int &nb_elem) {
            typedef typename TM::Pvec Pvec;
            make_rect( m, Quad(), apex[0], apex[2], Pvec( nb_elem,nb_elem ) );
        }

}

#endif // subdivide_mesh_HEADER
