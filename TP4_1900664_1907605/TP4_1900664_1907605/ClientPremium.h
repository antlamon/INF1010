/********************************************
* Titre: Travail pratique #4 - Fournisseur.cpp
* Date: 1 mars 2018
* Auteur: Frédéric Fortin 1900664 Antoine Lamontagne 1907605
*******************************************/

#ifndef CLIENT_PREMIUM_H
#define CLIENT_PREMIUM_H

#include <string>
#include "Client.h"

using namespace std;

class ClientPremium : public Client
{
  public:
	//Constructeurs paramétriques
    ClientPremium(unsigned int joursRestants = 0);
    ClientPremium(const string &nom, const string &prenom, int identifiant, const string &codePostal, unsigned int codeClient, unsigned int joursRestants = 0);

	//Méthode d'accès
    unsigned int obtenirJoursRestants() const;
    double obtenirTotalAPayer() const;

	//Méthode publique
    void afficherProfil() const;

	//Méthode de modification
    void modifierJoursRestants(unsigned int joursRestants);

  private:
	//Attribut
    unsigned int joursRestants_; // avant la fin de l'abonnement
};

#endif
