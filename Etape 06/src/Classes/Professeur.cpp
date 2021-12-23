#include "Professeur.h"

/*==================== CONSTRUCTEURS ====================*/
Professeur::Professeur() {
#ifdef DEBUG
    cout << "[DEBUG] Professeur: constructeur par défaut" << endl;
#endif
    nom = NULL;
    prenom = NULL;
}
Professeur::Professeur(int nvId, const char *nvNom, const char *nvPrenom) {
#ifdef DEBUG
    cout << "[DEBUG] Professeur: constructeur avec paramètres" << endl;
#endif
    nom = NULL;
    prenom = NULL;

    setId(nvId);
    setNom(nvNom);
    setPrenom(nvPrenom);
}
Professeur::Professeur(const Professeur &copie) {
#ifdef DEBUG
    cout << "[DEBUG] Professeur: constructeur de copie" << endl;
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
    cout << "[DEBUG] Professeur: destructeur" << endl;
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
/*===== Autres méthodes privées =====*/
int Professeur::compareProfs(const Professeur &prof) const {
    int ret;

    ret = strcmp(getNom(), prof.getNom());
    // cout << "[DEBUG] Prof: comparaison (Nom) (" << getNom() << " - " << prof.getNom() << "): " << ret << endl;
    if (ret < 0) return -1;
    if (ret > 0) return 1;

    ret = strcmp(getPrenom(), prof.getPrenom());
    // cout << "[DEBUG] Prof: comparaison (Prenom) (" << getPrenom() << " - " << prof.getPrenom() << "): " << ret << endl;
    if (ret < 0) return -1;
    if (ret > 0) return 1;

    return 0;
}

/*==================== OPÉRATEURS ====================*/
/*===== Opérateur = =====*/
void Professeur::operator=(const Professeur &prof) {
#ifdef DEBUG
    cout << "[DEBUG] Professeur: op =" << endl;
#endif
    setId(prof.getId());
    setNom(prof.getNom());
    setPrenom(prof.getPrenom());
}
/*===== Opérateurs >>, << =====*/
ostream &operator<<(ostream &s, const Professeur &prof) {
    /*
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
    */

    if (prof.getNom())
        s << prof.getNom();
    else
        s << "/";
    s << " ";
    if (prof.getPrenom())
        s << prof.getPrenom();
    else
        s << "/";

    return s;
}
/*===== Opérateurs >, <, ==, >=, <= =====*/
int Professeur::operator>(const Professeur &prof) const {
    int ret = (compareProfs(prof) == 1);
#ifdef DEBUG
    cout << "[DEBUG] Prof: (" << getNom() << " > " << prof.getNom() << ") : " << ret << endl;
#endif
    return ret;
}
int Professeur::operator<(const Professeur &prof) const {
    int ret = (compareProfs(prof) == -1);
#ifdef DEBUG
    cout << "[DEBUG] Prof: (" << getNom() << " < " << prof.getNom() << ") : " << ret << endl;
#endif
    return ret;
}
int Professeur::operator==(const Professeur &prof) const {
    int ret = (compareProfs(prof) == 0);
#ifdef DEBUG
    cout << "[DEBUG] Prof: (" << getNom() << " == " << prof.getNom() << ") : " << ret << endl;
#endif
    return ret;
}
int Professeur::operator>=(const Professeur &prof) const {
    int ret = (compareProfs(prof) == 1 || compareProfs(prof) == 0);
#ifdef DEBUG
    cout << "[DEBUG] Prof: (" << getNom() << " >= " << prof.getNom() << ") : " << ret << endl;
#endif
    return ret;
}
int Professeur::operator<=(const Professeur &prof) const {
    int ret = (compareProfs(prof) == -1 || compareProfs(prof) == 0);
#ifdef DEBUG
    cout << "[DEBUG] Prof: (" << getNom() << " <= " << prof.getNom() << ") : " << ret << endl;
#endif
    return ret;
}