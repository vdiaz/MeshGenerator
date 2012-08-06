#include "nodos.h"

Nodos::Nodos() {
    num_nodos = 0;
    num_nodos_validos = 0;
}

Nodos::Nodos(vector<Nodo*> nds) {
    num_nodos = nds.size();
    num_nodos_validos = nds.size();
    nodos = nds;
}

int Nodos::addNodo(Nodo* n) {
    // Si existe un indice en que haya un punto que fue borrado insertamos el punto ahi.
    if(borrados.size() > 0) {
        int ind = borrados[0];
        nodos[ind] = n;
        borrados.erase(borrados.begin());
        num_nodos_validos++; // actualizamos el numero de nodos validos
        return ind;
    }
    else {
        nodos.push_back(n); // agregamos el punto al contenedor.
        num_nodos++; // actualizamos el numero de nodos del contenedor
        num_nodos_validos++; // actualizamos el numero de nodos validos
        return (nodos.size()-1);
    }
}

void Nodos::eraseNodo(int indice) {
    assert((indice < (int)nodos.size()) && (indice >= 0));
    if(nodos[indice] != 0) {
		delete nodos[indice];
        nodos[indice] = 0;
        borrados.push_back(indice);
        num_nodos_validos--;
    }
}

Nodo* Nodos::getNodo(int indice) {
    assert((indice < (int)nodos.size()) && (indice >= 0));
    return nodos[indice];
}

Nodo* Nodos::operator[](int indice) {
    assert((indice < (int)nodos.size()) && (indice >= 0));
    return nodos[indice];
}

void Nodos::moverNodo(int indice, double dist) {
    if(indice == -1) {
        return;
    }
    if(indice >= (int)nodos.size() || indice < 0) {
        cout << "Error: Moviendo Nodo(" << indice << "). Numero de nodos = " << nodos.size() << endl;
        assert((indice < (int)nodos.size()) && (indice >= 0));
    }
    Nodo *n = nodos[indice];
    //movemos el nodo una distancia dist.
    if(n != 0) {
        Vect *normal = n->getNormal();
        if(normal != 0) {
            n->getPunto()->setX(n->getPunto()->getX()+normal->getPunto().getX()*dist);
            n->getPunto()->setY(n->getPunto()->getY()+normal->getPunto().getY()*dist);
            n->getPunto()->setZ(n->getPunto()->getZ()+normal->getPunto().getZ()*dist);
        }
    }
}

void Nodos::moverNodoSegunConcentracion(int indice, double val) {
    if(indice == -1) {
        return;
    }
    if(indice >= (int)nodos.size() || indice < 0) {
        cout << "Error: Moviendo Nodo(" << indice << "). Numero de nodos = " << nodos.size() << endl;
        assert((indice < (int)nodos.size()) && (indice >= 0));
    }
    Nodo *n = nodos[indice];
    //movemos el nodo una distancia dist.
    if(n != 0) {
        Vect *normal = n->getNormal();
        if(normal != 0) {
            n->getPunto()->setX(n->getPunto()->getX()+normal->getPunto().getX()*val*n->getConcentracion());
            n->getPunto()->setY(n->getPunto()->getY()+normal->getPunto().getY()*val*n->getConcentracion());
            n->getPunto()->setZ(n->getPunto()->getZ()+normal->getPunto().getZ()*val*n->getConcentracion());
        }
    }
}

void Nodos::regresarNodo(int indice, double dist) {
    if(indice == -1) {
        return;
    }
    if(indice >= (int)nodos.size() || indice < 0) {
        cout << "Error: Regresando Nodo(" << indice << "). Numero de nodos = " << nodos.size() << endl;
        assert((indice < (int)nodos.size()) && (indice >= 0));
    }
    Nodo *n = nodos[indice];
    //regresamos el nodo una distancia dist.
    if(n != 0) {
        Vect *normal = n->getNormal();
        if(normal != 0) {
            n->getPunto()->setX(n->getPunto()->getX()-normal->getPunto().getX()*dist);
            n->getPunto()->setY(n->getPunto()->getY()-normal->getPunto().getY()*dist);
            n->getPunto()->setZ(n->getPunto()->getZ()-normal->getPunto().getZ()*dist);
        }
    }
}

void Nodos::regresarNodoSegunConcentracion(int indice, double val) {
    if(indice == -1) {
        return;
    }
    if(indice >= (int)nodos.size() || indice < 0) {
        cout << "Error: Regresando Nodo(" << indice << "). Numero de nodos = " << nodos.size() << endl;
        assert((indice < (int)nodos.size()) && (indice >= 0));
    }
    Nodo *n = nodos[indice];
    //regresamos el nodo una distancia dist.
    if(n != 0) {
        Vect *normal = n->getNormal();
        if(normal != 0) {
            n->getPunto()->setX(n->getPunto()->getX()-normal->getPunto().getX()*val*n->getConcentracion());
            n->getPunto()->setY(n->getPunto()->getY()-normal->getPunto().getY()*val*n->getConcentracion());
            n->getPunto()->setZ(n->getPunto()->getZ()-normal->getPunto().getZ()*val*n->getConcentracion());
        }
    }
}

void Nodos::moverTodos(double dist) {
    for(int i=0; i<(int)nodos.size(); i++) {
        if(nodos[i] != 0) {
            cout << "Moviendo nodo = " << i << endl;
            moverNodo(i,dist);
        }
    }
}

void Nodos::moverTodosSegunConcentracion(double val) {
    for(int i=0; i<(int)nodos.size(); i++) {
        if(nodos[i] != 0) {
            moverNodo(i,val*nodos[i]->getConcentracion());
        }
    }
}

int Nodos::getNumNodos() {
    assert(num_nodos == (int)nodos.size()); // nos aseguramos que sean iguales
    return num_nodos;
}

int Nodos::getNumNodosValidos() {
    assert(num_nodos_validos == (int)nodos.size() - (int)borrados.size()); // nos aseguramos que sean iguales
    return num_nodos_validos;
}

void Nodos::addCaraNodo(int indice, int cara) {
    assert((indice < (int)nodos.size()) && (indice >= 0));
    nodos[indice]->addCara(cara);
}

void Nodos::addArcoNodo(int indice, int arco) {

    if((indice >= (int)nodos.size()) || (indice < 0)) {
        cout << "indice = " << indice << endl;
        cout << "nodos.size() = " << nodos.size() << endl;
        assert((indice < (int)nodos.size()) && (indice >= 0));
    }
    nodos[indice]->addArco(arco);
}

int Nodos::popNodoVacio(int indice) {
    assert((indice < (int)nodos.size()) && (indice >= 0));
    assert(nodos[indice] == 0);

    int ind_ultimo_nodo = num_nodos-1;
    // borramos los indices vacios que esten al final hascta llegar a un nodo no vacio
    while(nodos[ind_ultimo_nodo] == 0) {
        nodos.erase(nodos.begin()+ind_ultimo_nodo);
        ind_ultimo_nodo--;
    }
    nodos[indice] = nodos[ind_ultimo_nodo];
    nodos.erase(nodos.begin()+ind_ultimo_nodo);
    num_nodos = nodos.size();
    // el numero de nodos validos se mantiene

    //eliminados de borrados el indice
    for(int i=0; i<(int)borrados.size(); i++) {
        if(borrados[i] == indice) {
            borrados.erase(borrados.begin()+i);
        }
    }
    return ind_ultimo_nodo;
}

Nodos::~Nodos(){
	for (int i=0; i<(int)nodos.size(); i++)
		delete nodos[i];
	}
