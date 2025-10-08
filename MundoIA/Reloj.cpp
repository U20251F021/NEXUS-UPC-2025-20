#include "pch.h"
#include "Reloj.h"
#include "Recurso.h"
#include "iostream"
#include "Juego.h"

void Reloj::dibujar() {
    Herramienta h;
    h.asignarcolor(4);
    h.ubicar(x, y);     cout << "   _____   ";
    h.ubicar(x, y + 1); cout << "  /     \\ ";
    h.ubicar(x, y + 2); cout << " |  |    | ";
    h.ubicar(x, y + 3); cout << " |  °--- | ";
    h.ubicar(x, y + 4); cout << " |       | ";
    h.ubicar(x, y + 5); cout << "  \\_____/ ";

}

void Reloj::borrar() {

    Herramienta h;

    h.ubicar(x, y);     cout << "          ";
    h.ubicar(x, y + 1); cout << "          ";
    h.ubicar(x, y + 2); cout << "          ";
    h.ubicar(x, y + 3); cout << "          ";
    h.ubicar(x, y + 4); cout << "          ";
    h.ubicar(x, y + 5); cout << "          ";

}


void Reloj::aplicarEfectoAlJugador(Jugador& jugador) {


    if (this->intersecta(jugador.getRect()))
    {

        this->borrar();
        this->generarPosAleatoria();
        cantidad += 10;
    }





}
void Reloj::generarPosAleatoria() {
    this->setX(1 + rand() % (180 - 1 + 1));
    this->setY(21 + rand() % (52 - 21 + 1));




}