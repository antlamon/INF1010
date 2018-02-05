/**************************************************
* Titre: Travail pratique #1 - Produit.cpp
* Date: 4 f�vrier 2018
* Auteur: Fr�d�ric Fortin(1900664) et Antoine Lamontagne(1907605)
Classe repr�sentant les diff�rents produits en vente sur le site
**************************************************/
#include "client.h"

//Constructeur par param�tre
Produit::Produit(string nom, int reference, double prix)
	:nom_(nom), reference_(reference), prix_(prix){}

// M�thode pour obtenir la chaine de l'attribut nom_
string Produit::obtenirNom() const
{
	return nom_;
}

// M�thode pour obtenir la valeur enti�re de l'attribut reference_
int Produit::obtenirReference() const
{
	return reference_;
}

// M�thode pour obtenir la valeur de l'attribut prix_
double Produit::obtenirPrix() const
{
	return prix_;
}

// M�thode pour modifier nom_
void Produit::modifierNom(string nom)
{
	nom_ = nom;
}

// M�thode pour modifier reference_
void Produit::modifierReference(int reference)
{
	reference_ = reference;
}

// M�thode pour modifier prix_
void Produit::modifierPrix(double prix)
{
	prix_ = prix;
}

//M�thode affichant les informations de la classe
void Produit::afficher() const
{
	cout << "\t" << "Produit: " << obtenirNom() << "\t" << "reference: " << obtenirReference() << "\t" << "prix: " << obtenirPrix() << endl;
}
