#pragma once
#include <map>
#include <SFML\Graphics\Texture.hpp>
using namespace std;
using namespace sf;

/*
@brief: classe qui charge toutes les textures du jeu
*/

class TextureFactory
{
	map<string, Texture*> textureMap;
	static TextureFactory *uniqueInstance;
	void loadResource(string resourceName, string fileName);

public:

	static TextureFactory *getInstance();
	TextureFactory();

	/*
	@brief: retourne la texture utilisé
	@result: Texture
	*/
	Texture* get(const string txtName) const;

	~TextureFactory();
};