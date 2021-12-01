#include "Temps.h"

/*==================== CONSTRUCTEURS ====================*/
Temps::Temps() {
#ifdef DEBUG
    cout << "Temps: constructeur par défaut" << endl;
#endif
    setHeure(0);
    setMinute(0);
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

/*==================== DESTRUCTEUR ====================*/
Temps::~Temps() {
#ifdef DEBUG
    cout << "Temps: destructeur " << endl;
#endif
}

/*==================== SETTERS ====================*/
void Temps::setHeure(int h) {
    if (h < 0 || h > 23) {
        throw(TempsException(TempsException::HEURE_INVALIDE));
    } else {
        heure = h;
    }
}
void Temps::setMinute(int m) {
    if (m < 0 || m > 59) {
        throw(TempsException(TempsException::MINUTE_INVALIDE));
    } else {
        minute = m;
    }
}

/*==================== GETTERS ====================*/
int Temps::getHeure() const {
    return heure;
}
int Temps::getMinute() const {
    return minute;
}
int Temps::getDuree() const {
    return getHeure() * 60 + getMinute();
}

/*==================== AUTRES MÉTHODES ====================*/
void Temps::Affiche() const {
    cout << heure
         << "h";
    if (minute < 10 && minute >= 0)
        cout << "0";
    cout << minute;

    //cout << "Temps: heure: " << heure << ":" << minute << endl;
}

/*===== Autres méthodes privées =====*/
int Temps::compareTemps(Temps temps) const {
    if (getHeure() < temps.getHeure()) return -1;
    if (getHeure() > temps.getHeure()) return 1;
    if (getMinute() < temps.getMinute()) return -1;
    if (getMinute() > temps.getMinute()) return 1;
    return 0;
}

/*==================== OPÉRATEURS ====================*/
/*===== Opérateur = =====*/
void Temps::operator=(const Temps &temps) {
#ifdef DEBUG
    cout << "Temps: op =" << endl;
#endif
    setMinute(temps.getMinute());
    setHeure(temps.getHeure());
}
/*===== Opérateur + =====*/
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
/*===== Opérateur - =====*/
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
/*===== Opérateurs >>, << =====*/
istream& operator>>(istream &s, Temps &temps) {
    int h, m, i = 0;
    char buff[80];

    s.getline(buff, 80);

    // cout << buff[i] << endl;
    if(buff[i] < '0' || buff[i] > '9')
        throw(TempsException(TempsException::FORMAT_INVALIDE));
    h = buff[i] - '0';
    i++;
    if(buff[i] >= '0' && buff[i] <= '9'){
        h = h * 10 + buff[i] - '0';
        i++;
    }
    if(buff[i] != 'h')
        throw(TempsException(TempsException::FORMAT_INVALIDE));
    i++;
    if(buff[i] < '0' || buff[i] > '9')
        throw(TempsException(TempsException::FORMAT_INVALIDE));
    m = buff[i] - '0';
    i++;
    if(buff[i] >= '0' && buff[i] <= '9'){
        m = m * 10 + buff[i] - '0';
        i++;
    }
    if(buff[i] != '\0')
        throw(TempsException(TempsException::FORMAT_INVALIDE));

    temps.setHeure(h);
    temps.setMinute(m);
    return s;
}
ostream &operator<<(ostream &s, const Temps &temps) { // const
    s << "Temps : " << temps.getHeure() << "h";
    if (temps.getMinute() < 10)
        s << "0";
    s << temps.getMinute();
    return s;
}
/*===== Opérateurs ++, -- =====*/
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
/*===== Opérateur >, <, == =====*/
int Temps::operator>(const Temps &temps) const {
    return compareTemps(temps) == 1;
}
int Temps::operator<(const Temps &temps) const {
    return compareTemps(temps) == -1;
}
int Temps::operator==(const Temps &temps) const {
    return compareTemps(temps) == 0;
}