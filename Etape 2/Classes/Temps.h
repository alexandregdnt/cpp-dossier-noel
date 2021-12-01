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

    // Autres méthodes
    void Affiche() const;
};

#endif