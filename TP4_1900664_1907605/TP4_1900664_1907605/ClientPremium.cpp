/********************************************
* Titre: Travail pratique #4 - Fournisseur.cpp
* Date: 1 mars 2018
* Auteur: Frédéric Fortin 1900664 Antoine Lamontagne 1907605
*******************************************/
#include "ClientPremium.h"
#include <iostream>

//Constructeur prenant le seul parametre joursRestants et l'assignant à son attribut correspondant.
//Appele aussi le constructeur par défaut de Client
ClientPremium::ClientPremium(unsigned int joursRestants)
    : Client(),
      joursRestants_(joursRestants)
{
}

//Constructeur par paramètres passant les paramètres correspondant au constructeur par paramètre de Client
// assignant le paramètre joursRestant à son attribut correspondant
ClientPremium::ClientPremium(const string &nom, const string &prenom, int identifiant,
                             const string &codePostal, unsigned int codeClient,
                             unsigned int joursRestants)
    : Client(nom, prenom, identifiant, codePostal, codeClient),
      joursRestants_(joursRestants)
{
}

//Méthode d'accès
unsigned int ClientPremium::obtenirJoursRestants() const
{
    return joursRestants_;
}

//Méthode retournant le coût total de tous les produits du panier du client
double ClientPremium::obtenirTotalAPayer() const
{
	double total = 0;

	for (Produit* prod : panier_)
	{
		total += fmax(prod->obtenirPrix(), 0);
	}

	return total;
}

//Méthode affichant la classe. Appelle la méthode afficherProfil() de sa classe parent
//Client et rajoutant par la suite sa spécificité du nombre de jours restant
void ClientPremium::afficherProfil() const
{
	Client::afficherProfil();
	cout << "\t\tjours restants: " << joursRestants_;
}

//Méthode de modification
void ClientPremium::modifierJoursRestants(unsigned int joursRestants)
{
    joursRestants_ = joursRestants_;
}
