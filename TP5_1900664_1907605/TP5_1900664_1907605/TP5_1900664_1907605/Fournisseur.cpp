#include "Fournisseur.h"
#include <iostream>

Fournisseur::Fournisseur()
    : Usager()
{
	gestionnaire_ = new GestionnaireProduits();
}

Fournisseur::Fournisseur(const string &nom, const string &prenom, int identifiant,
                         const string &codePostal)
    : Usager(nom, prenom, identifiant, codePostal)
{
	gestionnaire_ = new GestionnaireProduits();
}

Fournisseur::~Fournisseur()
{
	delete gestionnaire_;
}

GestionnaireProduits * Fournisseur::obtenirCatalogue() const
{
    return gestionnaire_;
}

void Fournisseur::afficherCatalogue() const
{
    cout << "CATALOGUE (de " << obtenirNom() << ")"
         << "\n";
	gestionnaire_->afficher();
    //for (unsigned int i = 0; i < catalogue_.size(); i++)
    //    catalogue_[i]->afficher();
    cout << endl;
}

void Fournisseur::afficher() const
{
    Usager::afficher();
    cout << "\t\tcatalogue:\t" << gestionnaire_->obtenirConteneur().size() << " elements" << endl;
}

void Fournisseur::reinitialiser()
{
	gestionnaire_->reinitialiserFournisseur();
	//for (unsigned int i = 0; i < catalogue_.size(); i++)
    //    catalogue_[i]->modifierFournisseur(nullptr);
}

void Fournisseur::ajouterProduit(Produit *produit)
{
    //for (unsigned int i = 0; i < catalogue_.size(); i++)
    //    if (catalogue_[i] == produit)
    //        return;
    Fournisseur *fournisseur = produit->obtenirFournisseur();
    if (fournisseur != nullptr && fournisseur != this)
        fournisseur->enleverProduit(produit);
	gestionnaire_->ajouter(produit);
}

void Fournisseur::enleverProduit(Produit *produit)
{
    produit->modifierFournisseur(nullptr);
    //for (unsigned int i = 0; i < catalogue_.size(); i++)
    //{
    //    if (catalogue_[i] == produit)
    //    {
    //        catalogue_[i] = catalogue_[catalogue_.size() - 1];
    //        catalogue_.pop_back();
    //        return;
    //    }
    //}
	gestionnaire_->supprimer(produit);
}

Produit * Fournisseur::trouverProduitPlusCher() const
{
	return gestionnaire_->trouverProduitPlusCher();
}

void Fournisseur::DiminuerPrix(int pourcent)
{
	gestionnaire_->pourChaqueElement(FoncteurDiminuerPourcent(pourcent));
}
