#pragma once
#include "Herramienta.h"
#include "iostream"

class Mundo
{
protected:

public:

	Mundo();
	~Mundo();

	virtual void dibujarFondo() = 0;
	void dibujarContornos(int x1, int x2, int y1, int y2);
};

