#pragma once
#include "Recurso.h"
#include "Herramienta.h"
#include "string"

class Reloj : public Recurso
{
private:
	int contador;
public:
	Reloj() {
		cantidad = 80;
	}

	virtual ~Reloj() {

	}

	Reloj(int px, int py, int w, int h) :Recurso(px, py, w, h) {
		cantidad = 0;
		contador = 0;
		generarPosAleatoria();
	}
	// Métodos heredados 
	void generarPosAleatoria() override;
	void dibujar() override;
	void borrar() override;

	void aplicarEfectoAlJugador(Jugador& jugador) override;

	int  getCantidad() { return cantidad; }

	int colorDeCelda(int fila, int columna) {
		return 0;
	}

	void setCantidad(int nuevaCantidad) {
		cantidad = nuevaCantidad;
	}


};

