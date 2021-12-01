#include "Exception.h"

/*==================== CONSTRUCTEURS ====================*/
Exception::Exception() {
#ifdef DEBUG
    cout << "Exception: constructeur par défaut" << endl;
#endif
    message = NULL;
}

/*==================== DESTRUCTEUR ====================*/
Exception::~Exception() {
#ifdef DEBUG
    cout << "Exception: destructeur" << endl;
#endif
    if (message)
        delete message;
}

/*==================== GETTERS ====================*/
const char *Exception::getMessage() const {
    return message;
}