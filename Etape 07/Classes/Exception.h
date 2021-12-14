#ifndef EXCEPTION
#define EXCEPTION

#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;



class Exception
{
	private:
		char* message;

	public:
		//CONSTRUCTEUR
		Exception();
		Exception(const char* m);
		Exception(const Exception& copie);

		//DESTRUCTEUR
		virtual ~Exception();

		//GETTEUR
		const char* getMessage() const;

		//SETTEUR
		void setMessage(const char* m);

		//METHODE
		virtual int getCode() const = 0;

};

#endif