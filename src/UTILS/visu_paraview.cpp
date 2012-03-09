//
// C++ Implementation: visu_paraview
//
// Description: 
//
//
// Author: David Violeau <dvioleau@structure-computation.com>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "containers/vec.h"
#include "mesh/displayparaview.h"
#include "mesh/calculate_measure.h"

#include "LEVEL.h"

#include "mesh_utils.h"

#if DIM==3
#ifdef CPU
#include "problem_prob_elast_cpu_3/mesh_carac.h"
#else
#include "problem_prob_elast_gpu_3/mesh_carac.h"
#endif
#endif

#if DIM==2
#ifdef CPU
#include "problem_prob_elast_cpu_2/mesh_carac.h"
#else
#include "problem_prob_elast_gpu_2/mesh_carac.h"
#endif
#endif

// #include "problem_prob_elast_3/mesh_carac.h"
// #include "problem_prob_elast_2/mesh_carac.h"
#include "meshcaracinter.h"

//#include "problem_pb_elast/problem.h"
#include <boost/concept_check.hpp>

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

#ifndef ASSIGN_NUM
#define ASSIGN_NUM     
struct assign_num {
     template<class TE>
        void operator()(TE &e, unsigned &i, int num_group) const {
            e.num=i;
            e.num_group=num_group;
        }
};
#endif //ASSIGN_NUM
#ifndef ASSIGN_NUM_E
#define ASSIGN_NUM_E   
struct assign_num_E {
     template<class TE>
        void operator()(TE &e, unsigned &i, int type, TYPE E) const {
            e.num=i;
            e.num_group=type;
            e.E=E;
        }
};
#endif //ASSIGN_NUM


void create_mesh_sst(int ns, int * S_apex, TYPE * data_user_node, NB &nb, TYPE * nodes, int * elements){
//     TYPE *apex; 
//     apex=(TYPE*)malloc(nb.apex_sst*DIM*sizeof(TYPE));
//     std::cout << ns << endl;
//     for(unsigned i=0;i<nb.apex_sst  ;i++){
//     int repnode=S_apex[i*nb.sst_s+ns];
//     for(unsigned j=0;j< DIM ;j++){
//         apex[i*DIM+j]=data_user_node[j+repnode*DIM];
//         std::cout << apex[i*DIM+j] << " " ;
//         }
//         std::cout << endl;
//     }
    

#if DIM==2
//create_mesh_tri_2D_ter(apex, nb.decoup, nodes, elements);
    //create_mesh_tri_2D_ter(apex, nb.decoup, nodes, elements);
    create_mesh_tri_2D(S_apex,data_user_node, nb.decoup, nodes, elements,nb.sst_s,ns); 
#else
    //create_mesh_tet_ter(apex, nb.decoup, nodes, elements);
    create_mesh_tet(S_apex,data_user_node, nb.decoup, nodes, elements,nb.sst_s,nb.apex_sst,ns); 
#endif
}

template<class TM>
    void convert_mesh(TM &m, TYPE * nodes, int * elem, NB &nb){
    typedef typename TM::Pvec Pvec;
    typedef typename TM::TNode TNode;
    map<int,TNode *> map_num_node;
    for(unsigned i=0;i< nb.nodes_sst  ;i++){
        Vec<TYPE,DIM> vec;
        for(int di=0;di<DIM;di++)
            vec[di]=nodes[i*DIM+di];
        map_num_node[i] = m.add_node(vec);
    }

    for(unsigned i=0;i< nb.elements_sst ;i++){
        LMT::Vec<TNode *> vn; vn.resize(nb.nodes_element_sst);
        for(int j=0;j<nb.nodes_element_sst;j++) {
            int number=elem[i*nb.nodes_element_sst+j];
            vn[j] = map_num_node[number];
            
        }

#if DIM==2
        m.add_element(Triangle(),DefaultBehavior(),vn.ptr());
#else 
        m.add_element(Tetra(),DefaultBehavior(),vn.ptr());
#endif
    }
}


template<class TM> 
void assignate_dep_to_nodes(int ns, TM &m, Vec<TYPE> &S_q, NB &nb){
    for(unsigned i=0;i< nb.nodes_sst  ;i++){
        for(unsigned id=0;id< DIM  ;id++){
            m.node_list[i].dep[id]=S_q[ns+nb.sst_s*(id+i*DIM)];
        }
    }
}

