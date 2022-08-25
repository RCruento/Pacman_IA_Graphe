#pragma once
#include "GuiHandler.h"
#include "GameWorld.h"

/*
@brief: classe du nv deux du jeu ou les fantomes chasse pacman quand ils le voient ou se deplacent vers lui au "flair"
*/

class DeplacementFantomeNiveau2 : public GuiHandler
{
protected:
	bool canHandle(const string & actionName) const;
	void execute(ParametersHolder *ph) const;

public:
	DeplacementFantomeNiveau2(GuiHandler * next) :GuiHandler(next) {}


};
