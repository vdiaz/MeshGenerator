#include "config.h"
#include "refinar.h"

#ifdef REFINAR_ALG_LEPPDELAUNAY
#include "leppdelaunay.h"
#endif

#ifdef REFINAR_ALG_LONGESTEDGE
#include "delaunaylongestedgebisection.h"
#endif

#ifdef REFINAR_CRITERIO_ANGULOMIN
#include "angulominimo.h"
#endif

#ifdef REFINAR_CRITERIO_AREAMAX
#include "areacara.h"
#endif

#ifdef REFINAR_CRITERIO_LARGOMAX
#include "largoarcomaximo.h"
#endif

Refinar::Refinar(Malla *m, int algoritmo, int criterio, double valorCriterio): Comando(m) {
    assert(m);

	this->algoritmo=NULL;
	this->criterio=NULL;

	if(algoritmo==0) {
#ifdef REFINAR_ALG_LEPPDELAUNAY
		this->algoritmo=new LeppDelaunay();
#endif
	}
	else if(algoritmo==1) {
#ifdef REFINAR_ALG_LONGESTEDGE
		this->algoritmo=new DelaunayLongestEdgeBisection();
#endif
	}

	if (criterio==0) {
#ifdef REFINAR_CRITERIO_ANGULOMIN
		this->criterio=new AnguloMinimo(valorCriterio);
#endif
	}
	else if (criterio==1) {
#ifdef REFINAR_CRITERIO_AREAMAX
		this->criterio=new AreaCara(valorCriterio);
#endif
	}
	else if (criterio==2) {
#ifdef REFINAR_CRITERIO_LARGOMAX
		this->criterio=new LargoArcoMaximo(valorCriterio);
#endif
	}

	assert(this->algoritmo && this->criterio);
	}

void Refinar::execute() {
    algoritmo->aplicar(malla,criterio);
	}

Refinar::~Refinar(){
	delete algoritmo;
	delete criterio;
	}
