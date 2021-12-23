#include "TimingException.h"

/*==================== VARIABLES ====================*/
const int TimingException::JOUR_INVALIDE (-1);
const int TimingException::AUCUN_TIMING (-2);

/*==================== CONSTRUCTEURS ====================*/
TimingException::TimingException() {
#ifdef DEBUG
    cout << "[DEBUG] TimingException: constructeur par défaut" << endl;
#endif
}
TimingException::TimingException(int nvCode) {
#ifdef DEBUG
    cout << "[DEBUG] TempsException: constructeur avec code" << endl;
#endif
    code = nvCode;
    message = new char [80];

    switch (code) {
        case JOUR_INVALIDE:
            strcpy(message, "Jour invalide");
            break;
        case AUCUN_TIMING:
            strcpy(message, "Aucun Timing");
            break;
    }
}

/*==================== DESTRUCTEUR ====================*/
TimingException::~TimingException() {
#ifdef DEBUG
    cout << "[DEBUG] TimingException: destructeur" << endl;
#endif
}

/*==================== GETTERS ====================*/
int TimingException::getCode() const {
    return code;
}

/*==================== OPÉRATEURS ====================*/
ostream &operator<<(ostream &s, const TimingException &exception) { // const
    s << "Erreur: ";
    if (exception.getMessage())
        s << exception.getMessage();
    else
        s << "/";
    s << " !" << endl;

    return s;
}