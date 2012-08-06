#include "verificacionnodosvecinos.h"

#include "segtriint.h"

VerificacionNodosVecinos::VerificacionNodosVecinos(double val):AlgDesplazamiento(){
	this->val=val;
	this->nnodosborrados=0;
	}

void VerificacionNodosVecinos::aplicar(Malla *malla){
	int ninconsistencias=repairMalla(malla);
	double mov=moverHasta(malla);
	cout << "Total de inconsistencias encontradas=" << ninconsistencias << endl;
	cout << "Total de trayectorias reparadas=" << ninconsistencias-nnodosborrados << endl;
	cout << "Total de nodos borrados=" << nnodosborrados << endl;
	cout << "Malla movida una proporcion = " << mov << endl;
	}

int VerificacionNodosVecinos::repairMalla(Malla *malla){
	//recorremos los nodos de la malla buscando donde se van a producir inconsistencias.
	int ninconsistencias=0;
	malla->clearNodosDestacados();
	//vector<int> nodosInconsistentes;
    for(int indNodo=0; indNodo<malla->getNodos()->getNumNodos(); indNodo++) {
			Nodo* nodoActual=malla->getNodos()->getNodo(indNodo);
			if (nodoActual!=NULL){
				cout << "Chequeo nodo " << indNodo << endl;
				/*if (indNodo==2697){
					//malla->setNodoDestacado(indNodo);
					//malla->checkMalla();
					//cerr << "el nodo tiene " << malla->getNodos()->getNodo(indNodo)->getCaras().size() << " caras vecinas." << endl;
					//cerr << "el nodo tiene " << malla->getNodos()->getNodo(2698)->getArcos()[0] << " como arco a colapsar." << endl;
					//cerr << malla->getArcos()->getArco(malla->getNodos()->getNodo(2698)->getArcos()[0])->getNodo2() << endl;
					break;
					}*/
				bool seIntersecta=checkInterseccionNodo(malla, indNodo);
				if (seIntersecta){
					cout << "Hay interseccion en nodo " << indNodo << endl;
					//malla->setNodoDestacado(indNodo);
					ninconsistencias++;
					//nodosInconsistentes.push_back(indNodo);
					corrigeInconsistencia(malla, indNodo);
					}
				}
			}

	/*
	while (nodosInconsistentes.size()>0){
        int casilla=rand()%nodosInconsistentes.size();
        int indNodo=nodosInconsistentes[casilla];
        Nodo* nodoActual=malla->getNodos()->getNodo(indNodo);
        if (nodoActual!=NULL){
            bool seIntersecta=checkInterseccionNodo(malla, indNodo);
            if (seIntersecta){
                cout << "Corregire inconsistencia en nodo " << indNodo << endl;
                corrigeInconsistencia(malla, indNodo);
                }
            }
        nodosInconsistentes.erase(nodosInconsistentes.begin()+casilla);
        }*/

	return ninconsistencias;
	}

double VerificacionNodosVecinos::moverHasta(Malla* malla){
	//Ahora movemos la malla.
	malla->getNodos()->moverTodosSegunConcentracion(val);
	return val;
	}

