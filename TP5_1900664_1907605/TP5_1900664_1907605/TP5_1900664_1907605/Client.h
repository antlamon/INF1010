#pragma once
#include "Usager.h"
#include "GestionnaireProduits.h"
#include <string>

using namespace std;

class Client : public Usager
{
  public:
    Client(unsigned int codeClient = 0);
    Client(const string &nom, const string &prenom, int identifiant, const string &codePostal, unsigned int codeClient = 0);
	~Client();

    unsigned int obtenirCodeClient() const;
	void modifierCodeClient(unsigned int codeClient);
	// TODO : Modifier ces méthodes : -------------------
	GestionnaireProduits * obtenirPanier() const;
    virtual double obtenirTotalAPayer() const;
    void afficherPanier() const;
    virtual void afficher() const;
    virtual void enleverProduit(Produit *produit);
    virtual void ajouterProduit(Produit *produit);
    virtual void reinitialiser();
	// --------------------------------------------------

	// TODO : Implémenter cette méthodes : 
	Produit* trouverProduitPlusCher() const;
  
  protected:
    GestionnaireProduits * gestionnaire_;

  private:
    unsigned int codeClient_;
};