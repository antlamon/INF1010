#include "Rayon.h"

Rayon::Rayon(string cat)
	:categorie_(cat)
{
	tousProduits_ = nullptr;
	capaciteProduits_ = 0;
	nombreProduits_ = 0;
}


string Rayon::obtenirCategorie() const
{
	return categorie_;
}

Produit ** Rayon::obtenirTousProduits() const
{
	return tousProduits_;
}

int Rayon::obtenirCapaciteProduits() const
{
	return capaciteProduits_;
}

int Rayon::obtenirNombreProduits() const
{
	return nombreProduits_;
}

void Rayon::modifierCategorie(string cat)
{
	categorie_ = cat;
}

void Rayon::ajouterProduit(Produit* produit)
{
	if (tousProduits_ == nullptr)
		creerTableau();
	if (nombreProduits_ >= capaciteProduits_)
		augmenterCapaciteTableau();
	tousProduits_[nombreProduits_++] = produit;
}

void Rayon::creerTableau()
{
	capaciteProduits_ += INCREMENT_CAPACITE;
	tousProduits_ = new Produit*[capaciteProduits_];
}

void Rayon::augmenterCapaciteTableau()
{
	capaciteProduits_ += INCREMENT_CAPACITE;
	Produit** temp = new Produit*[capaciteProduits_];
	for (int i = 0; i < nombreProduits_; ++i)
	{
		temp[i] = tousProduits_[i];
	}
	delete[] tousProduits_;
	tousProduits_ = temp;
}

void Rayon::afficher() const
{
	cout << "Categorie Rayon: " << categorie_ << endl;
	cout << " Produits disponibles: " << endl;
	for (int i = 0; i < nombreProduits_; ++i)
	{
		tousProduits_[i]->afficher();
	}
}