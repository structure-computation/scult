//
// C++ Interface: read_sc
//
// Description:
//
//
// Author: David Violeau <d.violeau@structure-computation.com>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//


#ifndef LMT_READ_SC_HEADER
#define LMT_READ_SC_HEADER

#include "containers/vec.h"
#include "mesh/mesh.h"
#include "mesh/tetra.h"
#include "mesh/triangle_6.h"

#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include <stdexcept>

void read_results ( string name2, Vec<TYPE> &data );
void read_geom_motif ( string name2, Vec<TYPE> &_nodes, Vec<int> &_S_apex, Vec<int,9> &data_size );

#include "visu_paraview.h"
#include "struct_nb.h"


namespace LMT
{

/// read sc format
	template<class TM>
	void read_sc_mesh ( TM &m, std::string &name_geom ) throw ( std::runtime_error )
	{

		Vec<TYPE> nodes;
		Vec<int> S_apex;
		Vec<int,9> data_size;
		read_geom_motif ( name_geom, nodes, S_apex, data_size );

		NB nb;
		nb.sst=data_size[0];
		nb.nodes_sst=data_size[1];
		nb.elements_sst=data_size[2];
		nb.nodes_element_sst=data_size[3];
		nb.decoup=data_size[6];
		nb.apex_sst=data_size[7];
		nb.sst_s=data_size[8];

		TM meshglob;
		create_LMTpp_mesh ( meshglob,S_apex, nodes, nb );

	}

	template<class TM>
	void read_sc ( TM &m, std::string &name_geom, std::string &name_result ) throw ( std::runtime_error )
	{

		Vec<TYPE> nodes;
		Vec<int> S_apex;
		Vec<int,9> data_size;
		read_geom_motif ( name_geom, nodes, S_apex, data_size );

		Vec<TYPE> S_q;
		read_results ( name_result, S_q );

		NB nb;
		nb.sst=data_size[0];
		nb.nodes_sst=data_size[1];
		nb.elements_sst=data_size[2];
		nb.nodes_element_sst=data_size[3];
		nb.decoup=data_size[6];
		nb.apex_sst=data_size[7];
		nb.sst_s=data_size[8];

		TM meshglob;
		create_LMTpp_mesh_dep ( meshglob, S_q, S_apex, nodes, nb );

	}

};

#endif // LMT_READ_SC_HEADER

