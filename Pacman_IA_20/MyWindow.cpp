#include "MyWindow.h"


MyWindow::MyWindow() {
	getWindow();
}

MyWindow * MyWindow::win;
MyWindow * MyWindow::getInstance()
{
	if (win == nullptr)
		win = new MyWindow();
	return win;
}
FenetreGrapheSFML * MyWindow::getWindow()
{
	if (sfmlWin == nullptr)
	{
		
		string nomFichierFonte1 = "mespolices\\Action Man.ttf";
		bool k = font1.loadFromFile(nomFichierFonte1);


		string nomFichierFonte2 = "mespolices\\Mario-Kart-DS.ttf";
		bool k2 = font2.loadFromFile(nomFichierFonte2);

		string titre("Pac-Man_2019-2020_L3");
		int largeur = 1000, hauteur = 1000;

		Vecteur2D  coinBG(-0.5, -0.5), coinHD(8, 8);

		unsigned int fondCarte = 0x00000000;	//gris clair

		sf::ContextSettings settings;
		settings.antialiasingLevel = 4; 

		sfmlWin = new FenetreGrapheSFML(titre, fondCarte, coinBG, coinHD, largeur, hauteur, font1);
	}
	return sfmlWin;
}

void MyWindow::display() {
	sfmlWin->fenetre.display();
}


void MyWindow::close()
{
	sfmlWin->fenetre.close();
}
