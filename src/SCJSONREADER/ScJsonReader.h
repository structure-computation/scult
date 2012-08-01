#ifndef SCJSONREADER_H
#define SCJSONREADER_H

#include "../UTILS/Sc2String.h"

#include <Metil/BasicVec.h>
using namespace Metil;


class ScJsonReader{
public:
    struct Json_options{
        struct Json_convergence_method_LATIN{
            int max_iteration;
            TYPEREEL convergence_rate;
        };
        Json_convergence_method_LATIN convergence_method_LATIN;

        Sc2String mode;
    };
    Json_options options;

    struct Json_multiresolution_parameters{
        Sc2String multiresolution_type;
        int resolution_number;
        struct Json_collection{
            Sc2String parametric_function;
            int nb_value;
            Sc2String alias_name;
            Sc2String name;
            TYPEREEL nominal_value;
            TYPEREEL max_value;
            TYPEREEL min_value;
            int id_in_calcul;
        };
        BasicVec<Json_collection> collection_vec;

    };
    Json_multiresolution_parameters multiresolution_parameters;

    struct Json_interfaces{
        int id;
        int group;
        int assigned;
        int link_id;
        Sc2String adj_num_group;
        Sc2String name;
        Sc2String type;
        int id_in_calcul;
    };
    BasicVec<Json_interfaces> interfaces_vec;

    struct Json_mesh{
        Sc2String model_directory;
        int nb_sst;
        int nb_groups_elem;
        Sc2String mesh_directory;
        Sc2String extension;
        int nb_ddl;
        int nb_groups_inter;
        Sc2String mesh_name;
        int nb_inter;
    };
    Json_mesh mesh;

    struct Json_volumic_forces{
        Sc2String gamma;
        Sc2String name;
        Sc2String dx;
        Sc2String dy;
        Sc2String dz;
    };
    BasicVec<Json_volumic_forces> volumic_forces_vec;

    struct Json_thermal_load{
        Sc2String name;
        Sc2String function;
    };
    Json_thermal_load thermal_load;

    struct Json_materials{
        Sc2String name;
        int id_in_calcul;
        int type_num;
        Sc2String mtype;
        Sc2String mtype_isotrope;
        Sc2String mtype_orthotrope;
        Sc2String comp;
        Sc2String comp_el;
        Sc2String comp_pl;
        Sc2String comp_en;
        Sc2String comp_mes;
        Sc2String rho;
        TYPEREEL dir_1_x;
        TYPEREEL dir_1_y;
        TYPEREEL dir_1_z;
        TYPEREEL dir_2_x;
        TYPEREEL dir_2_y;
        TYPEREEL dir_2_z;
        TYPEREEL dir_3_x;
        TYPEREEL dir_3_y;
        TYPEREEL dir_3_z;
        Sc2String alpha_1;
        Sc2String alpha_2;
        Sc2String alpha_3;
        Sc2String E_1;
        Sc2String E_2;
        Sc2String E_3;
        Sc2String nu_12;
        Sc2String nu_13;
        Sc2String nu_23;
        Sc2String cis_1;
        Sc2String cis_2;
        Sc2String cis_3;
        Sc2String type_plast;
        Sc2String R0;
        Sc2String k_p;
        Sc2String m_p;
        Sc2String coeff_plast_cinematique;
        Sc2String type_endo;
        Sc2String Yo;
        Sc2String Yc;
        Sc2String Ycf;
        TYPEREEL dmax;
        TYPEREEL a;
        TYPEREEL couplage;
        bool effet_retard;
        TYPEREEL b_c;
        TYPEREEL tau_c;
        Sc2String viscosite;
    };
    BasicVec<Json_materials> materials_vec;

    struct Json_boundary_conditions{
        Sc2String name;
        Sc2String spatial_function_x;
        Sc2String spatial_function_y;
        Sc2String spatial_function_z;
        int id_in_calcul;
        Sc2String condition_type;
    };
    BasicVec<Json_boundary_conditions> boundary_conditions_vec;

    struct Json_time_steps{
        Sc2String time_scheme;
        struct Json_collection{
            Sc2String name;
            TYPEREEL initial_time;
            TYPEREEL final_time;
            TYPEREEL time_step;
            int id_in_calcul;
            int nb_time_steps;
        };
        BasicVec<Json_collection> collection_vec;

        struct Json_parameter_collection{
            struct Json_stepFunctions{
                Sc2String temporal_function_t;
                int step_id;
            };
            BasicVec<Json_stepFunctions> stepFunctions_vec;

            Sc2String alias_name;
            Sc2String name;
            int id_param;
            int id_in_calcul;
        };
        BasicVec<Json_parameter_collection> parameter_collection_vec;

    };
    Json_time_steps time_steps;

    struct Json_edges{
        int id_in_calcul;
        int assigned;
        Sc2String name;
        Sc2String criteria;
        Sc2String geometry;
        TYPEREEL direction_x;
        TYPEREEL direction_y;
        TYPEREEL direction_z;
        TYPEREEL point_1_x;
        TYPEREEL point_1_y;
        TYPEREEL point_1_z;
        TYPEREEL point_2_x;
        TYPEREEL point_2_y;
        TYPEREEL point_2_z;
        TYPEREEL radius;
        Sc2String equation;
        int boundary_condition_id;
    };
    BasicVec<Json_edges> edges_vec;

    struct Json_links{
        Sc2String name;
        Sc2String family;
        Sc2String description;
        int id_in_calcul;
        int type_num;
        Sc2String comp_generique;
        Sc2String comp_complexe;
        int Ep_type;
        Sc2String Ep_n;
        Sc2String Ep_x;
        Sc2String Ep_y;
        Sc2String Ep_z;
        Sc2String Preload_z;
        Sc2String Preload_y;
        Sc2String Preload_x;
        Sc2String Preload_n;
        Sc2String f;
        Sc2String Fcr_t;
        Sc2String Fcr_n;
        Sc2String Rop;
        Sc2String kp;
        Sc2String np;
        Sc2String Kn;
        Sc2String Knc;
        Sc2String Kt;
        Sc2String Yo;
        Sc2String Yc;
        Sc2String alpha;
        Sc2String gamma;
        Sc2String n;
    };
    BasicVec<Json_links> links_vec;

    struct Json_pieces{
        int material_id;
        int group;
        int assigned;
        Sc2String name;
        int id_in_calcul;
    };
    BasicVec<Json_pieces> pieces_vec;

    const Json_interfaces* find_interfaces_pointer(int id_) const;
    int find_interfaces_index(int id_) const;

    const Json_materials* find_materials_pointer(int id_) const;
    int find_materials_index(int id_) const;

    const Json_boundary_conditions* find_boundary_conditions_pointer(int id_) const;
    int find_boundary_conditions_index(int id_) const;

    const Json_edges* find_edges_pointer(int id_) const;
    int find_edges_index(int id_) const;

    const Json_links* find_links_pointer(int id_) const;
    int find_links_index(int id_) const;

    const Json_pieces* find_pieces_pointer(int id_) const;
    int find_pieces_index(int id_) const;


    void read_json(const Sc2String& file_path);
};

#endif  //SCJSONREADER_H
