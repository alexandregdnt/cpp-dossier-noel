#include "Temps.h"

// Constructeurs
Temps::Temps() {
#ifdef DEBUG
    cout << "Temps: constructeur par défaut" << endl;
#endif
    heure = -1;
    minute = -1;
}
Temps::Temps(int h, int m) {
#ifdef DEBUG
    cout << "Temps: constructeur d'initialisation de Temps (heure)" << endl;
#endif
    setHeure(h);
    setMinute(m);
}
Temps::Temps(int d) {
#ifdef DEBUG
    cout << "Temps: constructeur d'initialisation de Temps (duree)" << endl;
#endif
    setHeure(d / 60);
    setMinute(d % 60);
}
Temps::Temps(const Temps &temps) {
#ifdef DEBUG
    cout << "Temps: copie temps" << endl;
#endif
    setMinute(temps.getMinute());
    setHeure(temps.getHeure());
}

// Destructeur
Temps::~Temps() {
#ifdef DEBUG
    cout << "Temps: destructeur " << endl;
#endif
}

// Setters
void Temps::setHeure(int h) {
    if (h < 0 || h > 23) {
        heure = -1;
    } else {
        heure = h;
    }
}
void Temps::setMinute(int m) {
    if (m < 0 || m > 59) {
        heure = -1;
    } else {
        minute = m;
    }
}

// Getters
int Temps::getHeure() const {
    return heure;
}
int Temps::getMinute() const {
    return minute;
}

// Autres méthodes
void Temps::Affiche() const {
    cout << heure
         << "h";
    if (minute < 10 && minute >= 0)
        cout << "0";
    cout << minute;

    //cout << "Temps: heure: " << heure << ":" << minute << endl;
}