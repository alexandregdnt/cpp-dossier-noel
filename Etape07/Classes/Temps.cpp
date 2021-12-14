#include "Temps.h"


Temps::Temps()
{
	#ifdef DEBUG
    cout << "Temps : constructeur par defaut" << endl;
    #endif
    
    heure = -1;
    minute = -1;
}

Temps::Temps(int h, int m)
{
	#ifdef DEBUG
    cout << "Temps : constructeur d'initialisation" << endl;
    #endif
    
    setHeure(h);
    setMinute(m);
}

Temps::Temps(int d)
{
  #ifdef DEBUG
    cout << "Temps : constructeur d'initialisation duree" << endl;
    #endif
    
    setHeure(d/60);
    setMinute(d%60);
}

Temps::Temps(const Temps& t)
{
	#ifdef DEBUG
    cout << "Temps : constructeur de copie" << endl;
    #endif

    setHeure(t.getHeure());
    setMinute(t.getMinute());
}

Temps::~Temps()
{
	#ifdef DEBUG
    cout << "Temps : destructeur" << heure << "h" << minute << endl;
    #endif

}

int Temps::getHeure() const
{
	return heure;
}

int Temps::getMinute() const
{
	return minute;
}

void Temps::setHeure(int h)
{
	if(h < 0 || h > 23)
    throw(TempsException("Heure invalide ! L'heure doit etre comprise entre 0 et 23", TempsException::HEURE_INVALIDE));
	heure = h;
}

void Temps::setMinute(int m)
{
	if(m < 0 || m > 59)
		throw(TempsException("Minute invalide ! La minute doit etre comprise entre 0 et 59", TempsException::MINUTE_INVALIDE));
	minute = m;
}

void Temps::Affiche() const
{
  cout << heure;
  if(minute < 10)
    cout << "h0";
  else
    cout << "h";
  cout << minute << endl;
}

Temps& Temps::operator=(const Temps& t) 
{
  setHeure(t.getHeure());
  setMinute(t.getMinute());

  return (*this);
}

Temps Temps::operator+(int d)
{
  Temps h(*this);
  int heure, minute;

  if((h.getMinute() + d) < 60)
  {
    minute = h.getMinute() + d;
    heure = h.getHeure();
  }
  else
  {
    heure = h.getHeure() + ((h.getMinute() + d) / 60);
    minute = (h.getMinute() + d) % 60;
  }
  
  if(heure > 23 || heure < 0)
      throw(TempsException("Le resultat n'est pas compris entre 0h00 et 23h59 !", TempsException::DEPASSEMENT));
  
  h.setHeure(heure);
  h.setMinute(minute);
  
  return h;
}

Temps Temps::operator+(const Temps& t)
{
  Temps h(*this);
  int heure, minute;

  if((getMinute() + t.getMinute()) < 60)
  {
    heure = getHeure() + t.getHeure();
    minute = getMinute() + t.getMinute();
  }
  else
  {
    heure = getHeure() + t.getHeure() + ((getMinute() + t.getMinute()) / 60);
    minute = (getMinute() + t.getMinute()) % 60;
  }

  if(heure > 23 || heure < 0)
    throw(TempsException("Le resultat n'est pas compris entre 0h00 et 23h59 !", TempsException::DEPASSEMENT));
  
  h.setHeure(heure);
  h.setMinute(minute);

  return h;
}

Temps operator+(int d, Temps t)
{
  return (t + d);
}

Temps Temps::operator-(int d) 
{
  Temps h(*this);
  int heure, minute;
  int tmp = 0;

  if(h.getMinute() >= d)
  {
    minute = h.getMinute() - d;
  }
  else
  {
    if(h.getMinute() >= d % 60)
    {
      minute = h.getMinute() - d % 60;
    }
    else
    {
      tmp++;
      minute = 60 + h.getMinute() - d % 60;
    }
    
  }
  
  heure = h.getHeure() - tmp - d / 60;

  if(heure > 23 || heure < 0)
    throw(TempsException("Le resultat n'est pas compris entre 0h00 et 23h59 !", TempsException::DEPASSEMENT));

  h.setMinute(minute);
  h.setHeure(heure);
  
  return h;
}

