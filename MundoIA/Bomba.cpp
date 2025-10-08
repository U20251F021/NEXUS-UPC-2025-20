#include "pch.h"
#include "Bomba.h"
#include "Recurso.h"
#include "iostream"

void Bomba::dibujar() {
	Herramienta h;
	h.asignarcolor(4);
    h.ubicar(x, y);     cout << "        /";
    h.ubicar(x, y + 1); cout << "   ____/ ";
    h.ubicar(x, y + 2); cout << "  /__ /\\ ";
    h.ubicar(x, y + 3); cout << " /   /// ";
    h.ubicar(x, y + 4); cout << "/___/ /  ";
    h.ubicar(x, y + 5); cout << "\\___\\/ ";
          
}

void Bomba::borrar() {

    Herramienta h;
    
    h.ubicar(x, y);     cout << "         ";
    h.ubicar(x, y + 1); cout << "         ";
    h.ubicar(x, y + 2); cout << "         ";
    h.ubicar(x, y + 3); cout << "         ";
    h.ubicar(x, y + 4); cout << "         ";
    h.ubicar(x, y + 5); cout << "         ";

}

void Bomba::generarPosAleatoria() {
    
        this->setX(1 + rand() % (180 - 1 + 1));
        this->setY(21 + rand() % (48 - 21 + 1));
    
}

void Bomba::aplicarEfectoAlJugador(Jugador& jugador) {
    Herramienta h;
    if (this->intersecta(jugador.getRect())) {
        _sleep(600);
        this->borrar();
        this->generarPosAleatoria();
        string mensaje = "La clave de desactivacion de la bomba es: ";
        int random = 100000 + rand() % (999999 - 100000 + 1);
        
        h.ubicar(205, 28); h.asignarcolor(7); cout << mensaje;
        h.asignarcolor(6); cout << random;
        h.ubicar(206, 30); h.asignarcolor(7); cout << "Ingresa el codigo para desactivarla con exito";
        int codigo;
        h.ubicar(226, 32); cin >> codigo;
        if (codigo != random) { 
            h.borrarDialogo(205, 259, 28, 33, "");
            h.ubicar(213, 30); h.asignarcolor(4);
            cout << "ERROR, CODIGO INCORRECTO. -1 vida.";
            jugador.setVidas(jugador.getVidas() - 1);
            _sleep(700);
        }
        else{ this->cantidad++; }
        h.borrarDialogo(205, 259, 28, 33, "");
        this->dibujar();
        
      
    }
}
