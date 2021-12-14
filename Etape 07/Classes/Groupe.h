#ifndef GROUPE
#define GROUPE

#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <iostream>
using namespace std;

#include "Planifiable.h"

class Groupe : public Planifiable
{
	private:
		int numero;

	public:
		//CONSTRUCTEUR
		Groupe();
		Groupe(int i, int n);
		Groupe(const Groupe& copie);

		//DESTRUCTEUR
		~Groupe();

		//GETTEUR
		int getNumero() const;

		//SETTEUR
		void setNumero(int n);

		//OPERATEUR
		Groupe& operator=(const Groupe& g);
		friend ostream& operator<<(ostream& s, const Groupe& g);

		//METHODE
		const char* Txt();
		const char* Tuple();
};

#endif