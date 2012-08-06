#include "mejdelaunay.h"

MejDelaunay::MejDelaunay():AlgMejoramiento() {

}

void MejDelaunay::aplicar(Malla *malla) {
    //Hacemos los flip en donde se pueda y se mejoren los angulos.
    for(int i=0; i<malla->getArcos()->getNumArcos(); i++){
		if (malla->getArco(i)!=NULL){
			cout << "Aplicando Mejoramiento Delaunay en arco " << i << endl;
        	malla->makeDelaunay(i);
			}
		}
	}
