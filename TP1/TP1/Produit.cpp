#include "client.h"

Produit::Produit(string nom, int reference, double prix)
	:nom_(nom), reference_(reference), prix_(prix){}

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

void Produit::modifierNom(string nom)
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

void Produit::afficher() const
{
	cout << "\t" << "Produit: " << obtenirNom() << "\t" << "reference: " << obtenirReference() << "\t" << "prix: " << obtenirPrix() << endl;
}
