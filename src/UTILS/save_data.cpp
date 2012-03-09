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

#include "LEVEL.h"


void LEVEL::save_results(DATA_USER &data_user){
    
    std::ostringstream ss1;
    ss1<<data_user.calcul_directory<<"/calcul_"<<data_user.id_calcul<<"/resultat.sc";
    string name(ss1.str());
    std::cout << name << endl;
    ofstream os( name.c_str() );
    
    //Sauvegarde de la dimension du vecteur resultat puis du vecteur lui meme en binaire
    Vec<int,1> dimension(S_q.size());
    os.write( (char *)dimension.ptr(), sizeof(int) );
    os.write( (char *)S_q.ptr(), sizeof(TYPE)*S_q.size() );
    os.close();
    
}

void read_results(string name2, Vec<TYPE> &data){
    ifstream is;
    is.open( name2.c_str() );
    
    //lecture de la dimension puis du vecteur de deplacement en chaque noeud (S_q)
    Vec<int,1> dim_data;
    is.read( (char *)dim_data.ptr(), sizeof(int) );
    data.resize(dim_data[0]);
    is.read( (char *)data.ptr(), sizeof(TYPE)*data.size() );
    //std::cout << data << endl;
}

void LEVEL::save_geom_data_user(DATA_USER &data_user){
    
    std::ostringstream ss1;
    ss1<<data_user.mesh_directory<<"/mesh.sc";
    string name(ss1.str());
    ofstream os( name.c_str() );
    
    //Sauvegarde du nombre de sst, du nombre de noeuds par sst, du nombre d'elements par sst, du nombre de noeuds par elements de sst, du nombre de noeuds et de la taille d'apex + d'autres champs utiles lors de la reconstruction du maillage
    Vec<int,9> data_size(nb.sst,nb.nodes_sst,nb.elements_sst,nb.nodes_element_sst,nodes.size(),S_apex.size(),nb.decoup,nb.apex_sst,nb.sst_s);
    os.write( (char *)data_size.ptr(), sizeof(int)*9 );
    //Sauvegarde des noeuds puis des elements
    os.write( (char *)nodes.ptr(), sizeof(TYPE)*nodes.size() );
    os.write( (char *)S_apex.ptr(), sizeof(int)*S_apex.size() );
    os.close();
    
}

void read_geom_data_user(string name2, Vec<TYPE> &_nodes, Vec<int> &_S_apex, Vec<int,9> &data_size){
    ifstream is;
    is.open( name2.c_str() );
    
    //lecture de la dimension puis du vecteur de deplacement en chaque noeud (S_q)
    is.read( (char *)data_size.ptr(), sizeof(int)*9);
       
    _nodes.resize(data_size[4]);
    _S_apex.resize(data_size[5]);
    is.read( (char *)_nodes.ptr(), sizeof(TYPE)*_nodes.size() );
    is.read( (char *)_S_apex.ptr(), sizeof(TYPE)*_S_apex.size() );


    
    
}
