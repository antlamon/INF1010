/********************************************
* Titre: Travail pratique #4 - Client.h
* Date: 1 mars 2018
* Auteur: Frédéric Fortin 1900664 Antoine Lamontagne 1907605
*******************************************/
#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include "Usager.h"
#include "Produit.h"

using namespace std;

class Client : public Usager
{
  public:
    Client(unsigned int codeClient = 0);
    Client(const string &nom, const string &prenom, int identifiant, const string &codePostal, unsigned int codeClient = 0);

    unsigned int obtenirCodeClient() const;
    vector<Produit *> obtenirPanier() const;
	//virtual ajoute pour modifier le total d'un client s'il est membre
    virtual double obtenirTotalAPayer() const;
    void afficherPanier() const;
	//virtual ajoute pour differencier un client et un membre
	virtual void afficherProfil() const;

    void modifierCodeClient(unsigned int codeClient);
	//Mot cle virtual pour clarifier le code
    virtual void enleverProduit(Produit *produit);
    virtual void ajouterProduit(Produit *produit);
    virtual void reinitialiser();
  
  protected:
    vector<Produit *> panier_;

  private:
    unsigned int codeClient_;
};

#endif
