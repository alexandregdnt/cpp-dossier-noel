#include "Timing.h"

// Variables statiques
const char *Timing::LUNDI("Lundi");
const char *Timing::MARDI("Mardi");
const char *Timing::MERCREDI("Mercredi");
const char *Timing::JEUDI("Jeudi");
const char *Timing::VENDREDI("Vendredi");
const char *Timing::SAMEDI("Samedi");
const char *Timing::DIMANCHE("Dimanche");

// Constructeurs
Timing::Timing() {
#ifdef DEBUG
    cout << "Timing: constructeur par défaut" << endl;
#endif
    jour = NULL;
    heure = Temps();
    duree = Temps();
}

Timing::Timing(const char *j, const Temps &h, const Temps &d) {
#ifdef DEBUG
    cout << "Timing: constructeur avec paramètres (jour, heure, duree)" << endl;
#endif
    jour = NULL;
    heure = Temps();
    duree = Temps();

    setJour(j);
    setHeure(h);
    setDuree(d);
}

Timing::Timing(const Timing &timing) {
#ifdef DEBUG
    cout << "Timing: copie timing" << endl;
#endif
    jour = NULL;
    heure = Temps();
    duree = Temps();

    setJour(timing.getJour());
    setHeure(timing.getHeure());
    setDuree(timing.getDuree());
}

// Desctructeur
Timing::~Timing() {
#ifdef DEBUG
    cout << "Timing: desctructeur" << endl;
#endif
    if (jour)
        delete jour;
}

// Setters
void Timing::setJour(const char *j) {
    if (j == NULL) return;
    if (jour) delete jour;

    jour = new char[strlen(j) + 1];
    strcpy(jour, toCapitalize(j));

    // Pas de vérification pour l'instant
    /*
    switch (j)
    {
      case "Lundi":
      case "Mardi":
      case "Mercredi":
      case "Jeudi":
      case "Vendredi":
      case "Samedi":
      case "Dimanche":
        jour = j;
        break;

      default:
        break;
    }
    */
}

void Timing::setHeure(const Temps &h) {
    heure.setHeure(h.getHeure());
    heure.setMinute(h.getMinute());
}

void Timing::setDuree(const Temps &d) {
    duree.setHeure(d.getHeure());
    duree.setMinute(d.getMinute());
}

// Getters
const char *Timing::getJour() const {
    return jour;
}

Temps Timing::getHeure() const {
    return heure;
}

Temps Timing::getDuree() const {
    return duree;
}

// Autres méthodes
void Timing::Affiche() const {
    cout << "Jour: ";
    if (jour)
        cout << jour;
    else
        cout << "/";
    cout << ", heure: ";
    heure.Affiche();
    cout << ", duree: ";
    duree.Affiche();
    cout << endl;
}

// Autres
char *Timing::toCapitalize(const char *str) {
    char *tmpstr;
    tmpstr = new char[strlen(str) + 1];

    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0)
            tmpstr[i] = toupper(str[i]);
        else
            tmpstr[i] = tolower(str[i]);
    }
    return tmpstr;
}