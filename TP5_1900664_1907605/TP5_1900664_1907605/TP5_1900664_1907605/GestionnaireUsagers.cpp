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
	for_each(conteneur_.begin(), conteneur_.end(), [&](Usager * usager) {chiffreAffaire += usager->obtenirTotalAPayer(); });
	return chiffreAffaire;
}

void GestionnaireUsagers::encherir(Client * client, ProduitAuxEncheres * produit, double montant) const
{
	if (montant > produit->obtenirPrix())
		produit->mettreAJourEnchere(client, montant);
}

void GestionnaireUsagers::reinitialiser()
{
	for_each(conteneur_.begin(), conteneur_.end(), [](Usager * usager) {usager->reinitialiser(); });
}

void GestionnaireUsagers::afficherProfils() const
{
	for_each(conteneur_.begin(), conteneur_.end(), [](Usager* usager) {usager->afficher(); cout << endl; });
}
