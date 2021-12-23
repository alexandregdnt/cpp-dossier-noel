#ifndef PROFESSEUR
#define PROFESSEUR

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include "../Libraries/Functions.h"
#include "Planifiable.h"

using namespace std;

class Professeur: public Planifiable {
private:
    char *nom;
    char *prenom;
    int horaire;

    /*===== Autres Méthodes =====*/
    int compareProfs(const Professeur &) const;

public:
    /*==================== CONSTRUCTEURS ====================*/
    Professeur();
    Professeur(int, const char *, const char *);
    Professeur(const Professeur &);

    /*==================== DESTRUCTEUR ====================*/
    ~Professeur();

    /*==================== SETTERS ====================*/
    void setNom(const char *);
    void setPrenom(const char *);

    /*==================== GETTERS ====================*/
    const char *getNom() const;
    const char *getPrenom() const;

    /*==================== AUTRES MÉTHODES ====================*/
    const char *Txt();
    const char *Tuple();

    /*==================== OPÉRATEURS ====================*/
    /*===== Opérateur = =====*/
    void operator= (const Professeur &);
    /*===== Opérateurs >>, << =====*/
    friend ostream &operator<< (ostream &, const Professeur &);
    /*===== Opérateurs >, <, ==, >=, <= =====*/
    int operator> (const Professeur &) const;
    int operator< (const Professeur &) const;
    int operator== (const Professeur &) const;
    int operator>= (const Professeur &) const;
    int operator<= (const Professeur &) const;
};

#endif