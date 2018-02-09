/********************************************
* Titre: Travail pratique #2 - Panier.cpp
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothée CHAUVIN
*******************************************/
/**************************************************
* Titre: Travail pratique #2 - Panier.cpp
* Date: 8 février 2018
* Auteur: Frédéric Fortin(1900664) et Antoine Lamontagne(1907605)
* Classe qui représente un panier dans un magasin quelconque.
**************************************************/

#include "Panier.h"

//Constructeur par default d'un panier.
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

//Représente le nombre d'éléments dans le vecteur de produits.
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

//Ajoute des produits dans le vecteurs de produits en l'ajoutant à la fin de celui-ci pour s'assurer qu'il augmente sa taille.
void Panier::ajouter(Produit * prod)
{
	contenuPanier_.push_back(prod);
	totalAPayer_ += prod->obtenirPrix();
}

//Livre le panier en vidant le panier, donc en ajustant le montant à payer.
void Panier::livrer()
{
	contenuPanier_.clear();
	totalAPayer_ = 0;
}

//Trouve le produit le plus cher entre tous les produits qui se trouve dans le panier en comparant leur prix.
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

// surcharge de l'opérateur << pour permettre l'affichage d'un panier.
ostream & operator<<(ostream & cout, const Panier & panier)
{
	for (int i = 0; i < panier.obtenirNombreContenu(); i++)
		cout << *panier.contenuPanier_[i] << endl;

	cout << "----> total a payer : " << panier.totalAPayer_ << endl;

	return cout;
}
