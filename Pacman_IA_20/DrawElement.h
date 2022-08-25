#pragma once
#include "GameElement.h"
#include "Graphe\Vecteur2D.h"
#include "Graphe\InfoSommet.h"

/*!
	\class Classe principale pour dessiner les models utilisés
*/

class DrawElement
{
	static DrawElement *dw;
public:
	virtual void draw(GameElement<InfoSommet> *ge) const = 0;
	virtual  void draw(string textureName, Vecteur2D position)  const = 0;
};
