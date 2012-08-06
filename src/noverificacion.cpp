#include "noverificacion.h"

NoVerificacion::NoVerificacion(double val) : AlgDesplazamiento() {
    this->val = val;
}


void NoVerificacion::aplicar(Malla *malla) {
    if(val < 0.0) return;
    malla->getNodos()->moverTodosSegunConcentracion(val);
}
