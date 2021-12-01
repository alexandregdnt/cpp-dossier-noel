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

public:
    // Variables statiques
    static const char *LUNDI;
    static const char *MARDI;
    static const char *MERCREDI;
    static const char *JEUDI;
    static const char *VENDREDI;
    static const char *SAMEDI;
    static const char *DIMANCHE;

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

    // Autres méthodes
    void Affiche() const;

    // Autres
    char *toCapitalize(const char *);
};

#endif