#pragma once
#include "GuiHandler.h"



/*
 @brief: classe du premier nv du jeu ou les fantomes se déplacent aléatoirement
*/

class DeplacementFantomeNiveau1 :
	public GuiHandler
{
public:
	/// constructeur de la classe
	DeplacementFantomeNiveau1(GuiHandler * next) :GuiHandler(next) {}

protected:
	bool canHandle(const string & actionName) const;
	void execute(ParametersHolder *ph) const;
};
