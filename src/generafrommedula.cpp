#include <fstream>
#include <sstream>
#include "generafrommedula.h"

#define MAXLINE 256

GeneraFromMedula::GeneraFromMedula(string archivo, double radio, int num_anillos,int num_puntos){
    this->radio = radio;
    this->num_anillos=num_anillos;
    this->num_puntos = num_puntos;

    ifstream in(archivo.c_str());
    char line[MAXLINE];
    double x,y,z;
    while(true){
        in.getline(line,MAXLINE);
        if (in.fail()) break;
        stringstream streamin(line);
        streamin >> x;
        streamin >> y;
        streamin >> z;
        medula.push_back(Punto(x,y,z));
        }
    in.close();



    }

Punto* GeneraFromMedula::sectorMedula(double altura){
    int i;
    for (i=0; i+1<(int)medula.size(); i++){
        if (altura<=medula[i+1].getY())
            break;
        }
    int sector=i;

    Vect v1(medula[sector].getX(),medula[sector].getY(),medula[sector].getZ());
    Vect v2(medula[sector+1].getX(),medula[sector+1].getY(),medula[sector+1].getZ());
    Vect vect=v2-v1;
    Vect vectPonderado=vect*((altura-medula[sector].getY())/(vect.getPunto().getY()));

    double x=medula[sector].getX()+vectPonderado.getPunto().getX();
    double y=medula[sector].getY()+vectPonderado.getPunto().getY();
    double z=medula[sector].getZ()+vectPonderado.getPunto().getZ();

    return new Punto(x,y,z);
    }

Malla* GeneraFromMedula::aplicar(){

    nodos = new Nodos();
    Nodo *nodo;
    Punto *p;
    Vect normal, v1, v2;

    double angulo;
    double h;
    double altura=medula.back().getY();
    h = altura / num_anillos;
    angulo = 2*PI / num_puntos;
    for(int i=0; i<num_anillos; i++) {
        for(int j=0; j<num_puntos; j++) {
            Punto* sector=sectorMedula(i*h);
            p=new Punto(sector->getX()+radio*cos(j*angulo),sector->getY(),sector->getZ()+radio*sin(j*angulo));

            v1 = Vect(p->getX(),p->getY(),p->getZ());
            v2 = Vect(sector->getX(),sector->getY(),sector->getZ());
            normal = v1 - v2;
            normal.normalizar();

            delete sector;

            nodo = new Nodo(p);
            nodo->setNormal(normal); //le seteamos su normal
            nodo->setConcentracion(0.0); // le seteamos su concentracion
            if (i==0)
                nodo->esBordeInferior=true;
            else if (i==num_anillos-1)
                nodo->esBordeSuperior=true;
            nodos->addNodo(nodo);
        }
    }

    arcos = new Arcos();
    caras = new Caras();
    int n0, n1, n2, n3;

    for(int i=0; i<num_anillos-1; i++) {
        for(int j=0; j<num_puntos; j++) {

            n0 = num_puntos*i+j;
            n1 = num_puntos*i+((j+1)%num_puntos);
            n2 = num_puntos*(i+1)+j;
            n3 = num_puntos*(i+1)+((j+1)%num_puntos);

            //if ((i%2==0 && j%2==0) || (i%2!=0 && j%2!=0)){
            if (i%2==0){  //Para que se vayan alternando los arcos.
                arcos->addArco(new Arco(n0, n1));
                arcos->addArco(new Arco(n0, n2));
                arcos->addArco(new Arco(n0, n3));
                caras->addCara(new Cara(n0,n3,n1));
                caras->addCara(new Cara(n0,n2,n3));
                }
            else{
                arcos->addArco(new Arco(n0, n1));
                arcos->addArco(new Arco(n0, n2));
                arcos->addArco(new Arco(n1, n2));
                caras->addCara(new Cara(n1,n2,n3));
                caras->addCara(new Cara(n0,n2,n1));
                }

            if(i==num_anillos-2)    //Generamos los arcos del borde superior.
                arcos->addArco(new Arco(n2, n3));

            }
        }

    updateVecinos();

    Malla *malla = new Malla(nodos,arcos,caras);
    malla->setMedula(medula);
    malla->setConcentracionMax(1.0);
    malla->setConcentracionMin(0.0);

    return malla;
    }

void GeneraFromMedula::updateVecinos(){
    //Actualizo arcos vecinos de los nodos.
    int numarcos=arcos->getNumArcos();
    for (int iarco=0; iarco<numarcos; iarco++){
        nodos->getNodo(arcos->getArco(iarco)->getNodo1())->addArco(iarco);
        nodos->getNodo(arcos->getArco(iarco)->getNodo2())->addArco(iarco);
        }

    //Actualizo caras vecinas de los nodos.
    int numcaras=caras->getNumCaras();
    for (int icara=0; icara<numcaras; icara++){
        nodos->getNodo(caras->getCara(icara)->getNodos()[0])->addCara(icara);
        nodos->getNodo(caras->getCara(icara)->getNodos()[1])->addCara(icara);
        nodos->getNodo(caras->getCara(icara)->getNodos()[2])->addCara(icara);
        }

    //Actualizo arcos vecinos de las caras y caras vecinas de los arcos
    vector<int> nodosCara;
    vector<int> arcosARevisar;

    for (int icara=0; icara<numcaras; icara++){
        nodosCara=caras->getCara(icara)->getNodos();

        arcosARevisar=nodos->getNodo(nodosCara[0])->getArcos();
        for(int iarco=0; iarco<(int)arcosARevisar.size(); iarco++)
            if(arcos->getArco(arcosARevisar[iarco])->estanNodos(nodosCara)){
                caras->getCara(icara)->addArco(arcosARevisar[iarco]);
                arcos->getArco(arcosARevisar[iarco])->setCara(icara);
                }

        arcosARevisar=nodos->getNodo(nodosCara[1])->getArcos();
        for(int iarco=0; iarco<(int)arcosARevisar.size(); iarco++)
            if(arcos->getArco(arcosARevisar[iarco])->estanNodos(nodosCara)){
                caras->getCara(icara)->addArco(arcosARevisar[iarco]);
                arcos->getArco(arcosARevisar[iarco])->setCara(icara);
                }

        arcosARevisar=nodos->getNodo(nodosCara[2])->getArcos();
        for(int iarco=0; iarco<(int)arcosARevisar.size(); iarco++)
            if(arcos->getArco(arcosARevisar[iarco])->estanNodos(nodosCara)){
                caras->getCara(icara)->addArco(arcosARevisar[iarco]);
                arcos->getArco(arcosARevisar[iarco])->setCara(icara);
                }

        }

    }

GeneraFromMedula::~GeneraFromMedula(){
    //dtor
    }


