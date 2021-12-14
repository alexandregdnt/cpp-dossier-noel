#include "ListeTriee.h"
#include "Professeur.h"

/*==================== CONSTRUCTEURS ====================*/
template<class T>
ListeTriee<T>::ListeTriee(): Liste<T>() {
#ifdef DEBUG
    cout << "ListeTriee: constructeur par défaut" << endl;
#endif
}
template<class T>
ListeTriee<T>::ListeTriee(const ListeTriee<T> &copie): Liste<T>(copie) {
#ifdef DEBUG
    cout << "ListeTriee: constructeur de copie" << endl;
#endif
}

/*==================== DESTRUCTEUR ====================*/
template<class T>
ListeTriee<T>::~ListeTriee() {
#ifdef DEBUG
    cout << "ListeTriee: destructeur" << endl;
#endif
}

/*==================== AUTRES MÉTHODES ====================*/
template<class T>
void ListeTriee<T>::insere(const T &val) {
    if (estVide()) {
        pTete = new Cellule<T>;
        pTete->valeur = val;
        pTete->suivant = NULL;
    } else {
        Cellule<T> *nvCell, *pTmp;
        pTmp = pTete;

        nvCell = new Cellule<T>;
        nvCell->valeur = val;
        nvCell->suivant = NULL;
        // cout << "nv val: " << nvCell->valeur << " - address: " << nvCell << endl;

        while (pTmp->suivant != NULL) {
            pTmp = pTmp->suivant;
        }

        if (pTmp->suivant == NULL) {
            pTmp->suivant = nvCell;
        }
    }
}

template class ListeTriee<int>;
template class ListeTriee<Professeur>;