/**************************************************
* Titre: Travail pratique #1 - client.cpp
* Date: 4 février 2018
* Auteur: Frédéric Fortin(1900664) et Antoine Lamontagne(1907605)
Classe ayant les informations concernant le client du site internet lui permmettant de faire ses achats
**************************************************/

#include "client.h"
//Constructeur par paramètre
Client::Client(string nom, string prenom, int identifiant, string codePostal, long date)
	:nom_(nom), prenom_(prenom), identifiant_(identifiant), codePostal_(codePostal), dateNaissance_(date)
{
	monPanier_ = nullptr;
}

// Méthode pour obtenir la chaine de l'attribut nom_
string Client::obtenirNom() const
{
	return nom_;
}

// Méthode pour obtenir la chaine de l'attribut prenom_
string Client::obtenirPrenom() const
{
	return prenom_;
}

// Méthode pour obtenir la valeur entière de l'attribut identifiant_
int Client::obtenirIdentifiant() const 
{
	return identifiant_;
}

// Méthode pour obtenir la chaine de l'attribut codePostal_
string Client::obtenirCodePostal() const
{
	return codePostal_;
}

// Méthode pour obtenir la valeur de l'attribut dateNaissance_
long Client::obtenirDateNaissance() const
{
	return dateNaissance_;
}

// Méthode pour modifier nom_
void Client::modifierNom(string nom)
{
	nom_ = nom;
}

// Méthode pour modifier prenom_
void Client::modifierPrenom(string prenom)
{
	prenom_ = prenom;
}

// Méthode pour modifier identifiant_
void Client::modifierIdentifiant(int identifiant)
{
	identifiant_ = identifiant;
}

// Méthode pour modifier codePostal_
void Client::modifierCodePostal(string codePostal)
{
	codePostal_ = codePostal;
}

// Méthode pour modifier dateNaissance_
void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

//Méthode ajoutant le nouveau produit que le client désire acheter à son panier
void Client::acheter(Produit * prod)
{
	if (monPanier_ == nullptr)
	{
		monPanier_ = new Panier(4);
	}

	monPanier_->ajouter(prod);

}

//Méthode affichant les informations de la classe
void Client::afficherPanier()
{
	if(monPanier_ != nullptr)
		monPanier_->afficher();
	else
		cout << "Aucun panier" << endl;
}

//Méthode faisant la livraison des produits acheters qui pour ce programme agit qu'en tant que destructeur
void Client::livrerPanier()
{
	monPanier_->livrer();
	delete monPanier_;
	monPanier_ = nullptr;
}
