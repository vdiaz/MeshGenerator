#include "caras.h"

Caras::Caras() {
    num_caras = 0;
    num_caras_validas = 0;
}

Caras::Caras(Cara *c) {
    num_caras = 1;
    num_caras_validas = 1;
    caras.push_back(c);
}

Caras::Caras(vector<Cara*> crs) {
    num_caras = crs.size();
    num_caras_validas = crs.size();
    caras = crs;
}

int Caras::addCara(Cara *c) {
    // Si existe un indice en que haya un arco que fue borrado insertamos la cara ahi.
    if(borrados.size() > 0) {
        int ind = borrados[0];
        caras[ind] = c;
        borrados.erase(borrados.begin());
        num_caras_validas++; // actualizamos el numero de caras validas
        return ind;
    }
    else {
        caras.push_back(c); // agregamos la cara al contenedor.
        num_caras++; // actualizamos el numero de caras del contenedor
        num_caras_validas++; // actualizamos el numero de caras validas
        return (caras.size()-1);
    }
}

int Caras::addCaraIn(Cara *c, int indice) {
    assert((indice < (int)caras.size()) && (indice >= 0));
    if(caras[indice] == 0) {
        for(int i=0; i<(int)borrados.size(); i++) {
            if(borrados[i] == indice) {
                borrados.erase(borrados.begin()+i);
                num_caras_validas++;
                caras[indice] = c;
                return indice;
            }
        }
    }
    caras[indice] = c;
    return indice;
}

void Caras::eraseCara(int indice) {
    assert((indice < (int)caras.size()) && (indice >= 0));
    if(caras[indice] != 0) {
		delete caras[indice];
        caras[indice] = 0;
        borrados.push_back(indice);
        num_caras_validas--;
    }
}

Cara* Caras::getCara(int indice) {
    assert((indice < (int)caras.size()) && (indice >= 0));
    return caras[indice];
}

Cara* Caras::operator[](int indice) {
    assert((indice < (int)caras.size()) && (indice >= 0));
    return caras[indice];
}

int Caras::getNumCaras() {
    return num_caras;
}

int Caras::getNumCarasValidas() {
    return num_caras_validas;
}

Caras::~Caras(){
	for (int i=0; i<(int)caras.size(); i++)
		delete caras[i];
	}
