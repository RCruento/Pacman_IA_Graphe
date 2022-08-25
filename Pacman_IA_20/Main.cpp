#include <string>
#include <time.h>
#include <SFML\Graphics\Color.hpp>
#include <SFML/Window/Event.hpp>
#include "configs.h"
#include "GameWorld.h"
#include "MyWindow.h"
#include "MainController.h"
using namespace std;
MainController *MController;

int main()
{
	srand(time(NULL));
	MController = new MainController();
	MyWindow * win = MyWindow::getInstance();
	while (win->getWindow()->fenetre.isOpen())
	{
		win->getWindow()->fenetre.clear(sf::Color::Black); 
		MController->render(win);
		win->display();
		Event event;

		//boucle infinie de contr�le des �v�nements de la fen�tre
		if (win->getWindow()->fenetre.pollEvent(event))
		{
			win->currentRiszedEvent = event; 
			if (event.type == Event::Closed) 
				win->close();
		}
	}
	return 0;
}
