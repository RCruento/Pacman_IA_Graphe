#include "DeplacementFantomeNiveau3.h"
#include "Graphe\OutilsCarte.h"
#include "Graphe\AStarT.h"




bool DeplacementFantomeNiveau3::canHandle(const string & actionName) const
{
	return actionName == "DeplacementFantomeNiveau3";
}

void DeplacementFantomeNiveau3::execute(ParametersHolder * ph) const
{
	OutilsCarte::cible = ph->destination;

	AStarT< Graphe<InfoArete, InfoSommet>, Sommet<InfoSommet> >::aStar(*ph->g, ph->source, OutilsCarte::hh);
	PElement<Sommet<InfoSommet>> * c;
	chemin(ph->destination, c);

	ph->result = c->s->v;
}
