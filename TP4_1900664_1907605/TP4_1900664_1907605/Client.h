/********************************************
* Titre: Travail pratique #4 - Client.h
* Date: 1 mars 2018
* Auteur: Frédéric Fortin 1900664 Antoine Lamontagne 1907605
*******************************************/
/********************************************
Réponse au questions:
1. 1
2. Puisque le vecteur est un vecteur de pointeur de A, la fonction qui est appelé est celle de la classe A. Ensuite, puisque la fonction de la classe A n'est pas virtual,
	c'est celle de la classe A qui est appelé et non celle de la classe B.
3. Une première solution serait d'enlever le mot clé virtual de la classe B pour ne pas que la fonction de la classe C se fasse appeler.
	une deuxième solution serait de caster l'objet de classe C en un objet de classe B en l'ajoutant au vecteur de pointeur de B.
4. On ne peut pas instancier un objet de la classe Usager, car c'est une classe virtuelle pure. Certaines de ses fonctions seront seulement définies dans les classes héritantes d'Usager.
5. Si l'on a un vecteur de produit contenant tous les types de produits (ProduitSolde et ProduitAuxEncheres), on peut parcourir tous les elements du vecteur en leur faisant passer un test.
	Le test consiste à appliquer un dynamic_cast sur le produit en essayant de le convertir en produitSolde. Si le cast réussi (le pointeur de l'objet n'est pas nul),
	on ajoute ce produit à un vecteur de ProduitSolde sinon on l'ajoute à un vecteur de ProduitAuxEncheres. Ensuite on peut afficher les vecteurs un après l'autre.
********************************************/
#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include "Usager.h"
#include "Produit.h"

using namespace std;

class Client : public Usager
{
  public:
    Client(unsigned int codeClient = 0);
    Client(const string &nom, const string &prenom, int identifiant, const string &codePostal, unsigned int codeClient = 0);

    unsigned int obtenirCodeClient() const;
    vector<Produit *> obtenirPanier() const;
	//virtual ajoute pour modifier le total d'un client s'il est membre
    virtual double obtenirTotalAPayer() const;
    void afficherPanier() const;
	//virtual ajoute pour differencier un client et un membre
	virtual void afficherProfil() const;

    void modifierCodeClient(unsigned int codeClient);
	//Mot cle virtual pour clarifier le code
    virtual void enleverProduit(Produit *produit);
    virtual void ajouterProduit(Produit *produit);
    virtual void reinitialiser();
  
  protected:
    vector<Produit *> panier_;

  private:
    unsigned int codeClient_;
};

#endif
