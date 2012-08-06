#include "generafromarchivosxyzu.h"

GeneraFromArchivosXYZU::GeneraFromArchivosXYZU(string arch_x, string arch_y, string arch_z, string arch_u):AlgGeneracion() {
    archivo_x = arch_x;
    archivo_y = arch_y;
    archivo_z = arch_z;
    archivo_u = arch_u;
}

Malla* GeneraFromArchivosXYZU::aplicar() {
	//Lineas necesarias para que scanf lea archivo en computadores seteados en otro lenguaje.
	setlocale(LC_NUMERIC, "POSIX");

    FILE *arch_x = fopen(archivo_x.c_str(),"r");
    FILE *arch_y = fopen(archivo_y.c_str(),"r");
    FILE *arch_z = fopen(archivo_z.c_str(),"r");
    FILE *arch_u = fopen(archivo_u.c_str(),"r");

    char line[32];
    char cx[16];
    char cy[16];
    char cz[16];
    int num_puntos, num_caras;
    float x,y,z,nx,ny,nz,u;
    fscanf(arch_x,"%s %s\n",line,line);
    fscanf(arch_y,"%s %s\n",line,line);
    fscanf(arch_z,"%s %s\n",line,line);
    fscanf(arch_u,"%s %s\n",line,line);

    num_puntos=0;
    Nodos *nodos = new Nodos();
    Nodo *nodo;
    while(true) {
        fscanf(arch_x,"%s %s %s\n",cx,cy,cz);
        fscanf(arch_y,"%s %s %s\n",cx,cy,cz);
        fscanf(arch_z,"%s %s %s\n",cx,cy,cz);
        fscanf(arch_u,"%s %s %s\n",cx,cy,cz);
        if(strcmp(cx,"%") == 0) {
            break;
        }
        sscanf(cx,"%f",&x);
        sscanf(cy,"%f",&y);
        sscanf(cz,"%f",&z);
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
        fscanf(arch_x,"%s %s %s\n",cx,cy,cz);
        fscanf(arch_y,"%s %s %s\n",cx,cy,cz);
        fscanf(arch_z,"%s %s %s\n",cx,cy,cz);
        fscanf(arch_u,"%s %s %s\n",cx,cy,cz);
        if(strcmp(cx,"%") == 0) {
            break;
        }
        sscanf(cx,"%d",&i1);
        sscanf(cy,"%d",&i2);
        sscanf(cz,"%d",&i3);

        indice_puntos.push_back(i1-1);
        indice_puntos.push_back(i2-1);
        indice_puntos.push_back(i3-1);
//         cout << "i1=" << indice_puntos[0] << " i2=" << indice_puntos[1] << " i3=" << indice_puntos[2] << endl;

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
//     cout << "num_caras = " << num_caras << endl;
    //cout << "num_caras = " << caras->getNumCaras() << endl;

    float max_concentracion = 0;
    float min_concentracion = 999999999;
    for(int i=0; i<num_puntos; i++) {
        fscanf(arch_x,"%f\n",&nx);
        fscanf(arch_y,"%f\n",&ny);
        fscanf(arch_z,"%f\n",&nz);
        fscanf(arch_u,"%f\n",&u);

        if(u < min_concentracion) {
            min_concentracion = u;
        }
        if(u > max_concentracion) {
            max_concentracion = u;
        }

        Vect normal = Vect(nx,ny,nz);
        nodos->getNodo(i)->setNormal(normal);
        nodos->getNodo(i)->setConcentracion(u);
    }

    cout << "max_concentracion = " << max_concentracion << endl;
    cout << "min_concentracion = " << min_concentracion << endl;

    Malla *malla = new Malla(nodos,arcos,caras);
    malla->setConcentracionMax(max_concentracion);
    malla->setConcentracionMin(min_concentracion);

	fclose(arch_x);
	fclose(arch_y);
	fclose(arch_z);
	fclose(arch_u);
	setlocale(LC_NUMERIC, "");

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
