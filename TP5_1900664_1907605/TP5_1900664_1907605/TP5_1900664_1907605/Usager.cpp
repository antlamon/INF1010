/***
* Titre: Travail pratique #5 - Usager.cpp
* Date:  9 avril 2018
* Auteur: Frederic Fortin 1900664 & Antoine Lamontagne 1907605
***/
#include "Usager.h"
#include <iostream>

//Constructeur par parametres
Usager::Usager(const string &nom, const string &prenom, int identifiant,
               const string &codePostal)
    : nom_(nom),
      prenom_(prenom),
      reference_(identifiant),
      codePostal_(codePostal)
{
}

//Obtient le nom de l'usager
string Usager::obtenirNom() const
{
    return nom_;
}

//Obtient le prenom de l'usager
string Usager::obtenirPrenom() const
{
    return prenom_;
}

//Obtient le numero de reference de l'usager
int Usager::obtenirReference() const
{
    return reference_;
}

//Obtient le code postal de l'usager
string Usager::obtenirCodePostal() const
{
    return codePostal_;
}

//Obtient le total a payer d'un usager (0 puisque ce n'est pas un client ou un fournisseur)
double Usager::obtenirTotalAPayer() const
{
    return 0;
}

//Affiche le nom, prenom, numero de reference et le code postal d'un usager
void Usager::afficher() const
{
    cout << "\t" << nom_ << ", " << prenom_ << " (" << reference_ << ")" << endl
        << "\t\tcode postal:\t" << codePostal_ << endl;
}

//Modifie le nom de l'usager selon le string envoye
void Usager::modifierNom(const string &nom)
{
    nom_ = nom;
}

//Modifie le prenom de l'usager selon le string envoye
void Usager::modifierPrenom(const string &prenom)
{
    prenom_ = prenom;
}

//Modifie le numero de reference de l'usager selon le nombre envoye
void Usager::modifierReference(int identifiant)
{
	reference_ = identifiant;
}

//Modifie le code postal de l'usager selon le string envoye
void Usager::modifierCodePostal(const string &codePostal)
{
    codePostal_ = codePostal;
}
