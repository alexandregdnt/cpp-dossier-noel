#ifndef TEMPS
#define TEMPS

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "TempsException.h"

using namespace std;

class Temps {
private:
    int heure;
    int minute;

    /*===== Autres Méthodes =====*/
    int compareTemps(Temps) const;

public:
    /*==================== CONSTRUCTEURS ====================*/
    Temps();
    Temps(int, int);
    Temps(int);
    Temps(const Temps &);

    /*==================== DESTRUCTEUR ====================*/
    ~Temps();

    /*==================== SETTERS ====================*/
    void setHeure(int);
    void setMinute(int);

    /*==================== GETTERS ====================*/
    int getHeure() const;
    int getMinute() const;
    int getDuree() const;

    /*==================== AUTRES MÉTHODES ====================*/
    void Affiche() const;

    /*==================== OPÉRATEURS ====================*/
    /*===== Opérateur = =====*/
    void operator= (const Temps &);
    /*===== Opérateur + =====*/
    Temps operator+ (const Temps &);
    Temps operator+ (int);
    friend Temps operator+ (int, Temps &);
    /*===== Opérateur - =====*/
    Temps operator- (const Temps &);
    Temps operator- (int);
    friend Temps operator- (int, Temps &);
    /*===== Opérateurs >>, << =====*/
    friend istream &operator>>(istream &, Temps &);
    friend ostream &operator<<(ostream &, const Temps &); /* const */
    /*===== Opérateurs ++, -- =====*/
    Temps operator++();
    Temps operator++(int);
    Temps operator--();
    Temps operator--(int);
    /*===== Opérateurs >, <, == =====*/
    int operator>(const Temps &) const;
    int operator<(const Temps &) const;
    int operator==(const Temps &) const;
};

#endif