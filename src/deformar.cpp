#include "config.h"
#include "deformar.h"

#ifdef DEFORMAR_ALG_SINVERIFICACION
#include "noverificacion.h"
#endif

#ifdef DEFORMAR_ALG_CONSLOCAL
#include "verificacionlocal.h"
#endif

#ifdef DEFORMAR_ALG_NODOSVECINOS
#include "verificacionnodosvecinos.h"
#endif

Deformar::Deformar(Malla *m, int tipoVerificaciones, double porcentajeAMover) : Comando(m) {
    this->algoritmo = NULL;

	if (tipoVerificaciones==0) {
#ifdef DEFORMAR_ALG_SINVERIFICACION
		this->algoritmo=new NoVerificacion(porcentajeAMover);
#endif
	}
	else if (tipoVerificaciones==1) {
#ifdef DEFORMAR_ALG_CONSLOCAL
		this->algoritmo=new VerificacionLocal(porcentajeAMover);
#endif
	}
	else if (tipoVerificaciones==2) {
#ifdef DEFORMAR_ALG_NODOSVECINOS
		this->algoritmo=new VerificacionNodosVecinos(porcentajeAMover);
#endif
	}

	assert(algoritmo);
	}

void Deformar::execute() {
    algoritmo->aplicar(malla);
	}

Deformar::~Deformar(){
	delete algoritmo;
	}
