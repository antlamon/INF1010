/********************************************
* Titre: Travail pratique #4 - Fournisseur.h
* Date: 1 mars 2018
* Auteur: Frédéric Fortin 1900664 Antoine Lamontagne 1907605
*******************************************/
#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <string>
#include <vector>
#include "Usager.h"
#include "Produit.h"

using namespace std;

class Fournisseur : public Usager
{
  public:
    Fournisseur();
    Fournisseur(const string &nom, const string &prenom, int identifiant, const string &codePostal);

    vector<Produit *> obtenirCatalogue() const;
    void afficherCatalogue() const;

	//Ajout du mot clé virtual pour clarifier le code.
    virtual void afficherProfil() const;

    virtual void reinitialiser();
    virtual void ajouterProduit(Produit *produit);
    virtual void enleverProduit(Produit *produit);

  private:
    vector<Produit *> catalogue_;
};

#endif
