#include "punto.h"

Punto::Punto() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Punto::Punto(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Punto::setX(double x) {
    this->x = x;
}

void Punto::setY(double y) {
    this->y = y;
}

void Punto::setZ(double z) {
    this->z = z;
}

double Punto::getX() {
    assert(this != 0);
    return x;
}

double Punto::getY() {
    assert(this != 0);
    return y;
}

double Punto::getZ() {
    assert(this != 0);
    return z;
}

double Punto::operator[](int indice) {
    assert(this != 0);
    assert(indice == 0 || indice == 1 || indice == 2);
    if(indice == 0) {
        return x;
    }
    else if(indice == 1) {
        return y;
    }
    else if(indice == 2) {
        return z;
    }
    else {
        return 0;
    }
}


void Punto::imprimir() {
    assert(this != 0);
    cout << "Punto(" << x << "," << y << "," << z << ")" << endl;
}
