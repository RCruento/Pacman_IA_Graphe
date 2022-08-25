#include "MainController.h"
#include "configs.h"
#include "GameWorld.h"


configs *cof;
GameWorld *gWorld;

MainController::MainController()
{
	gameSC = new GameScreen();
	niveauSC = new NiveauScreen();
	finJeuSC = new FinJeuScreen();
	actualScreen = niveauSC;
	cof = configs::getInstance();
	gWorld = GameWorld::getInstance();
}


void MainController::render(MyWindow * win)
{
	if (GameWorld::getInstance()->verifierSiLeNiveauEstChanger()) {
		actualScreen = niveauSC;
		cof->gameIsRuning = false; // aretter le jeux quand le paneaux qui indique le nouveau niveau s'affiche
	}

	if (cof->gameOver || cof->winGame) {
		actualScreen = finJeuSC;   // afficher le paneaux de fin de jeux
		cof->gameIsRuning = false;
	}


	if (win->currentRiszedEvent.type == (sf::Event::KeyPressed))
		if (win->currentRiszedEvent.key.code == sf::Keyboard::Enter)
		{
			gWorld->resetGame(); // renitialiser les paramettre du jeux pour la nouvelle partie.
			actualScreen = gameSC;  // l'ecrant actuelle qui va etre afficher
			cof->gameIsRuning = true; // demarer la partie
		}

	actualScreen->render(win);
}