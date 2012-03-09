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
#ifndef MESH_UTILS_H
#define MESH_UTILS_H

/** creation du maillage avec des Bar, des Triangles ou des Tetra en fonction du nombre d'element souhaites sur les cotes (nb_elem=decoupage a nb_elem sur les cotes)
Le stockage des noeuds est le suivant : 
n1_x, n1_y, n2_x, n2_y...
Le stockage des elements est donne par :
e1_n1, e1_n2, e2_n1, e2_n2...
 **/

inline void create_mesh_bar(TYPE *apex,int nb_elem, TYPE * nodes, int * elements){
    //nb_elem correspond au nombre d'elements souhaites sur les cotes et non pas au nombre d'elements souhaites
    for(int i=0;i<= nb_elem ;i++){
        nodes[2*i]=apex[0]+(apex[2]-apex[0])*i/nb_elem;
        nodes[2*i+1]=apex[1]+(apex[3]-apex[1])*i/nb_elem;
    }
    for(int i=0;i<nb_elem  ;i++){
        elements[2*i]=i;
        elements[2*i+1]=i+1;
    }
}

inline void create_mesh_tri_3D(TYPE *apex,int nb_elem, TYPE * nodes, int * elements){
    int num=0;
    for(int i=0;i<= nb_elem ;i++){
        for(int j=0;j<= nb_elem-i  ;j++){
            nodes[3*num]=apex[0]+(apex[3]-apex[0])*j/nb_elem+(apex[6]-apex[0])*i/nb_elem;
            nodes[3*num+1]=apex[1]+(apex[4]-apex[1])*j/nb_elem+(apex[7]-apex[1])*i/nb_elem;
            nodes[3*num+2]=apex[2]+(apex[5]-apex[2])*j/nb_elem+(apex[8]-apex[2])*i/nb_elem;
            num=num+1;
        }
    }
    int nb_nodes=0;
    num=0;
    for(int i=0;i<nb_elem  ;i++){
        int nb_nodes_lign=nb_elem+1-i;
        for(int j=0;j<nb_elem-i ;j++){
            elements[3*num]=j+nb_nodes;
            elements[3*num+1]=j+1+nb_nodes;
            elements[3*num+2]=nb_nodes_lign+j+nb_nodes;
            num=num+1;
        }
        for(int j=1;j<nb_elem-i ;j++){
            elements[3*num]=j+nb_nodes;
            elements[3*num+1]=j+nb_nodes+nb_nodes_lign;
            elements[3*num+2]=j-1+nb_nodes+nb_nodes_lign;
            num=num+1;
        }
        nb_nodes+=nb_nodes_lign;
    }
}



// inline void create_mesh_tri_2D(TYPE *apex,int nb_elem, TYPE * nodes, int * elements){
// 
//     int num=0;
//     for(int i=0;i<= nb_elem ;i++){
//         for(int j=0;j<= nb_elem-i  ;j++){
//             nodes[2*num]=apex[0]+(apex[2]-apex[0])*j/nb_elem+(apex[4]-apex[0])*i/nb_elem;
//             nodes[2*num+1]=apex[1]+(apex[3]-apex[1])*j/nb_elem+(apex[5]-apex[1])*i/nb_elem;
//             num=num+1;
//         }
//     }
//     int nb_nodes=0;
//     num=0;
//     for(int i=0;i<nb_elem  ;i++){
//         int nb_nodes_lign=nb_elem+1-i;
//         for(int j=0;j<nb_elem-i ;j++){
//             elements[3*num]=j+nb_nodes;
//             elements[3*num+1]=j+1+nb_nodes;
//             elements[3*num+2]=nb_nodes_lign+j+nb_nodes;
//             num=num+1;
//         }
//         for(int j=1;j<nb_elem-i ;j++){
//             elements[3*num]=j+nb_nodes;
//             elements[3*num+1]=j+nb_nodes+nb_nodes_lign;
//             elements[3*num+2]=j-1+nb_nodes+nb_nodes_lign;
//             num=num+1;
//         }
//         nb_nodes+=nb_nodes_lign;
//     }
// }
// 
// 
// inline void create_mesh_tet(TYPE *apex,int nb_elem, TYPE * nodes, int * elements){
//   //creation explicite
//     
//     if(nb_elem==2){
//         //ajout des noeuds coincidant avec les sommets
//         for(unsigned i=0;i<  4*3 ;i++)
//             nodes[i]=apex[i];
//         //ajout des noeuds milieu
//         int rep=12;
//         for(unsigned j=0;j< 3 ;j++){
//             nodes[rep+j]=(apex[0+j]+apex[3+j])/2;
//             nodes[rep+j+3]=(apex[3+j]+apex[6+j])/2;
//             nodes[rep+j+6]=(apex[6+j]+apex[0+j])/2;
//             nodes[rep+j+9]=(apex[3+j]+apex[9+j])/2;
//             nodes[rep+j+12]=(apex[6+j]+apex[9+j])/2;
//             nodes[rep+j+15]=(apex[0+j]+apex[9+j])/2;
//         }
//         
//         int elements_explicite[]={0,4,6,9,1,5,4,7,2,6,5,8,3,8,7,9,4,5,9,7,5,9,7,8,5,6,9,8,5,9,6,4};
//         for(unsigned i=0;i< 32  ;i++){
//             elements[i]=elements_explicite[i];
//         }
//     }
//     else{
//         std::cout << "Nombre maximal de decoupage d'arete d'un tetra égal à 2" << endl;
//     }
// }

