/**************************************************
* Titre: Travail pratique #3 - main.cpp
* Date: 15 fevrier 2017
* Auteur: Frédéric Fortin 1900664 Antoine Lamontagne 1907605
**************************************************/

#include "Fournisseur.h"
#include "ProduitOrdinaire.h"
#include "ProduitAuxEncheres.h"
#include "Client.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int  NB_PRODUCTS = 15;

/**
*Répondez aux questions ici :
* 1/Car tous deux, étant des produits, partage différents attributs commun à tous les produits(prix,nom, type,etc.). Cependant, leur spécificité sont différents l'un de l'autre.
Ainsi, les dériver de produits permet d'unir leur attribut commun sous la classe Produit et de garder leur spécificité dans leur classe.
* 2/
* 2.1 Car chaque dérivation différentes de la classe Produit à sa propre surcharge spécifique de l'opérateur. Ainsi, le typecast est important pour s'assurer que cela soit la bonne surcharge
d'opérateur qui soit appelé pour chacun des produits dans le panier qui peut contenir tout les types de Produits.
* 2.2 Sans précision sur le type, étant donné que le panier base sa liste de produit sur un vector<Produit>, pour chacun des produits, il appelera la surcharge de l'oppérateur << de la Classe Produit
peu importe que cela soit un Produit, un ProduitOrdinaire ou un ProduitAuxEncheres.
**/

int main()
{
	cout << boolalpha << setprecision(2) << fixed;
	// Creez un objet de classe client à l'aide du constructeur
	Client martine("Bellaiche", "Martine", 1111, "H2T3A6", 199004);

	// creez un objet de la classe client à l'aide du constructeur de copie
	// et modifier sonm identifiant
	Client maCopie(martine);
	maCopie.modifierIdentifiant(777);

	// vérifier si les copies sont identiques;

	if (maCopie == martine)
		cout << "clients identitiques" << endl;
	else
		cout << "non Identiques " << endl;

	Client unAutreClient("Client", "autre", 2222, "h3T3A7", 20180212);
	unAutreClient = maCopie;

	cout << unAutreClient;

	// Creez un fournisseur
	Fournisseur poly = Fournisseur("Ecole", "Polytechnique", 123456789, "H3T 1J4");
	// afficher le fournisseur
	cout << poly;
	// Creation de 15 Produits Ordinaire
	ProduitOrdinaire* produits[NB_PRODUCTS];
	double echantillonPrix[NB_PRODUCTS] =
	{ 12.56, 50.0, 34.0, 56.0, 77.0, 91.0, 21.0, 34.0, 88.0, 65.0, 42.0, 72.0, 82.0, 53.0, 68.0 };
	for (int i = 0; i < NB_PRODUCTS; i++)
		produits[i] = new ProduitOrdinaire(poly, "p" + to_string(i), i, echantillonPrix[i], TypeProduitOrdinaire, true);

	// Creez un produit aux encheres
	ProduitAuxEncheres* prodAuxEncheres = new ProduitAuxEncheres(poly, "pAuxEncheres", 20,
		100, TypeProduitAuxEncheres);

	// Le client achete les 7 premiers porduits
	for (int i = 0; i < 7; i++)
		martine.acheter(produits[i]);

	// Afficher Panier du client
	cout << martine;

	// afficher le fournisseur
	cout << poly;

	// Client mise sur le produit aux encheres 
	martine.miserProduit(prodAuxEncheres, 500);

	// afficher le produit aux enchères
	cout << *prodAuxEncheres << endl;

	// Ma copie mise aussi  sur le produit  aux enchères
	maCopie.miserProduit(prodAuxEncheres, 555);

	// afficher le produit aux enchères
	cout << *prodAuxEncheres << endl;

	// Afficher Panier du client
	cout << martine << endl;

	// trouver le produit le plus cher du panier
	cout << " Produit le plus cher "<< *martine.obtenirPanier()->trouverProduitPlusCher() << endl;
	
	// livrer le panier du client martine
	martine.livrerPanier();

	// Afficher le fournisseur
	cout << poly << endl;
	
	// Nettoyer la memoire 
	for (int i = 0; i < NB_PRODUCTS;i++) {
		delete produits[i];
	}
	delete prodAuxEncheres;
	
}
