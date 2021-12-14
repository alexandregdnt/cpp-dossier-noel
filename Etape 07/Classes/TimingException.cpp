#include"TimingException.h"

const int TimingException::JOUR_INVALIDE = 0;
const int TimingException::AUCUN_TIMING = 1;

TimingException::TimingException() : Exception()
{
	#ifdef DEBUG
    cout << "TimingException : constructeur par defaut" << endl;
    #endif

    code = -1;
}

TimingException::TimingException(const char* m, int c) : Exception(m)
{
	#ifdef DEBUG
    cout << "TimingException : constructeur d'initialisation" << endl;
    #endif

    setCode(c);
}

TimingException::TimingException(const TimingException& copie) : Exception(copie)
{
	#ifdef DEBUG
    cout << "TimingException : constructeur de copie" << endl;
    #endif

    setCode(copie.getCode());
}

TimingException::~TimingException()
{
	#ifdef DEBUG
    cout << "TimingException : destructeur" << endl;
    #endif
}

int TimingException::getCode() const
{
	return code;
}

void TimingException::setCode(int c)
{
	if(c < 0 || c > 2)
		return;
	code = c;
}
