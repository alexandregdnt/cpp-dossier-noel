#include "Timing.h"

/*==================== VARIABLES ====================*/
const char *Timing::LUNDI = "Lundi";
const char *Timing::MARDI = "Mardi";
const char *Timing::MERCREDI = "Mercredi";
const char *Timing::JEUDI = "Jeudi";
const char *Timing::VENDREDI = "Vendredi";
const char *Timing::SAMEDI = "Samedi";
const char *Timing::DIMANCHE = "Dimanche";

/*==================== CONSTRUCTEURS ====================*/
Timing::Timing() {
#ifdef DEBUG
    cout << "[DEBUG] Timing: constructeur par défaut" << endl;
#endif
    jour = NULL;
}
Timing::Timing(const char *j, const Temps &h, const Temps &d) {
#ifdef DEBUG
    cout << "[DEBUG] Timing: constructeur avec paramètres (jour, heure, duree)" << endl;
#endif
    jour = NULL;

    setJour(j);
    setHeure(h);
    setDuree(d);
}
Timing::Timing(const Timing &timing) {
#ifdef DEBUG
    cout << "[DEBUG] Timing: copie timing" << endl;
#endif
    jour = NULL;

    setJour(timing.getJour());
    setHeure(timing.getHeure());
    setDuree(timing.getDuree());
}

/*==================== DESTRUCTEUR ====================*/
Timing::~Timing() {
#ifdef DEBUG
    cout << "[DEBUG] Timing: desctructeur" << endl;
#endif
    if (jour)
        delete jour;
}

/*==================== SETTERS ====================*/
void Timing::setJour(const char *j) {
    if (j == NULL) return;
    if (jour) delete jour;

    jour = new char[strlen(j) + 1];
    strcpy(jour, toCapitalize(j));

    // Vérification
    if (jour != NULL) {
        getNombreJour();
    }
}
void Timing::setHeure(const Temps &h) {
    heure.setHeure(h.getHeure());
    heure.setMinute(h.getMinute());
}
void Timing::setDuree(const Temps &d) {
    duree.setHeure(d.getHeure());
    duree.setMinute(d.getMinute());
}

/*==================== GETTERS ====================*/
const char *Timing::getJour() const {
    return jour;
}
Temps Timing::getHeure() const {
    return heure;
}
Temps Timing::getDuree() const {
    return duree;
}

/*==================== AUTRES MÉTHODES ====================*/
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

/*===== Autres méthodes privées =====*/
int Timing::compareTemps(Timing timing) const {
    if (getNombreJour() < timing.getNombreJour()) return -1;
    if (getNombreJour() > timing.getNombreJour()) return 1;
    if (getHeure() < timing.getHeure()) return -1;
    if (getHeure() > timing.getHeure()) return 1;
    if (getDuree() < timing.getDuree()) return -1;
    if (getDuree() > timing.getDuree()) return 1;
    return 0;
}
int Timing::getNombreJour () const {
    if (strcmp(getJour(), Timing::LUNDI) == 0) return 1;
    if (strcmp(getJour(), Timing::MARDI) == 0) return 2;
    if (strcmp(getJour(), Timing::MERCREDI) == 0) return 3;
    if (strcmp(getJour(), Timing::JEUDI) == 0) return 4;
    if (strcmp(getJour(), Timing::VENDREDI) == 0) return 5;
    if (strcmp(getJour(), Timing::SAMEDI) == 0) return 6;
    if (strcmp(getJour(), Timing::DIMANCHE) == 0) return 7;

    throw(TimingException(TimingException::JOUR_INVALIDE));
}

/*==================== OPÉRATEURS ====================*/
int Timing::operator>(const Timing &timing) const {
    return compareTemps(timing) == 1;
}
int Timing::operator<(const Timing &timing) const {
    return compareTemps(timing) == -1;
}
int Timing::operator==(const Timing &timing) const {
    return compareTemps(timing) == 0;
}
