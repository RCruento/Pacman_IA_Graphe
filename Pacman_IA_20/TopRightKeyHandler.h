#pragma once

#include "GuiHandler.h"

/*
@brief: classe qui permet de deplacer vers le haut-droite touche 9 du pavé numerique
*/

class TopRightKeyHandler : public GuiHandler
{
protected:
	bool canHandle(const string & actionName) const;
	void execute(ParametersHolder *ph) const;
public:
	TopRightKeyHandler(GuiHandler * next);
};

