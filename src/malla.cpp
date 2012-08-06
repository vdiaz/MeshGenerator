#include "malla.h"

/*** CONSTRUCTORES: ***/
Malla::Malla(Punto *p0, Punto *p1) {
    nodos = new Nodos();
    arcos = new Arcos();
    caras = new Caras();
    arcos->addArco(new Arco(nodos->addNodo(new Nodo(p0)),nodos->addNodo(new Nodo(p1)),-1,-1));
	show_nodos_destacados=true;
    concentracion_max = 1;
    concentracion_min = 0;
}

Malla::Malla(Punto *p0, Punto *p1, Punto *p2) {
    nodos = new Nodos();
    arcos = new Arcos();
    caras = new Caras();

    //Nodos.
    int ind_n0 = nodos->addNodo(new Nodo(p0));
    int ind_n1 = nodos->addNodo(new Nodo(p1));
    int ind_n2 = nodos->addNodo(new Nodo(p2));

    //Arcos
    int ind_a0 = arcos->addArco(new Arco(ind_n0,ind_n1,0,-1));
    int ind_a1 = arcos->addArco(new Arco(ind_n1,ind_n2,0,-1));
    int ind_a2 = arcos->addArco(new Arco(ind_n2,ind_n0,0,-1));

    //Cara
    int ind_cara = caras->addCara(new Cara(ind_n0,ind_n1,ind_n2,ind_a0,ind_a1,ind_a2));

    //Indices de los nodos a la cara y los arcos.
    nodos->getNodo(ind_n0)->addCara(ind_cara);
    nodos->getNodo(ind_n1)->addCara(ind_cara);
    nodos->getNodo(ind_n2)->addCara(ind_cara);

    nodos->getNodo(ind_n0)->addArco(ind_a0);
    nodos->getNodo(ind_n0)->addArco(ind_a2);
    nodos->getNodo(ind_n1)->addArco(ind_a0);
    nodos->getNodo(ind_n1)->addArco(ind_a1);
    nodos->getNodo(ind_n2)->addArco(ind_a1);
    nodos->getNodo(ind_n2)->addArco(ind_a2);

	show_nodos_destacados=true;
    concentracion_max = 1;
    concentracion_min = 0;
}

Malla::Malla(Punto *p0, Punto *p1, Punto *pc0, Punto *pc1) {
    nodos = new Nodos();
    arcos = new Arcos();
    caras = new Caras();

    //Nodos.
    int ind_n0 = nodos->addNodo(new Nodo(p0));
    int ind_n1 = nodos->addNodo(new Nodo(p1));
    int ind_nc0 = nodos->addNodo(new Nodo(pc0));
    int ind_nc1 = nodos->addNodo(new Nodo(pc1));

    //Arcos
    int ind_a0 = arcos->addArco(new Arco(ind_n0,ind_n1,0,1));
    int ind_a1 = arcos->addArco(new Arco(ind_n0,ind_nc0,0,-1));
    int ind_a2 = arcos->addArco(new Arco(ind_n1,ind_nc0,0,-1));
    int ind_a3 = arcos->addArco(new Arco(ind_n0,ind_nc1,1,-1));
    int ind_a4 = arcos->addArco(new Arco(ind_n1,ind_nc1,1,-1));

    //Caras
    int ind_c0 = caras->addCara(new Cara(ind_n0,ind_n1,ind_nc0,ind_a0,ind_a2,ind_a1));
    int ind_c1 = caras->addCara(new Cara(ind_n1,ind_n0,ind_nc1,ind_a0,ind_a3,ind_a4));

    //Indices de los nodos a la cara y los arcos.
    nodos->getNodo(ind_n0)->addCara(ind_c0);
    nodos->getNodo(ind_n0)->addCara(ind_c1);
    nodos->getNodo(ind_n1)->addCara(ind_c0);
    nodos->getNodo(ind_n1)->addCara(ind_c1);
    nodos->getNodo(ind_nc0)->addCara(ind_c0);
    nodos->getNodo(ind_nc1)->addCara(ind_c1);

    nodos->getNodo(ind_n0)->addArco(ind_a0);
    nodos->getNodo(ind_n0)->addArco(ind_a1);
    nodos->getNodo(ind_n0)->addArco(ind_a3);
    nodos->getNodo(ind_n1)->addArco(ind_a0);
    nodos->getNodo(ind_n1)->addArco(ind_a2);
    nodos->getNodo(ind_n1)->addArco(ind_a4);
    nodos->getNodo(ind_nc0)->addArco(ind_a1);
    nodos->getNodo(ind_nc0)->addArco(ind_a2);
    nodos->getNodo(ind_nc1)->addArco(ind_a3);
    nodos->getNodo(ind_nc1)->addArco(ind_a4);

	show_nodos_destacados=true;
    concentracion_max = 1;
    concentracion_min = 0;
}

Malla::Malla(Nodos *nds, Arcos *arcs, Caras *crs) {
    nodos = nds;
    arcos = arcs;
    caras = crs;
	show_nodos_destacados=true;
    concentracion_max = 1;
    concentracion_min = 0;
}


/*** SETTERS Y GETTERS: ***/
void Malla::setConcentracionMax(double max) {
    concentracion_max = max;
}

void Malla::setConcentracionMin(double min) {
    concentracion_min = min;
}

double Malla::getConcentracionMax() {
    return concentracion_max;
}

double Malla::getConcentracionMin() {
    return concentracion_min;
}

Nodos* Malla::getNodos() {
    return nodos;
}

Arcos* Malla::getArcos() {
    return arcos;
}

Caras* Malla::getCaras() {
    return caras;
}

Nodo* Malla::getNodo(int ind_nodo) {
    return nodos->getNodo(ind_nodo);
}

Arco* Malla::getArco(int ind_arco) {
    return arcos->getArco(ind_arco);
}

Cara* Malla::getCara(int ind_cara) {
    return caras->getCara(ind_cara);
}

void Malla::setNodoDestacado(int indNodo){
	nodosDestacados.push_back(indNodo);
	}

vector<int>* Malla::getNodosDestacados(){
	return &nodosDestacados;
	}

void Malla::clearNodosDestacados(){
	nodosDestacados.clear();
	}

void Malla::setMedula(vector<Punto> medula){
    this->medula=medula;
    }

vector<Punto> Malla::getMedula(){
    return this->medula;
    }

/*** MÉTODOS ARCOS: ***/
double Malla::getLargoArco(int ind_arco) {
    assert((ind_arco < arcos->getNumArcos()) && (ind_arco >= 0));
    double x1 = nodos->getNodo(arcos->getArco(ind_arco)->getNodo1())->getPunto()->getX();
    double y1 = nodos->getNodo(arcos->getArco(ind_arco)->getNodo1())->getPunto()->getY();
    double z1 = nodos->getNodo(arcos->getArco(ind_arco)->getNodo1())->getPunto()->getZ();
    double x2 = nodos->getNodo(arcos->getArco(ind_arco)->getNodo2())->getPunto()->getX();
    double y2 = nodos->getNodo(arcos->getArco(ind_arco)->getNodo2())->getPunto()->getY();
    double z2 = nodos->getNodo(arcos->getArco(ind_arco)->getNodo2())->getPunto()->getZ();
    Vect *v = new Vect(x1-x2,y1-y2,z1-z2);
	double largoArco=v->largo();
	delete v;
    return largoArco;
}

Punto* Malla::getPuntoMedioArco(int ind_arco) {
    assert((ind_arco < arcos->getNumArcos()) && (ind_arco >= 0));
    Punto *p1 = nodos->getNodo(arcos->getArco(ind_arco)->getNodo1())->getPunto();
    Punto *p2 = nodos->getNodo(arcos->getArco(ind_arco)->getNodo2())->getPunto();
    return new Punto((p1->getX()+p2->getX())/2,(p1->getY()+p2->getY())/2,(p1->getZ()+p2->getZ())/2);
}

double Malla::getAnguloArco(int ind_arco) {
    assert((ind_arco < arcos->getNumArcos()) && (ind_arco >= 0));

    int ind_c1 = arcos->getArco(ind_arco)->getCara1();
    int ind_c2 = arcos->getArco(ind_arco)->getCara2();

    Vect normal_c1 = this->getNormal(ind_c1);
    Vect normal_c2 = this->getNormal(ind_c2);

    return normal_c1.getAngulo(normal_c2);
}

bool Malla::esArcoBorde(int ind_arco) {
    assert((ind_arco < arcos->getNumArcos()) && (ind_arco >= 0));

    int ind_c1 = arcos->getArco(ind_arco)->getCara1();
    int ind_c2 = arcos->getArco(ind_arco)->getCara2();

    if(ind_c1 == -1 || ind_c2 == -1) {
        return true;
    }
    return false;
}

bool Malla::esAnguloDiedro(int ind_arco, double anguloDiedroMax) {
    assert((ind_arco < arcos->getNumArcos()) && (ind_arco >= 0));

    double anguloDiedro = this->getAnguloArco(ind_arco);
    if(anguloDiedro > anguloDiedroMax) {
        // No se puede realizar flip porque se pierde la forma.
        return true;
    }

    //Finalmente retornamos falso.
    return false;
}

bool Malla::esArcoConcavo(int ind_arco) {
    assert((ind_arco < arcos->getNumArcos()) && (ind_arco >= 0));

    int ind_c1 = arcos->getArco(ind_arco)->getCara1();
    int ind_c2 = arcos->getArco(ind_arco)->getCara2();

    if(ind_c1 == -1 || ind_c2 == -1) {
        return false;
    }

    //obtenemos los indices de los puntos
    int ind_p1 = arcos->getArco(ind_arco)->getNodo1();
    int ind_p2 = arcos->getArco(ind_arco)->getNodo2();

    double angulo1 = this->getAnguloVertice(ind_c1,ind_p1) + this->getAnguloVertice(ind_c2,ind_p1);
    double angulo2 = this->getAnguloVertice(ind_c1,ind_p2) + this->getAnguloVertice(ind_c2,ind_p2);

    //si se forma un angulo mayor o igual a 180º no se puede realizar el flip
    if(angulo1 >= PI || angulo2 >= PI) {
        //Es concavo
        return true;
    }

    //Finalmente retornamos falso. es convexo
    return false;
}

bool Malla::esArcoFijo(int ind_arco) {
    assert((ind_arco < arcos->getNumArcos()) && (ind_arco >= 0));
    if(esArcoBorde(ind_arco)) {
        return true;
    }
    if(esAnguloDiedro(ind_arco,ANGULO_DIEDRO)) {
        return true;
    }
    if(esArcoConcavo(ind_arco)) {
        return true;
    }
    return false;
}

/*** MÉTODOS CARAS: ***/
double Malla::getArea(int ind_cara) {
    assert((ind_cara < caras->getNumCaras()) && (ind_cara >= 0));

    //obtenemos los indices de los nodos de la cara
    vector<int> nodos_cara = caras->getCara(ind_cara)->getNodos();
    Vect vp0 = Vect(nodos->getNodo(nodos_cara[0])->getPunto()->getX(),nodos->getNodo(nodos_cara[0])->getPunto()->getY(),nodos->getNodo(nodos_cara[0])->getPunto()->getZ());
    Vect vp1, vp2;
    Vect v1, v2, prod_cruz;
    double area = 0;
    for(int i=1; i<(int)nodos_cara.size()-1; i++) {
        vp1 = Vect(*nodos->getNodo(nodos_cara[i])->getPunto());
        vp2 = Vect(*nodos->getNodo(nodos_cara[i+1])->getPunto());
        v1 = vp1 - vp0;
        v2 = vp2 - vp0;
        prod_cruz = v1.prodCruz(v2);
        area = area + prod_cruz.largo()/2;
    }
    return area;
}

double Malla::getPerimetro (int indCara){
	vector<int> indArcos=caras->getCara(indCara)->getArcos();
	double perimetro=0;
	for (int i=0; i<(int)indArcos.size(); i++)
		perimetro=perimetro+getLargoArco(indArcos[i]);

	return perimetro;
	}

double Malla::getAnguloVertice(int ind_cara, int ind_nodo) {
    assert((ind_cara < caras->getNumCaras()) && (ind_cara >= 0));
    //obtenemos los indices de los nodos de la cara
    vector<int> nodos_cara = caras->getCara(ind_cara)->getNodos();
    Punto *p1, *p2, *p3;
    Vect v1, v2;
    double angulo;
    for(int i=0; i<(int)nodos_cara.size(); i++) {
        p1 = nodos->getNodo(nodos_cara[i])->getPunto();
        p2 = nodos->getNodo(nodos_cara[int(fmod(i+1,nodos_cara.size()))])->getPunto();
        p3 = nodos->getNodo(nodos_cara[int(fmod(i+2,nodos_cara.size()))])->getPunto();
        Vect vp1(*p1);
        Vect vp2(*p2);
        Vect vp3(*p3);
        v1 = vp1 - vp2;
        v2 = vp3 - vp2;
        if(ind_nodo == nodos_cara[int(fmod(i+1,nodos_cara.size()))]) {
			//cerr << "p1: "; p1->imprimir();
			//cerr << "p2: "; p2->imprimir();
			//cerr << "p3: "; p3->imprimir();
			//cerr << "v1: "; v1->imprimir();
			//cerr << "v2: "; v2->imprimir();
            angulo = v1.getAngulo(v2);
            return angulo;
        }
    }
    // el indice del nodo no pertenece a la cara
    assert(1 == 0);
    return 0;
}

