/********************************************
* Titre: Travail pratique #2 -Rayon.h
* Date: 25 janvier 2018
* Auteur: Timothée CHAUVIN
*******************************************/

#pragma once

#include <string>
#include <vector>
#include "Produit.h"

using namespace std;

class Rayon
{

public:
	Rayon(const string& cat = "inconnu");
	~Rayon();

	string obtenirCategorie() const;
	vector<Produit*> obtenirTousProduits() const;
	int obtenirCapaciteProduits() const;
	int obtenirNombreProduits() const;

	void modifierCategorie(const string& cat);

	// TODO: Cette methode doit etre remplacee par la surchage de l'operateur +=
	Rayon& operator+=(Produit* prod);
	// TODO: Implermenter la methode compterDoublons
	int compterDoublons(const Produit& produit);

	// TODO: Cette methode doit être remplacee par la surcharge de l'opérateur <<
	friend ostream& operator<<(ostream& cout, const Rayon& rayon);


private:
	string categorie_;

	// TODO: Remplacer ces attributs par un vecteur de la STL
	vector<Produit*>  tousProduits_;
	int capaciteProduits_;
	int nombreProduits_;

};
