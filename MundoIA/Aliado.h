#pragma once
#include "pch.h"
#include "Herramienta.h"
#include "Jugador.h"

using namespace std;

class Aliado {
protected:
    int  x, y;
    int  ancho, alto;
    bool estado_activo;
    int ayudas = 3;

public:
    Aliado();
    Aliado(int px, int py, int w, int h);
    virtual ~Aliado();

    // Acceso básico
    int  getX();
    int  getY();
    int  getAncho();
    int  getAlto();
    void setX(int nx);
    void setY(int ny);
    void setTamaño(int w, int h);
    bool activo() const;
    void setAyudas(int nuevaAyuda) { ayudas = nuevaAyuda; }
    int getAyudas() { return ayudas; }

    // Métodos virtuales puros
    
    virtual void aplicarEfectoAlJugador(Jugador& j) = 0;
    virtual int  colorDeCelda(int fila, int col) = 0;

    // Métodos virtuales redefinibles
    virtual void dibujar() = 0;
    virtual void borrar() = 0 ;

    // Colisiones
    Rectangle obtenerRectangulo() ;
    bool intersecta( Rectangle& r) ;
};
