#ifndef COURS
#define COURS

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Liste.h"
#include "ListeTriee.h"
#include "Iterateur.h"
#include "Event.h"
using namespace std;

class Cours : public Event
{
	private:
		int idProfesseur;
		int idLocal;
	
	public:
		//VARIABLE
		Liste<int> idGroupes;

		//CONSTRUCTEUR
		Cours();
		Cours(int code, const char* intitule, Timing timing, int idp, int idl, Liste<int> idg);
		Cours(int code, const char* intitule, int idp, int idl, Liste<int> idg);
		Cours(const Cours& copie);

		//DESTRUCTEUR
		~Cours();

		//GETTEUR
		int getIdProfesseur() const;
		int getIdLocal() const;

		//SETTEUR
		void setIdProfesseur(int id);
		void setIdLocal(int id);

		//OPERATEUR
		Cours& operator=(const Cours& c);
		friend ostream& operator<<(ostream& s, const Cours& c);
		bool operator>(const Cours& c) const;
      	bool operator<(const Cours& c) const;
      	bool operator==(const Cours& c) const;

      	//METHODE
      	void ajouteIdGroupe(int id);
      	bool contientIdGroupe(int id);
};

#endif