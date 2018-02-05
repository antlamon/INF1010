
//  client.h
//  Created by Martine Bellaiche on 18-01-22.
//  Copyright © 2018 Martine Bellaiche. All rights reserved.
//
/********************************************
* Titre: Travail pratique #1 -client.h
* Date: 25 janvier 2018
* Auteur: Frédéric Fortin(1900664) et Antoine Lamontagne(1907605)
*******************************************/

#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include "panier.h"
using namespace std;
class Client
{
public:
	// Constructeurs par parametres
    Client (string  nom,  string prenom, int identifiant, string codePostal,  long date);

    // methodes d'acces
    string obtenirNom() const;
    string obtenirPrenom() const;
    int obtenirIdentifiant() const;
    string obtenirCodePostal() const;
    long obtenirDateNaissance() const;
    
    // methodes de modification
    void modifierNom(string nom) ;
    void modifierPrenom(string prenom) ;
    void modifierIdentifiant(int identifiant) ;
    void modifierCodePostal(string codePostal);
    void modifierDateNaissance(long date);
    
    // autres méthodes
    void acheter (Produit * prod);
    void afficherPanier();
    void livrerPanier();
    
private:
    
	// Attributs prives
    string nom_;
    string prenom_;
    int identifiant_;
    string codePostal_;
    long dateNaissance_;
    Panier *  monPanier_;
};
#endif /* client_h */
