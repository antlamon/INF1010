/**************************************************
* Titre: Travail pratique #1 - Rayon.cpp
* Date: 4 février 2018
* Auteur: Frédéric Fortin(1900664) et Antoine Lamontagne(1907605)
Classe représentant les différents rayons du site de ventes. Contient donc une variété de produits soit des instances
de la classe de même nom.
**************************************************/
#include "Rayon.h"

//Constructeur par paramètre
Rayon::Rayon(string cat)
	:categorie_(cat)
{
	tousProduits_ = nullptr;
	capaciteProduits_ = 0;
	nombreProduits_ = 0;
}

//Destructeur de la classe
Rayon::~Rayon()
{
	delete[] tousProduits_;
	tousProduits_ = nullptr;
}

// Méthode pour obtenir la chaine de l'attribut categorie_
string Rayon::obtenirCategorie() const
{
	return categorie_;
}

// Méthode pour obtenir le tableau de pointeur de produit de l'attribut tousProduits_
Produit ** Rayon::obtenirTousProduits() const
{
	return tousProduits_;
}

// Méthode pour obtenir la valeur entière de l'attribut capaciteProduits_
int Rayon::obtenirCapaciteProduits() const
{
	return capaciteProduits_;
}

// Méthode pour obtenir la valeur entière de l'attribut nombreProduits_
int Rayon::obtenirNombreProduits() const
{
	return nombreProduits_;
}

// Méthode pour modifier categorie_
void Rayon::modifierCategorie(string cat)
{
	categorie_ = cat;
}

//Méthode pour ajouter une nouvelle instance de la classe produit a tousProduits_
void Rayon::ajouterProduit(Produit* produit)
{
	if (tousProduits_ == nullptr)
		creerTableau();
	if (nombreProduits_ >= capaciteProduits_)
		augmenterCapaciteTableau();
	tousProduits_[nombreProduits_++] = produit;
}

//Méthode créant le tableau qu'est tousProduits_
void Rayon::creerTableau()
{
	capaciteProduits_ += INCREMENT_CAPACITE;
	tousProduits_ = new Produit*[capaciteProduits_];
}

//Méthode augmentant la capacité de tousProduits_ de 5
void Rayon::augmenterCapaciteTableau()
{
	capaciteProduits_ += INCREMENT_CAPACITE;
	Produit** temp = new Produit*[capaciteProduits_];
	for (int i = 0; i < nombreProduits_; ++i)
	{
		temp[i] = tousProduits_[i];
	}
	delete[] tousProduits_;
	tousProduits_ = temp;
}

//Méthode affichant les informations de la classe
void Rayon::afficher() const
{
	cout << "Categorie Rayon: " << obtenirCategorie() << endl;
	cout << " Produits disponibles: " << endl;
	for (int i = 0; i < nombreProduits_; ++i)
	{
		tousProduits_[i]->afficher();
	}
}