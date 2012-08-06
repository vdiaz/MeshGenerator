#include "informacionmalla.h"

InformacionMalla::InformacionMalla(){
	h = gsl_histogram_alloc (10);
	info=new double[20];
	}

void InformacionMalla::aplicar(Malla *malla){
	assert(malla!=NULL);
	
	info[0]=malla->getCaras()->getNumCarasValidas();
	info[1]=malla->getArcos()->getNumArcosValidos();
	info[2]=malla->getNodos()->getNumNodosValidos();
	
	//Calculamos las areas y angulos de las caras.
	double areaMinima=numeric_limits<double>::max();
	double areaMaxima=0;
	double areaPromedio=0;
	double anguloMinimo=numeric_limits<double>::max();
	double anguloMaximo=0;
	Caras* caras=malla->getCaras();
	for(int i=0; i<caras->getNumCaras(); i++){
		if(caras->getCara(i)!=NULL){
			double area=malla->getArea(i);
			if(area<areaMinima)
				areaMinima=area;
			if (area>areaMaxima)
				areaMaxima=area;
			areaPromedio=areaPromedio+area;
			
			double angulo=malla->getAnguloMin(i);
			if (angulo<anguloMinimo)
				anguloMinimo=angulo;
			angulo=malla->getAnguloMax(i);
			if (angulo>anguloMaximo)
				anguloMaximo=angulo;
			}
		}
	areaPromedio=areaPromedio/caras->getNumCarasValidas();
	info[3]=areaMinima;
	info[4]=areaMaxima;
	info[5]=areaPromedio;
	info[6]=anguloMinimo*180/PI;
	info[7]=anguloMaximo*180/PI;
		
	//Calculamos el histograma de las areas.
	gsl_histogram_set_ranges_uniform (h, areaMinima, areaMaxima);
	for(int i=0; i<caras->getNumCaras(); i++){
		if(caras->getCara(i)!=NULL)
			gsl_histogram_increment (h, malla->getArea(i));
		}
	
	//Calculamos los largos de los arcos.
	double largoMinimo=numeric_limits<double>::max();
	double largoMaximo=0;
	double largoPromedio=0;
	Arcos* arcos=malla->getArcos();
	for(int i=0; i<arcos->getNumArcos(); i++){
		if(arcos->getArco(i)!=NULL){
			double largo=malla->getLargoArco(i);
			if(largo<largoMinimo)
				largoMinimo=largo;
			if (largo>largoMaximo)
				largoMaximo=largo;
			largoPromedio=largoPromedio+largo;
			}
		}
	largoPromedio=largoPromedio/arcos->getNumArcosValidos();
	info[8]=largoMinimo;
	info[9]=largoMaximo;
	info[10]=largoPromedio;
	
	//gsl_histogram_fprintf (stdout, h, "%g", "%g");
	}

double * InformacionMalla::getInfo(){
	return info;
	}

double InformacionMalla::getLimiteMenorHistograma(int bin){
	double resultado;
	double aux;
	gsl_histogram_get_range(h,bin,&resultado,&aux);
	return resultado;
	}

double InformacionMalla::getLimiteMayorHistograma(int bin){
	double resultado;
	double aux;
	gsl_histogram_get_range(h,bin,&aux,&resultado);
	return resultado;
	}

double InformacionMalla::getFrecuenciaHistograma(int bin){
	return gsl_histogram_get(h,bin);
	}
	
InformacionMalla::~InformacionMalla(){
	delete info;
	gsl_histogram_free (h);
	}
