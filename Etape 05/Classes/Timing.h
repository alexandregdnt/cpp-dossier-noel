#ifndef TIMING
#define TIMING

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Temps.h"
#include "TimingException.h"
#include "../Functions.h"

using namespace std;

class Timing {
private:
    char *jour;
    Temps heure;
    Temps duree;

    /*===== Autres Méthodes =====*/
    int compareTemps(Timing) const;
    int getNombreJour() const;

public:
    /*==================== VARIABLES ====================*/
    static const char *LUNDI, *MARDI, *MERCREDI, *JEUDI, *VENDREDI, *SAMEDI, *DIMANCHE;

    /*==================== CONSTRUCTEURS ====================*/
    Timing();
    Timing(const char *, const Temps &, const Temps &);
    Timing(const Timing &);

    /*==================== DESTRUCTEUR ====================*/
    ~Timing();

    /*==================== SETTERS ====================*/
    void setJour(const char *);
    void setHeure(const Temps &);
    void setDuree(const Temps &);

    /*==================== GETTERS ====================*/
    const char *getJour() const;
    Temps getHeure() const;
    Temps getDuree() const;

    /*==================== AUTRES MÉTHODES ====================*/
    void Affiche() const;

    /*==================== OPÉRATEURS ====================*/
    /*===== Opérateurs >, <, == =====*/
    int operator>(const Timing &) const;
    int operator<(const Timing &) const;
    int operator==(const Timing &) const;

};

#endif