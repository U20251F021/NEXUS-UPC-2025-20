#pragma once
#include "Enemigo.h"
#include <cstdlib>  
#include <ctime>    
#include "Jugador.h"


class Drone : public Enemigo {
private:
    int contador;
    int dx, dy; 
public:
    Drone();
    Drone(int px, int py, int w, int h);
    virtual ~Drone();

    // Métodos heredados obligatorios
    void dibujar() override;
    void borrar() override;
    void mover(Jugador& jugador) override;
    void aplicarEfectoAlJugador(Jugador& jugador) override;
    

    // Método propio
    void generarPosAleatoria();
    
};