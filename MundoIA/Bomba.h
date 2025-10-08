#pragma once
#include "Herramienta.h"
#include "string"
#include "Recurso.h"
#include <ctime>

using namespace std;
class Bomba : public Recurso
{
private:
	int daño;
	bool llego[5];
public:
	Bomba() {

	}

	void setLlego(bool nuevo, int pos) {
		llego[pos] = nuevo;
	}
	bool getLlego(int pos) {
		return llego[pos];
	}

	void generarPosAleatoria() override;


	Bomba(int x, int y, int ancho, int alto, int daño)
		:Recurso(x, y, ancho, alto) {
		this->daño = daño;
		for (int i = 0; i < 5; i++) {
			llego[i] = false;
		}
	}
		
	~Bomba() {

	}
	int colorDeCelda(int fila, int columna) {
		return 0 ;
	}
	void dibujar() override;
	void borrar() override;
	void mover() override{}
	void aplicarEfectoAlJugador(Jugador& jugador) override;
	

};

