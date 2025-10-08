#pragma once
#include "pch.h"
#include "Herramienta.h"
#include "Jugador.h"
using namespace System::Drawing;
using namespace std;
class Recurso
{
protected:
	int x, y;
	int ancho, alto;
	bool estado_activo;       // estado (los hijos pueden redefinir su lógica)
	int cantidad = 0;
public:

	Recurso();
	Recurso(int px, int py, int w, int h);
	~Recurso();

	int  getX();
	int  getY();
	int  getAncho();
	int  getAlto();
	void setX(int nx);
	void setY(int ny);
	void setTamaño(int w, int h);
	bool activo();
	void setEstado(bool nuevoEstado);

	virtual void generarPosAleatoria() = 0;

	virtual void aplicarEfectoAlJugador(Jugador& jugador) = 0;

	virtual int  colorDeCelda(int fila, int columna) = 0;

	virtual void mover() {}


	void setCantidad(int nuevaCantidad) {
		cantidad = nuevaCantidad;;
	}
	int getCantidad() {
		return this->cantidad;
	}

	virtual void dibujar() = 0;

	virtual void borrar() = 0;



	void animar();

	Rectangle obtenerRectangulo();
	bool intersecta(Rectangle& r);


};

