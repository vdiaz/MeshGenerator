#include "arco.h"

Arco::Arco() {
    nodo1 = -1;
    nodo2 = -1;
    cara1 = -1;
    cara2 = -1;
}

Arco::Arco(int n1, int n2) {
    nodo1 = n1;
    nodo2 = n2;
    cara1 = -1;
    cara2 = -1;
}

Arco::Arco(int n1, int n2, int c1, int c2) {
    nodo1 = n1;
    nodo2 = n2;
    cara1 = c1;
    cara2 = c2;
}

void Arco::setNodo1(int n1) {
    nodo1 = n1;
}

void Arco::setNodo2(int n2) {
    nodo2 = n2;
}

void Arco::setNodos(int n1, int n2) {
    nodo1 = n1;
    nodo2 = n2;
}

void Arco::setCara1(int c1) {
    cara1 = c1;
}

void Arco::setCara2(int c2) {
    cara2 = c2;
}

void Arco::setCara(int c){
    if(cara1==c || cara2==c)
        return;

    if (cara1==-1)
        cara1=c;
    else if (cara2==-1)
        cara2=c;
    }

void Arco::setCaras(int c1, int c2) {
    cara1 = c1;
    cara2 = c2;
}

int Arco::getNodo1() {
    assert(this != 0);
    return nodo1;
}

int Arco::getNodo2() {
    assert(this != 0);
    return nodo2;
}

int Arco::getCara1() {
    assert(this != 0);
	//cerr << "cara1=" << cara1 << endl;
    return cara1;
}

int Arco::getCara2() {
    assert(this != 0);
	//cerr << "cara2=" << cara2 << endl;
    return cara2;
}

int Arco::getNodoDistinto(int n){
	if (n==nodo1)
		return nodo2;
	if (n==nodo2)
		return nodo1;
	else
		return -1;
	}

bool Arco::estanNodos(vector<int> nodos){
    if (find(nodos.begin(),nodos.end(),nodo1)==nodos.end())
        return false;
    if (find(nodos.begin(),nodos.end(),nodo2)==nodos.end())
        return false;
    return true;
    }

void Arco::imprimir() {
    cout << "Arco: nodo1=" << nodo1 << " nodo2=" << nodo2 << "; cara1=" << cara1 << " cara2=" << cara2 << endl;
}
