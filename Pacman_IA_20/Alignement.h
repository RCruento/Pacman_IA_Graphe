#pragma once
#include "Graphe\Sommet.h"
#include "Graphe\InfoSommet.h"
#include "Graphe\Graphe.h"
#include "configs.h"

/*
@brief: classe vérifiant l'alignement d'un sommet pas rapport a un autre
*/

class Alignement
{
public:

	template<int ligne, int colonne, class S, class T>
	inline Sommet<InfoSommet>* alignement(Graphe<S, T> *g, Sommet<InfoSommet>* (&virtexArray)[ligne][colonne], Sommet<InfoSommet>* source, Sommet<InfoSommet>* target);
	int a = 1;

	//horizontale et vertical vérification

	template<int ligne, int colonne>

	/*
	@brief: vérifie si la destination est horizontale avec le sommet de depart, retourne le prochain sommet vert le sommet de destination
	*/
	inline Sommet<InfoSommet>* alignementHorizontale(Sommet<InfoSommet>* (&virtexArray)[ligne][colonne], Sommet<InfoSommet>* source, Sommet<InfoSommet>* target);
	template<int ligne, int colonne>

	/*
	@brief: vérifie si la destination est verticale avec le sommet de depart, retourne le prochain sommet vert le sommet de destination
	*/
	inline Sommet<InfoSommet>* alignementVerticale(Sommet<InfoSommet>* (&virtexArray)[ligne][colonne], Sommet<InfoSommet>* source, Sommet<InfoSommet>* target);



	//diagonale verification

	/*
	@brief: vérifie si la destination est en diagonale avec le sommet de depart, retourne le prochain sommet vert le sommet de destination
	*/
	template<int ligne, int colonne, class S, class T>
	Sommet<InfoSommet>* alignementDiagonale(Graphe<S, T> *g, Sommet<InfoSommet>*(&virtexArray)[ligne][colonne], Sommet<InfoSommet>* source, Sommet<InfoSommet>* target);


};

template<int ligne, int colonne, class S, class T>
inline Sommet<InfoSommet>* Alignement::alignement(Graphe<S, T> *g, Sommet<InfoSommet>* (&virtexArray)[ligne][colonne], Sommet<InfoSommet>* source, Sommet<InfoSommet>* target)
{
	Sommet<InfoSommet>* res = nullptr;

	res = alignementHorizontale(virtexArray, source, target);

	if (!res)
		res = alignementVerticale(virtexArray, source, target);
	if (!res)
		res = alignementDiagonale(g, virtexArray, source, target);
	return res;
}

template<int ligne, int colonne>
inline Sommet<InfoSommet>* Alignement::alignementHorizontale(Sommet<InfoSommet>* (&virtexArray)[ligne][colonne], Sommet<InfoSommet>* source, Sommet<InfoSommet>* target)
{
	Vecteur2D sourcePos = source->v.vSommet.p;
	Vecteur2D targetPos = target->v.vSommet.p;

	if (sourcePos.y != targetPos.y) return nullptr; // doivent etre sur la meme ligne

	if (targetPos.x > sourcePos.y)
		return virtexArray[(int)sourcePos.y][(int)sourcePos.x + 1];
	else
		return virtexArray[(int)sourcePos.y][(int)sourcePos.x - 1];
}


template<int ligne, int colonne>
inline Sommet<InfoSommet>* Alignement::alignementVerticale(Sommet<InfoSommet>* (&virtexArray)[ligne][colonne], Sommet<InfoSommet>* source, Sommet<InfoSommet>* target)
{
	Vecteur2D sourcePos = source->v.vSommet.p;
	Vecteur2D targetPos = target->v.vSommet.p;

	if (sourcePos.x != targetPos.x) return nullptr; // doivent etre sur la meme colonne

	if (targetPos.y > sourcePos.y)
		return virtexArray[(int)sourcePos.y + 1][(int)sourcePos.x];
	else
		return virtexArray[(int)sourcePos.y - 1][(int)sourcePos.x];
}



///alignement 
template<int ligne, int colonne, class S, class T>
Sommet<InfoSommet>* Alignement::alignementDiagonale(Graphe<S, T> *g, Sommet<InfoSommet>*(&virtexArray)[ligne][colonne], Sommet<InfoSommet>* source, Sommet<InfoSommet>* target)
{

	Vecteur2D sourcePos = source->v.vSommet.p;
	Vecteur2D targetPos = target->v.vSommet.p;



	Sommet<InfoSommet>* res = nullptr, *sommetSuivant = nullptr, *sommetPrecedent = source;

	bool lock = false;

	a += 1;
	int k = 1;

	int kk = sqrt(configs::NB_LINES *configs::NB_LINES + configs::NB_COLUMNS * configs::NB_LINES); // diagonalMaximal= sqlrt(l*l+L*L) = racine(l²+L²)

	for (int i = 0; i < kk; i++)
	{

		k += 1;
		// position droite
		if (targetPos.x > sourcePos.x)
		{
			// Haut vres droite
			if (targetPos.y > sourcePos.y)
				sommetSuivant = virtexArray[(int)(sourcePos.y += 1)][(int)(sourcePos.x += 1)];
			else
				// Haut vers le bas
				sommetSuivant = virtexArray[(int)(sourcePos.y -= 1)][(int)(sourcePos.x += 1)];
		}
		else // position gauche
		{
			// Haut vers la gauche
			if (targetPos.y > sourcePos.y)
				sommetSuivant = virtexArray[(int)(sourcePos.y += 1)][(int)(sourcePos.x -= 1)];
			else
				// Bas vers droite
				sommetSuivant = virtexArray[(int)(sourcePos.y -= 1)][(int)(sourcePos.x -= 1)];
		}


		if (!lock) { res = sommetSuivant; lock = true; }

		if (!g->getAreteParSommets(sommetSuivant, sommetPrecedent)) return NULL;
		else if (target == sommetSuivant)
			return res;

		sommetPrecedent = sommetSuivant;

		if (sourcePos.x == 0 || sourcePos.x == 4 || sourcePos.y == 0 || sourcePos.y == 4) {
			//On retourne un NULL sinon on sera en out of range
			return NULL;
		}
	}
	return nullptr;
}
