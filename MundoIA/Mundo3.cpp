// Adr
#include "pch.h"
#include "iostream"
#include "Mundo3.h"


Mundo3::Mundo3() {

}
Mundo3::~Mundo3() {

}

void Mundo3::dibujarFondo() {
	Herramienta herramienta;
	for (int f = 0; f < 20; ++f) {
		for (int c = 0; c < 200; ++c) {

			herramienta.asignarcolor(matrizColab[f][c]);
			herramienta.ubicar(c, f);
			cout << char(219);
		}
	}
}



void Mundo3::dibujarContornos(int x1, int x2, int y1, int y2) {
	Herramienta h;
	if (x1 < 0 || x2>260 || y1 < 0 || y2>60) { cout << "Fuera de rango" << endl; return; }
	for (int i = 0; i < x2 - x1; i++) {
		h.asignarcolor(15); h.ubicar(x1 + i - 1, y1 - 1); cout << char(219);
		h.asignarcolor(15); h.ubicar(x1 + i - 1, y2 - 1); cout << char(219);
	}
	for (int i = 0; i < y2 - y1; i++) {
		h.asignarcolor(15); h.ubicar(x1 - 1, y1 + i - 1); cout << char(219);
		h.asignarcolor(15); h.ubicar(x2 - 1, y1 + i - 1); cout << char(219);
	}
}
void Mundo3::dibujarGuiaPersonaje(int x, int y) {
	Herramienta h;
	h.asignarcolor(7);
	h.ubicar(x, y);     cout << "   _____   ";
	h.ubicar(x, y + 1); cout << "  / °°  \\ ";
	h.ubicar(x, y + 2); cout << " | °|||° | ";
	h.ubicar(x, y + 3); cout << " |_______| ";
	h.ubicar(x, y + 4); cout << "   \\\\//  ";
	h.ubicar(x, y + 5); cout << " |--------|";
	h.ubicar(x, y + 6); cout << " |__    __|";
	h.ubicar(x, y + 7); cout << " | |    | |";
	h.ubicar(x, y + 8); cout << " | |    | |";
	h.ubicar(x, y + 9); cout << " | |    | |";
	h.ubicar(x, y + 10); cout << "  |____| | ";
	h.ubicar(x, y + 11); cout << "  / ---\\  ";
	h.ubicar(x, y + 12); cout << " | | | | | ";
	h.ubicar(x, y + 13); cout << " | | | | | ";

}


void Mundo3::borrarGuiaPersonaje(int x, int y) {
	Herramienta h;
	h.asignarcolor(0);
	h.ubicar(x, y);     cout << "            ";
	h.ubicar(x, y + 1); cout << "            ";
	h.ubicar(x, y + 2); cout << "            ";
	h.ubicar(x, y + 3); cout << "            ";
	h.ubicar(x, y + 4); cout << "            ";
	h.ubicar(x, y + 5); cout << "            ";
	h.ubicar(x, y + 6); cout << "            ";
	h.ubicar(x, y + 7); cout << "            ";
	h.ubicar(x, y + 8); cout << "            ";
	h.ubicar(x, y + 9); cout << "            ";
	h.ubicar(x, y + 10); cout << "            ";
	h.ubicar(x, y + 11); cout << "            ";
	h.ubicar(x, y + 12); cout << "            ";
	h.ubicar(x, y + 13); cout << "            ";

}


void Mundo3::dibujarGuia() {
	Herramienta h;
	h.asignarcolor(6);

	h.ubicar(210, 34); cout << "-----=-=*+-#*#-#*#+##*+##+-**----  ";
	h.ubicar(210, 35); cout << "-=+-#*##++##=*#*=+#==##=+##+#*##-  ";
	h.ubicar(210, 36); cout << "=#+*#-=*+=================+==#*+#- ";
	h.ubicar(210, 37); cout << "-#*-===========================*#- ";
	h.ubicar(210, 38); cout << "-=*-===========================**- ";
	h.ubicar(210, 39); cout << "--#--==========================*+- ";
	h.ubicar(210, 40); cout << "--#=-==========================#=- ";
	h.ubicar(210, 41); cout << "--#+-==========================#-- ";
	h.ubicar(210, 42); cout << "--#*-=========================+#-- ";
	h.ubicar(210, 43); cout << "--**-==========================+#--";
	h.ubicar(210, 44); cout << "--##=-========================##-- ";
	h.ubicar(210, 45); cout << "-+*-==*+=-==*=======++===+*+==*+-  ";
	h.ubicar(210, 46); cout << "-=#=*---------*===*---------+=#+-  ";
	h.ubicar(210, 47); cout << " --=#-----------*=+-----------+#-- ";
	h.ubicar(210, 48); cout << "--*+----#*-----+=+-----+#=---=#--  ";
	h.ubicar(210, 49); cout << "--+*----------=+==*----------#+--  ";
	h.ubicar(210, 50); cout << "--=#*--------*======-------=*##*-  ";
	h.ubicar(210, 51); cout << "-#+=+=*=---=**=======*+++*===+=**  ";
	h.ubicar(210, 52); cout << "=#=+===========+**+===========++** ";
	h.ubicar(210, 53); cout << "-*#=#====t================t===++#= ";
	h.ubicar(210, 54); cout << "---+#===tt===============t=t=*#*-- ";
	h.ubicar(210, 55); cout << "----#==t==ttttttttttttttt===t*#--- ";
	h.ubicar(210, 56); cout << "----*#=++++=============++*==#=--- ";
	h.ubicar(210, 57); cout << "------#*===================*#----  ";
	h.ubicar(210, 58); cout << "--------+#*==============**------- ";


}
void Mundo3::borrarGuia() {
	Herramienta h;
	h.asignarcolor(0);
	h.ubicar(210, 34); cout << "                                   ";
	h.ubicar(210, 35); cout << "                                   ";
	h.ubicar(210, 36); cout << "                                   ";
	h.ubicar(210, 37); cout << "                                   ";
	h.ubicar(210, 38); cout << "                                   ";
	h.ubicar(210, 39); cout << "                                   ";
	h.ubicar(210, 40); cout << "                                   ";
	h.ubicar(210, 41); cout << "                                   ";
	h.ubicar(210, 42); cout << "                                   ";
	h.ubicar(210, 43); cout << "                                   ";
	h.ubicar(210, 44); cout << "                                   ";
	h.ubicar(210, 45); cout << "                                   ";
	h.ubicar(210, 46); cout << "                                   ";
	h.ubicar(210, 47); cout << "                                   ";
	h.ubicar(210, 48); cout << "                                   ";
	h.ubicar(210, 49); cout << "                                   ";
	h.ubicar(210, 50); cout << "                                   ";
	h.ubicar(210, 51); cout << "                                   ";
	h.ubicar(210, 52); cout << "                                   ";
	h.ubicar(210, 53); cout << "                                   ";
	h.ubicar(210, 54); cout << "                                   ";
	h.ubicar(210, 55); cout << "                                   ";
	h.ubicar(210, 56); cout << "                                   ";
	h.ubicar(210, 57); cout << "                                   ";
	h.ubicar(210, 58); cout << "                                   ";
}

