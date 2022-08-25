#include "LeftKeyHandler.h"




LeftKeyHandler::LeftKeyHandler(GuiHandler * next) : GuiHandler(next)
{
}

bool LeftKeyHandler::canHandle(const string & actionName) const
{
	return actionName == to_string(sf::Keyboard::Numpad4);
}

void LeftKeyHandler::execute(ParametersHolder * ph) const
{
	auto gw = GameWorld::getInstance();

	int col = gw->pacM->currentPosition->v.vSommet.p.x;
	int ligne = gw->pacM->currentPosition->v.vSommet.p.y;

	if (col > 0)
		gw->pacM->currentPosition = gw->sommet[ligne][col - 1];
}
