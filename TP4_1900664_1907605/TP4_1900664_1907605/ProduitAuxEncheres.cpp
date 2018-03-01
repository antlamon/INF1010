/********************************************
* Titre: Travail pratique #4 - ProduitAuxEncheres.cpp
* Date: 1 mars 2018
* Auteur: Frédéric Fortin 1900664 Antoine Lamontagne 1907605
*******************************************/
#include "ProduitAuxEncheres.h"

ProduitAuxEncheres::ProduitAuxEncheres(double prix)
    : Produit(),
      prixInitial_(prix),
      encherisseur_(nullptr)
{
}

ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur *fournisseur, const string &nom,
                                       int reference, double prix)
    : Produit(fournisseur, nom, reference, prix),
      prixInitial_(prix),
      encherisseur_(nullptr)
{
}

double ProduitAuxEncheres::obtenirPrixInitial() const
{
    return prixInitial_;
}

Client *ProduitAuxEncheres::obtenirEncherisseur() const
{
    return encherisseur_;
}

//Affiche un produit aux encheres en affichant d'abord ses elements de base.
void ProduitAuxEncheres::afficher() const
{
	Produit::afficher();
	cout << "\t\tprix initial:\t$" << prixInitial_ << endl
		<< "\t\tencherisseur:\t" << encherisseur_->obtenirNom() << endl;
}

void ProduitAuxEncheres::modifierPrixInitial(double prixInitial)
{
    prixInitial_ = prixInitial;
}

//Modifie l'encherisseur et le prix d'un produit aux encheres.
void ProduitAuxEncheres::mettreAJourEnchere(Client *encherisseur, double nouveauPrix)
{
	if (encherisseur_ != encherisseur)
	{
		modifierPrix(nouveauPrix);
		if(encherisseur != nullptr)
			encherisseur->ajouterProduit(this);
		if(encherisseur_ != nullptr)
			encherisseur_->enleverProduit(this);
		encherisseur_ = encherisseur;
	}
}
