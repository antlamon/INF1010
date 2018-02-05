//  panier.cpp
//  Created by Martine Bellaiche on 18-01-22.
//  Copyright © 2018 Martine Bellaiche. All rights reserved.
//
/********************************************
* Titre: Travail pratique #1 -panier.h
* Date: 25 janvier 2018
* Auteur: Frédéric Fortin(1900664) et Antoine Lamontagne(1907605)
*******************************************/

#include <string>
#include "Produit.h"

#ifndef PANIER_H
#define PANIER_H
class Panier
{
public:
	// Constructeurs par defaut et par parametres
    Panier(int capacite);
	~Panier();

    // methodes d'accès
    Produit **  obtenirContenuPanier() const;
    int obtenirNombreContenu() const;
    double obtenirTotalApayer() const;
    
    // méthodes de modification
    
    // autres méthodes
    void ajouter ( Produit * prod);
    void livrer();
    void afficher() const;

private:
	// Attributs prives
    Produit ** contenuPanier_;
    int  nombreContenu_;
    int capaciteContenu_;
    double totalAPayer_;

	//Méthodes privés
	void augmenterCapaciteTableau();
};

#endif

