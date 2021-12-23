#ifndef ITERATEUR
#define ITERATEUR

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Liste.h"

template<class T> class Liste;
template<class T> struct Cellule;

using namespace std;

template<class T>
class Iterateur {
private:
    Liste<T> &lis;
    Cellule<T> *pData;

public:
    /*==================== CONSTRUCTEURS ====================*/
    Iterateur(Liste<T> &l): lis(l), pData(l.getPTete()) {};
    Iterateur(const Iterateur<T> &copie): lis(copie.lis), pData(copie.pData) {};

    /*==================== DESTRUCTEUR ====================*/
    ~Iterateur();

    /*==================== AUTRES MÉTHODES ====================*/
    void reset();
    bool end() const;

    /*==================== OPÉRATEURS ====================*/
    bool operator++(); // Post
    bool operator++(int); // Pré

    operator T();
};

#endif