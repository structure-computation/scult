#parametres a modifier si necessaire
DIM = 3
NB_COMP_PROC = 1
MACHINE_TYPE = CPU

DIR_SOURCES_COMPUTE = -Isrc -Isrc/GEOMETRY -Isrc/COMPUTE -Isrc/UTILS -Isrc/UTILS/hdf -Isrc/UTILS/xdmf  -Isrc/UTILS/json_spirit 

DIR_build_release_cpu = --comp-dir build/SC_create_$(DIM)_release_$(MACHINE_TYPE)
DIR_build_debug_cpu = --comp-dir build/SC_create_$(DIM)_debug_$(MACHINE_TYPE)

PRG_create_2 = SC_create_2_cpu_$(DIM).exe

LOC_MC = metil_comp 
CFLAGS=`xml2-config --cflags`
LIBS=`xml2-config  --libs`
DIR_SOURCES_LMT =  -ILMT -ILMT/include -ILMT/include/LDL -ILMT/include/util -Iusr/include/suitesparse
OPT = -ne -j$(NB_COMP_PROC) -gdb -O3 -ffast-math -fexpensive-optimizations
OPTDEBUG = -ne -j$(NB_COMP_PROC) -ggdb -g3 -ffast-math -fexpensive-optimizations
GLOB_VAR = -D$(MACHINE_TYPE) -DDIM=$(DIM) -DTYPE=double -DTYPEREEL=double -DLDL -DWITH_CHOLMOD -DWITH_UMFPACK


all: DEBUG RELEASE JSONREADER


DEBUG :
	$(LOC_MC)  -o  $(PRG_create_2) $(GLOB_VAR) $(DIR_SOURCES_LMT) $(DIR_SOURCES_COMPUTE) $(DIR_build_debug_cpu) $(CFLAGS) $(LIBS) $(OPTDEBUG)  src/SC_create_2.cpp 8

RELEASE :
	$(LOC_MC)  -o  $(PRG_create_2) $(GLOB_VAR) $(DIR_SOURCES_LMT) $(DIR_SOURCES_COMPUTE) $(DIR_build_release_cpu) $(CFLAGS) $(LIBS) $(OPT)  src/SC_create_2.cpp 8

JSONREADER:
	$(LOC_MC) -o DataUserUpdater.exe $(DIR_SOURCES_LMT) -Ihome/scproduction/code_dev/Metil-test/src $(DIR_SOURCES_SC) $(DIR_SOURCES_GEOMETRY) $(DIR_SOURCES_MPI) --comp-dir build/DataUserUpdater $(CFLAGS) src/SCJSONREADER/run.cpp

codegen:
	cd LMT/include/codegen; scons
clean:
	cd LMT/include/codegen; scons -c
