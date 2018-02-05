/**************************************************
* Titre: Travail pratique #1 - Panier.cpp
* Date: 4 février 2018
* Auteur: Frédéric Fortin(1900664) et Antoine Lamontagne(1907605)
Classe contenant les différents produits que le client à l'intention d'acheter et permet l'achat de ces derniers.
**************************************************/
#include "panier.h"

//Constructeur par paramètre
Panier::Panier(int capacite)
	:capaciteContenu_(capacite)
{
	nombreContenu_ = 0;
	totalAPayer_ = 0;
	contenuPanier_ = new Produit*[capacite];
}

//Destructeur de la classe
Panier::~Panier() 
{
	delete[] contenuPanier_;
	contenuPanier_ = nullptr;
}

// Méthode pour obtenir le tableau de pointeur de produit de l'attribut contenuPanier_
Produit ** Panier::obtenirContenuPanier() const
{
	return contenuPanier_;
}

// Méthode pour obtenir la valeur entière de l'attribut nombreContenu_
int Panier::obtenirNombreContenu() const
{
	return nombreContenu_;
}

// Méthode pour obtenir la valeur de l'attribut totalAPayer_
double Panier::obtenirTotalApayer() const
{
	return totalAPayer_;
}

//Méthode pour ajouter une nouvelle instance de la classe produit a contenuPanier_
void Panier::ajouter(Produit * prod)
{
	if (capaciteContenu_ == nombreContenu_)
	{
		augmenterCapaciteTableau();
	}
	contenuPanier_[nombreContenu_++] = prod;
	totalAPayer_ += prod->obtenirPrix();
}

//Méthode faisant la livraison des produits acheters qui pour ce programme agit qu'en tant que destructeur
void Panier::livrer()
{
	delete[] contenuPanier_;
	contenuPanier_ = nullptr;
	nombreContenu_ = 0;
	totalAPayer_ = 0;
}

//Méthode affichant les informations de la classe
void Panier::afficher() const
{
	cout << "Contenu du panier: prix: " << obtenirTotalApayer() << endl;

	for (int i = 0; i < nombreContenu_; i++)
	{
		contenuPanier_[i]->afficher();
	};
}

//Méthode doublant la capacité de tousProduits_ 
void Panier::augmenterCapaciteTableau()
{
	capaciteContenu_ *= 2;
	Produit** temp = new Produit*[capaciteContenu_];
	for (int i = 0; i < nombreContenu_; ++i)
	{
		temp[i] = contenuPanier_[i];
	}
	delete[] contenuPanier_;
	contenuPanier_ = temp;
}
