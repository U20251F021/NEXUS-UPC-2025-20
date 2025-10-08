#pragma once
#include "Aliado.h"

#include <string>
#include <vector>
class Estudiante : public Aliado
{
private:
	int contador;
	int px, py;
	int dx, dy;

	struct Pregunta {
		string texto;
		string opciones[4];
		char respuestaCorrecta; // 'a', 'b', 'c'
	};

	vector<Pregunta> preguntas;




public:
	Estudiante();
	Estudiante(int px, int py, int w, int h);

	void borrar() override;
	void dibujar() override;
	void aplicarEfectoAlJugador(Jugador& jugador) override;
	int  colorDeCelda(int fila, int col) override {
		return 0;
	}
	void generarPosAleatoria();					 // nuevo



	void cargarPreguntas();                            // nuevo
};