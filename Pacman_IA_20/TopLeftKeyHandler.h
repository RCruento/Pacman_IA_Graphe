#pragma once

#include "GuiHandler.h"

/*
@brief: classe qui permet de deplacer vers le haut-gauche touche 7 du pavé numerique
*/

class TopLeftKeyHandler : public GuiHandler
{
protected:
	bool canHandle(const string & actionName) const;
	void execute(ParametersHolder *ph) const;
public:
	TopLeftKeyHandler(GuiHandler * next);
};