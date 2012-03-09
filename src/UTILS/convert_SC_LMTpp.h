//
// C++ Interface: convert_SC_LMTpp
//
// Description: 
//
//
// Author: Violeau David,,, <d.violeau@structure-computation.com>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "problem_pb_elast/problem.h"

using namespace LMT;
using namespace std;

template<class TM>
void convert_tri(TYPE * nodes, int * elem, int nb_nodes, int nb_elem, TM &m, int nb_apex){
    typedef typename TM::Pvec Pvec;
    typedef typename TM::TNode TNode;
    map<int,TNode *> map_num_node;
    
    for(unsigned i=0;i< nb_nodes  ;i++){
        Vec<TYPE,DIM> vec;
        for(int di=0;di<DIM;di++)
            vec[di]=nodes[i*DIM+di];
        map_num_node[number] = m.add_node(vec);
    }

    for(unsigned i=0;i< nb_elem  ;i++){
        LMT::Vec<TNode *> vn; vn.resize(nb_apex);
        for(int j=0;j<nb_apex;j++) {
            int number=elem[i*nb_apex+j];
            vn[i] = map_num_node[number];
        }
#if DIM==2
        m.add_element(Triangle(),DefaultBehavior(),vn.ptr());
#else 
        m.add_element(Tetra(),DefaultBehavior(),vn.ptr());
#end
    }
}