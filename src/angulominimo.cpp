#include "angulominimo.h"

AnguloMinimo::AnguloMinimo(double min) : Criterio() {
    this->min = min;
}

bool AnguloMinimo::seCumple(Malla *malla, int indice) {
	assert (malla->getCara(indice)!=NULL);
	
    double angulo_min = malla->getAnguloMin(indice);
    if(angulo_min < min) {
        return false;
    }
    else {
        return true;
    }
}
