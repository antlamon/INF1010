/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/
#pragma once
#include <map>
#include <set>
#include <algorithm>
#include "Usager.h"


// TODO : Créer le FoncteurEgal
template <typename T>
class FoncteurEgal
{
public:
	FoncteurEgal(T * t)
		:t_(t) {};

	bool operator()(pair<int, T *> paire) const
	{
		return t_ == paire.second;
	};

private:
	T * t_;
};

// TODO : Créer le FoncteurGenerateurId
/*
Attributs :
- id_;
Méthodes :
- operator(); Incrémenter id_ à chaque appel
*/
class FoncteurGenerateurId
{
public:
	FoncteurGenerateurId()
		:id_(0) {};

	int operator()()
	{
		return id_++;
	};

private:
	int id_;
};

// TODO : Créer le FoncteurDiminuerPourcent
/*
Attributs :
- pourcentage_;
Méthodes :
- operator(); Calule le nouveau prix du Produit de la pair passé en paramètre et le modifie
*/
class FoncteurDiminuerPourcent
{
public:
	FoncteurDiminuerPourcent(int pourcentage)
		:pourcentage_(pourcentage) {};

	void operator()(pair<int, Produit *> paire)
	{
		//Calculer le nouveau prix
		double nouveauPrix = (1 - pourcentage_ / 100.0) * paire.second->Produit::obtenirPrix();
		paire.second->modifierPrix(nouveauPrix);
	};

private:
	int pourcentage_;
};

// TODO : Créer le FoncteurIntervalle
/*
Attributs :
- borneInf_;
- borneSup_;
Méthodes :
- operator(); Vérifie que le Produit associé à la pair passé en paramètre est compris entre les bornes borneInf_ et borneSup_ (retourne un booléen)
*/
class FoncteurIntervalle
{
public:
	FoncteurIntervalle(double min, double max)
		:borneInf_(min), borneSup_(max) {};

	bool operator()(pair<int, Produit*> prod) const
	{
		//Obtenir le prix
		double prix = prod.second->obtenirPrix();
		//Vérifier les bornes selon le prix
		return prix <= borneSup_ && prix >= borneInf_;
	};

private:
	double borneInf_, borneSup_;
};

// TODO : Créer le Foncteur AjouterProduit
/*
Attributs :
- &multimap_;
Méthodes :
- operator(); Ajoute dans la multimap la pair passé par paramètre et retourne la multimap_;
*/
class AjouterProduit
{
public:
	AjouterProduit(multimap<int, Produit *> & map)
		:multimap_(map) {};

	multimap<int, Produit *> & operator()(Produit * prod)
	{
		multimap_.insert(multimap_.end(), make_pair(prod->obtenirReference(), prod));
		return multimap_;
	};

private:
	multimap<int, Produit *> & multimap_;
};

// TODO : Créer le Foncteur SupprimerProduit
/*
Attributs :
- &multimap_;
Méthodes :
- operator(); Utilise la fonction find_if avec le FoncteurEgal. Si le Produit existe,
				on supprime le Produit et on retourne la multimap_,
				sinon on retourne juste la multimap_ sans supprimer l'élément.
*/
class SupprimerProduit
{
public:
	SupprimerProduit(multimap<int, Produit *> & map)
		:multimap_(map) {};

	multimap<int, Produit *> & operator()(Produit * prod)
	{
		auto it = find_if(multimap_.begin(), multimap_.end(), FoncteurEgal<Produit>(prod));
		if(it != multimap_.end())
			multimap_.erase(it);
		return multimap_;
	};

private:
	multimap<int, Produit *> & multimap_;
};

//TODO : Créer le Foncteur AjouterUsager
/*
Attributs :
- &set;
Méthodes :
- operateur(); Ajoute un Usager dans le conteneur.
*/
class AjouterUsager
{
public:
	AjouterUsager(set<Usager *> & set)
		:set_(set) {};

	set<Usager *> & operator()(Usager * usager)
	{
		auto it = set_.end();
		set_.insert(it, usager);
		return set_;
	};

private:
	set<Usager *> & set_;
};

//TODO : Créer le Foncteur SupprimerUsager
/*
Attributs :
- &set;
Méthodes :
- operateur(); Trouve l'Usager dans le set_, s'il existe on le supprime et on retourne le set_, sinon on retourne juste directement le set_.
*/
class SupprimerUsager
{
public:
	SupprimerUsager(set<Usager *> & set)
		:set_(set) {};

	set<Usager *> & operator()(Usager * usager)
	{
		if (usager != nullptr)
			set_.erase(usager);
		return set_;
	};

private:
	set<Usager *> & set_;
};
