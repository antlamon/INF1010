/********************************************
* Titre: Travail pratique #3 - ProduitAuxEncheres.cpp
* Date: 15 fevrier 2017
* Auteur: Frédéric Fortin 1900664 Antoine Lamontagne 1907605
*******************************************/

#include "ProduitAuxEncheres.h"

ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur & fournisseur, const string & nom, int reference, double prix, TypeProduit type)
	:Produit(fournisseur, nom, reference, prix, type)
{
	identifiantClient_ = 0;
	prixBase_ = 0;
}

int ProduitAuxEncheres::obtenirIdentifiantClient() const
{
	return identifiantClient_;
}

double ProduitAuxEncheres::obtenirPrixBase() const
{
	return prixBase_;
}

void ProduitAuxEncheres::modifierIdentifiantClient(int identifiantClient)
{
	identifiantClient_ = identifiantClient;
}

void ProduitAuxEncheres::modifierPrixBase(double prixBase)
{
	prixBase_ = prixBase;
}

istream & operator>>(istream & is, ProduitAuxEncheres & produit)
{
	return is >> static_cast<Produit&>(produit);
}

ostream & operator<<(ostream & os, const ProduitAuxEncheres & produit)
{
	os << "Produit au enchere " << static_cast<Produit>(produit)
		<< " \t \t Prix de base: " << produit.obtenirPrixBase() << endl << " \t \t Identifiant client: " << produit.obtenirIdentifiantClient() << endl;
	return os;
}
