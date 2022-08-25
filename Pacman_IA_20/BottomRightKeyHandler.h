#pragma once

#include "GuiHandler.h"


/*
@breif: classe qui permet de deplacer vers la bas-droite touche 3 du pav� numerique
 */
class BottomRightKeyHandler : public GuiHandler
{
protected:
	bool canHandle(const string & actionName) const;
	void execute(ParametersHolder *ph) const;
public:
	BottomRightKeyHandler(GuiHandler * next);
};

