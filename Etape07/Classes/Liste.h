#ifndef LISTE
#define LISTE

#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

template<class T> 
struct Cellule
{
	T valeur;
	Cellule<T> *suivant;
};

template<class T> 
class Liste
{
	protected:
		Cellule<T> *pTete;

	public:
		//CONSTRUCTEUR
		Liste();
		Liste(const Liste<T>& copie);

		//DESTRUCTEUR
		virtual ~Liste();

		//GETTEUR
		Cellule<T> *getPtete() const;

		//SETTEUR
		void setPtete(Cellule<T> *t);

		//METHODE
		bool estVide() const;
		int getNombreElements() const;
		void Affiche() const;
		virtual void insere(const T& val);
		T retire(int ind);

		//OPERATEUR
		Liste<T> &operator=(const Liste<T>& c);
};

#endif

