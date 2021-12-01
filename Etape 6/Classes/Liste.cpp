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
        pTete == NULL;
    } else {
        Cellule<T> *curCopie = copie.pTete, *curThis = NULL, *tmp = NULL;

        while (curCopie != NULL) {
            tmp = new Cellule<T>;
            tmp->valeur = curCopie->valeur;

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
    Cellule<T> *pTmp, *pPrec;
    pTmp = pTete;

    while (pTmp != NULL) {
        pPrec = pTmp;
        pTmp = pTmp->suivant;
        delete pPrec;
    }

    if (pTmp)
        delete pTmp;
    if (pTete)
        delete pTete;
}

/*==================== MODIFICATEURS ====================*/
template<class T>
void Liste<T>::insere(const T &val) {
#ifdef DEBUG
    cout << "Liste: insere" << endl;
#endif
    Cellule<T> *nvCell, *pTmp;
    pTmp = pTete;

    nvCell = new Cellule<T>;
    nvCell->valeur = val;
    // cout << "nv val: " << nvCell->valeur << " - address: " << nvCell << endl;

    if (pTmp == NULL) {
        pTete = nvCell;
    } else {
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
            cout << " ";
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
    Cellule<T> *pTmpThis, *pTmpCopie;
    pTmpThis = pTete;
    pTmpCopie = copie.pTete;

    while (pTmpCopie != NULL) {
        pTmpThis->valeur = pTmpCopie->valeur;
        pTmpCopie = pTmpCopie->suivant;
    }

    if (pTmpThis)
        delete pTmpThis;
    if (pTmpCopie)
        delete pTmpCopie;
}

template struct Cellule<int>;
template class Liste<int>;

template struct Cellule<Professeur>;
template class Liste<Professeur>;