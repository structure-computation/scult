#parametres a modifier si necessaire
DIM = 3
DIR_SOURCES_COMPUTE = -Isrc -Isrc/GEOMETRY -Isrc/COMPUTE -Isrc/UTILS -Isrc/UTILS/hdf -Isrc/UTILS/xdmf  -Isrc/UTILS/json_spirit 

PRG_create_2_cpu = SC_create_2_cpu_$(DIM).exe
PRG_compute_2_cpu = SC_compute_2_cpu_$(DIM).exe
PRG_data_reader_2_cpu = SC_data_reader_2_cpu_$(DIM).exe

LOC_MC = metil_comp 
CFLAGS=`xml2-config --cflags`
LIBS=`xml2-config  --libs`
DIR_SOURCES_LMT =  -ILMT -ILMT/include -ILMT/include/LDL -ILMT/include/util -Iusr/include/suitesparse
DIR_SOURCES_CUDA = -I/usr/local/cuda/include -I/home/jbellec/driver_toolkit/NVIDIA_GPU_Computing_SDK/C/common/inc
OPT = -ne -gdb -O3 -ffast-math -fexpensive-optimizations

# all: compact_GEOMETRY 
all: metil_comp_create_2_cpu

metil_test :
	metil src/CALCUL/code_metil/test.met

metil_comp_create_2_cpu :
	$(LOC_MC)  -o  $(PRG_create_2_cpu) -DDIM=$(DIM) -DGPU  -DTYPE=double -DLDL -DWITH_CHOLMOD -DWITH_UMFPACK $(DIR_SOURCES_LMT) $(DIR_SOURCES_COMPUTE) $(CFLAGS) $(LIBS) $(OPT)  src/SC_create_2.cpp 8

metil_comp_compute_2_cpu :
	$(LOC_MC)  -o  $(PRG_compute_2_cpu) -DDIM=$(DIM) -DGPU  -DTYPE=double -DTHREADSPERBLOCK=48  -DSIZEGRID=6  -DLDL -DWITH_CHOLMOD -DWITH_UMFPACK   $(DIR_SOURCES_LMT) $(DIR_SOURCES_COMPUTE) $(CFLAGS) $(LIBS) $(OPT)  src/SC_compute_2.cpp

metil_comp_data_2_cpu :
	$(LOC_MC)  -o  $(PRG_data_reader_2_cpu) -DDIM=$(DIM) -DGPU  -DTYPE=double -DLDL -DWITH_CHOLMOD -DWITH_UMFPACK $(DIR_SOURCES_LMT) $(DIR_SOURCES_COMPUTE) $(CFLAGS) $(LIBS) $(OPT)  src/SC_data_reader_2.cpp 8

compact_GEOMETRY: 
	$(LOC_MC) -o compact_GEOMETRY.exe -O0 -DDIM=$(DIM) -DCPU  -DTYPE=double -DLDL -DWITH_CHOLMOD -DWITH_UMFPACK $(DIR_SOURCES_LMT) $(DIR_SOURCES_COMPUTE) $(DIR_build_cpu) $(CFLAGS) $(LIBS) src/GEOMETRY/GenerationGeometryCompactClass.cpp

compact_FIELD_STRUCTURE: 
	$(LOC_MC) -o compact_FIELD_STRUCTURE.exe -O0 -DDIM=$(DIM) -DCPU  -DTYPE=double -DLDL -DWITH_CHOLMOD -DWITH_UMFPACK $(DIR_SOURCES_LMT) $(DIR_SOURCES_COMPUTE) $(DIR_build_cpu) $(CFLAGS) $(LIBS) src/COMPUTE/GenerationFieldStructureCompactClass.cpp

compact_DATA: 
	$(LOC_MC) -o compact_DATA.exe -O0 -DDIM=$(DIM) -DCPU  -DTYPE=double -DLDL -DWITH_CHOLMOD -DWITH_UMFPACK $(DIR_SOURCES_LMT) $(DIR_SOURCES_COMPUTE) $(DIR_build_cpu) $(CFLAGS) $(LIBS) src/COMPUTE/GenerationDataUserCompactClass.cpp

codegen:
	cd LMT/include/codegen; scons