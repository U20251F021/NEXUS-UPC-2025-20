#pragma once
#include "pch.h"
#include "Aliado.h"
#include "Herramienta.h"
#include <conio.h>  
static const int JEFE_ANCHO = 32; // ajusta al ancho real de tu ASCII
static const int JEFE_ALTO = 9;  // 9 líneas
class JefeDeHangar : public Aliado {
private:
    bool llave_autorizada;
    int  colorPrincipal;

    int msgX, msgY, msgW, msgH;



    // Utilidades internas para diálogo
    void mostrarDialogo(string& texto, int color);
    void borrarDialogoArea();
    int  leerOpcion123();

public:
    JefeDeHangar();
    JefeDeHangar(int px, int py, int color = 10);
    virtual ~JefeDeHangar() {}

    void setAreaMensaje(int x, int y, int ancho, int alto = 6) {
        msgX = x; msgY = y; msgW = ancho; msgH = alto;
    }

    void dibujar() override;
    void borrar()  override;

    void aplicarEfectoAlJugador(Jugador& j) override;
    int  colorDeCelda(int  fila, int  col) override { return colorPrincipal; }


    bool llaveAutorizada() { return llave_autorizada; }
    void resetValidacion() { llave_autorizada = false; }
};