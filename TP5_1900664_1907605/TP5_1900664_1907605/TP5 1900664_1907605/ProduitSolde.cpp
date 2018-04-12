/***
* Titre: Travail pratique #5 - ProduitSolde.cpp
* Date:  9 avril 2018
* Auteur: Frederic Fortin 1900664 & Antoine Lamontagne 1907605
***/
#include "ProduitSolde.h"
#include <cmath>

//Contructeur par parametre qui recoit le pourcentage de rabais du solde et initialise un produit nul
ProduitSolde::ProduitSolde(int pourcentageRabais)
	: Produit(), Solde(pourcentageRabais) {}

//Constructeur par parametre qui initialise un produit et une solde
ProduitSolde::ProduitSolde(Fournisseur *fournisseur, const string &nom,
                           int reference, double prix, int pourcentageRabais)
    : Produit(fournisseur, nom, reference, prix),
      Solde(pourcentageRabais)
{
}

//Obtient le prix d'un produit solde, il est arrondi pour tester l'egalite
double ProduitSolde::obtenirPrix() const
{
    return roundf(prix_ * ((100 - pourcentageRabais_) / 100.0));
}

//Affiche un produit et son pourcentage de rabais
void ProduitSolde::afficher() const
{
    Produit::afficher();
    cout << "\t\trabais:\t\t" << pourcentageRabais_ << "%" << endl;
}
