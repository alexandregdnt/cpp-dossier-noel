#ifndef LISTE_TRIEE
#define LISTE_TRIEE

#include <stdlib.h>
#include <iostream>
#include "Liste.h"

using namespace std;

template<class T>
class ListeTriee: public Liste<T> {
private:
    using Liste<T>::pTete;

public:
    /*==================== CONSTRUCTEURS ====================*/
    ListeTriee();
    ListeTriee(const ListeTriee<T> &);

    /*==================== DESTRUCTEUR ====================*/
    ~ListeTriee();

    /*==================== MÉTHODES ====================*/
    void insere(const T &);
};

#endif