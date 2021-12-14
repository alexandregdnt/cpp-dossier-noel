#ifndef GROUPE
#define GROUPE

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include "Planifiable.h"

using namespace std;

class Groupe: public Planifiable {
private:
    int numero;

public:
    /*==================== CONSTRUCTEURS ====================*/
    Groupe();
    Groupe(int, int);
    Groupe(const Groupe &);

    /*==================== DESTRUCTEUR ====================*/
    ~Groupe();

    /*==================== SETTERS ====================*/
    void setNumero(int);

    /*==================== GETTERS ====================*/
    int getNumero() const;

    /*==================== AUTRES MÉTHODES ====================*/
    const char *Txt();
    const char *Tuple();

    /*==================== OPÉRATEURS ====================*/
    void operator= (const Groupe &);
    friend ostream &operator<< (ostream &, const Groupe &); /* const */
};

#endif