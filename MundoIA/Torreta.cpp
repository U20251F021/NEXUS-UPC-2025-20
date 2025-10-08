#include "pch.h"
#include "Torreta.h"
#include "Herramienta.h"
#include <iostream>
using namespace std;

Torreta::Torreta() : Enemigo(0, 0, 3, 3) {}  
Torreta::Torreta(int px, int py, int w, int h) : Enemigo(px, py, w, h) {
    this->dx = 1;
    this->contador = 0;
    this->disparo = false;
    this->proyectilActivo = false;
}
Torreta::~Torreta() {}

void Torreta::dibujar() {
     
    Herramienta h;
    h.asignarcolor(7);
     h.ubicar(x,y);    cout<<"      /|\\      ";
     h.ubicar(x,y+1);  cout<<"     |-.-|      ";
     h.ubicar(x,y+2);  cout<<"     '-:-'      ";
     h.ubicar(x,y+3);  cout<<"      [|]       ";
     h.ubicar(x,y+4);  cout<<"      [|]       ";
     h.ubicar(x,y+5);  cout<<"     :/|\\:     ";
     h.ubicar(x,y+6);  cout<<"     [/|\\]     ";
     h.ubicar(x,y+7);  cout<<"   .:_#|#_:.    ";
     h.ubicar(x,y+8);  cout<<"   |_ '-' _|    ";
    
     if (proyectilActivo) {
         h.asignarcolor(7);
         h.ubicar(px, py);
         cout << char(219);
     }
    
}

void Torreta::borrar() {
    Herramienta h;

    h.ubicar(x, y);      cout << "                ";
    h.ubicar(x, y + 1);  cout << "                ";
    h.ubicar(x, y + 2);  cout << "                ";
    h.ubicar(x, y + 3);  cout << "                ";
    h.ubicar(x, y + 4);  cout << "                ";
    h.ubicar(x, y + 5);  cout << "                ";
    h.ubicar(x, y + 6);  cout << "                ";
    h.ubicar(x, y + 7);  cout << "                ";
    h.ubicar(x, y + 8);  cout << "                ";

    borrarProyectil();
}


void Torreta::mover(Jugador& jugador) {
    contador++;
  
    if (contador % 3 == 0) {

        if (x <= 0 || x + ancho >= 199) { 
            dx *= -1;
        }
       
        x += dx;
    }
        
    if (contador % 5 == 0) {
    int jx = jugador.getX();
    if (jx >= x && jx <= x + ancho) {
        disparo = true;
        disparar(jugador);
    }
    
    if (proyectilActivo) {
        moverProyectil();
    }

    }
}

void Torreta::aplicarEfectoAlJugador(Jugador& jugador) {
    if (proyectilActivo && jugador.getRect().IntersectsWith(Rectangle(px, py, 1, 1))) {
        jugador.setVidas(jugador.getVidas() - 1);
        proyectilActivo = false; 
    }
}

void Torreta::generarPosAleatoria() {
    
    x = 1 + rand() % (180 - ancho);
    y = 50;
}

void Torreta::disparar(Jugador& jugador) {
    if (!proyectilActivo) {
        px = x + ancho / 2; 
        py = y -1;        
        proyectilActivo = true;
    }
}

 void Torreta::moverProyectil() {
     if (!proyectilActivo) return;

     borrarProyectil();

     py--; 

     if (py < 21 ) {
         proyectilActivo = false; // desaparece si sale del mapa
     }
 }

 void Torreta::borrarProyectil() {
     if (proyectilActivo) {
         Herramienta h;
         h.ubicar(px, py);
         cout << " ";
     }
 }