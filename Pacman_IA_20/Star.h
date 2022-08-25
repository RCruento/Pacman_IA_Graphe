#pragma once
#include "GameElement.h"
template<class T>

///@class classe representant les pacgomme, hérite de GameElement



class Star : public GameElement<T>
{
public:
	Star(Sommet<T> *initialPosition, string txtName) :GameElement<T>(initialPosition, txtName)
	{}
};