double Malla::getAnguloMin(int ind_cara) {
    assert((ind_cara < caras->getNumCaras()) && (ind_cara >= 0));
    //obtenemos los indices de los nodos de la cara
    vector<int> nodos_cara = caras->getCara(ind_cara)->getNodos();
    Vect normal_cara = this->getNormal(ind_cara);
    Punto *p1, *p2, *p3;
    Vect v1, v2, prod_cruz;
    double angulo;
    double angulo_min = 2*PI;
    for(int i=0; i<(int)nodos_cara.size(); i++) {
        p1 = nodos->getNodo(nodos_cara[i])->getPunto();
        p2 = nodos->getNodo(nodos_cara[int(fmod(i+1,nodos_cara.size()))])->getPunto();
        p3 = nodos->getNodo(nodos_cara[int(fmod(i+2,nodos_cara.size()))])->getPunto();
        Vect vp1(*p1);
        Vect vp2(*p2);
        Vect vp3(*p3);
        v1 = vp1 - vp2;
        v2 = vp3 - vp2;
        prod_cruz = v1.prodCruz(v2);
        angulo = v1.getAngulo(v2);
        if(normal_cara.prodPunto(prod_cruz) > 0) {
            angulo = 2*PI - angulo;
        }
        if(angulo < angulo_min) {
            angulo_min = angulo;
        }
    }

    return angulo_min;
}

double Malla::getAnguloMax(int ind_cara) {
    assert((ind_cara < caras->getNumCaras()) && (ind_cara >= 0));
    //obtenemos los indices de los arcos de la cara
    vector<int> nodos_cara = caras->getCara(ind_cara)->getNodos();
    Vect normal_cara = this->getNormal(ind_cara);
    Punto *p1, *p2, *p3;
    Vect v1, v2, prod_cruz;
    double angulo;
    double angulo_max = 0;
    for(int i=0; i<(int)nodos_cara.size(); i++) {
        p1 = nodos->getNodo(nodos_cara[i])->getPunto();
        p2 = nodos->getNodo(nodos_cara[int(fmod(i+1,nodos_cara.size()))])->getPunto();
        p3 = nodos->getNodo(nodos_cara[int(fmod(i+2,nodos_cara.size()))])->getPunto();
        Vect vp1(*p1);
        Vect vp2(*p2);
        Vect vp3(*p3);
        v1 = vp1 - vp2;
        v2 = vp3 - vp2;
        prod_cruz = v1.prodCruz(v2);
        angulo = v1.getAngulo(v2);
        if(normal_cara.prodPunto(prod_cruz) > 0) {
            angulo = 2*PI - angulo;
        }
        if(angulo > angulo_max) {
            angulo_max = angulo;
        }
    }
    return angulo_max;
}

vector<int> Malla::getArcosAnguloMin(int ind_cara) {
    assert((ind_cara < caras->getNumCaras()) && (ind_cara >= 0));
    //obtenemos los indices de los nodos de la cara
    vector<int> nodos_cara = caras->getCara(ind_cara)->getNodos();
    //obtenemos los indices de los arcos de la cara
    vector<int> arcos_cara = caras->getCara(ind_cara)->getArcos();

    int ind_nodo_min = this->getNodoAnguloMin(ind_cara);

    vector<int> arcos_angulo_min;
    vector<int> arcos_nodo = nodos->getNodo(ind_nodo_min)->getArcos();

    for(int i=0; i<(int)arcos_nodo.size(); i++) {
        for(int j=0; j<(int)arcos_cara.size(); j++) {
            if(arcos_nodo[i] == arcos_cara[j]) {
                arcos_angulo_min.push_back(arcos_nodo[i]);
            }
        }
    }
    assert(arcos_angulo_min.size() == 2);
    return arcos_angulo_min;
}

int Malla::getNodoAnguloMin(int ind_cara) {
    assert((ind_cara < caras->getNumCaras()) && (ind_cara >= 0));
    //obtenemos los indices de los nodos de la cara
    vector<int> nodos_cara = caras->getCara(ind_cara)->getNodos();
    double angulo;
    int ind_nodo_min = -1;
    double angulo_min = 2*PI;
    for(int i=0; i<(int)nodos_cara.size(); i++) {
        angulo = this->getAnguloVertice(ind_cara, nodos_cara[i]);
        if(angulo < angulo_min) {
            angulo_min = angulo;
            ind_nodo_min = nodos_cara[i];
        }
    }
    return ind_nodo_min;
}

Vect Malla::getNormal(int ind_cara) {
    assert((ind_cara < caras->getNumCaras()) && (ind_cara >= 0));
	assert(getCaras()->getCara(ind_cara)!=NULL);
    vector<int> nodos_cara = caras->getCara(ind_cara)->getNodos();
    Punto *p1,*p2,*p3;
    p1 = nodos->getNodo(nodos_cara[0])->getPunto();
    p2 = nodos->getNodo(nodos_cara[1])->getPunto();
    p3 = nodos->getNodo(nodos_cara[2])->getPunto();
    Vect vp1(*p1);
    Vect vp2(*p2);
    Vect vp3(*p3);
    Vect v12 = vp2 - vp1;
    Vect v13 = vp3 - vp2;
    Vect N = v12.prodCruz(v13);



    //Verificamos que los puntos de las caras sean coplanares
//     Punto *p;
//     for(int i=3; i<nodos_cara.size(); i++) {
//         p = nodos->getNodo(nodos_cara[i])->getPunto();
//         double prod_punto = N->prodPunto((*p)-p1);
//         if(prod_punto > 0.00001 || prod_punto < -0.00001) {
//             cout << "Error: Cara(" << i << "), posee puntos que no son coplanares" << endl;
//             assert(1==0); // no salimos de la ejecucion
//         }
//     }
    return N;
}

double Malla::getAnguloCaras(int ind_cara1, int ind_cara2) {
    assert((ind_cara1 < caras->getNumCaras()) && (ind_cara1 >= 0));
    assert((ind_cara2 < caras->getNumCaras()) && (ind_cara2 >= 0));
    Vect v1 = this->getNormal(ind_cara1);
    Vect v2 = this->getNormal(ind_cara2);
    return v1.getAngulo(v2);
}

int Malla::getArcoMasLargo(int ind_cara) {
    assert((ind_cara < caras->getNumCaras()) && (ind_cara >= 0));
    vector<int> arcos_cara = caras->getCara(ind_cara)->getArcos();
    int ind_arco_mas_largo = arcos_cara[0];
    for(int i=1; i<(int)arcos_cara.size(); i++) {
        if(this->getLargoArco(arcos_cara[i]) > this->getLargoArco(ind_arco_mas_largo)) {
            ind_arco_mas_largo = arcos_cara[i];
        }
    }
    return ind_arco_mas_largo;
}

int Malla::getArcoMasCorto(int ind_cara) {
    assert((ind_cara < caras->getNumCaras()) && (ind_cara >= 0));
    vector<int> arcos_cara = caras->getCara(ind_cara)->getArcos();
    int ind_arco_mas_corto = arcos_cara[0];
    for(int i=1; i<(int)arcos_cara.size(); i++) {
        if(this->getLargoArco(arcos_cara[i]) < this->getLargoArco(ind_arco_mas_corto)) {
            ind_arco_mas_corto = arcos_cara[i];
        }
    }
    return ind_arco_mas_corto;
}

bool Malla::sonCarasVecinas(int ind_cara1, int ind_cara2) {
    assert((ind_cara1 < caras->getNumCaras()) && (ind_cara1 >= -1));
    assert((ind_cara2 < caras->getNumCaras()) && (ind_cara2 >= -1));

    if(ind_cara1 == -1 || ind_cara2 == -1) {
        return false;
    }
    vector<int> arcos_cara1 = this->caras->getCara(ind_cara1)->getArcos();
    vector<int> arcos_cara2 = this->caras->getCara(ind_cara2)->getArcos();
    for(int i=0; i<(int)arcos_cara1.size(); i++) {
        for(int j=0; j<(int)arcos_cara2.size(); j++) {
            if(arcos_cara1[i] == arcos_cara2[j]) {
                return true;
            }
        }
    }
    return false;
}

bool Malla::esCaraBorde(int ind_cara) {
    assert((ind_cara < caras->getNumCaras()) && (ind_cara >= 0));
    vector<int> ind_arcos_cara = caras->getCara(ind_cara)->getArcos();
    for(int i=0; i<(int)ind_arcos_cara.size(); i++) {
        if(esArcoBorde(ind_arcos_cara[i])) {
            return true;
        }
    }
    return false;
}

vector<int> Malla::getArcosBordeCara(int ind_cara) {
    assert((ind_cara < caras->getNumCaras()) && (ind_cara >= 0));
    vector<int> arcos_borde;
    vector<int> ind_arcos_cara = caras->getCara(ind_cara)->getArcos();
    for(int i=0; i<(int)ind_arcos_cara.size(); i++) {
        if(esArcoBorde(ind_arcos_cara[i])) {
            arcos_borde.push_back(ind_arcos_cara[i]);
        }
    }
    return arcos_borde;
}

/*** TRANSFORMACIONES: ***/
int Malla::edgeFlip(int ind_arco) {
    assert((ind_arco < arcos->getNumArcos()) && (ind_arco >= 0));
    int ind_c1 = arcos->getArco(ind_arco)->getCara1();
    int ind_c2 = arcos->getArco(ind_arco)->getCara2();
    if(ind_c1 < 0 || ind_c2 < 0) {
		cout << "Arco " << ind_arco << " es region borde. No se hace el flip." << endl;
        return -1; // este arco no define 2 caras --> region borde (No se puede realizar el flip).
	}
    //obtenemos los indices de los 4 puntos
    int ind_p1 = arcos->getArco(ind_arco)->getNodo1();
    int ind_p2 = arcos->getArco(ind_arco)->getNodo2();
    int ind_p_c1 = this->getNodoOpuestoArco(ind_c1,ind_arco);
    int ind_p_c2 = this->getNodoOpuestoArco(ind_c2,ind_arco);

	/* 	Se comenta estas lineas para permitir que los algoritmos de deformacion puedan
		funcionar. Estas verificaciones se caen si se llaman durante la deformacion ya
		que durante la deformacion la malla esta en un estado inconsistente.

		Update: Al final mejor dejarlas descomentadas ya que sino no funciona edgeCollapse.
	*/
    double angulo1 = this->getAnguloVertice(ind_c1,ind_p1) + this->getAnguloVertice(ind_c2,ind_p1);
    double angulo2 = this->getAnguloVertice(ind_c1,ind_p2) + this->getAnguloVertice(ind_c2,ind_p2);

    //si se forma un angulo mayor o igual a 180º no se puede realizar el flip
    if(angulo1 >= PI || angulo2 >= PI) {
		cout << "Arco " << ind_arco << " forma angulo mayor a 180º. No se hace el flip." << endl;
        return -1;
    }


    Vect normal_c1 = this->getNormal(ind_c1);
    Vect normal_puntos = this->getNormalNodos(ind_p1,ind_p2,ind_p_c1);
    double prod_punto = normal_puntos.prodPunto(normal_c1);
    if(prod_punto < 0) {
        // Cambiamos los indices de p1 y p2
        int aux = ind_p1;
        ind_p1 = ind_p2;
        ind_p2 = aux;
    }

    //obtenemos los indices de los arcos
    int ind_a1_c1 = this->getArcoOpuestoNodo(ind_c1,ind_p1);
    int ind_a2_c1 = this->getArcoOpuestoNodo(ind_c1,ind_p2);
    int ind_a1_c2 = this->getArcoOpuestoNodo(ind_c2,ind_p1);
    int ind_a2_c2 = this->getArcoOpuestoNodo(ind_c2,ind_p2);

    //obtenemos los indices de las caras vecinas
    int ind_c1_vecina1 = getCaraOpuestaNodo(ind_c1, ind_p1);
    int ind_c1_vecina2 = getCaraOpuestaNodo(ind_c1, ind_p2);
    int ind_c2_vecina1 = getCaraOpuestaNodo(ind_c2, ind_p1);
    int ind_c2_vecina2 = getCaraOpuestaNodo(ind_c2, ind_p2);

    //borramos el arco en ind_arco y agregamos el nuevo arco. Esto se hace en un paso con la funcion addArcoIn(Arco *a, int indice), es decir, agrega el arco "a" en la posicion de indice. Con esto el nuevo arco quedara en la misma posicion en en que estaba el arco borrado.
    int ind_nuevo_arco = arcos->addArcoIn(new Arco(ind_p_c1,ind_p_c2),ind_arco);

    vector<int> indice_puntos;
    vector<int> indice_arcos;
    vector<int> indice_caras;

    indice_puntos.push_back(ind_p_c2);
    indice_puntos.push_back(ind_p_c1);
    indice_puntos.push_back(ind_p1);

    indice_arcos.push_back(ind_nuevo_arco);
    indice_arcos.push_back(ind_a2_c1);
    indice_arcos.push_back(ind_a2_c2);

    //borramos la cara en ind_c1 y agregamos la nueva cara
    int ind_nueva_cara1 = caras->addCaraIn(new Cara(indice_puntos,indice_arcos),ind_c1);
    arcos->setCaraArco(ind_nuevo_arco,ind_nueva_cara1);

    indice_puntos[0] = ind_p_c1;
    indice_puntos[1] = ind_p_c2;
    indice_puntos[2] = ind_p2;
    indice_arcos[0] = ind_nuevo_arco;
    indice_arcos[1] = ind_a1_c2;
    indice_arcos[2] = ind_a1_c1;

    //borramos la cara en ind_c1 y agregamos la nueva cara
    int ind_nueva_cara2 = caras->addCaraIn(new Cara(indice_puntos,indice_arcos),ind_c2);
    arcos->setCaraArco(ind_nuevo_arco,ind_nueva_cara2);

    //actualizamos los indices del nodo p1 hacia sus arcos y caras
    nodos->getNodo(ind_p1)->eraseCara(ind_c1);
    nodos->getNodo(ind_p1)->eraseCara(ind_c2);
    nodos->getNodo(ind_p1)->addCara(ind_nueva_cara1);
    nodos->getNodo(ind_p1)->eraseArco(ind_arco);

    //actualizamos los indices del nodo p2 hacia sus arcos y caras
    nodos->getNodo(ind_p2)->eraseCara(ind_c1);
    nodos->getNodo(ind_p2)->eraseCara(ind_c2);
    nodos->getNodo(ind_p2)->addCara(ind_nueva_cara2);
    nodos->getNodo(ind_p2)->eraseArco(ind_arco);

    //actualizamos los indices del nodo p_cara1 hacia sus arcos y caras
    nodos->getNodo(ind_p_c1)->eraseCara(ind_c1);
    nodos->getNodo(ind_p_c1)->addCara(ind_nueva_cara1);
    nodos->getNodo(ind_p_c1)->addCara(ind_nueva_cara2);
    nodos->getNodo(ind_p_c1)->addArco(ind_nuevo_arco);

    //actualizamos los indices del nodo p_cara2 hacia sus arcos y caras
    nodos->getNodo(ind_p_c2)->eraseCara(ind_c2);
    nodos->getNodo(ind_p_c2)->addCara(ind_nueva_cara1);
    nodos->getNodo(ind_p_c2)->addCara(ind_nueva_cara2);
    nodos->getNodo(ind_p_c2)->addArco(ind_nuevo_arco);

    //actualizamos los indices de los arcos que apuntan hacia las nuevas caras
    arcos->getArco(ind_a1_c1)->setCaras(ind_nueva_cara2,ind_c1_vecina1);
    arcos->getArco(ind_a2_c1)->setCaras(ind_nueva_cara1,ind_c1_vecina2);
    arcos->getArco(ind_a1_c2)->setCaras(ind_nueva_cara2,ind_c2_vecina1);
    arcos->getArco(ind_a2_c2)->setCaras(ind_nueva_cara1,ind_c2_vecina2);

    return ind_nuevo_arco;
}

