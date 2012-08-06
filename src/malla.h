#ifndef MALLA_H
#define MALLA_H

#include "definiciones.h"

#include "nodo.h"
#include "nodos.h"
#include "arco.h"
#include "arcos.h"
#include "cara.h"
#include "caras.h"
#include "polinomio.h"

/**
@author Nicolas Silva Herrera
Esta clase representa una malla, la cual esta compuesta por Nodos, Arcos y Caras.
 */
class Malla{
    private:
        Nodos *nodos; // conjunto de nodos de la malla.
        Arcos *arcos; // conjunto de arcos de la malla.
        Caras *caras; // conjunto de caras de la malla.
        vector<Punto> medula;
        //bool show_arcos; // indica si se muestran los arcos al visualizar la malla.
        //bool show_caras; // indica si se muestran las caras al visualizar la malla.
        //bool show_concentracion; // indica si se muestra cada cara con un color de acuerdo a su concentración.
        bool show_nodos_destacados; //indica si se deben destacar los nodos marcados como destacados.
		double concentracion_max; // indica la concentración máxima de los nodos de la malla.
        double concentracion_min; // indica la concentración mínima de los nodos de la malla.
		vector<int> nodosDestacados;	//Indica los indices de nodos que deben ser destacados en la visualizacion

    public:
        // construtores:
        Malla(Punto *p0, Punto *p1); // Malla simple, contiene 2 Nodos y 1 Arco (0 caras).
        Malla(Punto *p0, Punto *p1, Punto *p2); // Malla que contiene 1 triángulo (3 Nodos, 3 Arcos y 1 Cara);
        Malla(Punto *p0, Punto *p1, Punto *pc0, Punto *pc1); // Malla que contiene 2 triángulo contigüos (4 Nodos, 5 Arcos y 2 Cara);
        Malla(Nodos *nds, Arcos *arcs, Caras *crs); // Malla con esos Nodos, Arcos y Caras.

        // setters y getters:
        void setConcentracionMax(double max);
        double getConcentracionMax();
        void setConcentracionMin(double min);
        double getConcentracionMin();
        Nodos* getNodos();
        Arcos* getArcos();
        Caras* getCaras();
        Nodo* getNodo(int ind_nodo); // get del nodo en ese indice.
        Arco* getArco(int ind_arco); // get del arco en ese indice.
        Cara* getCara(int ind_cara); // get de la cara en ese indice.
		void setNodoDestacado(int indNodo);	//setea un nodo para ser destacado en la visualizacion
		vector<int>* getNodosDestacados();
		void clearNodosDestacados();
		void setMedula(vector<Punto> medula);
		vector<Punto> getMedula();

        // métodos arcos:
        double getLargoArco(int ind_arco);
        Punto* getPuntoMedioArco(int ind_arco);
        double getAnguloArco(int ind_arco); // retorna el angulo entre las caras que comparte el arco
        bool esArcoBorde(int ind_arco);
        bool esAnguloDiedro(int ind_arco, double anguloDiedroMax);	//Retorna true si el angulo diedro entre las dos caras que comparten el arco es mayor que anguloDiedroMax.
        bool esArcoConcavo(int ind_arco);
        bool esArcoFijo(int ind_arco); // Que sea fijo significa que no se puede realizar un flip sobre ese arco.
        bool esNodoBorde(int indNodo); //Indice si el nodo esta en un borde de la malla.

        // métodos caras:
        double getArea(int ind_cara); // retorna el área de la cara en el índice.
		double getPerimetro (int indCara);	//retorna el perimetro de la cara en el indice.
        double getAnguloVertice(int ind_cara, int ind_nodo); // retorna el ángulo en la cara ind_cara y el nodo ind_nodo.
        double getAnguloMin(int ind_cara); // retorna el ángulo mínimo de la cara en el índice
        double getAnguloMax(int ind_cara); // retorna el ángulo máximo de la cara en el índice
        vector<int> getArcosAnguloMin(int ind_cara); // retorna los índices de los 2 arcos que forman el ángulo mínimo de la cara
        int getNodoAnguloMin(int ind_cara); // retorna el índice del nodo que es vértice del ángulo min.
        Vect getNormal(int ind_cara); // retorna el vector normal de esa cara
        double getAnguloCaras(int ind_cara1, int ind_cara2); // retorna el ángulo entre las caras
        int getArcoMasLargo(int ind_cara); // retorna el indice del arco mas largo en la cara ind_cara.
        int getArcoMasCorto(int ind_cara); // retorna el indice del arco mas corto en la cara ind_cara.
        bool sonCarasVecinas(int ind_cara1, int ind_cara2);
        bool esCaraBorde(int ind_cara);
        vector<int> getArcosBordeCara(int ind_cara);

