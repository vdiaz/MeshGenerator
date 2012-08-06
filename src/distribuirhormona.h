#ifndef DISTRIBUIRHORMONA_H
#define DISTRIBUIRHORMONA_H

#include "comando.h"
#include "SimpleGLScene.hh"

class DistribuirHormona : public Comando
{
    public:
        DistribuirHormona(  Malla* malla,
                            SimpleGLScene* simpleglscene,
                            double factorgravitacional,
                            double factorlongitudinal,
                            double factortangencial
                            );
        void execute();
        ~DistribuirHormona();
    protected:
    private:
        SimpleGLScene* simpleglscene;
        double factorgravitacional;
        double factorlongitudinal;
        double factortangencial;

        Vect getVectorLongitudinal(double altura);
        double calcularProbabilidad(int indNodo, int indArco);  //Calcula la probabilidad de que indNodo vaya a indArco
        void paseoHormonas(); //Realiza el paseo al hazar de las hormonas y actualiza las concentraciones de acuerdo a eso.
        int paseoAlAzar(int indNodo);   //Retorna el indice al nodo donde continua el paseo.
};



#endif // DISTRIBUIRHORMONA_H
