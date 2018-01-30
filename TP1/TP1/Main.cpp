/**************************************************
* Titre: Travail pratique #1 - Main.cpp
* Date: 20 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA
**************************************************/

#include "Produit.h"
#include "Rayon.h"
#include "client.h"
#include "panier.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//C'est à vous de voir si vous devez allouer dynamiquement ou non les élèments
	cout << fixed << setprecision(2);
	//1-  Creez 15 objets de la classe produit
	Produit** produits = new Produit*[15];
	for (int i = 0; i < 15; i++)
	{
		produits[i] = new Produit(to_string(i), i, i);
	}
    
	//2-  Modifiez le nom, la référence, le prix de  troisieme objet Produit créé
    //   afficher les attributs de cet objet Produit
	produits[2]->modifierNom("Banane");
	produits[2]->modifierReference(99);
	produits[2]->modifierPrix(1.69);
	produits[2]->afficher();
	
	//3-  Creez un objet du classe rayon à l'aide du constructeur par défaut
	Rayon rayon;
	//4-  Modifiez la catégorie  du rayon
	rayon.modifierCategorie("Chiffre");
    //5- Ajouter 6 produits de  voret chaoix dans le rayon créé
	for (int i = 0; i < 6; i++)
	{
		rayon.ajouterProduit(produits[i]);
	}

    //6- afficher le contenu du rayon
	rayon.afficher();
  
	//7-  Creez un objet de classe client à l'aide du constructeur
	Client client("Fortin", "Fred", 0, "J1PO07", 199712);

	//8-  afficher l'etat des attributs du client
	cout << client.obtenirNom() << " " << client.obtenirPrenom() << " " << client.obtenirIdentifiant() << " " << client.obtenirCodePostal() << " " << client.obtenirDateNaissance() << endl;

	//9-   Le client achete 9 produits
	for (int i = 0; i < 9; i++)
	{
		client.acheter(produits[i]);
	}

	//10- Afficher le contenu du panier du client
	client.afficherPanier();

    //11- livrer le panier du client
	client.livrerPanier();
    
	//12- afficher le contenu du panier du client
	client.afficherPanier();

	//13-  terminer le programme correctement
	for (int i = 9; i < 15; i++)
	{
		if (produits[i] != nullptr)
			delete produits[i];
	}
	delete[] produits;
	produits = nullptr;
	
    return 0;
}
