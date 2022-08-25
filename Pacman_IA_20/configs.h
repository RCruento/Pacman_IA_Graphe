#pragma once
#include "GuiHandler.h"

/*
@class : configs, regroupe toutes les configuration du jeu
*/
class configs
{

	GuiHandler * chaineList; // la chaine de responsablilité qui gére le deplacement des elements du jeux
	static configs *instance;
	configs() :score(0), niveauJeuCourant(1), gameIsRuning(false), gameOver(false), winGame(false)
	{}
public:

	static configs * getInstance();
	static const int NB_LINES = 7;
	static const int NB_COLUMNS = 7;
	unsigned int VIRTEX_COLOR = 0x00000000; // la couleur du sommet
	static const unsigned int TAUX_REFROIDISEMENT = 5;  // a chaque iteration la couleur va diminuer avec cette valeur
	static const unsigned int HOT_ARC_COLOR = 7864569; // la couleur de l'arrete quand elle soit chaude
	static const int MAX_SCORE_PAR_PARTIE = 4; // le score m'aximale quand peut avoir dans une partie pour allez au niveau suivant
	static const int NOMBRE_DE_PARTIE = 3;
	static const int TEMP_DEPLACEMENT_FANTOME = 2900; // en mili-sec
	static const int TEMP_DE_REFROIDISSEMENT_DES_ARETTES = 200; // temps de refoidsement en mili-sec

	int score;
	int  niveauJeuCourant;
	bool gameIsRuning;
	bool gameOver;
	bool winGame;
	const GuiHandler * getchaineList();


};

