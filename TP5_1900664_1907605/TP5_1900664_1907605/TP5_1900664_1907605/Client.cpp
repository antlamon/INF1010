/**
* Titre: Travail pratique #5 - Client.cpp
* Date:  2 avril 2018
* Auteur: Frederic Fortin 1900664 & Antoine Lamontagne 1907605
***/

#include "Client.h"
#include <iostream>

//Constructeur paramétrique recevant le codeClient. Il appelle le constructeur par défaut de la classe Usager
//et instancie le gestionnaire_.
Client::Client(unsigned int codeClient)
    : Usager(),
      codeClient_(codeClient)
{
	gestionnaire_ = new GestionnaireProduits();
}


//Constructeur parametrique recevant nom, prenom, identifiant et codePostal qui sont passé au constructeur Usager les prenant
// et le codeClient. Instancie le gestionnaire_.
Client::Client(const string &nom, const string &prenom, int identifiant,
               const string &codePostal, unsigned int codeClient)
    : Usager(nom, prenom, identifiant, codePostal),
      codeClient_(codeClient)
{
	gestionnaire_ = new GestionnaireProduits();
}


//Destructeur désallouant l'espace pris par le pointeur du gestionnaire_.
Client::~Client()
{
	delete gestionnaire_;
}


//Méthode d'accès de l'attribut codeClient_
unsigned int Client::obtenirCodeClient() const
{
    return codeClient_;
}

//Méthode d'accès de l'attribut gestionnaire_
GestionnaireProduits * Client::obtenirPanier() const
{
    return gestionnaire_;
}

//Méthode retournant le total des prix de tous les produits dans le gestionnaire_.
double Client::obtenirTotalAPayer() const
{
    double montant = gestionnaire_->obtenirTotalAPayer();
    return montant;
}


//Méthode permmettant d'afficher les informations relier à un panier (soit le gestionnaire_) en appelant
// la méthode correspondante du GestionnaireProduits
void Client::afficherPanier() const
{
    cout << "PANIER (de " << obtenirNom() << ")"
         << "\n";
	gestionnaire_->afficher();
    cout << endl;
}

//Méthode affichant les informations réliées au client.
void Client::afficher() const
{
    Usager::afficher();
    cout << "\t\tcode client:\t" << codeClient_ << endl
         << "\t\tpanier:\t\t" << gestionnaire_->obtenirConteneur().size() << " elements" << endl;
}


//Méthode permettant de modifier le codeClient_
void Client::modifierCodeClient(unsigned int codeClient)
{
    codeClient_ = codeClient_;
}

//Méthode enlevant un produit du panier
void Client::enleverProduit(Produit *produit)
{
	gestionnaire_->supprimer(produit);
}

//Méthode ajoutant un produit au panier
void Client::ajouterProduit(Produit *produit)
{
	gestionnaire_->ajouter(produit);
}

//Méthode réinitialisant le panier à son état d'origine
void Client::reinitialiser()
{
	gestionnaire_->reinitialiserClient();
}

//Méthode retournant un pointeur vers le produit le plus chers dans le panier(gestionnaire_)
Produit * Client::trouverProduitPlusCher() const
{
	return gestionnaire_->trouverProduitPlusCher();
}
