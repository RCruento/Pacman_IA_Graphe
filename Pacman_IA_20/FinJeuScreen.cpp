#include "FinJeuScreen.h"
#include "configs.h"

configs *confi;


FinJeuScreen::FinJeuScreen()
{
	txtGameState.setFont(MyWindow::getInstance()->font2);
	txtGameState.setFillColor(sf::Color::Red);
	txtGameState.setCharacterSize(37);
	txtGameState.setPosition(390, 350);

	information = Text(txtGameState);
	information.setPosition(280, 480);
	information.setFont(MyWindow::getInstance()->font2);
	information.setFillColor(sf::Color::Black);
	information.setCharacterSize(19);

	information.setString("Appuyez sur la touche entrée pour commencer à joeur");



}

void FinJeuScreen::render(MyWindow *win)
{
	confi = configs::getInstance();

	if (confi->gameOver) {
		txtGameState.setPosition(390, 350);
		txtGameState.setFillColor(sf::Color::Red);
		txtGameState.setString("YOU DIED !!!");
	}
	else
	{
		txtGameState.setPosition(300, 350);
		txtGameState.setFillColor(sf::Color::Yellow);
		txtGameState.setString(sf::String("VOUS AVEZ GAGNE !"));
	}


	sfDraw.draw("pacmanlogo", Vecteur2D(300, 50));

	win->getWindow()->fenetre.draw(information);
	win->getWindow()->fenetre.draw(txtGameState);
}
