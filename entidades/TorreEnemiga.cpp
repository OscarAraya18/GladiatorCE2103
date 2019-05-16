#include "TorreEnemiga.h"

TorreEnemiga::TorreEnemiga(int tipoTorre) {
    this->tipoTorre = tipoTorre;
}

int TorreEnemiga::getTipoTorre() {
    return tipoTorre;
}
