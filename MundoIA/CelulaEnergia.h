//.h

#pragma once
#include "pch.h"
#include "Recurso.h"
#include "Herramienta.h"

class CelulaEnergia : public Recurso {
private:
    int contador;     // controla la velocidad de caída
    int dy;           // delta Y por movimiento
    int pasoFrames;   // se mueve cada 'pasoFrames' frames (2 rápido, 3 medio, 4 lento)


public:
    CelulaEnergia();
    CelulaEnergia(int px, int py);
    virtual ~CelulaEnergia() {}

    void dibujar() override;
    void borrar()  override;
    void mover()   override;
    void generarPosAleatoria() override;
    void aplicarEfectoAlJugador(Jugador& jugador) override;


    void setPasoFrames(int n) { pasoFrames = (n < 1 ? 1 : n); }
    int  colorDeCelda(int fila, int  col) override { return 9; } // azul (si usas el modo por celdas)



};