vector<int> Malla::edgeSplit(int ind_arco, double dist, int retorna) {
    assert((ind_arco < arcos->getNumArcos()) && (ind_arco >= 0));
    assert(dist>0 && dist<1);

    vector<int> nuevos_arcos;
    vector<int> nuevas_caras;

    int ind_c1 = arcos->getArco(ind_arco)->getCara1();
    int ind_c2 = arcos->getArco(ind_arco)->getCara2();

    //obtenemos los indices de los 4 puntos
    int ind_p1 = arcos->getArco(ind_arco)->getNodo1();
    int ind_p2 = arcos->getArco(ind_arco)->getNodo2();
    int ind_p_c1 = this->getNodoOpuestoArco(ind_c1,ind_arco);
    int ind_p_c2 = this->getNodoOpuestoArco(ind_c2,ind_arco);

    Vect normal_c1 = this->getNormal(ind_c1);
    Vect normal_puntos = this->getNormalNodos(ind_p1,ind_p2,ind_p_c1);
    double prod_punto = normal_puntos.prodPunto(normal_c1);
    if(prod_punto < 0) {
        // Cambiamos los indices de p1 y p2
        int aux = ind_p1;
        ind_p1 = ind_p2;
        ind_p2 = aux;
    }

    //obtenemos los indices de los arcos
    int ind_a1_c1 = this->getArcoOpuestoNodo(ind_c1,ind_p1);
    int ind_a2_c1 = this->getArcoOpuestoNodo(ind_c1,ind_p2);
    int ind_a1_c2 = this->getArcoOpuestoNodo(ind_c2,ind_p1);
    int ind_a2_c2 = this->getArcoOpuestoNodo(ind_c2,ind_p2);

    //obtenemos los indices de las caras vecinas
    int ind_c1_vecina1 = getCaraOpuestaNodo(ind_c1, ind_p1);
    int ind_c1_vecina2 = getCaraOpuestaNodo(ind_c1, ind_p2);
    int ind_c2_vecina1 = getCaraOpuestaNodo(ind_c2, ind_p1);
    int ind_c2_vecina2 = getCaraOpuestaNodo(ind_c2, ind_p2);

    //borramos las 2 caras
    if(ind_c1 != -1) {
        caras->eraseCara(ind_c1);
    }
    if(ind_c2 != -1) {
        caras->eraseCara(ind_c2);
    }

    //borramos el arco
    arcos->eraseArco(ind_arco);

    //agregamos el nuevo nodo y le seteamos su normal y concentracion.
    Punto *p1 = nodos->getNodo(ind_p1)->getPunto();
    Punto *p2 = nodos->getNodo(ind_p2)->getPunto();
    Vect vp1(*p1);
    Vect vp2(*p2);
    Vect v_p1_p2 = vp2 - vp1;
    v_p1_p2 = v_p1_p2 * dist;
    Vect vp = vp1 + v_p1_p2;
    Punto *p=new Punto(vp.getPunto().getX(),vp.getPunto().getY(),vp.getPunto().getZ());
    Nodo *nuevo_nodo = new Nodo(p);
    int ind_nuevo_nodo = nodos->addNodo(nuevo_nodo);
    //le seteamos su normal como el promedio de las normales de sus nodos vecinos
	//le seteamos la concentracion como el promedio de la concentracion de nodos vecinos.
    Vect *normal_p1 = nodos->getNodo(ind_p1)->getNormal();
    Vect *normal_p2 = nodos->getNodo(ind_p2)->getNormal();
    Vect normal_prom = *normal_p1 + *normal_p2;
	double concentracion_p1=nodos->getNodo(ind_p1)->getConcentracion();
	double concentracion_p2=nodos->getNodo(ind_p2)->getConcentracion();
	double sumaConcentracion=concentracion_p1+concentracion_p2;
	double divisorConcentracion=2;

    if(ind_p_c1 != -1) {
        Vect *normal_p_c1 = nodos->getNodo(ind_p_c1)->getNormal();
        normal_prom = normal_prom + *normal_p_c1;
		sumaConcentracion=sumaConcentracion+nodos->getNodo(ind_p_c1)->getConcentracion();
		divisorConcentracion++;
    }
    if(ind_p_c2 != -1) {
        Vect *normal_p_c2 = nodos->getNodo(ind_p_c2)->getNormal();
        normal_prom = normal_prom + *normal_p_c2;
		sumaConcentracion=sumaConcentracion+nodos->getNodo(ind_p_c2)->getConcentracion();
		divisorConcentracion++;
    }
    if(normal_prom.largo() != 0) {
        normal_prom = normal_prom * (1/normal_prom.largo()); // se normaliza
    }
    //this->setNormal(ind_nuevo_nodo,normal_prom);
    nodos->getNodo(ind_nuevo_nodo)->setNormal(normal_prom);
	this->getNodos()->getNodo(ind_nuevo_nodo)->setConcentracion(sumaConcentracion/divisorConcentracion);

    //agregamos los 4 nuevos arcos
    int ind_nuevo_arco_p1 = arcos->addArco(new Arco(ind_p1,ind_nuevo_nodo));
    nuevos_arcos.push_back(ind_nuevo_arco_p1);
    int ind_nuevo_arco_p2 = arcos->addArco(new Arco(ind_p2,ind_nuevo_nodo));
    nuevos_arcos.push_back(ind_nuevo_arco_p2);
    //Le seteamos estos arcos al nodo insertado
    nodos->addArcoNodo(ind_nuevo_nodo,ind_nuevo_arco_p1);
    nodos->addArcoNodo(ind_nuevo_nodo,ind_nuevo_arco_p2);
    int ind_nuevo_arco_p_c1 = -1;
    int ind_nuevo_arco_p_c2 = -1;
    if(ind_p_c1 != -1) {
        ind_nuevo_arco_p_c1 = arcos->addArco(new Arco(ind_p_c1,ind_nuevo_nodo));
        nuevos_arcos.push_back(ind_nuevo_arco_p_c1);
        //Le seteamos este arco al nodo insertado
        nodos->addArcoNodo(ind_nuevo_nodo,ind_nuevo_arco_p_c1);
    }
    if(ind_p_c2 != -1) {
        ind_nuevo_arco_p_c2 = arcos->addArco(new Arco(ind_p_c2,ind_nuevo_nodo));
        nuevos_arcos.push_back(ind_nuevo_arco_p_c2);
        //Le seteamos este arco al nodo insertado
        nodos->addArcoNodo(ind_nuevo_nodo,ind_nuevo_arco_p_c2);
    }

    vector<int> indice_puntos;
    vector<int> indice_arcos;
    vector<int> indice_caras;

    //agregamos las nuevas caras
    int ind_nueva_cara1 = -1;
    int ind_nueva_cara2 = -1;
    int ind_nueva_cara3 = -1;
    int ind_nueva_cara4 = -1;
    if(ind_p_c1 != -1) {
        indice_puntos.push_back(ind_p1);
        indice_puntos.push_back(ind_nuevo_nodo);
        indice_puntos.push_back(ind_p_c1);

        indice_arcos.push_back(ind_nuevo_arco_p1);
        indice_arcos.push_back(ind_nuevo_arco_p_c1);
        indice_arcos.push_back(ind_a2_c1);

        ind_nueva_cara1 = caras->addCara(new Cara(indice_puntos,indice_arcos));
        nuevas_caras.push_back(ind_nueva_cara1);
        arcos->setCaraArco(ind_nuevo_arco_p_c1,ind_nueva_cara1);
        arcos->setCaraArco(ind_nuevo_arco_p1,ind_nueva_cara1);
        //Le seteamos esta cara al nodo insertado
        nodos->addCaraNodo(ind_nuevo_nodo,ind_nueva_cara1);

        indice_puntos[0] = ind_p2;
        indice_puntos[1] = ind_p_c1;
        indice_puntos[2] = ind_nuevo_nodo;
        indice_arcos[0] = ind_a1_c1;
        indice_arcos[1] = ind_nuevo_arco_p_c1;
        indice_arcos[2] = ind_nuevo_arco_p2;

        ind_nueva_cara2 = caras->addCara(new Cara(indice_puntos,indice_arcos));
        nuevas_caras.push_back(ind_nueva_cara2);
        arcos->setCaraArco(ind_nuevo_arco_p_c1,ind_nueva_cara2);
        arcos->setCaraArco(ind_nuevo_arco_p2,ind_nueva_cara2);
        //Le seteamos esta cara al nodo insertado
        nodos->addCaraNodo(ind_nuevo_nodo,ind_nueva_cara2);

        indice_puntos.clear();
        indice_arcos.clear();

        //actualizamos los indices del nodo p_cara1 hacia sus arcos y caras
        nodos->getNodo(ind_p_c1)->eraseCara(ind_c1);
        nodos->getNodo(ind_p_c1)->addCara(ind_nueva_cara1);
        nodos->getNodo(ind_p_c1)->addCara(ind_nueva_cara2);
        nodos->getNodo(ind_p_c1)->addArco(ind_nuevo_arco_p_c1);

        //actualizamos los indices de los arcos que apuntan hacia las nuevas caras
        arcos->getArco(ind_a1_c1)->setCaras(ind_nueva_cara2,ind_c1_vecina1);
        arcos->getArco(ind_a2_c1)->setCaras(ind_nueva_cara1,ind_c1_vecina2);
    }
    if(ind_p_c2 != -1) {

        indice_puntos.push_back(ind_p2);
        indice_puntos.push_back(ind_nuevo_nodo);
        indice_puntos.push_back(ind_p_c2);

        indice_arcos.push_back(ind_nuevo_arco_p2);
        indice_arcos.push_back(ind_nuevo_arco_p_c2);
        indice_arcos.push_back(ind_a1_c2);

        ind_nueva_cara3 = caras->addCara(new Cara(indice_puntos,indice_arcos));
        nuevas_caras.push_back(ind_nueva_cara3);
        arcos->setCaraArco(ind_nuevo_arco_p_c2,ind_nueva_cara3);
        arcos->setCaraArco(ind_nuevo_arco_p2,ind_nueva_cara3);
        //Le seteamos esta cara al nodo insertado
        nodos->addCaraNodo(ind_nuevo_nodo,ind_nueva_cara3);

        indice_puntos[0] = ind_p1;
        indice_puntos[1] = ind_p_c2;
        indice_puntos[2] = ind_nuevo_nodo;
        indice_arcos[0] = ind_a2_c2;
        indice_arcos[1] = ind_nuevo_arco_p_c2;
        indice_arcos[2] = ind_nuevo_arco_p1;

        ind_nueva_cara4 = caras->addCara(new Cara(indice_puntos,indice_arcos));
        nuevas_caras.push_back(ind_nueva_cara4);
        arcos->setCaraArco(ind_nuevo_arco_p_c2,ind_nueva_cara4);
        arcos->setCaraArco(ind_nuevo_arco_p1,ind_nueva_cara4);
        //Le seteamos esta cara al nodo insertado
        nodos->addCaraNodo(ind_nuevo_nodo,ind_nueva_cara4);

        indice_puntos.clear();
        indice_arcos.clear();

        //actualizamos los indices del nodo p_cara2 hacia sus arcos y caras
        nodos->getNodo(ind_p_c2)->eraseCara(ind_c2);
        nodos->getNodo(ind_p_c2)->addCara(ind_nueva_cara3);
        nodos->getNodo(ind_p_c2)->addCara(ind_nueva_cara4);
        nodos->getNodo(ind_p_c2)->addArco(ind_nuevo_arco_p_c2);

        //actualizamos los indices de los arcos que apuntan hacia las nuevas caras
        arcos->getArco(ind_a1_c2)->setCaras(ind_nueva_cara3,ind_c2_vecina1);
        arcos->getArco(ind_a2_c2)->setCaras(ind_nueva_cara4,ind_c2_vecina2);
    }

    //actualizamos los indices del nodo p1 hacia sus arcos y caras
    nodos->getNodo(ind_p1)->eraseCara(ind_c1);
    nodos->getNodo(ind_p1)->eraseCara(ind_c2);
    nodos->getNodo(ind_p1)->addCara(ind_nueva_cara1);
    nodos->getNodo(ind_p1)->addCara(ind_nueva_cara4);
    nodos->getNodo(ind_p1)->eraseArco(ind_arco);
    nodos->getNodo(ind_p1)->addArco(ind_nuevo_arco_p1);

    //actualizamos los indices del nodo p2 hacia sus arcos y caras
    nodos->getNodo(ind_p2)->eraseCara(ind_c1);
    nodos->getNodo(ind_p2)->eraseCara(ind_c2);
    nodos->getNodo(ind_p2)->addCara(ind_nueva_cara2);
    nodos->getNodo(ind_p2)->addCara(ind_nueva_cara3);
    nodos->getNodo(ind_p2)->eraseArco(ind_arco);
    nodos->getNodo(ind_p2)->addArco(ind_nuevo_arco_p2);

    if(retorna == 1) {
        return nuevas_caras;
    }
    else {
        return nuevos_arcos;
    }
}


