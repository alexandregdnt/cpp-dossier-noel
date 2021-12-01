#ifndef PROFESSEUR
#define PROFESSEUR

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include "Planifiable.h"

using namespace std;

class Professeur: public Planifiable {
private:
    char *nom;
    char *prenom;
    int horaire;

    /*===== Autres Méthodes =====*/
    char *toCapitalize(const char *);

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
    void operator= (const Professeur &);
    friend ostream &operator<< (ostream &, const Professeur &);

};

#endif