#include "areacara.h"

AreaCara::AreaCara(double max):Criterio() {
    this->max = max;
}

bool AreaCara::seCumple(Malla *malla, int indice) {
	assert (malla->getCara(indice)!=NULL);
	
    double area_cara = malla->getArea(indice);
	//cerr << "AreaCara=" << area_cara << endl;
    if(area_cara > max) {
        return false;
    }
    else {
        return true;
    }
}
