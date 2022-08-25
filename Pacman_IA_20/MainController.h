#pragma once

#include "MyWindow.h"

#include "Screen.h"
#include "GameScreen.h"
#include "MenuScreen.h"
#include "FinJeuScreen.h"
#include "NiveauScreen.h"


 ///class Controleur generale pour afficher tous les des ecrans

class MainController
{
public:
	Screen *actualScreen;
	GameScreen *gameSC;
	NiveauScreen *niveauSC;
	FinJeuScreen *finJeuSC;
	MainController();
	void render(MyWindow * win);
};