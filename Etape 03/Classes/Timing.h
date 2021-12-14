#ifndef TIMING
#define TIMING

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Temps.h"

using namespace std;

class Timing {
private:
    char *jour;
    Temps heure;
    Temps duree;
    int compareTemps(Timing) const;

public:
    // Constructeurs
    Timing();
    Timing(const char *, const Temps &, const Temps &);
    Timing(const Timing &);

    // Destructeur
    ~Timing();

    // Setters
    void setJour(const char *);
    void setHeure(const Temps &);
    void setDuree(const Temps &);

    // Getters
    const char *getJour() const;
    Temps getHeure() const;
    Temps getDuree() const;
    int getNombreJour () const;

    // Autres méthodes
    void Affiche() const;

    // Variables
    static const char *LUNDI, *MARDI, *MERCREDI, *JEUDI, *VENDREDI, *SAMEDI, *DIMANCHE;

    // Opérateurs
    int operator<(const Timing &) const;
    int operator>(const Timing &) const;
    int operator==(const Timing &) const;

    // Autres
    char *toCapitalize(const char *);
};

#endif