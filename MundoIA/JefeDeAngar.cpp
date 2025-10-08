#include "pch.h"
#include "JefeDeAngar.h"
#include <iostream>
using namespace std;

JefeDeHangar::JefeDeHangar() : Aliado(), llave_autorizada(false), colorPrincipal(10) {
    setTamaño(JEFE_ANCHO, JEFE_ALTO);   
    msgX = 50; msgY = 30; msgW = 60; msgH = 6;
}
JefeDeHangar::JefeDeHangar(int px, int py, int color)
    : Aliado(px, py, JEFE_ANCHO, JEFE_ALTO), llave_autorizada(false), colorPrincipal(color) {
    setTamaño(JEFE_ANCHO, JEFE_ALTO);  
    msgX = 50; msgY = 30; msgW = 90; msgH = 6;
}

void JefeDeHangar::dibujar() {
    Herramienta h;
    h.asignarcolor(colorPrincipal);
     
    h.ubicar(x, y); cout << "       -''--.";
    h.ubicar(x, y + 1); cout << "       _`>   `\.-'<";
    h.ubicar(x, y + 2); cout << "    _.'     _     '._";
    h.ubicar(x, y + 3); cout << "  .'   _.='   '=._   '.";
    h.ubicar(x, y + 4); cout << "  >_   / /_\\ /_\\ \\   _<";
    h.ubicar(x, y + 5); cout << "    / (  \\o/\\\\o/  ) \\ ";
    h.ubicar(x, y + 6); cout << "    >._\\ .-,_)-. /_.<";
    h.ubicar(x, y + 7); cout << "jgs     /__/ \\__\\ ";
    h.ubicar(x, y + 8); cout << "          '---'     E=mc^2";
}

void JefeDeHangar::borrar() {
    Herramienta h;
    h.ubicar(x, y); cout << "                              ";
    h.ubicar(x, y + 1); cout << "                              ";
    h.ubicar(x, y + 2); cout << "                              ";
    h.ubicar(x, y + 3); cout << "                              ";
    h.ubicar(x, y + 4); cout << "                              ";
    h.ubicar(x, y + 5); cout << "                              ";
    h.ubicar(x, y + 6); cout << "                              ";
    h.ubicar(x, y + 7); cout << "                              ";
    h.ubicar(x, y + 8); cout << "                              ";
}


void JefeDeHangar::mostrarDialogo(string& texto, int color) {
    Herramienta h;
    int x1 = msgX;
    int x2 = msgX + msgW;
    int y1 = msgY;
    int y2 = msgY + msgH;  
    h.dialogo(x1, x2, y1, y2, texto, color);

}
void JefeDeHangar::borrarDialogoArea() {
    Herramienta h;
    int x1 = msgX, x2 = msgX + msgW, y1 = msgY, y2 = msgY + msgH;
    h.borrarDialogo(x1, x2, y1, y2, "");
}

int JefeDeHangar::leerOpcion123() {
    while (true) {
        int ch = _getch();
        if (ch == '1') return 1;
        if (ch == '2') return 2;
        if (ch == '3') return 3;
    }
}



void JefeDeHangar::aplicarEfectoAlJugador(Jugador& jugador) {
    int q = 1 + (rand() % 3);

    const char* L0 = ""; 
    const char* L1 = ""; 
    const char* L2 = ""; 
    const char* L3 = ""; 
    const char* L4 = "Elige (1/2/3):";
    int correcta = 2;
    const char* FB1 = "";
    const char* FB2 = "";
    const char* FB3 = "";

    if (q == 1) {
        L0 = "[HANGAR] Falta 1 Celula. Un Caza cae cerca y otra Celula mas lejos.";
        L1 = "1) Intercepto el Caza primero.";
        L2 = "2) Voy directo por la Celula y calculo su caida.";
        L3 = "3) Me quedo en el centro esperando otra ronda.";
        correcta = 2;
        FB1 = "Reducir riesgo sin avanzar objetivo alarga la partida.";
        FB2 = "Criterio correcto. Llave autorizada.";
        FB3 = "Esperar pasivo aumenta la exposicion sin ganar nada.";
    }
    else if (q == 2) {
        L0 = "[HANGAR] Tienes 1 Escudo y 2 vidas; caen un Dron y un Caza casi juntos.";
        L1 = "1) Paso bajo el Dron y guardo el Escudo para el Caza.";
        L2 = "2) Gasto el Escudo en el Dron para no perder el HUD.";
        L3 = "3) Me voy al borde a 'resetear' la oleada.";
        correcta = 1;
        FB1 = "Correcto: reserva el escudo para impacto real.";
        FB2 = "Ineficiente: el HUD apagado no quita vidas.";
        FB3 = "Ir al borde solo te retrasa.";
    }
    else {
        L0 = "[HANGAR] Ya tienes 3 Celulas y estoy a 6 casillas; un Caza cae entre ambos.";
        L1 = "1) Cruzo por la ventana; si me golpea, que consuma el Escudo.";
        L2 = "2) Retrocedo y espero otra oleada.";
        L3 = "3) Busco mas Escudos antes de avanzar.";
        correcta = 1;
        FB1 = "Correcto: con la meta lista, prioriza cerrar.";
        FB2 = "Esperar suma riesgo acumulado.";
        FB3 = "Farm extra no es necesario con recursos limitados.";
    }


    Herramienta h; h.asignarcolor(7);
    int x1 = msgX, x2 = msgX + msgW;
    int y = msgY;
    int salto = 2;

    h.dialogo(x1, x2, y + salto * 0, y + salto * 0 + 1, string(L0), 10); _sleep(70);
    h.dialogo(x1, x2, y + salto * 1, y + salto * 1 + 1, string(L1), 10); _sleep(70);
    h.dialogo(x1, x2, y + salto * 2, y + salto * 2 + 1, string(L2), 10); _sleep(70);
    h.dialogo(x1, x2, y + salto * 3, y + salto * 3 + 1, string(L3), 10); _sleep(70);
    h.dialogo(x1, x2, y + salto * 4, y + salto * 4 + 1, string(L4), 14);

    int op = leerOpcion123();


    h.borrarDialogo(x1, x2, y + salto * 0, y + salto * 4 + 1, "");


    if (op == correcta) {
        llave_autorizada = true;
        const char* OK = (correcta == 1 ? FB1 : (correcta == 2 ? FB2 : FB3));
        h.dialogo(x1, x2, y + salto * 2, y + salto * 2 + 1, std::string(OK), 10);
    }
    else {
        llave_autorizada = false;
        const char* FB = (op == 1 ? FB1 : (op == 2 ? FB2 : FB3));
        h.dialogo(x1, x2, y + salto * 2, y + salto * 2 + 1, std::string(FB), 14);
        jugador.setVidas(jugador.getVidas() - 1);
    }
    _sleep(1400);
    h.borrarDialogo(x1, x2, y + salto * 2, y + salto * 2 + 1, "");
}
