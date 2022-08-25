#pragma once
#include "DrawElement.h"


class DrawWithSFML : public DrawElement
{
public:
	void draw(GameElement<InfoSommet> *ge)const;
	void draw(string textureName, Vecteur2D position) const;
};

