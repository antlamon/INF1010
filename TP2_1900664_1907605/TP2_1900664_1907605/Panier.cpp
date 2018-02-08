/********************************************
* Titre: Travail pratique #2 - Panier.cpp
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothée CHAUVIN
*******************************************/

#include "Panier.h"

Panier::Panier() :
	totalAPayer_{ 0 }
{
}

Panier::~Panier()
{
}

// methodes d'accès
vector<Produit*>  Panier::obtenirContenuPanier() const
{
	return contenuPanier_;
}

int Panier::obtenirNombreContenu() const
{
	return contenuPanier_.size();
}

double Panier::obtenirTotalApayer() const
{
	return totalAPayer_;
}

void Panier::modifierTotalAPayer(double totalAPayer)
{
	totalAPayer_ = totalAPayer;
}

// méthodes de modification

// autres méthodes
void Panier::ajouter(Produit * prod)
{
	contenuPanier_.push_back(prod);
	totalAPayer_ += prod->obtenirPrix();
}

void Panier::livrer()
{
	contenuPanier_.clear();
	totalAPayer_ = 0;
}

Produit * Panier::trouverProduitPlusCher()
{
	int indice = 0;
	for (int i = 1; i < obtenirNombreContenu(); i++)
	{
		if (*contenuPanier_[indice] < *contenuPanier_[i])
			indice = i;
	}

	return contenuPanier_[indice];
}

ostream & operator<<(ostream & cout, const Panier & panier)
{
	for (int i = 0; i < panier.obtenirNombreContenu(); i++)
		cout << *panier.contenuPanier_[i] << endl;

	cout << "----> total a payer : " << panier.totalAPayer_ << endl;

	return cout;
}
