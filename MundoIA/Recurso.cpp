#include "pch.h"
#include "Recurso.h"


Recurso::Recurso() : x(0), y(0), ancho(1), alto(1), estado_activo(true) {}
Recurso::Recurso(int px, int py, int w, int h) : x(px), y(py), ancho(w), alto(h), estado_activo(true) {}
Recurso::~Recurso() {}

int  Recurso::getX() { return x; }
int  Recurso::getY() { return y; }
int  Recurso::getAncho() { return ancho; }
int  Recurso::getAlto() { return alto; }
void Recurso::setX(int nx) { x = nx; }
void Recurso::setY(int ny) { y = ny; }
void Recurso::setTamaño(int w, int h) { ancho = w; alto = h; }
bool Recurso::activo() { return estado_activo; }
void Recurso::setEstado(bool nuevoEstado) { estado_activo = nuevoEstado; }


void Recurso::animar() {
    borrar();
    if (!activo()) return;
    mover();
    if (!activo()) return;  
    dibujar();
}

Rectangle Recurso::obtenerRectangulo() {
	return Rectangle(x, y, ancho, alto);
}

bool Recurso::intersecta(Rectangle& r) {
	return obtenerRectangulo().IntersectsWith(r);
}