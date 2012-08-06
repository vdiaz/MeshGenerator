#include "nodo.h"

Nodo::Nodo() {
    this->p = new Punto(0,0,0);
    normal = 0;
    concentracion = 0;
    esBordeSuperior=false;
    esBordeInferior=false;
}

Nodo::Nodo(Punto *p) {
    this->p = p;
    normal = 0;
    concentracion = 0;
    esBordeSuperior=false;
    esBordeInferior=false;
}

void Nodo::setPunto(Punto *p) {
    this->p = p;
}

Punto* Nodo::getPunto() {
    return p;
}

/*void Nodo::setNormal(Vect *n) {
    //le seteamos una normal unitaria, su módulo esta dado por la concentración.
    n->normalizar();
    normal = n;
}*/

void Nodo::setNormal(Vect n){
    n.normalizar();
    this->normal=new Vect(n.getPunto().getX(),n.getPunto().getY(),n.getPunto().getZ());
    }

Vect* Nodo::getNormal() {
    if(normal != 0) {
        return normal;
    }
    else {
        return new Vect(0,0,0);
    }
}

void Nodo::setConcentracion(double con) {
    concentracion = con;
}

double Nodo::getConcentracion() {
    return concentracion;
}

void Nodo::setCaras(vector<int> crs) {
    caras = crs;
}

vector<int> Nodo::getCaras() {
    return caras;
}

void Nodo::setArcos(vector<int> ars) {
    arcos = ars;
}

vector<int> Nodo::getArcos() {
    return arcos;
}

void Nodo::addCara(int cara) {
    //si es menor que cero no la agregamos
    if(cara < 0) {
        return;
    }
    //si ya estaba tampoco la agregamos
    for(int i=0; i<(int)caras.size(); i++) {
        if(caras[i] == cara) {
            return;
        }
    }
    caras.push_back(cara);
}

void Nodo::eraseCara(int cara) {
    vector<int>::iterator iter;
    for(iter=caras.begin(); iter!=caras.end(); iter++) {
        if(*iter == cara) {
            iter = caras.erase(iter);
            return;
        }
    }
}

void Nodo::addArco(int arco) {
    //si es menor que cero no lo agregamos
    if(arco < 0) {
        return;
    }
    //si ya estaba tampoco lo agregamos
    for(int i=0; i<(int)arcos.size(); i++) {
        if(arcos[i] == arco) {
            return;
        }
    }
    arcos.push_back(arco);
}

void Nodo::eraseArco(int arco) {
    vector<int>::iterator iter;
    for(iter=arcos.begin(); iter!=arcos.end(); iter++) {
        if(*iter == arco) {
            iter = arcos.erase(iter);
            return;
        }
    }
}

void Nodo::addProbabilidadArco(double probabilidad, int indArco){
    int i;
    for (i=0; i<(int)arcos.size(); i++)
        if(indArco==arcos[i])
            break;

    if ((int)probabilidadArcos.size()<i+1)
        probabilidadArcos.resize(i+1);

    probabilidadArcos[i]=probabilidad;
    }

vector<double> Nodo::getProbabilidadArcos(){
    return probabilidadArcos;
    }

void Nodo::normalizarProbabilidades(){
    double suma=0;
    for (int i=0; i<(int)probabilidadArcos.size(); i++)
        suma=suma+probabilidadArcos[i];

    for (int i=0; i<(int)probabilidadArcos.size(); i++)
        probabilidadArcos[i]=probabilidadArcos[i]/suma;
    }

void Nodo::imprimir() {
    if(this != 0) {
        cout << "Punto(" << (*p)[0] << "," << (*p)[1] << "," << (*p)[2] << ")" << endl;
    }
    else {
        cout << "Punto nulo" << endl;
    }
}

Nodo::~Nodo(){
	delete p;
	delete normal;
	}
