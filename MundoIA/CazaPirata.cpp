#include "pch.h"
#include "CazaPirata.h"
#include <iostream>
#include <cstdlib>
using namespace std;

CazaPirata::CazaPirata() : Enemigo() {
    contador = 0; dx = 0; dy = 1;
    ancho = 13; alto = 3;
}

CazaPirata::CazaPirata(int px, int py, int w, int h) : Enemigo(px, py, w, h) {
    contador = 0; dx = 0; dy = 1;
}

void CazaPirata::dibujar() {
    Herramienta h; h.asignarcolor(4);
    h.ubicar(x, y); cout << "  \\==^==/   ";
    h.ubicar(x, y + 1); cout << "===|.|=== ";
    h.ubicar(x, y + 2); cout << "   /   \\    ";
}

void CazaPirata::borrar() {
    Herramienta h;
    h.ubicar(x, y); cout << "             ";
    h.ubicar(x, y + 1); cout << "             ";
    h.ubicar(x, y + 2); cout << "             ";
}

void CazaPirata::mover(Jugador& jugador) {
    contador++;
    if (contador % 2 != 0) return;
    y += dy;


    if (y + alto >= 56) {
        estado_activo = false;
        borrar();

        return;
    }
}

void CazaPirata::aplicarEfectoAlJugador(Jugador& jugador) {

    jugador.setVidas(jugador.getVidas() - 1);


    estado_activo = false;
    borrar();
}

void CazaPirata::generarPosAleatoria() {
    setX(1 + rand() % (180 - 1 + 1));
    setY(21);
}