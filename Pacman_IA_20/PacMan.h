#pragma once
#include "GameElement.h"
template<class T>

/*
@brief: classe representant le model pacman, herite de GameElement
*/
class PacMan : public GameElement<T>
{
public:
	PacMan(Sommet<T> *initialPosition, string txtName) :GameElement<T>(initialPosition, txtName) {}
};
