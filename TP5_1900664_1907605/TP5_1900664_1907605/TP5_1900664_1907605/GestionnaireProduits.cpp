/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireProduits.h"

void GestionnaireProduits::reinitialiserClient()
{
}

void GestionnaireProduits::reinitialiserFournisseur()
{
}

void GestionnaireProduits::afficher() const
{
}

double GestionnaireProduits::obtenirTotalAPayer() const
{
	return 0.0;
}

double GestionnaireProduits::obtenirTotalApayerPremium() const
{
	return 0.0;
}

Produit * GestionnaireProduits::trouverProduitPlusCher() const
{
	return nullptr;
}

vector<pair<int, Produit*>> GestionnaireProduits::obtenirProduitsEntre() const
{
	return vector<pair<int, Produit*>>();
}

Produit * GestionnaireProduits::obtenirProduitSuivant(Produit * prod) const
{
	return nullptr;
}
