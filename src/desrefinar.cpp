#include "config.h"
#include "desrefinar.h"

#include "desrefinamientoedgecollapse.h"

#ifdef DESREFINAR_CRITERIO_AREAMIN
#include "areacara.h"
#endif

#ifdef DESREFINAR_CRITERIO_LARGOMIN
#include "largoarcominimo.h"
#endif

Desrefinar::Desrefinar(Malla *m, int algoritmo, int criterio, double valorCriterio): Comando(m) {
    assert(m);

	this->algoritmo=NULL;
	this->criterio=NULL;

	if(algoritmo==0)
		this->algoritmo=new DesrefinamientoEdgeCollapse();

	if (criterio==1) {
#ifdef DESREFINAR_CRITERIO_AREAMIN
		this->criterio=new AreaCara(valorCriterio);
#endif
	}
	else if (criterio==2) {
#ifdef DESREFINAR_CRITERIO_LARGOMIN
		this->criterio=new LargoArcoMinimo(valorCriterio);
#endif
	}

	assert(this->algoritmo && this->criterio);
	}

void Desrefinar::execute() {
    algoritmo->aplicar(malla,criterio);
	}

Desrefinar::~Desrefinar(){
	delete algoritmo;
	delete criterio;
	}
