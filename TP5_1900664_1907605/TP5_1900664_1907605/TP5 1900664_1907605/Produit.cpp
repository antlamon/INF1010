/***
* Titre: Travail pratique #5 - Produit.cpp
* Date:  9 avril 2018
* Auteur: Frederic Fortin 1900664 & Antoine Lamontagne 1907605
***/
#include "Produit.h"
#include "Fournisseur.h"
#include <iostream>

//Constructeur par parametres d'un produit qui initialise un produit complet
Produit::Produit(Fournisseur * fournisseur, const string &nom, int reference, double prix)
    : fournisseur_(fournisseur),
      nom_(nom),
      reference_(reference),
      prix_(prix)
{
    if (fournisseur_ != nullptr)
        fournisseur_->ajouterProduit(this);
}

//Obtient le nom du produit
string Produit::obtenirNom() const
{
    return nom_;
}

//Obtient le numero de reference d'un produit
int Produit::obtenirReference() const
{
    return reference_;
}

//Obtient le prix d'un produit
double Produit::obtenirPrix() const
{
    return prix_;
}

//Obtient le fournisseur d'un produit
Fournisseur *Produit::obtenirFournisseur() const
{
    return fournisseur_;
}

//Affiche un produit selon son nom, sa reference, son prix et son fournisseur
void Produit::afficher() const
{
    cout << "\t" << nom_ << endl
         << "\t\treference:\t" << reference_ << endl
         << "\t\tprix:\t\t" << "$" << prix_ << endl;
    if (fournisseur_ != nullptr)
        cout << "\t\tfournisseur:\t" << fournisseur_->obtenirNom() << endl;
}

//Modifie le nom d'un produit
void Produit::modifierNom(const string &nom)
{
    nom_ = nom;
}

//Modifie la reference d'un produit
void Produit::modifierReference(int reference)
{
    reference_ = reference;
}

//Modifie le prix d'un produit
void Produit::modifierPrix(double prix)
{
    prix_ = prix;
}

//Modifie le fournisseur d'un produit
void Produit::modifierFournisseur(Fournisseur *fournisseur)
{
    fournisseur_ = fournisseur;
}
