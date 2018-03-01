/********************************************
* Titre: Travail pratique #4 - Usager.h
* Date: 1 mars 2018
* Auteur: Frédéric Fortin 1900664 Antoine Lamontagne 1907605
*******************************************/
#ifndef USAGER_H
#define USAGER_H

#include "Produit.h"
#include <string>

using namespace std;

class Usager
{
  public:
    Usager(const string &nom = "Doe", const string &prenom = "John",
           int identifiant = 0, const string &codePostal = "A1A A1A");

    string obtenirNom() const;
    string obtenirPrenom() const;
    int obtenirIdentifiant() const;
    string obtenirCodePostal() const;
    double obtenirTotalAPayer() const;
	//Virtual pour diffencier l'affichage d'un client et d'un fournisseur.
    virtual void afficherProfil() const;

    void modifierNom(const string &nom);
    void modifierPrenom(const string &prenom);
    void modifierIdentifiant(int identifiant);
    void modifierCodePostal(const string &codePostal);
	//Ajout du mot cle virtual pour permettre de modifier les methodes pour un client et un fournisseur.
	//Virtuelle pure, car un usager n'a pas de panier, donc pas de produit.
    virtual void reinitialiser() = 0;
    virtual void ajouterProduit(Produit *produit) = 0;
	virtual void enleverProduit(Produit *produit) = 0;
	bool operator==(const Usager& usager) const;

  private:
    string nom_;
    string prenom_;
    int identifiant_;
    string codePostal_;
};

#endif
