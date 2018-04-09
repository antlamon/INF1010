/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireProduits.h"
#include "ProduitAuxEncheres.h"
#include <algorithm>
#include <functional>

void GestionnaireProduits::reinitialiserClient()
{
	auto lambda = [](pair<int, Produit*> element) { ProduitAuxEncheres *produit = dynamic_cast<ProduitAuxEncheres *>(element.second); 
													  if (produit) { produit->modifierEncherisseur(nullptr);
													  produit->modifierPrix(produit->obtenirPrixInitial());
													  }; };
	for_each(conteneur_.begin(), conteneur_.end(), lambda);
	conteneur_.clear();
}

void GestionnaireProduits::reinitialiserFournisseur()
{
	for_each(conteneur_.begin(), conteneur_.end(),[](pair<int, Produit*> element ) {element.second->modifierFournisseur(nullptr);  });
	conteneur_.clear();
}

void GestionnaireProduits::afficher() const
{
	pourChaqueElement<>([this](pair<int, Produit*> element) {element.second->afficher(); cout << "\t\texemplaire :\t" << conteneur_.count(element.first) << endl; });
}

double GestionnaireProduits::obtenirTotalAPayer() const
{
	double montant = 0.0;
	pourChaqueElement<>([&](pair<int, Produit*> element) {montant += element.second->obtenirPrix(); });
	return montant;
}

double GestionnaireProduits::obtenirTotalApayerPremium() const
{
	double montant = 0.0;
	double prix = 0.0;
	pourChaqueElement<>([&](pair<int, Produit*> element) {prix = element.second->obtenirPrix();  montant += prix < 5 ? 0 : prix - 5 ; });
	return montant;
}

Produit * GestionnaireProduits::trouverProduitPlusCher() const
{
	Produit * prod = nullptr;
	if (!conteneur_.empty())
	{
		auto lambda = ([](pair<int, Produit *> prod1, pair<int, Produit *> prod2) -> bool {return prod1.second->obtenirPrix() < prod2.second->obtenirPrix(); });
		prod = max_element(conteneur_.begin(), conteneur_.end(), lambda)->second;
	}
	return prod;
}

vector<pair<int, Produit*>> GestionnaireProduits::obtenirProduitsEntre(double par1, double par2) const
{
	vector<pair<int, Produit*>> vec;
	copy_if(conteneur_.begin(), conteneur_.end(), back_inserter(vec), FoncteurIntervalle(par1, par2));
	return vec;
}

Produit * GestionnaireProduits::obtenirProduitSuivant(Produit * prod) const
{
	Produit * produit = nullptr;
	if (!conteneur_.empty())
	{
		auto lambda = [](pair <int, Produit *> element, Produit * prod) {return element.second->obtenirReference() > prod->obtenirReference(); };
		produit = (find_if(conteneur_.begin(), conteneur_.end(), bind(lambda, placeholders::_1, prod)))->second;
	}
	return produit;
}
