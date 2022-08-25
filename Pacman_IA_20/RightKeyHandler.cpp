#include "RightKeyHandler.h"




RightKeyHandler::RightKeyHandler(GuiHandler * next) : GuiHandler(next)
{
}

bool RightKeyHandler::canHandle(const string & actionName) const
{
	return actionName == to_string(sf::Keyboard::Numpad6);
}

void RightKeyHandler::execute(ParametersHolder * ph) const
{
	auto gw = GameWorld::getInstance();

	int col = gw->pacM->currentPosition->v.vSommet.p.x;
	int ligne = gw->pacM->currentPosition->v.vSommet.p.y;

	if (col < gw->NB_COLUMNS - 1)
		gw->pacM->currentPosition = gw->sommet[ligne][col + 1];
}
