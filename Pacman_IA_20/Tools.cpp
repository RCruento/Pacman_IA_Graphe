#include "tools.h"
#include <stdlib.h>



int Tools::randomNumber(int debut, int fin)
{
	return  (rand() % (fin - debut + 1)) + debut;
}
