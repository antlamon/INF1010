/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include "GestionnaireGenerique.h"

// TODO : Cr�er la classe GestionnaireProduits

// TODO : M�thodes :
/*
- reinitialiserClient();
- reinitialiserFournisseur();
- afficher();
- obtenirTotalAPayer();
- obtenirTotalApayerPremium();
- trouverProduitPlusCher();
- obtenirProduitsEntre();
- obtenirProduitSuivant();
*/

class GestionnaireProduits : public GestionnaireGenerique<Produit, multimap<int, Produit*>, AjouterProduit, SupprimerProduit>
{
  public:
	  //M�thodes Publiques
	  void reinitialiserClient();
	  void reinitialiserFournisseur();
	  void afficher() const;
	  double obtenirTotalAPayer() const;
	  double obtenirTotalApayerPremium() const;
	  Produit* trouverProduitPlusCher() const;
	  vector<pair<int, Produit*>> obtenirProduitsEntre() const;
	  Produit* obtenirProduitSuivant(Produit* prod) const;
};