/* Ce petit programme vient lire un fichier json
 * et creer une structure dont les attributs calquent l'organisation du fichier
 * ainsi qu'une methode de lecture du json.
 * Cette structure s'appelle ScJsonReader, et la methode
 *     void read_json(const Sc2String& file_path)
 * avec 'file_path' le chemin d'acces au fichier.
 * 
 * Des fonctions de nommenclatures et typage sont definies plus bas.
 * 
 * Pour les listes de 1er niveau (links, pieces, ...), des fonctions de recherche par index
 * peuvent etre definies (voir add_search_function).
 */

#include <fstream>
#include <iostream>
#include <cstdlib>

#include "../UTILS/json_spirit/json_spirit.h"
using namespace json_spirit;

#include "../UTILS/Sc2String.h"
#include <Metil/BasicVec.h>
using namespace Metil;


struct ReaderBuilder{
    Sc2String h_begin;
    Sc2String h_struct;
    Sc2String h_read;
    Sc2String h_find;
    Sc2String h_end;
    int struct_level;       /// Niveau d'indentation courant dans h_struct
    Sc2String cpp_begin;
    Sc2String cpp_read;
    Sc2String cpp_find;
    Sc2String cpp_end;
    int read_level;         /// Niveau d'indentation courant dans cpp_read
    
    ReaderBuilder(){}
    
    /** ------------------------------------------------------------------------------------------------------ *
     *                                      CONVENTIONS DE NOMMAGE                                             *
     *  ------------------------------------------------------------------------------------------------------ */
    Sc2String name_class(){return "ScJsonReader";}
    
    Sc2String type_array(const Sc2String& name_in_json){return Sc2String("BasicVec<") + type_object(name_in_json) + Sc2String(">");}
    Sc2String type_object(const Sc2String& name_in_json){return Sc2String("Json_") + name_in_json;}
    Sc2String type_string(const Sc2String& value_in_json){
        if(value_in_json == "integer"){
            return "int";
        }else if(value_in_json == "real"){
            return "TYPEREEL";
        }else if(value_in_json == "string"){
            return "Sc2String";
        }else if(value_in_json == ""){
            return "null";
        }else if(value_in_json == "null"){
            return "null";
        }else{
            return value_in_json;
        }
    }
    Sc2String type_JSON(const Sc2String& value_in_json){
        if(value_in_json == "bool" or value_in_json == "boolean")
            return "bool_type";
        else if(value_in_json == "int" or value_in_json == "integer")
            return "int_type";
        else if(value_in_json == "unsigned" or value_in_json == "unsigned int" or value_in_json == "uint")
            assert(0);  //Les entiers non-signes ne sont pas pris en charge
        else if(value_in_json == "long" or value_in_json == "long int" or value_in_json == "int64")
            return "int64_type";
        else if(value_in_json == "unsigned long" or value_in_json == "unsigned long int" or value_in_json == "uint64")
            assert(0);  //Les entiers non-signes ne sont pas pris en charge
        else if(value_in_json == "float" or value_in_json == "double" or value_in_json == "TYPEREEL" or value_in_json == "real")
            return "real_type";
        else if(value_in_json == "string" or value_in_json == "Sc2String" or value_in_json == "str")
            return "str_type";
        else
            assert(0);  //Mauvais type de variable
        return "";
    }
    Sc2String type_get_value(const Sc2String& value_in_json){
        if(value_in_json == "bool" or value_in_json == "boolean")
            return "get_bool";
        else if(value_in_json == "int" or value_in_json == "integer")
            return "get_int";
        else if(value_in_json == "unsigned" or value_in_json == "unsigned int" or value_in_json == "uint")
            return "get_uint";
        else if(value_in_json == "long" or value_in_json == "long int" or value_in_json == "int64")
            return "get_int64";
        else if(value_in_json == "unsigned long" or value_in_json == "unsigned long int" or value_in_json == "uint64")
            return "get_uint64";
        else if(value_in_json == "float" or value_in_json == "double" or value_in_json == "TYPEREEL" or value_in_json == "real")
            return "get_real";
        else if(value_in_json == "string" or value_in_json == "Sc2String" or value_in_json == "str")
            return "get_str";
        else
            assert(0);  //Mauvais type de variable
            return "";
    }
    Sc2String name_array(const Sc2String& name_in_json){return name_in_json + Sc2String("_vec");}
    Sc2String name_object(const Sc2String& name_in_json){return name_in_json;}
    Sc2String name_string(const Sc2String& name_in_json){return name_in_json;}
    
