#include "GuiHandler.h"
#include "exGuiHandler.h"

GuiHandler::GuiHandler(GuiHandler * next) : next(next)
{
}

void GuiHandler::HandleRequest(const string& actionName, ParametersHolder * ph) const
{

	if (canHandle(actionName))
		execute(ph);
	else
		if (next != nullptr) next->HandleRequest(actionName, ph);
}


