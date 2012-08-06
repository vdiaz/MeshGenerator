#ifndef NOVERIFICACION_H
#define NOVERIFICACION_H

#include "algdesplazamiento.h"

/**
@author Ricardo Medina Diaz
 * Desplaza los elementos de la malla sin considerar su consistencia, solo hay cambios geométricos.
 */
class NoVerificacion : public AlgDesplazamiento {
    private:
        double val;
    public:
        NoVerificacion(double val);
        void aplicar(Malla *malla);
};

#endif
