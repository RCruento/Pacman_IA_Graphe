#include "BottomLeftKeyHandler.h"




BottomLeftKeyHandler::BottomLeftKeyHandler(GuiHandler * next) : GuiHandler(next)
{
}

bool BottomLeftKeyHandler::canHandle(const string & actionName) const
{
	return actionName == to_string(sf::Keyboard::Numpad1);
}

void BottomLeftKeyHandler::execute(ParametersHolder * ph) const
{
	auto gw = GameWorld::getInstance();

	int col = gw->pacM->currentPosition->v.vSommet.p.x;
	int ligne = gw->pacM->currentPosition->v.vSommet.p.y;

	if (col > 0 && ligne <= gw->NB_LINES - 1)
	{
		if (gw->g.getAreteParSommets(gw->pacM->currentPosition, gw->sommet[ligne - 1][col - 1]) != NULL) // verfier si il ya une arette entre la position actuelle est la position ou on veut aller
			gw->pacM->currentPosition = gw->sommet[ligne - 1][col - 1];
	}
}