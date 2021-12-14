#ifndef EVENT
#define EVENT

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Timing.h"
#include "TimingException.h"

using namespace std;

class Event {
private:
    int code;
    char *intitule;
    Timing *timing;

public:
    /*==================== VARIABLES ====================*/
    static int codeCourant;

    /*==================== CONSTRUCTEURS ====================*/
    Event();
    Event(int, const char *);
    Event(const Event &);

    /*==================== DESTRUCTEUR ====================*/
    ~Event();

    /*==================== SETTERS ====================*/
    void setCode(int);
    void setIntitule(const char *);
    void setTiming(const Timing &);

    /*==================== GETTERS ====================*/
    int getCode() const;
    const char *getIntitule() const;
    Timing getTiming() const;

    /*==================== AUTRES MÉTHODES ====================*/
    void Affiche() const;
};

#endif