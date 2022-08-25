#ifndef FENETREGRAPHESFML_H
#define FENETREGRAPHESFML_H

#include<SFML/Graphics/RenderWindow.hpp>
#include <SFML\Graphics\RectangleShape.hpp>
#include<SFML/Graphics/VertexArray.hpp>
#include<SFML/GRAPHICS/CircleShape.hpp>
#include<SFML/GRAPHICS/ConvexShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include<SFML/GRAPHICS/Texture.hpp>
#include<SFML/GRAPHICS/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include "Sommet.h"
#include "Arete.h"
#include "InfosGrapheDessin.h"
#include "TransfoAffine2D.h"
#include "Erreur.h"


using namespace sf;
using namespace std;

/**
Prend en charge le dessin d'un graphe.
*/

inline const Vector2f vecteur2DToVector2f(const Vecteur2D & v) { float x, y; v.arrondit(x, y); return Vector2f(x, y); }

/**
vSommet : en coordonn�es monde
*/
inline bool dessinePetitRond(RenderWindow & fenetre, const TransfoAffine2D & t, const VSommet & vSommet, const Font & font,
	const Vecteur2D & deltaTextePixels = Vecteur2D(0.15*10, 10))
{
	Vecteur2D position = t.applique(vSommet.p);
	Vecteur2D position1 = position - 10*Vecteur2D(1, 1);

	// si on appliquait la transfo t globalement � tout le graphe avant de commencer � dessiner, on optimiserait
	// bcp de calculs !!!!

	CircleShape disque((float)10);
	disque.setFillColor(Color(vSommet.couleur));
	float epaisseurBord = (float)(0.15*10);
	disque.setOutlineThickness(epaisseurBord);
	disque.setOutlineColor(Color(0xA10684FF));

	Vector2f p1 = vecteur2DToVector2f(position1);
	disque.setPosition(p1);
	fenetre.draw(disque);
	return true;
}

/**
d�but et fin sont en coordonn�es monde
*/
inline bool dessineSegment(RenderWindow & fenetre, const TransfoAffine2D & t, const unsigned int couleur,
	const Vecteur2D & debut, const Vecteur2D & fin, const unsigned int epaisseurTraitPixels = 12)
{
	// on va dessiner un rectangle tr�s fin pour repr�senter l'ar�te
	Vecteur2D A, B;	// {AB] est l'ar�te � repr�senter
	A = t.applique(debut); B = t.applique(fin);		// on passe des coordonn�es monde aux coordonn�es �cran
	Vecteur2D u = B - A;
	double nU = norme(u);
	u /= nU;
	Vecteur2D  n = u.rotationDirecteQuartDeTour();

	//double e = 1;	// �paisseur du rectangle = 2*e. longueur du rectangle == AB
	double e = 0.5*epaisseurTraitPixels;	// �paisseur du rectangle = 2*e. longueur du rectangle == AB
	Vecteur2D v = e * n;
	Vecteur2D A0 = A - v, A1 = B - v, A2 = B + v, A3 = A + v; // on calcule les 4 sommets du rectangle dont l'ar�te [AB] est un axe de sym�trie
	Vector2f F0 = vecteur2DToVector2f(A0);
	Vector2f F1 = vecteur2DToVector2f(A1);
	Vector2f F2 = vecteur2DToVector2f(A2);
	Vector2f F3 = vecteur2DToVector2f(A3);

	ConvexShape rectangle(4);
	rectangle.setPoint(0, F0);
	rectangle.setPoint(1, F1);
	rectangle.setPoint(2, F2);
	rectangle.setPoint(3, F3);
	rectangle.setFillColor(Color(couleur));
	fenetre.draw(rectangle);

	return true;
}

/**
 prend en charge le dessin d'une texture
*/
inline bool dessineTexture(RenderWindow & fenetre, Texture texture, Vecteur2D p) {

	//Cr�ation d'un sprite � partir de cette texture
	Sprite sprite;
	sprite.setTexture(texture);
	Vector2f p1 = vecteur2DToVector2f(p);
	sprite.setPosition(p1);
	fenetre.draw(sprite);
	return true;
}


