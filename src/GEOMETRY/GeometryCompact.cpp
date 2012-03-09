//
// C++ Interface: GEOMETRY
//
// Description:
//
//
// Author: David Violeau <d.violeau@structure-computation.com>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include <Metil/BasicVec.h>
#include <Metil/StructCompactor.h>

#include "GeometryCompact.h"

void calculate_measure(Ps<GeometryCompactClass> &geometry_compact_CPU, GeometryUser &geometry_user){
    std::cout << geometry_compact_CPU->group_interfaces.size() << std::endl;
    for(int i_group=0; i_group < geometry_compact_CPU->group_interfaces.size(); i_group++){
        geometry_compact_CPU->group_interfaces[i_group].measure=0;
        for(int i_elem=0; i_elem<geometry_compact_CPU->group_interfaces[i_group].nb_interfaces ; i_elem++)
            geometry_compact_CPU->group_interfaces[i_group].measure+=geometry_compact_CPU->group_interfaces[i_group].Me[i_elem];
        std::cout << geometry_compact_CPU->group_interfaces[i_group].measure << std::endl;
        geometry_user.group_interfaces[i_group].measure=geometry_compact_CPU->group_interfaces[i_group].measure;
    }
}