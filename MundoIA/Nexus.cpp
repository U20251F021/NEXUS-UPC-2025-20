#include "pch.h"
#include "iostream"
#include "conio.h"

#include "Herramienta.h"
#include "Mundo1.h"

#include "Jugador.h"

#include "Recurso.h"
#include "Bomba.h"

#include "Enemigo.h"
#include "Drone.h"
#include "Torreta.h"

#include "Aliado.h"
#include "Robot.h"
#include "JefeDeAngar.h"

#include "Juego.h"


using namespace System;
using namespace std;

void mostrarCreditos() {
    Console::Clear();
    Herramienta h;


    h.asignarcolor(11);
    h.ubicar(96, 6);  cout << "C R E D I T O S";


    h.asignarcolor(8);
    for (int x = 50; x <= 210; ++x) { h.ubicar(x, 8); cout << char(196); }

    h.asignarcolor(7);
    h.ubicar(54, 11); cout << "Universidad  : Universidad Peruana de Ciencias Aplicadas (UPC)";
    h.ubicar(54, 13); cout << "Carrera      : Ciencias de la Computacion";
    h.ubicar(54, 15); cout << "Curso        : Algoritmos y Programacion (1ACC265)";
    h.ubicar(54, 17); cout << "Periodo      : 2025-20";


    h.asignarcolor(14);
    h.ubicar(54, 20); cout << "Profesor/a   : Mendoza Puerta, Henry Antonio";


    h.asignarcolor(10);
    h.ubicar(54, 23); cout << "Autor(es)    :";
    h.asignarcolor(7);
    h.ubicar(70, 25); cout << "- Morales Silva, Gerardo Jesus (U20251E345)";
    h.ubicar(70, 26); cout << "- Ojeda Garcia, Ilder Jesus   (U20251F021)";
    h.ubicar(70, 27); cout << "- Matos Roman, Adriano        (U202517141)";

    h.asignarcolor(8);
    h.ubicar(54, 30); cout << "Motor        : C++ (Consola) + ASCII";
    h.ubicar(54, 32); cout << "Tematica     : IA vs. Pensamiento Critico";

    h.asignarcolor(15);
    h.ubicar(78, 38); cout << "Presiona cualquier tecla para volver al menu...";
    _getch();
    Console::Clear();
}


int main() {
    Console::CursorVisible = false;
    srand((unsigned)time(NULL));

    Herramienta* h = new Herramienta();

    // --- Presentación al iniciar el programa ---
    {
        Juego splash;
        splash.presentacion();
        _getch();
        system("cls");
    }

    bool salir = false;
    do {
        system("cls");
        h->asignarcolor(11);
        h->ubicar(95, 8);  cout << "MENU PRINCIPAL";
        h->asignarcolor(7);
        h->ubicar(85, 12); cout << "1) Iniciar juego";
        h->ubicar(85, 14); cout << "2) Creditos";
        h->ubicar(85, 16); cout << "3) Salir";
        h->ubicar(72, 20); cout << "Selecciona una opcion (1-3) y presiona ENTER...";

        int key = _getch();
        switch (key) {
        case '1': { // === INICIAR JUEGO ===
            system("cls");

            // crea juego y jugador SOLO aquí
            Jugador* jugador = new Jugador(1, 45, 1);
            Juego* juego = new Juego();

            // (si quieres) intro del mundo 1
            juego->instrucciones(1);
            
            
            h->ubicar(60, 20); h->asignarcolor(3);
            cout << "Que harias si, de pronto, la tecnologia en la que confias desapareciera... y tuvieras que pensar por ti mismo?";
            _sleep(2500);
            system("cls");
            
            // ===== NIVEL 1 =====
            juego->nivel1(jugador);
            _sleep(600);
            system("cls");
            
            if (!juego->getEstadoNivel()) {
                juego->perdiste();
                _getch();
                delete juego;
                delete jugador;
                break;
            }
            else {
                juego->ganaste();
                _getch();
                system("cls");
            }
            
            // Puente narrativo
            juego->setEstadoNivel(false);
            h->ubicar(40, 11); h->asignarcolor(2); cout << "IA: Has completado la primera fase. Con estas 5 bombas podriamos terminar la mision."; _sleep(1800);
            h->ubicar(40, 13); cout << "IA: Acabo de recibir un mensaje del hangar... el enemigo tomo el sector."; _sleep(1800);
            h->ubicar(40, 15); h->asignarcolor(3); cout << "Astronauta: Entonces, dame el mando para viajar a otra galaxia."; _sleep(1600);
            h->ubicar(40, 17); h->asignarcolor(2); cout << "IA: ERROR CRITICO DETECTADO... control comprometido. Rumbo fijado a Andromeda."; _sleep(1800);
            
            system("cls");
            // ===== NIVEL 2 =====
            juego->instrucciones(2);  // tu pantalla de intro+instrucciones
            
            system("cls");
            
            juego->nivel2(jugador);
            
            
            if (juego->getEstadoNivel()) {
                juego->ganaste();
                _getch();
                juego->setEstadoNivel(false);
                system("cls");
            
                // Si tienes nivel 3:
                juego->nivel3(jugador);
                system("cls");
                if (juego->getEstadoNivel()) {
                    juego->ganaste();
                    _getch();
                }
                else {
                    juego->perdiste();
                    _getch();
                }
            }

            //juego->nivel3(jugador);

            else {
                juego->ganaste();
            }

            delete juego;
            delete jugador;
            break;
        }

        case '2': { // === CREDITOS ===
            system("cls");
            mostrarCreditos();
            break;
        }

        case '3': // === SALIR ===
            salir = true;
            break;

        default:
            break;
        }
    } while (!salir);

    delete h;
    return 0;
}