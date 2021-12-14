#include "Local.h"

Local::Local() : Planifiable()
{
	#ifdef DEBUG
    cout << "Local : constructeur par defaut" << endl;
    #endif

    nom = NULL;
}

Local::Local(int i, const char* n) : Planifiable(i)
{
	#ifdef DEBUG
    cout << "Local : constructeur d'initialisation" << endl;
    #endif

    nom = NULL;
    setNom(n);
}

Local::Local(const Local& copie) : Planifiable(copie)
{
	#ifdef DEBUG
    cout << "Local : constructeur de copie" << endl;
    #endif

    nom = NULL;
    setNom(copie.getNom());
}

Local::~Local()
{
	#ifdef DEBUG
    cout << "Local : destructeur" << endl;
    #endif

    if(nom)
    	delete nom;
}

const char* Local::getNom() const
{
	return nom;
}


void Local::setNom(const char* n)
{
	if(n == NULL)
		return;
	if(nom)
		delete nom;
	nom = new char[strlen(n) + 1];
	strcpy(nom, n);
}

Local& Local::operator=(const Local& l)
{
	setId(l.getId());
	setNom(l.getNom());

	return (*this);
}

ostream& operator<<(ostream& s, const Local& l)
{
	if(l.getNom())
		s << l.getNom();
	else
		s << "/";

	return s;
}

bool Local::operator>(const Local& l) const
{
	Local h(*this);
  	bool resultat = false;

  	if(strcmp(h.getNom(), l.getNom()) > 0)
  	{
  		resultat = true;
  	}

  	return resultat;
}

bool Local::operator<(const Local& l) const
{
	Local h(*this);
  	bool resultat = false;

  	if(strcmp(h.getNom(), l.getNom()) < 0)
  	{
  		resultat = true;
  	}

  	return resultat;
}

bool Local::operator==(const Local& l) const
{
	Local h(*this);
  	bool resultat = false;

  	if(strcmp(h.getNom(), l.getNom()) == 0)
  	{
  		resultat = true;
  	}

  	return resultat;
}

const char* Local::Txt()
{
	char buf[50];
	
	sprintf(buf, "%s", getNom());
	setTxt(buf);

	return getTxt();
}

const char* Local::Tuple()
{
	char buf[50];
	
	sprintf(buf, "%d;%s", getId(), getNom());
	setTuple(buf);

	return getTuple();
}