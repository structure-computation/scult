//
// C++ Interface: Tenseur_n
//
// Description: 
//permet de construir des tenseurs d'ordre n
//
// Author: Alain CAIGNOT <caignot@lmt.ens-cachan.fr>, (C) 2007
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef TENSEUR_N_h
#define TENSEUR_N_h

#include "containers/mat.h"
#include "fonc_utiles_tenseur_n.h"
using namespace LMT;
using namespace std;


namespace LMT {

// creation de la classe tenseur
template<class T,unsigned n>
struct MonTenseur {
    Vec<T> data;
    Vec<Vec<unsigned> > data_index;
    Vec<T,n> density;
    Vec<unsigned,n> sizes;
    Vec<unsigned,n> cum_sizes;
    
    // fonctions qui permette de redimensionner et d'initialiser les valeur du tenseur d'ordre n
    void resize( Vec<unsigned,n> &s ) {
        unsigned c=1;
        for(unsigned i=0;i<n;++i) {
            cum_sizes[i] = c;
            c *= s[i];
        }
        sizes = s;
        data.resize(c);
    }
    void resize( Vec<unsigned,n> &s, T num ) {
        unsigned c=1;
        for(unsigned i=0;i<n;++i) {
            cum_sizes[i] = c;
            c *= s[i];
        }
        sizes = s;
        data.resize(c,num);
    }
    void resize( unsigned s ) {
        unsigned c=1;
        for(unsigned i=0;i<n;++i) {
            cum_sizes[i] = c;
            c *= s;
            sizes[i] = s;
        }
        data.resize(c);
    }
    void resize( unsigned s, T num ) {
        unsigned c=1;
        for(unsigned i=0;i<n;++i) {
            cum_sizes[i] = c;
            c *= s;
            sizes[i] = s;
        }
        data.resize(c,num);
    }
    
    // fonction qui permet d'afficher sous forme de matrice les valeurs selon les dimensions
    // dim1 et dim2 pour des valeurs fixees des autres parametre dans index. 
    Mat<T> matrice(unsigned dim1,unsigned dim2, Vec<unsigned,n> &index){
        Mat<T> resultat;
        resultat.resize(sizes[dim1],sizes[dim2]);
        for(unsigned i=0;i<sizes[dim1];i++){
            for(unsigned j=0;j<sizes[dim2];j++){
                index[dim1] = i;
                index[dim2] = j;
                resultat(i,j) = data[ sum (index * cum_sizes) ];
            }
        }
        return resultat;
    }
    
    // fonction qui permet d'afficher sous forme de vecteur les valeurs selon la dimensions
    // dim1 pour des valeurs fixees des autres parametre dans index. 
    Vec<T> vector(unsigned dim1, Vec<unsigned,n> &index){
        Vec<T> resultat;
        resultat.resize(sizes[dim1]);
        for(unsigned i=0;i<sizes[dim1];i++){
                index[dim1] = i;
                resultat[i] = data[ sum (index * cum_sizes) ];
        }
        return resultat;
    }
    
    // fonction qui permet de remplir le tenseur d'ordre n a partir du produit tensoriel de n vecteur
    void remplir(Vec<Vec<T>,n> &input){
        Vec<T> data_0;
        data_0.resize(1,1);
        for(unsigned i=0;i<n;i++){
            Vec<T> data_temp = prod_tensoriel<T>(data_0,input[i]);
            data_0.resize(data_temp.size());
            data_0 = data_temp;
        }
        data = data_0;
    }
    
