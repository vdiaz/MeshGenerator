#ifndef MEJDELAUNAY_H
#define MEJDELAUNAY_H

#include "algmejoramiento.h"

/**
@author Ricardo Medina Diaz
 * Algoritmo que mejora la malla maximizando el ángulo mínimo de las caras mediante flips de arcos
 */
class MejDelaunay : public AlgMejoramiento {
    public:
        MejDelaunay();
        void aplicar(Malla *malla);
};

#endif
