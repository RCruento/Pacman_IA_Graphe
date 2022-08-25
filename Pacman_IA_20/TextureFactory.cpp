#include "TextureFactory.h"
#include <exception>
#include <Windows.h>


TextureFactory *TextureFactory::uniqueInstance;


TextureFactory * TextureFactory::getInstance()
{
	if (uniqueInstance == nullptr)
		uniqueInstance = new TextureFactory();
	return uniqueInstance;
}

TextureFactory::TextureFactory()
{
	loadResource("PacMan", "pacMan.png");
	loadResource("Fantome1","Fantome1.png");
	loadResource("Fantome2","Fantome2.png");
	loadResource("Fantome3","Fantome3.png");
	loadResource("Star","star.jpg");
	loadResource("pacmanlogo","logo.png");
}

void TextureFactory::loadResource(string resourceName, string fileName)
{
	auto ex = exception("can't load image file");
	auto txt = new Texture();
	if (!txt->loadFromFile("Resources/" + fileName)) throw ex;
	textureMap[resourceName] = txt;
}


Texture* TextureFactory::get(string txtName) const
{
	return textureMap.at(txtName);
}

TextureFactory::~TextureFactory()
{
}