/**
prend en charge le dessin du fond de l'eran
*/
inline bool dessineFond(RenderWindow & fenetre) {
	sf::RectangleShape rectangle1(sf::Vector2f(600, 95));
	sf::RectangleShape rectangle2(sf::Vector2f(58, 600));
	sf::RectangleShape rectangle3(sf::Vector2f(70, 600));
	sf::RectangleShape rectangle4(sf::Vector2f(600, 46));
	rectangle1.setPosition(sf::Vector2f(0, 0));
	rectangle1.setFillColor(sf::Color::Yellow);
	rectangle2.setPosition(sf::Vector2f(0, 0));
	rectangle2.setFillColor(sf::Color::Yellow);
	rectangle3.setPosition(sf::Vector2f(533, 0));
	rectangle3.setFillColor(sf::Color::Yellow);
	rectangle4.setPosition(sf::Vector2f(0, 570));
	rectangle4.setFillColor(sf::Color::Yellow);
	fenetre.draw(rectangle1);
	fenetre.draw(rectangle2);
	fenetre.draw(rectangle3);
	fenetre.draw(rectangle4);
	return true;
}


class FenetreGrapheSFML
{
public:
	RenderWindow fenetre;
	const Font & font;
	sf::Event _event;
	TransfoAffine2D t;	// r�alise le passage fen�tre-cl�ture (ou encore monde vers �cran)
	/**
	Cr�e la fen�tre qui va contenir le dessin du graphe.

	DONNEES : titre : titre de la fen�tre
			  fondCarte : couleur du fond de la sc�ne au formar RGBA
			  coinBG : coin Bas Gauche de la sc�ne en coordonn�es monde
			  coinHD : coin Haut Droit de la sc�ne en coordonn�es monde
			  largeur : largeur de la fen�tre �cran (en pixels)
			  hauteur : hauteur de la fen�tre �cran (en pixels)
			  font : police � utiliser pour les annotations sur les sommets

	*/
	FenetreGrapheSFML(const string & titre, const unsigned int fondCarte,
		const Vecteur2D & coinBG, const Vecteur2D & coinHD,
		const int largeur, const int hauteur, const Font & font) :
		fenetre(sf::VideoMode(largeur, hauteur), titre), font(font)
	{
		fenetre.clear(Color(fondCarte));
		// calcul de la transformation affine - changement de rep�re : monde ---> �cran
		Vecteur2D coinEcranBG(0, hauteur), coinEcranHD(largeur, 0);
		t = TransfoAffine2D::passageMondeEcran(coinBG, coinHD, coinEcranBG, coinEcranHD);
	}
	/**
	Dessine un sommet du graphe. Exemples :  nom, couleur, informations associ�es, etc.
	renvoie true en cas de succ�s, false en cas d'�chec
	On suppose que les coordonn�es du sommet sont d�finies par rapport au rep�re du monde
	*/
	template <class T>
	bool dessine(const Sommet<T> * sommet);

	/**
	Dessine l'ar�te (d�but->fin) en utilisant la couleur "couleur"
	renvoie true en cas de succ�s, false en cas d'�chec
	On suppose que les coordonn�es des sommets sont d�finies par rapport au rep�re du monde
	*/
	template <class T>
	bool dessine(const Sommet<T> * debut, const Sommet<T> * fin, unsigned int couleur);

	/**
	Dessine un ar�te du graphe. Exemples :  nom, couleur, informations associ�es, etc.
	renvoie true en cas de succ�s, false en cas d'�chec
	On suppose que les coordonn�es des sommets sont d�finies par rapport au rep�re du monde
	*/
	template <class S, class T>
	bool dessine(const Arete<S, T> * arete);
};





#endif // FENETRE_H
