#include "BottomKeyHandler.h"
#include <windows.h>



BottomKeyHandler::BottomKeyHandler(GuiHandler * next) : GuiHandler(next)
{
}

bool BottomKeyHandler::canHandle(const string & actionName) const
{
	return actionName == to_string(sf::Keyboard::Numpad2);
}
void BottomKeyHandler::execute(ParametersHolder * ph) const
{
	auto gw = GameWorld::getInstance();

	int col = gw->pacM->currentPosition->v.vSommet.p.x;
	int ligne = gw->pacM->currentPosition->v.vSommet.p.y;

	if (ligne > 0)
		gw->pacM->currentPosition = gw->sommet[ligne - 1][col];

}
