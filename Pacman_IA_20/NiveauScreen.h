#pragma once
#include "Screen.h"

/*
@brief: classe representant le nv qui doit s'afficher qu'on passe un nv
*/

class NiveauScreen : public Screen
{
public:
	NiveauScreen();
	void render(MyWindow *);
};