int Malla::checkMalla(){
	//Chequeamos los nodos.
	for(int i=0; i<nodos->getNumNodos(); i++)
			if(nodos->getNodo(i)!=NULL)
				if(checkNodo(i)==-1){
					cout << "Hay errores en la malla." << endl;
					return -1;
					}

	//Chequeamos los arcos.
	for(int i=0; i<arcos->getNumArcos(); i++)
			if(arcos->getArco(i)!=NULL)
				if(checkArco(i)==-1){
					cout << "Hay errores en la malla." << endl;
					return -1;
					}

	//Chequeamos las caras.
	for(int i=0; i<caras->getNumCaras(); i++)
			if(caras->getCara(i)!=NULL)
				if(checkCara(i)==-1){
					cout << "Hay errores en la malla." << endl;
					return -1;
					}

	cout << "La malla esta correcta." << endl;
	return 0;
	}

int Malla::checkNodo(int indNodo){
	Nodo* nodo=nodos->getNodo(indNodo);
	vector<int> indCaras=nodo->getCaras();
	vector<int> indArcos=nodo->getArcos();
	for (int i=0; i<(int)indCaras.size(); i++)
		if (caras->getCara(indCaras[i])==NULL){
			cout << "Error en la Malla. Nodo " << indNodo << " apunta a Cara Vecina " << indCaras[i] << " la cual es nula." << endl;
			return -1;
			}
	for (int i=0; i<(int)indArcos.size(); i++)
		if (arcos->getArco(indArcos[i])==NULL){
			cout << "Error en la Malla. Nodo " << indNodo << " apunta a Arco Vecino " << indArcos[i] << " el cual es nulo." << endl;
			return -1;
			}

	return 0;
	}

int Malla::checkArco(int indArco){
	Arco* arco=arcos->getArco(indArco);

	if (arco->getCara1()!=-1 && caras->getCara(arco->getCara1())==NULL){
		cout << "Error en la Malla. Arco " << indArco << " apunta a Cara Vecina " << arco->getCara1() << " la cual es nula." << endl;
		return -1;
		}
	if (arco->getCara2()!=-1 && caras->getCara(arco->getCara2())==NULL){
		cout << "Error en la Malla. Arco " << indArco << " apunta a Cara Vecina " << arco->getCara2() << " la cual es nula." << endl;
		return -1;
		}
	if (arco->getNodo1()!=-1 && nodos->getNodo(arco->getNodo1())==NULL){
		cout << "Error en la Malla. Arco " << indArco << " apunta a Nodo Vecino " << arco->getNodo1() << " el cual es nulo." << endl;
		return -1;
		}
	if (arco->getNodo2()!=-1 && nodos->getNodo(arco->getNodo2())==NULL){
		cout << "Error en la Malla. Arco " << indArco << " apunta a Nodo Vecino " << arco->getNodo2() << " el cual es nulo." << endl;
		return -1;
		}

	return 0;
	}

int Malla::checkCara(int indCara){
	Cara* cara=caras->getCara(indCara);
	vector<int> indNodos=cara->getNodos();
	vector<int> indArcos=cara->getArcos();
	for (int i=0; i<(int)indNodos.size(); i++)
		if (nodos->getNodo(indNodos[i])==NULL){
			cout << "Error en la Malla. Cara " << indCara << " apunta a Nodo Vecino " << indNodos[i] << " el cual es nulo." << endl;
			return -1;
			}
	for (int i=0; i<(int)indArcos.size(); i++)
		if (arcos->getArco(indArcos[i])==NULL){
			cout << "Error en la Malla. Cara " << indCara << " apunta a Arco Vecino " << indArcos[i] << " el cual es nulo." << endl;
			return -1;
			}

	return 0;
	}

int Malla::vertexDeletion(int indArcoAColapsar, int indVerticeABorrar){
	assert(arcos->getArco(indArcoAColapsar) != NULL);
	assert(nodos->getNodo(indVerticeABorrar) != NULL);

	//Omitiremos los bordes por ahora.
	/*vector<int> carasVecinasAlVertice=nodos->getNodo(indVerticeABorrar)->getCaras();
	for (int i=0; i<(int)carasVecinasAlVertice.size(); i++)
		if (esCaraBorde(carasVecinasAlVertice[i]))
			return -1;*/

	//Se omite si el vertice esta en el borde.
	if (esNodoBorde(indVerticeABorrar))
		return -1;

	//Obtenemos el vertice a mantener.
	int indVerticeAMantener;
	if(arcos->getArco(indArcoAColapsar)->getNodo1()!=indVerticeABorrar)
		indVerticeAMantener=arcos->getArco(indArcoAColapsar)->getNodo1();
	else
		indVerticeAMantener=arcos->getArco(indArcoAColapsar)->getNodo2();

	//Obtenemos las caras que van a ser borradas.
	int indCaraABorrar1=arcos->getArco(indArcoAColapsar)->getCara1();
	int indCaraABorrar2=arcos->getArco(indArcoAColapsar)->getCara2();

	//Obtenemos las caras reemplazantes.
	int indCaraAReemplazar1=getCaraOpuestaNodo(indCaraABorrar1,indVerticeAMantener);
	int indCaraAReemplazar2=getCaraOpuestaNodo(indCaraABorrar2,indVerticeAMantener);

	//Obtenemos los arcos que van a ser borrados.
	int indArcoABorrar1=getArcoOpuestoNodo(indCaraABorrar1,indVerticeAMantener);
	int indArcoABorrar2=getArcoOpuestoNodo(indCaraABorrar2,indVerticeAMantener);

	//Obtenemos los arcos que se van a mantener.
	int indArcoAMantener1=getArcoOpuestoNodo(indCaraABorrar1,indVerticeABorrar);
	int indArcoAMantener2=getArcoOpuestoNodo(indCaraABorrar2,indVerticeABorrar);

	//Obtenemos las caras que deben ser modificadas.
	vector<int> indCarasAModificar;
	vector<int> indCarasVecinasAlNodo=nodos->getNodo(indVerticeABorrar)->getCaras();
	for (int i=0; i<(int)indCarasVecinasAlNodo.size(); i++)
		if (indCarasVecinasAlNodo[i]!=indCaraABorrar1 && indCarasVecinasAlNodo[i]!=indCaraABorrar2)
			indCarasAModificar.push_back(indCarasVecinasAlNodo[i]);



	//Chequeamos si se puede hacer el vertexDeletion.
	//Vemos si alguna cara se voltearia al hacerlo.
	for (int i=0; i<(int)indCarasAModificar.size(); i++){
		int indCara=indCarasAModificar[i];
		Nodo* verticeABorrar=getNodos()->getNodo(indVerticeABorrar);
		Nodo* verticeAMantener=getNodos()->getNodo(indVerticeAMantener);
		Vect viejaNormal=getNormal(indCara);
		Punto* viejoPunto=verticeABorrar->getPunto();
		Punto* nuevoPunto=verticeAMantener->getPunto();
		verticeABorrar->setPunto(nuevoPunto);
		Vect nuevaNormal=getNormal(indCara);
		verticeABorrar->setPunto(viejoPunto);
		if (viejaNormal.inOrigen() || nuevaNormal.inOrigen()) //Por problema de precision no se puede calcular la normal.
			return -1;
		double angulo=viejaNormal.getAngulo(nuevaNormal);
		if (angulo>PI/2)
			return -1;
		}

	//Chequeamos si se puede hacer el vertexDeletion.
	//Vemos si hay caras vecinas a las caras a borrar que son vecinas entre ellas.
	int ind_p1=indVerticeABorrar;
	int ind_p2=indVerticeAMantener;
	int ind_c1=indCaraABorrar1;
	int ind_c2=indCaraABorrar2;
	int ind_c1_vecina1 = getCaraOpuestaNodo(ind_c1, ind_p1);
    int ind_c1_vecina2 = getCaraOpuestaNodo(ind_c1, ind_p2);
    int ind_c2_vecina1 = getCaraOpuestaNodo(ind_c2, ind_p1);
    int ind_c2_vecina2 = getCaraOpuestaNodo(ind_c2, ind_p2);
	if(this->sonCarasVecinas(ind_c1_vecina1,ind_c1_vecina2) || this->sonCarasVecinas(ind_c2_vecina1,ind_c2_vecina2))
		return -1;


	//Modificamos las caras.
	for (int i=0; i<(int)indCarasAModificar.size(); i++){
		Cara* caraAModificar=caras->getCara(indCarasAModificar[i]);
		//Modificamos sus nodos.
		caraAModificar->changeNodo(indVerticeABorrar,indVerticeAMantener);
		for (int j=0; j<(int)caraAModificar->getNodos().size(); j++){
			int indNodoAModificar=caraAModificar->getNodos()[j];
			Nodo* nodoAModificar=nodos->getNodo(indNodoAModificar);
			nodoAModificar->eraseCara(indCaraABorrar1);
			nodoAModificar->eraseCara(indCaraABorrar2);
			nodoAModificar->eraseArco(indArcoABorrar1);
			nodoAModificar->eraseArco(indArcoABorrar2);
			}
		//Modificamos sus arcos.
		for (int j=0; j<(int)caraAModificar->getArcos().size(); j++){
			int indArcoAModificar=caraAModificar->getArcos()[j];
			Arco* arcoAModificar=arcos->getArco(indArcoAModificar);
			if (indArcoAModificar==indArcoABorrar1)
				caraAModificar->changeArco(indArcoAModificar,indArcoAMantener1);	//Cambiamos el arco.
			else if (indArcoAModificar==indArcoABorrar2)
				caraAModificar->changeArco(indArcoAModificar,indArcoAMantener2);	//Cambiamos el arco.
			else if (arcoAModificar->getNodo1()==indVerticeABorrar)
				arcoAModificar->setNodo1(indVerticeAMantener);
			else if (arcoAModificar->getNodo2()==indVerticeABorrar)
				arcoAModificar->setNodo2(indVerticeAMantener);

			}
		}

	//Modificamos los nodos mantenido.
	Nodo* verticeAMantener=nodos->getNodo(indVerticeAMantener);
	verticeAMantener->eraseCara(indCaraABorrar1);
	verticeAMantener->eraseCara(indCaraABorrar2);
	verticeAMantener->eraseArco(indArcoABorrar1);
	verticeAMantener->eraseArco(indArcoABorrar2);
	verticeAMantener->eraseArco(indArcoAColapsar);
	for (int i=0; i<(int)indCarasAModificar.size(); i++){
		verticeAMantener->addCara(indCarasAModificar[i]);
		Cara* cara=caras->getCara(indCarasAModificar[i]);
		for (int j=0; j<(int)cara->getArcos().size(); j++){
			int indArco=cara->getArcos()[j];
			Arco* arco=arcos->getArco(indArco);
			if (indArco!=indArcoAMantener1 && indArco!=indArcoAMantener2 &&
				(arco->getNodo1()==indVerticeAMantener || arco->getNodo2()==indVerticeAMantener))
					verticeAMantener->addArco(indArco);
			}
		}

	//Modificamos los arcos mantenidos.
	Arco* arcoAMantener1=arcos->getArco(indArcoAMantener1);
	if (arcoAMantener1->getCara1()==indCaraABorrar1)
		arcoAMantener1->setCara1(indCaraAReemplazar1);
	else if (arcoAMantener1->getCara2()==indCaraABorrar1)
		arcoAMantener1->setCara2(indCaraAReemplazar1);

	Arco* arcoAMantener2=arcos->getArco(indArcoAMantener2);
	if (arcoAMantener2->getCara1()==indCaraABorrar2)
		arcoAMantener2->setCara1(indCaraAReemplazar2);
	else if (arcoAMantener2->getCara2()==indCaraABorrar2)
		arcoAMantener2->setCara2(indCaraAReemplazar2);

	//Borramos
	nodos->eraseNodo(indVerticeABorrar);
	caras->eraseCara(indCaraABorrar1);
	caras->eraseCara(indCaraABorrar2);
	arcos->eraseArco(indArcoABorrar1);
	arcos->eraseArco(indArcoABorrar2);
	arcos->eraseArco(indArcoAColapsar);

	return 0;
	}

