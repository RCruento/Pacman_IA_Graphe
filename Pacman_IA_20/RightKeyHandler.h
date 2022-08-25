#pragma once

#include "GuiHandler.h"

/*
@breif: classe qui permet de deplacer vers la droite touche 6 du pavé numerique
*/


class RightKeyHandler : public GuiHandler
{
protected:
	bool canHandle(const string & actionName) const;
	void execute(ParametersHolder *ph) const;
public:
	RightKeyHandler(GuiHandler * next);


};

