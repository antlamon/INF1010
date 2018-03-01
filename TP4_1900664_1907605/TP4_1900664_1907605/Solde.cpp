/********************************************
* Titre: Travail pratique #4 - Fournisseur.cpp
* Date: 1 mars 2018
* Auteur: Frédéric Fortin 1900664 Antoine Lamontagne 1907605
*******************************************/
#include "Solde.h"

//Constructeur paramètrique assignant le paramètre pourcentageRabais à son attribut
//correspondant.
Solde::Solde(int pourcentageRabais)
    : pourcentageRabais_(pourcentageRabais)
{
}

//Destructeur virtuel pur pour rendre la classe abstraite
Solde::~Solde() {}

//Méthode d'accès
double Solde::obtenirPourcentageRabais() const
{
    return pourcentageRabais_;
}

//Méthode de modification
void Solde::modifierPourcentageRabais(int pourcentageRabais)
{
    pourcentageRabais_ = pourcentageRabais;
}