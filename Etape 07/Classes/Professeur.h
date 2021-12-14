#ifndef PROFESSEUR
#define PROFESSEUR

#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <iostream>
using namespace std;

#include "Planifiable.h"

class Professeur : public Planifiable
{
	private:
		char* nom;
		char* prenom;

	public:
		//CONSTRUCTEUR
		Professeur();
		Professeur(int i, const char*n, const char*p);
		Professeur(const Professeur& copie);

		//DESTRUCTEUR
		~Professeur();

		//GETTEUR
		const char* getNom() const;
		const char* getPrenom() const;

		//SETTEUR
		void setNom(const char* n);
		void setPrenom(const char* p);

		//OPERATEUR
		Professeur& operator=(const Professeur& p);
		friend ostream& operator<<(ostream& s, const Professeur& p);
		bool operator>(const Professeur& p) const;
      	bool operator<(const Professeur& p) const;
      	bool operator==(const Professeur& p) const;

		//METHODE
		const char* Txt();
		const char* Tuple();

};

#endif