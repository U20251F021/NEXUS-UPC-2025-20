#include "pch.h"
#include "Jugador.h"
#include "conio.h"
Jugador::Jugador() {
    x = 4; y = 4;
    vidas = 3; respuesta = "";
    cantidadLlaves = 0;
    tieneLlave = false;
    ancho = AnchoJugador; alto = AltoJugador;
    escudos = 0;              // << nuevo
    energiaRecolectada = 0;
    aplicarSkin(1);
}

Jugador::Jugador(int px, int py, int skinId) {
    x = px; y = py;
    vidas = 3; respuesta = "";
    cantidadLlaves = 0;
    tieneLlave = false;
    ancho = AnchoJugador; alto = AltoJugador;
    escudos = 0;              // << nuevo
    energiaRecolectada = 0;
    aplicarSkin(skinId);
}

void Jugador::setX(int nx) { x = nx; }
int  Jugador::getX() { return x; }
int  Jugador::setCantidadLlaves(int cl) { return cantidadLlaves = cl; }
void Jugador::setY(int ny) { y = ny; }

bool Jugador::setTieneLlave(bool tl) { return tieneLlave = tl; }
int  Jugador::getY() { return y; }
void Jugador::setVidas(int v) { vidas = v; }
int  Jugador::getVidas() { return vidas; }
void Jugador::setRespuesta(string r) { respuesta = r; }
string Jugador::getRespuesta() { return respuesta; }
bool Jugador::getTieneLlave() { return tieneLlave; }
int  Jugador::getCantidadLlaves() { return cantidadLlaves; }

void Jugador::dibujar() {
    Herramienta h;
    for (int f = 0; f < alto; ++f) {
        for (int c = 0; c < ancho; ++c) {
            int color = matriz[f][c];
            h.asignarcolor(color);
            h.ubicar(x + c, y + f);
            cout << char(219);
        }
    }
}

void Jugador::borrar() {
    Herramienta h;
    for (int f = 0; f < alto; ++f) {
        h.asignarcolor(0);
        for (int c = 0; c < ancho; ++c) {
            h.ubicar(x + c, y + f);
            cout << " ";
        }
    }
}

void Jugador::mover() {

    if (!kbhit()) return;
    int t = getch();
    if (t == 224) t = getch(); // flechas

    switch (t) {
    case 'a': case 'A': case 75: // LEFT
        if (x > 1) x -= 1;
        break;
    case 'd': case 'D': case 77: // RIGHT
        if (x + ancho < 199) x += 1;
        break;
    case 'w': case 'W': case 72: // UP
        if (y > 20) y -= 1;
        break;
    case 's': case 'S': case 80: // DOWN
        if (y + alto < 59) y += 1;
        break;
    default: break;
    }


}

void Jugador::animar() {
    borrar();
    mover();
    dibujar();
}

