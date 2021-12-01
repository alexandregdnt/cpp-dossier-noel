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
Planifiable::Planifiable(const Planifiable &copie) {
#ifdef DEBUG
    cout << "Planifiable: constructeur de copie" << endl;
#endif
    id = copie.id;
    txt = NULL;
    tuple = NULL;

    if (copie.txt)
        strcpy(txt, copie.txt);
    if (copie.tuple)
        strcpy(tuple, copie.tuple);
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