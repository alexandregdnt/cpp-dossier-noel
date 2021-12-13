#ifndef TEMPS_EXCEPTION
#define TEMPS_EXCEPTION

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Exception.h"

using namespace std;

class TempsException: public Exception {
private:
    int code;

public:
    /*==================== VARIABLES ====================*/
    static const int HEURE_INVALIDE;
    static const int MINUTE_INVALIDE;
    static const int DEPASSEMENT;
    static const int FORMAT_INVALIDE;

    /*==================== CONSTRUCTEURS ====================*/
    TempsException();
    TempsException(int);

    /*==================== DESTRUCTEUR ====================*/
    ~TempsException();

    /*==================== GETTERS ====================*/
    int getCode() const;

    /*==================== OPÉRATEURS ====================*/
    friend ostream &operator<<(ostream &s, const TempsException &exception);

};

#endif