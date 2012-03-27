#ifndef SCSTRING_H
#define SCSTRING_H

#include <string>
#include <sstream>
#include <Metil/String.h>


/** Sc2String
 * Cette classe herite de std::string et ses masquages/surcharges d'operateurs
 * assure sa compatibilite de comportement avec la classe Metil::String.
 * Les Sc2String peuvent donc remplacer ces deux classes et supportent leurs principaux
 * formalismes d'ecriture.
 */
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
    template<class T> Sc2String& operator= (const Sc2String &s){
        assign(convert(s));
        return (*this);
    }
    
    /// Operateur +=
    template<class T> Sc2String& operator+= (const T &s){
        append(convert(s)); 
        return (*this);
    }
    
    /// Operateur + (binaire) (reproduit le comportement de std::string)
    template<class T> Sc2String operator+ ( const T& str ) 
    {
        Sc2String sum = (*this);
        return sum << str ;
    }
    
    /// Operateur << (reproduit le comportement de Metil::String)
    template<class T> Sc2String& operator<< (const T &s){
        append(convert(s)); 
        return *this;
    }
    
    /// Assure la compatibilite avec les fonctions de la librairie Metil
    void write_str(Metil::String &s) const {s<<c_str();}
    
    
private:
    /// fonction de conversion generique
    template<class T> std::string convert(const T &s){
        std::ostringstream tmp;
        tmp << s;
        return tmp.str();
    }
    
    /// fonction de conversion specialisee pour les Sc2String
    const char* convert(const Sc2String &s){
        return s.c_str();
    }
    /// fonction de conversion specialisee pour les Metil::String
    const char* convert(const Metil::String &s){
        return s.c_str();
    }
};

#endif //SCSTRING_H
