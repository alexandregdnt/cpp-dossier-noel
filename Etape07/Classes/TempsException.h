#ifndef TEMPSEXCEPTION
#define TEMPSEXCEPTION

#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

#include"Exception.h"



class TempsException : public Exception
{
	private:
		int code;

	public:
		//VARIABLES
		static const int HEURE_INVALIDE; 
    	static const int MINUTE_INVALIDE;
    	static const int DEPASSEMENT;
    	static const int FORMAT_INVALIDE;

		//CONSTRUCTEUR
		TempsException();
		TempsException(const char* m, int c);
		TempsException(const TempsException& copie);

		//DESTRUCTEUR
		~TempsException();

		//GETTEUR
		int getCode() const;

		//SETTEUR
		void setCode(int c);
};

#endif