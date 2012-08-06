#include "arcos.h"

Arcos::Arcos() {
    num_arcos = 0;
    num_arcos_validos = 0;
}

Arcos::Arcos(Arco *a) {
    num_arcos = 1;
    num_arcos_validos = 1;
    arcos.push_back(a);
}

Arcos::Arcos(vector<Arco*> arcs) {
    num_arcos = arcs.size();
    num_arcos_validos = arcs.size();
    arcos = arcs;
}

int Arcos::addArco(Arco *a) {
    // Si existe un indice en que haya un arco que fue borrado insertamos el arco ahi.
    if(borrados.size() > 0) {
        int ind = borrados[0];
        arcos[ind] = a;
        borrados.erase(borrados.begin());
        num_arcos_validos++; // actualizamos el numero de arcos validos
        return ind;
    }
    else {
        arcos.push_back(a); // agregamos el arco al contenedor.
        num_arcos++; // actualizamos el numero de arcos del contenedor
        num_arcos_validos++; // actualizamos el numero de arcos validos
        return (arcos.size()-1);
    }
}

int Arcos::addArcoIn(Arco *a, int indice) {
    assert((indice < (int)arcos.size()) && (indice >= 0));
    if(arcos[indice] == 0) {
        for(int i=0; i<(int)borrados.size(); i++) {
            if(borrados[i] == indice) {
                borrados.erase(borrados.begin()+i);
                num_arcos_validos++;
                arcos[indice] = a;
                return indice;
            }
        }
    }
    arcos[indice] = a;
    return indice;
}

void Arcos::eraseArco(int indice) {
    assert((indice < (int)arcos.size()) && (indice >= 0));
    if(arcos[indice] != 0) {
		delete arcos[indice];
        arcos[indice] = 0;
        borrados.push_back(indice);
        num_arcos_validos--;
    }
}

Arco* Arcos::getArco(int indice) {
    assert((indice < (int)arcos.size()) && (indice >= 0));
    return arcos[indice];
}

Arco* Arcos::operator[](int indice) {
    assert((indice < (int)arcos.size()) && (indice >= 0));
    return arcos[indice];
}

void Arcos::setCaraArco(int indice, int ind_cara) {
    assert((indice < (int)arcos.size()) && (indice >= 0));
    if(arcos[indice]->getCara1() == -1) {
        arcos[indice]->setCara1(ind_cara);
    }
    else if(arcos[indice]->getCara2() == -1) {
		//cerr << "seteo segunda cara" << endl;
        arcos[indice]->setCara2(ind_cara);
    }
    else {
        cout << "Malla con inconsistencias: Arco(" << indice << ") es parte de mas de 2 caras." << endl;
        //assert(1 == 0); // si ingresamos aqui, estamos mal porque quiere decir que un arco forma mas de 2 caras.
    }
}

int Arcos::getNumArcos() {
    return num_arcos;
}

int Arcos::getNumArcosValidos() {
    return num_arcos_validos;
}

int Arcos::getIndiceArco(int indice_n1, int indice_n2) {
    Arco *a;
    for(int i=0; i<num_arcos; i++) {
        a = arcos[i];
        if((indice_n1 == a->getNodo1() || indice_n1 == a->getNodo2()) && (indice_n2 == a->getNodo1() || indice_n2 == a->getNodo2())) {
            return i;
        }
    }
    a = new Arco(indice_n1,indice_n2);
    return this->addArco(a);
}

Arcos::~Arcos(){
	for (int i=0; i<(int)arcos.size(); i++)
		delete arcos[i];
	}
