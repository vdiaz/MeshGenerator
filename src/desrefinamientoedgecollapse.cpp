#include "desrefinamientoedgecollapse.h"

void DesrefinamientoEdgeCollapse::aplicar(Malla *malla, Criterio *criterio){
    Caras *caras = malla->getCaras();
	bool seEncontroInterseccion=true;
	while(seEncontroInterseccion==true){
		seEncontroInterseccion=false;
    	for(int i=0; i<caras->getNumCaras(); i++) {
			//int i=rand()%caras->getNumCaras();
    	    if(malla->getCara(i)!=NULL && find(excluidos.begin(),excluidos.end(),i)==excluidos.end() && criterio->seCumple(malla,i)) {
    	        cout << "Aplicando Desrefinamiento a cara " << i << " de " << caras->getNumCaras() << " (" << (float)i/caras->getNumCaras()*100 << "%)" <<endl;
				desrefinar(malla,i);
				//if (malla->checkMalla()==-1){
				//	malla->setNodoDestacado(42);
				//	return;
				//	}
    	        seEncontroInterseccion=true;
    	    	}
			}
		}
	
	/*Caras *caras = malla->getCaras();
	vector<int> listaCaras;
	for (int i=0; i<caras->getNumCaras(); i++)
		listaCaras.push_back(i);
	
	while(listaCaras.size()>0) {
		int casilla=rand()%listaCaras.size();
		int indCara=listaCaras[casilla];
    	if(malla->getCara(indCara)!=NULL && find(excluidos.begin(),excluidos.end(),indCara)==excluidos.end() && criterio->seCumple(malla,indCara)) {
    		cout << "Aplicando Desrefinamiento a cara " << indCara << " de " << caras->getNumCaras() << endl;
			desrefinar(malla,indCara);
			}
		listaCaras.erase(listaCaras.begin()+casilla);
		}*/
	
		
	}

int DesrefinamientoEdgeCollapse::desrefinar(Malla* malla, int indCara){
	int arcomascorto=malla->getArcoMasCorto(indCara);
	int resultado=malla->edgeCollapse2(arcomascorto,0.5);
	if (resultado==-1)
		excluidos.push_back(indCara);
	
	/*int arcomascorto=malla->getArcoMasCorto(indCara);
	int resultado=malla->vertexDeletion(arcomascorto,malla->getArcos()->getArco(arcomascorto)->getNodo1());
	if (resultado==-1)
		excluidos.push_back(indCara);*/
	
	return resultado;
	}
