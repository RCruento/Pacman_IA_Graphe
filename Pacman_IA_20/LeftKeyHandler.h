#pragma once

#include "GuiHandler.h"


/*
@brief: classe qui permet de deplacer vers la gauche touche 4 du pavé numerique
*/

class LeftKeyHandler : public GuiHandler
{
protected:
	bool canHandle(const string & actionName) const;
	void execute(ParametersHolder *ph) const;
public:
	LeftKeyHandler(GuiHandler * next);


};

