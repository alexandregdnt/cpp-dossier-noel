#ifndef TIMING
#define TIMING

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "Temps.h"
using namespace std;

#include"TimingException.h"

class Timing
{
	private :
		char* jour;
		Temps heure;
		Temps duree;

		//METHODE PRIVEE
		int numJour(const char* jour) const;

	public :
		//VARIABLES
    	static const char* LUNDI; 
    	static const char* MARDI;
    	static const char* MERCREDI;
    	static const char*JEUDI; 
    	static const char* VENDREDI;
    	static const char* SAMEDI;
    	static const char* DIMANCHE;

		//CONSTRUCTEUR
		Timing();
		Timing(const char* j, Temps h, Temps d);
		Timing(const Timing& time);

		//DESTRUCTEUR
		~Timing();

		//GETTEUR
		const char* getJour() const;
		Temps getHeure() const;
		Temps getDuree() const;


		//SETTEUR
		void setJour(const char* j);
		void setHeure(const Temps& h);
		void setDuree(const Temps& d);

		//AFFICHAGE
		void Affiche() const;

		//OPERATEUR
		int operator>(const Timing& t) const;
      	int operator<(const Timing& t) const;
      	int operator==(const Timing& t)const;

      	//METHODE
      	void Save(ofstream& fichier) const;
      	void Load(ifstream& fichier);
};

#endif