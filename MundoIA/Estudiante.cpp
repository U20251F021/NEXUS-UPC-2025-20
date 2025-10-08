#include "pch.h"
#include "Estudiante.h"
#include "Herramienta.h"
#include "iostream"
#include <vector>
#include <string>
using namespace std;

Estudiante::Estudiante() {
	cargarPreguntas();
	ayudas = 0;
}
Estudiante::Estudiante(int px, int py, int w, int h) : Aliado(px, py, w, h) {

}

void Estudiante::dibujar() {
	Herramienta h; h.asignarcolor(6);
	h.ubicar(x, y);     cout << "   '''''   ";
	h.ubicar(x, y + 1); cout << "   |° °|   ";
	h.ubicar(x, y + 2); cout << "   |---|   ";
	h.ubicar(x, y + 3); cout << "    | |    ";
	h.ubicar(x, y + 4); cout << "   /| |\\  ";
	h.ubicar(x, y + 5); cout << "  / | | \\ ";
	h.ubicar(x, y + 6); cout << "    | |    ";
	h.ubicar(x, y + 7); cout << "   // \\\\ ";
	h.ubicar(x, y + 8); cout << "  //   \\\\";
}
void Estudiante::borrar() {
	Herramienta h; h.asignarcolor(2);
	h.ubicar(x, y);      cout << "           ";
	h.ubicar(x, y + 1);  cout << "           ";
	h.ubicar(x, y + 2);  cout << "           ";
	h.ubicar(x, y + 3);  cout << "           ";
	h.ubicar(x, y + 4);  cout << "           ";
	h.ubicar(x, y + 5);  cout << "           ";
	h.ubicar(x, y + 6);  cout << "           ";
	h.ubicar(x, y + 7);  cout << "           ";
	h.ubicar(x, y + 8);  cout << "           ";


}


void Estudiante::aplicarEfectoAlJugador(Jugador& jugador) {
	Herramienta h;
	if (this->intersecta(jugador.getRect()) && !preguntas.empty()) {
		this->borrar();
		this->generarPosAleatoria();


		int pregPos = rand() % preguntas.size();
		Pregunta pregunta = preguntas[pregPos];
		preguntas.erase(preguntas.begin() + pregPos);

		h.dialogo(202, 258, 16, 19, pregunta.texto, 7); h.asignarcolor(7);
		h.ubicar(202, 20); h.asignarcolor(7); cout << pregunta.opciones[0];
		h.ubicar(202, 22); h.asignarcolor(7); cout << pregunta.opciones[1];
		h.ubicar(202, 24); h.asignarcolor(7); cout << pregunta.opciones[2];
		h.dialogo(202, 258, 8, 13, pregunta.opciones[3], 6);
		h.ubicar(202, 26); h.asignarcolor(7); cout << "Ingresa tu respuesta (a, b, c): ";
		char respuestaUsuario;
		cin >> respuestaUsuario;

		if (respuestaUsuario == pregunta.respuestaCorrecta) {
			h.ubicar(202, 28); h.asignarcolor(2); cout << "Respuesta correcta! Un paso mas a la victoria!";
			ayudas++;
			_sleep(200);
			h.borrarDialogo(202, 259, 7, 29, pregunta.texto + pregunta.opciones[0] + pregunta.opciones[1] + pregunta.opciones[2] + "Ingresa tu respuesta (a, b, c): " + "Respuesta correcta! Un paso mas cerca de terminar el dia!");
		}
		else {
			h.ubicar(202, 28); h.asignarcolor(4); cout << "Respuesta incorrecta... ";
			jugador.setVidas(jugador.getVidas() - 1);
			_sleep(200);
			h.borrarDialogo(202, 259, 7, 29, pregunta.texto + pregunta.opciones[0] + pregunta.opciones[1] + pregunta.opciones[2] + "Ingresa tu respuesta (a, b, c): " + "Respuesta incorrecta... ");


		}
	}
}

void Estudiante::generarPosAleatoria() {
	this->setX(80 + rand() % (180 - 80 + 1));
	this->setY(21 + rand() % (50 - 21 + 1));
}

void Estudiante::cargarPreguntas() {
	preguntas.clear(); // Limpia por si ya tenía preguntas cargadas

	preguntas.push_back({
		"Soy el cerebro de la maquina, aprendo de datos sin descanso; sin mi, la IA no tendria avance.?",
		{"a) Algoritmo", "b) Neurona", "c) Procesador", "Hola! soy IA BART, tu y yo podremos juntos con esto! te dejo una pista: No soy humano, pero puedo “pensar”."},
		'a'
		});

	preguntas.push_back({
		"Trabajo en silencio en tu dispositivo, guardo informacion que quieres proteger; si me rompen, todo se pierde.",
		{"a) Memoria RAM", "b) Disco Duro", "c) Cache", "Hola! soy IA BART, tu y yo podremos juntos con esto! te dejo una pista: Soy rapido, pero no corro."},
		'b'
		});

	preguntas.push_back({
		"Me entrenan con miles de ejemplos, y puedo hablar, escribir o incluso crear imagenes; mi objetivo es predecir lo que sigue.",
		{"a) IA", "b) Red neuronal", "c) Sistema experto", "Hola! soy IA BART, tu y yo podremos juntos con esto! te dejo una pista: A veces me confunden con un humano al responder."},
		'a'
		});

	preguntas.push_back({
		" Aunque no tengo ojos, puedo ver, aunque no tengo manos, puedo tocar, mis sensores me ayudan a explorar el mundo fisico.",
		{"a) Robot", "b) Drone", "c) Camara", "Hola! soy IA BART, tu y yo podremos juntos con esto! te dejo una pista: Suelo moverse en entornos peligrosos para humanos."},
		'a'
		});

	preguntas.push_back({
		"Sin mi, no hay interaccion digital, interpreto tus comandos y los transformo en acciones dentro del software.",
		{"a) Driver", "b) API", "c) Interfaz", "Hola! soy IA BART, tu y yo podremos juntos con esto! te dejo una pista: Soy el traductor entre humanos y maquinas."},
		'c'
		});

	preguntas.push_back({
		"Puedo procesar imagenes y sonidos, pero no entiendo lenguaje humano.",
		{"a) Inteligencia Artificial", "b) Red neuronal", "c) Sistema experto", "Hola! soy IA BART, tu y yo podremos juntos con esto! te dejo una pista: Aprendo de ejemplos visuales o auditivos."},
		'b'
		});
}