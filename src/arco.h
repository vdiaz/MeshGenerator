#ifndef ARCO_H
#define ARCO_H

#include <iostream>
#include <vector>
#include <iterator>
#include <cassert>
#include <algorithm>

using namespace std;

/**
@author Ricardo Medina Diaz
Esta clase representa un arco, el cual está formado por 2 índices a un conjunto de puntos
 */
class Arco {
    private:
        int nodo1; // indice al primer nodo que define el arco
        int nodo2; // indice al segundo nodo que define el arco
        int cara1; // indice a una de las caras que tiene este arco
        int cara2; // indice a la otra cara que tiene este arco
    public:
        Arco();
        Arco(int n1, int n2);
        Arco(int n1, int n2, int c1, int c2);

        // setters y getters:
        void setNodo1(int n1);
        void setNodo2(int n2);
        void setNodos(int n1, int n2);
        void setCara1(int c1);
        void setCara2(int c2);
        void setCara(int c); //inserta la cara en el espacio desocupado, cara1 o cara2
        void setCaras(int c1, int c2);
        int getNodo1();
        int getNodo2();
        int getCara1();
        int getCara2();
		int getNodoDistinto(int n);	//Entrega el nodo diferente al que se le paso como argumento
		bool estanNodos(vector<int> nodos); //Retorna true si dentro de la lista estan los nodos que componen el arco.

        // imprime los indices
        void imprimir();
};

#endif
