#include "almacenatoxyzu.h"

#include <sstream>

AlmacenaToXYZU::AlmacenaToXYZU():AlgAlmacenamiento(){

	}


void AlmacenaToXYZU::aplicar(Malla *malla, string filename){
	//Lineas necesarias para que scanf lea archivo en computadores seteados en otro lenguaje.
	setlocale(LC_NUMERIC, "POSIX");

	int posextension=filename.rfind(".");
	string nombrefile=filename.substr(0,posextension);
	string extension=filename.substr(posextension+1,filename.length());

	if (posextension==0){
		nombrefile=filename;
		extension="txt";
		}


	stringstream archivox;
	stringstream archivoy;
	stringstream archivoz;
	stringstream archivou;

	archivox << nombrefile << "_nx." << extension;
	archivoy << nombrefile << "_ny." << extension;
	archivoz << nombrefile << "_nz." << extension;
	archivou << nombrefile << "_u." << extension;

	FILE *archivo_x = fopen(archivox.str().c_str(),"w");
	FILE *archivo_y = fopen(archivoy.str().c_str(),"w");
	FILE *archivo_z = fopen(archivoz.str().c_str(),"w");
	FILE *archivo_u = fopen(archivou.str().c_str(),"w");

	char separador1[32] = "% Coordinates\n";
    fprintf(archivo_x,"%s",separador1);
    fprintf(archivo_y,"%s",separador1);
    fprintf(archivo_z,"%s",separador1);
    fprintf(archivo_u,"%s",separador1);

    Nodos *nds = malla->getNodos();
    Caras *crs = malla->getCaras();

    Nodo *nodo;
	int* nuevoIndiceNodos=new int[nds->getNumNodos()];
	int nlinea=0;
    for(int i=0; i<nds->getNumNodos(); i++) {
        nodo = nds->getNodo(i);
        if(nodo != NULL) {
            fprintf(archivo_x,"%f   %f  %f\n",nodo->getPunto()->getX(),nodo->getPunto()->getY(),nodo->getPunto()->getZ());
            fprintf(archivo_y,"%f   %f  %f\n",nodo->getPunto()->getX(),nodo->getPunto()->getY(),nodo->getPunto()->getZ());
            fprintf(archivo_z,"%f   %f  %f\n",nodo->getPunto()->getX(),nodo->getPunto()->getY(),nodo->getPunto()->getZ());
            fprintf(archivo_u,"%f   %f  %f\n",nodo->getPunto()->getX(),nodo->getPunto()->getY(),nodo->getPunto()->getZ());
        	nuevoIndiceNodos[i]=nlinea;
			nlinea++;
		}
    }
    char separador2[32] = "% Elements (triangular)\n";
    fprintf(archivo_x,"%s",separador2);
    fprintf(archivo_y,"%s",separador2);
    fprintf(archivo_z,"%s",separador2);
    fprintf(archivo_u,"%s",separador2);

    Cara *c;
    vector<int> ind_nodos;
    for(int i=0; i<crs->getNumCaras(); i++) {
        c = crs->getCara(i);
        if(c != 0) {
            ind_nodos = c->getNodos();
            fprintf(archivo_x,"%d   %d  %d\n",nuevoIndiceNodos[ind_nodos[0]]+1,nuevoIndiceNodos[ind_nodos[1]]+1,nuevoIndiceNodos[ind_nodos[2]]+1);
            fprintf(archivo_y,"%d   %d  %d\n",nuevoIndiceNodos[ind_nodos[0]]+1,nuevoIndiceNodos[ind_nodos[1]]+1,nuevoIndiceNodos[ind_nodos[2]]+1);
			fprintf(archivo_z,"%d   %d  %d\n",nuevoIndiceNodos[ind_nodos[0]]+1,nuevoIndiceNodos[ind_nodos[1]]+1,nuevoIndiceNodos[ind_nodos[2]]+1);
			fprintf(archivo_u,"%d   %d  %d\n",nuevoIndiceNodos[ind_nodos[0]]+1,nuevoIndiceNodos[ind_nodos[1]]+1,nuevoIndiceNodos[ind_nodos[2]]+1);

        }
    }

    char separador_x[32] = "% Data (nx)\n";
    char separador_y[32] = "% Data (ny)\n";
    char separador_z[32] = "% Data (nz)\n";
    char separador_u[32] = "% Data (u)\n";

    fprintf(archivo_x,"%s",separador_x);
    fprintf(archivo_y,"%s",separador_y);
    fprintf(archivo_z,"%s",separador_z);
    fprintf(archivo_u,"%s",separador_u);

    for(int i=0; i<nds->getNumNodos(); i++) {
        nodo = nds->getNodo(i);
//         cout << nodo->imprimir() << endl;
        if(nodo != NULL) {
            fprintf(archivo_x,"%f\n",nodo->getNormal()->getPunto().getX());
            fprintf(archivo_y,"%f\n",nodo->getNormal()->getPunto().getY());
            fprintf(archivo_z,"%f\n",nodo->getNormal()->getPunto().getZ());
            fprintf(archivo_u,"%f\n",nodo->getConcentracion());
        }
    }

	delete nuevoIndiceNodos;

    fclose(archivo_x);
    fclose(archivo_y);
    fclose(archivo_z);
    fclose(archivo_u);

	setlocale(LC_NUMERIC, "");
	}
