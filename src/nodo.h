#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <vector>
#include <cassert>

#include "punto.h"
#include "vect.h"

using namespace std;

/**
@author Ricardo Medina Diaz
Esta clase se utiliza para la representación de un punto dentro de una malla
 */
class Nodo {
    private:
        Punto *p; // Punto en el espacio 3D que representa.
        Vect *normal; // Vector de desplazamiento del Punto.
        double concentracion; // Modulo del desplazamiento del nodo.
        vector<int> caras; // Lista de indices a las caras que tienen este nodo.
        vector<int> arcos; // Lista de indices a los arcos que tienen este nodo.
        vector<double> probabilidadArcos;   //Lista de probabilidad de que hormona se vaya al arco correspondiente.

    public:
        Nodo();
        Nodo(Punto *p);

        // getters y setters.
        void setPunto(Punto *p);
        Punto* getPunto();
        //void setNormal(Vect *n);
        void setNormal(Vect n);
        Vect* getNormal();
        void setConcentracion(double con);
        double getConcentracion();
        void setCaras(vector<int> crs);
        vector<int> getCaras();
        void setArcos(vector<int> ars);
        vector<int> getArcos();

        void addCara(int cara); // se agrega la cara a la lista de caras solo si no estaba insertada antes.
        void eraseCara(int cara); // borra la cara de la lista de caras solo si esta.
        void addArco(int arco); // se agrega el arco a la lista de arcos solo si no estaba insertado antes.
        void eraseArco(int arco); // borra el arco de la lista de arcos solo si esta.

        void addProbabilidadArco(double probabilidad, int indArco); //Agrega probabilidad de que hormona se vaya por indArco.
        vector<double> getProbabilidadArcos();  //Retorna el listado de probabilidades.
        void normalizarProbabilidades();    //Corrige las probabilidades para que sumen 1.
        bool esBordeSuperior;
        bool esBordeInferior;

        void imprimir(); // imprime a la salida estandar las coordenadas del Punto p.

		~Nodo();
};

#endif
