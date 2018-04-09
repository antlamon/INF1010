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


// TODO : Cr�er le FoncteurEgal
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

// TODO : Cr�er le FoncteurGenerateurId
/*
Attributs :
- id_;
M�thodes :
- operator(); Incr�menter id_ � chaque appel
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

// TODO : Cr�er le FoncteurDiminuerPourcent
/*
Attributs :
- pourcentage_;
M�thodes :
- operator(); Calule le nouveau prix du Produit de la pair pass� en param�tre et le modifie
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

// TODO : Cr�er le FoncteurIntervalle
/*
Attributs :
- borneInf_;
- borneSup_;
M�thodes :
- operator(); V�rifie que le Produit associ� � la pair pass� en param�tre est compris entre les bornes borneInf_ et borneSup_ (retourne un bool�en)
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
		//V�rifier les bornes selon le prix
		return prix <= borneSup_ && prix >= borneInf_;
	};

private:
	double borneInf_, borneSup_;
};

// TODO : Cr�er le Foncteur AjouterProduit
/*
Attributs :
- &multimap_;
M�thodes :
- operator(); Ajoute dans la multimap la pair pass� par param�tre et retourne la multimap_;
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

// TODO : Cr�er le Foncteur SupprimerProduit
/*
Attributs :
- &multimap_;
M�thodes :
- operator(); Utilise la fonction find_if avec le FoncteurEgal. Si le Produit existe,
				on supprime le Produit et on retourne la multimap_,
				sinon on retourne juste la multimap_ sans supprimer l'�l�ment.
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

//TODO : Cr�er le Foncteur AjouterUsager
/*
Attributs :
- &set;
M�thodes :
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

//TODO : Cr�er le Foncteur SupprimerUsager
/*
Attributs :
- &set;
M�thodes :
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
