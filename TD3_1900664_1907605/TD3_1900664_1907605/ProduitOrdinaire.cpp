/********************************************
* Titre: Travail pratique #3 - ProduitOrdinaire.h
* Date: 15 fevrier 2017
* Auteur: Fr�d�ric Fortin 1900664 Antoine Lamontagne 1907605
*******************************************/


#include <string>
#include <iostream>
#include "ProduitOrdinaire.h"
#include "Fournisseur.h"
using namespace std;

ProduitOrdinaire::ProduitOrdinaire(Fournisseur & fournisseur, const string & nom, int reference, double prix, TypeProduit type, bool estTaxable)
	:Produit(fournisseur, nom, reference, prix, type), estTaxable_(estTaxable)
{

}

bool ProduitOrdinaire::obtenirEstTaxable() const
{
	return estTaxable_;
}

void ProduitOrdinaire::modifierEstTaxable(bool estTaxable)
{
	estTaxable_ = estTaxable;
}

ostream & operator<<(ostream & os, const ProduitOrdinaire & produit)
{
	os << "Produit Ordinaire " << static_cast<Produit>(produit) << " \t \t est taxable : " << produit.obtenirEstTaxable() << endl;
	return os;
}

istream & operator>>(istream & is, ProduitOrdinaire & produit)
{
	return is >> static_cast<Produit&>(produit) >> produit.estTaxable_;
}
