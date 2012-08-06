#include "vect.h"

Vect::Vect() {
    p = Punto(0,0,0);
}

Vect::Vect(Punto p) {
    this->p = p;
}

Vect::Vect(double x, double y, double z) {
    this->p = Punto(x,y,z);
}

void Vect::setPunto(Punto p) {
    this->p = p;
}

Punto Vect::getPunto() {
    assert(this != 0);
    return this->p;
}

bool Vect::inOrigen() {
    assert(this != 0);
    if(p.getX() == 0 && p.getY() == 0 && p.getZ() == 0) {
        return true;
    }
    return false;
}

double Vect::largo() {
    return sqrt(p.getX()*p.getX()+p.getY()*p.getY()+p.getZ()*p.getZ());
}

double Vect::getAngulo(Vect v) {
    assert(!this->inOrigen() && !v.inOrigen());
	double cos_angulo = (this->prodPunto(v)) / (this->largo() * v.largo());
    if(cos_angulo > 1 && cos_angulo < 1.000001) {
        return 0;
    }
    return acos(cos_angulo);
}

double Vect::prodPunto(Vect v) {
    return p.getX()*v.getPunto().getX()+p.getY()*v.getPunto().getY()+p.getZ()*v.getPunto().getZ();
    }

Vect Vect::prodCruz(Vect v) {
    return Vect(p.getY()*v.getPunto().getZ()-p.getZ()*v.getPunto().getY(),p.getZ()*v.getPunto().getX()-p.getX()*v.getPunto().getZ(),p.getX()*v.getPunto().getY()-p.getY()*v.getPunto().getX());
}

Vect Vect::operator*(double x) {
    assert(this != 0);
    Vect vct = Vect(p.getX()*x,p.getY()*x,p.getZ()*x);
    return vct;
}

Vect Vect::operator+(Vect v) {
    return Vect(p.getX()+v.getPunto().getX(),p.getY()+v.getPunto().getY(),p.getZ()+v.getPunto().getZ());
    }

Vect Vect::operator-(Vect v) {
    return Vect(p.getX()-v.getPunto().getX(),p.getY()-v.getPunto().getY(),p.getZ()-v.getPunto().getZ());
    }

void  Vect::normalizar(){
    double multiplicador=1/this->largo();
    p.setX(multiplicador*p.getX());
    p.setY(multiplicador*p.getY());
    p.setZ(multiplicador*p.getZ());
    }

ostream& operator<<(ostream &os, Vect v){
    os << "Vect(" << v.p.getX() << "," << v.p.getY() << "," << v.p.getZ() << ")" << endl;
    return os;
    }

Vect::~Vect(){

	}
