#ifndef LISTE
#define LISTE

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Iterateur.h"

using namespace std;

template<class T> struct Cellule {
    T valeur;
    Cellule<T> *suivant;
};

template<class T> class Liste {
protected:
    Cellule<T> *pTete;

public:
    /*==================== CONSTRUCTEURS ====================*/
    Liste();
    Liste(const Liste<T> &);

    /*==================== DESTRUCTEUR ====================*/
    virtual ~Liste();

    /*==================== MODIFICATEURS ====================*/
    virtual void insere(const T &);
    T retire(int);

    /*==================== GETTERS ====================*/
    int getNombreElements() const;
    Cellule<T> *getPTete() const;

    /*==================== AUTRES MÉTHODES ====================*/
    bool estVide() const;
    void Affiche() const;

    /*==================== ITÉRATEUR ====================*/
    // friend class Iterateur<T>;

    /*==================== OPÉRATEURS ====================*/
    void operator= (const Liste<T> &);

};

#endif