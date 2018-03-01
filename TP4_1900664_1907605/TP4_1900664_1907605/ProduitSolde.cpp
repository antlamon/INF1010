/********************************************
* Titre: Travail pratique #4 - Fournisseur.cpp
* Date: 1 mars 2018
* Auteur: Frédéric Fortin 1900664 Antoine Lamontagne 1907605
*******************************************/
#include "ProduitSolde.h"

//Constructeur par parmètre assignant le paramètre pourcentageRabais à son attribut
//correspondant et appelle le constructeur par défaut de Produit
ProduitSolde::ProduitSolde(int pourcentageRabais)
    : Produit(),
      Solde(pourcentageRabais)
{
}


//Constructeur par paramètre passant les paramètres correspondant au contructeur
//paramètrique de la classe Produit et assignant le paramètre pourcentageRabais à son attribut
//correspondant
ProduitSolde::ProduitSolde(Fournisseur *fournisseur, const string &nom,
                           int reference, double prix, int pourcentageRabais)
    : Produit(fournisseur, nom, reference, prix),
      Solde(pourcentageRabais)
{
}

//Méthode retournant le prix avec le rabais appliqué
double ProduitSolde::obtenirPrix() const
{
	return prix_ * (100 - pourcentageRabais_) / 100;
}

//Méthode appelant l'affichage de la méthode parent Produit et rajoutant sa spécificité
// du rabais
void ProduitSolde::afficher() const
{
	Produit::afficher();
	cout << "\t\trabais:\t\t" << pourcentageRabais_ << '%' << endl;
}