inline void create_mesh_tri_2D(int *S_apex, TYPE *data_user_node,int nb_elem, TYPE * nodes, int * elements,int nsst_s,int ns){
    int num=0;

// Creation de NODES : version d'origine sans apex.    
    for(int i=0;i<= nb_elem ;i++){
        for(int j=0;j<= nb_elem-i  ;j++){
            nodes[(2*num)]=data_user_node[S_apex[ns]*DIM]+(data_user_node[S_apex[nsst_s+ns]*DIM]-data_user_node[S_apex[ns]*DIM])*j/nb_elem+(data_user_node[S_apex[2*nsst_s+ns]*DIM]-data_user_node[S_apex[ns]*DIM])*i/nb_elem;
            nodes[(2*num+1)]=data_user_node[1+S_apex[ns]*DIM]+(data_user_node[1+S_apex[nsst_s+ns]*DIM]-data_user_node[1+S_apex[ns]*DIM])*j/nb_elem+(data_user_node[1+S_apex[2*nsst_s+ns]*DIM]-data_user_node[1+S_apex[ns]*DIM])*i/nb_elem;
            num=num+1;
        }
    }

    //creation des elements (les memes pour toutes les SST)
        int nb_nodes=0;
        num=0;
        for(int i=0;i<nb_elem  ;i++){
            int nb_nodes_lign=nb_elem+1-i;
            for(int j=0;j<nb_elem-i ;j++){
                elements[3*num  ]=j+nb_nodes;
                elements[3*num+1]=j+1+nb_nodes;
                elements[3*num+2]=nb_nodes_lign+j+nb_nodes;
                num=num+1;
            }
            for(int j=1;j<nb_elem-i ;j++){
                elements[3*num  ]=j+nb_nodes;
                elements[3*num+1]=j+nb_nodes+nb_nodes_lign;
                elements[3*num+2]=j-1+nb_nodes+nb_nodes_lign;
                num=num+1;
            }
            nb_nodes+=nb_nodes_lign;
        }

}

inline void create_mesh_tet(int *S_apex, TYPE *data_user_node,int nb_elem, TYPE * nodes, int * elements,int nsst_s,int napex_sst,int ns){
  //creation explicite

    if(nb_elem==2){
        //ajout des noeuds coincidant avec les sommets
/*        for(unsigned i=0;i<  4*3 ;i++)
        nodes[i*nb_thread+threadIdx.x]=apex[i];*/
        for(unsigned i=0;i<napex_sst  ;i++){
            for(unsigned j=0;j< DIM ;j++)
                nodes[(i*DIM+j)]=data_user_node[j+S_apex[i*nsst_s+ns]*DIM];
        }
        //ajout des noeuds milieu
        int rep=12;
        for(unsigned j=0;j< 3 ;j++){
            nodes[(rep+j)]=(nodes[(0+j)]+nodes[(3+j)])/2;
            nodes[(rep+j+3)]=(nodes[(3+j)]+nodes[(6+j)])/2;
            nodes[(rep+j+6)]=(nodes[(6+j)]+nodes[(0+j)])/2;
            nodes[(rep+j+9)]=(nodes[(3+j)]+nodes[(9+j)])/2;
            nodes[(rep+j+12)]=(nodes[(6+j)]+nodes[(9+j)])/2;
            nodes[(rep+j+15)]=(nodes[(0+j)]+nodes[(9+j)])/2;
        }
        
        int elements_explicite[]={0,4,6,9,1,5,4,7,2,6,5,8,3,8,7,9,4,5,9,7,5,9,7,8,5,6,9,8,5,9,6,4};
        for(unsigned i=0;i< 32  ;i++){
            elements[i]=elements_explicite[i];
        }
    }
    else{
        std::cout << "Nombre maximal de decoupage d'arete d'un tetra egal a 2" << std::endl; assert(0);
    }
}


#endif //MESH_UTILS_H
