#include "Client.h"
#include "ProduitAuxEncheres.h"
#include <iostream>

Client::Client(unsigned int codeClient)
    : Usager(),
      codeClient_(codeClient)
{
	gestionnaire_ = new GestionnaireProduits();
}

Client::Client(const string &nom, const string &prenom, int identifiant,
               const string &codePostal, unsigned int codeClient)
    : Usager(nom, prenom, identifiant, codePostal),
      codeClient_(codeClient)
{
	gestionnaire_ = new GestionnaireProduits();
}

Client::~Client()
{
	delete gestionnaire_;
}

unsigned int Client::obtenirCodeClient() const
{
    return codeClient_;
}

multimap<int, Produit *> Client::obtenirPanier() const
{
    return gestionnaire_->obtenirConteneur();
}

double Client::obtenirTotalAPayer() const
{
    double montant = gestionnaire_->obtenirTotalAPayer();
    //for (unsigned int i = 0; i < panier_.size(); i++)
    //    montant += panier_[i]->obtenirPrix();
    return montant;
}

void Client::afficherPanier() const
{
    cout << "PANIER (de " << obtenirNom() << ")"
         << "\n";
	gestionnaire_->pourChaqueElement<>([](Produit * prod) {prod->afficher(); });
    //for (unsigned int i = 0; i < panier_.size(); i++)
    //    panier_[i]->afficher();
    cout << endl;
}

void Client::afficher() const
{
    Usager::afficher();
    cout << "\t\tcode client:\t" << codeClient_ << endl
         << "\t\tpanier:\t\t" << gestionnaire_->obtenirConteneur().size() << " elements" << endl;
}

void Client::modifierCodeClient(unsigned int codeClient)
{
    codeClient_ = codeClient_;
}

void Client::enleverProduit(Produit *produit)
{
	gestionnaire_->supprimer(produit);
    //for (unsigned int i = 0; i < panier_.size(); i++)
    //{
    //    if (panier_[i] == produit)
    //    {
    //        panier_[i] = panier_[panier_.size() - 1];
    //        panier_.pop_back();
    //        return;
    //    }
    //}
}

void Client::ajouterProduit(Produit *produit)
{
	gestionnaire_->ajouter(produit);
    //for (unsigned int i = 0; i < panier_.size(); i++)
    //    if (panier_[i] == produit)
    //        return;
    //panier_.push_back(produit);
}

void Client::reinitialiser()
{
    //for (unsigned int i = 0; i < panier_.size(); i++)
    //{
    //    ProduitAuxEncheres *produit = dynamic_cast<ProduitAuxEncheres *>(panier_[i]);
    //    if (produit) {
    //        produit->modifierEncherisseur(nullptr);
    //        produit->modifierPrix(produit->obtenirPrixInitial());
    //    }
    //}
	gestionnaire_->reinitialiserClient();
}

Produit * Client::trouverProduitPlusCher() const
{
	return gestionnaire_->trouverProduitPlusCher();
}
