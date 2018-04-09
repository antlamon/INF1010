/**
* Titre: Travail pratique #5 - GestionnaireProduits.cpp
* Date:  2 avril 2018
* Auteur: Frederic Fortin 1900664 & Antoine Lamontagne 1907605
***/

#include "Fournisseur.h"
#include <iostream>

//Constructeur par d�faut appelant le constructeur par d�faut d'Usager et instanciant gestionnaire_
Fournisseur::Fournisseur()
    : Usager()
{
	gestionnaire_ = new GestionnaireProduits();
}


//Constructeur param�trique recevant nom, prenom, identifiant et codePostal qui sont pass�s au constructeur d'Usager.
//Instancie gestionnaire_
Fournisseur::Fournisseur(const string &nom, const string &prenom, int identifiant,
                         const string &codePostal)
    : Usager(nom, prenom, identifiant, codePostal)
{
	gestionnaire_ = new GestionnaireProduits();
}

//Destructeur d�sallouant l'espace du pointeur de gestionnaire_
Fournisseur::~Fournisseur()
{
	delete gestionnaire_;
}

//M�thode d'acc�s de l'attribut gestionnaire_
GestionnaireProduits * Fournisseur::obtenirCatalogue() const
{
    return gestionnaire_;
}

//M�thode affichant les informations reli�s au diff�rents produits du catalogue du fournisseur
void Fournisseur::afficherCatalogue() const
{
    cout << "CATALOGUE (de " << obtenirNom() << ")"
         << "\n";
	gestionnaire_->afficher();
    cout << endl;
}

//M�thode affichant les informations reli�s � un  fournisseur
void Fournisseur::afficher() const
{
    Usager::afficher();
    cout << "\t\tcatalogue:\t" << gestionnaire_->obtenirConteneur().size() << " elements" << endl;
}

//M�thode r�initialisant le catalogue(gestionnaire_) � son �tat initiale
void Fournisseur::reinitialiser()
{
	gestionnaire_->reinitialiserFournisseur();
}

//M�thode ajoutant un produit au catalogue
void Fournisseur::ajouterProduit(Produit *produit)
{
    Fournisseur *fournisseur = produit->obtenirFournisseur();
    if (fournisseur != nullptr && fournisseur != this)
        fournisseur->enleverProduit(produit);
	gestionnaire_->ajouter(produit);
}

//M�thode enlevant un produit du catalogue du fournisseur
void Fournisseur::enleverProduit(Produit *produit)
{
    produit->modifierFournisseur(nullptr);
	gestionnaire_->supprimer(produit);
}


//M�thode trouvant le produit le plus cher du fournisseur
Produit * Fournisseur::trouverProduitPlusCher() const
{
	return gestionnaire_->trouverProduitPlusCher();
}

//Diminue tous les produits du fournisseur du pourcentage pass� en param�tre
void Fournisseur::DiminuerPrix(int pourcent)
{
	gestionnaire_->pourChaqueElement(FoncteurDiminuerPourcent(pourcent));
}
