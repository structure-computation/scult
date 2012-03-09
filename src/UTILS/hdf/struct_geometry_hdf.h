#ifndef STRUCT_HDF
#define STRUCT_HDF

#include <Metil/Hdf.h>

using namespace Metil;

struct Nodes_Hdf{
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

struct Element_Bar_Hdf{
    template<class Hdf> void write_to( Hdf &hdf, const String &name ) {
        c0.write_to( hdf, name + "/c0" );
        c1.write_to( hdf, name + "/c1" );
    }
    template<class Hdf> void read_from( Hdf &hdf, const String &name ) {
        c0.read_from( hdf, name + "/c0" );
        c1.read_from( hdf, name + "/c1" );
    }
    BasicVec<int> c0, c1; //connectivites
};

struct Element_Triangle_Hdf{
    template<class Hdf> void write_to( Hdf &hdf, const String &name ) {
        c0.write_to( hdf, name + "/c0" );
        c1.write_to( hdf, name + "/c1" );
        c2.write_to( hdf, name + "/c2" );
    }
    template<class Hdf> void read_from( Hdf &hdf, const String &name ) {
        c0.read_from( hdf, name + "/c0" );
        c1.read_from( hdf, name + "/c1" );
        c2.read_from( hdf, name + "/c2" );
    }
    BasicVec<int> c0, c1, c2; //connectivites
};

struct Element_Tetra_Hdf{
    template<class Hdf> void write_to( Hdf &hdf, const String &name ) {
        c0.write_to( hdf, name + "/c0" );
        c1.write_to( hdf, name + "/c1" );
        c2.write_to( hdf, name + "/c2" );
        c3.write_to( hdf, name + "/c3" );
    }
    template<class Hdf> void read_from( Hdf &hdf, const String &name ) {
        c0.read_from( hdf, name + "/c0" );
        c1.read_from( hdf, name + "/c1" );
        c2.read_from( hdf, name + "/c2" );
        c3.read_from( hdf, name + "/c3" );
    }
    BasicVec<int> c0, c1, c2, c3; //connectivites
};

struct Elements_1_Hdf{
    template<class Hdf> void write_to( Hdf &hdf, const String &name , int &nb_list) {
        
        //ecriture des bars
        for(unsigned i=0;i<list_bar.size();i++){
            String name_group ;
            name_group << name << "/list_" << i+nb_list;
            list_bar[i].write_to(hdf, name_group); 
            hdf.add_tag(name_group,"base","bar");
            hdf.add_tag(name_group,"nb_connectivities",list_bar[i].c0.size());
        }
        nb_list+=list_bar.size();
        //ecriture des triangles
        for(unsigned i=0;i<list_triangle.size();i++){
            String name_group ;
            name_group << name << "/list_" << i+nb_list;
            list_triangle[i].write_to(hdf, name_group );
            //ajout du tag correspondant
            hdf.add_tag(name_group,"base","triangle");
            hdf.add_tag(name_group,"nb_connectivities",list_triangle[i].c0.size());
        }
        nb_list+=list_triangle.size();  
    }
    
