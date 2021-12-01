#include "Planifiable.h"

/*==================== CONSTRUCTEURS ====================*/
Planifiable::Planifiable() {
#ifdef DEBUG
    cout << "Planifiable: constructeur par défaut" << endl;
#endif
    id = -1;
    txt = NULL;
    tuple = NULL;
}

/*==================== DESTRUCTEUR ====================*/
Planifiable::~Planifiable() {
#ifdef DEBUG
    cout << "Planifiable: destructeur" << endl;
#endif
    if (txt)
        delete txt;
    if (tuple)
        delete tuple;
}

/*==================== SETTERS ====================*/
void Planifiable::setId(int nvId) {
    if (nvId && nvId > 0) {
        id = nvId;
    } else {
        id = -1;
    }
}

/*==================== GETTERS ====================*/
int Planifiable::getId() const {
    return id;
}