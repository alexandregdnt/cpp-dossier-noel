#include "Local.h"

/*==================== CONSTRUCTEURS ====================*/
Local::Local() {
#ifdef DEBUG
    cout << "Local: constructeur par défaut" << endl;
#endif
    nom = NULL;
}
Local::Local(int nvId, const char *nvNom) {
#ifdef DEBUG
    cout << "Local: constructeur avec paramètres" << endl;
#endif
    nom = NULL;

    setId(nvId);
    setNom(nvNom);
}
Local::Local(const Local &copie) {
#ifdef DEBUG
    cout << "Local: constructeur de copie" << endl;
#endif
    nom = NULL;

    setId(copie.getId());
    setNom(copie.getNom());
}

/*==================== DESTRUCTEUR ====================*/
Local::~Local() {
#ifdef DEBUG
    cout << "Local: destructeur" << endl;
#endif
    if (nom)
        delete nom;
}

/*==================== SETTERS ====================*/
void Local::setNom(const char *nvNom) {
    if (nvNom == NULL) return;
    if (nom) delete nom;

    nom = new char[strlen(nvNom) + 1];
    strcpy(nom, nvNom);

    for (int i=0; i<strlen(nom); i++) {
        nom[i] = toupper(nom[i]);
    }
}

/*==================== GETTERS ====================*/
const char *Local::getNom() const {
    return nom;
}

/*==================== AUTRES MÉTHODES ====================*/
const char *Local::Txt() {
    int length = 0;

    if (getNom()) {
        length += strlen(getNom());
    } else {
        length += 2;
    }

    txt = new char[length + 1];

    if (getNom()) {
        strcpy(txt, getNom());
        strcat(txt, " ");
    } else {
        strcat(txt, "/ ");
    }
    return txt;
}
const char *Local::Tuple() {
    int nDigits = floor(log10(abs(getId()))) + 1;
    int length = 0;

    if (getNom()) {
        length += strlen(getNom());
    } else {
        length += 2;
    }

    tuple = new char[nDigits + length + 1];
    sprintf(tuple,"%d",getId());
    strcat(tuple, ";");

    if (getNom()) {
        strcat(tuple, getNom());
    } else {
        strcat(tuple, "/");
    }

    return tuple;
}

/*==================== OPÉRATEURS ====================*/
void Local::operator=(const Local &local) {
#ifdef DEBUG
    cout << "Local: op =" << endl;
#endif
    setId(local.getId());
    setNom(local.getNom());
}
ostream &operator<<(ostream &s, const Local &local) { // const
    s << "Local : (" << local.getId() << ") ";
    if (local.getNom()) {
        s << local.getNom() << " ";
    } else {
        s << "/ ";
    }
    s << endl;

    return s;
}
