#include "Liste.h"
#include "Professeur.h"

/*==================== CONSTRUCTEURS ====================*/
template<class T>
Liste<T>::Liste() {
#ifdef DEBUG
    cout << "Liste: constructeur par défaut" << endl;
#endif
    pTete = NULL;
}
template<class T>
Liste<T>::Liste(const Liste<T> &copie) {
#ifdef DEBUG
    cout << "Liste: constructeur de copie" << endl;
#endif

    if (copie.pTete == NULL) {
        pTete = NULL;
    } else {
        Cellule<T> *curCopie, *curThis, *tmp;

        curCopie = copie.pTete;
        curThis = NULL;
        tmp = NULL;

        pTete = new Cellule<T>;
        pTete->valeur = curCopie->valeur;
        pTete->suivant = NULL;

        curCopie = curCopie->suivant;
        curThis = pTete;

        while (curCopie != NULL) {
            tmp = new Cellule<T>;
            tmp->valeur = curCopie->valeur;
            tmp->suivant = NULL;

            curCopie = curCopie->suivant;
            curThis->suivant = tmp;
            curThis = tmp;
        }
    }
}

/*==================== DESTRUCTEUR ====================*/
template<class T>
Liste<T>::~Liste() {
#ifdef DEBUG
    cout << "Liste: destructeur" << endl;
#endif
    Cellule<T> *pTmp = pTete, *pCur = NULL;

    while (pTmp != NULL) {
        pCur = pTmp;
        pTmp = pTmp->suivant;
        delete pCur;
    }
    delete pTmp;
}

/*==================== MODIFICATEURS ====================*/
template<class T>
void Liste<T>::insere(const T &val) {
#ifdef DEBUG
    cout << "Liste: insere" << endl;
#endif
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
template<class T>
T Liste<T>::retire(int ind) {
    Cellule<T> *pTmp = pTete;
    T retour;

    for (int i=0; i<getNombreElements()-1; i++) {
        if (i == ind) {
            retour = pTmp->valeur;
        }
        pTmp = pTmp->suivant;
    }

    pTmp = pTete;
    for (int i=0; i<getNombreElements()-1; i++) {
        if (i == ind-1) {
            pTmp->suivant = pTmp->suivant->suivant;
        }
        pTmp = pTmp->suivant;
    }

    return retour;
}

/*==================== GETTERS ====================*/
template<class T>
int Liste<T>::getNombreElements() const {
    Cellule<T> *pTmp = pTete;
    int i = 0;

    while (pTmp != NULL) {
        pTmp = pTmp->suivant;
        i++;
    }

    delete pTmp;
    return i;
}

/*==================== AUTRES MÉTHODES ====================*/
template<class T>
bool Liste<T>::estVide() const {
    return pTete == NULL;
}
template<class T>
void Liste<T>::Affiche() const {
    Cellule<T> *pTmp = pTete;

    cout << "(";
    while (pTmp != NULL) {
        cout << pTmp->valeur;
        if (pTmp->suivant != NULL)
            cout << "; ";
        pTmp = pTmp->suivant;
    }
    cout << ")" << endl;

    delete pTmp;
}

template<class T>
void Liste<T>::operator=(const Liste<T> &copie) {
#ifdef DEBUG
    cout << "Liste: constructeur de copie" << endl;
#endif
    if (copie.pTete == NULL) {
        pTete = NULL;
    } else {
        Cellule<T> *curCopie, *curThis, *tmp;

        curCopie = copie.pTete;
        curThis = NULL;
        tmp = NULL;

        pTete = new Cellule<T>;
        pTete->valeur = curCopie->valeur;
        pTete->suivant = NULL;

        curCopie = curCopie->suivant;
        curThis = pTete;

        while (curCopie != NULL) {
            tmp = new Cellule<T>;
            tmp->valeur = curCopie->valeur;
            tmp->suivant = NULL;

            curCopie = curCopie->suivant;
            curThis->suivant = tmp;
            curThis = tmp;
        }
    }
}

template struct Cellule<int>;
template class Liste<int>;

template struct Cellule<Professeur>;
template class Liste<Professeur>;