#pragma once
#include "pch.h"
#include "Herramienta.h"
#include "Jugador.h"
#include <string>
using namespace std;

class Enemigo {
protected:
    int x, y;
    int ancho, alto;
    bool estado_activo;


public:
    // Constructores y destructor
    Enemigo();
    Enemigo(int px, int py, int w, int h);
    virtual ~Enemigo();

    // Getters y setters
    int getX();
    int getY();
    int getAncho();
    int getAlto();
    void setX(int nx);
    void setY(int ny);
    void setTamaño(int w, int h);
    bool activo();

    // Métodos virtuales
    virtual void mover(Jugador& jugador) = 0;
    virtual void aplicarEfectoAlJugador(Jugador& jugador) = 0;
    virtual void dibujar() = 0;
    virtual void borrar() = 0;
    virtual void generarPosAleatoria() = 0;
    // Métodos generales


    void animar(Jugador& jugador);
    Rectangle obtenerRectangulo();
    bool intersecta(Rectangle& r);
};
