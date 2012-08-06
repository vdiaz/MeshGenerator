#include "config.h"
#include "guardar.h"

#ifdef GUARDAR_OFF
#include "almacenatooff.h"
#endif

#ifdef GUARDAR_XYZU
#include "almacenatoxyzu.h"
#endif

#ifdef GUARDAR_COMSOL
#include "almacenatocomsol_1.h"
#endif

Guardar::Guardar(Malla *m, int formato, string filename) : Comando(m) {
    algoritmo=NULL;
	this->filename=filename;

	if (formato==0) {
#ifdef GUARDAR_OFF
		algoritmo = new AlmacenaToOff();
#endif
	}
	else if (formato==2) {
#ifdef GUARDAR_XYZU
		algoritmo = new AlmacenaToXYZU();
#endif
	}
	else if (formato==3) {
#ifdef GUARDAR_COMSOL
		algoritmo = new AlmacenaToComsol_1();
#endif
	}

	assert(algoritmo);
	}

void Guardar::execute() {
    algoritmo->aplicar(malla, filename);
}

Guardar::~Guardar(){
	delete algoritmo;
	}
