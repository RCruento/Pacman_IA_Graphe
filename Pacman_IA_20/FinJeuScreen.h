#pragma once
#include "Screen.h"
#include "DrawWithSFML.h"

/*
 @brief: classe d'ecran de fin de jeu
*/
class FinJeuScreen : public Screen
{
public:

	FinJeuScreen();
	void render(MyWindow *);
	DrawWithSFML sfDraw;
	Text txtGameState;
	Text information;
};

