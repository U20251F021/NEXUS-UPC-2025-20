
#pragma once
#include "pch.h"
#include "Recurso.h"
#include "Herramienta.h"

class LlaveAcoplamiento : public Recurso {
private:
    int contador;
    int dy;
    int pasoFrames;   // cada cuántos frames se mueve (2 rápido, 3+ más lento)

public:
    LlaveAcoplamiento();
    LlaveAcoplamiento(int px, int py);
    virtual ~LlaveAcoplamiento() {}

    void dibujar() override;
    void borrar()  override;
    void mover()   override;

    void generarPosAleatoria() override;

    void aplicarEfectoAlJugador(Jugador& jugador) override;

    void setPasoFrames(int n) { pasoFrames = (n < 1 ? 1 : n); }


    int colorDeCelda(int  fila, int  col) override { return 10; }

};