#ifndef CARA_H
#define CARA_H

#include <cassert>
#include <vector>

using namespace std;

/**
@author Ricardo Medina Diaz
Esta clase representa una cara del objeto a modelar. Posee una lista de indices a los puntos que
forman la cara, y una lista de indices a los arcos que forman la cara.
 */
class Cara {
    private:
        vector<int> ind_nodos; // Lista de indices a los nodos de la cara (no necesariamente en orden de la mano derecha)
        vector<int> ind_arcos; // Lista de indices a los arcos de la cara (no necesariamente en orden de la mano derecha)
        int num_elem; // Numero de puntos y arcos de la cara
        float rgb[3]; // color de la cara al visualizarla
    public:
        Cara(int n1, int n2, int n3, int a1, int a2, int a3); // crea una cara con 3 elementos --> un triángulo
        Cara(int n1, int n2, int n3);
        Cara(vector<int> ind_pts, vector<int> ind_arcs); // crea una cara con la lista de índices dados
        void setNodos(vector<int> nds); // set de la lista de nodos
        void addNodo(int nodo); // se inserta el nodo solo si no esta insertado antes
        void eraseNodo(int nodo); // borra el nodo si esta.
        void changeNodo(int nodo_sale, int nodo_entra); // cambia el indice nodo_sale por el indice nodo_entra. Si no encuentro nodo_sale no hago nada.
        void changeArco(int arco_sale, int arco_entra);
		vector<int> getNodos(); // get de la lista de nodos
        void setArcos(vector<int> ars); // set de la lista de arcos
        void addArco(int arco); // se inserta el arco solo si no esta insertado antes
        void eraseArco(int arco); // borra la cara si esta.
        vector<int> getArcos(); // get de la lista de arcos
        int getPuntoDistinto(int p1, int p2); // solo para una cara triangular, retorna el indice que es distinto a los indices pasados como parametros.
        vector<int> getPuntosDistintos(int p1); // solo para una cara triangular, retorna los indices que son distintos al indice pasado como parametro.
		int getNumElem(); // get del numero de elementos de la cara (numero de vertices o arcos)
        void setColores(float r, float g, float b); // set de los colores.
        float getR();
        float getG();
        float getB();
};

#endif
