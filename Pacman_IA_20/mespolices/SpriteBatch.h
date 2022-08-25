/**
* Cree la fenetre du jeu
*/

#ifndef SPRITEBACTH_H
#define SPRITEBACTH_H

#include <iostream>
#include <sstream>
#include <string>

#include <SFML\Graphics\Color.hpp>
#include <SFML\Graphics\RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/Font.hpp>
#include<SFML/GRAPHICS/Texture.hpp>
#include<SFML/GRAPHICS/Sprite.hpp>

#include "Graphe.h"
#include "FenetreGrapheSFML.h"


using namespace std;

template <class T>
class SpriteBatch {
	
	Font _font1, _font2;

	string
		_nomFichierFonte2 = "mespolices\\Pixeled.ttf", 
		_nomFichierFonte1 = "mespolices\\Action Man Extended.ttf";

	string _titre;
	int _largeur, _hauteur;
	Vecteur2D _coinBG, _coinHD;
	unsigned int _fondCarte;

	sf::Event _event;
	FenetreGrapheSFML *fenetreGraphe;

	// devient true si le joueur a fermer la fenetre
	bool _fenetre_close = false;

public:

	// touche du clavier en int
	const static int
		HAUT = 83,
		BAS = 77,
		GAUCHE = 79,
		DROITE = 81,
		BAS_GAUCHE = 76,
		BAS_DROITE = 78,
		HAUT_GAUCHE = 82,
		HAUT_DROITE = 84;

	SpriteBatch(const string titre);
	virtual ~SpriteBatch();

	const int get_key_pressed() const;
	FenetreGrapheSFML *get_fenetreGraphe() const;

	const bool get_fenetre_close() const;

	void clear();
	void verif_close_fenetre();
	const bool is_open();
	const bool pollEvent();
	const bool key_pressed();

	/**
	* Affiche le texte "texte" sur la fenetre
	*/
	void transition_texte(const string texte);

	/**
	* Dessine le boutton qui permet de lancer le jeu
	*/
	void draw_button_start(const string chemin_image);

	/**
	* Dessine l'interface au lancement du jeu
	*/
	void draw_logo(const string chemin_image);

	/**
	* Dessine kes regles du jeu
	*/
	void draw_regle_du_jeux(const string regle);

	/**
	* Dessine l'interface de fin du jeu
	*/
	void draw_menu_fin(const string chemin_image, const string message);

	/**
	* Dessine le score et le niveau actuel
	*/
	void draw_score_et_niveau(const int score, const int niveau);

	/**
	* Dessine le fond
	*/
	void draw_fond();

	/**
	* Attend que le joueur clique sur le bouton start
	*/
	void attend_event_button_debut_pressed();

	/**
	* Attend que le joueur clique sur le bouton rejouer ou quitter
	*/
	const bool attend_event_button_fin_pressed();
};

template <class T>
SpriteBatch<T>::SpriteBatch(const string titre) {

	if (!_font1.loadFromFile(_nomFichierFonte1) || !_font2.loadFromFile(_nomFichierFonte2))
		throw Erreur();

	_titre = titre;

	_largeur = 600;
	_hauteur = 600;

	_coinBG = Vecteur2D(-0.5, -0.5);
	_coinHD = Vecteur2D(6, 6);

	_fondCarte = 0xEFEFEFFF; // sorte de gris clair ~= étain pur

	fenetreGraphe = new FenetreGrapheSFML(_titre, _fondCarte, _coinBG, _coinHD, _largeur, _hauteur, _font1);
}

template <class T>
SpriteBatch<T>::~SpriteBatch() {
	delete fenetreGraphe;
}

template <class T>
const bool SpriteBatch<T>::is_open() {
	return fenetreGraphe->fenetre.isOpen();
}
 
template <class T>
const bool SpriteBatch<T>::pollEvent() {
	return fenetreGraphe->fenetre.pollEvent(_event);
}

template <class T>
void SpriteBatch<T>::verif_close_fenetre() {

	if (_event.type == sf::Event::Closed || _event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Escape) {
		fenetreGraphe->fenetre.close();

		_fenetre_close = true;
	}
}

template <class T>
void SpriteBatch<T>::clear() {
	fenetreGraphe->fenetre.clear(sf::Color::Blue);
}

template <class T>
const bool SpriteBatch<T>::key_pressed() {
	return _event.type == sf::Event::KeyPressed;
}

template <class T>
const int SpriteBatch<T>::get_key_pressed() const {
	return _event.key.code;
}

template <class T>
FenetreGrapheSFML *SpriteBatch<T>::get_fenetreGraphe() const {
	return fenetreGraphe;
}

template <class T>
const bool SpriteBatch<T>::get_fenetre_close() const {
	return _fenetre_close;
}

template <class T>
void SpriteBatch<T>::transition_texte(const string texte) {

	sf::Text text(texte, _font2);

	text.setCharacterSize(70);

	text.setStyle(sf::Text::Bold);

	text.setFillColor(sf::Color::Yellow);

	Vector2f p1 = vecteur2DToVector2f(Vecteur2D(110, 270));
	text.setPosition(p1);

	fenetreGraphe->fenetre.draw(text);
}

