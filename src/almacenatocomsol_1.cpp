#include "almacenatocomsol_1.h"

AlmacenaToComsol_1::AlmacenaToComsol_1():AlgAlmacenamiento(){

	}


void AlmacenaToComsol_1::aplicar(Malla *malla, string filename){
	//Lineas necesarias para que scanf lea archivo en computadores seteados en otro lenguaje.
	setlocale(LC_NUMERIC, "POSIX");
	
	FILE *archivo_x = fopen(filename.c_str(),"w");
	
	char separador1[32] = "% Coordinates\n";
    fprintf(archivo_x,"%s",separador1);
    
    Nodos *nds = malla->getNodos();
    Caras *crs = malla->getCaras();
    
    Nodo *nodo;
	int* nuevoIndiceNodos=new int[nds->getNumNodos()];
	int nlinea=0;
    for(int i=0; i<nds->getNumNodos(); i++) {
        nodo = nds->getNodo(i);
        if(nodo != NULL) {
            fprintf(archivo_x,"%f   %f  %f\n",nodo->getPunto()->getX(),nodo->getPunto()->getY(),nodo->getPunto()->getZ());
        	nuevoIndiceNodos[i]=nlinea;
			nlinea++;
		}
    }
    char separador2[32] = "% Elements (triangular)\n";
    fprintf(archivo_x,"%s",separador2);
    
    Cara *c;
    vector<int> ind_nodos;
    for(int i=0; i<crs->getNumCaras(); i++) {
        c = crs->getCara(i);
        if(c != 0) {
            ind_nodos = c->getNodos();
			//Nota: Se invierte el orden de insercion de los puntos, para que las normales queden seteadas correctamente.
			//ya que en el archivo cms_1 los nodos estan al reves, dejando las normales hacia adentro.
            fprintf(archivo_x,"%d   %d  %d\n",nuevoIndiceNodos[ind_nodos[2]]+1,nuevoIndiceNodos[ind_nodos[1]]+1,nuevoIndiceNodos[ind_nodos[0]]+1);
        }
    }
    
	delete nuevoIndiceNodos;
    
    fclose(archivo_x);
	
	setlocale(LC_NUMERIC, "");
	}