        // transformaciones:
        int edgeFlip(int ind_arco); // realiza un flip o swap, retorna el índice del nuevo arco
        vector<int> edgeSplit(int ind_arco, double dist, int retorna=0); // inserta un punto en ind_arco a una distancia dist desde el primer punto del arco. dist debe ser entre 0 y 1. Por ejemplo si dist=0.5 inserta un punto en la mitad del arco. Retorna los indices de los nuevos arcos agregados a la malla. Retorna=0, por defecto retorna los nuevos arcos. Retorna=1, retorna las nuevas caras. Retorna=2, retorna el nuevo nodo.
        int edgeCollapse(int ind_arco, double dist); // reduce el arco a un punto. dist es para ver en que parte del arco queda el punto. Por ejemplo si dist=0.5 el punto queda en la mitad del arco.
        int vertexDeletion(int indArcoAColapsar, int indVerticeABorrar);	//Metodo que sustituira a edgeCollapse. Colapsa un Arco eliminando un vertice.
		int edgeCollapse2(int ind_arco, double dist);	//Reimplementacion de EdgeCollapse.

        // obtencion de indices:
        int getSiguienteCara(int indice, int ind_cara); // retorna la cara vecina de la cara ind_cara por el arco indice
        int getArcoOpuestoNodo(int ind_cara, int ind_nodo); // retorna el o los indice del o los arcos opuestos al nodo ind_nodo, en la cara ind_cara (Si la cara tiene 3 lados es un solo arco, asi que por el momento retorno solo un indice, despues se puede generalizar)
        int getNodoOpuestoNodo(int ind_cara, int ind_nodo); // retorna el o los indices del o los nodos opuestos al nodo ind_nodo por las cara ind_cara (Si la cara tiene 3 lados es un solo nodo, asi que por el momento retorno solo un indice, despues se puede generalizar)
        int getNodoOpuestoArco(int ind_cara, int ind_arco); // dado una cara y una arco de esa misma cara, retorna el nodo perteneciente a esa cara y que no pertenece a ese arco. (Si la cara tiene 3 lados es un solo nodo, asi que por el momento retorno solo un indice, despues se puede generalizar).
        int getCaraOpuestaNodo(int ind_cara, int ind_nodo); // dada una cara y un nodo de esa cara, retorna el indice de la cara vecina a la cara dada que esta opuesta al nodo dado. (Si la cara tiene 3 lados es una sola cara, asi que por el momento retorno solo un indice, despues se puede generalizar).

        // otros métodos:
        void setNormales(); // setea las normales de cada punto perteneciente a la malla como el promedio de las normales de las caras adyacentes al punto.
        void setNormal(int ind_nodo, Vect normal); // setea la normal de ese nodo.
        void setConcentracionTodos(double val); // setea la concentración de cada nodo con valor val
        Vect getNormalNodos(int ind_p1, int ind_p2, int ind_p3); // retorna la normal al plano formado por los 3 puntos pasados como parametro.
        int checkMalla();	//Chequea que la malla sea consistente. Que no hayan punteros al vacio.
		int checkCara(int indCara);
		int checkArco(int indArco);
		int checkNodo(int indNodo);

        // métodos dirigidos al desplazamiento de la malla:
        vector<double> getValoresVolumenCero(int ind_arco);
        int getTipoMovRegion(int ind_arco, double val); // movemos los puntos pertenecientes a la region y vemos que tipo de region es. Luego volvemos los puntos a donde estaban y retornamos el tipo de la region.
        int tipArco(int ind_arco);
        int puntoInCara(Punto *p, int ind_cara); // ve si el punto p esta dentro de la cara o no. Una pre-condicion es que el punto pertenesca al plano que forma la cara.
        int seCruzan(Punto *p1_arco1, Punto *p2_arco1, Punto *p1_arco2, Punto *p2_arco2); // ve si los arcos se cruzan o no.
        void manejaInconsitenciaArco(int ind_arco);
        void manejaInconsistenciaArcoAntes(int ind_arco, double val);
        double valorInterseccion(Punto *p1_arco1, Punto *p2_arco1, Punto *p1_arco2, Punto *p2_arco2); // retorna el valor de interseccion segun el arco1, es decir, el punto de interseccion estara multiplicando el vector arco1 por el valor retornado. Los puntos deben estar en el mismo plano.

		// métodos Delaunay
		int isDelaunay(int ind_arco);	//Indica si el arco es Delaunay
		void makeDelaunay(int ind_arco);	//Aplica Delaunay al arco. Este metodo chequea antes si el arco es Delaunay.

		//Destructor
		~Malla();
};

#endif
