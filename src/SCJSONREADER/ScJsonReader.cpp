#include "ScJsonReader.h"
#include "../UTILS/json_spirit/json_spirit.h"
#include <fstream>
#include <sstream>
using namespace json_spirit;
using namespace Metil;

#define DEBUG_SCJSONREADER false


const ScJsonReader::Json_interfaces* ScJsonReader::find_interfaces_pointer(int id_) const {
    for(unsigned i = 0; i < interfaces_vec.size(); i++){
        if(interfaces_vec[i].id_in_calcul == id_){
            return &(interfaces_vec[i]);
        }
    }
}

int ScJsonReader::find_interfaces_index(int id_) const {
    for(unsigned i = 0; i < interfaces_vec.size(); i++){
        if(interfaces_vec[i].id_in_calcul == id_){
            return i;
        }
    }
}

const ScJsonReader::Json_materials* ScJsonReader::find_materials_pointer(int id_) const {
    for(unsigned i = 0; i < materials_vec.size(); i++){
        if(materials_vec[i].id_in_calcul == id_){
            return &(materials_vec[i]);
        }
    }
}

int ScJsonReader::find_materials_index(int id_) const {
    for(unsigned i = 0; i < materials_vec.size(); i++){
        if(materials_vec[i].id_in_calcul == id_){
            return i;
        }
    }
}

const ScJsonReader::Json_boundary_conditions* ScJsonReader::find_boundary_conditions_pointer(int id_) const {
    for(unsigned i = 0; i < boundary_conditions_vec.size(); i++){
        if(boundary_conditions_vec[i].id_in_calcul == id_){
            return &(boundary_conditions_vec[i]);
        }
    }
}

int ScJsonReader::find_boundary_conditions_index(int id_) const {
    for(unsigned i = 0; i < boundary_conditions_vec.size(); i++){
        if(boundary_conditions_vec[i].id_in_calcul == id_){
            return i;
        }
    }
}

const ScJsonReader::Json_edges* ScJsonReader::find_edges_pointer(int id_) const {
    for(unsigned i = 0; i < edges_vec.size(); i++){
        if(edges_vec[i].id_in_calcul == id_){
            return &(edges_vec[i]);
        }
    }
}

int ScJsonReader::find_edges_index(int id_) const {
    for(unsigned i = 0; i < edges_vec.size(); i++){
        if(edges_vec[i].id_in_calcul == id_){
            return i;
        }
    }
}

const ScJsonReader::Json_links* ScJsonReader::find_links_pointer(int id_) const {
    for(unsigned i = 0; i < links_vec.size(); i++){
        if(links_vec[i].id_in_calcul == id_){
            return &(links_vec[i]);
        }
    }
}

int ScJsonReader::find_links_index(int id_) const {
    for(unsigned i = 0; i < links_vec.size(); i++){
        if(links_vec[i].id_in_calcul == id_){
            return i;
        }
    }
}

const ScJsonReader::Json_pieces* ScJsonReader::find_pieces_pointer(int id_) const {
    for(unsigned i = 0; i < pieces_vec.size(); i++){
        if(pieces_vec[i].id_in_calcul == id_){
            return &(pieces_vec[i]);
        }
    }
}

int ScJsonReader::find_pieces_index(int id_) const {
    for(unsigned i = 0; i < pieces_vec.size(); i++){
        if(pieces_vec[i].id_in_calcul == id_){
            return i;
        }
    }
}