Temps Temps::operator-(const Temps& t)
{
  Temps h(*this);
  int heure, minute;
  int tmp = 0;

  if(getMinute() >= t.getMinute())
  {
    minute = getMinute() - t.getMinute();
  }  
  else
  {
    if(getMinute() >= t.getMinute() % 60)
    {
      minute = getMinute() - t.getMinute() % 60;
    }
    else
    {
      tmp++;
      minute = 60 + getMinute() - t.getMinute() % 60;
    }
  }  
    
  heure = getHeure() - t.getHeure() - tmp - t.getMinute() / 60;

  if(heure > 23 || heure < 0)
    throw(TempsException("Le resultat n'est pas compris entre 0h00 et 23h59 !", TempsException::DEPASSEMENT));

  h.setMinute(minute);
  h.setHeure(heure);

  return h;
}

Temps operator-(int d, Temps t)
{
  return (Temps(d) - t);
}

int Temps::operator>(const Temps& t) const
{
  Temps h(*this);
  int resultat = 0;

  if(h.getHeure() > t.getHeure())
  {
    resultat = 1;
  }
  else
  {
    if(h.getHeure() == t.getHeure() && h.getMinute() > t.getMinute())
      resultat = 1;
  }

  return resultat;
}

int Temps::operator<(const Temps& t) const 
{
  Temps h(*this);
  int resultat = 0;

  if(h.getHeure() < t.getHeure())
  {
    resultat = 1;
  }
  else
  {
    if(h.getHeure() == t.getHeure() && h.getMinute() < t.getMinute())
      resultat = 1;
  }

  return resultat;
}

int Temps::operator==(const Temps& t) const
{
  Temps h(*this);
  int resultat = 0;

  if(h.getHeure() == t.getHeure() && h.getMinute() == t.getMinute())
    resultat = 1;

  return resultat;
}

ostream& operator<<(ostream& s, const Temps& t)
{
  
  if(t.getMinute() < 10)
    s << t.getHeure() << "h0" << t.getMinute();
  else
    s << t.getHeure() << "h" << t.getMinute();

  return s;
}

istream& operator>>(istream& s, Temps& t)
{
  int h, m, erreur;
  char heure[10];

  do{
    s >> heure;
    if(heure[2] == 'h')
    {
      h = (heure[0] - '0') * 10;
      h = h + (heure[1] - '0');
      m = (heure[3] - '0') * 10;
      m = m + (heure[4] - '0');
    }
    else
    {
      if(heure[1] == 'h')
      {
        h = heure[0] - '0';
        m = (heure[2] - '0') * 10;
        m = m + (heure[3] - '0');
      }
    }
    
    if(heure[2] != 'h' && heure[1] != 'h')
    {
      erreur = 1;
      throw(TempsException("Valeur saisie incorrecte !", TempsException::FORMAT_INVALIDE));
      cout << "Recommencez: ";
    }
    else
    {
      erreur = 0;
    }  
  }while(erreur);

  t.setHeure(h);
  t.setMinute(m);

  return s;
}

Temps Temps::operator++()
{
  Temps tmp(*this);

  (*this) = tmp + 30;

  return (*this);
}

Temps Temps::operator++(int i)
{
  Temps tmp(*this);

  (*this) = (*this) + 30;

  return tmp;
}

Temps Temps::operator--()
{
  Temps tmp(*this);

  (*this) = tmp - 30;

  return (*this);
}

Temps Temps::operator--(int i)
{
  Temps tmp(*this);

  (*this) = (*this) - 30;

  return tmp;
}

void Temps::Save(ofstream& fichier) const
{
  if(fichier.is_open())
  {
    int h = getHeure();
    int m = getMinute();

    fichier.write((char *)&h, sizeof(int));
    fichier.write((char *)&m, sizeof(int));
  }

}

void Temps::Load(ifstream& fichier)
{
  if(fichier.is_open())
  {
    int h, m;

    fichier.read((char *)&h, sizeof(int));
    fichier.read((char *)&m, sizeof(int));

    setHeure(h);
    setMinute(m);
  }
  
}