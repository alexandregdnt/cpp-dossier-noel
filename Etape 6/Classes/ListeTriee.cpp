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

/*==================== DESTRUCTEUR ====================*/
template<class T>
void ListeTriee<T>::insere(const T &) {

}

template class ListeTriee<int>;
template class ListeTriee<Professeur>;