    Sc2String name_id_parameter(){return "id_in_calcul";}
    Sc2String name_search_pointer(const Sc2String &name_in_json){return Sc2String("find_") + name_object(name_in_json) + Sc2String("_pointer");}
    Sc2String name_search_index(const Sc2String &name_in_json){return Sc2String("find_") + name_object(name_in_json) + Sc2String("_index");}
    
    
    /** ------------------------------------------------------------------------------------------------------ *
     *                                      FONCTIONS DE GENERATION                                            *
     *  ------------------------------------------------------------------------------------------------------ */
    void initialize(){
        /// Entete du fichier h
        h_begin << "#ifndef SCJSONREADER_H\n";
        h_begin << "#define SCJSONREADER_H\n";
        h_begin << "\n";
        h_begin << "#include \"../UTILS/Sc2String.h\"\n";
        h_begin << "\n";
        h_begin << "#include <Metil/BasicVec.h>\n";
        h_begin << "using namespace Metil;\n";
        h_begin << "\n";
        h_begin << "\n";
        h_begin << "class " << name_class() << "{\n";
        h_begin << "public:\n";
        struct_level = 0;
        /// Entete du fichier cpp
        cpp_begin << "#include \"" << name_class() << ".h\"\n";
        cpp_begin << "#include \"../UTILS/json_spirit/json_spirit.h\"\n";
        cpp_begin << "#include <fstream>\n";
        cpp_begin << "#include <sstream>\n";
        cpp_begin << "using namespace json_spirit;\n";
        cpp_begin << "using namespace Metil;\n";
        cpp_begin << "\n";
        cpp_begin << "#define DEBUG_SCJSONREADER false\n";
        cpp_begin << "\n";
        cpp_begin << "\n";
        /// Preparation de la fonction de lecture
        cpp_read << "void " << name_class() << "::read_json(const Sc2String& file_path){\n";
        cpp_read << "    if(DEBUG_SCJSONREADER) std::cout << \"Ouverture de \" << file_path << std::endl;\n"; 
        cpp_read << "    std::ifstream is(file_path.c_str());\n";
        cpp_read << "    if(!is.is_open()){\n";
        cpp_read << "        std::cerr << \"IMPOSSIBLE D'OUVRIR LE FICHIER :\" << file_path << std::endl;\n";
        cpp_read << "        assert(0);\n";
        cpp_read << "    }\n";
        cpp_read << "    std::istringstream input; /// Pour assurer la conversion vers les entiers et les reels\n";
        cpp_read << "    Value value;\n";
        cpp_read << "    read(is,value);\n";
        cpp_read << "    const Object& object = value.get_obj();\n";
        cpp_read << "    for(Object::size_type i = 0;i < object.size(); ++i){\n";
        cpp_read << "        const Sc2String& name0 = object[i].name_;\n";
        cpp_read << "        const Value& value0 = object[i].value_;\n";
        cpp_read << "        if(DEBUG_SCJSONREADER) std::cout << \"Reading \" << name0 << \" :\" << std::endl;\n";
        cpp_read << "        ";
        read_level = 2;
        /// Inclusion d'une fonction de tri (Heapsort) par id                A REVOIR
        /*
        h_find << "    template<typename Type>\n";
        h_find << "    void sort_by_id(BasicVec<Type> &array){\n";
        h_find << "        const int longueur = array.size();\n";
        h_find << "        for(unsigned i=longueur/2; i > -1; i--){\n";
        h_find << "            int k = i;\n";
        h_find << "            int j = 2*k;\n";
        h_find << "            while(j<longueur){\n";
        h_find << "                if(j<longueur and array[j]." << name_id_parameter() << " < array[j+1]." << name_id_parameter() << ")\n";
        h_find << "                    j++;\n";
        h_find << "                if(array[k]." << name_id_parameter() << "<array[j]." << name_id_parameter() << "){\n";
        h_find << "                    Type tmp = array[k];\n";
        h_find << "                    array[k] = array[j];\n";
        h_find << "                    array[j] = tmp;\n";
        h_find << "                    int k = i;\n";
        h_find << "                    int j = 2*k;\n";
        h_find << "                }else{\n";
        h_find << "                    break;\n";
        h_find << "                }\n";
        h_find << "            }\n";
        h_find << "        }\n";
        h_find << "        for(unsigned i=longueur; i > 0; i++){\n";
        h_find << "            Type tmp = array[i];\n";
        h_find << "            array[i] = array[1];\n";
        h_find << "            array[1] = tmp;\n";
        h_find << "            int k = 1;\n";
        h_find << "            int j = 2*k;\n";
        h_find << "            while(j<i-1){\n";
        h_find << "                if(j<i-1 and array[j]." << name_id_parameter() << " < array[j+1]." << name_id_parameter() << ")\n";
        h_find << "                    j++;\n";
        h_find << "                if(array[k]." << name_id_parameter() << "<array[j]." << name_id_parameter() << "){\n";
        h_find << "                    Type tmp = array[k];\n";
        h_find << "                    array[k] = array[j];\n";
        h_find << "                    array[j] = tmp;\n";
        h_find << "                    int k = i;\n";
        h_find << "                    int j = 2*k;\n";
        h_find << "                }else{\n";
        h_find << "                    break;\n";
        h_find << "                }\n";
        h_find << "            }\n";
        h_find << "        }\n";
        h_find << "    }\n";
        */
    }
    
