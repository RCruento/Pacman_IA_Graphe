#pragma once
#include "GuiHandler.h"


/*
@brief: classe qui represente le nv trois du jeu ou les fantomes chassent pacman a l'aide de l'algo A* donné
*/
class DeplacementFantomeNiveau3 : public GuiHandler
{
protected:
	bool canHandle(const string & actionName) const;
	void execute(ParametersHolder *ph) const;
public:
	DeplacementFantomeNiveau3(GuiHandler * next) :GuiHandler(next) {}
};

