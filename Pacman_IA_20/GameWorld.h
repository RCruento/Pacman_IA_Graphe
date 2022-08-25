#pragma once
#include <vector>

#include "PacMan.h"
#include "Star.h"
#include "Fantome.h"
#include "GameElement.h"

#include "Graphe\InfoArete.h"
#include "Graphe\InfoSommet.h"

#include "Graphe\Graphe.h"
#include "Graphe\InfosGrapheDessin.h"
using namespace std;

/*
@brief: classe regroupant toutes les instances de chaque element du jeu
*/

class GameWorld
{
	GameWorld();
	int lastGameLevel;
public:

	Graphe<InfoArete, InfoSommet> g;
	static const int NB_LINES = 7;
	static const int NB_COLUMNS = 7;
	static const int NOMBRE_DE_Star = 4;
	static const int NOMBRE_DE_FANTOME = 2;
	Sommet<InfoSommet> *sommet[NB_COLUMNS][NB_LINES];
	PacMan<InfoSommet> *pacM;
	Star<InfoSommet> *star[NOMBRE_DE_Star];
	Fantome<InfoSommet> * fantomes[NOMBRE_DE_FANTOME];

	//Tableau regroupant tous les element du jeu
	vector<GameElement<InfoSommet>*> gameElements;
	static GameWorld *gw;
	void initGraphVirtex();
	static GameWorld *getInstance();
	typedef struct position { int column; int row; };
	position index_To_2D_Index(int index) const;
	int TwoD_index_To_1D(const position&) const;
	position pacManPosition;

	/*
	@brief: retourne la position de pacman
	@result: position
	*/
	position  getPacMacPosition() const;

	/*
	@brief: verifie si le niveau a été changé
	@result: vraie si le nv a été changé, faux sinon
	*/
	bool verifierSiLeNiveauEstChanger();

	/*
	@brief: verifie la collision entre deux elements du jeu
	*/
	bool colision(GameElement<InfoSommet> *ge1, GameElement<InfoSommet> *ge2) const;

	/*
	@brief: refroidis les aretes du graphes en diminuant le degré
	*/
	void refroidirChemins();

	/*
	@brief: réinitialise le degré de chaleur de l'arete a 0
	*/
	void resetChaleur_des_Arretes();

	/*
	@brief: réinitialse entierement le jeu => nouvelle partie => réinitialse tous les paramètres
	*/
	void resetGame();

	/*
	@brief: procedure qui permet de passer au nv suivant
	*/
	void partieSuivate();

	/*
	@brief: procedure qui permet de passer au premier nv du jeu
	*/
	void resetGameLevel();
};
