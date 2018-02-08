/********************************************
* Titre: Travail pratique #2 - Rayon.cpp
* Date: 25 janvier 2018
* Auteur: Timoth�e CHAUVIN
*******************************************/

#include "Rayon.h"

Rayon::Rayon(const string& cat) :
	categorie_{ cat },
	capaciteProduits_{ 0 },
	nombreProduits_{ 0 }
{
}

Rayon::~Rayon()
{
	/*if (tousProduits_ != nullptr)
		delete tousProduits_;*/
}

// Methodes d'acces
string Rayon::obtenirCategorie() const
{
	return categorie_;
}

vector<Produit*> Rayon::obtenirTousProduits() const
{
	return tousProduits_;
}

int Rayon::obtenirCapaciteProduits() const
{
	return capaciteProduits_;
}

int Rayon::obtenirNombreProduits() const
{
	return tousProduits_.size();
}

// Methodes de modification
void Rayon::modifierCategorie(const string& cat)
{
	categorie_ = cat;
}

Rayon& Rayon::operator+=(Produit * prod)
{
	tousProduits_.push_back(prod);
	capaciteProduits_ = tousProduits_.capacity();
	return *this;
}

int Rayon::compterDoublons(const Produit & produit)
{
	int nbDoublons = 0;
	for (int i = 0; i < tousProduits_.size(); i++)
	{
		if (produit == *tousProduits_[i])
			++nbDoublons;
	}
	return nbDoublons;
}

ostream & operator<<(ostream & cout, const Rayon & rayon)
{
	cout << "Le rayon " << rayon.categorie_ << ": " << endl;
	for (int i = 0; i < rayon.obtenirNombreProduits(); i++)
	{
		cout << "----> "
			<< *rayon.tousProduits_[i] << endl;
	}

	return cout;
}
