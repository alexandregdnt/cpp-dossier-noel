#ifndef PLANIFIABLE
#define PLANIFIABLE

#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

class Planifiable
{
	private:
		int id;
		char* txt;
		char* tuple;

	public:
		//VARIABLE
		static int idCourant;

		//CONSTRUCTEUR
		Planifiable();
		Planifiable(int num);
		Planifiable(const Planifiable& copie);

		//DESTRUCTEUR
		virtual ~Planifiable();

		//GETTEUR
		int getId() const;
		const char* getTxt() const;
		const char* getTuple() const;

		//SETTEUR
		void setId(int num);
		void setTxt(const char* t);
		void setTuple(const char* t);

		//OPERATEUR
		virtual Planifiable& operator=(const Planifiable& p); 

		//METHODE
		virtual const char* Txt() = 0;
		virtual const char* Tuple() = 0;

};

#endif