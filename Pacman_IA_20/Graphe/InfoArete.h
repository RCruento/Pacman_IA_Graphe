//#ifndef INFOARETE_H
//#define INFOARETE_H


#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include "../MyColor.h"
#include <math.h>
//#include "../configs.h"

using namespace std;

/**

Information associée à une arête  (segment rectiligne) joignant 2 lieux d'une carte routière.

On ne stocke que le côut de l'arête, c-à-d sa longueur et sa couleur

*/

class InfoArete
{

public:

	double cout1;
	unsigned int couleur;
	unsigned int couleurInitial;
	unsigned int chaleur;    // by default set to zero
	static const int MAX_CHALEUR = 255;

	/**
	Par défaut, la couleur d'une arête est le bleu
	*/
	InfoArete(const double & cout1, const unsigned int couleur = 0x0000FFFF) :cout1(cout1), couleur(couleur), couleurInitial(couleur),chaleur(0) {}
	operator string() const;
	friend ostream & operator << (ostream & os, const InfoArete & infoArete) { return os << (string)infoArete; }

	// chaufe l'arret la nouvelle couleur est donnée en paramettre d'ou l'artte est chaud
	void Chaufer(unsigned int hotVirtexColor) { couleur = hotVirtexColor; chaleur = MAX_CHALEUR; }

	// refoidire l'arret
	void Refroidire();

	// restitue si l'arret est chaud ou pas
	bool estChaud() { return chaleur != 0; }

	void resetChaleur() { couleur = couleurInitial; chaleur = 0; }
};

inline InfoArete::operator string() const
{
	ostringstream oss;

	oss << "coût = " << cout1 << ", " << couleur;

	return oss.str();
}


inline void InfoArete::Refroidire()
{
	if (chaleur > 0)
	{
		chaleur -= 1;
		auto c = MyColor(couleur);
		auto initial_C = MyColor(couleurInitial);

		if (couleur != couleurInitial) {
			MyColor::CouleurRaprochement(c, initial_C);
			couleur = c.toIntValue();
		//	cout << couleur << endl;
		}
	}
	else {
		chaleur = 0;
		couleur = couleurInitial;
	}
}