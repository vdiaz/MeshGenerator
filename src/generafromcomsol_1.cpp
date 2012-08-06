#include "generafromcomsol_1.h"

#include <fstream>
#include <sstream>
#include <map>

#define MAXLINE	256


GeneraFromComsol_1::GeneraFromComsol_1(string arch_x):AlgGeneracion() {
    archivo = arch_x;
}

Malla* GeneraFromComsol_1::aplicar() {
	ifstream in(archivo.c_str());
	char line[MAXLINE];
	in.getline(line,MAXLINE);

    string cx,cy,cz;
	float x,y,z;

    int num_puntos, num_caras;

    num_puntos=0;
    Nodos *nodos = new Nodos();
    Nodo *nodo;

    while(true) {
        in.getline(line,MAXLINE);
		stringstream streamin(line);
		if (line[0]=='%')
			break;

		streamin >> x;
		streamin >> y;
		streamin >> z;

        nodo = new Nodo(new Punto(x,y,z));
        nodos->addNodo(nodo);
        num_puntos++;
    }

    //cout << "num_puntos = " << nodos->getNumNodos() << endl;


    map<pair<int,int>,int> ind_arcos;
    map<pair<int,int>,int>::iterator iter1;
	map<pair<int,int>,int>::iterator iter2;
    vector<int> indice_puntos;
    vector<int> indice_arcos;
    Arcos *arcos = new Arcos();
    Caras *caras = new Caras();
    Cara *c;
    int indice;

    int i1, i2, i3;
    num_caras=0;
    while(true) {
		in.getline(line,MAXLINE);
		if (in.fail() || line[0]=='%')
			break;
		stringstream streamin(line);
		streamin >> i1;
		streamin >> i2;
		streamin >> i3;

		//Nota: Se invierte el orden de insercion de los puntos, para que las normales queden seteadas correctamente.
		//      ya que en el archivo cms_1 los nodos estan al reves, dejando las normales hacia adentro.
        indice_puntos.push_back(i3-1);
        indice_puntos.push_back(i2-1);
        indice_puntos.push_back(i1-1);
		///////////////////////////////////////

        for(int j=0; j<3; j++) {
            int ind1 = indice_puntos[j];
            int ind2 = indice_puntos[int(fmod(j+1,3))];
            pair<int,int> pr1(ind1,ind2);
			pair<int,int> pr2(ind2,ind1);
            iter1 = ind_arcos.find(pr1);
			iter2 = ind_arcos.find(pr2);
            if(iter1 != ind_arcos.end())
                    indice_arcos.push_back(iter1->second);
            else if(iter2 != ind_arcos.end())
                    indice_arcos.push_back(iter2->second);
            else {
                indice = arcos->addArco(new Arco(ind1,ind2));
                indice_arcos.push_back(indice);
                ind_arcos.insert(make_pair(pr1,indice));
                nodos->addArcoNodo(ind1,indice);
                nodos->addArcoNodo(ind2,indice);
            }
        }
        c = new Cara(indice_puntos,indice_arcos);
        int ind_cara = caras->addCara(c);
        num_caras++;
        for(int j=0; j<3; j++) {
            arcos->setCaraArco(indice_arcos[j],ind_cara);
            nodos->addCaraNodo(indice_puntos[j],ind_cara);
        }
        indice_puntos.clear();
        indice_arcos.clear();
    }

    //cout << "num_caras = " << caras->getNumCaras() << endl;

	Malla *malla = new Malla(nodos,arcos,caras);
    malla->setConcentracionTodos(1.0);
    malla->setConcentracionMax(1.0);
    malla->setConcentracionMin(0.0);
    malla->setNormales();

	in.close();

	//Chequeamos consistencia topologica.
	int V=malla->getNodos()->getNumNodosValidos();
	int E=malla->getArcos()->getNumArcosValidos();
	int F=malla->getCaras()->getNumCarasValidas();
	cout << "Numero de nodos=" << V << endl;
	cout << "Numero de arcos=" << E << endl;
	cout << "Numero de caras=" << F << endl;
	if (V-E+F==2 || V-E+F==0)
		cout << "La malla es consistente. Cumple la formula de Euler: V-E+F=2" << endl;
	else
		cout << "Atencion, la malla no es consistente. No cumple la formula de Euler: V-E+F=" << V-E+F << " y deberia ser V-E+F=2" << endl;

    return malla;
}
