#pragma once
#include "GuiHandler.h"

/*
@breif: classe qui permet de deplacer vers la gauche-bas touche 1 du pavé numerique
 */
class BottomLeftKeyHandler : public GuiHandler
{

protected:
	bool canHandle(const string & actionName) const;
	void execute(ParametersHolder *ph) const;

public:

	BottomLeftKeyHandler(GuiHandler * next);

};
