#pragma once
#include "Screen.h"


/*
@brief: classe representant l'ecran principal du jeu
*/
class GameScreen : public Screen
{
public:
	void render(MyWindow *);
	GameScreen();
};