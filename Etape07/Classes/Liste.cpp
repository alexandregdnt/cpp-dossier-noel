#include "Liste.h"

template<class T> 
Liste<T>::Liste()
{
	#ifdef DEBUG
    cout << "Liste : constructeur par defaut" << endl;
    #endif

    pTete = NULL;
}

template<class T>
Liste<T>::Liste(const Liste<T>& copie)
{
	#ifdef DEBUG
    cout << "Liste : constructeur de copie" << endl;
    #endif

    if (copie.pTete == NULL)
        pTete = NULL;
    else
    {
        Cellule<T> *tmp = NULL;
        Cellule<T> *curThis = NULL;
        Cellule<T> *curCopy = copie.pTete;

        pTete = new Cellule<T>;
        pTete->valeur = curCopy->valeur;
        pTete->suivant = NULL;

        curCopy = curCopy->suivant;
        curThis = pTete;

        while (curCopy != NULL)
        {
            tmp = new Cellule<T>;
            tmp->valeur = curCopy->valeur;
            tmp->suivant = NULL;

            curCopy = curCopy->suivant;
            curThis->suivant = tmp;
            curThis = tmp;
        }
    }
}

template<class T>
Liste<T>::~Liste()
{
    #ifdef DEBUG
    cout << "Liste : destructeur" << endl;
    #endif

    Cellule<T> *tmp;

    while(pTete != NULL)
    {
        tmp = pTete->suivant;
        delete pTete;
        pTete = tmp;
    }
}

template<class T>
Cellule<T> *Liste<T>::getPtete() const
{
    return pTete;
}

template<class T>
void Liste<T>::setPtete(Cellule<T> *t)
{
    pTete = t;
}

template<class T>
bool Liste<T>::estVide() const
{
    if (pTete == NULL)
        return true;
    return false;
}

template<class T>
int Liste<T>::getNombreElements() const
{
    int i = 0;
    Cellule<T> *tmp = pTete;

    while(tmp != NULL)
    {
        tmp = tmp->suivant;
        i++;
    }

    return i;
}

template<class T>
void Liste<T>::Affiche() const
{
    Cellule<T> *tmp = pTete;
    if(tmp == NULL)
    {
        cout << "()" << endl;
    }
    else
    {
        cout << "( ";
        while (tmp != NULL)
        {
            cout <<tmp->valeur << " ";
            tmp = tmp->suivant;
        }
        cout << ")" << endl;
    }
    
}

template<class T>
void Liste<T>::insere(const T& val)
{
    if (estVide())
    {
        pTete = new Cellule<T>;
        pTete->valeur = val;
        pTete->suivant = NULL;
    }
    else
    {
        Cellule<T> *tmp = pTete;
        while (tmp->suivant != NULL)
        {
            tmp = tmp->suivant;
        }
        Cellule<T> *newCell = new Cellule<T>;
        newCell->valeur = val;
        newCell->suivant = NULL;
        tmp->suivant = newCell;
    }
}

template<class T>
T Liste<T>::retire(int ind)
{
    if(ind < 0 || ind > (getNombreElements() - 1))
    {
        //EXCEPTION (throw)
    }
    
    int i = 0;
    T valRetour;
    Cellule<T> *pPrec = NULL; 
    Cellule<T> *tmp = pTete;
    
    while(i != ind)
    {
        pPrec = tmp;
        tmp = tmp->suivant;
        i++;
    }
        
    if(pPrec == NULL)
        pTete = tmp->suivant;
    else
        pPrec->suivant = tmp->suivant;
        
    valRetour = tmp->valeur;
    delete tmp;

    return valRetour;
}

template<class T>
Liste<T>& Liste<T>::operator=(const Liste<T>& c)
{
    if (pTete != NULL)
        delete this;

    if (c.pTete != NULL)
    {
        Cellule<T> *tmp = NULL;
        Cellule<T> *curThis = NULL;
        Cellule<T> *curCopy = c.pTete;

        pTete = new Cellule<T>;
        pTete->valeur = curCopy->valeur;
        pTete->suivant = NULL;

        curCopy = curCopy->suivant;
        curThis = pTete;

        while (curCopy != NULL)
        {
            tmp = new Cellule<T>;
            tmp->valeur = curCopy->valeur;
            tmp->suivant = NULL;

            curCopy = curCopy->suivant;
            curThis->suivant = tmp;
            curThis = tmp;
        }
    }

    return (*this);
}

template struct Cellule<int>;
template class Liste<int>;

#include "Professeur.h"
template struct Cellule<Professeur>;
template class Liste<Professeur>;





