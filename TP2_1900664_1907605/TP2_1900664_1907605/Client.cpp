/********************************************
* Titre: Travail pratique #2 - Client.cpp
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothée CHAUVIN
*******************************************/
/**************************************************
* Titre: Travail pratique #2 - client.cpp
* Date: 8 février 2018
* Auteur: Frédéric Fortin(1900664) et Antoine Lamontagne(1907605)
Classe ayant les informations concernant le client du site internet lui permmettant de faire ses achats
**************************************************/

#include "Client.h"

//Constructeur qui crée un client ayant les paramètres comme attributs.
Client::Client(const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date) :
	nom_{ nom },
	prenom_{ prenom },
	identifiant_{ identifiant },
	codePostal_{ codePostal },
	dateNaissance_{ date },
	monPanier_{ nullptr }
{
}

//Constructeur de copie qui crée un objet en utilisant les attributs d'un objet existant.
//Gère la copie en profondeur des produits du panier.
Client::Client(const Client& client) : 
	nom_{ client.nom_ },
	prenom_{ client.prenom_ },
	identifiant_{ client.identifiant_ },
	codePostal_{ client.codePostal_ },
	dateNaissance_{ client.dateNaissance_ }
{
	monPanier_ = new Panier();
	for (int i = 0; i < client.monPanier_->obtenirNombreContenu(); i++)
		monPanier_->ajouter(client.monPanier_->obtenirContenuPanier()[i]);
}

Client::~Client()
{
	if (monPanier_ != nullptr)
		delete monPanier_;
}

// Methodes d'acces
string Client::obtenirNom() const
{
	return nom_;
}

string Client::obtenirPrenom() const
{
	return prenom_;
}

int Client::obtenirIdentifiant() const
{
	return identifiant_;
}

string Client::obtenirCodePostal() const
{
	return codePostal_;
}

long Client::obtenirDateNaissance() const
{
	return dateNaissance_;
}

Panier * Client::obtenirPanier() const
{
	return monPanier_;
}

// Methodes de modification
void  Client::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Client::modifierPrenom(const string& prenom)
{
	prenom_ = prenom;
}

void Client::modifierIdentifiant(int identifiant)
{
	identifiant_ = identifiant;
}

void Client::modifierCodePostal(const string& codePostal)
{
	codePostal_ = codePostal;
}

void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

// Permet à un client d'acheter un produit.
void Client::acheter(Produit * prod)
{
	if (monPanier_ == nullptr)
		monPanier_ = new Panier();
	monPanier_->ajouter(prod);
}

// Livre le panier du client et vidant celui-ci.
void Client::livrerPanier()
{
	monPanier_->livrer();
	delete monPanier_;
	monPanier_ = nullptr;
}

// Surchage de l'opérateur = pour permettre de copier les attributs d'un objet existant vers un autre objet existant.
Client& Client::operator=(const Client & client)
{
	modifierNom(client.obtenirNom());
	modifierPrenom(client.obtenirPrenom());
	modifierIdentifiant(client.obtenirIdentifiant());
	modifierCodePostal(client.obtenirCodePostal());
	modifierDateNaissance(client.obtenirDateNaissance());
	delete monPanier_;
	monPanier_ = new Panier();
	for (int i = 0; i < client.monPanier_->obtenirNombreContenu(); i++)
		monPanier_->ajouter(client.monPanier_->obtenirContenuPanier()[i]);

	return *this;
}

// Surchage de l'opérateur == qui permet de vérifier si deux clients ont le même identifiant.
bool Client::operator==(const int & id) const
{
	return identifiant_ == id;
}

bool operator==(const int & id, const Client & client)
{
	return client == id;
}

// Surcharge de l'opérateur << pour permettre l'affichage d'un client.
ostream & operator<<(ostream & cout, const Client & client)
{
	if (client.monPanier_ != nullptr) {
		cout << "Le panier de " << client.prenom_ << ": " << endl
			<< *client.monPanier_;
	}
	else {
		cout << "Le panier de " << client.prenom_ << " est vide !" << endl;
	}

	return cout;
}
