#include "Groupe.h"

Groupe::Groupe() : Planifiable()
{
	#ifdef DEBUG
    cout << "Groupe : constructeur par defaut" << endl;
    #endif

    numero = -1;
}

Groupe::Groupe(int i, int n) : Planifiable(i)
{
	#ifdef DEBUG
    cout << "Groupe : constructeur d'initialisation" << endl;
    #endif

    setNumero(n);
}

Groupe::Groupe(const Groupe& copie) : Planifiable(copie)
{
	#ifdef DEBUG
    cout << "Groupe : constructeur de copie" << endl;
    #endif

    setNumero(copie.getNumero());
}

Groupe::~Groupe()
{
	#ifdef DEBUG
    cout << "Groupe : destructeur" << endl;
    #endif
}

int Groupe::getNumero() const
{
	return numero;
}

void Groupe::setNumero(int n)
{
	if(n < 1)
		return;
	numero = n;
}

Groupe& Groupe::operator=(const Groupe& g)
{
	setId(g.getId());
	setNumero(g.getNumero());

	return (*this);
}

ostream& operator<<(ostream& s, const Groupe& g)
{
	s << "G" << g.getNumero();

	return s;
}

bool Groupe::operator>(const Groupe& g) const
{
	Groupe h(*this);
  	bool resultat = false;

  	if(h.getNumero() > g.getNumero())
  	{
  		resultat = true;
  	}

  	return resultat;
}

bool Groupe::operator<(const Groupe& g) const
{
	Groupe h(*this);
  	bool resultat = false;

  	if(h.getNumero() < g.getNumero())
  	{
  		resultat = true;
  	}

  	return resultat;
}

bool Groupe::operator==(const Groupe& g) const
{
	Groupe h(*this);
  	bool resultat = false;

  	if(h.getNumero() == g.getNumero())
  	{
  		resultat = true;
  	}

  	return resultat;
}

const char* Groupe::Txt()
{
	char buf[50];
	
	sprintf(buf, "G%d", getNumero());
	setTxt(buf);

	return getTxt();
}

const char* Groupe::Tuple()
{
	char buf[50];

	sprintf(buf, "%d;G%d", getId(), getNumero());
	setTuple(buf);

	return getTuple();
}