#pragma once
#include "Graphe\Graphe.h"
#include "Graphe\InfosGrapheDessin.h"
#include "Graphe\InfoSommet.h"
#include "Graphe\InfoArete.h"
#include "GameWorld.h"

/*
@breif: classe contenant les parametres qui vont etre utilisÚs pour etre passÚs a la chaine de responsabilitÚs
*/

class ParametersHolder
{
public:

	//Graphe de depart
	Graphe<InfoArete, InfoSommet> *g;

	//Sommet de depart
	Sommet<InfoSommet> * source;

	//Sommet de destination
	Sommet<InfoSommet> * destination;

	//Prochain sommet du chemin pour atteindre le sommet de destination
	Sommet<InfoSommet> * result;

	GameWorld * gameWorld;
};

