#pragma once
#include "Enemigo.h"
#include "Jugador.h"
#include <cstdlib>
#include <ctime>

class Torreta : public Enemigo {
private:
    int contador;
    bool disparo;
    bool proyectilActivo;
    int px, py;
    int dx;
public:
    Torreta();
    Torreta(int px, int py, int w, int h);
    virtual ~Torreta();

    // Métodos heredados 
    void dibujar() override;
    void borrar() override;
    void mover(Jugador& jugador) override;
    void aplicarEfectoAlJugador(Jugador& jugador) override;
    int colorDeCelda(int fila, int columna) {

    }
    void disparar(Jugador& jugador);
    void generarPosAleatoria();
    void moverProyectil();
    void borrarProyectil();
};
