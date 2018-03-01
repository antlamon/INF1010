/********************************************
* Titre: Travail pratique #4 - Fournisseur.cpp
* Date: 1 mars 2018
* Auteur: Fr�d�ric Fortin 1900664 Antoine Lamontagne 1907605
*******************************************/
#include "ProduitSolde.h"

//Constructeur par parm�tre assignant le param�tre pourcentageRabais � son attribut
//correspondant et appelle le constructeur par d�faut de Produit
ProduitSolde::ProduitSolde(int pourcentageRabais)
    : Produit(),
      Solde(pourcentageRabais)
{
}


//Constructeur par param�tre passant les param�tres correspondant au contructeur
//param�trique de la classe Produit et assignant le param�tre pourcentageRabais � son attribut
//correspondant
ProduitSolde::ProduitSolde(Fournisseur *fournisseur, const string &nom,
                           int reference, double prix, int pourcentageRabais)
    : Produit(fournisseur, nom, reference, prix),
      Solde(pourcentageRabais)
{
}

//M�thode retournant le prix avec le rabais appliqu�
double ProduitSolde::obtenirPrix() const
{
	return prix_ * (100 - pourcentageRabais_) / 100;
}

//M�thode appelant l'affichage de la m�thode parent Produit et rajoutant sa sp�cificit�
// du rabais
void ProduitSolde::afficher() const
{
	Produit::afficher();
	cout << "\t\trabais:\t\t" << pourcentageRabais_ << '%' << endl;
}
