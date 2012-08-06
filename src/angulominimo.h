#ifndef ANGULOMINIMO_H
#define ANGULOMINIMO_H

#include "criterio.h"

/**
@author Ricardo Medina Diaz
 */
class AnguloMinimo : public Criterio {
    public:
    private:
        double min;
    public:
        AnguloMinimo(double min);
        bool seCumple(Malla *malla, int indice);

};

#endif
