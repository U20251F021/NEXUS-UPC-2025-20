
#include "pch.h"
#include "EscudoPlasma.h"
#include <iostream>
#include <cstdlib>
using namespace std;


const int ES_ANCHO = 7;
const int ES_ALTO = 3;



EscudoPlasma::EscudoPlasma()
    : Recurso(0, 0, ES_ANCHO, ES_ALTO) {
    contador = 0;
    dy = 1;
    pasoFrames = 3;

}

EscudoPlasma::EscudoPlasma(int px, int py)
    : Recurso(px, py, ES_ANCHO, ES_ALTO) {
    contador = 0;
    dy = 1;
    pasoFrames = 3;
}

void EscudoPlasma::dibujar() {
    Herramienta h; h.asignarcolor(14);

    h.ubicar(x, y); cout << " /===\\ ";
    h.ubicar(x, y + 1); cout << "| |_| |";
    h.ubicar(x, y + 2); cout << "  \\_/ ";
}

void EscudoPlasma::borrar() {
    Herramienta h;
    h.ubicar(x, y); cout << "       ";
    h.ubicar(x, y + 1); cout << "       ";
    h.ubicar(x, y + 2); cout << "       ";
}

void EscudoPlasma::mover() {

    contador++;
    if (contador % pasoFrames != 0) return;

    y += dy;


    if (y + alto >= 56) {
        borrar();
        estado_activo = false;

    }
}


void EscudoPlasma::generarPosAleatoria() {

    setX(1 + rand() % (180 - 1 + 1));
    setY(21);
}

void EscudoPlasma::aplicarEfectoAlJugador(Jugador& jugador) {

    if (!estado_activo) return;
    borrar();
    estado_activo = false;

    jugador.addEscudo(1);
     

}