/********************************************
* Titre: Travail pratique #2 - Produit.cpp
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothee CHAUVIN
*******************************************/
/**************************************************
* Titre: Travail pratique #2 - Produit.cpp
* Date: 8 février 2018
* Auteur: Frédéric Fortin(1900664) et Antoine Lamontagne(1907605)
* Classe représentant un produit dans un certain magasin. 
**************************************************/

#include "Produit.h"

// Constructeur
Produit::Produit(const string& nom, int reference, double prix) :
	nom_{ nom },
	reference_{ reference },
	prix_{ prix }
{ }

// Methodes d'acces
string Produit::obtenirNom() const
{
	return nom_;
}

int Produit::obtenirReference() const
{
	return reference_;
}

double Produit::obtenirPrix() const
{
	return prix_;
}


// Methodes de modification
void Produit::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Produit::modifierReference(int reference)
{
	reference_ = reference;
}

void Produit::modifierPrix(double prix)
{
	prix_ = prix;
}

// Surcharge de l'opérateur > pour comparer le prix de deux produit.
bool Produit::operator>(const Produit & prod) const
{
	return obtenirPrix() > prod.obtenirPrix();
}

// Surcharge de l'opérateur < pour comparer le prix de deux produit.
bool Produit::operator<(const Produit & prod) const
{
	return obtenirPrix() < prod.obtenirPrix();
}

// Surcharge de l'opérateur  == pour comparer les valeurs des attributs de deux objets
bool Produit::operator==(const Produit & prod) const
{
	return obtenirNom() == prod.obtenirNom() && obtenirPrix() == prod.obtenirPrix() && obtenirReference() == prod.obtenirReference();
}

// Surcharge de l'opérateur >> pour modifier les valeurs d'un produit.
istream & operator>>(istream & cin,  Produit & prod)
{
	cin >> prod.nom_ >> prod.reference_ >> prod.prix_;
	return cin;
}

// Surcharge de l'opérateur >> pour permettre l'affichage d'un produit.
ostream & operator<<(ostream & cout, const Produit & prod)
{
	cout << "nom : " << prod.obtenirNom()
		<< "\t ref : " << prod.obtenirReference()
		<< "\t prix : " << prod.obtenirPrix();
	return cout;
}
