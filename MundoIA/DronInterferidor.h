#pragma once
#include "pch.h"
#include "Enemigo.h"
#include "Herramienta.h"

class DronInterferidor : public Enemigo {
private:
    int contador;
    int dx;
    int dy;

public:
    DronInterferidor();
    DronInterferidor(int px, int py, int w = 9, int h = 3);
    virtual ~DronInterferidor() {}

    void dibujar() override;
    void borrar() override;
    void mover(Jugador& jugador) override;
    void aplicarEfectoAlJugador(Jugador& jugador) override;
    void generarPosAleatoria() override;
};