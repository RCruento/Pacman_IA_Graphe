#pragma once

#include "Graphe\FenetreGrapheSFML.h"
#include <SFML/Window/Event.hpp>

/*
@brief: classe representant la fenetre du jeu
*/
class MyWindow
{
	MyWindow();
	FenetreGrapheSFML * sfmlWin;
	static MyWindow * win;

public:
	Font font1;
	Font font2;
	static MyWindow * getInstance();
	FenetreGrapheSFML * getWindow();
	Event currentRiszedEvent;
	/*
	@brief: procedure qui afficher la fenetre
	*/
	void display();

	/*
	@brief: procedure qui ferme la fenetre
	*/
	void close();
};