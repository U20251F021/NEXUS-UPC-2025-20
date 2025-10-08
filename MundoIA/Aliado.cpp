#include "pch.h"
#include "Aliado.h"
#include <iostream>
using namespace std;

Aliado::Aliado() : x(0), y(0), ancho(1), alto(1), estado_activo(true) {}
Aliado::Aliado(int px, int py, int w, int h) : x(px), y(py), ancho(w), alto(h), estado_activo(true) {}
Aliado::~Aliado() {}


int  Aliado::getX() { return x; }
int  Aliado::getY() { return y; }
int  Aliado::getAncho() { return ancho; }
int  Aliado::getAlto() { return alto; }
void Aliado::setX(int nx) { x = nx; }
void Aliado::setY(int ny) { y = ny; }
void Aliado::setTamaño(int w, int h) { ancho = w; alto = h; }
bool Aliado::activo() const { return estado_activo; }




// Colisiones
Rectangle Aliado::obtenerRectangulo()  {
    return Rectangle(x, y, ancho, alto);
}

bool Aliado::intersecta(Rectangle& r)  {
    return obtenerRectangulo().IntersectsWith(r);
}