    /// Fonction recursive de parcours de la structure du fichier json
    /// 'name' : le nom de la variable dans le json
    /// 'value': la valeur associee
    /// 'owner': le chemin d'acces a la variable en cours de definition
    void read_pattern(const Sc2String& name, const Value& value, const Sc2String& owner){
        Value_type type = value.type();
        switch(type){
            case obj_type:{ /// <-- Bloc "fictif", pour pouvoir declarer des variables, sinon le compilateur aime pas    
                const Object& object = value.get_obj();
                h_struct << indentation(struct_level + 1) << "struct " << type_object(name) << "{\n";
                
                cpp_read                            << "if(name" << struct_level << " == \"" << name_object(name) << "\"){\n";
                cpp_read << indentation(read_level) << "    const Object& object" << struct_level << " = value" << struct_level << ".get_obj();\n";
                cpp_read << indentation(read_level) << "    for(Object::size_type i" << struct_level << " = 0;i" << struct_level << " < object" << struct_level << ".size(); ++i" << struct_level << "){\n";
                cpp_read << indentation(read_level) << "        const Sc2String& name" << struct_level + 1 << " = object" << struct_level << "[i" << struct_level << "].name_;\n";
                cpp_read << indentation(read_level) << "        const Value& value" << struct_level + 1 << " = object" << struct_level << "[i" << struct_level << "].value_;\n";
                /// Stocke le resultat dans un chaine de caractere si possible (ni object ni array)
                cpp_read << indentation(read_level) << "        Sc2String value_as_string" << struct_level + 1 << " = \"\";\n";
                cpp_read << indentation(read_level) << "        if(value" << struct_level + 1 << ".type() == bool_type){\n";
                cpp_read << indentation(read_level) << "            value_as_string" << struct_level + 1 << " << value" << struct_level + 1 << ".get_bool();\n";
                cpp_read << indentation(read_level) << "        }else if(value" << struct_level + 1 << ".type() == int_type){\n";
                cpp_read << indentation(read_level) << "            value_as_string" << struct_level + 1 << " << value" << struct_level + 1 << ".get_int();\n";
                cpp_read << indentation(read_level) << "        }else if(value" << struct_level + 1 << ".type() == real_type){\n";
                cpp_read << indentation(read_level) << "            value_as_string" << struct_level + 1 << " << value" << struct_level + 1 << ".get_real();\n";
                cpp_read << indentation(read_level) << "        }else if(value" << struct_level + 1 << ".type() == str_type){\n";
                cpp_read << indentation(read_level) << "            if(value" << struct_level + 1 << ".get_str()!=\"null\")\n";
                cpp_read << indentation(read_level) << "                value_as_string" << struct_level + 1 << " << value" << struct_level + 1 << ".get_str();\n";
                cpp_read << indentation(read_level) << "        }else if(value" << struct_level + 1 << ".type() == null_type){\n";
                cpp_read << indentation(read_level) << "            value_as_string" << struct_level + 1 << " = \"\";\n";
                cpp_read << indentation(read_level) << "        }\n";
                cpp_read << indentation(read_level) << "        if(DEBUG_SCJSONREADER) std::cout << \"" << indentation(read_level/2) << "Reading \" << name" << struct_level + 1 << " << \" : \" << value_as_string" << struct_level + 1 << " << std::endl;\n";
                cpp_read << indentation(read_level) << "        ";
                
                Sc2String new_owner; new_owner << owner << name_object(name) << ".";
                
                struct_level += 1;
                read_level += 2;
                for(Object::size_type i = 0; i != object.size(); ++i )
                    read_pattern(object[i].name_,object[i].value_,new_owner);
                
                h_struct << indentation(struct_level) << "};\n";
                h_struct << indentation(struct_level) << type_object(name) << " " << name_object(name) << ";\n\n";
                struct_level -= 1;
                read_level -= 2;
                
                cpp_read << "{std::cerr << \"Mauvais nom dans calcul.json : \" << name" << struct_level + 1 << " << std::endl;assert(0);}\n"; /// Viens apres le dernier 'else' des attributs de l'objet
                cpp_read << indentation(read_level) << "    }\n";
                cpp_read << indentation(read_level) << "}else ";
            }
            break;
            case array_type:{
                const Array& array = value.get_array();
                if(array.size() == 0){
                    std::cerr << "Le vecteur '" << name << "' est vide. Definition de la structure impossible" << std::endl;
                    assert(0);
                }
                const Object& object = array[0].get_obj();
                
                h_struct << indentation(struct_level + 1) << "struct " << type_object(name) << "{\n";
                
                cpp_read                            << "if(name" << struct_level << " == \"" << name_object(name) << "\"){\n";
                cpp_read << indentation(read_level) << "    const Array& array" << struct_level << " = value" << struct_level << ".get_array();\n";
                cpp_read << indentation(read_level) << "    " << owner << name_array(name) << ".resize(array" << struct_level << ".size());\n";
                cpp_read << indentation(read_level) << "    for(Array::size_type j" << struct_level << " = 0;j" << struct_level << " < array" << struct_level << ".size(); ++j" << struct_level << "){\n";
                cpp_read << indentation(read_level) << "        if(DEBUG_SCJSONREADER) std::cout << \"" << indentation(read_level-1) << "Object \" << j" << struct_level << " << \" :\" << std::endl;\n";
                cpp_read << indentation(read_level) << "        const Object& object" << struct_level << " = array" << struct_level << "[j" << struct_level << "].get_obj();\n";
                cpp_read << indentation(read_level) << "        for(Object::size_type i" << struct_level << " = 0;i" << struct_level << " < object" << struct_level << ".size(); ++i" << struct_level << "){\n";
                cpp_read << indentation(read_level) << "            const Sc2String& name" << struct_level + 1 << " = object" << struct_level << "[i" << struct_level << "].name_;\n";
                cpp_read << indentation(read_level) << "            const Value& value" << struct_level + 1 << " = object" << struct_level << "[i" << struct_level << "].value_;\n";
                /// Stocke le resultat dans un chaine de caractere si possible (ni object ni array)
                cpp_read << indentation(read_level) << "            Sc2String value_as_string" << struct_level + 1 << " = \"\";\n";
                cpp_read << indentation(read_level) << "            if(value" << struct_level + 1 << ".type() == bool_type){\n";
                cpp_read << indentation(read_level) << "                value_as_string" << struct_level + 1 << " << value" << struct_level + 1 << ".get_bool();\n";
                cpp_read << indentation(read_level) << "            }else if(value" << struct_level + 1 << ".type() == int_type){\n";
                cpp_read << indentation(read_level) << "                value_as_string" << struct_level + 1 << " << value" << struct_level + 1 << ".get_int();\n";
                cpp_read << indentation(read_level) << "            }else if(value" << struct_level + 1 << ".type() == real_type){\n";
                cpp_read << indentation(read_level) << "                value_as_string" << struct_level + 1 << " << value" << struct_level + 1 << ".get_real();\n";
                cpp_read << indentation(read_level) << "            }else if(value" << struct_level + 1 << ".type() == str_type){\n";
                cpp_read << indentation(read_level) << "                if(value" << struct_level + 1 << ".get_str()!=\"null\")\n";
                cpp_read << indentation(read_level) << "                    value_as_string" << struct_level + 1 << " << value" << struct_level + 1 << ".get_str();\n";
                cpp_read << indentation(read_level) << "            }else if(value" << struct_level + 1 << ".type() == null_type){\n";
                cpp_read << indentation(read_level) << "                value_as_string" << struct_level + 1 << " = \"\";\n";
                cpp_read << indentation(read_level) << "            }\n";
                cpp_read << indentation(read_level) << "            if(DEBUG_SCJSONREADER) std::cout << \"" << indentation(read_level/2) << "Reading \" << name" << struct_level + 1 << " << \" : \" << value_as_string" << struct_level + 1 << " << std::endl;\n";
                cpp_read << indentation(read_level) << "            ";
                
                Sc2String new_owner; new_owner << owner << name_array(name) << "[j" << struct_level << "].";
                
                struct_level += 1;
                read_level += 3;
                for(Object::size_type j = 0; j != object.size(); ++j)
                    read_pattern(object[j].name_,object[j].value_,new_owner);
                
                h_struct << indentation(struct_level) << "};\n";
                h_struct << indentation(struct_level) << type_array(name) << " " << name_array(name) << ";\n\n";
                
                struct_level -= 1;
                read_level -= 3;
                
                cpp_read << "{std::cerr << \"Mauvais nom dans calcul.json : \" << name" << struct_level + 1 << " << std::endl;assert(0);}\n"; /// Viens apres le dernier 'else' des attributs de l'objet
                cpp_read << indentation(read_level) << "        }\n";
                cpp_read << indentation(read_level) << "    }\n";
                
                /// Ajout de la fonction de tri par id
                if(struct_level == 0){
                    bool has_id_parameter = false;
                    for(int i = 0; i < object.size(); i++){
                        if(object[i].name_ == name_id_parameter()){
                            has_id_parameter = true;
                            break;
                        }
                    }
                    if(has_id_parameter){
                        //cpp_read << indentation(read_level) << "    sort_by_id(" << name_array(name) << ");\n";
                        add_search_function(name);
                    }
                }
                cpp_read << indentation(read_level) << "}else ";
            }
            break;
            case str_type:{
                Sc2String type_var = type_string(value.get_str());
                Sc2String name_var = name_string(name);
                cpp_read                            << "if(name" << struct_level << " == \"" << name_var << "\"){\n";
                /// On doit ignorer les types 'null'
                if(type_var != "null"){
                    h_struct << indentation(struct_level + 1) << type_var << " " << name_var << ";\n";
                    if(type_JSON(type_var) == "str_type"){
                        cpp_read << indentation(read_level) << "        " << owner << name_var << " = value_as_string" << struct_level << ";\n";
                    }else{
                        cpp_read << indentation(read_level) << "        input.str(value_as_string" << struct_level << ");\n";
                        cpp_read << indentation(read_level) << "        input >> " << owner << name_var << ";\n";
                        cpp_read << indentation(read_level) << "        input.clear();\n";
                    }
                } else {
                    cpp_read << indentation(read_level) << "    ; /// valeur ignoree\n";
                }
                cpp_read << indentation(read_level) << "} else ";
            }
            break;
            default:
                std::cerr << "Unable to read " << name << std::endl;
                assert(0);
        }
    }
    
    
    void add_search_function(Sc2String name){
        Sc2String struct_type = type_object(name);
        Sc2String array_name = name_array(name);
        /// Recherche de l'objet
        h_find << "    const " << type_object(name) << "* " << name_search_pointer(name) << "(int id_) const;\n";
        cpp_find << "const " << name_class() << "::" << type_object(name) << "* " << name_class() << "::" << name_search_pointer(name) << "(int id_) const {\n";
        cpp_find << "    for(unsigned i = 0; i < " << name_array(name) << ".size(); i++){\n";
        cpp_find << "        if(" << name_array(name) << "[i]." << name_id_parameter() << " == id_){\n";
        cpp_find << "            return &(" << name_array(name) << "[i]);\n";
        cpp_find << "        }\n";
        cpp_find << "    }\n";
        cpp_find << "}\n\n";
        /// Recherche de l'index
        h_find << "    " << "int " << name_search_index(name) << "(int id_) const;\n\n";
        cpp_find << "int " << name_class() << "::" << name_search_index(name) << "(int id_) const {\n";
        cpp_find << "    for(unsigned i = 0; i < " << name_array(name) << ".size(); i++){\n";
        cpp_find << "        if(" << name_array(name) << "[i]." << name_id_parameter() << " == id_){\n";
        cpp_find << "            return i;\n";
        cpp_find << "        }\n";
        cpp_find << "    }\n";
        cpp_find << "}\n\n";
    }
    
