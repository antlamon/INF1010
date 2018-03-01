/********************************************
* Titre: Travail pratique #4 - Fournisseur.cpp
* Date: 1 mars 2018
* Auteur: Frédéric Fortin 1900664 Antoine Lamontagne 1907605
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
	//Méthode d'accès
    vector<Usager *> obtenirUsagers() const;

	//Méthodes publiques
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
