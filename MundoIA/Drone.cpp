#include "pch.h"
#include "Drone.h"
#include <iostream>
using namespace std;

Drone::Drone() : Enemigo() {}
Drone::Drone(int px, int py, int w, int h) : Enemigo(px, py, w, h) {
    this->contador = 0;
    this->dx = 1;
    this->dy = 1;
}
Drone::~Drone() {}

void Drone::dibujar() {
    Herramienta h;
    h.asignarcolor(4);
    h.ubicar(x, y);     cout << "_  _   _______   _  _";
    h.ubicar(x, y+1);   cout << "|__|__(---o---)__|__|";
    h.ubicar(x, y+2);   cout << "       (vvvvv)       ";
    h.ubicar(x, y+3);   cout << "         / \\        ";
                                  
}

void Drone::borrar() {

    Herramienta h;

    h.ubicar(x, y);       cout << "                     ";
    h.ubicar(x, y + 1);   cout << "                     ";
    h.ubicar(x, y + 2);   cout << "                     ";
    h.ubicar(x, y + 3);   cout << "                     ";

}

void Drone::mover(Jugador& jugador) {
    contador++;
    if (contador % 5 != 0) return;

    x += dx;
    y += dy;

  
    if (x <= 0 || x + ancho >= 200) {
        dx *= -1;  
        x += dx;   
    }
    if (y <= 20 || y + alto >= 60) {
        dy *= -1;  
        y += dy;   
    }
}


void Drone::aplicarEfectoAlJugador(Jugador& jugador) {

    if(this->intersecta(jugador.getRect())){
    jugador.setVidas(jugador.getVidas() - 1);
	this->borrar();
	this->generarPosAleatoria();
    }
}


void Drone::generarPosAleatoria() {
    
    this->setX(1 + rand() % (180 - 1 + 1));
    this->setY(21 + rand() % (48 - 21 + 1));
}