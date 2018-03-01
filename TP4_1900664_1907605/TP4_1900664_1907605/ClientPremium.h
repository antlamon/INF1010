/********************************************
* Titre: Travail pratique #4 - Fournisseur.cpp
* Date: 1 mars 2018
* Auteur: Fr�d�ric Fortin 1900664 Antoine Lamontagne 1907605
*******************************************/

#ifndef CLIENT_PREMIUM_H
#define CLIENT_PREMIUM_H

#include <string>
#include "Client.h"

using namespace std;

class ClientPremium : public Client
{
  public:
	//Constructeurs param�triques
    ClientPremium(unsigned int joursRestants = 0);
    ClientPremium(const string &nom, const string &prenom, int identifiant, const string &codePostal, unsigned int codeClient, unsigned int joursRestants = 0);

	//M�thode d'acc�s
    unsigned int obtenirJoursRestants() const;
    double obtenirTotalAPayer() const;

	//M�thode publique
    void afficherProfil() const;

	//M�thode de modification
    void modifierJoursRestants(unsigned int joursRestants);

  private:
	//Attribut
    unsigned int joursRestants_; // avant la fin de l'abonnement
};

#endif
