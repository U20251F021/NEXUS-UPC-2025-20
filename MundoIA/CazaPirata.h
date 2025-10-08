#pragma once
#include "pch.h"
#include "Enemigo.h"
#include "Herramienta.h"

class CazaPirata : public Enemigo {
private:
    int contador;
    int dx;
    int dy;

public:
    CazaPirata();
    CazaPirata(int px, int py, int w = 13, int h = 3);
    virtual ~CazaPirata() {}

    void dibujar() override;
    void borrar() override;
    void mover(Jugador& jugador) override;
    void aplicarEfectoAlJugador(Jugador& jugador) override;
    void generarPosAleatoria() override;
};