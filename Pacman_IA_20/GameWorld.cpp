#include "GameWorld.h"
#include "TextureFactory.h"
#include "configs.h"
#include "Graphe\Outils.h"
#include "Graphe\OutilsCarte.h"
#include "Alignement.h"

configs *config;

GameWorld::GameWorld()
{

	config = configs::getInstance();
	initGraphVirtex();
	pacM = new PacMan<InfoSommet>(sommet[0][2], "PacMan");

	star[0] = new Star<InfoSommet>(sommet[0][0], "Star");
	star[1] = new Star<InfoSommet>(sommet[0][4], "Star");
	star[2] = new Star<InfoSommet>(sommet[4][2], "Star");
	star[3] = new Star<InfoSommet>(sommet[1][2], "Star");

	gameElements.push_back(pacM); // ajouteur le pac man au tableau generale des elements du jeux 
	for (int i = 0; i < NOMBRE_DE_Star; i++)
		gameElements.push_back(star[i]);

	fantomes[0] = new Fantome<InfoSommet>(sommet[4][4], "Fantome1");
	fantomes[1] = new Fantome<InfoSommet>(sommet[4][1], "Fantome3");
	//fantomes[2] = new Fantome<InfoSommet>(sommet[4][2], "Fantome2");
	
	for (int i = 0; i < NOMBRE_DE_FANTOME; i++)
		gameElements.push_back(fantomes[i]);

	lastGameLevel = 1;
}


GameWorld *GameWorld::gw;
GameWorld *GameWorld::getInstance()
{
	if (gw == nullptr)
		gw = new GameWorld();
	return gw;
}

GameWorld::position GameWorld::index_To_2D_Index(int index) const
{
	position p;
	p.column = index % NB_COLUMNS;
	p.row = index / NB_COLUMNS;
	return p;
}

int GameWorld::TwoD_index_To_1D(const position &pos) const
{
	return (pos.row * NB_COLUMNS) + pos.column;
}

GameWorld::position GameWorld::getPacMacPosition() const
{
	return position();
}

// load virtex
void GameWorld::initGraphVirtex()
{
	unsigned int turquoise = 0x000000;	// couleur turquoise opaque. préfixe 0x pour héxadécimal. format RGBA
	unsigned int vertCitron = 16711680;

	unsigned int magenta = Color::Magenta.toInteger();		// récupère la couleur Magenta au format nombre entier non signé
	unsigned int tangerine0 = 0x00000000; // tangerine opaque


	for (size_t ligne = 0; ligne < NB_LINES; ligne++)

		for (size_t column = 0; column < NB_COLUMNS; column++)
			sommet[ligne][column] = g.creeSommet(InfoSommet(VSommet(to_string((ligne * 5) + column), Vecteur2D(column, ligne), magenta), InfoAStar()));


	for (size_t ligne = 0; ligne < NB_LINES; ligne++)

		for (size_t column = 0; column < NB_COLUMNS; column++)
		{
			if (column < NB_COLUMNS - 1)
				OutilsCarte::creeArete(sommet[ligne][column], sommet[ligne][column + 1], g);
			if (ligne < NB_LINES - 1)
				OutilsCarte::creeArete(sommet[ligne][column], sommet[ligne + 1][column], g);

			if ((ligne > 0 && column < NB_COLUMNS - 1) && ((ligne <= 2 && column >= 2) || ((ligne > 2 && column < 2)))) // arretes inclinet vert la gauche
				OutilsCarte::creeArete(sommet[ligne][column], sommet[ligne - 1][column + 1], g);

			if ((ligne < (NB_LINES - 1) && column < NB_COLUMNS - 1) && ((ligne < 2 && column < 2) || (ligne >= 2 && column >= 2)))
				OutilsCarte::creeArete(sommet[ligne][column], sommet[ligne + 1][column + 1], g);
		}
}


bool GameWorld::verifierSiLeNiveauEstChanger()
{
	bool res = lastGameLevel != config->niveauJeuCourant;
	lastGameLevel = config->niveauJeuCourant;
	return res;
}

bool GameWorld::colision(GameElement<InfoSommet> *ge1, GameElement<InfoSommet> *ge2)  const
{
	return ge1->currentPosition == ge2->currentPosition;
}


void GameWorld::partieSuivate()
{
	config->niveauJeuCourant += 1; // passer vers le niveau suivant

}

void GameWorld::resetGameLevel()
{
	config->niveauJeuCourant = 1;
}


void GameWorld::resetGame()
{
	config->winGame = false;
	config->gameOver = false;

	config->score = 0; // reset score

	for (auto ge : gameElements) // show all hiden elements ( cause when pac man eat apple the apple hides away)
		ge->show();

	// reset game elements initial position
	fantomes[0]->currentPosition = sommet[4][4];
	fantomes[1]->currentPosition = sommet[4][1];
	fantomes[2]->currentPosition = sommet[4][3];

	pacM->currentPosition = sommet[0][2];
	resetChaleur_des_Arretes();
}

void GameWorld::refroidirChemins()
{
	auto ar = g.lAretes;

	while (ar != nullptr)
	{
		if (ar->v->v.estChaud())
			ar->v->v.Refroidire();
		ar = ar->s;
	}
}

void GameWorld::resetChaleur_des_Arretes()
{
	auto ar = g.lAretes;

	while (ar != nullptr)
	{
		ar->v->v.resetChaleur();
		ar = ar->s;
	}
}
