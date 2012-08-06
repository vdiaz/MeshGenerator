#ifndef DESREFINAMIENTOEDGECOLLAPSE_H
#define DESREFINAMIENTOEDGECOLLAPSE_H

#include "algdesrefinamiento.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <cassert>
#include <algorithm>

/**
@author Nicolas Silva Herrera
algoritmo de desrefinamiento basado en Edge Collapse
 */
class DesrefinamientoEdgeCollapse : public AlgDesrefinamiento {
    public:
        void aplicar(Malla *malla, Criterio *criterio);
	private:
		vector<int> excluidos;
		int desrefinar(Malla* malla, int indCara);

};

#endif
