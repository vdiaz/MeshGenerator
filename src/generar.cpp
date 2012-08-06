#include "config.h"
#include "generar.h"

#ifdef CARGAR_OFF
#include "generafromoff.h"
#endif

#ifdef CARGAR_XYZU
#include "generafromarchivosxyzu.h"
#endif

#ifdef CARGAR_MATLAB
#include "generafrommatlab.h"
#endif

#ifdef CARGAR_COMSOL
#include "generafromcomsol_1.h"
#endif

#ifdef GENERAR_CILINDRO
#include "generacilindro.h"
#endif

#ifdef GENERAR_MEDULA
#include "generafrommedula.h"
#endif

Generar::Generar(int tipoFiltro, list<string> filenames, int numeroDeAnillos, int puntosPorAnillo, int tipoMalla):Comando(0){
    algoritmo=NULL;

	if (tipoFiltro==0){
#ifdef CARGAR_OFF
		list<string>::iterator iter=filenames.begin();
		string filename=*iter;
		algoritmo=new GeneraFromOFF(filename);
#endif
		}
	else if (tipoFiltro==1){
#ifdef CARGAR_MATLAB
		list<string>::iterator iter=filenames.begin();
		string filename=*iter;
		algoritmo=new GeneraFromMatLab(filename, numeroDeAnillos, puntosPorAnillo, tipoMalla);
#endif
		}
	else if (tipoFiltro==2){
#ifdef CARGAR_XYZU
		list<string>::iterator iter=filenames.begin();
		string filename1=*iter;
		iter++;
		string filename2=*iter;
		iter++;
		string filename3=*iter;
		iter++;
		string filename4=*iter;
		algoritmo=new GeneraFromArchivosXYZU(filename1, filename2, filename3, filename4);
#endif
		}
	else if (tipoFiltro==3){
#ifdef CARGAR_COMSOL
		list<string>::iterator iter=filenames.begin();
		string filename=*iter;
		algoritmo=new GeneraFromComsol_1(filename);
#endif
		}

	assert(algoritmo);
	}

Generar::Generar (int tipo, int altura, int radio, int numeroDeAnillos, int puntosPorAnillo, int tipoMalla):Comando(0){
	algoritmo=NULL;

	if (tipo==10) {
#ifdef GENERAR_CILINDRO
		algoritmo=new GeneraCilindro(altura,radio,numeroDeAnillos,puntosPorAnillo,tipoMalla);
#endif
	}

	assert(algoritmo);
	}

Generar::Generar(int tipo, string filename, int radio, int numeroDeAnillos,int puntosPorAnillo):Comando(0){
    algoritmo=NULL;

	if (tipo==20) {
#ifdef GENERAR_MEDULA
		algoritmo=new GeneraFromMedula(filename,radio,numeroDeAnillos,puntosPorAnillo);
#endif
	}

	assert(algoritmo);
    }

void Generar::execute() {
    this->malla = algoritmo->aplicar();
}

Generar::~Generar(){
	delete algoritmo;
	}
