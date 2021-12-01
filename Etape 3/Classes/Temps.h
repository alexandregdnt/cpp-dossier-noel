#ifndef TEMPS
#define TEMPS

#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

class Temps {
private:
    int heure;
    int minute;

    int compareTemps(Temps) const;

public:
    // Constructeurs
    Temps();
    Temps(int, int);
    Temps(int);
    Temps(const Temps &);

    // Destructeur
    ~Temps();

    // Setters
    void setHeure(int);
    void setMinute(int);

    // Getters
    int getHeure() const;
    int getMinute() const;
    int getDuree() const;

    // Autres méthodes
    void Affiche() const;

    // Opérateurs
    // =
    void operator= (const Temps &);
    // +
    Temps operator+ (const Temps &);
    Temps operator+ (int);
    friend Temps operator+ (int, Temps &);
    // -
    Temps operator- (const Temps &);
    Temps operator- (int);
    friend Temps operator- (int, Temps &);

    // >> et <<
    friend istream &operator>>(istream &, Temps &);
    friend ostream &operator<<(ostream &, const Temps &) const;
    // ++ et --
    Temps operator++();
    Temps operator++(int);
    Temps operator--();
    Temps operator--(int);
    // <, >, ==
    int operator<(const Temps &) const;
    int operator>(const Temps &) const;
    int operator==(const Temps &) const;
};

#endif