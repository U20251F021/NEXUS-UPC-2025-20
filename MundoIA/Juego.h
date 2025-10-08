#pragma once
#include "pch.h"
#include "vector"
#include "Recurso.h"
#include "Bomba.h"
#include "Jugador.h"
#include "Mundo1.h"
#include "Aliado.h"
#include "Robot.h"
#include "Enemigo.h"
#include "Drone.h"
#include "Torreta.h"
#include "conio.h"
#include "iostream"
#include "Mundo2.h"
#include "Mundo3.h"

using namespace System;
using namespace std;


class Juego
{
private:

	vector<Enemigo*> enemigos;
	vector<Aliado*> aliados;
	Jugador* jugador;
	vector<Recurso*> recursos;
	Mundo1* mundo = nullptr;
	Mundo2* mundo2 = nullptr;
	bool nivelPasado = false;

public:

	Juego() {};
	Juego(vector<Enemigo*> enemigos, vector<Aliado*> aliados, Jugador* jugador, vector<Recurso*> recursos, Mundo1* mundo);
	~Juego() {};

	void presentacion();

	void nivel2(Jugador* jugador);
	void datosNivel2(Jugador* jugador);

	void nivel1(Jugador* jugador);
	void datos(Jugador* jugador, Aliado* robot, Recurso* bomba);

	void nivel3(Jugador* jugador);

	bool getEstadoNivel() {
		return nivelPasado;
	}
	void setEstadoNivel(bool nuevoEstado) {
		nivelPasado = nuevoEstado;
	}

    void instrucciones(int nivel);

	void ganaste();

	void perdiste();

	

};

