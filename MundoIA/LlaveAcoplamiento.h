
#pragma once
#include "pch.h"
#include "Recurso.h"
#include "Herramienta.h"

class LlaveAcoplamiento : public Recurso {
private:
    int contador;
    int dy;
    int pasoFrames;   // cada cu�ntos frames se mueve (2 r�pido, 3+ m�s lento)

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