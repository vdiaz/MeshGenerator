#ifndef SEGTRIINT_H
#define SEGTRIINT_H

#include <vector>
#include "vect.h"
#include "segmenttriangleintersection.h"

using namespace std;

/**
@author Nicolas Silva Herrera
 Esta clase calcula la interseccion entre un segmento y un triangulo, adaptando de la clase
 SegmentTriangleIntersection.
 */
class SegTriInt {
    public:
		tPointi T;
		tPointd q;
		tPointd r;
		tPointd p;
		
		SegmentTriangleIntersection* segmenttriangleintersection;
        SegTriInt(Vect** T,Vect* q,Vect* r);
		char aplicar();
		~SegTriInt();
};

#endif