bool VerificacionNodosVecinos::checkInterseccionNodo(Malla* malla, int indNodo){
	assert(malla->getNodos()->getNodo(indNodo)!=NULL);

			Nodo* nodoActual=malla->getNodos()->getNodo(indNodo);

			//Definimos los puntos que componen el segmento de proyeccion del nodo.
			Punto *PuntoProyecNodoActual=new Punto(	nodoActual->getPunto()->getX()+nodoActual->getNormal()->getPunto().getX()*val*nodoActual->getConcentracion(),
													nodoActual->getPunto()->getY()+nodoActual->getNormal()->getPunto().getY()*val*nodoActual->getConcentracion(),
													nodoActual->getPunto()->getZ()+nodoActual->getNormal()->getPunto().getZ()*val*nodoActual->getConcentracion());
			Vect* q=new Vect(*nodoActual->getPunto());
			Vect* r=new Vect(*PuntoProyecNodoActual);

			//Revisamos cada una de las caras vecinas al nodo.
			vector<int> indCarasVecinas=nodoActual->getCaras();
			for (int indCara=0; indCara<(int)indCarasVecinas.size(); indCara++){
				Cara* caraVecina=malla->getCara(indCarasVecinas[indCara]);
				//Formo una pared del cilindro que rodea la proyeccion.
				int indPuntoA=caraVecina->getPuntosDistintos(indNodo)[0];
				int indPuntoB=caraVecina->getPuntosDistintos(indNodo)[1];
				Nodo* NodoA=malla->getNodo(indPuntoA);
				Nodo* NodoB=malla->getNodo(indPuntoB);
				Punto* PuntoProyecA=new Punto(NodoA->getPunto()->getX()+NodoA->getNormal()->getPunto().getX()*val*NodoA->getConcentracion(),
										NodoA->getPunto()->getY()+NodoA->getNormal()->getPunto().getY()*val*NodoA->getConcentracion(),
										NodoA->getPunto()->getZ()+NodoA->getNormal()->getPunto().getZ()*val*NodoA->getConcentracion());
				Punto* PuntoProyecB=new Punto(NodoB->getPunto()->getX()+NodoB->getNormal()->getPunto().getX()*val*NodoB->getConcentracion(),
										NodoB->getPunto()->getY()+NodoB->getNormal()->getPunto().getY()*val*NodoB->getConcentracion(),
										NodoB->getPunto()->getZ()+NodoB->getNormal()->getPunto().getZ()*val*NodoB->getConcentracion());

				SegTriInt* segtriint;
				char resultadoInterseccion;

				//Chequeamos interseccion con el primer triangulo
				Vect* triangulo1[3];
				triangulo1[0]=new Vect(*NodoA->getPunto());
				triangulo1[1]=new Vect(*PuntoProyecA);
				triangulo1[2]=new Vect(*PuntoProyecB);

				segtriint=new SegTriInt(triangulo1,q,r);
				resultadoInterseccion=segtriint->aplicar();
				delete segtriint;
				//cerr << "Nodo " << indNodo << " con plano de 1º triangulo de cara " << indCarasVecinas[indCara] << ": Interseccion=" << resultadoInterseccion << endl;
				if (resultadoInterseccion!='0'){
					/*triangulo1[0]->imprimir();
					triangulo1[1]->imprimir();
					triangulo1[2]->imprimir();
					q->imprimir();
					r->imprimir();*/
					return true;
					}

				//Chequeamos interseccion con el segundo triangulo
				Vect* triangulo2[3];
				triangulo2[0]=new Vect(*NodoB->getPunto());
				triangulo2[1]=new Vect(*NodoA->getPunto());
				triangulo2[2]=new Vect(*PuntoProyecB);

				segtriint=new SegTriInt(triangulo2,q,r);
				resultadoInterseccion=segtriint->aplicar();
				delete segtriint;
				//cerr << "Nodo " << indNodo << " con plano de 2º triangulo de cara " << indCarasVecinas[indCara] << ": Interseccion=" << resultadoInterseccion << endl;
				if (resultadoInterseccion!='0'){
					/*triangulo2[0]->imprimir();
					triangulo2[1]->imprimir();
					triangulo2[2]->imprimir();
					q->imprimir();
					r->imprimir();*/
					return true;
					}
				}

	return false;
	}

bool VerificacionNodosVecinos::corrigeInconsistencia (Malla *malla, int indNodo){
	assert(malla->getNodos()->getNodo(indNodo)!=NULL);

	Nodo* nodo=malla->getNodos()->getNodo(indNodo);
	Vect* viejaNormal=nodo->getNormal();
	Vect nuevaNormal;
	vector<int> indArcosVecinos=nodo->getArcos();
	for (int indArco=0; indArco< (int)indArcosVecinos.size(); indArco++){
		Arco* arcoVecino=malla->getArco(indArcosVecinos[indArco]);
		int indPuntoA=arcoVecino->getNodoDistinto(indNodo);
		Nodo* NodoA=malla->getNodo(indPuntoA);
		Vect vectorVecino=*NodoA->getNormal()*(val*NodoA->getConcentracion());
		/*if (indNodo==2553){
			cerr << "ind nodo vecino: " << indPuntoA << endl;
			cerr << "concentracion nodo vecino: " << NodoA->getConcentracion() << endl;
			cerr << "Vector vecino: "; vectorVecino->imprimir();
			}*/
		nuevaNormal=nuevaNormal+vectorVecino;
		}
	//Normalizamos.
	nuevaNormal = nuevaNormal*(1/nuevaNormal.largo());
	nodo->setNormal(nuevaNormal);
	//Si la inconsistencia no se corrige, borramos el nodo central.
	if (checkInterseccionNodo(malla,indNodo)==true){
		nodo->setNormal(*viejaNormal);
		cout << "Se debera borrar el nodo central " << indNodo << endl;
		nnodosborrados++;
		borrarNodoCentral(malla,indNodo);
		return false;
		}
	return true;
	}

void VerificacionNodosVecinos::borrarNodoCentral(Malla* malla, int indNodo){
	assert(malla->getNodos()->getNodo(indNodo)!=NULL);

	/*Nodo* nodo=malla->getNodos()->getNodo(indNodo);

	vector<int> arcos_nodo = nodo->getArcos();
    int ind_arco_mas_corto = arcos_nodo[0];
    for(int i=1; i<(int)arcos_nodo.size(); i++) {
        if(malla->getLargoArco(arcos_nodo[i]) < malla->getLargoArco(ind_arco_mas_corto)) {
            ind_arco_mas_corto = arcos_nodo[i];
        }
    }

	malla->vertexDeletion(ind_arco_mas_corto,indNodo);*/


	Nodo* nodo=malla->getNodos()->getNodo(indNodo);
	vector<int> arcos_nodo = nodo->getArcos();

    for(int i=0; i<(int)arcos_nodo.size(); i++) {
		int resultado=malla->vertexDeletion(arcos_nodo[i],indNodo);
        if(resultado!=-1)
        	break;
		}

	}
