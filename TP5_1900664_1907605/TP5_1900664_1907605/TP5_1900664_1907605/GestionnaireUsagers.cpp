/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireUsagers.h"

double GestionnaireUsagers::obtenirChiffreAffaires() const
{
	double chiffreAffaire = 0.0;
	//Incrémente le chiffre d'affaire selon le total a payer d'un usager pour tous les usagers
	pourChaqueElement<>([&](Usager * usager) {chiffreAffaire += usager->obtenirTotalAPayer(); });
	return chiffreAffaire;
}

void GestionnaireUsagers::encherir(Client * client, ProduitAuxEncheres * produit, double montant) const
{
	if (montant > produit->obtenirPrix())
		produit->mettreAJourEnchere(client, montant);
}

void GestionnaireUsagers::reinitialiser()
{
	pourChaqueElement<>([](Usager * usager) {usager->reinitialiser(); });
}

void GestionnaireUsagers::afficherProfils() const
{
	pourChaqueElement<>([](Usager * usager) {usager->afficher(); cout << endl; });
}
