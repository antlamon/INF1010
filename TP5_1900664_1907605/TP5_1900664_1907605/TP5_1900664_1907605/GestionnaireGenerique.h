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

#include "Usager.h"
#include "Foncteur.h"
#include "Client.h"
#include "ProduitAuxEncheres.h"
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace placeholders;

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
		  A(donnees);
	  };

	  void supprimer(T* donnees)
	  {
		  S(donnees);
	  };

	  template<typename Predicate>
	  void pourChaqueElement(Predicate predicat) const
	  {
		  for_each(conteneur_.begin(), conteneur_.end(), predicat);
	  };

  protected:
	  C conteneur_;

};

