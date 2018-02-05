/**************************************************
* Titre: Travail pratique #1 - Rayon.cpp
* Date: 4 f�vrier 2018
* Auteur: Fr�d�ric Fortin(1900664) et Antoine Lamontagne(1907605)
Classe repr�sentant les diff�rents rayons du site de ventes. Contient donc une vari�t� de produits soit des instances
de la classe de m�me nom.
**************************************************/
#include "Rayon.h"

//Constructeur par param�tre
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

// M�thode pour obtenir la chaine de l'attribut categorie_
string Rayon::obtenirCategorie() const
{
	return categorie_;
}

// M�thode pour obtenir le tableau de pointeur de produit de l'attribut tousProduits_
Produit ** Rayon::obtenirTousProduits() const
{
	return tousProduits_;
}

// M�thode pour obtenir la valeur enti�re de l'attribut capaciteProduits_
int Rayon::obtenirCapaciteProduits() const
{
	return capaciteProduits_;
}

// M�thode pour obtenir la valeur enti�re de l'attribut nombreProduits_
int Rayon::obtenirNombreProduits() const
{
	return nombreProduits_;
}

// M�thode pour modifier categorie_
void Rayon::modifierCategorie(string cat)
{
	categorie_ = cat;
}

//M�thode pour ajouter une nouvelle instance de la classe produit a tousProduits_
void Rayon::ajouterProduit(Produit* produit)
{
	if (tousProduits_ == nullptr)
		creerTableau();
	if (nombreProduits_ >= capaciteProduits_)
		augmenterCapaciteTableau();
	tousProduits_[nombreProduits_++] = produit;
}

//M�thode cr�ant le tableau qu'est tousProduits_
void Rayon::creerTableau()
{
	capaciteProduits_ += INCREMENT_CAPACITE;
	tousProduits_ = new Produit*[capaciteProduits_];
}

//M�thode augmentant la capacit� de tousProduits_ de 5
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

//M�thode affichant les informations de la classe
void Rayon::afficher() const
{
	cout << "Categorie Rayon: " << obtenirCategorie() << endl;
	cout << " Produits disponibles: " << endl;
	for (int i = 0; i < nombreProduits_; ++i)
	{
		tousProduits_[i]->afficher();
	}
}