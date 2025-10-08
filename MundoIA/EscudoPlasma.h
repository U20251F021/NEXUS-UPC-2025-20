//. h
#pragma once
#include "pch.h"
#include "Recurso.h"
#include "Herramienta.h"

class EscudoPlasma : public Recurso {
private:
    int contador;
    int dy;
    int pasoFrames;


public:
    EscudoPlasma();
    EscudoPlasma(int px, int py);
    virtual ~EscudoPlasma() {}

    void dibujar() override;
    void borrar()  override;
    void mover()   override;
    void generarPosAleatoria() override;



    void aplicarEfectoAlJugador(Jugador& jugador) override;


    void setPasoFrames(int n) { pasoFrames = (n < 1 ? 1 : n); }


    int colorDeCelda(int  fila, int  col) override { return 14; } // amarillo
};