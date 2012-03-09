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
#ifndef UTILS_MESH_H
#define UTILS_MESH_H

#include "containers/vec.h"
#include "mesh/displayparaview.h"
#include "mesh/calculate_measure.h"

using namespace std;


struct adapt_qtrans {
    template<class TN>
            void operator()(TN &node, typename TN::Pvec &trans) const {
        node.qtrans=node.pos-trans;
            }
};
                
template<class TM>
        void mesh_threshold(TM &m, double &th){
    typedef typename TM::Pvec Pvec;
    Pvec G=barycenter_constant_rho(m);
// translation du maillage
    Pvec trans=G*th;
// modification du champ qtrans
    apply(m.node_list,adapt_qtrans(),trans);
        }
        
struct assign_num {
    template<class TE>
            void operator()(TE &e, unsigned &i) const {
        e.num_sst=i;
            }
};

    
        template<class TLIST>
                void display_list_mesh(TLIST &list,string type="all"){
            DisplayParaview dp;
            typename TLIST::TM meshglob;
            if(type=="all"){
                for(unsigned i=0;i< list.mesh.size() ;i++){
                    double th=1.0;
                    mesh_threshold(list.mesh[i],th);
                    apply(list.mesh[i].elem_list,assign_num(),i);
                    meshglob.append(list.mesh[i]);
                }
            }
            string name="./tmp/mesh";
            dp.add_mesh(meshglob,name,Vec<string>("qtrans","num_sst"));
            dp.exec();
                }

#endif //UTILS_MESH_H