#pragma once

#include "GuiHandler.h"

/*
@breif: classe qui permet de deplacer vers le bas touche 2 du pavé numerique
*/
class BottomKeyHandler : public GuiHandler
{
protected:
	bool canHandle(const string & actionName) const;
	void execute(ParametersHolder *ph) const;
public:
	BottomKeyHandler(GuiHandler * next);
};