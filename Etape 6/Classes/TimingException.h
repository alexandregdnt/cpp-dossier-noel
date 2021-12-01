#ifndef TIMING_EXCEPTION
#define TIMING_EXCEPTION

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Exception.h"
#include "TempsException.h"

using namespace std;

class TimingException: public Exception {
private:
    int code;

public:
    /*==================== VARIABLES ====================*/
    static const int JOUR_INVALIDE;
    static const int AUCUN_TIMING;

    /*==================== CONSTRUCTEURS ====================*/
    TimingException();
    TimingException(int);

    /*==================== DESTRUCTEUR ====================*/
    ~TimingException();

    /*==================== GETTERS ====================*/
    int getCode() const;

    /*==================== OPÉRATEURS ====================*/
    friend ostream &operator<<(ostream &s, const TimingException &exception);

};

#endif