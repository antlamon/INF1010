/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

// TODO : Cr�er la classe GestionnaireGenerique

// TODO : M�thodes :
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
	  }

	  void ajouter(T* donnees)
	  {
		  A(donnees);
	  }

	  void supprimer(T* donnees)
	  {
		  S(donnees);
	  }

	  template<typename Predicate>
	  void pourChaqueElement(Predicate predicat)
	  {
		  for_each(C.begin(), C.end(), predicat());
	  }

  protected:
	  C conteneur_;

};

