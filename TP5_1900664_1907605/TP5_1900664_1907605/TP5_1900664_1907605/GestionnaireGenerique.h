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
	  C obtenirConteneur() const
	  {
		  return conteneur_;
	  };

	  void ajouter(T* donnees)
	  {
		  A ajout(conteneur_);
		  conteneur_ = ajout(donnees);
	  };

	  void supprimer(T* donnees)
	  {
		  S suppression(conteneur_);
		  conteneur_ = suppression(donnees);
	  };

	  template<typename Predicate>
	  void pourChaqueElement(Predicate predicat) const
	  {
		  for_each(conteneur_.begin(), conteneur_.end(), predicat);
	  };

  protected:
	  C conteneur_;

};