    void complete(){
        h_end << "\n    void read_json(const Sc2String& file_path);\n";
        h_end << "};\n";
        h_end << "\n";
        h_end << "#endif  //SCJSONREADER_H\n";
        
        /// Finalisation du .cpp
        cpp_end << "{std::cerr << \"Mauvais nom dans calcul.json : \" << name0;assert(0);}\n"; /// Viens apres le dernier 'else' des attributs de l'objet
        cpp_end << "    }\n";
        cpp_end << "}\n";
    }
    
    /// Fonction de convenience pour l'indentation (plus facile a relire apres)
    Sc2String indentation(int n){
        Sc2String indent;
        for(int i = 0; i < n; i++)
            indent << "    ";
        return indent;
    }
};



int main(int argc, char** argv){
    /// Repertoire des fichiers
    Sc2String dir_input = "src/SCJSONREADER/";
    Sc2String dir_output = "src/SCJSONREADER/";
    /// Fichier JSON
    Sc2String name_input = "pattern.json";
    std::ifstream file_input;
    /// Fichier H
    Sc2String name_h = "ScJsonReader.h";
    std::ofstream file_h((dir_output + name_h).c_str());
    /// Fichier CPP
    Sc2String name_cpp = "ScJsonReader.cpp";
    std::ofstream file_cpp((dir_output + name_cpp).c_str());
    try{
        file_input.open((dir_input + name_input).c_str());
        
        ReaderBuilder reader;
        reader.initialize();
        
        /// Appel a la fonction de parcours
        Value value;
        read(file_input,value);
        const Object& object = value.get_obj();
        for(Object::size_type i = 0; i != object.size(); ++i )
            reader.read_pattern(object[i].name_,object[i].value_,"");
        
        /// Finalisation
        reader.complete();
        
        /// Ecriture des fichiers .h et .cpp et fermeture
        file_input.close();
        file_h << reader.h_begin;
        file_h << reader.h_struct;
        file_h << reader.h_find;
        file_h << reader.h_end;
        file_h.close();
        file_cpp << reader.cpp_begin;
        file_cpp << reader.cpp_find;
        file_cpp << reader.cpp_read;
        file_cpp << reader.cpp_end;
        file_cpp.close();
        
    }catch(std::exception &e){
        std::cerr << e.what() << std::endl;
        /// Fermeture des fichiers en cas d'echec
        file_input.close();
        file_h.close();
        file_cpp.close();
    }
    
    std::cout << "Generation de " << dir_output << name_h << std::endl;
    std::cout << "           et " << dir_output << name_cpp << std::endl;
}
