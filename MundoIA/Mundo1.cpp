#include "pch.h"
#include "iostream"
#include "Mundo1.h"

Mundo1::Mundo1() {

}
Mundo1::~Mundo1() {

}

void Mundo1::dibujarFondo() {
	Herramienta herramienta;
	for (int f = 0; f < 20; ++f) {
		for (int c = 0; c < 200; ++c) {
	
			herramienta.asignarcolor(matrizIA[f][c]);
			herramienta.ubicar(c, f);
			cout << char(219);
		}
	}
}



void Mundo1::dibujarIA() {
	Herramienta h;
	h.asignarcolor(2);
	h.ubicar(210,34);cout<<"										";
	h.ubicar(210,35);cout<<"	          .andAHHAbnn.			    ";
	h.ubicar(210,36);cout<<"           .aAHHHAAUUAAHHHAn.			";
	h.ubicar(210,37);cout<<"          dHP^~'        '~^THb.		    ";
	h.ubicar(210,38);cout<<"    .   .AHF                YHA.   .	";
	h.ubicar(210,39);cout<<"    |  .AHHb.              .dHHA.  |	";
	h.ubicar(210,40);cout<<"    |  HHAUAAHAbn      adAHAAUAHA  |	";
	h.ubicar(210,41);cout<<"    I  HF~'_____        ____ ]HHH  I	";
	h.ubicar(210,42);cout<<"   HHI HAPK''~^YUHb  dAHHHHHHHHHH IHH	";
	h.ubicar(210,43);cout<<"   HHI HHHD> .andHH  HHUUP^~YHHHH IHH	";
	h.ubicar(210,44);cout<<"   YUI ]HHP     '~Y  P~'     THH[ IUP	";
	h.ubicar(210,45);cout<<"    '  `HK                   ]HH'  '	";
	h.ubicar(210,46);cout<<"        THAn.  .d.aAAn.b.  .dHHP		";
	h.ubicar(210,47);cout<<"        ]HHHHAAUP' ~~ 'YUAAHHHH[		";
	h.ubicar(210,48);cout<<"        `HHP^~'  .annn.  '~^YHH'		";
	h.ubicar(210,49);cout<<"         YHb    ~' '' '~    dHF		    ";
	h.ubicar(210,50);cout<<"          'YAb..abdHHbndbndAP'			";
	h.ubicar(210,51);cout<<"           THHAAb.  .adAHHF			    ";
	h.ubicar(210,52);cout<<"            'UHHHHHHHHHHU'				";
	h.ubicar(210,53);cout<<"              ]HHUUHHHHHH[				";
	h.ubicar(210,54);cout<<"            .adHHb 'HHHHHbn.			";
	h.ubicar(210,55);cout<<"     ..andAAHHHHHHb.AHHHHHHHAAbnn..	    ";
	h.ubicar(210,56);cout<<".ndAAHHHHHHUUHHHHHHHHHHUP^~'~^YUHHHAAbn.";
	h.ubicar(210,57);cout<<"  '~^YUHHP'   '~^YUHHUP'        '^YUP^' ";
	h.ubicar(210,58);cout<<"       ''         '~~'					";

	
}
void Mundo1::borrarIA() {

}

void Mundo1::dibujarIAcuerpo(int x, int y) {
	Herramienta h;
	h.asignarcolor(2);
	h.ubicar(x,y);   cout<<"    ____	 ";
    h.ubicar(x,y+1); cout<<"   [    ]	 ";
    h.ubicar(x,y+2); cout<<"   ]()()[ 	 ";
    h.ubicar(x,y+3); cout<<" ___\\__/___ ";
    h.ubicar(x,y+4); cout<<"|__|    |__| ";
    h.ubicar(x,y+5); cout<<" |_|_/\\_|_| ";
    h.ubicar(x,y+6); cout<<" | | __ | |  ";
    h.ubicar(x,y+7); cout<<" |_|[::]|_|  ";
    h.ubicar(x,y+8); cout<<" \\_|_||_|_/ ";
    h.ubicar(x,y+9); cout<<"   |_||_|    ";
	h.ubicar(x,y+10);cout<<"   |_||_|    ";
	h.ubicar(x,y+11);cout<<"   |_||_|    ";
	h.ubicar(x,y+12);cout<<"   |_||_|    ";
    h.ubicar(x,y+13);cout<<" |___||___|  ";
	
}

void Mundo1::borrarIAcuerpo(int x, int y) {
	Herramienta h;
	h.asignarcolor(3);
	h.ubicar(x, y);   cout   <<  "            ";
	h.ubicar(x, y + 1); cout <<  "            ";
	h.ubicar(x, y + 2); cout <<  "            ";
	h.ubicar(x, y + 3); cout <<  "            ";
	h.ubicar(x, y + 4); cout <<  "            ";
	h.ubicar(x, y + 5); cout <<  "            ";
	h.ubicar(x, y + 6); cout <<  "            ";
	h.ubicar(x, y + 7); cout <<  "            ";
	h.ubicar(x, y + 8); cout <<  "            ";
	h.ubicar(x, y + 9); cout <<  "            ";
	h.ubicar(x, y + 10); cout<<  "            ";
	h.ubicar(x, y + 11); cout<<  "            ";
	h.ubicar(x, y + 12); cout << "            ";
	h.ubicar(x, y + 13); cout << "            ";

}