bool Malla::esNodoBorde(int indNodo){
	vector<int> arcos=getNodo(indNodo)->getArcos();
	for (int i=0; i<(int)arcos.size(); i++)
		if (esArcoBorde(arcos[i]))
			return true;

	return false;
	}

int Malla::edgeCollapse2(int ind_arco, double dist) {
	int indNodo1=arcos->getArco(ind_arco)->getNodo1();
	int indNodo2=arcos->getArco(ind_arco)->getNodo2();

	//Si el nodo que vamos a hacerle el deletion esta en el borde, le hacemos el deletion al
	//nodo opuesto.
	if(esNodoBorde(indNodo1)){
		int aux=indNodo2;
		indNodo2=indNodo1;
		indNodo1=aux;
		}

	Nodo* nodo1=nodos->getNodo(indNodo1);
	Nodo* nodo2=nodos->getNodo(indNodo2);
	Punto* A = nodo1->getPunto();
    Punto* B = nodo2->getPunto();
	Vect vectA(A->getX(),A->getY(),A->getZ());
	Vect vectB(B->getX(),B->getY(),B->getZ());
	Vect AMenosB= vectA-vectB;
	Vect distAMenosB=AMenosB*dist;
	Vect P=vectB+distAMenosB;
	int resultado=vertexDeletion(ind_arco,indNodo1);
	if (resultado!=-1){
		nodo2->getPunto()->setX(P.getPunto().getX());
		nodo2->getPunto()->setY(P.getPunto().getY());
		nodo2->getPunto()->setZ(P.getPunto().getZ());
		}

	return resultado;
	}

int Malla::edgeCollapse(int ind_arco, double dist) {
    assert((ind_arco < arcos->getNumArcos()) && (ind_arco >= 0));
    assert(dist>=0 && dist<=1);
    assert(arcos->getArco(ind_arco) != NULL);


    int ind_c1 = arcos->getArco(ind_arco)->getCara1();
    int ind_c2 = arcos->getArco(ind_arco)->getCara2();

    //obtenemos los indices de los 4 puntos
    int ind_p1 = arcos->getArco(ind_arco)->getNodo1();
    int ind_p2 = arcos->getArco(ind_arco)->getNodo2();
    int ind_p_c1 = this->getNodoOpuestoArco(ind_c1,ind_arco);
    int ind_p_c2 = this->getNodoOpuestoArco(ind_c2,ind_arco);

    //obtenemos los indices de los arcos
    int ind_a1_c1 = this->getArcoOpuestoNodo(ind_c1,ind_p1);
    int ind_a2_c1 = this->getArcoOpuestoNodo(ind_c1,ind_p2);
    int ind_a1_c2 = this->getArcoOpuestoNodo(ind_c2,ind_p1);
    int ind_a2_c2 = this->getArcoOpuestoNodo(ind_c2,ind_p2);

    //obtenemos los indices de las caras vecinas, pueden ser -1 si no hay cara vecina
    int ind_c1_vecina1 = getCaraOpuestaNodo(ind_c1, ind_p1);
    int ind_c1_vecina2 = getCaraOpuestaNodo(ind_c1, ind_p2);
    int ind_c2_vecina1 = getCaraOpuestaNodo(ind_c2, ind_p1);
    int ind_c2_vecina2 = getCaraOpuestaNodo(ind_c2, ind_p2);
	/*if(ind_c1_vecina1!=-1 && getCara(ind_c1_vecina1)==NULL) ind_c1_vecina1=-1;
	if(ind_c1_vecina2!=-1 && getCara(ind_c1_vecina2)==NULL) ind_c1_vecina2=-1;
	if(ind_c2_vecina1!=-1 && getCara(ind_c2_vecina1)==NULL) ind_c2_vecina1=-1;
	if(ind_c2_vecina2!=-1 && getCara(ind_c2_vecina2)==NULL) ind_c2_vecina2=-1;*/

    if(ind_c1 != -1 && ind_c1_vecina1 == -1 && ind_c1_vecina2 == -1) {
        //No se puede reducir el arco
        return -1;
    }
    if(ind_c2 != -1 && ind_c2_vecina1 == -1 && ind_c2_vecina2 == -1) {
        //No se puede reducir el arco
        return -1;
    }

    if(this->sonCarasVecinas(ind_c1_vecina1,ind_c1_vecina2) || this->sonCarasVecinas(ind_c2_vecina1,ind_c2_vecina2)) {
        int nuevo_arco = this->edgeFlip(ind_arco);
		cerr << "Hago edge-flip sobre arco " << ind_arco << " con resultado nuevo_arco = " << nuevo_arco << endl;
		if(nuevo_arco != -1) {
            this->edgeCollapse(nuevo_arco,dist);
        }
        return -1;
    }

    vector<int> ind_arcos_p1 = nodos->getNodo(ind_p1)->getArcos();
    vector<int> ind_arcos_p2 = nodos->getNodo(ind_p2)->getArcos();
    vector<int> ind_caras_p1 = nodos->getNodo(ind_p1)->getCaras();
    vector<int> ind_caras_p2 = nodos->getNodo(ind_p2)->getCaras();

    //borramos las 2 caras
    if(ind_c1 != -1) {
        caras->eraseCara(ind_c1);
    }
    if(ind_c2 != -1) {
        caras->eraseCara(ind_c2);
    }

    //borramos el arco dado como parametro
    arcos->eraseArco(ind_arco);
//     cout << "Borrando arco:" << ind_arco << endl;
    //borramos los 4 otros arcos que formaban las caras
    if(ind_a1_c1 != -1) {
        arcos->eraseArco(ind_a1_c1);
    }
    if(ind_a1_c2 != -1) {
        arcos->eraseArco(ind_a1_c2);
    }
    if(ind_a2_c1 != -1) {
        arcos->eraseArco(ind_a2_c1);
    }
    if(ind_a2_c2 != -1) {
        arcos->eraseArco(ind_a2_c2);
    }

    // obtenemos la informacion que necesitamos de los nodos p1 y p2 antes de borrarlos
    Punto *p1 = nodos->getNodo(ind_p1)->getPunto();
    Punto *p2 = nodos->getNodo(ind_p2)->getPunto();
    Vect vp1(*p1);
    Vect vp2(*p2);

    Vect *normal_p1 = nodos->getNodo(ind_p1)->getNormal();
    Vect *normal_p2 = nodos->getNodo(ind_p2)->getNormal();

    //agregamos el nuevo nodo y le seteamos su normal
    Vect v_p1_p2 = vp2 - vp1;
    v_p1_p2 = v_p1_p2 * dist;
    Vect vp = vp1 + v_p1_p2;

    //le seteamos su normal como el promedio de las normales de sus nodos vecinos
    Vect normal_prom = *normal_p1 + *normal_p2;
    if(normal_prom.largo() != 0) {
        normal_prom = normal_prom * (1/normal_prom.largo()); // se normaliza
    }

	//borramos los 2 nodos
    nodos->eraseNodo(ind_p1);
    nodos->eraseNodo(ind_p2);

	//creamos el nuevo nodo
	Punto *p=new Punto(vp.getPunto().getX(),vp.getPunto().getY(),vp.getPunto().getZ());
	Nodo *nuevo_nodo = new Nodo(p);
    int ind_nuevo_nodo = nodos->addNodo(nuevo_nodo);
    nodos->getNodo(ind_nuevo_nodo)->setNormal(normal_prom);
    //this->setNormal(ind_nuevo_nodo,normal_prom);

    //agregamos los nuevos arcos, seteandole sus caras. Ademas al nuevo nodo le seteamos estos arcos y actualizamos p_c1 y p_c2
    int ind_nuevo_arco_p_c1 = -1;
    int ind_nuevo_arco_p_c2 = -1;
    if(ind_p_c1 != -1) {
        //agregamos el nuevo arco
        assert(nodos->getNodo(ind_p_c1) != 0 && nodos->getNodo(ind_nuevo_nodo) != 0);
        ind_nuevo_arco_p_c1 = arcos->addArco(new Arco(ind_p_c1,ind_nuevo_nodo));
        //le seteamos sus caras
        cout << "Nuevo arco = " << ind_nuevo_arco_p_c1 << endl;
        arcos->getArco(ind_nuevo_arco_p_c1)->setCaras(ind_c1_vecina1,ind_c1_vecina2);
        //seteamos este arco al nuevo nodo
        nodos->getNodo(ind_nuevo_nodo)->addArco(ind_nuevo_arco_p_c1);
        //actualizamos el nodo p_c1
        nodos->getNodo(ind_p_c1)->eraseCara(ind_c1);
        nodos->getNodo(ind_p_c1)->eraseArco(ind_a1_c1);
        nodos->getNodo(ind_p_c1)->eraseArco(ind_a2_c1);
        nodos->getNodo(ind_p_c1)->addArco(ind_nuevo_arco_p_c1);
    }
    if(ind_p_c2 != -1) {
        //agregamos el nuevo arco
        assert(nodos->getNodo(ind_p_c2) != 0 && nodos->getNodo(ind_nuevo_nodo) != 0);
        ind_nuevo_arco_p_c2 = arcos->addArco(new Arco(ind_p_c2,ind_nuevo_nodo));
        //le seteamos sus caras
        cout << "Nuevo arco = " << ind_nuevo_arco_p_c2 << endl;
        assert(ind_c2_vecina1 != ind_c2_vecina2);
        arcos->getArco(ind_nuevo_arco_p_c2)->setCaras(ind_c2_vecina1,ind_c2_vecina2);
        //seteamos este arco al nuevo nodo
        nodos->getNodo(ind_nuevo_nodo)->addArco(ind_nuevo_arco_p_c2);
        //actualizamos el nodo p_c2
        nodos->getNodo(ind_p_c2)->eraseCara(ind_c2);
        nodos->getNodo(ind_p_c2)->eraseArco(ind_a1_c2);
        nodos->getNodo(ind_p_c2)->eraseArco(ind_a2_c2);
        nodos->getNodo(ind_p_c2)->addArco(ind_nuevo_arco_p_c2);
    }

    //actualizamos los arcos de las caras vecinas.
    if(ind_c1_vecina2 != -1) {
        caras->getCara(ind_c1_vecina2)->eraseArco(ind_a2_c1);
        caras->getCara(ind_c1_vecina2)->addArco(ind_nuevo_arco_p_c1);
    }
    if(ind_c1_vecina1 != -1) {
		//cerr << "aux " << caras->getCara(ind_c1_vecina1)->getNumElem() << endl;
		//cerr << "aux " << caras->getCara(ind_c1_vecina1) << endl;
        caras->getCara(ind_c1_vecina1)->eraseArco(ind_a1_c1);
        caras->getCara(ind_c1_vecina1)->addArco(ind_nuevo_arco_p_c1);
    }
    if(ind_c2_vecina2 != -1) {
        caras->getCara(ind_c2_vecina2)->eraseArco(ind_a2_c2);
        caras->getCara(ind_c2_vecina2)->addArco(ind_nuevo_arco_p_c2);
    }
    if(ind_c2_vecina1 != -1) {
        caras->getCara(ind_c2_vecina1)->eraseArco(ind_a1_c2);
        caras->getCara(ind_c2_vecina1)->addArco(ind_nuevo_arco_p_c2);
    }

    //Le seteamos los arcos y caras al nodo insertado (las que tenian p1 y p2)
    //seteo de arcos que tenia p1 menos los que ya no estan:
    for(int i=0; i<(int)ind_arcos_p1.size(); i++) {
        if(ind_arcos_p1[i] != ind_arco && ind_arcos_p1[i] != ind_a2_c1 && ind_arcos_p1[i] != ind_a2_c2) {
            nodos->getNodo(ind_nuevo_nodo)->addArco(ind_arcos_p1[i]);
        }
    }
    //seteo de arcos que tenia p2 menos los que ya no estan:
    for(int i=0; i<(int)ind_arcos_p2.size(); i++) {
        if(ind_arcos_p2[i] != ind_arco && ind_arcos_p2[i] != ind_a1_c1 && ind_arcos_p2[i] != ind_a1_c2) {
            nodos->getNodo(ind_nuevo_nodo)->addArco(ind_arcos_p2[i]);
        }
    }

    //seteo de caras que tenia p1 menos las que ya no estan:
    for(int i=0; i<(int)ind_caras_p1.size(); i++) {
        if(ind_caras_p1[i] != ind_c1 && ind_caras_p1[i] != ind_c2) {
            nodos->getNodo(ind_nuevo_nodo)->addCara(ind_caras_p1[i]);
        }
    }
    //seteo de caras que tenia p2 menos las que ya no estan:
    for(int i=0; i<(int)ind_caras_p2.size(); i++) {
        if(ind_caras_p2[i] != ind_c1 && ind_caras_p2[i] != ind_c2) {
            nodos->getNodo(ind_nuevo_nodo)->addCara(ind_caras_p2[i]);
        }
    }

    //actualizamos los nodos de los arcos que tenian como nodo los que ya no estan
    vector<int> arcos_nuevo_nodo = nodos->getNodo(ind_nuevo_nodo)->getArcos();
    for(int i=0; i<(int)arcos_nuevo_nodo.size(); i++) {
        if(arcos_nuevo_nodo[i] != ind_nuevo_arco_p_c1 && arcos_nuevo_nodo[i] != ind_nuevo_arco_p_c2) {
            if(arcos->getArco(arcos_nuevo_nodo[i])->getNodo1() == ind_p1 || arcos->getArco(arcos_nuevo_nodo[i])->getNodo1() == ind_p2) {
                arcos->getArco(arcos_nuevo_nodo[i])->setNodo1(ind_nuevo_nodo);
            }
            else {
                arcos->getArco(arcos_nuevo_nodo[i])->setNodo2(ind_nuevo_nodo);
            }
        }
    }

    //actualizamos los nodos de las caras que tenian como nodo los que ya no estan
    vector<int> caras_nuevo_nodo = nodos->getNodo(ind_nuevo_nodo)->getCaras();
    for(int i=0; i<(int)caras_nuevo_nodo.size(); i++) {
        if(caras_nuevo_nodo[i] != ind_c1 && caras_nuevo_nodo[i] != ind_c2) {
            caras->getCara(caras_nuevo_nodo[i])->changeNodo(ind_p1,ind_nuevo_nodo);
            caras->getCara(caras_nuevo_nodo[i])->changeNodo(ind_p2,ind_nuevo_nodo);
        }
    }
	return 0;
}

