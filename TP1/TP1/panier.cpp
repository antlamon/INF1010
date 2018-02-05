/**************************************************
* Titre: Travail pratique #1 - Panier.cpp
* Date: 4 f�vrier 2018
* Auteur: Fr�d�ric Fortin(1900664) et Antoine Lamontagne(1907605)
Classe contenant les diff�rents produits que le client � l'intention d'acheter et permet l'achat de ces derniers.
**************************************************/
#include "panier.h"

//Constructeur par param�tre
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

// M�thode pour obtenir le tableau de pointeur de produit de l'attribut contenuPanier_
Produit ** Panier::obtenirContenuPanier() const
{
	return contenuPanier_;
}

// M�thode pour obtenir la valeur enti�re de l'attribut nombreContenu_
int Panier::obtenirNombreContenu() const
{
	return nombreContenu_;
}

// M�thode pour obtenir la valeur de l'attribut totalAPayer_
double Panier::obtenirTotalApayer() const
{
	return totalAPayer_;
}

//M�thode pour ajouter une nouvelle instance de la classe produit a contenuPanier_
void Panier::ajouter(Produit * prod)
{
	if (capaciteContenu_ == nombreContenu_)
	{
		augmenterCapaciteTableau();
	}
	contenuPanier_[nombreContenu_++] = prod;
	totalAPayer_ += prod->obtenirPrix();
}

//M�thode faisant la livraison des produits acheters qui pour ce programme agit qu'en tant que destructeur
void Panier::livrer()
{
	delete[] contenuPanier_;
	contenuPanier_ = nullptr;
	nombreContenu_ = 0;
	totalAPayer_ = 0;
}

//M�thode affichant les informations de la classe
void Panier::afficher() const
{
	cout << "Contenu du panier: prix: " << obtenirTotalApayer() << endl;

	for (int i = 0; i < nombreContenu_; i++)
	{
		contenuPanier_[i]->afficher();
	};
}

//M�thode doublant la capacit� de tousProduits_ 
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
