#pragma once
#include <string>
#include <iostream>
#include "Graphe\Sommet.h"
#include "Graphe\InfosGrapheDessin.h"
using namespace std;
template<class T>

/*
@brief: Classe qui regroupe tous les elements du jeu
*/

class GameElement
{
public:
	//Position currente 
	Sommet<T> * currentPosition;
	string textureName;
	bool visible;
	GameElement(Sommet<T> *initialPosition, string txtName) : currentPosition(initialPosition), textureName(txtName), visible(true) {}

	/*
	@brief: fonction qui permet de cacher un element du jeu
	*/
	void hide() { visible = false; }

	/*
	@brief: fonction qui permet de rendre visible un element du jeu
	*/
	void show() { visible = true; }
	virtual ~GameElement() {}
};