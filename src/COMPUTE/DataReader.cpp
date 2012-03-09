#include <Metil/Level1/CompilationEnvironment.h>
#include <Metil/DynamicLibrary.h>
#include <Metil/MathBasicVec.h>
#include <Metil/System.h>
#include <Metil/Math.h>
#include <Metil/Md5.h>
#include <set>
#include <map>

#include "DataReader.h"

BEG_METIL_NAMESPACE;


// DataReader *NEW_DataReader( DataUser &data_user  ) {
//     
//     
//     String base;
//     base << "ReadParam_" << data_user.id_calcul;
//     
//     Level1::CompilationEnvironment &ce = Level1::CompilationEnvironment::get_main_compilation_environment();
// //     String calcul_path;
// //     calcul_path << data_user.calcul_path.c_str();
// //     ce.set_comp_dir( calcul_path );
//     ce.add_inc_path("./src/COMPUTE/");
//     ce.add_inc_path("./src/GEOMETRY/");
//     ce.add_inc_path("./src/UTILS/json_spirit/");
//     
//     String proc_DIM;
//     proc_DIM << "DIM=" << DIM;
//     String proc_TYPE;
//     proc_TYPE << "TYPE=" << "double";
//     String proc_THREADSPERBLOCK;
//     proc_THREADSPERBLOCK << "THREADSPERBLOCK=" << 48;
//     String proc_SIZEGRID;
//     proc_SIZEGRID << "SIZEGRID=" << 6;
//     ce.add_def_proc(proc_DIM);
//     ce.add_def_proc(proc_TYPE);
//     ce.add_def_proc(proc_THREADSPERBLOCK);
//     ce.add_def_proc(proc_SIZEGRID);
//     String file_cu = ce.cu_for( base );
//     String file_h = ce.h_for( base );
// 
//     data_user.write_read_prop_cpp( file_cu,  file_h);
// 
//     String so = ce.lib_for( base, true );
//     SI64 date_so = last_modification_time_or_zero_of_file_named( so );
//     if ( ce.make_lib( so, file_cu, true ) )
//         ERROR( "Pb during compilation of %s", file_cu.c_str() );
// // 
//     // load lib
//     static std::map<String,DynamicLibrary> libs;
//     if ( not libs.count( so ) )
//         libs[ so ].open( so );
//  
// //     // find symbol
//     DynamicLibrary &dl = libs[ so ];
//     typedef DataReader *NewReader();
//     NewReader *nr = (NewReader *)dl.get_sym( "NEW_Reader" );
//     ASSERT( nr, "..." );
//     return nr();
// }

END_METIL_NAMESPACE;