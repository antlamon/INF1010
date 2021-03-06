/********************************************
* Titre: Travail pratique #2 - Client.h
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothée CHAUVIN
*******************************************/
/**************************************************
* Titre: Travail pratique #2 - Client.h
* Date: 8 février 2018
* Auteur: Frédéric Fortin(1900664) et Antoine Lamontagne(1907605)
**************************************************/

#pragma once

#include <string>
#include "Panier.h"

using namespace std;

class Client
{

public:
	Client(const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date);
	Client(const Client& client);
	~Client();

	// TODO: Ajouter un constructeur par copie si necessaire

	string obtenirNom() const;
	string obtenirPrenom() const;
	int obtenirIdentifiant() const;
	string obtenirCodePostal() const;
	long obtenirDateNaissance() const;
	Panier* obtenirPanier() const;

	void modifierNom(const string& nom);
	void modifierPrenom(const string& prenom);
	void modifierIdentifiant(int identifiant);
	void modifierCodePostal(const string& codePostal);
	void modifierDateNaissance(long date);

	// Adapter l'implementation de la methode acheter si besion
	void acheter(Produit * prod);
	void livrerPanier();

	// TODO: Surcharger l'operateur d'affectation =
	Client& operator=(const Client& client);
	// TODO: Surcharger l'operateur == (client == identifiant)
	bool operator==(const int& id) const;

	// TODO: Surcharger l'operateur == (identifiant == client)
	friend bool operator==(const int& id, const Client& client);
	// TODO: Cette methode doit être remplacée par la surcharge de l'opérateur <<
	friend ostream& operator<<(ostream& cout, const Client& client);


private:
	string nom_;
	string prenom_;
	int identifiant_;
	string codePostal_;
	long dateNaissance_;
	Panier *  monPanier_;

};