/*** OBTENCIÓN DE ÍNDICES: ***/
int Malla::getSiguienteCara(int indice, int ind_cara) {
    assert((indice < arcos->getNumArcos()) && (indice >= 0));
    assert((ind_cara < caras->getNumCaras()) && (ind_cara >= 0));

    int ind_c1 = arcos->getArco(indice)->getCara1();
    int ind_c2 = arcos->getArco(indice)->getCara2();

    if(ind_cara == ind_c1) {
        return ind_c2;
    }
    else if(ind_cara == ind_c2) {
        return ind_c1;
    }
    else {
        return -1;
    }
}

int Malla::getArcoOpuestoNodo(int ind_cara, int ind_nodo) {
    assert((ind_nodo < nodos->getNumNodos()) && (ind_nodo >= 0));
    assert((ind_cara < caras->getNumCaras()) && (ind_cara >= -1));

    if(ind_cara == -1) {
        return -1;
    }

    vector<int> ind_arcos = caras->getCara(ind_cara)->getArcos();
    for(int i=0; i<(int)ind_arcos.size(); i++) {
        int ind1 = arcos->getArco(ind_arcos[i])->getNodo1();
        int ind2 = arcos->getArco(ind_arcos[i])->getNodo2();
        if(ind_nodo != ind1 && ind_nodo != ind2) {
            return ind_arcos[i];
        }
    }
    return -1;
}

int Malla::getNodoOpuestoNodo(int ind_cara, int ind_nodo) {
    assert((ind_nodo < nodos->getNumNodos()) && (ind_nodo >= 0));
    assert((ind_cara < caras->getNumCaras()) && (ind_cara >= 0));

    int ind_arco = this->getArcoOpuestoNodo(ind_cara, ind_nodo);
    int ind_cara_vecina = this->getSiguienteCara(ind_arco,ind_cara);
    return this->getNodoOpuestoArco(ind_cara_vecina,ind_arco);
}

int Malla::getNodoOpuestoArco(int ind_cara, int ind_arco) {
    assert((ind_cara < caras->getNumCaras()) && (ind_cara >= -1));
    assert((ind_arco < arcos->getNumArcos()) && (ind_arco >= 0));

    if(ind_cara == -1) {
        return -1;
    }

    vector<int> ind_nodos = caras->getCara(ind_cara)->getNodos();
    vector<int> ind_arcos = caras->getCara(ind_cara)->getArcos();
    int ind1 = arcos->getArco(ind_arco)->getNodo1();
    int ind2 = arcos->getArco(ind_arco)->getNodo2();
    for(int i=0; i<(int)ind_nodos.size(); i++) {
        if(ind_nodos[i] != ind1 && ind_nodos[i] != ind2) {
            return ind_nodos[i];
        }
    }
    return -1;
}

int Malla::getCaraOpuestaNodo(int ind_cara, int ind_nodo) {
    assert((ind_nodo < nodos->getNumNodos()) && (ind_nodo >= 0));
    assert((ind_cara < caras->getNumCaras()) && (ind_cara >= -1));

    if(ind_cara == -1) {
        return -1;
    }

    int ind_arco = this->getArcoOpuestoNodo(ind_cara, ind_nodo);
    int ind_cara_vecina = this->getSiguienteCara(ind_arco,ind_cara);

    return ind_cara_vecina;
}


/*** OTROS MÉTODOS: ***/
/*void Malla::setNormales() {
    vector<Vect*> normales;
    Vect *normal;
    for(int i=0; i<(int)caras->getNumCaras(); i++) {
        if(caras->getCara(i) != 0) {
            normal = this->getNormal(i);
            normal = (*normal)*(1/normal->largo());
            normales.push_back(normal);
        }
    }
	assert (normales[98]->getPunto()!=NULL);
    vector<int> ind_caras;
    for(int i=0; i<nodos->getNumNodos(); i++){
        if(nodos->getNodo(i) != 0) {
            ind_caras = nodos->getNodo(i)->getCaras();
            normal = normales[ind_caras[0]];
            for(int j=1; j<(int)ind_caras.size(); j++) {
				cerr << "indcaras[j]=" << ind_caras[j] << endl;
                normal = (*normal) + normales[ind_caras[j]];
            }
            nodos->getNodo(i)->setNormal(normal);
        }
    }
}*/

void Malla::setNormales() {

	for(int i=0; i<nodos->getNumNodos(); i++){
        if(nodos->getNodo(i) != 0) {
			vector<int> ind_caras = nodos->getNodo(i)->getCaras();
			Vect normal;
			for (int j=0; j<(int)ind_caras.size(); j++){
				normal = getNormal(ind_caras[j]) + normal;
				}
			normal = normal*(1/normal.largo());
			nodos->getNodo(i)->setNormal(normal);
			}
		}


	}

void Malla::setNormal(int ind_nodo, Vect normal) {
    if(ind_nodo == -1) {
        return;
    }
    assert((ind_nodo < nodos->getNumNodos()) && (ind_nodo >= 0) && nodos->getNodo(ind_nodo) != 0);
    nodos->getNodo(ind_nodo)->setNormal(normal);
}

void Malla::setConcentracionTodos(double val) {
    for(int i=0; i<nodos->getNumNodos(); i++){
        if(nodos->getNodo(i) != 0) {
            nodos->getNodo(i)->setConcentracion(val);
        }
    }
}

Vect Malla::getNormalNodos(int ind_p1, int ind_p2, int ind_p3) {
    assert((ind_p1 < nodos->getNumNodos()) && (ind_p1 >= 0));
    assert((ind_p2 < nodos->getNumNodos()) && (ind_p2 >= 0));
    assert((ind_p3 < nodos->getNumNodos()) && (ind_p3 >= 0));
    Punto *p1,*p2,*p3;
    p1 = nodos->getNodo(ind_p1)->getPunto();
    p2 = nodos->getNodo(ind_p2)->getPunto();
    p3 = nodos->getNodo(ind_p3)->getPunto();
    Vect vp1(*p1);
    Vect vp2(*p2);
    Vect vp3(*p3);
    Vect v12 = vp2 - vp1;
    Vect v23 = vp3 - vp2;
    Vect N = v12.prodCruz(v23);
    return N;
}


/*** MÉTODOS DIRIGIDOS AL DESPLAZAMIENTO DE LA MALLA: ***/
vector<double> Malla::getValoresVolumenCero(int ind_arco) {
    assert((ind_arco < arcos->getNumArcos()) && (ind_arco >= 0));

    vector<double> raices;

    int ind_c1 = arcos->getArco(ind_arco)->getCara1();
    int ind_c2 = arcos->getArco(ind_arco)->getCara2();

    if(ind_c1 < 0 || ind_c2 < 0) {
        return raices; // este arco no define 2 caras --> region borde.
    }

    //sacamos los indices de los 4 puntos
    int ind_p1 = arcos->getArco(ind_arco)->getNodo1();
    int ind_p2 = arcos->getArco(ind_arco)->getNodo2();
    int ind_p_cara1 = this->getNodoOpuestoArco(ind_c1,ind_arco);
    int ind_p_cara2 = this->getNodoOpuestoArco(ind_c2,ind_arco);

    Punto *p1 = nodos->getNodo(ind_p1)->getPunto();
    Punto *p2 = nodos->getNodo(ind_p2)->getPunto();
    Punto *p3 = nodos->getNodo(ind_p_cara1)->getPunto();
    Punto *p4 = nodos->getNodo(ind_p_cara2)->getPunto();

    //Obtenemos los vectores normales a cada nodo y los multiplicamos por su concentración.
    Vect *norm1 = nodos->getNodo(ind_p1)->getNormal();
    Vect normal1 = *norm1 * nodos->getNodo(ind_p1)->getConcentracion();
    Vect *norm2 = nodos->getNodo(ind_p2)->getNormal();
    Vect normal2 = *norm2 * nodos->getNodo(ind_p2)->getConcentracion();
    Vect *norm3 = nodos->getNodo(ind_p_cara1)->getNormal();
    Vect normal3 = *norm3 * nodos->getNodo(ind_p_cara1)->getConcentracion();
    Vect *norm4 = nodos->getNodo(ind_p_cara2)->getNormal();
    Vect normal4 = *norm4 * nodos->getNodo(ind_p_cara2)->getConcentracion();

	Polinomio* aux1;
	Polinomio* aux2;

    vector<Polinomio*> pol1;
    pol1.push_back(new Polinomio(p1->getX(),normal1.getPunto().getX()));
    pol1.push_back(new Polinomio(p1->getY(),normal1.getPunto().getY()));
    pol1.push_back(new Polinomio(p1->getZ(),normal1.getPunto().getZ()));

    vector<Polinomio*> pol2;
    pol2.push_back(new Polinomio(p2->getX(),normal2.getPunto().getX()));
    pol2.push_back(new Polinomio(p2->getY(),normal2.getPunto().getY()));
    pol2.push_back(new Polinomio(p2->getZ(),normal2.getPunto().getZ()));

    vector<Polinomio*> pol3;
    pol3.push_back(new Polinomio(p3->getX(),normal3.getPunto().getX()));
    pol3.push_back(new Polinomio(p3->getY(),normal3.getPunto().getY()));
    pol3.push_back(new Polinomio(p3->getZ(),normal3.getPunto().getZ()));

    vector<Polinomio*> pol4;
    pol4.push_back(new Polinomio(p4->getX(),normal4.getPunto().getX()));
    pol4.push_back(new Polinomio(p4->getY(),normal4.getPunto().getY()));
    pol4.push_back(new Polinomio(p4->getZ(),normal4.getPunto().getZ()));

    vector<Polinomio*> pol_a;
    pol_a.push_back((*pol2[0])-pol1[0]);
    pol_a.push_back((*pol2[1])-pol1[1]);
    pol_a.push_back((*pol2[2])-pol1[2]);

    vector<Polinomio*> pol_b;
    pol_b.push_back((*pol3[0])-pol1[0]);
    pol_b.push_back((*pol3[1])-pol1[1]);
    pol_b.push_back((*pol3[2])-pol1[2]);

    vector<Polinomio*> pol_c;
    pol_c.push_back((*pol4[0])-pol1[0]);
    pol_c.push_back((*pol4[1])-pol1[1]);
    pol_c.push_back((*pol4[2])-pol1[2]);

    vector<Polinomio*> pol_b_cruz_c;
    aux1=(*pol_b[1])*pol_c[2];
	aux2=(*pol_b[2])*pol_c[1];
	pol_b_cruz_c.push_back((*aux1)-aux2);
	delete aux1; delete aux2;
	aux1=(*pol_b[2])*pol_c[0];
	aux2=(*pol_b[0])*pol_c[2];
    pol_b_cruz_c.push_back((*aux1)-aux2);
	delete aux1; delete aux2;
	aux1=(*pol_b[0])*pol_c[1];
	aux2=(*pol_b[1])*pol_c[0];
    pol_b_cruz_c.push_back((*aux1)-aux2);
	delete aux1; delete aux2;
	//pol_b_cruz_c.push_back((*((*pol_b[1])*pol_c[2]))-((*pol_b[2])*pol_c[1]));
    //pol_b_cruz_c.push_back((*((*pol_b[2])*pol_c[0]))-((*pol_b[0])*pol_c[2]));
    //pol_b_cruz_c.push_back((*((*pol_b[0])*pol_c[1]))-((*pol_b[1])*pol_c[0]));

    vector<Polinomio*> pol_abc;
    pol_abc.push_back((*pol_a[0])*pol_b_cruz_c[0]);
    pol_abc.push_back((*pol_a[1])*pol_b_cruz_c[1]);
    pol_abc.push_back((*pol_a[2])*pol_b_cruz_c[2]);

	aux1=(*pol_abc[1])+pol_abc[2];
    Polinomio *final = (*pol_abc[0]) + aux1;
	delete aux1;

    int n;
    double x1, x2, x3;

    if((*final)[3] != 0) {
        n = final->getRaicesCubicas(x1,x2,x3);
        raices.push_back(x1);
        if(n == 3) {
            raices.push_back(x1);
            raices.push_back(x2);
            raices.push_back(x3);
        }
    }
    else if((*final)[2] != 0) {
        n = final->getRaicesCuadradas(x1,x2);
        if(n == 2) {
            raices.push_back(x1);
            raices.push_back(x2);
        }
    }
    else if((*final)[1] != 0){
        n = final->getRaizLineal(x1);
        raices.push_back(x1);
    }
    else {
        n = 0;
    }

	//Libero memoria de los polinomios usados.
	for (int i=0; i<(int)pol1.size() ; i++)
		delete pol1[i];
	for (int i=0; i<(int)pol2.size() ; i++)
		delete pol2[i];
	for (int i=0; i<(int)pol3.size() ; i++)
		delete pol3[i];
	for (int i=0; i<(int)pol4.size() ; i++)
		delete pol4[i];
	for (int i=0; i<(int)pol_a.size() ; i++)
		delete pol_a[i];
	for (int i=0; i<(int)pol_b.size() ; i++)
		delete pol_b[i];
	for (int i=0; i<(int)pol_c.size() ; i++)
		delete pol_c[i];
	for (int i=0; i<(int)pol_b_cruz_c.size() ; i++)
		delete pol_b_cruz_c[i];
	for (int i=0; i<(int)pol_abc.size() ; i++)
		delete pol_abc[i];
	delete final;

    return raices;
}

