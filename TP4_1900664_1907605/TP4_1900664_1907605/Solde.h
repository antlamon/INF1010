/********************************************
* Titre: Travail pratique #4 - Fournisseur.cpp
* Date: 1 mars 2018
* Auteur: Frédéric Fortin 1900664 Antoine Lamontagne 1907605
*******************************************/
#ifndef SOLDE_H
#define SOLDE_H

#include <string>
#include <iostream>

using namespace std;

class Solde
{
  public:
	//Constructeur par paramètre
    Solde(int pourcentageRabais);

	//Destructeur virtuel pur
    virtual ~Solde() = 0; // par convention, pour rendre une classe abstraite lorsque celle-ci
                          // n'a aucune méthode qui mériterait d'être virtuelle pure, on préfère
                          // généralement rendre le destructeur de la classe virtuel pur.

	//Méthode d'accès
    double obtenirPourcentageRabais() const;

	//Méthode de modification
    void modifierPourcentageRabais(int pourcentageRabais);

  protected:
	//Attribut
    int pourcentageRabais_;
};

#endif
