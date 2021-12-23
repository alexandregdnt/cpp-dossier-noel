#include "Iterateur.h"
#include "Professeur.h"

/*==================== DESTRUCTEUR ====================*/
template<class T>
Iterateur<T>::~Iterateur() {
#ifdef DEBUG
    cout << "[DEBUG] Iterateur: destructeur" << endl;
#endif
}

/*==================== AUTRES MÉTHODES ====================*/
template<class T>
void Iterateur<T>::reset() {
    pData = lis.getPTete();
}
template<class T>
bool Iterateur<T>::end() const {
    if (pData == NULL)
        return true;
    else
        return false;
}

/*==================== OPÉRATEURS ====================*/
template<class T>
bool Iterateur<T>::operator++() {
    if (!end()) {
        pData = pData->suivant;
        return true;
    } else {
        return false;
    }
}
template<class T>
bool Iterateur<T>::operator++(int) {
    return operator++();
}
template<class T>
Iterateur<T>::operator T() {
    return pData->valeur;
}

template class Iterateur<int>;
template class Iterateur<Professeur>;