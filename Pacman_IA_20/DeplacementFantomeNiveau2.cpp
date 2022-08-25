#include "DeplacementFantomeNiveau2.h"
#include "Alignement.h"
#include "configs.h"
#include "GameWorld.h"
bool DeplacementFantomeNiveau2::canHandle(const string & actionName) const
{
	return actionName == "DeplacementFantomeNiveau2";
}

void DeplacementFantomeNiveau2::execute(ParametersHolder * ph) const
{
	// deplacement diagonale, vertical, horisentalle
	Alignement al;
	ph->result = al.alignement(ph->g, ph->gameWorld->sommet, ph->source, ph->destination);

	// delacement selon le flair
	if (ph->result == nullptr)
	{
		Arete<InfoArete, InfoSommet> * arret_Plus_chaud = nullptr;

		auto voisin = ph->g->voisins(ph->source);

		while (voisin != NULL)
		{
			auto ar = ph->g->getAreteParSommets(ph->source, voisin->v);

			if (ar->v.estChaud()) {

				if (ph->result == nullptr)
					arret_Plus_chaud = ar;
				else
					if (ar->v.chaleur > arret_Plus_chaud->v.chaleur)
						arret_Plus_chaud = ar;
			}
			if (arret_Plus_chaud != nullptr)
				ph->result = (ph->source == arret_Plus_chaud->debut) ? arret_Plus_chaud->fin : arret_Plus_chaud->debut;
			voisin = voisin->s;
		}
	}
	
	if (ph->result == nullptr)
		configs::getInstance()->getchaineList()->HandleRequest("DeplacementFantomeNiveau1", ph);
}
