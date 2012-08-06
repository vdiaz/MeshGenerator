#include "cara.h"

Cara::Cara(int n1, int n2, int n3, int a1, int a2, int a3) {
    num_elem = 3;
    ind_nodos.push_back(n1);
    ind_nodos.push_back(n2);
    ind_nodos.push_back(n3);
    ind_arcos.push_back(a1);
    ind_arcos.push_back(a2);
    ind_arcos.push_back(a3);
    rgb[0] = -1;
    rgb[1] = -1;
    rgb[2] = -1;
}

Cara::Cara(int n1, int n2, int n3) {
    num_elem = 3;
    ind_nodos.push_back(n1);
    ind_nodos.push_back(n2);
    ind_nodos.push_back(n3);
    rgb[0] = -1;
    rgb[1] = -1;
    rgb[2] = -1;
}

Cara::Cara(vector<int> ind_nds, vector<int> ind_arcs) {
    assert(ind_nds.size() == ind_arcs.size());
    num_elem = ind_nds.size();
    ind_nodos = ind_nds;
    ind_arcos = ind_arcs;
    rgb[0] = -1;
    rgb[1] = -1;
    rgb[2] = -1;
}

void Cara::setNodos(vector<int> nds) {
    ind_nodos = nds;
}

void Cara::addNodo(int nodo) {
    for(int i=0; i<(int)ind_nodos.size(); i++) {
        if(ind_nodos[i] == nodo) {
            return;
        }
    }
    ind_nodos.push_back(nodo);
}

void Cara::eraseNodo(int nodo) {
    vector<int>::iterator iter;
    for(iter=ind_nodos.begin(); iter!=ind_nodos.end(); iter++) {
        if(*iter == nodo) {
            iter = ind_nodos.erase(iter);
            return;
        }
    }
}

void Cara::changeNodo(int nodo_sale, int nodo_entra) {
    for(int i=0; i<(int)ind_nodos.size(); i++) {
        if(ind_nodos[i] == nodo_sale) {
            ind_nodos[i] = nodo_entra;
            return;
        }
    }
}

void Cara::changeArco(int arco_sale, int arco_entra){
	for(int i=0; i<(int)ind_arcos.size(); i++) {
        if(ind_arcos[i] == arco_sale) {
            ind_arcos[i] = arco_entra;
            return;
        	}
    	}
	}

vector<int> Cara::getNodos() {
    return ind_nodos;
}

void Cara::setArcos(vector<int> ars) {
    ind_arcos = ars;
}

void Cara::addArco(int arco) {
    for(int i=0; i<(int)ind_arcos.size(); i++) {
        if(ind_arcos[i] == arco) {
            return;
        }
    }
    ind_arcos.push_back(arco);
}
#include <algorithm>
void Cara::eraseArco(int arco) {
    vector<int>::iterator iter;
    for(iter=ind_arcos.begin(); iter!=ind_arcos.end(); iter++) {
        if(*iter == arco) {
            iter = ind_arcos.erase(iter);
            return;
        }
    }

}

vector<int> Cara::getArcos() {
    return ind_arcos;
}

int Cara::getPuntoDistinto(int p1, int p2) {
    assert(num_elem == 3);
    if(ind_nodos[0] != p1 && ind_nodos[0] != p2) {
        return ind_nodos[0];
    }
    else if(ind_nodos[1] != p1 && ind_nodos[1] != p2) {
        return ind_nodos[1];
    }
    else {
        return ind_nodos[2];
    }
}

vector<int> Cara::getPuntosDistintos(int p1) {
    assert(num_elem == 3);
	vector<int> puntosDistintos;
    if(ind_nodos[0] == p1) {
        puntosDistintos.push_back(ind_nodos[1]);
		puntosDistintos.push_back(ind_nodos[2]);
    }
    else if(ind_nodos[1] == p1) {
        puntosDistintos.push_back(ind_nodos[2]);
		puntosDistintos.push_back(ind_nodos[0]);
    }
    else if(ind_nodos[2] == p1) {
        puntosDistintos.push_back(ind_nodos[0]);
		puntosDistintos.push_back(ind_nodos[1]);
    }
	return puntosDistintos;
}

int Cara::getNumElem() {
    return num_elem;
}

void Cara::setColores(float r, float g, float b) {
    rgb[0] = r;
    rgb[1] = g;
    rgb[2] = b;
}

float Cara::getR() {
    return rgb[0];
}

float Cara::getG() {
    return rgb[1];
}

float Cara::getB() {
    return rgb[2];
}
