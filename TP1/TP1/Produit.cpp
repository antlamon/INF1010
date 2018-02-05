/**************************************************
* Titre: Travail pratique #1 - Produit.cpp
* Date: 4 février 2018
* Auteur: Frédéric Fortin(1900664) et Antoine Lamontagne(1907605)
Classe représentant les différents produits en vente sur le site
**************************************************/
#include "client.h"

//Constructeur par paramètre
Produit::Produit(string nom, int reference, double prix)
	:nom_(nom), reference_(reference), prix_(prix){}

// Méthode pour obtenir la chaine de l'attribut nom_
string Produit::obtenirNom() const
{
	return nom_;
}

// Méthode pour obtenir la valeur entière de l'attribut reference_
int Produit::obtenirReference() const
{
	return reference_;
}

// Méthode pour obtenir la valeur de l'attribut prix_
double Produit::obtenirPrix() const
{
	return prix_;
}

// Méthode pour modifier nom_
void Produit::modifierNom(string nom)
{
	nom_ = nom;
}

// Méthode pour modifier reference_
void Produit::modifierReference(int reference)
{
	reference_ = reference;
}

// Méthode pour modifier prix_
void Produit::modifierPrix(double prix)
{
	prix_ = prix;
}

//Méthode affichant les informations de la classe
void Produit::afficher() const
{
	cout << "\t" << "Produit: " << obtenirNom() << "\t" << "reference: " << obtenirReference() << "\t" << "prix: " << obtenirPrix() << endl;
}
