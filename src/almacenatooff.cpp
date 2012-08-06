#include "almacenatooff.h"

AlmacenaToOff::AlmacenaToOff(){

	}

void AlmacenaToOff::aplicar(Malla *malla, string filename){
	//Lineas necesarias para que scanf lea archivo en computadores seteados en otro lenguaje.
	setlocale(LC_NUMERIC, "POSIX");
	
	FILE *archivoSalida = fopen(filename.c_str(),"w");
	fprintf(archivoSalida,"OFF\n");
    
    Nodos *nds = malla->getNodos();
    Arcos *arcs = malla->getArcos();
    Caras *crs = malla->getCaras();
    
    fprintf(archivoSalida,"%d %d %d\n",nds->getNumNodosValidos(),crs->getNumCarasValidas(),arcs->getNumArcosValidos());
    
    Nodo *nodo;
	int* nuevoIndiceNodos=new int[nds->getNumNodos()];
	int nlinea=0;
    for(int i=0; i<nds->getNumNodos(); i++) {
        nodo = nds->getNodo(i);
        if(nodo != NULL) {
            fprintf(archivoSalida,"%f %f %f\n",nodo->getPunto()->getX(),nodo->getPunto()->getY(),nodo->getPunto()->getZ());
        	nuevoIndiceNodos[i]=nlinea;
			nlinea++;
		}
    }
    
    Cara *c;
    vector<int> ind_nodos;
    vector<int> ind_arcos;
    for(int i=0; i<crs->getNumCaras(); i++) {
        c = crs->getCara(i);
        if(c != 0) {
            ind_nodos = c->getNodos();
            ind_arcos = c->getArcos();
            fprintf(archivoSalida,"%d ",c->getNumElem());
            double conc_prom = 0;
            for(int j=0; j<(int)ind_nodos.size(); j++) {
                conc_prom = conc_prom + nds->getNodo(ind_nodos[j])->getConcentracion();
                fprintf(archivoSalida,"%d ",nuevoIndiceNodos[ind_nodos[j]]);
            }
            fprintf(archivoSalida,"\n");
        }
    }
	
	delete nuevoIndiceNodos;
	
    fclose(archivoSalida);
	
	setlocale(LC_NUMERIC, "");
	}
