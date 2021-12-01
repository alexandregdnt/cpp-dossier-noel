#ifndef PLANIFIABLE
#define PLANIFIABLE

#include <stdlib.h>
#include <iostream>

using namespace std;

class Planifiable {
protected:
    int id;
    char *txt;
    char *tuple;

public:
    /*==================== CONSTRUCTEURS ====================*/
    Planifiable();

    /*==================== DESTRUCTEUR ====================*/
    virtual ~Planifiable();

    /*==================== SETTERS ====================*/
    void setId(int);

    /*==================== GETTERS ====================*/
    int getId() const;

    /*==================== AUTRES MÉTHODES ====================*/
    virtual const char *Txt() = 0;
    virtual const char *Tuple() = 0;

};

#endif