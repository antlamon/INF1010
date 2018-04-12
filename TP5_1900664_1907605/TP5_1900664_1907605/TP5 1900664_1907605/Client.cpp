/**
* Titre: Travail pratique #5 - Client.cpp
* Date:  2 avril 2018
* Auteur: Frederic Fortin 1900664 & Antoine Lamontagne 1907605
***/

#include "Client.h"
#include <iostream>

//Constructeur param�trique recevant le codeClient. Il appelle le constructeur par d�faut de la classe Usager
//et instancie le gestionnaire_.
Client::Client(unsigned int codeClient)
    : Usager(),
      codeClient_(codeClient)
{
	gestionnaire_ = new GestionnaireProduits();
}


//Constructeur parametrique recevant nom, prenom, identifiant et codePostal qui sont pass� au constructeur Usager les prenant
// et le codeClient. Instancie le gestionnaire_.
Client::Client(const string &nom, const string &prenom, int identifiant,
               const string &codePostal, unsigned int codeClient)
    : Usager(nom, prenom, identifiant, codePostal),
      codeClient_(codeClient)
{
	gestionnaire_ = new GestionnaireProduits();
}


//Destructeur d�sallouant l'espace pris par le pointeur du gestionnaire_.
Client::~Client()
{
	delete gestionnaire_;
}


//M�thode d'acc�s de l'attribut codeClient_
unsigned int Client::obtenirCodeClient() const
{
    return codeClient_;
}

//M�thode d'acc�s de l'attribut gestionnaire_
GestionnaireProduits * Client::obtenirPanier() const
{
    return gestionnaire_;
}

//M�thode retournant le total des prix de tous les produits dans le gestionnaire_.
double Client::obtenirTotalAPayer() const
{
    double montant = gestionnaire_->obtenirTotalAPayer();
    return montant;
}


//M�thode permmettant d'afficher les informations relier � un panier (soit le gestionnaire_) en appelant
// la m�thode correspondante du GestionnaireProduits
void Client::afficherPanier() const
{
    cout << "PANIER (de " << obtenirNom() << ")"
         << "\n";
	gestionnaire_->afficher();
    cout << endl;
}

//M�thode affichant les informations r�li�es au client.
void Client::afficher() const
{
    Usager::afficher();
    cout << "\t\tcode client:\t" << codeClient_ << endl
         << "\t\tpanier:\t\t" << gestionnaire_->obtenirConteneur().size() << " elements" << endl;
}


//M�thode permettant de modifier le codeClient_
void Client::modifierCodeClient(unsigned int codeClient)
{
    codeClient_ = codeClient_;
}

//M�thode enlevant un produit du panier
void Client::enleverProduit(Produit *produit)
{
	gestionnaire_->supprimer(produit);
}

//M�thode ajoutant un produit au panier
void Client::ajouterProduit(Produit *produit)
{
	gestionnaire_->ajouter(produit);
}

//M�thode r�initialisant le panier � son �tat d'origine
void Client::reinitialiser()
{
	gestionnaire_->reinitialiserClient();
}

//M�thode retournant un pointeur vers le produit le plus chers dans le panier(gestionnaire_)
Produit * Client::trouverProduitPlusCher() const
{
	return gestionnaire_->trouverProduitPlusCher();
}
