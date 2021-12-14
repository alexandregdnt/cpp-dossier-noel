#ifndef EXCEPTION
#define EXCEPTION

#include <stdlib.h>

using namespace std;

class Exception {
protected:
    char *message;

public:
    /*==================== CONSTRUCTEURS ====================*/
    Exception();

    /*==================== DESTRUCTEUR ====================*/
    virtual ~Exception();

    /*==================== DESTRUCTEUR ====================*/
    const char *getMessage() const;

    /*==================== AUTRES MÉTHODES ====================*/
    virtual int getCode() const = 0;
};

#endif