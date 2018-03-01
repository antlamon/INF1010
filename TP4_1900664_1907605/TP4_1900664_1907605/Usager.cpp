/********************************************
* Titre: Travail pratique #4 - Usager.cpp
* Date: 1 mars 2018
* Auteur: Frédéric Fortin 1900664 Antoine Lamontagne 1907605
*******************************************/
#include "Usager.h"
#include <iostream>

Usager::Usager(const string &nom, const string &prenom, int identifiant,
               const string &codePostal)
    : nom_(nom),
      prenom_(prenom),
      identifiant_(identifiant),
      codePostal_(codePostal)
{
}

string Usager::obtenirNom() const
{
    return nom_;
}

string Usager::obtenirPrenom() const
{
    return prenom_;
}

int Usager::obtenirIdentifiant() const
{
    return identifiant_;
}

string Usager::obtenirCodePostal() const
{
    return codePostal_;
}

//Une usager n'a pas de panier, donc rien a payer
double Usager::obtenirTotalAPayer() const
{
	return 0;
}

//Affiche le nom, prenom, identifiant et code postal d'un client.
void Usager::afficherProfil() const
{
	cout << "\t" << nom_ << ", " << prenom_ << " (" << identifiant_ << ")" << endl
		<< "\t\t" << "code postal:\t" << codePostal_ << endl;
}

void Usager::modifierNom(const string &nom)
{
    nom_ = nom;
}

void Usager::modifierPrenom(const string &prenom)
{
    prenom_ = prenom;
}

void Usager::modifierIdentifiant(int identifiant)
{
    identifiant_ = identifiant;
}

void Usager::modifierCodePostal(const string &codePostal)
{
    codePostal_ = codePostal;
}

bool Usager::operator==(const Usager & usager) const
{
	return identifiant_ == usager.obtenirIdentifiant();
}
