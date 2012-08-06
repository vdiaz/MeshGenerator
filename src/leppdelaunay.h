#ifndef LEPPDELAUNAY_H
#define LEPPDELAUNAY_H

#include "algrefinamiento.h"

/**
@author Nicolas Silva Herrera
algoritmo Lepp-Delaunay de refinación de las mallas
 */
class LeppDelaunay : public AlgRefinamiento {
    public:
        void aplicar(Malla *malla, Criterio *criterio);
	private:
		void BoundaryEdgePointInsertion(Malla* malla, int ind_arco);
		void TerminalEdgePointInsertion(Malla* malla, int ind_arco);
		void PointInsertion(Malla* malla, int ind_cara);
		void Improve(Malla* malla, int ind_cara);
};

#endif
