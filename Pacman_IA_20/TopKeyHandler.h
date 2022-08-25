#pragma once

#include "GuiHandler.h"


/*
@breif: classe qui permet de deplacer vers le haut touche 8 du pavé numerique
*/

class TopKeyHandler : public GuiHandler
{
protected:
	bool canHandle(const string & actionName) const;
	void execute(ParametersHolder *ph) const;
public:

	TopKeyHandler(GuiHandler * next);

};