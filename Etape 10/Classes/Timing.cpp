#include "Timing.h"

const char* Timing::LUNDI ("Lundi");
const char* Timing::MARDI ("Mardi");
const char* Timing::MERCREDI ("Mercredi");
const char* Timing::JEUDI ("Jeudi");
const char* Timing::VENDREDI ("Vendredi");
const char* Timing::SAMEDI ("Samedi");
const char* Timing::DIMANCHE ("Dimanche");

Timing::Timing()
{
	#ifdef DEBUG
    cout << "Timing : constructeur par defaut" << endl;
    #endif

    jour = NULL;
    heure.setHeure(0);
    heure.setMinute(0);
    duree.setHeure(0);
    duree.setMinute(0);
}

Timing::Timing(const char* j, Temps h, Temps d)
{
	#ifdef DEBUG
    cout << "Timing : constructeur d'initialisation" << endl;
    #endif

    jour = NULL;
    setJour(j);
    heure.setHeure(h.getHeure());
    heure.setMinute(h.getMinute());
    duree.setHeure(d.getHeure());
    duree.setMinute(d.getMinute());
}

Timing::Timing(const Timing& time)
{
    #ifdef DEBUG
    cout << "Timing : constructeur de copie" << endl;
    #endif

    jour = NULL;
    setJour(time.getJour());
    setHeure(time.getHeure());
    setDuree(time.getDuree());
}

Timing::~Timing()
{
    #ifdef DEBUG
    cout << "Timing : destructeur" << endl;
    #endif

    if(jour)
        delete[] jour;
}

const char* Timing::getJour() const
{
    return jour;
}

Temps Timing::getHeure() const
{
    return heure;
}

Temps Timing::getDuree() const
{
    return duree;
}

void Timing::setJour(const char* j)
{
    if(j == NULL  || numJour(j) == 0)
      throw(TimingException("Jour invalide !", TimingException::JOUR_INVALIDE));
    if(jour)
      delete jour;
    jour = new char[strlen(j) + 1];
    strcpy (jour, j);
}

void Timing::setHeure(const Temps& h)
{
    heure.setHeure(h.getHeure());
    heure.setMinute(h.getMinute());
}

void Timing::setDuree(const Temps& d)
{
    duree.setHeure(d.getHeure());
    duree.setMinute(d.getMinute());
}

void Timing::Affiche() const
{
    cout << "Timing : heure ";
        heure.Affiche();
    cout << "  duree ";
    duree.Affiche();
    cout << "  jour ";
    if(jour)
      cout << jour << endl;
    else
      cout << "/" << endl;
}

int Timing::operator>(const Timing& t) const
{
    Timing h(*this);
    int resultat = 0;

    if(h.getJour() && t.getJour())
    {
        if(numJour(h.getJour()) > numJour(t.getJour()))
        {
            resultat = 1;
        }
        else
        {
            if(numJour(h.getJour()) == numJour(t.getJour()) && h.getHeure() > t.getHeure())
            {
                resultat = 1;
            }
            else
            {
                if(numJour(h.getJour()) == numJour(t.getJour()) && h.getHeure() == t.getHeure() && h.getDuree() > t.getDuree())
                    resultat = 1;
            }
        }
    }
    else
    {
        cout << "Erreur : Jour n'est pas initialisé !" << endl;
    }

    return resultat;
}

int Timing::operator<(const Timing& t) const
{
    Timing h(*this);
    int resultat = 0;

    if(h.getJour() && t.getJour())
    {
        if(numJour(h.getJour()) < numJour(t.getJour()))
        {
            resultat = 1;
        }
        else
        {
            if(numJour(h.getJour()) == numJour(t.getJour()) && h.getHeure() < t.getHeure())
            {
                resultat = 1;
            }
            else
            {
                if(numJour(h.getJour()) == numJour(t.getJour()) && h.getHeure() == t.getHeure() && h.getDuree() < t.getDuree())
                    resultat = 1;
            }
        }
    }
    else
    {
        cout << "Erreur : Jour n'est pas initialisé !" << endl;
    }
    
    return resultat;
}

int Timing::operator==(const Timing& t) const
{
    Timing h(*this);
    int resultat = 0;

    if(h.getJour() && t.getJour())
    {
        if(numJour(h.getJour()) == numJour(t.getJour()))
        {
            if(h.getHeure() == t.getHeure())
            {
                if(h.getDuree() == t.getDuree())
                    resultat = 1;
            }
        }
    }
    else
    {
        cout << "Erreur : Jour n'est pas initialisé !" << endl;
    }

    return resultat;
}

int Timing::numJour(const char* jour) const
{
    int resultat = 0;

    if(!strcmp(jour, "Lundi"))
    {
        resultat = 1;
    }
    else
    {
        if(!strcmp(jour, "Mardi"))
        {
            resultat = 2;
        }
        else
        {
            if(!strcmp(jour, "Mercredi"))
            {
                resultat = 3;
            }
            else
            {
                if(!strcmp(jour, "Jeudi"))
                {
                    resultat = 4;
                }
                else
                {
                    if(!strcmp(jour, "Vendredi"))
                    {
                        resultat = 5;
                    }
                    else
                    {
                        if(!strcmp(jour, "Samedi"))
                        {
                            resultat = 6;
                        }
                        else
                        {
                            if(!strcmp(jour, "Dimanche"))
                                resultat = 7;
                        }
                    }
                }
            }
        }
    }

    return resultat;
}

void Timing::Save(ofstream& fichier) const
{
    if(fichier.is_open())
    {
        char *j = new char[strlen(getJour()) + 1];
        strcpy(j, getJour());
        int taille = strlen(j);

        Temps h(getHeure());
        Temps d(getDuree());

        fichier.write((char *)&taille, sizeof(int));
        fichier.write((char *)j, taille);

        h.Save(fichier);
        d.Save(fichier);

        if(j)
            delete j;
    }
}

void Timing::Load(ifstream& fichier)
{
    if(fichier.is_open())
    {
        int taille;
        Temps h, d;

        fichier.read((char *)&taille, sizeof(int));
        char *j = new char[taille + 1];
        fichier.read((char *)j, taille);
        
        h.Load(fichier);
        d.Load(fichier);
        
        setJour(j);
        setHeure(h);
        setDuree(d);

        if(j)
            delete j;
    }
}