    template<class Hdf> void read_from( Hdf &hdf, const String &name ) {
        for(unsigned i=0;i<list_bar.size();i++){
            String name_group ;
            name_group << name << "/list_" << i;
            list_bar[i].read_from(hdf, name + "/list_"+i );  
        }
        for(unsigned i=0;i<list_triangle.size();i++){
            String name_group ;
            name_group << name << "/list_" << i;
            list_triangle[i].read_from(hdf, name + "/list_"+i );  
        }
     }
    BasicVec<Element_Triangle_Hdf> list_triangle; //liste d'elements triangulaires
    BasicVec<Element_Bar_Hdf> list_bar; //liste d'elements bar
    
};

struct Elements_Hdf{
    template<class Hdf> void write_to( Hdf &hdf, const String &name , int &nb_list) {
        
        //ecriture des bars
        for(unsigned i=0;i<list_bar.size();i++){
            String name_group ;
            name_group << name << "/list_" << i+nb_list;
            list_bar[i].write_to(hdf, name_group); 
            hdf.add_tag(name_group,"base","bar");
            hdf.add_tag(name_group,"nb_connectivities",list_bar[i].c0.size());
        }
        nb_list+=list_bar.size();
        for(unsigned i=0;i<list_triangle.size();i++){
            String name_group ;
            name_group << name << "/list_" << i+nb_list;
            list_triangle[i].write_to(hdf, name_group );
            //ajout du tag correspondant
/*            hdf.add_tag(name_group,"piece",i);*/
            hdf.add_tag(name_group,"base","triangle"); 
            hdf.add_tag(name_group,"nb_connectivities",list_triangle[i].c0.size());
        }
        nb_list+=list_triangle.size();        
        for(unsigned i=0;i<list_tetra.size();i++){
            String name_group ;
            name_group << name << "/list_" << i+nb_list;
            list_tetra[i].write_to(hdf, name_group);  
            //ajout du tag correspondant
/*            hdf.add_tag(name_group,"piece",i+nb_list);*/
            hdf.add_tag(name_group,"base","tetra");
            hdf.add_tag(name_group,"nb_connectivities",list_tetra[i].c0.size());
        }
        nb_list+=list_tetra.size(); 

        
    }
    template<class Hdf> void read_from( Hdf &hdf, const String &name ) {

        for(unsigned i=0;i<list_triangle.size();i++){
            String name_group ;
            name_group << name << "/list_" << i;
            list_triangle[i].read_from(hdf, name + "/list_"+i );  
        }
        for(unsigned i=0;i<list_tetra.size();i++){ 
            String name_group ;
            name_group << name << "/list_" << i;
            list_tetra[i].read_from(hdf, name + "/list_"+i );  
        }
    }
    BasicVec<Element_Bar_Hdf> list_bar; //liste d'elements bar
    BasicVec<Element_Tetra_Hdf> list_tetra; //liste d'elements triangulaires
    BasicVec<Element_Triangle_Hdf> list_triangle; //liste d'elements triangulaires
    BasicVec<String> name_in_hdf5; //nom de la liste dans le fichier hdf5
    BasicVec<String> behaviour; //nom du comportement associé à chaque liste
    BasicVec<int> num_behaviour; //nom du comportement associé à chaque liste
};

struct Sides_Hdf{
    template<class Hdf> void write_to( Hdf &hdf, const String &name ) {
        i0.write_to( hdf, name + "/i0" );
        i1.write_to( hdf, name + "/i1" );
        i2.write_to( hdf, name + "/i2" );
#if DIM==3       
        i3.write_to( hdf, name + "/i3" );
#endif
    }
    template<class Hdf> void read_from( Hdf &hdf, const String &name ) {
        i0.read_from( hdf, name + "/i0" );
        i1.read_from( hdf, name + "/i1" );
        i2.read_from( hdf, name + "/i2" );
#if DIM==3       
        i3.read_from( hdf, name + "/i3" );
#endif
    }
    BasicVec<int> i0, i1, i2, i3; //connectivites
};


struct Elements_children_Hdf{
    template<class Hdf> void write_to( Hdf &hdf, const String &name ) {
        c0.write_to( hdf, name + "/c0" );
        c1.write_to( hdf, name + "/c1" );
#if DIM==3       
        c2.write_to( hdf, name + "/c2" );
#endif        
    }
    template<class Hdf> void read_from( Hdf &hdf, const String &name ) {
        c0.read_from( hdf, name + "/c0" );
        c1.read_from( hdf, name + "/c1" );
#if DIM==3       
        c2.read_from( hdf, name + "/c2" );
#endif        
    }    
    BasicVec<int> c0, c1, c2; //connectivites
};

class Geometry_Hdf{
    public:

    Nodes_Hdf nodes;
/*    BasicVec<Elements_Hdf,2> elements;*/
    Elements_Hdf elements_0; //connectivites des elements parents
    int nb_list_elements_0; //nombre de listes d'elements (pieces)
    Elements_Hdf elements_1_edge; //connectivites des elements enfants sur les bords des pieces
    Elements_Hdf elements_1_interior; //connectivites des elements enfants a l'interieur des pieces
    Elements_Hdf elements_1_link; //connectivites des elements enfants des liaisons (entre deux pieces)
    int nb_list_elements_1_edge; //nombre de listes d'elements sur les bords des pieces
    int nb_list_elements_1_interior; //nombre de listes d'elements a l'interieur des pieces
    int nb_list_elements_1_link; //nombre de listes d'elements des liaisons (entre deux pieces)
    
    void write_to( Hdf &hdf, const String &name );
    void read_from( Hdf &hdf, const String &name );
};


#endif
