#include "GameScreen.h"
#include "GameWorld.h"
#include "MyWindow.h"
#include "Graphe\FenetreGrapheSFML.h"
#include <SFML/Window/Event.hpp>
#include "DrawWithSFML.h"
#include "TextureFactory.h"
#include "configs.h"
#include "Fantome.h"
GameWorld *gw;
FenetreGrapheSFML *window;
DrawWithSFML sfmlDraw;
configs *cf;

Text scoreTxt;
Text niveauJeu;
Clock ck;

Clock ck_refroidisement;

GameScreen::GameScreen()
{
	gw = GameWorld::getInstance();
	window = MyWindow::getInstance()->getWindow();
	cf = configs::getInstance();
	// init score text
	scoreTxt.setFont(MyWindow::getInstance()->font1);
	scoreTxt.setFillColor(sf::Color::Red);
	scoreTxt.setCharacterSize(24);
	scoreTxt.setPosition(400, 50);

	// init niveau text
	niveauJeu = Text(scoreTxt);
	niveauJeu.setPosition(400, 100);
}


void GameScreen::render(MyWindow *win)
{
	gw->g.dessine(window);

	// mise a jour du score et niveau du jeux
	scoreTxt.setString("Score :   " + to_string(cf->score));
	niveauJeu.setString("Niveau :   " + to_string(cf->niveauJeuCourant));
	// dessin du text de score et niveau actuelle
	window->fenetre.draw(scoreTxt);
	window->fenetre.draw(niveauJeu);

	// gestion des evenement de  touche de deplacemenet de pac-man 
	if (win->currentRiszedEvent.type == (sf::Event::KeyPressed)) {
		auto sommetPacManAvant = gw->pacM->currentPosition;
		cf->getchaineList()->HandleRequest(to_string(win->currentRiszedEvent.key.code), nullptr);

		if (sommetPacManAvant != gw->pacM->currentPosition && cf->niveauJeuCourant == 2) { // si pac man a changé sa position 
			gw->refroidirChemins();
			gw->g.getAreteParSommets(sommetPacManAvant, gw->pacM->currentPosition)->v.Chaufer(configs::HOT_ARC_COLOR);
		}
	}

	// dessin des elements du jeux et gestion de colision
	for (auto ge : gw->gameElements) {
		if (ge->visible)
			sfmlDraw.draw(ge); // dessin de tous les elements du jeux 
		if (ge != gw->pacM)
			if (gw->colision(gw->pacM, ge)) { // gestion de la colision

				if (dynamic_cast<Star<InfoSommet>*>(ge) != nullptr)
				{
					if (ge->visible) {
						cf->score += 1;
						ge->hide();
					}
				}
				else if (dynamic_cast<Fantome<InfoSommet>*>(ge) != nullptr)
					cf->gameOver = true;
			}
	}

	if (ck.getElapsedTime().asMilliseconds() > configs::TEMP_DEPLACEMENT_FANTOME) // deplacement des fantom chaque 3200 miliseconde
	{
		for (auto *f : gw->fantomes)
		{
			ParametersHolder ph;
			ph.g = &gw->g;
			ph.source = f->currentPosition; // la position actuelle du fantome
			ph.destination = gw->pacM->currentPosition; // la position actuelle de pac-Man
			ph.gameWorld = gw;
			cf->getchaineList()->HandleRequest("DeplacementFantomeNiveau" + to_string(cf->niveauJeuCourant), &ph);
			f->currentPosition = ph.result; // affecte la nouvelle position au fantome apres le calcule du chemin
			ck.restart();
		}
	}



	if (cf->score == configs::MAX_SCORE_PAR_PARTIE)
	{
		if (cf->niveauJeuCourant == configs::NOMBRE_DE_PARTIE) {
			cf->winGame = true; // le jeux est gagné
			gw->resetGameLevel(); // vers la premiére partie
		}
		else
			gw->partieSuivate();
	}
	if ( cf->niveauJeuCourant == 2 && ck_refroidisement.getElapsedTime().asMilliseconds() > configs::TEMP_DE_REFROIDISSEMENT_DES_ARETTES)
	{
		gw->refroidirChemins();
		ck_refroidisement.restart();
	}
}