template <class T>
void SpriteBatch<T>::draw_button_start(const string chemin_image) {

	Texture button;

	if (!button.loadFromFile(chemin_image))
		throw Erreur("impossible de charger l'image du bouton start");

	//Création d'un sprite à partir de cette texture
	Sprite sprite;
	sprite.setTexture(button);

	Vector2f p1 = vecteur2DToVector2f(Vecteur2D(80, 315));

	sprite.setPosition(p1);
	
	fenetreGraphe->fenetre.draw(sprite); 
}

template <class T>
void SpriteBatch<T>::draw_logo(const string chemin_image) {

	Texture button;

	if (!button.loadFromFile(chemin_image))
		throw Erreur("impossible de charger l'image de debut");

	//Création d'un sprite à partir de cette texture
	Sprite sprite;
	sprite.setTexture(button);
	
	fenetreGraphe->fenetre.draw(sprite); 
}

template <class T>
void SpriteBatch<T>::draw_regle_du_jeux(const string regle) {

	sf::Text text(regle, _font1);

	text.setCharacterSize(17);

	text.setStyle(sf::Text::Bold);

	text.setFillColor(sf::Color::Black);

	Vector2f p1 = vecteur2DToVector2f(Vecteur2D(8, 520));
	text.setPosition(p1);
	fenetreGraphe->fenetre.draw(text); 
}

template <class T>
void SpriteBatch<T>::draw_menu_fin(const string chemin_image, const string message) {

	Texture button;

	if (!button.loadFromFile(chemin_image))
		throw Erreur("impossible de charger l'image de fin");

	//Création d'un sprite à partir de cette texture
	Sprite sprite;
	sprite.setTexture(button);

	fenetreGraphe->fenetre.draw(sprite);

	sf::Text text(message, _font1);

	text.setCharacterSize(18);

	text.setStyle(sf::Text::Bold);

	text.setFillColor(sf::Color::Red);

	Vector2f p1 = vecteur2DToVector2f(Vecteur2D(20, 550));
	text.setPosition(p1);
	fenetreGraphe->fenetre.draw(text);
}

template <class T>
void SpriteBatch<T>::draw_score_et_niveau(const int score, const int niveau) {

	string 
		_score = "SCORE: " + to_string(score) + "/" + to_string(Game::NOMBRE_PAC_GOMME),
		_niveau = "LEVEL " + to_string(niveau);

	sf::Text text1(_score, _font1);
	sf::Text text2(_niveau, _font1);

	text1.setCharacterSize(15);
	text1.setStyle(sf::Text::Bold);
	text1.setFillColor(sf::Color::Black);
	text1.setPosition(vecteur2DToVector2f(Vecteur2D(23, 10)));

	text2.setCharacterSize(15);
	text2.setStyle(sf::Text::Bold);
	text2.setFillColor(sf::Color::Black);
	text2.setPosition(vecteur2DToVector2f(Vecteur2D(470, 10)));

	fenetreGraphe->fenetre.draw(text1);
	fenetreGraphe->fenetre.draw(text2);
}

template <class T>
void SpriteBatch<T>::draw_fond() {

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

	fenetreGraphe->fenetre.draw(rectangle1);
	fenetreGraphe->fenetre.draw(rectangle2);
	fenetreGraphe->fenetre.draw(rectangle3);
	fenetreGraphe->fenetre.draw(rectangle4);
}

template <class T>
void SpriteBatch<T>::attend_event_button_debut_pressed() {

	Vector2i localPosition;

	bool a_chosie = false;

	// on attend que le joueur clique sur le bouton commencer
	while (!a_chosie) 
		while (pollEvent()) {

			verif_close_fenetre();

			if (_event.type == sf::Event::MouseButtonPressed && Mouse::isButtonPressed(Mouse::Left)) {

				localPosition = Mouse::getPosition(get_fenetreGraphe()->fenetre);

				if (localPosition.x > 95 && localPosition.x < 330 && localPosition.y > 330 && localPosition.y < 480)
					a_chosie = true;
			}
		}
}


template <class T>
const bool SpriteBatch<T>::attend_event_button_fin_pressed() {

	Vector2i localPosition;

	// on attend que le joueur clique sur le bouton rejouer ou quitter
	while (true)
		while (pollEvent()) {

			verif_close_fenetre();

			if (_event.type == sf::Event::MouseButtonPressed &&  Mouse::isButtonPressed(Mouse::Left)) {

				localPosition = Mouse::getPosition(get_fenetreGraphe()->fenetre);

				if (localPosition.x > 45 && localPosition.x < 220 && localPosition.y > 360 && localPosition.y < 410)
					return true;

				if (localPosition.x > 360 && localPosition.x < 550 && localPosition.y > 360 && localPosition.y < 410)
					return false;
			}
		}
}

#endif // SPRITEBACTH_H