#include "pch.h"
#include "CelulaEnergia.h"
#include <iostream>
#include <cstdlib>
using namespace std;

// Tamaño fijo de este recurso (coincide con las cadenas de dibujar/borrar)
const int CE_ANCHO = 7;
const int CE_ALTO = 3;



CelulaEnergia::CelulaEnergia()
    : Recurso(0, 0, CE_ANCHO, CE_ALTO) {
    contador = 0;
    dy = 1;
    pasoFrames = 3;   // 2 más rápido, 4 más lento

}

CelulaEnergia::CelulaEnergia(int px, int py)
    : Recurso(px, py, CE_ANCHO, CE_ALTO) {
    contador = 0;
    dy = 1;
    pasoFrames = 3;
}

void CelulaEnergia::dibujar() {
    Herramienta h; h.asignarcolor(9); // azul
    h.ubicar(x, y); cout << " .-+-. ";
    h.ubicar(x, y + 1); cout << " |+*+| ";
    h.ubicar(x, y + 2); cout << " '-+-' ";
}

void CelulaEnergia::borrar() {
    Herramienta h;
    h.ubicar(x, y); cout << "       ";
    h.ubicar(x, y + 1); cout << "       ";
    h.ubicar(x, y + 2); cout << "       ";
}

void CelulaEnergia::mover() {
    contador++;
    if (contador % pasoFrames != 0) return;

    const int CY2 = 58;               
    const int maxTop = CY2 - alto;    

    int ny = y + dy;

    if (ny > maxTop) {
       
        y = maxTop;
        estado_activo = false;
        return;
         
    }

    y = ny;
}


void CelulaEnergia::generarPosAleatoria() {

    setX(1 + rand() % (180 - 1 + 1));  
    setY(21);
}

void CelulaEnergia::aplicarEfectoAlJugador(Jugador& j) {
    if (!estado_activo) return;
    estado_activo = false;
    borrar();
    j.addEnergia(1);    
}