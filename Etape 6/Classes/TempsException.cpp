#include "TempsException.h"

/*==================== VARIABLES ====================*/
const int TempsException::HEURE_INVALIDE (-1);
const int TempsException::MINUTE_INVALIDE (-2);
const int TempsException::DEPASSEMENT (-3);
const int TempsException::FORMAT_INVALIDE (-4);

/*==================== CONSTRUCTEURS ====================*/
TempsException::TempsException() {
#ifdef DEBUG
    cout << "TempsException: constructeur par défaut" << endl;
#endif
}
TempsException::TempsException(int nvCode) {
#ifdef DEBUG
    cout << "TempsException: constructeur avec code" << endl;
#endif
    code = nvCode;
    message = new char [80];

    switch (code) {
        case HEURE_INVALIDE:
            strcpy(message, "Heure invalide");
            break;
        case MINUTE_INVALIDE:
            strcpy(message, "Minute invalide");
            break;
        case DEPASSEMENT:
            strcpy(message, "Dépassement (-00h00 ou +23h59)");
            break;
        case FORMAT_INVALIDE:
            strcpy(message, "Format invalide (ex: 10h30)");
            break;
        default:
            strcpy(message, "Aucune information supplémentaire");
    }
}

/*==================== DESTRUCTEUR ====================*/
TempsException::~TempsException() {
#ifdef DEBUG
    cout << "TempsException: destructeur" << endl;
#endif
}

/*==================== GETTERS ====================*/
int TempsException::getCode() const {
    return code;
}

/*==================== OPÉRATEURS ====================*/
ostream &operator<<(ostream &s, const TempsException &exception) { // const
    s << "Erreur: ";
    if (exception.getMessage())
        s << exception.getMessage();
    else
        s << "/";
    s << " !" << endl;

    return s;
}