#include "pch.h"
#include "Mundo2.h"
using namespace std;

// Mundo2.cpp

void Mundo2::dibujarFondo() {
    Herramienta h;
    h.asignarcolor(7); // gris claro para el fondo

    h.ubicar(0, 0);  cout << "           .            .                     .         +           .  ";
    h.ubicar(0, 1);  cout << "                     _        .                          .            (";
    h.ubicar(0, 2);  cout << "                    (_)        .       .                      +              .";
    h.ubicar(0, 3);  cout << "     .        ____.--^.";
    h.ubicar(0, 4);  cout << "      .      /:  /    |                               +           .         .";
    h.ubicar(0, 5);  cout << "            /:  `--=--'   .                                                .";
    h.ubicar(0, 6);  cout << "  LS       /: __[\\==`-.___          *           .";
    h.ubicar(0, 7);  cout << "          /__|\\ _~~~~~~   ~~--..__            .             .";
    h.ubicar(0, 8);  cout << "          \\   \\|::::|-----.....___|~--.                                 .";
    h.ubicar(0, 9);  cout << "           \\ _\\_~~~~~-----:|:::______//---...___";
    h.ubicar(0, 10);  cout << "       .   [\\  \\  __  --     \\       ~  \\_      ~~~===------==-...____";
    h.ubicar(0, 11);  cout << "           [============================================================-";
    h.ubicar(0, 12);  cout << "           /         __/__   --  /__    --       /____....----''''~~~~      .";
    h.ubicar(0, 13);  cout << "     *    /  /   ==           ____....=---='''~~~~ .";
    h.ubicar(0, 14);  cout << "         /____....--=-''':~~~~                      .                .";
    h.ubicar(0, 15);  cout << "         .       ~--~         Kuat Drive Yard's Imperial-class Star Destroyer";
    h.ubicar(0, 16);  cout << "                        .                                   .           .";
    h.ubicar(0, 17);  cout << "                             .                      .             +";
    h.ubicar(0, 18);  cout << "           .     +              .                                       <=>";
    h.ubicar(0, 19);  cout << "                                                      .                .      .";


    int sx = 80, sy = 0;     // <-- ajusta sy si deseas otra altura
    h.asignarcolor(15);

    h.ubicar(sx, sy + 0); cout << "                                                ____________   +       +    ";
    h.ubicar(sx, sy + 1); cout << "    .            .        +     --)-----------|____________|     .     .    ";
    h.ubicar(sx, sy + 2); cout << "        .                                     ,'       ,'                   ";
    h.ubicar(sx, sy + 3); cout << "   +            -)------========       .    ,'  ____ ,'      +              ";
    h.ubicar(sx, sy + 4); cout << "                         `.    `.         ,'  ,'__ ,'           .           ";
    h.ubicar(sx, sy + 5); cout << "   +     .                 `.    `.     ,'       ,'    .                    ";
    h.ubicar(sx, sy + 6); cout << "               +     .       `.    `._,'_______,'__                         ";
    h.ubicar(sx, sy + 7); cout << "                               [._ _| ^--      || |            .     +      ";
    h.ubicar(sx, sy + 8); cout << "      .                ____,...-----|__________ll_|\\                         ";
    h.ubicar(sx, sy + 9); cout << "      ,.,..-------\"\"\"\"\"     \"----'                 ||            +      ";
    h.ubicar(sx, sy + 10); cout << "  .-\"\"  |=========================== ______________ |   +     .            ";
    h.ubicar(sx, sy + 11); cout << "   \"-...l_______________________    |  |'      || |_]                       ";
    h.ubicar(sx, sy + 12); cout << "                                [`-.|__________ll_|      Incom's T-65B X-wing";
    h.ubicar(sx, sy + 13); cout << "                      +       ,'    ,' `.        `.      Space Superiority   ";
    h.ubicar(sx, sy + 14); cout << "     +                      ,'    ,'     `.    ____`.    Starfighter (2)     ";
    h.ubicar(sx, sy + 15); cout << "        .       -)---------========   .    `.  `.____`.                      ";
    h.ubicar(sx, sy + 16); cout << "                           +                 `.        `.    .    +    .     ";
    h.ubicar(sx, sy + 17); cout << "    By Unknown                              .  `.________`.      .           ";
    h.ubicar(sx, sy + 18); cout << "    Patched by LS     .        --)-------------|___________|            .    ";

}

void Mundo2::dibujarVillano(int x, int y) {
    Herramienta h;
    h.asignarcolor(12); // blanco

    h.ubicar(x, y + 0); cout << "           _.-'~~~~~~`-._";
    h.ubicar(x, y + 1); cout << "          /      ||      \\";
    h.ubicar(x, y + 2); cout << "         /       ||       \\";
    h.ubicar(x, y + 3); cout << "        |        ||        |";
    h.ubicar(x, y + 4); cout << "        | _______||_______ |";
    h.ubicar(x, y + 5); cout << "        |/ ----- \\/ ----- \\|";
    h.ubicar(x, y + 6); cout << "       /  (     )  (     )  \\";
    h.ubicar(x, y + 7); cout << "      / \\  ----- () -----  / \\";
    h.ubicar(x, y + 8); cout << "     /   \\      /||\\      /   \\";
    h.ubicar(x, y + 9); cout << "    /     \\    /||||\\    /     \\";
    h.ubicar(x, y + 10); cout << "   /       \\  /||||||\\  /       \\";
    h.ubicar(x, y + 11); cout << "  /_        \\o========o/        _\\";
    h.ubicar(x, y + 12); cout << "    `--...__|`-._  _.-'|__...--'";
    h.ubicar(x, y + 13); cout << "            |    `'    |             -U";
}

void Mundo2::borrarVillano(int x, int y) {
    Herramienta h;
    h.ubicar(x, y + 0);  std::cout << "                                        ";
    h.ubicar(x, y + 1);  std::cout << "                                        ";
    h.ubicar(x, y + 2);  std::cout << "                                        ";
    h.ubicar(x, y + 3);  std::cout << "                                        ";
    h.ubicar(x, y + 4);  std::cout << "                                        ";
    h.ubicar(x, y + 5);  std::cout << "                                        ";
    h.ubicar(x, y + 6);  std::cout << "                                        ";
    h.ubicar(x, y + 7);  std::cout << "                                        ";
    h.ubicar(x, y + 8);  std::cout << "                                        ";
    h.ubicar(x, y + 9);  std::cout << "                                        ";
    h.ubicar(x, y + 10);  std::cout << "                                        ";
    h.ubicar(x, y + 11);  std::cout << "                                        ";
    h.ubicar(x, y + 12);  std::cout << "                                        ";
    h.ubicar(x, y + 13);  std::cout << "                                        ";
}
