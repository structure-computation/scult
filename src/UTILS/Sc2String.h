#ifndef SCSTRING_H
#define SCSTRING_H

#include <string>
#include <sstream>
#include <Metil/String.h>


/// Sc2String
/// Cette classe herite de std::string et ses masquages/surcharges d'operateurs
/// assure sa compatibilite de comportement avec la classe Metil::String.
/// Les Sc2String peuvent donc remplacer ces deux classes et supportent leurs principaux
/// formalismes d'ecriture.
class Sc2String: public std::string{
public:
    ///Constructeurs associes a std::string
    Sc2String ( ) : std::string(){}
    Sc2String ( const std::string& str ) : std::string(str){}
    Sc2String ( const std::string& str, size_t pos, size_t n = npos ) : std::string(str,pos,n){}
    Sc2String ( const char * s, size_t n ) : std::string(s,n){}
    Sc2String ( const char * s ) : std::string(s){}
    Sc2String ( size_t n, char c ) : std::string(n,c){}
    template<class InputIterator> Sc2String (InputIterator begin, InputIterator end) : std::string(begin,end){}
    /// Constructeur associe a Metil::String
    Sc2String ( const Metil::String &s ) : std::string(){assign(s.c_str());}
    
    /// Operateur =
    Sc2String &operator=(const Metil::String &s){assign(s.c_str()); return (*this);}
    Sc2String &operator=(const std::string &s){assign(s); return (*this);}
    Sc2String &operator=(const char *s){assign(s); return (*this);}
    
    /// Operateur +=
    Sc2String& operator+= ( const Metil::String& str ) {append(str.c_str());return (*this);}
    Sc2String& operator+= ( const std::string& str ) {append(str);return (*this);}
    Sc2String& operator+= ( const char* s ) {append(s);return (*this);}
    
    /// Operateur + (binaire) (reproduit le comportement de std::string)
    template<class T> Sc2String operator+ ( const T& str ) 
    {
        Sc2String sum = (*this);
        sum << str ;
        return sum;
    }
    
    /// Operateur << (reproduit le comportement de Metil::String)
    template<class T> Sc2String &operator<<(const T &s){
        convert(s); 
        return *this;
    }
    
    /// Assure la compatibilite avec les fonctions de la librairie Metil
    void write_str(Metil::String &s) const {s<<c_str();}
    
    
private:
    /// fonction de conversion generique
    template<class T> void convert(const T &s){
        std::ostringstream tmp;
        tmp << s;
        append(tmp.str());
    }
    
    /// fonction de conversion specialisee pour les Metil::String
    void convert(const Metil::String &s){
        append(s.c_str());
    }
};

#endif //SCSTRING_H
