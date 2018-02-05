/**************************************************
* Titre: Travail pratique #1 - client.cpp
* Date: 4 f�vrier 2018
* Auteur: Fr�d�ric Fortin(1900664) et Antoine Lamontagne(1907605)
Classe ayant les informations concernant le client du site internet lui permmettant de faire ses achats
**************************************************/

#include "client.h"
//Constructeur par param�tre
Client::Client(string nom, string prenom, int identifiant, string codePostal, long date)
	:nom_(nom), prenom_(prenom), identifiant_(identifiant), codePostal_(codePostal), dateNaissance_(date)
{
	monPanier_ = nullptr;
}

// M�thode pour obtenir la chaine de l'attribut nom_
string Client::obtenirNom() const
{
	return nom_;
}

// M�thode pour obtenir la chaine de l'attribut prenom_
string Client::obtenirPrenom() const
{
	return prenom_;
}

// M�thode pour obtenir la valeur enti�re de l'attribut identifiant_
int Client::obtenirIdentifiant() const 
{
	return identifiant_;
}

// M�thode pour obtenir la chaine de l'attribut codePostal_
string Client::obtenirCodePostal() const
{
	return codePostal_;
}

// M�thode pour obtenir la valeur de l'attribut dateNaissance_
long Client::obtenirDateNaissance() const
{
	return dateNaissance_;
}

// M�thode pour modifier nom_
void Client::modifierNom(string nom)
{
	nom_ = nom;
}

// M�thode pour modifier prenom_
void Client::modifierPrenom(string prenom)
{
	prenom_ = prenom;
}

// M�thode pour modifier identifiant_
void Client::modifierIdentifiant(int identifiant)
{
	identifiant_ = identifiant;
}

// M�thode pour modifier codePostal_
void Client::modifierCodePostal(string codePostal)
{
	codePostal_ = codePostal;
}

// M�thode pour modifier dateNaissance_
void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

//M�thode ajoutant le nouveau produit que le client d�sire acheter � son panier
void Client::acheter(Produit * prod)
{
	if (monPanier_ == nullptr)
	{
		monPanier_ = new Panier(4);
	}

	monPanier_->ajouter(prod);

}

//M�thode affichant les informations de la classe
void Client::afficherPanier()
{
	if(monPanier_ != nullptr)
		monPanier_->afficher();
	else
		cout << "Aucun panier" << endl;
}

//M�thode faisant la livraison des produits acheters qui pour ce programme agit qu'en tant que destructeur
void Client::livrerPanier()
{
	monPanier_->livrer();
	delete monPanier_;
	monPanier_ = nullptr;
}
