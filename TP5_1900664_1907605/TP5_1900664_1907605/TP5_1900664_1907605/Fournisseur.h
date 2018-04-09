#pragma once

#include <string>
#include <vector>
#include "Client.h"
#include "GestionnaireUsagers.h"

using namespace std;

class Fournisseur : public Usager
{
  public:
    Fournisseur();
    Fournisseur(const string &nom, const string &prenom, int identifiant, const string &codePostal);
	~Fournisseur();

	// TODO : Modifier l'implémentation de ses méthodes : ----
	GestionnaireProduits * obtenirCatalogue() const;
    void afficherCatalogue() const;
    virtual void afficher() const;
    virtual void reinitialiser();
    virtual void ajouterProduit(Produit *produit);
    virtual void enleverProduit(Produit *produit);   
	// -------------------------------------------------------

	// TODO : implémenter les méthodes suivantes :
	Produit* trouverProduitPlusCher() const;
	void DiminuerPrix(int pourcent);

  private:
    GestionnaireProduits * gestionnaire_;
};
