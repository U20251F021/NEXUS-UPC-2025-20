#include "pch.h"
#include "Herramienta.h"
#include "iostream"
using namespace System;
using namespace std;

void Herramienta::ventana(int x, int y) {
    Console::SetWindowSize(x,y);
}

void Herramienta::asignarcolor(int color) {
    switch (color)
    {
    case 0: Console::ForegroundColor = ConsoleColor::Black; break;
    case 1: Console::ForegroundColor = ConsoleColor::Blue; break;
    case 2: Console::ForegroundColor = ConsoleColor::Green; break;
    case 3: Console::ForegroundColor = ConsoleColor::Cyan; break;
    case 4: Console::ForegroundColor= ConsoleColor::Red; break;
    case 5: Console::ForegroundColor = ConsoleColor::Magenta; break;
    case 6: Console::ForegroundColor = ConsoleColor::Yellow; break;
    case 7: Console::ForegroundColor = ConsoleColor::White; break;
    case 8: Console::ForegroundColor = ConsoleColor::Gray; break;
    case 9: Console::ForegroundColor = ConsoleColor::DarkBlue; break;
    case 10: Console::ForegroundColor = ConsoleColor::DarkGreen; break;
    case 11: Console::ForegroundColor = ConsoleColor::DarkCyan; break;
    case 12: Console::ForegroundColor = ConsoleColor::DarkRed; break;
    case 13: Console::ForegroundColor = ConsoleColor::DarkMagenta; break;
    case 14: Console::ForegroundColor = ConsoleColor::DarkYellow; break;
    case 15: Console::ForegroundColor = ConsoleColor::DarkGray; break;

    default: Console::ForegroundColor = ConsoleColor::Blue; break;

    }

}

void Herramienta::ubicar(int x, int y) {
    Console::SetCursorPosition(x, y);
}

void Herramienta::dialogo(int x, int x2, int y, int y2, string dialogo, int color) {
    Herramienta h;
    int ancho = x2 - x;
    int alto = y2 - y;

    for (int j = 0; j < alto; j++) {
        for (int i = 0; i < ancho; i++) {
            int pos = i + (j * ancho);
            if (pos < dialogo.size()) {
                h.asignarcolor(color);
                h.ubicar(x + i, y + j);
                cout << dialogo[pos];
            }
            else {
                h.asignarcolor(7);
                h.ubicar(x + i, y + j);
                cout << " ";
            }
        }
    }
}

void Herramienta::borrarDialogo(int x, int x2, int y, int y2, string dialogo) {
    Herramienta h;
    int ancho = x2 - x;
    int alto = y2 - y;

    for (int j = 0; j < alto; j++) {
        for (int i = 0; i < ancho; i++) {
            int pos = i + (j * ancho);
            if (pos < dialogo.size()) {
                h.asignarcolor(7);
                h.ubicar(x + i, y + j);
                cout << " ";
            }
            else {
                h.asignarcolor(7);
                h.ubicar(x + i, y + j);
                cout << " ";
            }
        }
    }
}