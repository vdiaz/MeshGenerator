#include "largoarcominimo.h"

LargoArcoMinimo::LargoArcoMinimo(double max):Criterio() {
    this->max = max;
}

bool LargoArcoMinimo::seCumple(Malla *malla, int indice) {
	assert (malla->getCara(indice)!=NULL);
	
    int arcoMinimo=malla->getArcoMasCorto(indice);
	double largoArco=malla->getLargoArco(arcoMinimo);
	if (largoArco>max)
		return false;
	else
		return true;
	}		
	
	/*double largo_arco = malla->getLargoArco(indice);
    if(largo_arco > max) {
        return false;
    }
    else {
        return true;
    }*/
