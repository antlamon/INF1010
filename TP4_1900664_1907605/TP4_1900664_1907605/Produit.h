#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>

using namespace std;

class Fournisseur;

class Produit
{
  public:
    Produit(Fournisseur *fournisseur = nullptr, const string &nom = "outil",
            int reference = 0, double prix = 0.0);

    string obtenirNom() const;
    int obtenirReference() const;
	//Virtual pour appliquer un solde.
    virtual double obtenirPrix() const;
    Fournisseur *obtenirFournisseur() const;
	//Virtual pour permettre l'affichage de differents produits
    virtual void afficher() const;

    void modifierNom(const string& nom);
    void modifierReference(int reference);
    void modifierPrix(double prix);
    void modifierFournisseur(Fournisseur *fournisseur);
	bool operator==(const Produit& prod);

  private:
    Fournisseur *fournisseur_;
    string nom_;
    int reference_;

  protected:
    double prix_;
};

#endif
