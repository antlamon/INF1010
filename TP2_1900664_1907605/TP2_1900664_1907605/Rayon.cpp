/********************************************
* Titre: Travail pratique #2 - Rayon.cpp
* Date: 25 janvier 2018
* Auteur: Timoth�e CHAUVIN
*******************************************/
/**************************************************
* Titre: Travail pratique #2 - Rayon.cpp
* Date: 8 février 2018
* Auteur: Frédéric Fortin(1900664) et Antoine Lamontagne(1907605)
* Classe qui représente un rayon d'un magasin quelconque.
**************************************************/

#include "Rayon.h"

//Constructeur utilisant la catégorie du rayon.
Rayon::Rayon(const string& cat) :
	categorie_{ cat },
	capaciteProduits_{ 0 },
	nombreProduits_{ 0 }
{
}

Rayon::~Rayon()
{
	
}

// Methodes d'acces
string Rayon::obtenirCategorie() const
{
	return categorie_;
}

vector<Produit*> Rayon::obtenirTousProduits() const
{
	return tousProduits_;
}

int Rayon::obtenirCapaciteProduits() const
{
	return capaciteProduits_;
}

int Rayon::obtenirNombreProduits() const
{
	return tousProduits_.size();
}

// Methodes de modification
void Rayon::modifierCategorie(const string& cat)
{
	categorie_ = cat;
}

// Surcharge de l'opérateur += pour ajouter facilement un produit au rayon.
Rayon& Rayon::operator+=(Produit * prod)
{
	tousProduits_.push_back(prod);
	capaciteProduits_ = tousProduits_.capacity();
	return *this;
}

// Compte le nombre d'occurence d'un produit dans la liste de produit du rayon.
int Rayon::compterDoublons(const Produit & produit)
{
	int nbDoublons = 0;
	for (int i = 0; i < tousProduits_.size(); i++)
	{
		if (produit == *tousProduits_[i])
			++nbDoublons;
	}
	return nbDoublons;
}

// Surcharge de l'opérateur << pour permettre l'affichage d'un rayon.
ostream & operator<<(ostream & cout, const Rayon & rayon)
{
	cout << "Le rayon " << rayon.categorie_ << ": " << endl;
	for (int i = 0; i < rayon.obtenirNombreProduits(); i++)
	{
		cout << "----> "
			<< *rayon.tousProduits_[i] << endl;
	}

	return cout;
}
