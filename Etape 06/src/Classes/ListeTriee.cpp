#include "ListeTriee.h"
#include "Professeur.h"

/*==================== CONSTRUCTEURS ====================*/
template<class T>
ListeTriee<T>::ListeTriee(): Liste<T>() {
#ifdef DEBUG
    cout << "[DEBUG] ListeTriee: constructeur par défaut" << endl;
#endif
}
template<class T>
ListeTriee<T>::ListeTriee(const ListeTriee<T> &copie): Liste<T>(copie) {
#ifdef DEBUG
    cout << "[DEBUG] ListeTriee: constructeur de copie" << endl;
#endif
}

/*==================== DESTRUCTEUR ====================*/
template<class T>
ListeTriee<T>::~ListeTriee() {
#ifdef DEBUG
    cout << "[DEBUG] ListeTriee: destructeur" << endl;
#endif
}

/*==================== AUTRES MÉTHODES ====================*/
template<class T>
void ListeTriee<T>::insere(const T &val) {
    if (Liste<T>::estVide()) {
        pTete = new Cellule<T>;
        pTete->valeur = val;
        pTete->suivant = NULL;
    } else {
        Cellule<T> *nvCell, *pTmp, *pPrec;
        pTmp = pTete;
        pPrec = pTete;

        nvCell = new Cellule<T>;
        nvCell->valeur = val;
        nvCell->suivant = NULL;
        // cout << "nv val: " << nvCell->valeur << " - address: " << nvCell << endl;

        while (pTmp->suivant != NULL && pTmp->valeur <= nvCell->valeur) {
            pPrec = pTmp;
            pTmp = pTmp->suivant;
        }

        // Insertion de la nouvelle valeur
        if (pTmp == pTete) {
            if (nvCell->valeur < pTmp->valeur) {
                nvCell->suivant = pTmp;
                pTete = nvCell;
            } else {
                pTmp->suivant = nvCell;
            }
        } else {
            if (nvCell->valeur < pTmp->valeur) {
                pPrec->suivant = nvCell;
                nvCell->suivant = pTmp;
            } else {
                pTmp->suivant = nvCell;
            }
        }
    }
#ifdef DEBUG
    cout << "[DEBUG] ListeTriee: insere: " << Liste<T>::getNombreElements() << ". ";
        Liste<T>::Affiche();
#endif
}

template class ListeTriee<int>;
template class ListeTriee<Professeur>;