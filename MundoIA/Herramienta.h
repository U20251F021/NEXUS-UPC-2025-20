#pragma once
#include "pch.h"
#include <string>  

using namespace std;
class Herramienta
{
public:
    void ventana(int x, int y);

    void asignarcolor(int color);

    void ubicar(int x, int y);

    void dialogo(int x, int x2, int y, int y2, string dialogo, int color);
    void borrarDialogo(int x, int x2, int y, int y2, string dialogo);

};

