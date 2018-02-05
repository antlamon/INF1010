/********************************************
* Titre: Travail pratique #1 -Rayon.h
* Date: 25 janvier 2018
* Auteur: Frédéric Fortin(1900664) et Antoine Lamontagne(1907605)
*******************************************/

#ifndef RAYON_H
#define RAYON_H

#include <string>
#include "Produit.h"
using namespace std;

class Rayon
{
public:
	// Constructeurs par defaut et par paraametres
    //Rayon();
	Rayon(string cat = "inconnu");
	~Rayon();

	// Methodes d'acces
	string obtenirCategorie() const;
	Produit ** obtenirTousProduits() const;
    int obtenirCapaciteProduits() const;
    int obtenirNombreProduits() const;
	

	// Methodes de modification
	void modifierCategorie(string cat);
    
    // autres methodes
    void ajouterProduit (Produit * produit);
    void afficher() const;

	//Constante
	const int INCREMENT_CAPACITE = 5;

private:

	// Attributs prives
	string categorie_;
    Produit ** tousProduits_;
    int capaciteProduits_;
	int nombreProduits_;

	//Méthodes privés
	void creerTableau();
	void augmenterCapaciteTableau();
};

#endif
