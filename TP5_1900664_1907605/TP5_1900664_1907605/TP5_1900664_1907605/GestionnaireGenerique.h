/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

// TODO : Créer la classe GestionnaireGenerique

// TODO : Méthodes :
/*
- ajouter()
- supprime()
- obtenirConteneur()
- pourChaqueElement()
*/

#include "Foncteur.h"

using namespace std;

//T=Produits ou usagers
//C=conteneur
//A=foncteur d'ajout
//S=foncteur de suppression
template< typename T, typename C, typename A, typename S>
class GestionnaireGenerique
{
  public:
	  //Obtient le conteneur de type C du gestionnaire
	  C obtenirConteneur() const
	  {
		  return conteneur_;
	  };

	  //Ajoute des donnees de type T dans un conteneur de type C
	  void ajouter(T* donnees)
	  {
		  A ajout(conteneur_);
		  conteneur_ = ajout(donnees);
	  };

	  //Supprime les donnees T du conteneur de type C
	  void supprimer(T* donnees)
	  {
		  S suppression(conteneur_);
		  conteneur_ = suppression(donnees);
	  };

	  //Fonction qui permet d'utiliser un prédicat sur tous les elements T d'un conteneur 
	  template<typename Predicate>
	  void pourChaqueElement(Predicate predicat) const
	  {
		  for_each(conteneur_.begin(), conteneur_.end(), predicat);
	  };

  protected:
	  C conteneur_;

};

