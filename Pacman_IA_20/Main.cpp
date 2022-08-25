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

		//boucle infinie de contrôle des évènements de la fenêtre
		if (win->getWindow()->fenetre.pollEvent(event))
		{
			win->currentRiszedEvent = event; 
			if (event.type == Event::Closed) 
				win->close();
		}
	}
	return 0;
}
