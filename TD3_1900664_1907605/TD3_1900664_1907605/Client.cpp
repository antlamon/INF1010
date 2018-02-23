/********************************************
* Titre: Travail pratique #3 - Client.cpp
* Date: 15 fevrier 2017
* Auteur: Frédéric Fortin 1900664 Antoine Lamontagne 1907605
*******************************************/

#include "Client.h"
#include "Fournisseur.h"
#include <stdlib.h>
#include <time.h>



Client::Client(const string & nom, const string & prenom, int identifiant, const string & codePostal, long date)
	: Usager(nom, prenom, identifiant,codePostal), dateNaissance_(date)
{
	monPanier_ = nullptr;
	srand(time(0));
}

Client::~Client()
{
	if (monPanier_ != nullptr)
		delete monPanier_;
}

Client::Client(const Client & client) :
	Usager(client.obtenirNom(), client.obtenirPrenom(), client.obtenirIdentifiant(), client.obtenirCodePostal()),	
	dateNaissance_{ client.dateNaissance_ }
{
	if (client.monPanier_ == nullptr)
		monPanier_ = nullptr;
	else {
		monPanier_ = new Panier(client.obtenirIdentifiant());
		for (int i = 0; i < client.monPanier_->obtenirNombreContenu(); i++) {
			monPanier_->ajouter(client.monPanier_->obtenirContenuPanier()[i]);
		}
		int idClient = this->obtenirIdentifiant();
		monPanier_->modifierTotalAPayer(client.monPanier_->obtenirTotalApayer());
	}
	srand(time(0));
}


// Methodes d'acces
long Client::obtenirDateNaissance() const
{
	return dateNaissance_;
}

Panier * Client::obtenirPanier() const
{
	return monPanier_;
}


// Methodes de modification
void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

// Autres méthodes
void Client::acheter(ProduitOrdinaire * prod)
{
	if (monPanier_ == nullptr)
		monPanier_ = new Panier(this->obtenirIdentifiant());
	monPanier_->ajouter(prod);
	// obtenir une note aléatoire
	int note = rand() % NIVEAUX_SATISFACTION;
	// faire la mise à jour de la satisfaction au fournisseur
	prod->obtenirFournisseur().noter(note);
}

void Client::livrerPanier()
{
	monPanier_->livrer();
	delete monPanier_;
	monPanier_ = nullptr;
}


void Client::miserProduit(ProduitAuxEncheres* produitAuxEncheres, double montantMise)
{
	if (produitAuxEncheres->obtenirPrixBase() < montantMise)
	{
		produitAuxEncheres->modifierPrixBase(montantMise);
		produitAuxEncheres->modifierIdentifiantClient(obtenirIdentifiant());
		if (monPanier_ == nullptr)
			monPanier_ = new Panier(this->obtenirIdentifiant());
		monPanier_->ajouter(produitAuxEncheres);
	}
}

Client & Client::operator=(const Client & client)
{
	if (this != &client) {
		this->modifierNom(client.obtenirNom());
		this->modifierPrenom(client.obtenirPrenom());
		this->modifierIdentifiant(client.obtenirIdentifiant());
		this->modifierCodePostal(client.obtenirCodePostal());
		dateNaissance_ = client.obtenirDateNaissance();
		if (client.monPanier_ != nullptr) {
			delete monPanier_;
			monPanier_ = new Panier(obtenirIdentifiant());
			for (int i = 0; i < client.monPanier_->obtenirNombreContenu(); i++) {
				monPanier_->ajouter(client.monPanier_->obtenirContenuPanier()[i]);
			}
		}
		else
			monPanier_ = nullptr;
	}
	return *this;
}


ostream & operator<<(ostream & os, const Client & client)
{
	os << "Client: " << static_cast<Usager>(client)
		<< "Le panier de " << client.obtenirPrenom() << ':' << endl;
	if (client.obtenirPanier() != nullptr)
		os << *client.obtenirPanier();
	else
		os << "est vide.";
	os << endl;
	return os;
}
