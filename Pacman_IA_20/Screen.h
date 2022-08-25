#pragma once
#include "MyWindow.h"
#include <SFML/Window/Event.hpp>


class Screen
{
public:
	virtual void render(MyWindow *) = 0;
};

