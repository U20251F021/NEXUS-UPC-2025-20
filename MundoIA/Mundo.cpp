#include "pch.h"
#include "Mundo.h"

Mundo::Mundo() {}
Mundo::~Mundo(){}


void Mundo::dibujarContornos(int x1, int x2, int y1, int y2) {
	Herramienta h;
	if (x1 < 0 || x2>260 || y1 < 0 || y2>60) { cout << "Fuera de rango" << endl; return; }
	for (int i = 0; i < x2 - x1; i++) {
		h.asignarcolor(15); h.ubicar(x1 + i - 1, y1 - 1); cout << char(219);
		h.asignarcolor(15); h.ubicar(x1 + i - 1, y2 - 1); cout << char(219);
	}
	for (int i = 0; i < y2 - y1; i++) {
		h.asignarcolor(15); h.ubicar(x1 - 1, y1 + i - 1); cout << char(219);
		h.asignarcolor(15); h.ubicar(x2 - 1, y1 + i - 1); cout << char(219);
	}
}


