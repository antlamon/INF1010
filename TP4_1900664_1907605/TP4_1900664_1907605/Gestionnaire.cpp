/********************************************
* Titre: Travail pratique #4 - Fournisseur.cpp
* Date: 1 mars 2018
* Auteur: Fr�d�ric Fortin 1900664 Antoine Lamontagne 1907605
*******************************************/

#include "Gestionnaire.h"

//M�thode d'acc�s
vector<Usager *> Gestionnaire::obtenirUsagers() const
{
    return usagers_;
}

//M�thode appelant la m�thode afficherProfil() de tous les usagers
void Gestionnaire::afficherLesProfils() const
{
	for (Usager* usager : usagers_)
	{
		usager->afficherProfil();
		cout << endl;
	}
}

//M�thode retournant le total � payer pour tous les usagers utilisant la m�thode publique
//obtenirTotalAPayer() de usagers.
double Gestionnaire::obtenirChiffreAffaires() const
{
	double chiffresAffaires = 0;

	for (Usager* usager : usagers_)
		chiffresAffaires += usager->obtenirTotalAPayer();

	return chiffresAffaires;
}

//M�thode ajoutant un nouveau s'il n'est pas deja present dans le vector usagers_
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

//M�thode appelant la m�thode publique reninitialiser() de la classe Usager pour tous
//les usagers dans le vector usagers_
void Gestionnaire::reinitialiser()
{
	for (Usager* unUsager : usagers_)
		unUsager->reinitialiser();
}

//M�thode mettant � jour le produit aux encheres si le nouveau encherisseur propose une meilleur mise
void Gestionnaire::encherir(Client *client, ProduitAuxEncheres *produit, double montant) const
{
	if (montant > produit->obtenirPrix())
		produit->mettreAJourEnchere(client, montant);
}
