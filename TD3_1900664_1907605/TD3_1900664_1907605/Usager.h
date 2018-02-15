/********************************************
* Titre: Travail pratique #3 - Usager.h
* Date: 15 fevrier 2017
* Auteur: Fr�d�ric Fortin 1900664 Antoine Lamontagne 1907605
*******************************************/

#ifndef USAGER_H
#define USAGER_H

#include <string>
using namespace std;
class Usager
{

public:
	Usager(const string&  nom, const string& prenom, int identifiant, const string& codePostal);
	
	string obtenirNom() const;
	string obtenirPrenom() const;
	int obtenirIdentifiant() const;
	string obtenirCodePostal() const;	
	
	
	void modifierNom(const string& nom);
	void modifierPrenom(const string & prenom);
	void modifierIdentifiant(int identifiant);
	void modifierCodePostal(const string & codePostal);

	Usager & operator=(const Usager& usager);
	bool operator==(int indentifiant) const;
	bool operator == (const Usager & usager);
	friend bool operator==(int indentifiant, const Usager& usager);
	friend ostream& operator<<(ostream& os, const Usager& u);

private:
	string nom_;
	string prenom_;
	int identifiant_;
	string codePostal_;
	
};

#endif