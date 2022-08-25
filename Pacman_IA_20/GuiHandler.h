#pragma once
#include <string>
#include "ParametersHolder.h"
#include <SFML\Window\Keyboard.hpp>
#include "GameWorld.h"
using namespace std;
using namespace sf;

/*
chaine of responsibility to dispay the the right Transform paramettres panel on the view
*/

class GuiHandler
{
protected:
	const GuiHandler * next;
	/*
	@brief : v�rifie si la chaine peut ou pas �tre manipul�e
	@result: true si peut etre manipul�, false sinon
	*/
	virtual bool canHandle(const string & actionName)const = 0;

	/*
	@brief: fonction qui execute la chaine de responsabilit� si canhandle() retourne Vrai
	*/
	virtual void execute(ParametersHolder *pm)const = 0;

public:
	GuiHandler(GuiHandler * next);
	void HandleRequest(const string & actionName, ParametersHolder *ph) const;

};

