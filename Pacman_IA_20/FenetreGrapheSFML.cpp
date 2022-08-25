#include "Graphe\FenetreGrapheSFML.h"
#include "Graphe\InfoSommet.h"
#include "Graphe\InfoArete.h"


//template <>
//bool FenetreGrapheSFML::dessine<Peinture, VSommet>(const Arete<Peinture, VSommet> * arete)
//{
//	dessineSegment(this->fenetre, this->t, arete->v.fond, arete->debut->v.p, arete->fin->v.p);
//	return dessineSegment(this->fenetre, this->t, arete->v.devant, arete->debut->v.p, arete->fin->v.p);
//}
//
//
//template <>
//bool FenetreGrapheSFML::dessine<VSommet>(const Sommet<VSommet> * sommet)
//{
//	return dessinePetitRond(this->fenetre, this->t, sommet->v, this->font);	// m�thode ordinaire. cf. d�but de ce fichier
//}

//---------------------------------------dessine le cas particulier de InfoSommet et InfoArete ------------------------------

/**
Dessine un sommet du graphe. Exemples :  nom, couleur, informations associ�es, etc.
renvoie true en cas de succ�s, false en cas d'�chec
On suppose que les coordonn�es du sommet sont d�finies par rapport au rep�re du monde
*/
template <>
bool FenetreGrapheSFML::dessine<InfoSommet>(const Sommet<InfoSommet> * sommet)
{
	Vecteur2D deltaTextePixels(0.8 * 10, 10);
	return dessinePetitRond(this->fenetre, this->t, sommet->v.vSommet, this->font, deltaTextePixels);
}

/**
Dessine l'ar�te (d�but->fin) en utilisant la couleur "couleur"
renvoie true en cas de succ�s, false en cas d'�chec
On suppose que les coordonn�es des sommets sont d�finies par rapport au rep�re du monde
*/
template <>
bool FenetreGrapheSFML::dessine<InfoSommet>(const Sommet<InfoSommet> * debut, const Sommet<InfoSommet> * fin, unsigned int couleur)
{
	unsigned int epaisseurAretePixels = 1;
	return dessineSegment(this->fenetre, this->t, couleur, debut->v.vSommet.p, fin->v.vSommet.p, epaisseurAretePixels);
}

/**
Dessine un ar�te du graphe. Exemples :  nom, couleur, informations associ�es, etc.
renvoie true en cas de succ�s, false en cas d'�chec
On suppose que les coordonn�es des sommets sont d�finies par rapport au rep�re du monde
*/
template <>
bool FenetreGrapheSFML::dessine<InfoArete, InfoSommet>(const Arete<InfoArete, InfoSommet> * arete)
{
	unsigned int epaisseurAretePixels = 4;
	return dessineSegment(this->fenetre, this->t, arete->v.couleur, arete->debut->v.vSommet.p, arete->fin->v.vSommet.p, epaisseurAretePixels);
}

