/**
* Titre: Travail pratique #5 - GestionnaireProduits.cpp
* Date:  2 avril 2018
* Auteur: Frederic Fortin 1900664 & Antoine Lamontagne 1907605
***/

#include "ClientPremium.h"
#include <iostream>

//Constructeur paramétrique recevant la valeur de joursRestants_ et appelant le constructeur par défaut de Client.
ClientPremium::ClientPremium(unsigned int joursRestants)
    : Client(),
      joursRestants_(joursRestants)
{
}


//Constructeur parametrique recevant nom, prenom, identifiant, codePostal et codeClient qui sont passé au constructeur Client les prenant
// et le joursRestants. 
ClientPremium::ClientPremium(const string &nom, const string &prenom, int identifiant,
                             const string &codePostal, unsigned int codeClient,
                             unsigned int joursRestants)
    : Client(nom, prenom, identifiant, codePostal, codeClient),
      joursRestants_(joursRestants)
{
}


//Méthode d'accès de L'attribut joursRestants_
unsigned int ClientPremium::obtenirJoursRestants() const
{
    return joursRestants_;
}

//Méthode retournant le total des prix des produits avec la rabais d'un client premium
double ClientPremium::obtenirTotalAPayer() const
{
	double montant = gestionnaire_->obtenirTotalApayerPremium();
    return montant;
}

//Méthode affichant les informations reliés à un client premium (affiche celles d'un client
//normal plus les informations spécifiques d'un premium) 
void ClientPremium::afficher() const
{
    Client::afficher();
    cout << "\t\tjours restants:\t" << joursRestants_ << endl;
}

//Méthode pour modifier la valeur de l'attribut joursRestants
void ClientPremium::modifierJoursRestants(unsigned int joursRestants)
{
    joursRestants_ = joursRestants_;
}
