/********************************************
* Titre: Travail pratique #4 - Fournisseur.cpp
* Date: 1 mars 2018
* Auteur: Fr�d�ric Fortin 1900664 Antoine Lamontagne 1907605
*******************************************/

#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <vector>
#include "Usager.h"
#include "Client.h"
#include "ProduitAuxEncheres.h"

using namespace std;

class Gestionnaire
{
  public:
	//M�thode d'acc�s
    vector<Usager *> obtenirUsagers() const;

	//M�thodes publiques
    void afficherLesProfils() const;
    double obtenirChiffreAffaires() const;
    void ajouterUsager(Usager *usager);
    void reinitialiser();
    void encherir(Client *client, ProduitAuxEncheres *produit, double montant) const;

  private:
	  //Attributs
    vector<Usager *> usagers_;
};

#endif
