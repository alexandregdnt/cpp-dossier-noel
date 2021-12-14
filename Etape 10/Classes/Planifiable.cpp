#include "Planifiable.h"

int Planifiable::idCourant = 0;

Planifiable::Planifiable()
{
	#ifdef DEBUG
    cout << "Planifiable : constructeur par defaut" << endl;
    #endif

    id = -1;
    txt = NULL;
    tuple = NULL;
}

Planifiable::Planifiable(int num)
{
	#ifdef DEBUG
    cout << "Planifiable : constructeur d'initialisation" << endl;
    #endif

	setId(num);
	txt = NULL;
    tuple = NULL;
}

Planifiable::Planifiable(const Planifiable& copie)
{
	#ifdef DEBUG
    cout << "Planifiable : constructeur de copie" << endl;
    #endif

    setId(copie.getId());
    txt = NULL;
    tuple = NULL;
}

Planifiable::~Planifiable()
{
	#ifdef DEBUG
    cout << "Planifiable : destructeur" << id << endl;
    #endif

    if(txt)
    	delete txt;
    if(tuple)
    	delete tuple;
}

int Planifiable::getId() const
{
	return id;
}

const char* Planifiable::getTxt() const
{
	return txt;
}

const char* Planifiable::getTuple() const
{
	return tuple;
}

void Planifiable::setId(int num)
{
	if(num < 1)
		return;
	id = num;
}

void Planifiable::setTxt(const char* t)
{
	if(t == NULL)
		return;
	if(txt)
		delete txt;
	txt = new char[strlen(t) + 1];
	strcpy(txt, t);
}

void Planifiable::setTuple(const char* t)
{
	if(t == NULL)
		return;
	if(tuple)
		delete tuple;
	tuple = new char[strlen(t) + 1];
	strcpy(tuple, t);
}

Planifiable& Planifiable::operator=(const Planifiable& p)
{
	setId(p.getId());

	return (*this);
}

