/********************************************
* Titre: Travail pratique #4 - Fournisseur.cpp
* Date: 1 mars 2018
* Auteur: Fr�d�ric Fortin 1900664 Antoine Lamontagne 1907605
*******************************************/
#include "ClientPremium.h"
#include <iostream>

//Constructeur prenant le seul parametre joursRestants et l'assignant � son attribut correspondant.
//Appele aussi le constructeur par d�faut de Client
ClientPremium::ClientPremium(unsigned int joursRestants)
    : Client(),
      joursRestants_(joursRestants)
{
}

//Constructeur par param�tres passant les param�tres correspondant au constructeur par param�tre de Client
// assignant le param�tre joursRestant � son attribut correspondant
ClientPremium::ClientPremium(const string &nom, const string &prenom, int identifiant,
                             const string &codePostal, unsigned int codeClient,
                             unsigned int joursRestants)
    : Client(nom, prenom, identifiant, codePostal, codeClient),
      joursRestants_(joursRestants)
{
}

//M�thode d'acc�s
unsigned int ClientPremium::obtenirJoursRestants() const
{
    return joursRestants_;
}

//M�thode retournant le co�t total de tous les produits du panier du client
double ClientPremium::obtenirTotalAPayer() const
{
	double total = 0;

	for (Produit* prod : panier_)
	{
		total += fmax(prod->obtenirPrix(), 0);
	}

	return total;
}

//M�thode affichant la classe. Appelle la m�thode afficherProfil() de sa classe parent
//Client et rajoutant par la suite sa sp�cificit� du nombre de jours restant
void ClientPremium::afficherProfil() const
{
	Client::afficherProfil();
	cout << "\t\tjours restants: " << joursRestants_;
}

//M�thode de modification
void ClientPremium::modifierJoursRestants(unsigned int joursRestants)
{
    joursRestants_ = joursRestants_;
}
