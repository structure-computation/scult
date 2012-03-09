//
// C++ Interface: CeometryCompact
//
// Description: 
//
//
// Author: Jeremie Bellec <j.bellec@structure-computation.com>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//
//


#include <Metil/BasicVec.h>
#include <Metil/StructCompactor.h>

#include "Patterns.h"
#include "GeometryCompactClass.h"
#include "GeometryCompactGen.h"
#include "GeometryUser.h"

using namespace Metil;

#ifndef GEOMETRY_COMPACT_H
#define GEOMETRY_COMPACT_H

//fonctions sur la géometrie compactée

//Calcul de la mesure de chaque groupe d'interfaces (aire ou longueur) à partir des mesures élémentaires stockées dans Me (compte tenu du choix de la discrétisation)
void calculate_measure(Ps<GeometryCompactClass> &geometry_compact_CPU, GeometryUser &geometry_user);




#endif //GEOMETRY_COMPACT_H
