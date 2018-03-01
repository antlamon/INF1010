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
    void afficherProfil() const;

    void modifierNom(const string &nom);
    void modifierPrenom(const string &prenom);
    void modifierIdentifiant(int identifiant);
    void modifierCodePostal(const string &codePostal);
    void reinitialiser();
    void ajouterProduit(Produit *produit);
    void enleverProduit(Produit *produit);

  private:
    string nom_;
    string prenom_;
    int identifiant_;
    string codePostal_;
};

#endif
