//Adr
#pragma once
#include "Enemigo.h"
#include "Jugador.h"
#include <cstdlib>
#include <ctime>

class VehiculoIA : public Enemigo
{
private:
    int contador;
    int px, py;
    int dy;
    int tipo;
public:

    VehiculoIA();
    VehiculoIA(int px, int py, int w, int h);
    virtual ~VehiculoIA();


    // Métodos heredados 
    void generarPosAleatoria() override;
    void dibujar() override;
    void borrar() override;
    void mover(Jugador& jugador) override;
    void aplicarEfectoAlJugador(Jugador& jugador) override;

};



