#include "DeplacementFantomeNiveau1.h"
#include "tools.h"
#include "Graphe\InfoSommet.h"
#include "Graphe\OutilsCarte.h"

bool DeplacementFantomeNiveau1::canHandle(const string & actionName) const
{
	return actionName == "DeplacementFantomeNiveau1";
}

void DeplacementFantomeNiveau1::execute(ParametersHolder * ph) const
{
	auto * voisin = listeVoisins(ph->source, *ph->g);

	int taille = PElement< pair<Sommet<InfoSommet>*, double> >::taille(voisin);

	int rd_index = Tools::randomNumber(0, taille - 1); // random index 

	PElement<pair<Sommet<InfoSommet>*, double>> *tmp = nullptr;

	for (int i = 0; i <= rd_index; i++) // parcours la liste pour trouver le sommet qui est a l'indice généré aleatoirement
		if (i == 0)
			tmp = voisin;
		else
			tmp = tmp->s;

	ph->result = tmp->v->first;
}