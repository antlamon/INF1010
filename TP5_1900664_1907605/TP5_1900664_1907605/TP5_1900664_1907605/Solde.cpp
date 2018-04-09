/***
* Titre: Travail pratique #5 - Solde.cpp
* Date:  9 avril 2018
* Auteur: Frederic Fortin 1900664 & Antoine Lamontagne 1907605
***/
#include "Solde.h"

//Constructeur par parametre d'une solde qui recoit le pourcentage de rabais
Solde::Solde(int pourcentageRabais)
	: pourcentageRabais_(pourcentageRabais) {}

//Le destructeur permet que solde soit une classe virtuelle pure
Solde::~Solde() {}

//Obtient le pourcentage de rabais du solde
double Solde::obtenirPourcentageRabais() const
{
    return pourcentageRabais_;
}

//Modifie le pourcentage de rabais du solde
void Solde::modifierPourcentageRabais(int pourcentageRabais)
{
    pourcentageRabais_ = pourcentageRabais;
}