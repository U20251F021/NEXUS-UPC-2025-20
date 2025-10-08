#include "pch.h"
#include "DronInterferidor.h"
#include <iostream>
#include <cstdlib>
using namespace std;

DronInterferidor::DronInterferidor() : Enemigo() {
    contador = 0; dx = 0; dy = 1;
    ancho = 9; alto = 3;
}

DronInterferidor::DronInterferidor(int px, int py, int w, int h) : Enemigo(px, py, w, h) {
    contador = 0; dx = 0; dy = 1;
}

void DronInterferidor::dibujar() {
    Herramienta h; h.asignarcolor(8);
    h.ubicar(x, y); cout << "  .-o-.  ";
    h.ubicar(x, y + 1); cout << " '-|-|-' ";
    h.ubicar(x, y + 2); cout << "   | |   ";
}

void DronInterferidor::borrar() {
    Herramienta h;
    h.ubicar(x, y); cout << "         ";
    h.ubicar(x, y + 1); cout << "         ";
    h.ubicar(x, y + 2); cout << "         ";
}

void DronInterferidor::mover(Jugador& jugador) {
    contador++;
    if (contador % 3 != 0) return;
    y += dy;

    if (y + alto >= 56) {
        estado_activo = false;
        borrar();
        return;
    }
}

void DronInterferidor::aplicarEfectoAlJugador(Jugador& jugador) {

    int e = jugador.getEnergia();               
    if (e > 0) {
        jugador.addEnergia(-1);

        Herramienta h; h.asignarcolor(11); 
    }
    estado_activo = false;
    borrar();
}


void DronInterferidor::generarPosAleatoria() {
    setX(1 + rand() % (180 - 1 + 1));
    setY(21);
}