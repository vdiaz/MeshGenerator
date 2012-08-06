#ifndef GENERAFROMARCHIVOSXYZU_H
#define GENERAFROMARCHIVOSXYZU_H

#include <map>
#include <math.h>

#include "alggeneracion.h"

using namespace std;

/**
@author Ricardo Medina Diaz
 */
class GeneraFromArchivosXYZU : public AlgGeneracion
{
    public:
    private:
        string archivo_x;
        string archivo_y;
        string archivo_z;
        string archivo_u;
    public:
        GeneraFromArchivosXYZU(string arch_x, string arch_y, string arch_z, string arch_u);
        Malla* aplicar();
};

#endif
