/********************************************
* Titre: Travail pratique #3 - Fournisseur.cpp
* Date: 15 fevrier 2017
* Auteur: Frédéric Fortin 1900664 Antoine Lamontagne 1907605
*******************************************/
#include "Fournisseur.h"

Fournisseur::Fournisseur(const string & nom, const string & prenom, int identifiant, const string & codePostal)
	: Usager(nom, prenom,identifiant,codePostal)
{
	for (int i = 0; i < NIVEAUX_SATISFACTION; ++i)
		satisfaction_.niveaux_[i] = 0;
}

Fournisseur::~Fournisseur()
{
	contenuCatalogue_.clear();
}

vector<Produit*> Fournisseur::obtenirCatalogue() const
{
	return contenuCatalogue_;
}

Satisfaction Fournisseur::obtenirSatisfaction() const
{
	return satisfaction_;
}

void Fournisseur::modifierSatisfaction(Satisfaction satisfaction)
{
	satisfaction_ = satisfaction;
}

void Fournisseur::noter(int appreciation)
{
	++satisfaction_.niveaux_[appreciation];
}

void Fournisseur::ajouterProduit(Produit * produit)
{
	contenuCatalogue_.push_back(produit);
}

void Fournisseur::enleverProduit(Produit * produit)
{
	bool trouve = false;
	for (int i = 0; !trouve && i < contenuCatalogue_.size(); ++i)
	{
		if (*produit == *contenuCatalogue_[i])
		{
			trouve = true;
			contenuCatalogue_[i] = contenuCatalogue_[contenuCatalogue_.size() - 1];
			contenuCatalogue_.pop_back();
		}
	}
}

Fournisseur & Fournisseur::operator=(const Fournisseur & fournisseur)
{
	Usager usager = static_cast<Usager>(*this);
	usager = static_cast<Usager>(fournisseur);
	return static_cast<Fournisseur&>(usager);
}

ostream & operator<<(ostream & os, Fournisseur & fournisseur)
{
	os << "Fournisseur: " << static_cast<Usager>(fournisseur) << " \t \t notes" << endl;
	for (int i = 0; i < NIVEAUX_SATISFACTION; ++i)
		os << " \t \t " << i << ": " << fournisseur.satisfaction_.niveaux_[i] << endl;
	return os;
}
