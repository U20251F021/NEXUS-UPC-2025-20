#pragma once
#include "Aliado.h"

class Robot : public Aliado {
private:
   

public:
    Robot();
    Robot(int px, int py, int w, int h);
    
    

    void borrar() override;
    void aplicarEfectoAlJugador(Jugador& j) override;
    int  colorDeCelda(int fila, int col) { return 0; }
    void dibujar() override;
    
    
};
