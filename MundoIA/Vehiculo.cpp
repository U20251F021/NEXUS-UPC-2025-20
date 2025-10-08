// Adr
#include "pch.h"
#include "Vehiculo.h"
#include "iostream"
#include <vector>
using namespace std;

VehiculoIA::VehiculoIA() : Enemigo(30, 20, 13, 9) {}
VehiculoIA::VehiculoIA(int px, int py, int w, int h) : Enemigo(px, py, w, h) {
	this->contador = 0;
	this->px = px;
	this->py = py;
	this->dy = 1;
	this->tipo = rand() % 2;
}
VehiculoIA::~VehiculoIA() {}

void VehiculoIA::dibujar() {
	Herramienta h;
	h.asignarcolor(4);

	if (tipo == 0) {
		h.ubicar(x, y);     cout << "   ______    ";
		h.ubicar(x, y + 1); cout << "||/ °  ° \\|| ";
		h.ubicar(x, y + 2); cout << " |_      _|  ";
		h.ubicar(x, y + 3); cout << " | |    | |  ";
		h.ubicar(x, y + 4); cout << " | |    | |  ";
		h.ubicar(x, y + 5); cout << " |°|____|°|  ";
		h.ubicar(x, y + 6); cout << " |--|--|--|  ";
		h.ubicar(x, y + 7); cout << " |________|  ";
		h.ubicar(x, y + 8); cout << "||\\______/|| ";


	}
	else {
		h.ubicar(x, y);     cout << "  ________   ";
		h.ubicar(x, y + 1); cout << " _||____||_  ";
		h.ubicar(x, y + 2); cout << "||_      _|| ";
		h.ubicar(x, y + 3); cout << " | | 88 | |  ";
		h.ubicar(x, y + 4); cout << " |--    --|  ";
		h.ubicar(x, y + 5); cout << " | |____| |  ";
		h.ubicar(x, y + 6); cout << " |--|  |--|  ";
		h.ubicar(x, y + 7); cout << " |________|  ";
		h.ubicar(x, y + 8); cout << "||\\______/||";
	}
}

void VehiculoIA::borrar() {
	Herramienta h;
	h.ubicar(x, y);       cout << "             ";
	h.ubicar(x, y + 1);   cout << "             ";
	h.ubicar(x, y + 2);   cout << "             ";
	h.ubicar(x, y + 3);   cout << "             ";
	h.ubicar(x, y + 4);   cout << "             ";
	h.ubicar(x, y + 5);   cout << "             ";
	h.ubicar(x, y + 6);   cout << "             ";
	h.ubicar(x, y + 7);   cout << "             ";
	h.ubicar(x, y + 8);   cout << "             ";
}

void VehiculoIA::mover(Jugador& jugador) {
	contador++;
	if (contador % 2 == 0) {
		if (y + dy < 20) {
			dy = 1;
		}
		else if (y + dy > 59 - alto) {
			dy = -1;
		}
		y += dy;
	}


}
void VehiculoIA::aplicarEfectoAlJugador(Jugador& jugador) {
	if (this->intersecta(jugador.getRect())) {
		this->borrar();
		this->generarPosAleatoria();
		jugador.setVidas(jugador.getVidas() - 1);
	}
}


void VehiculoIA::generarPosAleatoria() {
	int posicionesPermitidasX[] = { 30, 45, 60, 75 };
	int n = sizeof(posicionesPermitidasX) / sizeof(posicionesPermitidasX[0]);

	int indice = rand() % n;
	this->setX(posicionesPermitidasX[indice]);
	this->setY(20);
}
