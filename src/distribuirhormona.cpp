#include "distribuirhormona.h"

DistribuirHormona::DistribuirHormona(Malla* malla, SimpleGLScene* simpleglscene, double factorgravitacional, double factorlongitudinal, double factortangencial):Comando(malla){
    this->simpleglscene=simpleglscene;
    this->factorgravitacional=factorgravitacional;
    this->factorlongitudinal=factorlongitudinal;
    this->factortangencial=factortangencial;
    }

void DistribuirHormona::execute(){
    //Calculamos las probabilidades de los arcos vecinos a cada uno de los nodos.
    Nodos* nodos=malla->getNodos();
    for (int i=0; i<nodos->getNumNodos(); i++){
        Nodo* nodo=nodos->getNodo(i);
        if (nodo!=NULL){
            vector<int> indArcos=nodo->getArcos();
            for (int j=0; j<(int)indArcos.size(); j++)
                nodo->addProbabilidadArco(calcularProbabilidad(i,indArcos[j]),indArcos[j]);
            nodo->normalizarProbabilidades();
            }
        }

    //Ahora hacemos el paseo al azar de las hormonas.
    paseoHormonas();

    }

void DistribuirHormona::paseoHormonas(){
    Nodos* nodos=malla->getNodos();

    int npaseos=100;
    for (int i=0; i<nodos->getNumNodos(); i++){
        Nodo* nodo=nodos->getNodo(i);
        if (nodo!=NULL && nodo->esBordeSuperior){
            for (int ipaseo=0; ipaseo<npaseos; ipaseo++){
                int indNodoPaseo=i;
                while (true){                  //Pendiente establecer el fin
                    Nodo* nodoPaseo=nodos->getNodo(indNodoPaseo);
                    nodoPaseo->setConcentracion(nodoPaseo->getConcentracion()+1.0);
                    if (nodos->getNodo(indNodoPaseo)->esBordeInferior) break;
                    indNodoPaseo=paseoAlAzar(indNodoPaseo);
                    }
                }
            }
        }

    //Normalizo las concentraciones.
    double maxconcentracion=0;
    for (int i=0; i<nodos->getNumNodos(); i++){
        Nodo* nodo=nodos->getNodo(i);
        if (nodo!=NULL && nodo->getConcentracion()>maxconcentracion)
            maxconcentracion=nodo->getConcentracion();
        }
    for (int i=0; i<nodos->getNumNodos(); i++){
        Nodo* nodo=nodos->getNodo(i);
        if (nodo!=NULL)
            nodo->setConcentracion(nodo->getConcentracion()/maxconcentracion);
        }
    }

int DistribuirHormona::paseoAlAzar(int indNodo){
    Nodo* nodo=malla->getNodos()->getNodo(indNodo);
    vector<double> probabilidades=nodo->getProbabilidadArcos();
    int i;
    double limiteinferior=0;
    double limitesuperior=probabilidades[0];
    //srand( time(NULL) );
    double azar=1.0*rand()/RAND_MAX;

    for (i=0; i<(int)probabilidades.size(); i++){

        if (azar>=limiteinferior && azar<=limitesuperior)
            break;

        limiteinferior=limitesuperior;
        if (i+1>=(int)probabilidades.size())
            limitesuperior=1;
        else
            limitesuperior=limitesuperior+probabilidades[i+1];
        }

    int indArcoSeleccionado=nodo->getArcos()[i];
    int indNodoSeleccionado=malla->getArcos()->getArco(indArcoSeleccionado)->getNodoDistinto(indNodo);

    return indNodoSeleccionado;
    }

double DistribuirHormona::calcularProbabilidad(int indNodo, int indArco){
    Nodos* nodos=malla->getNodos();
    Arcos* arcos=malla->getArcos();

    //Calculo el vector del arco.
    Arco* arco=arcos->getArco(indArco);
    int indNodoOpuesto=arco->getNodoDistinto(indNodo);
    Nodo* nodo=nodos->getNodo(indNodo);
    Vect vectorNodo(nodo->getPunto()->getX(),nodo->getPunto()->getY(),nodo->getPunto()->getZ());
    Nodo* nodoOpuesto=nodos->getNodo(indNodoOpuesto);
    Vect vectorNodoOpuesto(nodoOpuesto->getPunto()->getX(),nodoOpuesto->getPunto()->getY(),nodoOpuesto->getPunto()->getZ());
    Vect vectorArco=vectorNodoOpuesto-vectorNodo;
    vectorArco.normalizar();

    //Obtengo el vector gravedad
    Vect *vectorGravedad=new Vect(0,-1,0);

    //Obtengo el vector longitudinal
    Vect vectorLongitudinal=getVectorLongitudinal(nodo->getPunto()->getY());

    //Calculo el vector tangencial
    Vect vectorTangencial=vectorLongitudinal.prodCruz(*nodo->getNormal());
    //Vect *vectorTangencial=new Vect(1,0,0);

    //Proyecto los vectores sobre el vector arco
    double proyeccionGravedad=vectorGravedad->prodPunto(vectorArco);
    double proyeccionTangencial=fabs(vectorTangencial.prodPunto(vectorArco));
    double proyeccionLongitudinal=vectorLongitudinal.prodPunto(vectorArco);

    double probabilidadArco=factorgravitacional*proyeccionGravedad+
                            factorlongitudinal*proyeccionLongitudinal+
                            factortangencial*proyeccionTangencial;

    if(probabilidadArco<0)
        probabilidadArco=0;

    return probabilidadArco;
    }


Vect DistribuirHormona::getVectorLongitudinal(double altura){
    vector<Punto> medula=malla->getMedula();

    int i;
    for (i=0; i+1<(int)medula.size(); i++){
        if (altura<=medula[i+1].getY())
            break;
        }
    int sector=i;

    Vect v1(medula[sector].getX(),medula[sector].getY(),medula[sector].getZ());
    Vect v2(medula[sector+1].getX(),medula[sector+1].getY(),medula[sector+1].getZ());
    Vect vect=v2-v1;
    Vect vectorLongitudinal=vect*(-1);

    return vectorLongitudinal;
    }


DistribuirHormona::~DistribuirHormona()
{
    //dtor
}


