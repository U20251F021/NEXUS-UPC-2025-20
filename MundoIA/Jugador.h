#pragma once
#include "pch.h"
#include "Herramienta.h"
#include "string"
#include <iostream>

using namespace System::Drawing;
using namespace std;

const int AnchoJugador = 12;
const int AltoJugador = 14;

class Jugador
{
private:
	int x, y;
	int vidas;
	string respuesta;
	int ancho, alto;

	int limiteX, limiteY;
	int cantidadLlaves;
	bool tieneLlave;
	int escudos = 0;              // << nuevo
	int energiaRecolectada = 0;


	int ASTRONAUTA[AltoJugador][AnchoJugador] = {
		{0,0,0,7,7,7,7,7,7,0,0,0},
		{0,0,7,7,0,0,0,0,7,7,0,0},
		{0,0,7,0,0,0,0,0,0,7,0,0},
		{0,7,0,0,0,0,7,0,0,0,7,0},
		{0,7,0,0,0,0,0,7,0,0,7,0},
		{0,0,7,0,0,0,0,0,0,7,0,0},
		{0,0,0,7,0,0,0,0,7,0,0,0},
		{7,7,7,7,7,7,7,7,7,7,7,7},
		{7,7,7,7,7,7,7,7,7,7,7,7},
		{7,7,0,7,7,7,7,7,7,0,7,7},
		{7,7,0,7,7,7,7,7,7,0,7,7},
		{0,0,0,7,7,0,0,7,7,0,0,0},
		{0,0,0,7,7,0,0,7,7,0,0,0},
		{0,0,7,7,7,0,0,7,7,7,0,0},
	};

	
	int ESTUDIANTE[AltoJugador][AnchoJugador] = {
		{0,0,4,4,4,4,4,4,4,4,0,0},
		{0,4,4,4,4,4,4,4,4,4,4,0},
		{0,0,6,6,0,6,6,6,0,6,0,0},
		{0,0,6,6,6,6,6,6,6,6,0,0},
		{0,0,6,6,0,0,0,0,6,6,0,0},
		{0,0,6,6,6,6,6,6,6,6,0,0},
		{0,0,0,6,6,6,6,6,6,0,0,0},
		{0,4,4,4,4,4,4,4,4,4,4,0},
		{4,4,4,4,4,4,4,4,4,4,4,4},
		{4,4,0,4,4,4,4,4,4,0,4,4},
		{4,4,0,1,1,1,1,1,1,0,4,4},
		{0,0,0,1,1,0,0,1,1,0,0,0},
		{0,0,0,1,1,0,0,1,1,0,0,0},
		{0,0,2,2,2,0,0,2,2,2,0,0},
	};


	int (*matriz)[AnchoJugador]; // Puntero a matriz para el jugador actual dependiendo del mundo: mundo 1 -> ASTRONAUTA, mundo 2 -> MINERO, mundo 3 -> ESTUDIANTE
	void aplicarSkin(int skinId) {
		switch (skinId) {
		case 1: matriz = ASTRONAUTA; break;

		case 3: matriz = ESTUDIANTE; break;
		default: matriz = ASTRONAUTA; break;
		}
	}


public:
	Jugador();

	Jugador(int px, int py, int skinId);
	void addEnergia(int n) { energiaRecolectada += n; }
	int  getEnergia() const { return energiaRecolectada; }

	// --- NUEVO: escudos ---
	void addEscudo(int n = 1) { escudos += n; }
	bool consumirEscudo() {
		if (escudos > 0) { --escudos; return true; }
		return false;
	}
	int  getEscudos() const { return escudos; }


	void setSkin(int skinId) { aplicarSkin(skinId); }

	~Jugador() {}

	// setters y getters
	void setX(int nx);
	int  getX();
	int  setCantidadLlaves(int cl);
	void setY(int ny);

	bool setTieneLlave(bool tl);
	int  getY();
	void setVidas(int v);
	int  getVidas();
	void setRespuesta(string r);
	string getRespuesta();
	bool getTieneLlave();
	int  getCantidadLlaves();

	// métodos de lógica
	void dibujar();
	void borrar();
	void mover();
	void animar();

	Rectangle getRect() {
		return System::Drawing::Rectangle(x, y, ancho, alto);
	}
	bool intersecta(Rectangle& r) {
		return getRect().IntersectsWith(r);
	}

};