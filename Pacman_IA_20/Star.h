#pragma once
#include "GameElement.h"
template<class T>

///@class classe representant les pacgomme, h�rite de GameElement



class Star : public GameElement<T>
{
public:
	Star(Sommet<T> *initialPosition, string txtName) :GameElement<T>(initialPosition, txtName)
	{}
};