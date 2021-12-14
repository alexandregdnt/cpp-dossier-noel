#include "Professeur.h"

Professeur::Professeur() : Planifiable()
{
	#ifdef DEBUG
    cout << "Professeur : constructeur par defaut" << endl;
    #endif

    nom = NULL;
    prenom = NULL;
}

Professeur::Professeur(int i, const char* n, const char* p) : Planifiable(i)
{
	#ifdef DEBUG
    cout << "Professeur : constructeur d'initialisation" << endl;
    #endif

    nom = NULL;
    setNom(n);
    prenom = NULL;
    setPrenom(p);
}

Professeur::Professeur(const Professeur& copie) : Planifiable(copie)
{
	#ifdef DEBUG
    cout << "Professeur : constructeur de copie" << endl;
    #endif

    nom = NULL;
    setNom(copie.getNom());

    prenom = NULL;
    setPrenom(copie.getPrenom());
}

Professeur::~Professeur()
{
	#ifdef DEBUG
    cout << "Professeur : destructeur" << endl;
    #endif

    if(nom)
    	delete nom;
    if(prenom)
    	delete prenom;
}

const char* Professeur::getNom() const
{
	return nom;
}

const char* Professeur::getPrenom() const
{
	return prenom;
}

void Professeur::setNom(const char* n)
{
	if(n == NULL)
		return;
	if(nom)
		delete nom;
	nom = new char[strlen(n) + 1];
	strcpy(nom, n);
}

void Professeur::setPrenom(const char* p)
{
	if(p == NULL)
		return;
	if(prenom)
		delete prenom;
	prenom = new char[strlen(p) + 1];
	strcpy(prenom, p);
}

Professeur& Professeur::operator=(const Professeur& p)
{
	setId(p.getId());
	setNom(p.getNom());
	setPrenom(p.getPrenom());

	return (*this);
}

ostream& operator<<(ostream& s, const Professeur& p)
{
	if(p.getNom() && p.getPrenom())
		s << p.getNom() << " " << p.getPrenom();
	else
		s << "/ /";

	return s;
}

bool Professeur::operator>(const Professeur& p) const
{
	Professeur h(*this);
  	bool resultat = false;

  	if(strcmp(h.getNom(), p.getNom()) > 0)
  	{
  		resultat = true;
  	}
  	else
  	{
  		if(strcmp(h.getNom(), p.getNom()) == 0)
  		{
  			if(strcmp(h.getPrenom(), p.getPrenom()) > 0)
  				resultat = true;
  		}
  	}

  	return resultat;
}

bool Professeur::operator<(const Professeur& p) const
{
	Professeur h(*this);
  	bool resultat = false;

  	if(strcmp(h.getNom(), p.getNom()) < 0)
  	{
  		resultat = true;
  	}
  	else
  	{
  		if(strcmp(h.getNom(), p.getNom()) == 0)
  		{
  			if(strcmp(h.getPrenom(), p.getPrenom()) < 0)
  				resultat = true;
  		}
  	}

  	return resultat;
}

bool Professeur::operator==(const Professeur& p) const
{
	Professeur h(*this);
  	bool resultat = false;

  	if(strcmp(h.getNom(), p.getNom()) == 0)
  	{
  		if(strcmp(h.getPrenom(), p.getPrenom()) == 0)
  			resultat = true;
  	}

  	return resultat;
}

const char* Professeur::Txt() 
{
	char buf[50];

	sprintf(buf,"%s %s", getNom(), getPrenom());
	setTxt(buf); 

	return getTxt();
}

const char* Professeur::Tuple() 
{
	char buf[50];

	sprintf(buf, "%d;%s;%s", getId(), getNom(), getPrenom());
	setTuple(buf);

	return getTuple();
}