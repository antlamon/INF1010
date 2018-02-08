/**************************************************
* Titre: Travail pratique #2 - Main.cpp
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothée CHAUVIN
**************************************************/

#include "Produit.h"
#include "Rayon.h"
#include "Client.h"
#include "Panier.h"
#include <string>
#include <iostream>

using namespace std;

#define NB_PRODUCTS 15

/**
*Répondez aux questions ici :
* 1/ L'utilité de l'opérateur = et du constructeur par copie est d'associer les mêmes valeurs d'une instance à l'autre en évitant de simplement copier la référence d'un objet ou de ses paramètres 
	 pour que chacun puisse ensuite modifer leurs propres valeurs sans affecter l'autre.
* 2/ Il est nécessaire d'implémenter le constructeur par copie et l'opérateur = losrsqu'un des attributs de l'objet est de type référence. (reference type vs value type).
* 3/ L'opérateur = permet d'associer les valeurs d'un objet existant à un autre objet existant alors que le constructeur par copie permet de construire un nouvel objet en utilisant un objet existant.
**/

int main()
{
	Produit* unProduit = new Produit();
	// Faire saisir à l'utilisateur les attributs du produit unProduit selon le format de la capture d'écran de l'énoncé
	cout << "Saisissez les attributs pour un produit : ";
	cin >> *unProduit;

	// Afficher le Produit unProduit
	cout << "Le produit saisie est " << *unProduit << endl;

	// Creation de 15 produits
	Produit * produits[NB_PRODUCTS];
	double echantillonPrix[NB_PRODUCTS] = { 12.56, 50.0, 34.0, 56.0, 77.0, 91.0, 21.0, 34.0, 88.0, 65.0, 42.0, 72.0, 82.0, 53.0, 68.0 };

	for (int i = 0; i < NB_PRODUCTS; i++)
		produits[i] = new Produit("p" + to_string(i), i, echantillonPrix[i]);

	// Modification du nom, de la référence, du prix du troisieme produit créé
	produits[2]->modifierNom("p20");
	produits[2]->modifierPrix(100);
	produits[2]->modifierReference(31);

	cout << "Le produit p20 est moins cher que le produit p1 ? ";
	// Comparer le prix du produit p20 et p1 à l'aide de la surcharge d'un operateur
	cout << boolalpha << (*produits[2] < *produits[1]) << endl;
	// Cration d'un rayon sport
	Rayon sport;

	// Modification la catégorie  du rayon
	sport.modifierCategorie("sport");

	// Ajoutez les 10 premiers produits de dans le rayon créé
	for (int i = 0; i < 10; i++)
	{
		sport += produits[i];
	}
	// Ajoutez encore une fois le produit p0 dans le rayon sport
	sport += produits[0];

	// Affichez le contenu du rayon
	cout << sport << endl;
	// Affichez le nombre de doublons du premier produit dans le rayon sport
	cout << "Nombre de doublons du produits p0 : " << sport.compterDoublons(*produits[0]) << endl;
	// Creation d'un client
	Client martine("Bellaiche", "Martine", 1111, "H2T3A6", 199004);

	// Martine achète les 5 derniers porduits
	for (int i = NB_PRODUCTS -1; i >= NB_PRODUCTS-5 ; i--)
	{
		martine.acheter(produits[i]);
	}
	// Copie du client martine dans un autre client puis changment de son nom, prenom et identifiant pour "Paul Martin 689"
	Client paul = martine;
	paul.modifierNom("Martin");
	paul.modifierPrenom("Paul");
	paul.modifierIdentifiant(689);

	cout << "Test identifiant paul: " << boolalpha << (689 == paul) << endl << endl;

	// Paul achete le produit p0
	paul.acheter(produits[0]);

	// Livrez le panier de Paul
	paul.livrerPanier();

	// Affichez le panier de Paul et de Martine
	cout << paul << endl <<martine;

	// Afichez le produit le plus cher du panier de martine
	cout << "Le produit le plus cher que Martine ait achete est :" << endl << *martine.obtenirPanier()->trouverProduitPlusCher() << endl;

	// Terminer le programme correctement
	for (int i = 0; i < NB_PRODUCTS; i++)
	{
		if (produits[i] != nullptr)
		{
			delete produits[i];
			produits[i] = nullptr;
		}
	}
	delete unProduit;
	unProduit = nullptr;
}
