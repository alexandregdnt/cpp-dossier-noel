#ifndef TIMINGEXCEPTION
#define TIMINGEXCEPTION

#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

#include"Exception.h"



class TimingException : public Exception
{
	private:
		int code;

	public:
		//VARIABLES
		static const int JOUR_INVALIDE; 
    	static const int AUCUN_TIMING;

		//CONSTRUCTEUR
		TimingException();
		TimingException(const char* m, int c);
		TimingException(const TimingException& copie);

		//DESTRUCTEUR
		~TimingException();

		//GETTEUR
		int getCode() const;

		//SETTEUR
		void setCode(int c);
};

#endif