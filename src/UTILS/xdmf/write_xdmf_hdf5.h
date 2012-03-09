//
// C++ Implementation: write_in_hdf
//
// Description: 
//
//
// Author: David Violeau <dvioleau@structure-computation.com>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef XDMF_HDF
#define XDMF_HDF
#include <Metil/Hdf.h>

void write_xdmf_from_hdf5(String output_xdmf, String input_hdf5, String name_geometry, int skin, String name_fields,  BasicVec<String> attributs);

#endif