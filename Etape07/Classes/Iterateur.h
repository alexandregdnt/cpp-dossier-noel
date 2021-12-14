#ifndef ITERATEUR
#define ITERATEUR

#include <iostream>
#include <stdlib.h>
#include"Liste.h"

template<class T>
class Liste;
template<class T>
struct Cellule;

using namespace std;

template<class T>
class Iterateur
{
	private:
		Liste<T> &lis;
    	Cellule<T> *pCur;

	public:
		//CONSTRUCTEUR
		Iterateur(Liste<T> &l) : lis(l), pCur(l.getPtete()){};
    	Iterateur(const Iterateur<T> &c) : lis(c.lis), pCur(c.pCur){};

    	//DESTRUCTEUR
    	~Iterateur();

    	//METHIDE
    	void reset();
    	bool end() const;

    	//OPERATEUR
    	operator T();
    	bool operator++();
    	bool operator++(int);
};

#endif