int Malla::getTipoMovRegion(int ind_arco, double val) {
    assert((ind_arco < arcos->getNumArcos()) && (ind_arco >= 0));

    int ind_c1 = arcos->getArco(ind_arco)->getCara1();
    int ind_c2 = arcos->getArco(ind_arco)->getCara2();

    if(ind_c1 < 0 || ind_c2 < 0) {
        return -1; // region borde
    }

    //obtenemos los indices de los 4 puntos
    int ind_p1 = arcos->getArco(ind_arco)->getNodo1();
    int ind_p2 = arcos->getArco(ind_arco)->getNodo2();
    int ind_p_c1 = this->getNodoOpuestoArco(ind_c1,ind_arco);
    int ind_p_c2 = this->getNodoOpuestoArco(ind_c2,ind_arco);

    //movemos los 4 nodos.
    nodos->moverNodoSegunConcentracion(ind_p1,val);
    nodos->moverNodoSegunConcentracion(ind_p2,val);
    nodos->moverNodoSegunConcentracion(ind_p_c1,val);
    nodos->moverNodoSegunConcentracion(ind_p_c2,val);

    int tipo_region = this->tipArco(ind_arco);

    //regresamos los 4 nodos.
    nodos->regresarNodoSegunConcentracion(ind_p1,val);
    nodos->regresarNodoSegunConcentracion(ind_p2,val);
    nodos->regresarNodoSegunConcentracion(ind_p_c1,val);
    nodos->regresarNodoSegunConcentracion(ind_p_c2,val);

    return tipo_region;
}

int Malla::tipArco(int ind_arco) {
    assert((ind_arco < arcos->getNumArcos()) && (ind_arco >= 0));

    int ind_c1 = arcos->getArco(ind_arco)->getCara1();
    int ind_c2 = arcos->getArco(ind_arco)->getCara2();

    if(ind_c1 < 0 || ind_c2 < 0) {
        return NO_TIP; // region borde ==> no hay tip
    }

    //obtenemos los indices de los 4 puntos
    int ind_p1 = arcos->getArco(ind_arco)->getNodo1();
    int ind_p2 = arcos->getArco(ind_arco)->getNodo2();
    int ind_p_c1 = this->getNodoOpuestoArco(ind_c1,ind_arco);
    int ind_p_c2 = this->getNodoOpuestoArco(ind_c2,ind_arco);

    Punto *p1 = nodos->getNodo(ind_p1)->getPunto();
    Punto *p2 = nodos->getNodo(ind_p2)->getPunto();
    Punto *p_c1 = nodos->getNodo(ind_p_c1)->getPunto();
    Punto *p_c2 = nodos->getNodo(ind_p_c2)->getPunto();

    //Vect *normal_c1 = this->getNormal(ind_c1);
    //Vect *v_p1_pc2 = (*p_c2) - p1;

    //double prod_punto = normal_c1->prodPunto(v_p1_pc2);

//     if(prod_punto >= 0.0000000000001 || prod_punto <= -0.0000000000001) {
//         return NO_TIP_YET;
//     }

    int tip_p_c1 = this->puntoInCara(p_c1,ind_c2);
    int tip_p_c2 = this->puntoInCara(p_c2,ind_c1);

    if(tip_p_c1 == TIP_ON_VERTEX || tip_p_c2 == TIP_ON_VERTEX) {
        return TIP_ON_VERTEX;
    }
    else if(tip_p_c1 == TIP_ON_EDGE || tip_p_c2 == TIP_ON_EDGE) {
        return TIP_ON_EDGE;
    }
    else if(tip_p_c1 == TIP_INSIDE || tip_p_c2 == TIP_INSIDE) {
        return TIP_INSIDE;
    }
    else {
        if(seCruzan(p1,p_c2,p2,p_c1) == 1 || seCruzan(p1,p_c1,p2,p_c2) == 1) {
            return TIP_OUTSIDE_A;
        }
        else {
            return TIP_OUTSIDE_B;
        }
    }
}

int Malla::puntoInCara(Punto *p, int ind_cara) {
    assert((ind_cara < caras->getNumCaras()) && (ind_cara >= -1));
    if(ind_cara == -1) {
        return NO_TIP;
    }

    Vect normal_cara = this->getNormal(ind_cara);
    vector<int> ind_puntos = caras->getCara(ind_cara)->getNodos();
    Punto *p0 = nodos->getNodo(ind_puntos[0])->getPunto();
    Punto *p1 = nodos->getNodo(ind_puntos[1])->getPunto();
    Punto *p2 = nodos->getNodo(ind_puntos[2])->getPunto();
    Vect vp(p->getX(),p->getY(),p->getZ());
    Vect vp0(*p0);
    Vect vp1(*p1);
    Vect vp2(*p2);
    Vect v_p0_p = vp - vp0;

    double prod = normal_cara.prodPunto(v_p0_p);

    // verificamos que el punto este en el plano
    //(prod == 0); --> seria la condicion con aritmetica exacta.
    if(prod >= 0.0000000000001 || prod <= -0.0000000000001) {
        return NO_TIP_YET;
    }

    Vect v_p0_p1 = vp1 - vp0;
    Vect v_p1_p2 = vp2 - vp1;
    Vect v_p2_p0 = vp0 - vp2;

    Vect v_p1_p = vp - vp1;
    Vect v_p2_p = vp - vp2;

    if(v_p0_p.largo() == 0 || v_p1_p.largo() == 0 || v_p2_p.largo() == 0) {
        return TIP_ON_VERTEX;
    }

    Vect v0 = v_p0_p1.prodCruz(v_p0_p);
    Vect v1 = v_p1_p2.prodCruz(v_p1_p);
    Vect v2 = v_p2_p0.prodCruz(v_p2_p);

    if(v0.largo() == 0 && v_p1_p.largo() < v_p0_p1.largo() && v_p0_p.largo() < v_p0_p1.largo()) {
        return TIP_ON_EDGE;
    }
    if(v1.largo() == 0 && v_p2_p.largo() < v_p1_p2.largo() && v_p1_p.largo() < v_p1_p2.largo()) {
        return TIP_ON_EDGE;
    }
    if(v2.largo() == 0 && v_p0_p.largo() < v_p2_p0.largo() && v_p2_p.largo() < v_p2_p0.largo()) {
        return TIP_ON_EDGE;
    }

    if(normal_cara.largo() == 0) {
        return TIP_OUTSIDE;
    }

    double prod_punto1 = normal_cara.prodPunto(v0);
    double prod_punto2 = normal_cara.prodPunto(v1);
    double prod_punto3 = normal_cara.prodPunto(v2);

    if(prod_punto1 < 0 || prod_punto2 < 0 || prod_punto3 < 0) {
        return TIP_OUTSIDE; // esta fuera de la cara
    }
    else {
        return TIP_INSIDE; // esta dentro de la cara
    }
}

int Malla::seCruzan(Punto *p1_arco1, Punto *p2_arco1, Punto *p1_arco2, Punto *p2_arco2) {

    Vect vp1_arco1(*p1_arco1);
    Vect vp2_arco1(*p2_arco1);
    Vect vp1_arco2(*p1_arco2);
    Vect vp2_arco2(*p2_arco2);

    Vect v_arco1 = vp2_arco1 - vp1_arco1;
    Vect v_arco2 = vp2_arco2 - vp1_arco2;

    Vect v11 = v_arco1.prodCruz(vp1_arco2-vp1_arco1);
    Vect v12 = v_arco1.prodCruz(vp2_arco2-vp1_arco1);

    Vect v21 = v_arco2.prodCruz(vp1_arco1-vp1_arco2);
    Vect v22 = v_arco2.prodCruz(vp2_arco1-vp1_arco2);

    double prod1 = v11.prodPunto(v12);
    double prod2 = v21.prodPunto(v22);

    if(prod1 < 0 && prod2 < 0) {
        return 1; // si se cruzan
    }
    else {
        return 0; // no se cruzan
    }
}

