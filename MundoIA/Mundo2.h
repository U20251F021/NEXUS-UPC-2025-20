#pragma once
#include "pch.h"
#include "Mundo.h"
#include "Herramienta.h"
#include <iostream>

class Mundo2 : public Mundo {
private:
    // Punto de inicio del arte del fondo (aj�stalo si deseas)
    int fx = 3, fy = 2;

public:
    Mundo2() {}
    ~Mundo2() {}

    void dibujarFondo() override;

    // Villano (due�o de la nave)
    void dibujarVillano(int x, int y);
    void borrarVillano(int x, int y);
};
