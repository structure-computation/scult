// fonction qui permet de générer la structure LEVEL.h compactée à partir de LEVEL_USER.h


#include "FieldStructureUser.h"
#include <Metil/StructCompactor.h>

using namespace Metil;

int main() {
    FieldStructureUser field_structure;
    StructCompactor sc(field_structure);
    sc.make_files();
}