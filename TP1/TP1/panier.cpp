#include "panier.h"

Panier::Panier(int capacite)
	:capaciteContenu_(capacite)
{
	nombreContenu_ = 0;
	totalAPayer_ = 0;
	contenuPanier_ = new Produit*[capacite];
}

Produit ** Panier::obtenirContenuPanier() const
{
	return contenuPanier_;
}

int Panier::obtenirNombreContenu() const
{
	return nombreContenu_;
}

double Panier::obtenirTotalApayer() const
{
	return totalAPayer_;
}

void Panier::ajouter(Produit * prod)
{
	if (capaciteContenu_ == nombreContenu_)
	{
		augmenterCapaciteTableau();
	}
	contenuPanier_[nombreContenu_++] = prod;
}

void Panier::livrer()
{
	for (int i = 0; i < nombreContenu_; i++)
	{
		delete contenuPanier_[i];
		contenuPanier_[i] = nullptr;
	}

	nombreContenu_ = 0;
	totalAPayer_ = 0;
}

void Panier::afficher()
{
	cout << "Contenu du panier: " << endl;

	for (int i = 0; i < nombreContenu_; i++)
	{
		contenuPanier_[i]->afficher();
	};
}

void Panier::augmenterCapaciteTableau()
{
	capaciteContenu_ *= 2;
	Produit** temp = new Produit*[capaciteContenu_];
	for (int i = 0; i < nombreContenu_; ++i)
	{
		temp[i] = contenuPanier_[i];
	}
	delete[] contenuPanier_;
	contenuPanier_ = temp;
}
