#include "TopKeyHandler.h"




TopKeyHandler::TopKeyHandler(GuiHandler * next) : GuiHandler(next)
{
}

bool TopKeyHandler::canHandle(const string & actionName) const
{
	return actionName == to_string(sf::Keyboard::Numpad8);
}

void TopKeyHandler::execute(ParametersHolder * ph) const
{
	auto gw = GameWorld::getInstance();
	int col = gw->pacM->currentPosition->v.vSommet.p.x;
	int ligne = gw->pacM->currentPosition->v.vSommet.p.y;

	if (ligne < gw->NB_LINES - 1)
		gw->pacM->currentPosition = gw->sommet[ligne + 1][col];
}
