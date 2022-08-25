#include "BottomRightKeyHandler.h"




BottomRightKeyHandler::BottomRightKeyHandler(GuiHandler * next) : GuiHandler(next)
{
}

void BottomRightKeyHandler::execute(ParametersHolder * ph) const
{
	auto gw = GameWorld::getInstance();

	int col = gw->pacM->currentPosition->v.vSommet.p.x;
	int ligne = gw->pacM->currentPosition->v.vSommet.p.y;

	if (col < gw->NB_COLUMNS && ligne <= gw->NB_LINES - 1)
	{
		if (gw->g.getAreteParSommets(gw->pacM->currentPosition, gw->sommet[ligne - 1][col + 1]) != NULL) // verfie si il ya une arette entre la position actuelle est la position ou on veut aller
			gw->pacM->currentPosition = gw->sommet[ligne - 1][col + 1];
	}
}

bool BottomRightKeyHandler::canHandle(const string & actionName) const
{
	return actionName == to_string(sf::Keyboard::Numpad3);
}
