#include "mejorar.h"
#include "mejdelaunay.h"

Mejorar::Mejorar(Malla *m) : Comando(m) {
    algoritmo = new MejDelaunay();
}

void Mejorar::execute() {
    algoritmo->aplicar(malla);
}

Mejorar::~Mejorar(){
	delete algoritmo;
	}
