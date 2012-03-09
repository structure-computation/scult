// fonction qui permet de générer la structure LEVEL.h compactée à partir de LEVEL_USER.h


#include "GeometryUser.h"
#include <Metil/StructCompactor.h>

using namespace Metil;

int main() {
    GeometryUser geometry;
    StructCompactor sc(geometry);
    sc.make_files();
}