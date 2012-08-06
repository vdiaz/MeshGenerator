#ifndef DELAUNAYLONGESTEDGEBISECTION_H
#define DELAUNAYLONGESTEDGEBISECTION_H

#include "algrefinamiento.h"

/**
@author Nicolas Silva Herrera
algoritmo Delaunay Longest Edge Bisection de refinación de las mallas
 */
class DelaunayLongestEdgeBisection : public AlgRefinamiento {
    public:
        void aplicar(Malla *malla, Criterio *criterio);
	private:
		void refine(Malla *malla, Criterio *criterio, int ind_cara);
};

#endif
