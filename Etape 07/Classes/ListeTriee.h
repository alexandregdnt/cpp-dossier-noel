#ifndef LISTETRIEE
#define LISTETRIEE

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Liste.h"
using namespace std;

template<class T>
class ListeTriee : public Liste<T>
{
	private:
		using Liste<T>::pTete;
	public:
		//CONSTRUCTEUR
		ListeTriee();
		ListeTriee(const ListeTriee<T>& copie);

		//DESTRUCTEUR
		~ListeTriee();

		//METHODE
		void insere(const T& val);
};

#endif