#include"Exception.h"

Exception::Exception()
{
	#ifdef DEBUG
    cout << "Exception : constructeur par defaut" << endl;
    #endif

    message = NULL;
}

Exception::Exception(const char* m)
{
	#ifdef DEBUG
    cout << "Exception : constructeur d'initialisation" << endl;
    #endif

    message = NULL;
    setMessage(m);
}

Exception::Exception(const Exception& copie)
{
	#ifdef DEBUG
    cout << "Exception : constructeur de copie" << endl;
    #endif

    message = NULL;
    setMessage(copie.getMessage());
}

Exception::~Exception()
{
	#ifdef DEBUG
    cout << "Exception : destructeur" << endl;
    #endif

    if(message)
    	delete message;
}

const char* Exception::getMessage() const
{
	return message;
}

void Exception::setMessage(const char* m)
{
	if(m == NULL)
		return;
	if(message)
		delete message;
	message = new char[strlen(m) + 1];
	strcpy(message, m);
}