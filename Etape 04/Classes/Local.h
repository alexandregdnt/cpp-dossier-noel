#ifndef LOCAL
#define LOCAL

#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include "Planifiable.h"

using namespace std;

class Local: public Planifiable {
private:
    char *nom;

public:
    /*==================== CONSTRUCTEURS ====================*/
    Local();
    Local(int, const char *);
    Local(const Local &);

    /*==================== DESTRUCTEUR ====================*/
    ~Local();

    /*==================== SETTERS ====================*/
    void setNom(const char*);

    /*==================== GETTERS ====================*/
    const char *getNom() const;

    /*==================== AUTRES MÉTHODES ====================*/
    const char *Txt();
    const char *Tuple();

    /*==================== OPÉRATEURS ====================*/
    void operator= (const Local &);
    friend ostream &operator<< (ostream &, const Local &); // const

};

#endif