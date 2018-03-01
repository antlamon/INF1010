/********************************************
* Titre: Travail pratique #4 - Fournisseur.cpp
* Date: 1 mars 2018
* Auteur: Fr�d�ric Fortin 1900664 Antoine Lamontagne 1907605
*******************************************/
#include "Solde.h"

//Constructeur param�trique assignant le param�tre pourcentageRabais � son attribut
//correspondant.
Solde::Solde(int pourcentageRabais)
    : pourcentageRabais_(pourcentageRabais)
{
}

//Destructeur virtuel pur pour rendre la classe abstraite
Solde::~Solde() {}

//M�thode d'acc�s
double Solde::obtenirPourcentageRabais() const
{
    return pourcentageRabais_;
}

//M�thode de modification
void Solde::modifierPourcentageRabais(int pourcentageRabais)
{
    pourcentageRabais_ = pourcentageRabais;
}