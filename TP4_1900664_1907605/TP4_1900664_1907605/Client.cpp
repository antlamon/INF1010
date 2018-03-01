/********************************************
* Titre: Travail pratique #4 - Client.cpp
* Date: 1 mars 2018
* Auteur: Frédéric Fortin 1900664 Antoine Lamontagne 1907605
*******************************************/
#include "Client.h"
#include <iostream>
#include "ProduitAuxEncheres.h"

Client::Client(unsigned int codeClient)
    : Usager(),
      codeClient_(codeClient)
{
}

Client::Client(const string &nom, const string &prenom, int identifiant,
               const string &codePostal, unsigned int codeClient)
    : Usager(nom, prenom, identifiant, codePostal),
      codeClient_(codeClient)
{
}

unsigned int Client::obtenirCodeClient() const
{
    return codeClient_;
}

vector<Produit *> Client::obtenirPanier() const
{
    return panier_;
}

double Client::obtenirTotalAPayer() const
{
	double total = 0;
	for (Produit* prod : panier_)
	{
		total += prod->obtenirPrix();
	}
}

void Client::afficherPanier() const
{
    cout << "PANIER (de " << obtenirNom() << ")"
         << "\n";
    for (unsigned int i = 0; i < panier_.size(); i++)
        panier_[i]->afficher();
    cout << endl;
}

void Client::afficherProfil() const
{
	Usager::afficherProfil();
	cout << "\t\tcode client:\t" << codeClient_ << endl
		<< "\t\tpanier:\t" << panier_.size() << " elements" << endl;
}

void Client::modifierCodeClient(unsigned int codeClient)
{
    codeClient_ = codeClient_;
}

void Client::enleverProduit(Produit *produit)
{
    for (unsigned int i = 0; i < panier_.size(); i++)
    {
        if (panier_[i] == produit)
        {
            panier_[i] = panier_[panier_.size() - 1];
            panier_.pop_back();
            return;
        }
    }
}

void Client::ajouterProduit(Produit *produit)
{
    for (unsigned int i = 0; i < panier_.size(); i++)
        if (panier_[i] == produit)
            return;
    panier_.push_back(produit);
}

void Client::reinitialiser()
{
	for (int i = panier_.size() - 1; i <= 0; --i)
	{
		ProduitAuxEncheres* prode = dynamic_cast<ProduitAuxEncheres*>(panier_[i]);
		if (prode != nullptr)
		{
			prode->mettreAJourEnchere(nullptr, prode->obtenirPrixInitial());
		}
		panier_.pop_back();
	}
}
