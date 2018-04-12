/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.cpp
* Date: 9 mars 2018
* Auteur: Frederic Fortin 1900664 & Antoine Lamontagne 1907605
*******************************************/

#include "GestionnaireUsagers.h"

//Obtient le chiffre d'affaire d'un usager selon leur total a payer
double GestionnaireUsagers::obtenirChiffreAffaires() const
{
	double chiffreAffaire = 0.0;
	//Incrémente le chiffre d'affaire selon le total a payer d'un usager pour tous les usagers
	pourChaqueElement<>([&](Usager * usager) {chiffreAffaire += usager->obtenirTotalAPayer(); });
	return chiffreAffaire;
}

//Enrichit un produit aux encheres si le prix est plus eleve et si l'encherisseur est different
void GestionnaireUsagers::encherir(Client * client, ProduitAuxEncheres * produit, double montant) const
{
	if (montant > produit->obtenirPrix())
		produit->mettreAJourEnchere(client, montant);
}

//Reinitialise tous les usagers presents dans le conteneur du gestionnaire
void GestionnaireUsagers::reinitialiser()
{
	for_each(conteneur_.begin(), conteneur_.end(), [](Usager * usager) {usager->reinitialiser(); });
}

//Affiche les profils de tous les usagers presents dans le conteneur
void GestionnaireUsagers::afficherProfils() const
{
	pourChaqueElement<>([](Usager * usager) {usager->afficher(); cout << endl; });
}
