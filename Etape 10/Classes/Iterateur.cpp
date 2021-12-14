#include"Iterateur.h"

template<class T>
Iterateur<T>::~Iterateur()
{
	#ifdef DEBUG
    cout << "Iterateur : destructeur" << endl;
    #endif
}

template<class T>
void Iterateur<T>::reset()
{
    pCur = lis.getPtete();
}

template<class T>
bool Iterateur<T>::end() const
{
    bool resultat = false;

    if(pCur == NULL)
    	resultat = true;

    return resultat;
}

template<class T>
Iterateur<T>::operator T()
{
    return (pCur->valeur);
}

template<class T>
bool Iterateur<T>::operator++()
{
    if (pCur != NULL)
    {
        pCur = pCur->suivant;
        return true;
    }

    return false;
}

template<class T>
bool Iterateur<T>::operator++(int)
{
    return operator++();
}

template class Iterateur<int>;

#include "Professeur.h"
template class Iterateur<Professeur>;

#include "Groupe.h"
template class Iterateur<Groupe>;

#include "Local.h"
template class Iterateur<Local>;

#include "Cours.h"
template class Iterateur<Cours>;