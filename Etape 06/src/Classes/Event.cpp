#include "Event.h"

/*==================== VARIABLES ====================*/
int Event::codeCourant = 1;

/*==================== CONSTRUCTEURS ====================*/
Event::Event() {
#ifdef DEBUG
    cout << "[DEBUG] Event: constructeur par défaut" << endl;
#endif
    code = -1;
    intitule = NULL;
    timing = NULL;
    codeCourant++;
}
Event::Event(int c, const char *i) {
#ifdef DEBUG
    cout << "[DEBUG] Event: constructeur d'initialisation" << endl;
#endif
    code = -1;
    intitule = NULL;
    timing = NULL;
    codeCourant++;

    setCode(c);
    setIntitule(i);
}
Event::Event(const Event &event) {
#ifdef DEBUG
    cout << "[DEBUG] Event: copie event" << endl;
#endif
    code = -1;
    intitule = NULL;
    timing = NULL;
    codeCourant++;

    setCode(event.getCode());
    setIntitule(event.getIntitule());
    setTiming(event.getTiming());
}

/*==================== DESTRUCTEUR ====================*/
Event::~Event() {
#ifdef DEBUG
    cout << "[DEBUG] Event: destructeur" << endl;
#endif
    codeCourant--;
    if (intitule)
        delete intitule;
    if (timing)
        delete timing;
}

/*==================== SETTERS ====================*/
void Event::setCode(int c) {
    if (c < 1) return;
    code = c;
}
void Event::setIntitule(const char *i) {
    if (i == NULL) return;
    if (intitule) delete intitule;

    intitule = new char[strlen(i) + 1];
    strcpy(intitule, i);
}
void Event::setTiming(const Timing &t) {
    if (timing)
        delete timing;
    timing = new Timing(t);
}

/*==================== GETTERS ====================*/
int Event::getCode() const {
    return code;
}
const char *Event::getIntitule() const {
    return intitule;
}
Timing Event::getTiming() const {
    if (timing)
        return Timing(*timing);
    else
        throw TimingException(TimingException::AUCUN_TIMING);
}

/*==================== AUTRES MÉTHODES ====================*/
void Event::Affiche() const {
    cout << "code: " << code << ", intitule: ";
    if (intitule)
        cout << intitule;
    else
        cout << "/";
    cout << ", timing: ";
    if (timing)
        timing->Affiche();
    else
        cout << "/";
    cout << endl;
}