void ScJsonReader::read_json(const Sc2String& file_path){
    if(DEBUG_SCJSONREADER) std::cout << "Ouverture de " << file_path << std::endl;
    std::ifstream is(file_path.c_str());
    if(!is.is_open()){
        std::cerr << "IMPOSSIBLE D'OUVRIR LE FICHIER :" << file_path << std::endl;
        assert(0);
    }
    std::istringstream input; /// Pour assurer la conversion vers les entiers et les reels
    Value value;
    read(is,value);
    const Object& object = value.get_obj();
    for(Object::size_type i = 0;i < object.size(); ++i){
        const Sc2String& name0 = object[i].name_;
        const Value& value0 = object[i].value_;
        if(DEBUG_SCJSONREADER) std::cout << "Reading " << name0 << " :" << std::endl;
        if(name0 == "action"){
            ; /// valeur ignoree
        } else if(name0 == "calcul_time"){
            ; /// valeur ignoree
        } else if(name0 == "controller"){
            ; /// valeur ignoree
        } else if(name0 == "created_at"){
            ; /// valeur ignoree
        } else if(name0 == "ctype"){
            ; /// valeur ignoree
        } else if(name0 == "description"){
            ; /// valeur ignoree
        } else if(name0 == "D2type"){
            ; /// valeur ignoree
        } else if(name0 == "estimated_calcul_time"){
            ; /// valeur ignoree
        } else if(name0 == "forcasts"){
            ; /// valeur ignoree
        } else if(name0 == "gpu_allocated"){
            ; /// valeur ignoree
        } else if(name0 == "id"){
            ; /// valeur ignoree
        } else if(name0 == "last_saved"){
            ; /// valeur ignoree
        } else if(name0 == "launch_autorisation"){
            ; /// valeur ignoree
        } else if(name0 == "launch_date"){
            ; /// valeur ignoree
        } else if(name0 == "log_type"){
            ; /// valeur ignoree
        } else if(name0 == "name"){
            ; /// valeur ignoree
        } else if(name0 == "result_date"){
            ; /// valeur ignoree
        } else if(name0 == "state"){
            ; /// valeur ignoree
        } else if(name0 == "sc_model_id"){
            ; /// valeur ignoree
        } else if(name0 == "updated_at"){
            ; /// valeur ignoree
        } else if(name0 == "used_memory"){
            ; /// valeur ignoree
        } else if(name0 == "user_id"){
            ; /// valeur ignoree
        } else if(name0 == "workspace_member_id"){
            ; /// valeur ignoree
        } else if(name0 == "options"){
            const Object& object0 = value0.get_obj();
            for(Object::size_type i0 = 0;i0 < object0.size(); ++i0){
                const Sc2String& name1 = object0[i0].name_;
                const Value& value1 = object0[i0].value_;
                Sc2String value_as_string1 = "";
                if(value1.type() == bool_type){
                    value_as_string1 << value1.get_bool();
                }else if(value1.type() == int_type){
                    value_as_string1 << value1.get_int();
                }else if(value1.type() == real_type){
                    value_as_string1 << value1.get_real();
                }else if(value1.type() == str_type){
                    if(value1.get_str()!="null")
                        value_as_string1 << value1.get_str();
                }else if(value1.type() == null_type){
                    value_as_string1 = "";
                }
                if(DEBUG_SCJSONREADER) std::cout << "    Reading " << name1 << " : " << value_as_string1 << std::endl;
                if(name1 == "convergence_method_LATIN"){
                    const Object& object1 = value1.get_obj();
                    for(Object::size_type i1 = 0;i1 < object1.size(); ++i1){
                        const Sc2String& name2 = object1[i1].name_;
                        const Value& value2 = object1[i1].value_;
                        Sc2String value_as_string2 = "";
                        if(value2.type() == bool_type){
                            value_as_string2 << value2.get_bool();
                        }else if(value2.type() == int_type){
                            value_as_string2 << value2.get_int();
                        }else if(value2.type() == real_type){
                            value_as_string2 << value2.get_real();
                        }else if(value2.type() == str_type){
                            if(value2.get_str()!="null")
                                value_as_string2 << value2.get_str();
                        }else if(value2.type() == null_type){
                            value_as_string2 = "";
                        }
                        if(DEBUG_SCJSONREADER) std::cout << "        Reading " << name2 << " : " << value_as_string2 << std::endl;
                        if(name2 == "max_iteration"){
                                input.str(value_as_string2);
                                input >> options.convergence_method_LATIN.max_iteration;
                                input.clear();
                        } else if(name2 == "convergence_rate"){
                                input.str(value_as_string2);
                                input >> options.convergence_method_LATIN.convergence_rate;
                                input.clear();
                        } else {std::cerr << "Mauvais nom dans calcul.json : " << name2 << std::endl;assert(0);}
                    }
                }else if(name1 == "precision_calcul"){
                    ; /// valeur ignoree
                } else if(name1 == "mode"){
                        options.mode = value_as_string1;
                } else {std::cerr << "Mauvais nom dans calcul.json : " << name1 << std::endl;assert(0);}
            }
        }else if(name0 == "multiresolution_parameters"){
            const Object& object0 = value0.get_obj();
            for(Object::size_type i0 = 0;i0 < object0.size(); ++i0){
                const Sc2String& name1 = object0[i0].name_;
                const Value& value1 = object0[i0].value_;
                Sc2String value_as_string1 = "";
                if(value1.type() == bool_type){
                    value_as_string1 << value1.get_bool();
                }else if(value1.type() == int_type){
                    value_as_string1 << value1.get_int();
                }else if(value1.type() == real_type){
                    value_as_string1 << value1.get_real();
                }else if(value1.type() == str_type){
                    if(value1.get_str()!="null")
                        value_as_string1 << value1.get_str();
                }else if(value1.type() == null_type){
                    value_as_string1 = "";
                }
                if(DEBUG_SCJSONREADER) std::cout << "    Reading " << name1 << " : " << value_as_string1 << std::endl;
                if(name1 == "multiresolution_type"){
                        multiresolution_parameters.multiresolution_type = value_as_string1;
                } else if(name1 == "resolution_number"){
                        input.str(value_as_string1);
                        input >> multiresolution_parameters.resolution_number;
                        input.clear();
                } else if(name1 == "collection"){
                    const Array& array1 = value1.get_array();
                    multiresolution_parameters.collection_vec.resize(array1.size());
                    for(Array::size_type j1 = 0;j1 < array1.size(); ++j1){
                        if(DEBUG_SCJSONREADER) std::cout << "            Object " << j1 << " :" << std::endl;
                        const Object& object1 = array1[j1].get_obj();
                        for(Object::size_type i1 = 0;i1 < object1.size(); ++i1){
                            const Sc2String& name2 = object1[i1].name_;
                            const Value& value2 = object1[i1].value_;
                            Sc2String value_as_string2 = "";
                            if(value2.type() == bool_type){
                                value_as_string2 << value2.get_bool();
                            }else if(value2.type() == int_type){
                                value_as_string2 << value2.get_int();
                            }else if(value2.type() == real_type){
                                value_as_string2 << value2.get_real();
                            }else if(value2.type() == str_type){
                                if(value2.get_str()!="null")
                                    value_as_string2 << value2.get_str();
                            }else if(value2.type() == null_type){
                                value_as_string2 = "";
                            }
                            if(DEBUG_SCJSONREADER) std::cout << "        Reading " << name2 << " : " << value_as_string2 << std::endl;
                            if(name2 == "function"){
                                    multiresolution_parameters.collection_vec[j1].function = value_as_string2;
                            } else if(name2 == "nb_value"){
                                    input.str(value_as_string2);
                                    input >> multiresolution_parameters.collection_vec[j1].nb_value;
                                    input.clear();
                            } else if(name2 == "name"){
                                    multiresolution_parameters.collection_vec[j1].name = value_as_string2;
                            } else if(name2 == "type"){
                                    multiresolution_parameters.collection_vec[j1].type = value_as_string2;
                            } else if(name2 == "id_in_calcul"){
                                    input.str(value_as_string2);
                                    input >> multiresolution_parameters.collection_vec[j1].id_in_calcul;
                                    input.clear();
                            } else {std::cerr << "Mauvais nom dans calcul.json : " << name2 << std::endl;assert(0);}
                        }
                    }
                }else {std::cerr << "Mauvais nom dans calcul.json : " << name1 << std::endl;assert(0);}
            }
        }else if(name0 == "interfaces"){
            const Array& array0 = value0.get_array();
            interfaces_vec.resize(array0.size());
            for(Array::size_type j0 = 0;j0 < array0.size(); ++j0){
                if(DEBUG_SCJSONREADER) std::cout << "    Object " << j0 << " :" << std::endl;
                const Object& object0 = array0[j0].get_obj();
                for(Object::size_type i0 = 0;i0 < object0.size(); ++i0){
                    const Sc2String& name1 = object0[i0].name_;
                    const Value& value1 = object0[i0].value_;
                    Sc2String value_as_string1 = "";
                    if(value1.type() == bool_type){
                        value_as_string1 << value1.get_bool();
                    }else if(value1.type() == int_type){
                        value_as_string1 << value1.get_int();
                    }else if(value1.type() == real_type){
                        value_as_string1 << value1.get_real();
                    }else if(value1.type() == str_type){
                        if(value1.get_str()!="null")
                            value_as_string1 << value1.get_str();
                    }else if(value1.type() == null_type){
                        value_as_string1 = "";
                    }
                    if(DEBUG_SCJSONREADER) std::cout << "    Reading " << name1 << " : " << value_as_string1 << std::endl;
                    if(name1 == "id"){
                            input.str(value_as_string1);
                            input >> interfaces_vec[j0].id;
                            input.clear();
                    } else if(name1 == "group"){
                            input.str(value_as_string1);
                            input >> interfaces_vec[j0].group;
                            input.clear();
                    } else if(name1 == "assigned"){
                            input.str(value_as_string1);
                            input >> interfaces_vec[j0].assigned;
                            input.clear();
                    } else if(name1 == "link_id"){
                            input.str(value_as_string1);
                            input >> interfaces_vec[j0].link_id;
                            input.clear();
                    } else if(name1 == "adj_num_group"){
                            interfaces_vec[j0].adj_num_group = value_as_string1;
                    } else if(name1 == "name"){
                            interfaces_vec[j0].name = value_as_string1;
                    } else if(name1 == "type"){
                            interfaces_vec[j0].type = value_as_string1;
                    } else if(name1 == "id_in_calcul"){
                            input.str(value_as_string1);
                            input >> interfaces_vec[j0].id_in_calcul;
                            input.clear();
                    } else if(name1 == "origine"){
                        ; /// valeur ignoree
                    } else {std::cerr << "Mauvais nom dans calcul.json : " << name1 << std::endl;assert(0);}
                }
            }
        }else if(name0 == "mesh"){
            const Object& object0 = value0.get_obj();
            for(Object::size_type i0 = 0;i0 < object0.size(); ++i0){
                const Sc2String& name1 = object0[i0].name_;
                const Value& value1 = object0[i0].value_;
                Sc2String value_as_string1 = "";
                if(value1.type() == bool_type){
                    value_as_string1 << value1.get_bool();
                }else if(value1.type() == int_type){
                    value_as_string1 << value1.get_int();
                }else if(value1.type() == real_type){
                    value_as_string1 << value1.get_real();
                }else if(value1.type() == str_type){
                    if(value1.get_str()!="null")
                        value_as_string1 << value1.get_str();
                }else if(value1.type() == null_type){
                    value_as_string1 = "";
                }
                if(DEBUG_SCJSONREADER) std::cout << "    Reading " << name1 << " : " << value_as_string1 << std::endl;
                if(name1 == "model_directory"){
                        mesh.model_directory = value_as_string1;
                } else if(name1 == "nb_sst"){
                        input.str(value_as_string1);
                        input >> mesh.nb_sst;
                        input.clear();
                } else if(name1 == "nb_groups_elem"){
                        input.str(value_as_string1);
                        input >> mesh.nb_groups_elem;
                        input.clear();
                } else if(name1 == "mesh_directory"){
                        mesh.mesh_directory = value_as_string1;
                } else if(name1 == "extension"){
                        mesh.extension = value_as_string1;
                } else if(name1 == "nb_ddl"){
                        input.str(value_as_string1);
                        input >> mesh.nb_ddl;
                        input.clear();
                } else if(name1 == "nb_groups_inter"){
                        input.str(value_as_string1);
                        input >> mesh.nb_groups_inter;
                        input.clear();
                } else if(name1 == "mesh_name"){
                        mesh.mesh_name = value_as_string1;
                } else if(name1 == "nb_inter"){
                        input.str(value_as_string1);
                        input >> mesh.nb_inter;
                        input.clear();
                } else {std::cerr << "Mauvais nom dans calcul.json : " << name1 << std::endl;assert(0);}
            }
        }else if(name0 == "volumic_forces"){
            const Array& array0 = value0.get_array();
            volumic_forces_vec.resize(array0.size());
            for(Array::size_type j0 = 0;j0 < array0.size(); ++j0){
                if(DEBUG_SCJSONREADER) std::cout << "    Object " << j0 << " :" << std::endl;
                const Object& object0 = array0[j0].get_obj();
                for(Object::size_type i0 = 0;i0 < object0.size(); ++i0){
                    const Sc2String& name1 = object0[i0].name_;
                    const Value& value1 = object0[i0].value_;
                    Sc2String value_as_string1 = "";
                    if(value1.type() == bool_type){
                        value_as_string1 << value1.get_bool();
                    }else if(value1.type() == int_type){
                        value_as_string1 << value1.get_int();
                    }else if(value1.type() == real_type){
                        value_as_string1 << value1.get_real();
                    }else if(value1.type() == str_type){
                        if(value1.get_str()!="null")
                            value_as_string1 << value1.get_str();
                    }else if(value1.type() == null_type){
                        value_as_string1 = "";
                    }
                    if(DEBUG_SCJSONREADER) std::cout << "    Reading " << name1 << " : " << value_as_string1 << std::endl;
                    if(name1 == "gamma"){
                            volumic_forces_vec[j0].gamma = value_as_string1;
                    } else if(name1 == "name"){
                            volumic_forces_vec[j0].name = value_as_string1;
                    } else if(name1 == "dx"){
                            volumic_forces_vec[j0].dx = value_as_string1;
                    } else if(name1 == "dy"){
                            volumic_forces_vec[j0].dy = value_as_string1;
                    } else if(name1 == "dz"){
                            volumic_forces_vec[j0].dz = value_as_string1;
                    } else if(name1 == "selected"){
                        ; /// valeur ignoree
                    } else {std::cerr << "Mauvais nom dans calcul.json : " << name1 << std::endl;assert(0);}
                }
            }
        }else if(name0 == "thermal_load"){
            const Object& object0 = value0.get_obj();
            for(Object::size_type i0 = 0;i0 < object0.size(); ++i0){
                const Sc2String& name1 = object0[i0].name_;
                const Value& value1 = object0[i0].value_;
                Sc2String value_as_string1 = "";
                if(value1.type() == bool_type){
                    value_as_string1 << value1.get_bool();
                }else if(value1.type() == int_type){
                    value_as_string1 << value1.get_int();
                }else if(value1.type() == real_type){
                    value_as_string1 << value1.get_real();
                }else if(value1.type() == str_type){
                    if(value1.get_str()!="null")
                        value_as_string1 << value1.get_str();
                }else if(value1.type() == null_type){
                    value_as_string1 = "";
                }
                if(DEBUG_SCJSONREADER) std::cout << "    Reading " << name1 << " : " << value_as_string1 << std::endl;
                if(name1 == "name"){
                        thermal_load.name = value_as_string1;
                } else if(name1 == "function"){
                        thermal_load.function = value_as_string1;
                } else {std::cerr << "Mauvais nom dans calcul.json : " << name1 << std::endl;assert(0);}
            }
        }else if(name0 == "materials"){
            const Array& array0 = value0.get_array();
            materials_vec.resize(array0.size());
            for(Array::size_type j0 = 0;j0 < array0.size(); ++j0){
                if(DEBUG_SCJSONREADER) std::cout << "    Object " << j0 << " :" << std::endl;
                const Object& object0 = array0[j0].get_obj();
                for(Object::size_type i0 = 0;i0 < object0.size(); ++i0){
                    const Sc2String& name1 = object0[i0].name_;
                    const Value& value1 = object0[i0].value_;
                    Sc2String value_as_string1 = "";
                    if(value1.type() == bool_type){
                        value_as_string1 << value1.get_bool();
                    }else if(value1.type() == int_type){
                        value_as_string1 << value1.get_int();
                    }else if(value1.type() == real_type){
                        value_as_string1 << value1.get_real();
                    }else if(value1.type() == str_type){
                        if(value1.get_str()!="null")
                            value_as_string1 << value1.get_str();
                    }else if(value1.type() == null_type){
                        value_as_string1 = "";
                    }
                    if(DEBUG_SCJSONREADER) std::cout << "    Reading " << name1 << " : " << value_as_string1 << std::endl;
                    if(name1 == "name"){
                            materials_vec[j0].name = value_as_string1;
                    } else if(name1 == "id_in_calcul"){
                            input.str(value_as_string1);
                            input >> materials_vec[j0].id_in_calcul;
                            input.clear();
                    } else if(name1 == "type_num"){
                            input.str(value_as_string1);
                            input >> materials_vec[j0].type_num;
                            input.clear();
                    } else if(name1 == "mtype"){
                            materials_vec[j0].mtype = value_as_string1;
                    } else if(name1 == "mtype_isotrope"){
                            materials_vec[j0].mtype_isotrope = value_as_string1;
                    } else if(name1 == "mtype_orthotrope"){
                            materials_vec[j0].mtype_orthotrope = value_as_string1;
                    } else if(name1 == "comp"){
                            materials_vec[j0].comp = value_as_string1;
                    } else if(name1 == "comp_el"){
                            materials_vec[j0].comp_el = value_as_string1;
                    } else if(name1 == "comp_pl"){
                            materials_vec[j0].comp_pl = value_as_string1;
                    } else if(name1 == "comp_en"){
                            materials_vec[j0].comp_en = value_as_string1;
                    } else if(name1 == "comp_mes"){
                            materials_vec[j0].comp_mes = value_as_string1;
                    } else if(name1 == "rho"){
                            materials_vec[j0].rho = value_as_string1;
                    } else if(name1 == "dir_1_x"){
                            input.str(value_as_string1);
                            input >> materials_vec[j0].dir_1_x;
                            input.clear();
                    } else if(name1 == "dir_1_y"){
                            input.str(value_as_string1);
                            input >> materials_vec[j0].dir_1_y;
                            input.clear();
                    } else if(name1 == "dir_1_z"){
                            input.str(value_as_string1);
                            input >> materials_vec[j0].dir_1_z;
                            input.clear();
                    } else if(name1 == "dir_2_x"){
                            input.str(value_as_string1);
                            input >> materials_vec[j0].dir_2_x;
                            input.clear();
                    } else if(name1 == "dir_2_y"){
                            input.str(value_as_string1);
                            input >> materials_vec[j0].dir_2_y;
                            input.clear();
                    } else if(name1 == "dir_2_z"){
                            input.str(value_as_string1);
                            input >> materials_vec[j0].dir_2_z;
                            input.clear();
                    } else if(name1 == "dir_3_x"){
                            input.str(value_as_string1);
                            input >> materials_vec[j0].dir_3_x;
                            input.clear();
                    } else if(name1 == "dir_3_y"){
                            input.str(value_as_string1);
                            input >> materials_vec[j0].dir_3_y;
                            input.clear();
                    } else if(name1 == "dir_3_z"){
                            input.str(value_as_string1);
                            input >> materials_vec[j0].dir_3_z;
                            input.clear();
                    } else if(name1 == "alpha_1"){
                            materials_vec[j0].alpha_1 = value_as_string1;
                    } else if(name1 == "alpha_2"){
                            materials_vec[j0].alpha_2 = value_as_string1;
                    } else if(name1 == "alpha_3"){
                            materials_vec[j0].alpha_3 = value_as_string1;
                    } else if(name1 == "E_1"){
                            materials_vec[j0].E_1 = value_as_string1;
                    } else if(name1 == "E_2"){
                            materials_vec[j0].E_2 = value_as_string1;
                    } else if(name1 == "E_3"){
                            materials_vec[j0].E_3 = value_as_string1;
                    } else if(name1 == "nu_12"){
                            materials_vec[j0].nu_12 = value_as_string1;
                    } else if(name1 == "nu_13"){
                            materials_vec[j0].nu_13 = value_as_string1;
                    } else if(name1 == "nu_23"){
                            materials_vec[j0].nu_23 = value_as_string1;
                    } else if(name1 == "cis_1"){
                            materials_vec[j0].cis_1 = value_as_string1;
                    } else if(name1 == "cis_2"){
                            materials_vec[j0].cis_2 = value_as_string1;
                    } else if(name1 == "cis_3"){
                            materials_vec[j0].cis_3 = value_as_string1;
                    } else if(name1 == "type_plast"){
                            materials_vec[j0].type_plast = value_as_string1;
                    } else if(name1 == "R0"){
                            materials_vec[j0].R0 = value_as_string1;
                    } else if(name1 == "k_p"){
                            materials_vec[j0].k_p = value_as_string1;
                    } else if(name1 == "m_p"){
                            materials_vec[j0].m_p = value_as_string1;
                    } else if(name1 == "coeff_plast_cinematique"){
                            materials_vec[j0].coeff_plast_cinematique = value_as_string1;
                    } else if(name1 == "type_endo"){
                            materials_vec[j0].type_endo = value_as_string1;
                    } else if(name1 == "Yo"){
                            materials_vec[j0].Yo = value_as_string1;
                    } else if(name1 == "Yc"){
                            materials_vec[j0].Yc = value_as_string1;
                    } else if(name1 == "Ycf"){
                            materials_vec[j0].Ycf = value_as_string1;
                    } else if(name1 == "dmax"){
                            input.str(value_as_string1);
                            input >> materials_vec[j0].dmax;
                            input.clear();
                    } else if(name1 == "a"){
                            input.str(value_as_string1);
                            input >> materials_vec[j0].a;
                            input.clear();
                    } else if(name1 == "couplage"){
                            input.str(value_as_string1);
                            input >> materials_vec[j0].couplage;
                            input.clear();
                    } else if(name1 == "effet_retard"){
                            input.str(value_as_string1);
                            input >> materials_vec[j0].effet_retard;
                            input.clear();
                    } else if(name1 == "b_c"){
                            input.str(value_as_string1);
                            input >> materials_vec[j0].b_c;
                            input.clear();
                    } else if(name1 == "tau_c"){
                            input.str(value_as_string1);
                            input >> materials_vec[j0].tau_c;
                            input.clear();
                    } else if(name1 == "viscosite"){
                            materials_vec[j0].viscosite = value_as_string1;
                    } else if(name1 == "state"){
                        ; /// valeur ignoree
                    } else if(name1 == "name_select"){
                        ; /// valeur ignoree
                    } else if(name1 == "updated_at"){
                        ; /// valeur ignoree
                    } else if(name1 == "description"){
                        ; /// valeur ignoree
                    } else if(name1 == "id_from_database"){
                        ; /// valeur ignoree
                    } else if(name1 == "family"){
                        ; /// valeur ignoree
                    } else if(name1 == "id_select"){
                        ; /// valeur ignoree
                    } else if(name1 == "created_at"){
                        ; /// valeur ignoree
                    } else if(name1 == "workspace_id"){
                        ; /// valeur ignoree
                    } else if(name1 == "reference"){
                        ; /// valeur ignoree
                    } else {std::cerr << "Mauvais nom dans calcul.json : " << name1 << std::endl;assert(0);}
                }
            }
        }else if(name0 == "boundary_conditions"){
            const Array& array0 = value0.get_array();
            boundary_conditions_vec.resize(array0.size());
            for(Array::size_type j0 = 0;j0 < array0.size(); ++j0){
                if(DEBUG_SCJSONREADER) std::cout << "    Object " << j0 << " :" << std::endl;
                const Object& object0 = array0[j0].get_obj();
                for(Object::size_type i0 = 0;i0 < object0.size(); ++i0){
                    const Sc2String& name1 = object0[i0].name_;
                    const Value& value1 = object0[i0].value_;
                    Sc2String value_as_string1 = "";
                    if(value1.type() == bool_type){
                        value_as_string1 << value1.get_bool();
                    }else if(value1.type() == int_type){
                        value_as_string1 << value1.get_int();
                    }else if(value1.type() == real_type){
                        value_as_string1 << value1.get_real();
                    }else if(value1.type() == str_type){
                        if(value1.get_str()!="null")
                            value_as_string1 << value1.get_str();
                    }else if(value1.type() == null_type){
                        value_as_string1 = "";
                    }
                    if(DEBUG_SCJSONREADER) std::cout << "    Reading " << name1 << " : " << value_as_string1 << std::endl;
                    if(name1 == "name"){
                            boundary_conditions_vec[j0].name = value_as_string1;
                    } else if(name1 == "description"){
                        ; /// valeur ignoree
                    } else if(name1 == "spatial_function_x"){
                            boundary_conditions_vec[j0].spatial_function_x = value_as_string1;
                    } else if(name1 == "spatial_function_y"){
                            boundary_conditions_vec[j0].spatial_function_y = value_as_string1;
                    } else if(name1 == "spatial_function_z"){
                            boundary_conditions_vec[j0].spatial_function_z = value_as_string1;
                    } else if(name1 == "id_in_calcul"){
                            input.str(value_as_string1);
                            input >> boundary_conditions_vec[j0].id_in_calcul;
                            input.clear();
                    } else if(name1 == "condition_type"){
                            boundary_conditions_vec[j0].condition_type = value_as_string1;
                    } else {std::cerr << "Mauvais nom dans calcul.json : " << name1 << std::endl;assert(0);}
                }
            }
        }else if(name0 == "time_steps"){
            const Object& object0 = value0.get_obj();
            for(Object::size_type i0 = 0;i0 < object0.size(); ++i0){
                const Sc2String& name1 = object0[i0].name_;
                const Value& value1 = object0[i0].value_;
                Sc2String value_as_string1 = "";
                if(value1.type() == bool_type){
                    value_as_string1 << value1.get_bool();
                }else if(value1.type() == int_type){
                    value_as_string1 << value1.get_int();
                }else if(value1.type() == real_type){
                    value_as_string1 << value1.get_real();
                }else if(value1.type() == str_type){
                    if(value1.get_str()!="null")
                        value_as_string1 << value1.get_str();
                }else if(value1.type() == null_type){
                    value_as_string1 = "";
                }
                if(DEBUG_SCJSONREADER) std::cout << "    Reading " << name1 << " : " << value_as_string1 << std::endl;
                if(name1 == "time_scheme"){
                        time_steps.time_scheme = value_as_string1;
                } else if(name1 == "collection"){
                    const Array& array1 = value1.get_array();
                    time_steps.collection_vec.resize(array1.size());
                    for(Array::size_type j1 = 0;j1 < array1.size(); ++j1){
                        if(DEBUG_SCJSONREADER) std::cout << "            Object " << j1 << " :" << std::endl;
                        const Object& object1 = array1[j1].get_obj();
                        for(Object::size_type i1 = 0;i1 < object1.size(); ++i1){
                            const Sc2String& name2 = object1[i1].name_;
                            const Value& value2 = object1[i1].value_;
                            Sc2String value_as_string2 = "";
                            if(value2.type() == bool_type){
                                value_as_string2 << value2.get_bool();
                            }else if(value2.type() == int_type){
                                value_as_string2 << value2.get_int();
                            }else if(value2.type() == real_type){
                                value_as_string2 << value2.get_real();
                            }else if(value2.type() == str_type){
                                if(value2.get_str()!="null")
                                    value_as_string2 << value2.get_str();
                            }else if(value2.type() == null_type){
                                value_as_string2 = "";
                            }
                            if(DEBUG_SCJSONREADER) std::cout << "        Reading " << name2 << " : " << value_as_string2 << std::endl;
                            if(name2 == "name"){
                                    time_steps.collection_vec[j1].name = value_as_string2;
                            } else if(name2 == "initial_time"){
                                    input.str(value_as_string2);
                                    input >> time_steps.collection_vec[j1].initial_time;
                                    input.clear();
                            } else if(name2 == "final_time"){
                                    input.str(value_as_string2);
                                    input >> time_steps.collection_vec[j1].final_time;
                                    input.clear();
                            } else if(name2 == "time_step"){
                                    input.str(value_as_string2);
                                    input >> time_steps.collection_vec[j1].time_step;
                                    input.clear();
                            } else if(name2 == "id_in_calcul"){
                                    input.str(value_as_string2);
                                    input >> time_steps.collection_vec[j1].id_in_calcul;
                                    input.clear();
                            } else if(name2 == "nb_time_steps"){
                                    input.str(value_as_string2);
                                    input >> time_steps.collection_vec[j1].nb_time_steps;
                                    input.clear();
                            } else {std::cerr << "Mauvais nom dans calcul.json : " << name2 << std::endl;assert(0);}
                        }
                    }
                }else if(name1 == "parameter_collection"){
                    const Array& array1 = value1.get_array();
                    time_steps.parameter_collection_vec.resize(array1.size());
                    for(Array::size_type j1 = 0;j1 < array1.size(); ++j1){
                        if(DEBUG_SCJSONREADER) std::cout << "            Object " << j1 << " :" << std::endl;
                        const Object& object1 = array1[j1].get_obj();
                        for(Object::size_type i1 = 0;i1 < object1.size(); ++i1){
                            const Sc2String& name2 = object1[i1].name_;
                            const Value& value2 = object1[i1].value_;
                            Sc2String value_as_string2 = "";
                            if(value2.type() == bool_type){
                                value_as_string2 << value2.get_bool();
                            }else if(value2.type() == int_type){
                                value_as_string2 << value2.get_int();
                            }else if(value2.type() == real_type){
                                value_as_string2 << value2.get_real();
                            }else if(value2.type() == str_type){
                                if(value2.get_str()!="null")
                                    value_as_string2 << value2.get_str();
                            }else if(value2.type() == null_type){
                                value_as_string2 = "";
                            }
                            if(DEBUG_SCJSONREADER) std::cout << "        Reading " << name2 << " : " << value_as_string2 << std::endl;
                            if(name2 == "stepFunctions"){
                                const Array& array2 = value2.get_array();
                                time_steps.parameter_collection_vec[j1].stepFunctions_vec.resize(array2.size());
                                for(Array::size_type j2 = 0;j2 < array2.size(); ++j2){
                                    if(DEBUG_SCJSONREADER) std::cout << "                        Object " << j2 << " :" << std::endl;
                                    const Object& object2 = array2[j2].get_obj();
                                    for(Object::size_type i2 = 0;i2 < object2.size(); ++i2){
                                        const Sc2String& name3 = object2[i2].name_;
                                        const Value& value3 = object2[i2].value_;
                                        Sc2String value_as_string3 = "";
                                        if(value3.type() == bool_type){
                                            value_as_string3 << value3.get_bool();
                                        }else if(value3.type() == int_type){
                                            value_as_string3 << value3.get_int();
                                        }else if(value3.type() == real_type){
                                            value_as_string3 << value3.get_real();
                                        }else if(value3.type() == str_type){
                                            if(value3.get_str()!="null")
                                                value_as_string3 << value3.get_str();
                                        }else if(value3.type() == null_type){
                                            value_as_string3 = "";
                                        }
                                        if(DEBUG_SCJSONREADER) std::cout << "            Reading " << name3 << " : " << value_as_string3 << std::endl;
                                        if(name3 == "temporal_function_t"){
                                                time_steps.parameter_collection_vec[j1].stepFunctions_vec[j2].temporal_function_t = value_as_string3;
                                        } else if(name3 == "step_id"){
                                                input.str(value_as_string3);
                                                input >> time_steps.parameter_collection_vec[j1].stepFunctions_vec[j2].step_id;
                                                input.clear();
                                        } else {std::cerr << "Mauvais nom dans calcul.json : " << name3 << std::endl;assert(0);}
                                    }
                                }
                            }else if(name2 == "alias_name"){
                                    time_steps.parameter_collection_vec[j1].alias_name = value_as_string2;
                            } else if(name2 == "name"){
                                    time_steps.parameter_collection_vec[j1].name = value_as_string2;
                            } else if(name2 == "description"){
                                ; /// valeur ignoree
                            } else if(name2 == "id_param"){
                                    input.str(value_as_string2);
                                    input >> time_steps.parameter_collection_vec[j1].id_param;
                                    input.clear();
                            } else if(name2 == "id_in_calcul"){
                                    input.str(value_as_string2);
                                    input >> time_steps.parameter_collection_vec[j1].id_in_calcul;
                                    input.clear();
                            } else {std::cerr << "Mauvais nom dans calcul.json : " << name2 << std::endl;assert(0);}
                        }
                    }
                }else {std::cerr << "Mauvais nom dans calcul.json : " << name1 << std::endl;assert(0);}
            }
        }else if(name0 == "edges"){
            const Array& array0 = value0.get_array();
            edges_vec.resize(array0.size());
            for(Array::size_type j0 = 0;j0 < array0.size(); ++j0){
                if(DEBUG_SCJSONREADER) std::cout << "    Object " << j0 << " :" << std::endl;
                const Object& object0 = array0[j0].get_obj();
                for(Object::size_type i0 = 0;i0 < object0.size(); ++i0){
                    const Sc2String& name1 = object0[i0].name_;
                    const Value& value1 = object0[i0].value_;
                    Sc2String value_as_string1 = "";
                    if(value1.type() == bool_type){
                        value_as_string1 << value1.get_bool();
                    }else if(value1.type() == int_type){
                        value_as_string1 << value1.get_int();
                    }else if(value1.type() == real_type){
                        value_as_string1 << value1.get_real();
                    }else if(value1.type() == str_type){
                        if(value1.get_str()!="null")
                            value_as_string1 << value1.get_str();
                    }else if(value1.type() == null_type){
                        value_as_string1 = "";
                    }
                    if(DEBUG_SCJSONREADER) std::cout << "    Reading " << name1 << " : " << value_as_string1 << std::endl;
                    if(name1 == "id_in_calcul"){
                            input.str(value_as_string1);
                            input >> edges_vec[j0].id_in_calcul;
                            input.clear();
                    } else if(name1 == "assigned"){
                            input.str(value_as_string1);
                            input >> edges_vec[j0].assigned;
                            input.clear();
                    } else if(name1 == "name"){
                            edges_vec[j0].name = value_as_string1;
                    } else if(name1 == "criteria"){
                            edges_vec[j0].criteria = value_as_string1;
                    } else if(name1 == "geometry"){
                            edges_vec[j0].geometry = value_as_string1;
                    } else if(name1 == "description"){
                        ; /// valeur ignoree
                    } else if(name1 == "direction_x"){
                            input.str(value_as_string1);
                            input >> edges_vec[j0].direction_x;
                            input.clear();
                    } else if(name1 == "direction_y"){
                            input.str(value_as_string1);
                            input >> edges_vec[j0].direction_y;
                            input.clear();
                    } else if(name1 == "direction_z"){
                            input.str(value_as_string1);
                            input >> edges_vec[j0].direction_z;
                            input.clear();
                    } else if(name1 == "point_1_x"){
                            input.str(value_as_string1);
                            input >> edges_vec[j0].point_1_x;
                            input.clear();
                    } else if(name1 == "point_1_y"){
                            input.str(value_as_string1);
                            input >> edges_vec[j0].point_1_y;
                            input.clear();
                    } else if(name1 == "point_1_z"){
                            input.str(value_as_string1);
                            input >> edges_vec[j0].point_1_z;
                            input.clear();
                    } else if(name1 == "point_2_x"){
                            input.str(value_as_string1);
                            input >> edges_vec[j0].point_2_x;
                            input.clear();
                    } else if(name1 == "point_2_y"){
                            input.str(value_as_string1);
                            input >> edges_vec[j0].point_2_y;
                            input.clear();
                    } else if(name1 == "point_2_z"){
                            input.str(value_as_string1);
                            input >> edges_vec[j0].point_2_z;
                            input.clear();
                    } else if(name1 == "radius"){
                            input.str(value_as_string1);
                            input >> edges_vec[j0].radius;
                            input.clear();
                    } else if(name1 == "epsilon"){
                            input.str(value_as_string1);
                            input >> edges_vec[j0].epsilon;
                            input.clear();
                    } else if(name1 == "equation"){
                            edges_vec[j0].equation = value_as_string1;
                    } else if(name1 == "boundary_condition_id"){
                            input.str(value_as_string1);
                            input >> edges_vec[j0].boundary_condition_id;
                            input.clear();
                    } else {std::cerr << "Mauvais nom dans calcul.json : " << name1 << std::endl;assert(0);}
                }
            }
        }else if(name0 == "links"){
            const Array& array0 = value0.get_array();
            links_vec.resize(array0.size());
            for(Array::size_type j0 = 0;j0 < array0.size(); ++j0){
                if(DEBUG_SCJSONREADER) std::cout << "    Object " << j0 << " :" << std::endl;
                const Object& object0 = array0[j0].get_obj();
                for(Object::size_type i0 = 0;i0 < object0.size(); ++i0){
                    const Sc2String& name1 = object0[i0].name_;
                    const Value& value1 = object0[i0].value_;
                    Sc2String value_as_string1 = "";
                    if(value1.type() == bool_type){
                        value_as_string1 << value1.get_bool();
                    }else if(value1.type() == int_type){
                        value_as_string1 << value1.get_int();
                    }else if(value1.type() == real_type){
                        value_as_string1 << value1.get_real();
                    }else if(value1.type() == str_type){
                        if(value1.get_str()!="null")
                            value_as_string1 << value1.get_str();
                    }else if(value1.type() == null_type){
                        value_as_string1 = "";
                    }
                    if(DEBUG_SCJSONREADER) std::cout << "    Reading " << name1 << " : " << value_as_string1 << std::endl;
                    if(name1 == "name"){
                            links_vec[j0].name = value_as_string1;
                    } else if(name1 == "family"){
                            links_vec[j0].family = value_as_string1;
                    } else if(name1 == "description"){
                            links_vec[j0].description = value_as_string1;
                    } else if(name1 == "id_in_calcul"){
                            input.str(value_as_string1);
                            input >> links_vec[j0].id_in_calcul;
                            input.clear();
                    } else if(name1 == "type_num"){
                            input.str(value_as_string1);
                            input >> links_vec[j0].type_num;
                            input.clear();
                    } else if(name1 == "comp_generique"){
                            links_vec[j0].comp_generique = value_as_string1;
                    } else if(name1 == "comp_complexe"){
                            links_vec[j0].comp_complexe = value_as_string1;
                    } else if(name1 == "Ep_type"){
                            input.str(value_as_string1);
                            input >> links_vec[j0].Ep_type;
                            input.clear();
                    } else if(name1 == "Ep_n"){
                            links_vec[j0].Ep_n = value_as_string1;
                    } else if(name1 == "Ep_x"){
                            links_vec[j0].Ep_x = value_as_string1;
                    } else if(name1 == "Ep_y"){
                            links_vec[j0].Ep_y = value_as_string1;
                    } else if(name1 == "Ep_z"){
                            links_vec[j0].Ep_z = value_as_string1;
                    } else if(name1 == "Preload_z"){
                            links_vec[j0].Preload_z = value_as_string1;
                    } else if(name1 == "Preload_y"){
                            links_vec[j0].Preload_y = value_as_string1;
                    } else if(name1 == "Preload_x"){
                            links_vec[j0].Preload_x = value_as_string1;
                    } else if(name1 == "Preload_n"){
                            links_vec[j0].Preload_n = value_as_string1;
                    } else if(name1 == "f"){
                            links_vec[j0].f = value_as_string1;
                    } else if(name1 == "Fcr_t"){
                            links_vec[j0].Fcr_t = value_as_string1;
                    } else if(name1 == "Fcr_n"){
                            links_vec[j0].Fcr_n = value_as_string1;
                    } else if(name1 == "Rop"){
                            links_vec[j0].Rop = value_as_string1;
                    } else if(name1 == "kp"){
                            links_vec[j0].kp = value_as_string1;
                    } else if(name1 == "np"){
                            links_vec[j0].np = value_as_string1;
                    } else if(name1 == "Kn"){
                            links_vec[j0].Kn = value_as_string1;
                    } else if(name1 == "Knc"){
                            links_vec[j0].Knc = value_as_string1;
                    } else if(name1 == "Kt"){
                            links_vec[j0].Kt = value_as_string1;
                    } else if(name1 == "Yo"){
                            links_vec[j0].Yo = value_as_string1;
                    } else if(name1 == "Yc"){
                            links_vec[j0].Yc = value_as_string1;
                    } else if(name1 == "alpha"){
                            links_vec[j0].alpha = value_as_string1;
                    } else if(name1 == "gamma"){
                            links_vec[j0].gamma = value_as_string1;
                    } else if(name1 == "n"){
                            links_vec[j0].n = value_as_string1;
                    } else if(name1 == "workspace_id"){
                        ; /// valeur ignoree
                    } else if(name1 == "reference"){
                        ; /// valeur ignoree
                    } else if(name1 == "updated_at"){
                        ; /// valeur ignoree
                    } else if(name1 == "name_select"){
                        ; /// valeur ignoree
                    } else if(name1 == "id_from_database"){
                        ; /// valeur ignoree
                    } else if(name1 == "id_select"){
                        ; /// valeur ignoree
                    } else if(name1 == "state"){
                        ; /// valeur ignoree
                    } else if(name1 == "created_at"){
                        ; /// valeur ignoree
                    } else {std::cerr << "Mauvais nom dans calcul.json : " << name1 << std::endl;assert(0);}
                }
            }
        }else if(name0 == "pieces"){
            const Array& array0 = value0.get_array();
            pieces_vec.resize(array0.size());
            for(Array::size_type j0 = 0;j0 < array0.size(); ++j0){
                if(DEBUG_SCJSONREADER) std::cout << "    Object " << j0 << " :" << std::endl;
                const Object& object0 = array0[j0].get_obj();
                for(Object::size_type i0 = 0;i0 < object0.size(); ++i0){
                    const Sc2String& name1 = object0[i0].name_;
                    const Value& value1 = object0[i0].value_;
                    Sc2String value_as_string1 = "";
                    if(value1.type() == bool_type){
                        value_as_string1 << value1.get_bool();
                    }else if(value1.type() == int_type){
                        value_as_string1 << value1.get_int();
                    }else if(value1.type() == real_type){
                        value_as_string1 << value1.get_real();
                    }else if(value1.type() == str_type){
                        if(value1.get_str()!="null")
                            value_as_string1 << value1.get_str();
                    }else if(value1.type() == null_type){
                        value_as_string1 = "";
                    }
                    if(DEBUG_SCJSONREADER) std::cout << "    Reading " << name1 << " : " << value_as_string1 << std::endl;
                    if(name1 == "id"){
                        ; /// valeur ignoree
                    } else if(name1 == "material_id"){
                            input.str(value_as_string1);
                            input >> pieces_vec[j0].material_id;
                            input.clear();
                    } else if(name1 == "group"){
                            input.str(value_as_string1);
                            input >> pieces_vec[j0].group;
                            input.clear();
                    } else if(name1 == "assigned"){
                            input.str(value_as_string1);
                            input >> pieces_vec[j0].assigned;
                            input.clear();
                    } else if(name1 == "name"){
                            pieces_vec[j0].name = value_as_string1;
                    } else if(name1 == "identificateur"){
                        ; /// valeur ignoree
                    } else if(name1 == "id_in_calcul"){
                            input.str(value_as_string1);
                            input >> pieces_vec[j0].id_in_calcul;
                            input.clear();
                    } else if(name1 == "origine"){
                        ; /// valeur ignoree
                    } else {std::cerr << "Mauvais nom dans calcul.json : " << name1 << std::endl;assert(0);}
                }
            }
        }else {std::cerr << "Mauvais nom dans calcul.json : " << name0;assert(0);}
    }
}
