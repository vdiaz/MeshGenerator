#ifndef ALGGENERACION_H
#define ALGGENERACION_H

#include "malla.h"
#include <cstdio>
#include <cstring>

/**
@author Ricardo Medina Diaz
Interfaz para los algoritmos de generación de la malla del objeto a modelar
 */
class AlgGeneracion {
    public:
        virtual Malla* aplicar() = 0;
		virtual ~AlgGeneracion(){}
};

#endif
