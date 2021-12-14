#ifndef EVENT
#define EVENT

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Timing.h"

using namespace std;

class Event {
private:
    int code;
    char *intitule;
    Timing *timing;

public:
    // Variables statiques
    static int codeCourant;

    // Constructeurs
    Event();
    Event(int, const char *);
    Event(const Event &);

    // Destructeur
    ~Event();

    // Setters
    void setCode(int);
    void setIntitule(const char *);
    void setTiming(const Timing &);

    // Getters
    int getCode() const;
    const char *getIntitule() const;
    Timing getTiming() const;

    // Autres méthodes
    void Affiche() const;
};

#endif