#include "NiveauScreen.h"

#include "Graphe\FenetreGrapheSFML.h"
#include "configs.h"
#include "DrawWithSFML.h"
Text txtLevel;

Text information;

DrawWithSFML sfDraw;

NiveauScreen::NiveauScreen()
{
	txtLevel.setFont(MyWindow::getInstance()->font2);
	txtLevel.setFillColor(sf::Color::Red);
	txtLevel.setCharacterSize(30);
	txtLevel.setPosition(450, 350);

	information = Text(txtLevel);
	information.setFillColor(sf::Color::Red);
	information.setCharacterSize(22);
	information.setPosition(290, 480);
	information.setString("Click sur ENTRER pour demarer la partie");

}

void NiveauScreen::render(MyWindow *win) 
{
	txtLevel.setString("NIVEAU "+ to_string(configs::getInstance()->niveauJeuCourant));

	sfDraw.draw("pacmanlogo", Vecteur2D(300, 50));

	win->getWindow()->fenetre.draw(txtLevel);
	win->getWindow()->fenetre.draw(information);

}
