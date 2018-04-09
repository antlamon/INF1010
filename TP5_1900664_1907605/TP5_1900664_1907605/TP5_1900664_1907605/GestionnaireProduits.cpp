/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireProduits.h"
#include "ProduitAuxEncheres.h"
#include <algorithm>
#include <functional>

//M�thode r�initialisant le conteneur_ selon les sp�cification d'un panier
void GestionnaireProduits::reinitialiserClient()
{
	//Lambda permettant de retirer le client d'�tre l'encherisseur d'un produit aux encheres
	auto lambda = [](pair<int, Produit*> element) { ProduitAuxEncheres *produit = dynamic_cast<ProduitAuxEncheres *>(element.second); 
													  if (produit) { produit->modifierEncherisseur(nullptr);
													  produit->modifierPrix(produit->obtenirPrixInitial());
													  }; };
	//Applique le lambda pour tous les �l�ments du conteneur
	for_each(conteneur_.begin(), conteneur_.end(), lambda);

	conteneur_.clear();
}

//M�thode r�initialisant le conteneur_ selon les sp�cification d'un catalogue
void GestionnaireProduits::reinitialiserFournisseur()
{
	//Modifie le fournisseur de tous les produits du catalogue pour null ptr
	for_each(conteneur_.begin(), conteneur_.end(),[](pair<int, Produit*> element ) {element.second->modifierFournisseur(nullptr);  });

	conteneur_.clear();
}

//M�thode affichant les informations de tous les produits dans le conteneur
void GestionnaireProduits::afficher() const
{
	pourChaqueElement<>([this](pair<int, Produit*> element) {element.second->afficher(); cout << "\t\texemplaire :\t" << conteneur_.count(element.first) << endl; });
}

//M�thode calculant le total � payer selon le contenu du conteneur (pour un panier)
double GestionnaireProduits::obtenirTotalAPayer() const
{
	double montant = 0.0;
	pourChaqueElement<>([&](pair<int, Produit*> element) {montant += element.second->obtenirPrix(); });
	return montant;
}

//M�thode calculant le total � payer selon le contenu du conteneur en appliquant le rabais d'un client premium (pour un panier)
double GestionnaireProduits::obtenirTotalApayerPremium() const
{
	double montant = 0.0;
	double prix = 0.0;
	//V�rifie que le prix reduit ne va pas sous la barre du 0
	pourChaqueElement<>([&](pair<int, Produit*> element) {prix = element.second->obtenirPrix();  montant += prix < 5 ? 0 : prix - 5 ; });

	return montant;
}

//M�thode trouvant le produit le plus cher dans le conteneur
Produit * GestionnaireProduits::trouverProduitPlusCher() const
{
	//Pour retourner un nullptr si le conteneur est vide
	Produit * prod = nullptr;
	if (!conteneur_.empty())
	{
		//Lambda comparant les prix de deux produits pour max_element
		//Retourne vrai si prod1 est plus petit que prod2
		auto lambda = ([](pair<int, Produit *> prod1, pair<int, Produit *> prod2) -> bool {return prod1.second->obtenirPrix() < prod2.second->obtenirPrix(); });


		prod = max_element(conteneur_.begin(), conteneur_.end(), lambda)->second;
	}
	return prod;
}

//Retourne un vector<int,Produit*> contenant les pair dont leur prix correspondont � l'intervalle pass� en param�tre
vector<pair<int, Produit*>> GestionnaireProduits::obtenirProduitsEntre(double borneinf, double bornesupp) const
{
	vector<pair<int, Produit*>> vec;
	copy_if(conteneur_.begin(), conteneur_.end(), back_inserter(vec), FoncteurIntervalle(borneinf, bornesupp));
	return vec;
}

//M�thode obtenant le premier produit ayant une r�f�rence supp�rieure au produit pass� en param�tre
Produit * GestionnaireProduits::obtenirProduitSuivant(Produit * prod) const
{
	//Permet de retourner un  pointeur nul si le conteneur est vide
	Produit * produit = nullptr;
	if (!conteneur_.empty())
	{
		//Lambda comparant les r�f�rence retournant vrai si celle d'element est plus grande
		auto lambda = [](pair <int, Produit *> element, Produit * prod) {return element.second->obtenirReference() > prod->obtenirReference(); };

		produit = (find_if(conteneur_.begin(), conteneur_.end(), bind(lambda, placeholders::_1, prod)))->second;
	}
	return produit;
}
