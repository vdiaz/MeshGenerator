#include "largoarcomaximo.h"

LargoArcoMaximo::LargoArcoMaximo(double max):Criterio() {
    this->max = max;
}

bool LargoArcoMaximo::seCumple(Malla *malla, int indice) {
	assert (malla->getCara(indice)!=NULL);
	
 	int arcoMaximo=malla->getArcoMasLargo(indice);
	double largoArco=malla->getLargoArco(arcoMaximo);
	if (largoArco>max)
		return false;
	else
		return true;
	}


	
	   /*Cara* cara=malla->getCara(indice);
	vector<int> ind_arcos=cara->getArcos();
	for (int i=0; i<(int)ind_arcos.size(); i++){
		double largo_arco=malla->getLargoArco(ind_arcos[i]);
		if(largo_arco > max)
        	return false;
		}
	return true;*/
	
	/*double largo_arco = malla->getLargoArco(indice);
    if(largo_arco > max) {
        return false;
    }
    else {
        return true;
    }*/
