#include"TempsException.h"

const int TempsException::HEURE_INVALIDE = 0;
const int TempsException::MINUTE_INVALIDE = 1;
const int TempsException::DEPASSEMENT = 2;
const int TempsException::FORMAT_INVALIDE = 3;

TempsException::TempsException() : Exception()
{
	#ifdef DEBUG
    cout << "TempsException : constructeur par defaut" << endl;
    #endif

    code = -1;
}

TempsException::TempsException(const char* m, int c) : Exception(m)
{
	#ifdef DEBUG
    cout << "TempsException : constructeur d'initialisation" << endl;
    #endif

    setCode(c);
}

TempsException::TempsException(const TempsException& copie) : Exception(copie)
{
	#ifdef DEBUG
    cout << "TempsException : constructeur de copie" << endl;
    #endif

    setCode(copie.getCode());
}

TempsException::~TempsException()
{
	#ifdef DEBUG
    cout << "TempsException : destructeur" << endl;
    #endif
}

int TempsException::getCode() const
{
	return code;
}

void TempsException::setCode(int c)
{
	if(c < 0 || c > 4)
		return;
	code = c;
}



