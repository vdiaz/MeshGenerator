#include "delaunaylongestedgebisection.h"

void DelaunayLongestEdgeBisection::aplicar(Malla *malla, Criterio *criterio){
	Caras *caras = malla->getCaras();
    for(int i=0; i<caras->getNumCaras(); i++) {
        if(malla->getCara(i)!=NULL && !criterio->seCumple(malla,i)) {
            cout << "La cara(" << i << ") es mala" << endl;
            refine(malla,criterio,i);
            i = 0;
        	}
		}
	}

void DelaunayLongestEdgeBisection::refine(Malla *malla, Criterio* criterio, int ind_cara){
	int ind_arco=malla->getArcoMasLargo(ind_cara);
	malla->makeDelaunay(ind_arco);
	
	if(!criterio->seCumple(malla,ind_cara))
        //debemos dividir el arco, agregando un punto al centro.
        vector<int> nuevos_arcos = malla->edgeSplit(ind_arco,0.5);
	}

/*
void DelaunayLongestEdgeBisection::aplicar(Malla *malla, Criterio *criterio){
	//recorremos los arcos de la malla y vemos si cada arco cumple el criterio del largo
    for(int i=0; i<malla->getArcos()->getNumArcos(); i++)
        refinarArco(malla,criterio,i);
	}

void DelaunayLongestEdgeBisection::refinarArco(Malla *malla, Criterio* criterio, int ind_arco){
	Arcos *arcos = malla->getArcos();
    assert(ind_arco >= 0 && ind_arco < arcos->getNumArcos());
    if(arcos->getArco(ind_arco) == 0) {
        cout << "arco vacio" << endl;
        return;
    }
    
    if(!malla->esArcoFijo(ind_arco,ANGULO_DIEDRO)) {
        // Obtenemos los indices que necesitamos.
        // Indices de las caras
        int ind_c1 = malla->getArcos()->getArco(ind_arco)->getCara1();
        int ind_c2 = malla->getArcos()->getArco(ind_arco)->getCara2();
        //Indices de los nodos
        int ind_p1 = malla->getArcos()->getArco(ind_arco)->getNodo1();
        int ind_p2 = malla->getArcos()->getArco(ind_arco)->getNodo2();
        int ind_p_c1 = malla->getNodoOpuestoArco(ind_c1,ind_arco);
        int ind_p_c2 = malla->getNodoOpuestoArco(ind_c2,ind_arco);
        
        //Obtenemos el angulo minimo de cada cara que separa el arco, y el minimo entre ellos.
        double angulo_min_c1 = malla->getAnguloMin(ind_c1);
        double angulo_min_c2 = malla->getAnguloMin(ind_c2);
        double angulo_min = angulo_min_c1;
        if(angulo_min_c2 < angulo_min) {
            angulo_min = angulo_min_c2;
        }
        
        Malla *m1 = new Malla(malla->getNodos()->getNodo(ind_p1)->getPunto(),malla->getNodos()->getNodo(ind_p_c2)->getPunto(),malla->getNodos()->getNodo(ind_p_c1)->getPunto());
        Malla *m2 = new Malla(malla->getNodos()->getNodo(ind_p2)->getPunto(),malla->getNodos()->getNodo(ind_p_c1)->getPunto(),malla->getNodos()->getNodo(ind_p_c2)->getPunto());
        
        double nuevo_angulo_min_c1 = m1->getAnguloMin(0);
        double nuevo_angulo_min_c2 = m2->getAnguloMin(0);
        double nuevo_angulo_min = nuevo_angulo_min_c1;
        if(nuevo_angulo_min_c2 < nuevo_angulo_min) {
            nuevo_angulo_min = nuevo_angulo_min_c2;
        }
        
        //si mejoramos el angulo minimo hacemos el flip.
        if(nuevo_angulo_min > angulo_min) {
            int nuevo_arco = malla->edgeFlip(ind_arco);
            assert(nuevo_arco == ind_arco);
            
            int nueva_c1 = malla->getArcos()->getArco(nuevo_arco)->getCara1();
            int nueva_c2 = malla->getArcos()->getArco(nuevo_arco)->getCara2();
            
            //revisamos los arcos vecinos que ya habiamos revisado, por si ahora se puede realizar el flip.
            vector<int> arcos_nueva_c1 = malla->getCaras()->getCara(nueva_c1)->getArcos();
            for(int i=0; i<(int)arcos_nueva_c1.size(); i++) {
                if(arcos_nueva_c1[i] != nuevo_arco && arcos_nueva_c1[i] < ind_arco) {
                    refinarArco(malla,criterio,arcos_nueva_c1[i]);
                }
            }
            vector<int> arcos_nueva_c2 = malla->getCaras()->getCara(nueva_c2)->getArcos();
            for(int i=0; i<(int)arcos_nueva_c2.size(); i++) {
                if(arcos_nueva_c2[i] != nuevo_arco && arcos_nueva_c2[i] < ind_arco) {
                    refinarArco(malla,criterio,arcos_nueva_c2[i]);
                }
            }
            
        }
    }
    
    if(!criterio->seCumple(malla,ind_arco)) {
        //debemos dividir el arco, agregando un punto al centro.
        vector<int> nuevos_arcos = malla->edgeSplit(ind_arco,0.5);
        //Ahora en forma recursiva reviso que los nuevos arcos cumplan el criterio.
        for(int i=0; i<(int)nuevos_arcos.size(); i++) {
            if((nuevos_arcos[i] <= ind_arco) && !criterio->seCumple(malla,nuevos_arcos[i])) {
                refinarArco(malla,criterio,nuevos_arcos[i]);
            }
        }
    }
    else {
        return;
    }
	}
*/
