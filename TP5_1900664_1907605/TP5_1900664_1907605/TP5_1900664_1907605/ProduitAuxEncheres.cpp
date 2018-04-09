/***
* Titre: Travail pratique #5 - ProduitAuxEncheres.cpp
* Date:  9 avril 2018
* Auteur: Frederic Fortin 1900664 & Antoine Lamontagne 1907605
***/
#include "ProduitAuxEncheres.h"

//Constructeur par parametre qui initialise un produit ayant seulement un prix
ProduitAuxEncheres::ProduitAuxEncheres(double prix)
    : Produit(),
      prixInitial_(prix),
      encherisseur_(nullptr)
{
}

//Constructeur par parametre qui initialise un produit aux encheres
ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur *fournisseur, const string &nom,
                                       int reference, double prix)
    : Produit(fournisseur, nom, reference, prix),
      prixInitial_(prix),
      encherisseur_(nullptr)
{
}

//Obtient le prix initial du produit aux encheres
double ProduitAuxEncheres::obtenirPrixInitial() const
{
    return prixInitial_;
}

//Obtient l'enrichisseur du produit aux encheres
Client *ProduitAuxEncheres::obtenirEncherisseur() const
{
    return encherisseur_;
}

//Affiche un produit et le prix initial et l'enrichisseur d'un produit aux encheres
void ProduitAuxEncheres::afficher() const
{
    Produit::afficher();
    cout << "\t\tprix initial:\t" << prixInitial_ << endl
         << "\t\tencherisseur:\t" << encherisseur_->obtenirNom() << endl;
}

//Modifie le prix initial d'un produit aux encheres
void ProduitAuxEncheres::modifierPrixInitial(double prixInitial)
{
    prixInitial_ = prixInitial;
}

//Modifie l'enrichisseur d'un produit aux encheres
void ProduitAuxEncheres::modifierEncherisseur(Client *encherisseur)
{
    encherisseur_ = encherisseur;
}

//Met a jour l'enchere sur un produit selon un nouvel encherisseur et un prix plus eleve
void ProduitAuxEncheres::mettreAJourEnchere(Client *encherisseur, double nouveauPrix)
{
    if (encherisseur_ == encherisseur)
        return;
    prix_ = nouveauPrix;
    encherisseur->ajouterProduit(this);
    if (encherisseur_ != nullptr)
        encherisseur_->enleverProduit(this);
    encherisseur_ = encherisseur;
}
