#include "configs.h"
#include "LeftKeyHandler.h"
#include "RightKeyHandler.h"

#include "TopKeyHandler.h"
#include "BottomKeyHandler.h"

#include "TopLeftKeyHandler.h"
#include "TopRightKeyHandler.h"

#include "BottomLeftKeyHandler.h"
#include "BottomRightKeyHandler.h"

#include "DeplacementFantomeNiveau1.h"
#include "DeplacementFantomeNiveau2.h"
#include "DeplacementFantomeNiveau3.h"

configs *configs::instance;


configs * configs::getInstance()
{
	if (instance == nullptr)
		instance = new configs();
	return instance;
}


const GuiHandler * configs::getchaineList()
{
	if (chaineList == nullptr) {
		chaineList = new LeftKeyHandler(nullptr);
		chaineList = new LeftKeyHandler(chaineList);
		chaineList = new RightKeyHandler(chaineList);
		chaineList = new TopKeyHandler(chaineList);
		chaineList = new BottomKeyHandler(chaineList);
		chaineList = new TopLeftKeyHandler(chaineList);
		chaineList = new TopRightKeyHandler(chaineList);
		chaineList = new BottomLeftKeyHandler(chaineList);
		chaineList = new BottomRightKeyHandler(chaineList);


		chaineList = new DeplacementFantomeNiveau1(chaineList);
		chaineList = new DeplacementFantomeNiveau2(chaineList);
		chaineList = new DeplacementFantomeNiveau3(chaineList);
	}
	return chaineList;
}