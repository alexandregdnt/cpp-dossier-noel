#include "Groupe.h"

/*==================== CONSTRUCTEURS ====================*/
Groupe::Groupe() {
#ifdef DDEBUG
    cout << "Groupe: constructeur par défaut" << endl;
#endif
    numero = -1;
}
Groupe::Groupe(int id, int numero) {
#ifdef DDEBUG
    cout << "Groupe: constructeur avec paramètres" << endl;
#endif
    setId(id);
    setNumero(numero);
}
Groupe::Groupe(const Groupe &copie) {
#ifdef DDEBUG
    cout << "Groupe: constructeur de copie" << endl;
#endif
    setId(copie.getId());
    setNumero(copie.getNumero());
}

/*==================== DESTRUCTEUR ====================*/
Groupe::~Groupe() {
#ifdef DDEBUG
    cout << "Groupe: destructeur" << endl;
#endif
}

/*==================== SETTERS ====================*/
void Groupe::setNumero(int nvNum) {
    if (nvNum && nvNum > 0) {
        numero = nvNum;
    } else {
        numero = -1;
    }
}

/*==================== GETTERS ====================*/
int Groupe::getNumero() const {
    return numero;
}

/*==================== AUTRES MÉTHODES ====================*/
const char *Groupe::Txt() {
    int nDigits = floor(log10(abs(getNumero()))) + 1;

    txt = new char[nDigits + 1];
    sprintf(txt,"%d",getNumero());

    return txt;
}
const char *Groupe::Tuple() {
    char *tmp = NULL;
    int nDigitsId = floor(log10(abs(getId()))) + 1;
    int nDigitsNum = floor(log10(abs(getNumero()))) + 1;

#ifdef DEBUG
    cout << endl << "DEBUG - " << "nDId: " << nDigitsId << " nDNum: " << nDigitsNum << endl;
#endif

    tuple = new char[nDigitsId + nDigitsNum + 1];
    sprintf(tuple,"%d",getId());
    strcat(tuple, ";");

    tmp = new char[nDigitsNum + 1];
    sprintf(tmp,"%d",getNumero());
    strcat(tuple, tmp);
    delete tmp;

    return tuple;
}

/*==================== OPÉRATEURS ====================*/
void Groupe::operator=(const Groupe &groupe) {
#ifdef DEBUG
    cout << "[DEBUG] Groupe: op =" << endl;
#endif
    setId(groupe.getId());
    setNumero(groupe.getNumero());
}
ostream &operator<<(ostream &s, const Groupe &groupe) { // const
    s << "Groupe : (" << groupe.getId() << ") " << groupe.getNumero() << endl;
    return s;
}