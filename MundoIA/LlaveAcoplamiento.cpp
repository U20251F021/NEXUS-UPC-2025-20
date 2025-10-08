
#include "pch.h"
#include "LlaveAcoplamiento.h"
#include <iostream>
#include <cstdlib>
using namespace std;

const int LL_ANCHO = 7;
const int LL_ALTO = 3;

LlaveAcoplamiento::LlaveAcoplamiento()
    : Recurso(0, 0, LL_ANCHO, LL_ALTO) {
    contador = 0;
    dy = 1;
    pasoFrames = 2;
}

LlaveAcoplamiento::LlaveAcoplamiento(int px, int py)
    : Recurso(px, py, LL_ANCHO, LL_ALTO) {
    contador = 0;
    dy = 1;
    pasoFrames = 2;
}

void LlaveAcoplamiento::dibujar() {
    Herramienta h; h.asignarcolor(10);

    h.ubicar(x, y); cout << "  __   ";
    h.ubicar(x, y + 1); cout << " |]  ";
    h.ubicar(x, y + 2); cout << " |     ";
}

void LlaveAcoplamiento::borrar() {
    Herramienta h;
    h.ubicar(x, y); cout << "       ";
    h.ubicar(x, y + 1); cout << "       ";
    h.ubicar(x, y + 2); cout << "       ";
}

void LlaveAcoplamiento::mover() {

}


void LlaveAcoplamiento::generarPosAleatoria() {


    setX(1 + rand() % (180 - 1 + 1));
    setY(21);
}

void LlaveAcoplamiento::aplicarEfectoAlJugador(Jugador& jugador) {

    jugador.setTieneLlave(true);

    int actual = jugador.getCantidadLlaves();
    jugador.setCantidadLlaves(actual + 1);


    estado_activo = false;
    borrar();

    Herramienta h; h.asignarcolor(10);
    h.dialogo(70, 130, 35, 39, string("Llave de Acoplamiento obtenida"), 15);

}