struct assign_sigma{
   template<class TE, class TV> void operator()(TE &e, Vec<int,3> &data_rep, TV &field) const{
       int num_elem=data_rep[0];
       int ns=data_rep[1];
       int nb_sst_s=data_rep[2];
       int nbe=data_rep[3];
       int nb_dim_field=DIM*(DIM+1)/2;
       for(unsigned nf=0; nf<nb_dim_field;nf++){
           e.sigma[nf]=field[ns+nb_sst_s*(nf*nbe+num_elem)];
       }
       data_rep[0]+=1;
   }
};

struct assign_epsilon{
   template<class TE, class TV> void operator()(TE &e, Vec<int,3> &data_rep, TV &field) const{
       int num_elem=data_rep[0];
       int ns=data_rep[1];
       int nb_sst_s=data_rep[2];
       int nbe=data_rep[3];
       int nb_dim_field=DIM*(DIM+1)/2;
       for(unsigned nf=0; nf<nb_dim_field;nf++){
           e.epsilon[nf]=field[ns+nb_sst_s*(nf*nbe+num_elem)];
       }
       data_rep[0]+=1;
   }
};

struct assign_sigma_von_mises{
   template<class TE, class TV> void operator()(TE &e, Vec<int,3> &data_rep, TV &field) const{
       int num_elem=data_rep[0];
       int ns=data_rep[1];
       int nb_sst_s=data_rep[2];
       int nbe=data_rep[3];
       e.sigma_mises=field[ns+nb_sst_s*num_elem];
       data_rep[0]+=1;
   }
};

