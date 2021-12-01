#include "Professeur.h"

/*==================== CONSTRUCTEURS ====================*/
Professeur::Professeur() {
#ifdef DEBUG
    cout << "Professeur: constructeur par défaut" << endl;
#endif
    nom = NULL;
    prenom = NULL;
}
Professeur::Professeur(int nvId, const char *nvNom, const char *nvPrenom) {
#ifdef DEBUG
    cout << "Professeur: constructeur avec paramètres" << endl;
#endif
    nom = NULL;
    prenom = NULL;

    setId(nvId);
    setNom(nvNom);
    setPrenom(nvPrenom);
}
Professeur::Professeur(const Professeur &copie) {
#ifdef DEBUG
    cout << "Professeur: constructeur de copie" << endl;
#endif
    nom = NULL;
    prenom = NULL;

    setId(copie.getId());
    setNom(copie.getNom());
    setPrenom(copie.getPrenom());
}

/*==================== DESTRUCTEUR ====================*/
Professeur::~Professeur() {
#ifdef DEBUG
    cout << "Professeur: destructeur" << endl;
#endif
    if (nom)
        delete(nom);
    if (prenom)
        delete(prenom);
}

/*==================== SETTERS ====================*/
void Professeur::setNom(const char *nvNom) {
    if (nvNom == NULL) return;
    if (nom) delete nom;

    nom = new char[strlen(nvNom) + 1];
    strcpy(nom, toCapitalize(nvNom));
}
void Professeur::setPrenom(const char *nvPrenom) {
    if (nvPrenom == NULL) return;
    if (prenom) delete prenom;

    prenom = new char[strlen(nvPrenom) + 1];
    strcpy(prenom, toCapitalize(nvPrenom));
}

/*==================== GETTERS ====================*/
const char *Professeur::getNom() const {
    return nom;
}
const char *Professeur::getPrenom() const {
    return prenom;
}

/*==================== AUTRES MÉTHODES ====================*/
const char *Professeur::Txt() {
    int length = 0;

    if (getNom()) {
        length += strlen(getNom());
    } else {
        length += 2;
    }
    if (getPrenom()) {
        length += strlen(getPrenom());
    } else {
        length += 1;
    }

    txt = new char[length + 1];

    if (getNom()) {
        strcpy(txt, getNom());
        strcat(txt, " ");
    } else {
        strcat(txt, "/ ");
    }
    if (getPrenom()) {
        strcat(txt, getPrenom());
    } else {
        strcat(txt, "/");
    }
    return txt;
}
const char *Professeur::Tuple() {
    int nDigits = floor(log10(abs(getId()))) + 1;
    int length = 0;

    if (getNom()) {
        length += strlen(getNom());
    } else {
        length += 2;
    }
    if (getPrenom()) {
        length += strlen(getPrenom());
    } else {
        length += 1;
    }

    tuple = new char[nDigits + length + 1];
    sprintf(tuple,"%d",getId());
    strcat(tuple, ";");

    if (getNom()) {
        strcat(tuple, getNom());
        strcat(tuple, ";");
    } else {
        strcat(tuple, "/;");
    }
    if (getPrenom()) {
        strcat(tuple, getPrenom());
    } else {
        strcat(tuple, "/");
    }
    return tuple;
}

/*==================== OPÉRATEURS ====================*/
void Professeur::operator=(const Professeur &prof) {
#ifdef DEBUG
    cout << "Professeur: op =" << endl;
#endif
    setId(prof.getId());
    setNom(prof.getNom());
    setPrenom(prof.getPrenom());
}
ostream &operator<<(ostream &s, const Professeur &prof) {
    s << "Professeur : (" << prof.getId() << ") ";
    if (prof.getNom()) {
        s << prof.getNom() << " ";
    } else {
        s << "/ ";
    }
    if (prof.getPrenom()) {
        s << prof.getPrenom();
    } else {
        s << "/";
    }
    s << endl;

    return s;
}
