#include "Temps.h"
#include <regex>

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
int Temps::getDuree() const {
    return getHeure() * 60 + getMinute();
}

// Autres méthodes
void Temps::Affiche() const {
    cout << heure
         << "h";
    if (minute < 10 && minute >= 0)
        cout << "0";
    cout << minute << endl;

    //cout << "Temps: heure: " << heure << ":" << minute << endl;
}

// Opérateurs
// =
void Temps::operator=(const Temps &temps) {
#ifdef DEBUG
    cout << "Temps: op =" << endl;
#endif
    setMinute(temps.getMinute());
    setHeure(temps.getHeure());
}
// +
Temps Temps::operator+(const Temps &droite) {
#ifdef DEBUG
    cout << "Temps: op +" << endl;
#endif
    int dureeTot = getDuree() + droite.getDuree();

    Temps tmp(dureeTot);
    return tmp;
}
Temps Temps::operator+(int droite) {
    Temps tmp(droite);
    return *this + tmp;
}
Temps operator+(int gauche, Temps &droite) {
    return droite + gauche;
}
// -
Temps Temps::operator-(const Temps &droite) {
#ifdef DEBUG
    cout << "Temps: op -" << endl;
#endif
    int dureeTot = getDuree() - droite.getDuree();

    Temps tmp(dureeTot);
    return tmp;
}
Temps Temps::operator-(int droite) {
    Temps tmp(droite);
    return *this - tmp;
}
Temps operator-(int gauche, Temps &droite) {
    Temps tmp(gauche);
    return tmp - droite;
}
// >> et <<
istream& operator>>(istream& s, Temps& temps){
    int h, m, i = 0;
    char buff[80];

    s.getline(buff, 80);

    cout << buff[i] << endl;
    if(buff[i] < '0' || buff[i] > '9')
        return -1;
    h = buff[i] - '0';
    i++;
    if(buff[i] >= '0' && buff[i] <= '9'){
        h = h * 10 + buff[i] - '0';
        i++;
    }
    if(buff[i] != 'h')
        return -2;
    i++;
    if(buff[i] < '0' || buff[i] > '9')
        return -3;
    m = buff[i] - '0';
    i++;
    if(buff[i] >= '0' && buff[i] <= '9'){
        m = m * 10 + buff[i] - '0';
        i++;
    }
    if(buff[i] != '\0')
        return -4;

    temps.setHeure(h);
    temps.setMinute(m);
    return s;
}

ostream &operator<<(ostream &s, const Temps &temps) const {
    s << "Temps : " << temps.getHeure() << "h";
    if (temps.getMinute() < 10)
        s << "0";
    s << temps.getMinute();
    return s;
}
// ++ et --
Temps Temps::operator++() {
    *this = (*this) + 30;
    return *this;
}
Temps Temps::operator++(int) {
    Temps temps(*this);
    *this = (*this) + 30;
    return temps;
}
Temps Temps::operator--() {
   *this = (*this) - 30;
   return *this;
}
Temps Temps::operator--(int) {
    Temps temps(*this);
    *this = (*this) - 30;
    return temps;
}
// <, >, ==
int Temps::compareTemps(Temps temps) const {
    if (getHeure() < temps.getHeure()) return -1;
    if (getHeure() > temps.getHeure()) return 1;
    if (getMinute() < temps.getMinute()) return -1;
    if (getMinute() > temps.getMinute()) return 1;
    return 0;
}
int Temps::operator<(const Temps &temps) const {
    return compareTemps(temps) == -1;
}
int Temps::operator>(const Temps &temps) const {
    return compareTemps(temps) == 1;
}
int Temps::operator==(const Temps &temps) const {
    return compareTemps(temps) == 0;
}