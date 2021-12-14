#include "Cours.h"

Cours::Cours() : Event()
{
	#ifdef DEBUG
    cout << "Cours : constructeur par defaut" << endl;
    #endif

    idProfesseur = -1;
    idLocal = -1;
    idGroupes = Liste<int>();
}

Cours::Cours(int code, const char* intitule, Timing timing, int idp, int idl, Liste<int> idg) : Event(code, intitule, timing)
{
	#ifdef DEBUG
    cout << "Cours : constructeur d'initialisation complet" << endl;
    #endif

    setIdProfesseur(idp);
    setIdLocal(idl);
    idGroupes = idg;
}

Cours::Cours(int code, const char* intitule, int idp, int idl, Liste<int> idg) : Event(code, intitule)
{
	#ifdef DEBUG
    cout << "Cours : constructeur d'initialisation partiel" << endl;
    #endif

    setIdProfesseur(idp);
    setIdLocal(idl);
    idGroupes = idg;
}

Cours::Cours(const Cours& copie) : Event(copie)
{
	#ifdef DEBUG
    cout << "Cours : constructeur de copie" << endl;
    #endif

    setIdProfesseur(copie.idProfesseur);
    setIdLocal(copie.idLocal);
    idGroupes = copie.idGroupes;
}

Cours::~Cours()
{
	#ifdef DEBUG
    cout << "Cours : destructeur" << endl;
    #endif

}

int Cours::getIdProfesseur() const
{
	return idProfesseur;
}

int Cours::getIdLocal() const
{
	return idLocal;
}

void Cours::setIdProfesseur(int id)
{
	idProfesseur = id;
}

void Cours::setIdLocal(int id)
{
	idLocal = id;
}

Cours& Cours::operator=(const Cours& c)
{
	setIdProfesseur(c.idProfesseur);
	setIdLocal(c.idLocal);
	idGroupes = c.idGroupes;

	return (*this);
}

ostream& operator<<(ostream& s, const Cours& c)
{
	s << "idProfesseur: " << c.getIdProfesseur() << "idLocal: " << c.getIdLocal();
	Liste<int> l = c.idGroupes;
	Liste<int> &ref = l;
	Iterateur<int> it(ref);
    for (it.reset() ; !it.end() ; it++)
    {
    	int g = (int)it;
    	s << " " << g << " ";
  	}

  	return s;
}

bool Cours::operator>(const Cours& c) const
{
	Cours x(*this);
  	bool resultat = false;

  	if(x.getTiming() > c.getTiming())
  		resultat = true;

  	return resultat;
}

bool Cours::operator<(const Cours& c) const
{
	Cours x(*this);
  	bool resultat = false;

  	if(x.getTiming() < c.getTiming())
  		resultat = true;

  	return resultat;
}

bool Cours::operator==(const Cours& c) const
{
	Cours x(*this);
  	bool resultat = false;

  	if(x.getTiming() == c.getTiming())
  		resultat = true;

  	return resultat;
}

void Cours::ajouteIdGroupe(int id)
{
    int &ref = id;
    idGroupes.insere(ref);
}

bool Cours::contientIdGroupe(int id)
{
	bool resultat = false;

	Iterateur<int> it(idGroupes);
	int g = (int)it;
    for (it.reset() ; !it.end() && g != id; it++)
    {
    	g = (int)it;
  	}

  	if(g == id)
  	{
  		resultat = true;
  	}

  	return resultat;
}