void Malla::manejaInconsitenciaArco(int ind_arco) {
    assert((ind_arco < arcos->getNumArcos()) && (ind_arco >= 0));

    int ind_c1 = arcos->getArco(ind_arco)->getCara1();
    int ind_c2 = arcos->getArco(ind_arco)->getCara2();

    cout << "ind_c1 = " << ind_c1 << endl;
    cout << "ind_c2 = " << ind_c2 << endl;

    if(ind_c1 < 0 || ind_c2 < 0) {
        return;
    }

    //obtenemos los indices de los 4 puntos
    int ind_p1 = arcos->getArco(ind_arco)->getNodo1();
    int ind_p2 = arcos->getArco(ind_arco)->getNodo2();
    int ind_p_c1 = this->getNodoOpuestoArco(ind_c1,ind_arco);
    int ind_p_c2 = this->getNodoOpuestoArco(ind_c2,ind_arco);

    //obtenemos los 4 puntos
    Punto *p_c1 = nodos->getNodo(ind_p_c1)->getPunto();
    Punto *p_c2 = nodos->getNodo(ind_p_c2)->getPunto();
    Punto *p1 = nodos->getNodo(ind_p1)->getPunto();
    Punto *p2 = nodos->getNodo(ind_p2)->getPunto();

    //obtenemos los indices de los arcos
    int ind_a1_c1 = this->getArcoOpuestoNodo(ind_c1,ind_p1);
    int ind_a2_c1 = this->getArcoOpuestoNodo(ind_c1,ind_p2);
    int ind_a1_c2 = this->getArcoOpuestoNodo(ind_c2,ind_p1);
    int ind_a2_c2 = this->getArcoOpuestoNodo(ind_c2,ind_p2);

    cout << "ind_a1_c1 = " << ind_a1_c1 << endl;
    cout << "ind_a2_c1 = " << ind_a2_c1 << endl;
    cout << "ind_a1_c2 = " << ind_a1_c2 << endl;
    cout << "ind_a2_c2 = " << ind_a2_c2 << endl;

    int tip_arco = this->tipArco(ind_arco);
    cout << "tip_arco = " << tip_arco << endl;

    if(tip_arco == TIP_INSIDE) {
        cout << "TIP_INSIDE en arco(" << ind_arco << ")" << endl;
        cout << "Realizado flip en arco(" << ind_arco << ")" << endl;
        edgeFlip(ind_arco);
    }
    else if(tip_arco == TIP_ON_EDGE) {
        cout << "TIP_ON_EDGE en arco(" << ind_arco << ")" << endl;
    }
    else if(tip_arco == TIP_OUTSIDE_B) {
        //no hacemos nada porque no se producen inconsistencias.
        cout << "TIP_OUTSIDE_B en arco(" << ind_arco << ")" << endl;
    }
    else if(tip_arco == TIP_OUTSIDE_A) {
        cout << "TIP_OUTSIDE_A en arco(" << ind_arco << ")" << endl;
        //tengo que ver que arcos se cruzan y en que punto
        if(seCruzan(p1,p_c2,p2,p_c1) == 1) {
            cout << "Se cruzan en: p1,p_c2,p2,p_c1" << endl;
            double alfa = valorInterseccion(p1,p_c2,p2,p_c1);
            double beta = valorInterseccion(p2,p_c1,p1,p_c2);
            cout << "alfa = " << alfa << endl;
            cout << "beta = " << beta << endl;

            if(arcos->getArco(ind_a1_c1) == 0) {
                cout << "ind_a1_c1 = " << ind_a1_c1 << " es nulo"<< endl;
            }
            if(arcos->getArco(ind_a2_c2) == 0) {
                cout << "ind_a2_c2 = " << ind_a2_c2 << " es nulo"<< endl;
            }

            //dividimos los arcos en su punto de intersecioon
            if(arcos->getArco(ind_a2_c2)->getNodo1() == ind_p1) {
                cout << "refinando en alfa" << endl;
                edgeSplit(ind_a2_c2,alfa);
            }
            else {
                edgeSplit(ind_a2_c2,1-alfa);
                cout << "refinando en 1-alfa" << endl;
            }
            if(arcos->getArco(ind_a1_c1)->getNodo1() == ind_p2) {
                cout << "refinando en beta" << endl;
                edgeSplit(ind_a1_c1,beta);
            }
            else {
                cout << "refinando en 1-beta" << endl;
                edgeSplit(ind_a1_c1,1-beta);
            }
            //hacemos un flip en el arco
            cout << "Flip ind_arco = " << ind_arco << endl;
            int nuevo_arco = edgeFlip(ind_arco);
            cout << "Nuevo nuevo_arco = " << nuevo_arco << endl;
            cout << "Largo nuevo_arco = " << getLargoArco(nuevo_arco) << endl;
            //ahora hacemos un reduce arco
            edgeCollapse(nuevo_arco,0);

        }
        else if(seCruzan(p1,p_c1,p2,p_c2) == 1) {
            cout << "Se cruzan en: p1,p_c1,p2,p_c2" << endl;
            double alfa = valorInterseccion(p1,p_c1,p2,p_c2);
            double beta = valorInterseccion(p2,p_c2,p1,p_c1);
            cout << "alfa = " << alfa << endl;
            cout << "beta = " << beta << endl;

            if(arcos->getArco(ind_a2_c1) == 0) {
                cout << "ind_a2_c1 = " << ind_a2_c1 << " es nulo"<< endl;
            }
            if(arcos->getArco(ind_a1_c2) == 0) {
                cout << "ind_a1_c2 = " << ind_a1_c2 << " es nulo"<< endl;
            }

            //dividimos los arcos en su punto de intersecioon
            if(arcos->getArco(ind_a2_c1)->getNodo1() == ind_p1) {
                cout << "refinando en alfa" << endl;
                edgeSplit(ind_a2_c1,alfa);
            }
            else {
                cout << "refinando en 1-alfa" << endl;
//                 cout << "Largo = " << this->getLargoArco(ind_a2_c1) << endl;
                edgeSplit(ind_a2_c1,1-alfa);
            }
            if(arcos->getArco(ind_a1_c2)->getNodo1() == ind_p2) {
                cout << "refinando en beta" << endl;
                edgeSplit(ind_a1_c2,beta);
            }
            else {
                cout << "refinando en 1-beta" << endl;
                edgeSplit(ind_a1_c2,1-beta);
            }
            //hacemos un flip en el arco
            int nuevo_arco = edgeFlip(ind_arco);
            //ahora hacemos un reduce arco
            edgeCollapse(nuevo_arco,0);
        }
        else {

        }
    }
    cout << "retornamos de manejaInconsitenciaArco" << endl;
    return;

}

void Malla::manejaInconsistenciaArcoAntes(int ind_arco, double val) {
    assert((ind_arco < arcos->getNumArcos()) && (ind_arco >= 0));

    int ind_c1 = arcos->getArco(ind_arco)->getCara1();
    int ind_c2 = arcos->getArco(ind_arco)->getCara2();

    if(ind_c1 < 0 || ind_c2 < 0) {
        return; // region borde
    }

    //obtenemos los indices de los 4 puntos
    int ind_p1 = arcos->getArco(ind_arco)->getNodo1();
    int ind_p2 = arcos->getArco(ind_arco)->getNodo2();
    int ind_p_c1 = this->getNodoOpuestoArco(ind_c1,ind_arco);
    int ind_p_c2 = this->getNodoOpuestoArco(ind_c2,ind_arco);

    //movemos los 4 nodos.
    nodos->moverNodoSegunConcentracion(ind_p1,val);
    nodos->moverNodoSegunConcentracion(ind_p2,val);
    nodos->moverNodoSegunConcentracion(ind_p_c1,val);
    nodos->moverNodoSegunConcentracion(ind_p_c2,val);

    this->manejaInconsitenciaArco(ind_arco);

    //regresamos los 4 nodos.
    nodos->regresarNodoSegunConcentracion(ind_p1,val);
    nodos->regresarNodoSegunConcentracion(ind_p2,val);
    nodos->regresarNodoSegunConcentracion(ind_p_c1,val);
    nodos->regresarNodoSegunConcentracion(ind_p_c2,val);
}

double Malla::valorInterseccion(Punto *p1_arco1, Punto *p2_arco1, Punto *p1_arco2, Punto *p2_arco2) {
    Vect vp1_arco1(*p1_arco1);
    Vect vp2_arco1(*p2_arco1);
    Vect vp1_arco2(*p1_arco2);
    Vect vp2_arco2(*p2_arco2);

    Vect v_arco1 = vp2_arco1 - vp1_arco1;
    Vect v_arco2 = vp2_arco2 - vp1_arco2;

    Vect v_p1_arco12 = vp1_arco2-vp1_arco1;
//     Vect *v_p2_arco12 = (*p2_arco2)-p1_arco1;

    Vect normal_a1_a2 = v_arco1.prodCruz(v_arco2);

    double num = v_p1_arco12.prodPunto(v_arco2.prodCruz(normal_a1_a2));
    double den = normal_a1_a2.largo()*normal_a1_a2.largo();

    if(den == 0) {
        //los segmento son paralelos
        return -1;
    }
    else {
        return num/den;
    }
}

int Malla::isDelaunay(int ind_arco){
	assert(ind_arco >= 0 && ind_arco < getArcos()->getNumArcos());
	assert(getArcos()->getArco(ind_arco) != NULL);

	Malla* malla=this;

   // if(malla->esArcoBorde(ind_arco) || malla->esArcoConcavo(ind_arco))
   if (malla->esArcoFijo(ind_arco))
        return -1;	//no se puede hacer el flip

    // Obtenemos los indices que necesitamos.
    // Indices de las caras
    int ind_c1 = malla->getArcos()->getArco(ind_arco)->getCara1();
    int ind_c2 = malla->getArcos()->getArco(ind_arco)->getCara2();

    //Indices de los nodos
    int ind_p1 = malla->getArcos()->getArco(ind_arco)->getNodo1();
    int ind_p2 = malla->getArcos()->getArco(ind_arco)->getNodo2();
    int ind_p_c1 = malla->getNodoOpuestoArco(ind_c1,ind_arco);
    int ind_p_c2 = malla->getNodoOpuestoArco(ind_c2,ind_arco);

   	if (ind_p_c1 == ind_p_c2){
	   	cerr << "No se puede chequar Delaunay en arco " << ind_arco << " ya que sus caras vecinas estan superpuestas" << endl;
    	return -1;
   		}

    //Obtenemos el angulo minimo de cada cara que separa el arco, y el minimo entre ellos.
    double angulo_min_c1 = malla->getAnguloMin(ind_c1);
    double angulo_min_c2 = malla->getAnguloMin(ind_c2);
    double angulo_min = angulo_min_c1;
    if(angulo_min_c2 < angulo_min) {
        angulo_min = angulo_min_c2;
    }
    //cout << "angulo_min = " << angulo_min << endl;

    //Malla *m1 = new Malla(malla->getNodos()->getNodo(ind_p1)->getPunto(),malla->getNodos()->getNodo(ind_p_c2)->getPunto(),malla->getNodos()->getNodo(ind_p_c1)->getPunto());
    //Malla *m2 = new Malla(malla->getNodos()->getNodo(ind_p2)->getPunto(),malla->getNodos()->getNodo(ind_p_c1)->getPunto(),malla->getNodos()->getNodo(ind_p_c2)->getPunto());

	double puntox1,puntoy1,puntoz1,puntox2,puntoy2,puntoz2,puntox3,puntoy3,puntoz3;

	puntox1=malla->getNodos()->getNodo(ind_p1)->getPunto()->getX();
	puntoy1=malla->getNodos()->getNodo(ind_p1)->getPunto()->getY();
	puntoz1=malla->getNodos()->getNodo(ind_p1)->getPunto()->getZ();
	puntox2=malla->getNodos()->getNodo(ind_p_c2)->getPunto()->getX();
	puntoy2=malla->getNodos()->getNodo(ind_p_c2)->getPunto()->getY();
	puntoz2=malla->getNodos()->getNodo(ind_p_c2)->getPunto()->getZ();
	puntox3=malla->getNodos()->getNodo(ind_p_c1)->getPunto()->getX();
	puntoy3=malla->getNodos()->getNodo(ind_p_c1)->getPunto()->getY();
	puntoz3=malla->getNodos()->getNodo(ind_p_c1)->getPunto()->getZ();

	Malla *m1= new Malla(new Punto(puntox1,puntoy1,puntoz1), new Punto(puntox2,puntoy2,puntoz2),new Punto(puntox3,puntoy3,puntoz3));

	puntox1=malla->getNodos()->getNodo(ind_p2)->getPunto()->getX();
	puntoy1=malla->getNodos()->getNodo(ind_p2)->getPunto()->getY();
	puntoz1=malla->getNodos()->getNodo(ind_p2)->getPunto()->getZ();
	puntox2=malla->getNodos()->getNodo(ind_p_c1)->getPunto()->getX();
	puntoy2=malla->getNodos()->getNodo(ind_p_c1)->getPunto()->getY();
	puntoz2=malla->getNodos()->getNodo(ind_p_c1)->getPunto()->getZ();
	puntox3=malla->getNodos()->getNodo(ind_p_c2)->getPunto()->getX();
	puntoy3=malla->getNodos()->getNodo(ind_p_c2)->getPunto()->getY();
	puntoz3=malla->getNodos()->getNodo(ind_p_c2)->getPunto()->getZ();

	Malla *m2= new Malla(new Punto(puntox1,puntoy1,puntoz1), new Punto(puntox2,puntoy2,puntoz2),new Punto(puntox3,puntoy3,puntoz3));

    double nuevo_angulo_min_c1 = m1->getAnguloMin(0);
    double nuevo_angulo_min_c2 = m2->getAnguloMin(0);

	delete m1;
	delete m2;

    double nuevo_angulo_min = nuevo_angulo_min_c1;
    if(nuevo_angulo_min_c2 < nuevo_angulo_min) {
        nuevo_angulo_min = nuevo_angulo_min_c2;
    }
    //cout << "nuevo_angulo_min = " << nuevo_angulo_min << endl;
	//si mejoramos el angulo minimo hacemos el flip ya que no es delaunay.
    if(nuevo_angulo_min > angulo_min)
		return 0;	//No cumple Delaunay
	else
		return 1;	//Si cumple Delaunay
	}


void Malla::makeDelaunay(int ind_arco){
	assert(ind_arco >= 0 && ind_arco < getArcos()->getNumArcos());

	if (isDelaunay(ind_arco)!=0) //Si es que ya es Delaunay o si es que no se puede determinar.
		return;

	Malla *malla=this;

	int nuevo_arco = malla->edgeFlip(ind_arco);
    if (nuevo_arco==-1) return;

    int nueva_c1 = malla->getArcos()->getArco(nuevo_arco)->getCara1();
    int nueva_c2 = malla->getArcos()->getArco(nuevo_arco)->getCara2();

    //revisamos los arcos vecinos, por si ahora se puede realizar el flip.
    vector<int> arcos_nueva_c1 = malla->getCaras()->getCara(nueva_c1)->getArcos();
    for(int i=0; i<(int)arcos_nueva_c1.size(); i++) {
    	if(arcos_nueva_c1[i] != nuevo_arco)
        	makeDelaunay(arcos_nueva_c1[i]);
        }
    vector<int> arcos_nueva_c2 = malla->getCaras()->getCara(nueva_c2)->getArcos();
    for(int i=0; i<(int)arcos_nueva_c2.size(); i++) {
    	if(arcos_nueva_c2[i] != nuevo_arco)
        	makeDelaunay(arcos_nueva_c2[i]);
        }
	}




Malla::~Malla(){
	delete nodos;
	delete arcos;
	delete caras;
	}
