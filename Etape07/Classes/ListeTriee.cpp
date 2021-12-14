#include "ListeTriee.h"

template<class T>
ListeTriee<T>::ListeTriee() : Liste<T>()
{
	#ifdef DEBUG
    cout << "ListeTriee : constructeur par defaut" << endl;
    #endif
}

template<class T>
ListeTriee<T>::ListeTriee(const ListeTriee<T>& copie) : Liste<T>(copie)
{
	#ifdef DEBUG
    cout << "ListeTriee : constructeur de copie" << endl;
    #endif
}

template<class T>
ListeTriee<T>::~ListeTriee()
{
	#ifdef DEBUG
    cout << "ListeTriee : destructeur" << endl;
    #endif
}

template<class T>
void ListeTriee<T>::insere(const T& val)
{
	Cellule<T> *newCell = new Cellule<T>;
    newCell->valeur = val;
    newCell->suivant = NULL;

    if(pTete == NULL)
    {
        pTete = newCell;
    }
    else
    {
        Cellule<T> *pPrec = NULL; 
        Cellule<T> *tmp = pTete;
        while(tmp != NULL && newCell->valeur > tmp->valeur)
        {
            pPrec = tmp;
            tmp = tmp->suivant;
        }

        if(pPrec == NULL)
        {
            newCell->suivant = pTete;
            pTete = newCell;
        }
        else
        {
            pPrec->suivant = newCell;
            newCell->suivant = tmp;
        }
    }
}

template class ListeTriee<int>;

#include "Professeur.h"
template class ListeTriee<Professeur>;




