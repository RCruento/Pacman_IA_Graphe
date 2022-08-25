
#include "TopLeftKeyHandler.h"



TopLeftKeyHandler::TopLeftKeyHandler(GuiHandler * next) : GuiHandler(next)
{
}

bool TopLeftKeyHandler::canHandle(const string & actionName) const
{
	return actionName == to_string(sf::Keyboard::Numpad7);
}

void TopLeftKeyHandler::execute(ParametersHolder * ph) const
{
	auto gw = GameWorld::getInstance();

	int col = gw->pacM->currentPosition->v.vSommet.p.x;
	int ligne = gw->pacM->currentPosition->v.vSommet.p.y;

	if (col > 0 && ligne <= gw->NB_LINES - 2)
	{
		if (gw->g.getAreteParSommets(gw->pacM->currentPosition, gw->sommet[ligne + 1][col - 1]) != NULL) // verfier si il ya une arette entre la position actuelle est la position ou en veux allez
			gw->pacM->currentPosition = gw->sommet[ligne + 1][col - 1];
	}
}
