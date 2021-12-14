#ifndef LOCAL
#define LOCAL

#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <iostream>
using namespace std;

#include "Planifiable.h"

class Local : public Planifiable
{
	private:
		char* nom;

	public:
		//CONSTRUCTEUR
		Local();
		Local(int i, const char* n);
		Local(const Local& copie);

		//DESTRUCTEUR
		~Local();

		//GETTEUR
		const char* getNom() const;

		//SETTEUR
		void setNom(const char* n);

		//OPERATEUR
		Local& operator=(const Local& l);
		friend ostream& operator<<(ostream& s, const Local& l);

		//METHODE
		const char* Txt();
		const char* Tuple();

};

#endif
