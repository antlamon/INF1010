/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireProduits.h"

void GestionnaireProduits::reinitialiserClient()
{
	auto lambda = [](pair<int, Produit*> element) { ProduitAuxEncheres *produit = dynamic_cast<ProduitAuxEncheres *>(element.second); 
													  if (produit) { produit->modifierEncherisseur(nullptr);
													  produit->modifierPrix(produit->obtenirPrixInitial());
													  }; };
	pourChaqueElement<>(lambda);
	conteneur_.clear();
}

void GestionnaireProduits::reinitialiserFournisseur()
{
	pourChaqueElement<>([](pair<int, Produit*> element ) {element.second->modifierFournisseur(nullptr);  });
	conteneur_.clear();
}

void GestionnaireProduits::afficher() const
{
	pourChaqueElement<>([](pair<int, Produit*> element) {element.second->afficher(); cout << endl; });
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
	pourChaqueElement<>([&](pair<int, Produit*>) {prix = prod->obtenirPrix();  montant += prix < 5 ? 0 : prix - 5 ; });
	return montant;
}

Produit * GestionnaireProduits::trouverProduitPlusCher() const
{
	auto lambda = ([](Produit * prod1, Produit * prod2) -> bool {return prod1->obtenirPrix() < prod2->obtenirPrix(); });
	Produit *prod = max_element(conteneur_.begin(), conteneur_.end(), lambda)->second;
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
	return nullptr;
}
