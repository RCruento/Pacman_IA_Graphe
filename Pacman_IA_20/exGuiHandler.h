#pragma once
#include <exception>
#include <string>


/*! \brief une classe qui lance une exception si on pointe sur une classe nulle dans la chaine de responsabilités
	\return exception si classe vide, sinon rien
*/
class exGuiHandler : public std::exception
{
public:

	exGuiHandler(std::string errorMsg) : exception(errorMsg.c_str()) {}
};