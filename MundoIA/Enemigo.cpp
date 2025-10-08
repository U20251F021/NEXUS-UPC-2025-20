#include "pch.h"
#include "Enemigo.h"
#include "Jugador.h"

using namespace std;

Enemigo::Enemigo() : x(0), y(0), ancho(1), alto(1), estado_activo(true) {}

Enemigo::Enemigo(int px, int py, int w, int h)
    : x(px), y(py), ancho(w), alto(h), estado_activo(true) {
}

Enemigo::~Enemigo() {}

int Enemigo::getX() { return x; }
int Enemigo::getY() { return y; }
int Enemigo::getAncho() { return ancho; }
int Enemigo::getAlto() { return alto; }

void Enemigo::setX(int nx) { x = nx; }
void Enemigo::setY(int ny) { y = ny; }
void Enemigo::setTamaño(int w, int h) { ancho = w; alto = h; }

bool Enemigo::activo()  { return estado_activo; }


void Enemigo::animar(Jugador& jugador) {
    borrar();
    if (!activo()) return;
    mover(jugador);
    if (!activo()) return;  
    dibujar();
}

Rectangle Enemigo::obtenerRectangulo()  {
    return Rectangle(x, y, ancho, alto);
}

bool Enemigo::intersecta(Rectangle& r)  {
    return obtenerRectangulo().IntersectsWith(r);
}