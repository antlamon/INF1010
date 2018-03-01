/********************************************
* Titre: Travail pratique #4 - Fournisseur.cpp
* Date: 1 mars 2018
* Auteur: Frédéric Fortin 1900664 Antoine Lamontagne 1907605
*******************************************/

#include "Gestionnaire.h"

//Méthode d'accès
vector<Usager *> Gestionnaire::obtenirUsagers() const
{
    return usagers_;
}

//Méthode appelant la méthode afficherProfil() de tous les usagers
void Gestionnaire::afficherLesProfils() const
{
	for (Usager* usager : usagers_)
	{
		usager->afficherProfil();
		cout << endl;
	}
}

//Méthode retournant le total à payer pour tous les usagers utilisant la méthode publique
//obtenirTotalAPayer() de usagers.
double Gestionnaire::obtenirChiffreAffaires() const
{
	double chiffresAffaires = 0;

	for (Usager* usager : usagers_)
		chiffresAffaires += usager->obtenirTotalAPayer();

	return chiffresAffaires;
}

//Méthode ajoutant un nouveau s'il n'est pas deja present dans le vector usagers_
void Gestionnaire::ajouterUsager(Usager *usager)
{
	bool usagerDejaAjoute = false;

	for (Usager* unUsager : usagers_)
	{
		if (unUsager == usager)
		{
			usagerDejaAjoute = true;
			break;
		}
	}

	if (!usagerDejaAjoute)
		usagers_.push_back(usager);
}

//Méthode appelant la méthode publique reninitialiser() de la classe Usager pour tous
//les usagers dans le vector usagers_
void Gestionnaire::reinitialiser()
{
	for (Usager* unUsager : usagers_)
		unUsager->reinitialiser();
}

//Méthode mettant à jour le produit aux encheres si le nouveau encherisseur propose une meilleur mise
void Gestionnaire::encherir(Client *client, ProduitAuxEncheres *produit, double montant) const
{
	if (montant > produit->obtenirPrix())
		produit->mettreAJourEnchere(client, montant);
}
