#pragma once
#include "GameElement.h"
template<class T>

/*
@brief: classe fantome h�rite de GameElement
*/

class Fantome : public GameElement<T>
{
public:

	Fantome(Sommet<T> *initialPosition, string txtName) :GameElement<T>(initialPosition, txtName)
	{}
};