    // fonction qui permet de creer l'index asocie a chaque membre de data : data_index
    void create_index(){
        data_index.resize(data.size());
        Vec<Vec<unsigned>,n> val_ind;
        for(unsigned i=0;i<n;i++){
            val_ind[i].resize(sizes[i],0);
            for(unsigned j=0;j<sizes[i];j++){
                val_ind[i][j] = j;
            }
        }
        Vec<Vec<unsigned> > index_data_0;
        index_data_0.resize(sizes[0]);
        for(unsigned j=0;j<sizes[0];j++){
            index_data_0[j].resize(1,val_ind[0][j]);
        }
        for(unsigned i=1;i<n;i++){
            Vec<Vec<unsigned> > index_data_temp = distrib_tensoriel<unsigned>(index_data_0,val_ind[i]);
            index_data_0.resize(index_data_temp.size());
            index_data_0 = index_data_temp;
        }
        data_index = index_data_0;
    }
    Mat<Vec<unsigned> > matrice_index(unsigned dim1,unsigned dim2, Vec<unsigned,n> &index){
        Mat<Vec<unsigned> > resultat;
        resultat.resize(sizes[dim1],sizes[dim2]);
        for(unsigned i=0;i<sizes[dim1];i++){
            for(unsigned j=0;j<sizes[dim2];j++){
                index[dim1] = i;
                index[dim2] = j;
                resultat(i,j) = data_index[ sum( index * cum_sizes ) ];
            }
        }
        return resultat;
    }
    
    void free(){
        data.free();
        data_index.free();
    }
    
    const T &operator()( const Vec<unsigned,n> &index ) const { return data[ sum( index * cum_sizes ) ]; }
    T &operator()( const Vec<unsigned,n> &index ) { return data[ sum( index * cum_sizes ) ]; }
};


//-----------------------------------------------------------------------------------------
//   fonction relative ou util pour la classe tenseur
//-----------------------------------------------------------------------------------------


template<class T,unsigned n>  MonTenseur<T,n> somme_tenseur(MonTenseur<T,n> &T1,MonTenseur<T,n> &T2){
    unsigned s1 = T1.data.size();
    unsigned s2 = T2.data.size();
    if(s1 != s2){
        std::cout << "on ne peut pas faire la somme de 2 tenseur de taille differente! " << endl;
        assert(0);
    }
    MonTenseur<T,n> result;
    result.resize(T1.sizes,0);
    for(unsigned i=0;i<result.data.size();i++){
        result.data[i]=T1.data[i]+T2.data[i];
    }
    return result;
};

template<class T,unsigned n>  MonTenseur<T,n> soustraction_tenseur(MonTenseur<T,n> &T1,MonTenseur<T,n> &T2){
    unsigned s1 = T1.data.size();
    unsigned s2 = T2.data.size();
    if(s1 != s2){
        std::cout << "on ne peut pas faire la somme de 2 tenseur de taille differente! " << endl;
        assert(0);
    }
    MonTenseur<T,n> result;
    result.resize(T1.sizes,0);
    for(unsigned i=0;i<result.data.size();i++){
        result.data[i]=T1.data[i]-T2.data[i];
    }
    return result;
};

template<class T,unsigned n>  MonTenseur<T,n> produit_tenseur(MonTenseur<T,n> &T1,MonTenseur<T,n> &T2){
    unsigned s1 = T1.data.size();
    unsigned s2 = T2.data.size();
    if(s1 != s2){
        std::cout << "on ne peut pas faire le produit de 2 tenseur de taille differente! " << endl;
        assert(0);
    }
    MonTenseur<T,n> result;
    result.resize(T1.sizes,0);
    for(unsigned i=0;i<result.data.size();i++){
        result.data[i]=T1.data[i]*T2.data[i];
    }
    return result;
};

template<class T,unsigned n>  T poids_tenseur(MonTenseur<T,n> &T1){
    T result;
    result= 0;
    for(unsigned i=0;i<T1.data.size();i++){
        result += T1.data[i];
    }
    return result;
};

template<class T,unsigned n>  MonTenseur<T,n> abs_tenseur(MonTenseur<T,n> &T1){
    MonTenseur<T,n> result;
    result.resize(T1.sizes,0);
    for(unsigned i=0;i<T1.data.size();i++){
        result.data[i] = abs(T1.data[i]);
    }
    return result;
};

}

#endif // TENSEUR_N_h
