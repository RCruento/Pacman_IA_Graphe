#include "DrawWithSFML.h"
#include "TextureFactory.h"
#include "MyWindow.h"
#include <SFML\Graphics\Sprite.hpp>


using namespace sf;

void DrawWithSFML::draw(GameElement<InfoSommet>* ge) const
{
	FenetreGrapheSFML  *window = MyWindow::getInstance()->getWindow();

	Sprite sp;
	Texture *txt = TextureFactory::getInstance()->get(ge->textureName);
	sp.setTexture(*txt);

	Vecteur2D position = window->t.applique(ge->currentPosition->v.vSommet.p);
	Vecteur2D position1 = position - 10 * Vecteur2D(1, 1);

	Vector2f p1 = vecteur2DToVector2f(position1);
	sp.setPosition(p1);

	window->fenetre.draw(sp);
}

void DrawWithSFML::draw(string textureName, Vecteur2D position) const
{
	FenetreGrapheSFML  *window = MyWindow::getInstance()->getWindow();

	Sprite sp;
	Texture *txt = TextureFactory::getInstance()->get(textureName);
	sp.setTexture(*txt);

	Vector2f pos = vecteur2DToVector2f(position);
	sp.setPosition(pos);

	window->fenetre.draw(sp);

}