#ifdef CPU
void create_LMTpp_mesh(Mesh<Mesh_carac_prob_elast_cpu<TYPE,DIM> > &meshglob, Vec<int> &S_apex, Vec<TYPE> &nodes, NB &nb, Vec<int> &num_group){
#else
void create_LMTpp_mesh(Mesh<Mesh_carac_prob_elast_gpu<TYPE,DIM> > &meshglob, Vec<int> &S_apex, Vec<TYPE> &nodes, NB &nb, Vec<int> &num_group){
#endif
    for(unsigned i=0;i< nb.sst ;i++){
        double th=1.0;
                    //creation du maillage pour la sst i
        int * elements_sst;
        TYPE * nodes_sst;
        nodes_sst=(TYPE*)malloc((DIM*nb.nodes_sst) * sizeof(TYPE));
        elements_sst=(int*)malloc((nb.nodes_element_sst*nb.elements_sst) * sizeof(int));
        create_mesh_sst(i, S_apex.ptr(), nodes.ptr(), nb,nodes_sst, elements_sst);

#ifdef CPU
        Mesh<Mesh_carac_prob_elast_cpu<TYPE,DIM> > m;    
#else
        Mesh<Mesh_carac_prob_elast_gpu<TYPE,DIM> > m;
#endif           
        convert_mesh(m,nodes_sst,elements_sst,nb);
        mesh_threshold(m,th);
          apply(m.elem_list,assign_num(),i,num_group[i]);
          
        meshglob.append(m);
    }
}
 

#ifdef CPU
void create_LMTpp_mesh_dep(Mesh<Mesh_carac_prob_elast_cpu<TYPE,DIM> > &meshglob, Vec<TYPE> &S_q, Vec<int> &S_apex, Vec<TYPE> &nodes, NB &nb, Vec<int> &num_group, Vec<TYPE> &E){
#else
void create_LMTpp_mesh_dep(Mesh<Mesh_carac_prob_elast_gpu<TYPE,DIM> > &meshglob, Vec<TYPE> &S_q, Vec<int> &S_apex, Vec<TYPE> &nodes, NB &nb, Vec<int> &num_group, Vec<TYPE> &E){
#endif
    for(unsigned i=0;i< nb.sst ;i++){
        double th=1.0;
                    //creation du maillage pour la sst i
        int * elements_sst;
        TYPE * nodes_sst;
        nodes_sst=(TYPE*)malloc((DIM*nb.nodes_sst) * sizeof(TYPE));
        elements_sst=(int*)malloc((nb.nodes_element_sst*nb.elements_sst) * sizeof(int));
        create_mesh_sst(i, S_apex.ptr(), nodes.ptr(), nb,nodes_sst, elements_sst);
        
#ifdef CPU
        Mesh<Mesh_carac_prob_elast_cpu<TYPE,DIM> > m;
#else
        Mesh<Mesh_carac_prob_elast_gpu<TYPE,DIM> > m;
#endif         
        convert_mesh(m,nodes_sst,elements_sst,nb);
                    
        assignate_dep_to_nodes(i,m,S_q,nb);
        mesh_threshold(m,th);
        apply(m.elem_list,assign_num_E(),i,num_group[i], E[i]);
        meshglob.append(m);
    }
}

#ifdef CPU
void create_LMTpp_mesh_dep_fields(Mesh<Mesh_carac_prob_elast_cpu<TYPE,DIM> > &meshglob, Vec<TYPE> &S_q, Vec<TYPE> &S_sigma, Vec<TYPE> &S_epsilon, Vec<TYPE> &S_sigma_von_mises, Vec<int> &S_apex, Vec<TYPE> &nodes, NB &nb, Vec<int> &num_group, Vec<TYPE> &E){
#else
void create_LMTpp_mesh_dep_fields(Mesh<Mesh_carac_prob_elast_gpu<TYPE,DIM> > &meshglob, Vec<TYPE> &S_q, Vec<TYPE> &S_sigma, Vec<TYPE> &S_epsilon, Vec<TYPE> &S_sigma_von_mises, Vec<int> &S_apex, Vec<TYPE> &nodes, NB &nb, Vec<int> &num_group, Vec<TYPE> &E){
#endif
    for(unsigned i=0;i< nb.sst ;i++){
        double th=1.0;
                    //creation du maillage pour la sst i
        int * elements_sst;
        TYPE * nodes_sst;
        nodes_sst=(TYPE*)malloc((DIM*nb.nodes_sst) * sizeof(TYPE));
        elements_sst=(int*)malloc((nb.nodes_element_sst*nb.elements_sst) * sizeof(int));
        create_mesh_sst(i, S_apex.ptr(), nodes.ptr(), nb,nodes_sst, elements_sst);
        
#ifdef CPU
        Mesh<Mesh_carac_prob_elast_cpu<TYPE,DIM> > m;
#else
        Mesh<Mesh_carac_prob_elast_gpu<TYPE,DIM> > m;
#endif      
        convert_mesh(m,nodes_sst,elements_sst,nb);

        assignate_dep_to_nodes(i,m,S_q,nb);
        Vec<int,3> data_rep;
        data_rep[0]=0; //num_local de l'element dans une sst
        data_rep[1]=i; //numero de la sst 
        data_rep[2]=nb.sst_s; //nbre de sst_s
        data_rep[3]=nb.elements_sst; //nbre d'elements pour une sst
        apply(m.elem_list,assign_sigma(),data_rep,S_sigma);
        data_rep[0]=0;
        apply(m.elem_list,assign_sigma_von_mises(),data_rep,S_sigma_von_mises);
        data_rep[0]=0;
        apply(m.elem_list,assign_epsilon(),data_rep,S_epsilon);
        mesh_threshold(m,th);
        apply(m.elem_list,assign_num_E(),i,num_group[i],E[i]);
        
        meshglob.append(m);
    }
}

/*
struct Projection_fields_on_skin{
  template<class TE, class TMS, class TM> void operator()(TE &e, const TMS &mskin, const TM &m) const{
    const typename TM::EA *ea = mskin.get_parents_of(e)[0];
    typedef typename TM::TElemList::template SubType<0>::T TypeParent;
    const TypeParent &parent = static_cast<const TypeParent &>( *ea );
    e.num = parent.num;
    e.num_group = parent.num_group;
  }
};*/

void LEVEL::display_mesh_sst(DATA_USER &data_user, string name="./tmp/paraview", string fields="qtrans,num,dep,num_group,sigma,epsilon,sigma_mises,E",int field=1){
            DisplayParaview dp;
            
#ifdef CPU
            Mesh<Mesh_carac_prob_elast_cpu<TYPE,DIM> > meshglob;
#else
            Mesh<Mesh_carac_prob_elast_gpu<TYPE,DIM> > meshglob;
#endif  
            Vec<string> keywords;
            keywords=tokenize(fields,',');
            //std::cout << keywords << endl;
                if(field==1){ //1 si deplacement uniquement
                create_LMTpp_mesh_dep(meshglob, S_q, S_apex, nodes, nb, S_num_group, S_E);
                }
                else if(field==2){ //2 si deplacement +contraintes...
                create_LMTpp_mesh_dep_fields(meshglob, S_q, S_sigma,S_epsilon,S_sigma_von_mises,S_apex, nodes, nb, S_num_group,S_E);
                }
                else{
                    create_LMTpp_mesh(meshglob, S_apex, nodes, nb, S_num_group);
                //    keywords=Vec<string>("qtrans","num","num_group");
                }
            //std::cout << name << endl;

            dp.add_mesh(meshglob,name,keywords);
            //dp.exec();
}



void assign_type( void *e, int tag, int num) {

}

template<class TE> void assign_type( TE *e, int tag, int num) {
    (*e).type=tag;
    (*e).num=num;
    //std::cout << (*e).type << endl;
}

template<class TM, class TMAP> 
void add_inter_mesh(TMAP &map_num_node, int nsst, int nside, int * S_apex, NB &nb, TM &m, int type, int num){
    typedef typename TM::TNode TNode;

    Vec<int> rep_apex;
    rep_apex.resize(nb.apex_sst);
    //std::cout << "apex_sst " << nb.apex_sst << endl;
    for(unsigned i=0;i< nb.apex_sst  ;i++){
        rep_apex[i]=S_apex[nsst+i*nb.sst_s];
    }
   // std::cout << rep_apex  << " " << nsst << " " << nside << endl;
    
    LMT::Vec<TNode *> vn; vn.resize(nb.apex_inter);
    for(unsigned i=0;i< nb.apex_inter ;i++){
            int number=rep_apex[(nside+i)%nb.apex_sst];
            //std::cout << number << endl;
            vn[i] = map_num_node[number];
        }
#if DIM==2
        assign_type(m.add_element(Bar(),DefaultBehavior(),vn.ptr()),type, num);
#else 
        assign_type(m.add_element(Triangle(),DefaultBehavior(),vn.ptr()),type, num);
#endif 
} 



void LEVEL::display_interface(DATA_USER &data_user, string type="all"){
    DisplayParaview dp;
    //Mesh<Meshcaracinter<DIM,DIM-1> > meshglob;
    typedef Mesh<Meshcaracinter<DIM,DIM-1> > TM;
    TM meshglob;

    if(type=="all"){
        typedef TM::Pvec Pvec;
        typedef TM::TNode TNode;
        map<int,TNode *> map_num_node;
        int nbnodes=nodes.size()/DIM;
        for(unsigned i=0;i< nbnodes  ;i++){
            Vec<TYPE,DIM> vec;
            for(int di=0;di<DIM;di++)
                vec[di]=nodes[i*DIM+di];
            
            map_num_node[i] = meshglob.add_node(vec);
        }
        
        for(unsigned i=0;i< nb.i_perfect  ;i++){
            int reps=I_perfect_side[i];
            int type=0;
	    int group=I_perfect_group[i];
	    //std::cout << group << endl;
	    add_inter_mesh(map_num_node,side_rep[reps],side_rep[reps+nb.side_s],S_apex.ptr(),nb,meshglob,type,group);
           // add_inter_mesh(map_num_node,side_rep[reps],side_rep[reps+nb.side_s],S_apex.ptr(),nb,meshglob,type,reps):
        }
        for(unsigned i=0;i< nb.i_eff  ;i++){
            int reps=I_eff_side[i];
            int type=1;
            if(I_eff_data[i]==data_user.Behaviour_CL.size()-1){
                type=2;
            }
            int group=1000;
            add_inter_mesh(map_num_node,side_rep[reps],side_rep[reps+nb.side_s],S_apex.ptr(),nb,meshglob,type,group);
        }
        for(unsigned i=0;i< nb.i_depl  ;i++){
            int reps=I_depl_side[i];
            int type=3;
	    int group=1000;
            add_inter_mesh(map_num_node,side_rep[reps],side_rep[reps+nb.side_s],S_apex.ptr(),nb,meshglob,type,group);
        }
        for(unsigned i=0;i< nb.i_contact  ;i++){
            int reps=I_contact_side[i];
            int type=4;
	    int group=I_contact_group[i];
            add_inter_mesh(map_num_node,side_rep[reps],side_rep[reps+nb.side_s],S_apex.ptr(),nb,meshglob,type,group);
	    //add_inter_mesh(map_num_node,side_rep[reps],side_rep[reps+nb.side_s],S_apex.ptr(),nb,meshglob,type,reps);

        }
        for(unsigned i=0;i< nb.i_sym  ;i++){
            int reps=I_sym_side[i];
            int type=5;
	    int group=1000;
            add_inter_mesh(map_num_node,side_rep[reps],side_rep[reps+nb.side_s],S_apex.ptr(),nb,meshglob,type,group);
        }
        for(unsigned i=0;i< nb.i_imposed_gap  ;i++){
            int reps=I_imposed_gap_side[i];
            int type=6;
	    int group=I_imposed_gap_group[i];
	    //std::cout << group << endl;
            add_inter_mesh(map_num_node,side_rep[reps],side_rep[reps+nb.side_s],S_apex.ptr(),nb,meshglob,type,group);
            //add_inter_mesh(map_num_node,side_rep[reps],side_rep[reps+nb.side_s],S_apex.ptr(),nb,meshglob,type,reps);
        }
        for(unsigned i=0;i< nb.i_depl_normal  ;i++){
            int reps=I_depl_normal_side[i];
            int type=7;
	    int group=1000;
            add_inter_mesh(map_num_node,side_rep[reps],side_rep[reps+nb.side_s],S_apex.ptr(),nb,meshglob,type,group);
        }
    }
    string name=data_user.name_directory+"/calcul_"+data_user.id_calcul+"/geom_inter";
    dp.add_mesh(meshglob,name,Vec<string>("type","num"));
    //dp.exec();
}

template<class TE> void assign_type_group( TE *e, int type, int group) {
    (*e).type=type;
    (*e).num_group=group;
    //std::cout << (*e).type << endl;
}


template<class TM, class TMAP> 
void create_element_from_interface(TMAP &map_num_node, int * I_apex, int numI, NB &nb, TM &m, int type, int group){
    typedef typename TM::TNode TNode;

    Vec<int> rep_apex;
    rep_apex.resize(nb.apex_inter);
    //std::cout << "apex_sst " << nb.apex_sst << endl;
    for(unsigned i=0;i< nb.apex_inter  ;i++){
        rep_apex[i]=I_apex[numI+i*nb.inter_s];
    }
   // std::cout << rep_apex  << " " << nsst << " " << nside << endl;
    
    LMT::Vec<TNode *> vn; vn.resize(nb.apex_inter);
    for(unsigned i=0;i< nb.apex_inter ;i++){
//             int number=rep_apex[(nside+i)%nb.apex_sst];
//             //std::cout << number << endl;
            vn[i] = map_num_node[rep_apex[i]];
        }
#if DIM==2
        assign_type_group(m.add_element(Bar(),DefaultBehavior(),vn.ptr()),type, group);
#else 
        assign_type_group(m.add_element(Triangle(),DefaultBehavior(),vn.ptr()),type, group);
#endif 
} 



void LEVEL::display_interface_create(DATA_USER &data_user, string type="all"){
    DisplayParaview dp;
    //Mesh<Meshcaracinter<DIM,DIM-1> > meshglob;
    typedef Mesh<Meshcaracinter<DIM,DIM-1> > TM;
    TM meshglob;
    typedef TM::Pvec Pvec;
    typedef TM::TNode TNode;
    map<int,TNode *> map_num_node;
    int nbnodes=nodes.size()/DIM;
    for(unsigned i=0;i< nbnodes  ;i++){
        Vec<TYPE,DIM> vec;
        for(int di=0;di<DIM;di++)
            vec[di]=nodes[i*DIM+di];
        
        map_num_node[i] = meshglob.add_node(vec);
    }
    if(type=="all"){
        for(unsigned i=0;i< nb.inter  ;i++){
            int type=I_type[i];
            int group=I_num_group[i];
            if(type!=0){
            create_element_from_interface(map_num_node,I_apex.ptr(), i, nb, meshglob, type, group);
            }
        }
    }
    else if(type=="edge"){
        for(unsigned i=0;i< nb.inter  ;i++){
            int type=I_type[i];
            int group=I_num_group[i];
            if(type==1){
                create_element_from_interface(map_num_node,I_apex.ptr(), i, nb, meshglob, type, group);
            }
        }
    }
    else if(type=="group_inter"){
        for(unsigned i=0;i< nb.inter  ;i++){
            int type=I_type[i];
            int group=I_num_group[i];
            if(type==2){
                create_element_from_interface(map_num_node,I_apex.ptr(), i, nb, meshglob, type, group);
            }
        }
    }
    string name=data_user.name_directory+"/MESH/geometry_"+type;
    dp.add_mesh(meshglob,name,Vec<string>("type","num_group"));
    //dp.exec();
}

