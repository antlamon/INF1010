#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include "Usager.h"
#include "ProduitAuxEncheres.h"
#include "GestionnaireProduits.h"

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
    multimap<int, Produit *> obtenirPanier() const;
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

#endif
