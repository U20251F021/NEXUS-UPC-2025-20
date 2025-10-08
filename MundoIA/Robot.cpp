#include "pch.h"
#include "Robot.h"

Robot::Robot() {

}

Robot::Robot(int px, int py, int w, int h) : Aliado(px, py, w, h) {
    
}

void Robot::dibujar() {
    Herramienta h; h.asignarcolor(2);
    h.ubicar(x, y);    cout << "  ;   ";
    h.ubicar(x, y + 1); cout << " [o]  ";
    h.ubicar(x, y + 2);  cout << "/[_]\\";
    h.ubicar(x, y + 3);  cout << " ] [  ";
}

void Robot::borrar() {
    Herramienta h; h.asignarcolor(2);
    h.ubicar(x, y);      cout << "      ";
    h.ubicar(x, y + 1);  cout << "      ";
    h.ubicar(x, y + 2);  cout << "      ";
    h.ubicar(x, y + 3);  cout << "      ";
}

void Robot::aplicarEfectoAlJugador(Jugador& j)
{   
    if(j.getVidas() < 3 && ayudas > 0 && this->intersecta(j.getRect())){
        j.setVidas(j.getVidas() + 1);
        this->borrar();
        this->setX(1 + rand() % (180 - 1 + 1));
		this->setY(21 + rand() % (48 - 21 + 1));
        ayudas--;
        

	}

}
