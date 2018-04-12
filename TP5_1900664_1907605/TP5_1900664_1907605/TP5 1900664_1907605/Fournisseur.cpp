/**
* Titre: Travail pratique #5 - GestionnaireProduits.cpp
* Date:  2 avril 2018
* Auteur: Frederic Fortin 1900664 & Antoine Lamontagne 1907605
***/

#include "Fournisseur.h"
#include <iostream>

//Constructeur par défaut appelant le constructeur par défaut d'Usager et instanciant gestionnaire_
Fournisseur::Fournisseur()
    : Usager()
{
	gestionnaire_ = new GestionnaireProduits();
}


//Constructeur paramètrique recevant nom, prenom, identifiant et codePostal qui sont passés au constructeur d'Usager.
//Instancie gestionnaire_
Fournisseur::Fournisseur(const string &nom, const string &prenom, int identifiant,
                         const string &codePostal)
    : Usager(nom, prenom, identifiant, codePostal)
{
	gestionnaire_ = new GestionnaireProduits();
}

//Destructeur désallouant l'espace du pointeur de gestionnaire_
Fournisseur::~Fournisseur()
{
	delete gestionnaire_;
}

//Méthode d'accès de l'attribut gestionnaire_
GestionnaireProduits * Fournisseur::obtenirCatalogue() const
{
    return gestionnaire_;
}

//Méthode affichant les informations reliés au différents produits du catalogue du fournisseur
void Fournisseur::afficherCatalogue() const
{
    cout << "CATALOGUE (de " << obtenirNom() << ")"
         << "\n";
	gestionnaire_->afficher();
    cout << endl;
}

//Méthode affichant les informations reliés à un  fournisseur
void Fournisseur::afficher() const
{
    Usager::afficher();
    cout << "\t\tcatalogue:\t" << gestionnaire_->obtenirConteneur().size() << " elements" << endl;
}

//Méthode réinitialisant le catalogue(gestionnaire_) à son état initiale
void Fournisseur::reinitialiser()
{
	gestionnaire_->reinitialiserFournisseur();
}

//Méthode ajoutant un produit au catalogue
void Fournisseur::ajouterProduit(Produit *produit)
{
    Fournisseur *fournisseur = produit->obtenirFournisseur();
    if (fournisseur != nullptr && fournisseur != this)
        fournisseur->enleverProduit(produit);
	gestionnaire_->ajouter(produit);
}

//Méthode enlevant un produit du catalogue du fournisseur
void Fournisseur::enleverProduit(Produit *produit)
{
    produit->modifierFournisseur(nullptr);
	gestionnaire_->supprimer(produit);
}


//Méthode trouvant le produit le plus cher du fournisseur
Produit * Fournisseur::trouverProduitPlusCher() const
{
	return gestionnaire_->trouverProduitPlusCher();
}

//Diminue tous les produits du fournisseur du pourcentage passé en paramètre
void Fournisseur::DiminuerPrix(int pourcent)
{
	gestionnaire_->pourChaqueElement(FoncteurDiminuerPourcent(pourcent));
}
