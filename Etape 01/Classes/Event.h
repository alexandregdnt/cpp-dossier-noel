#ifndef EVENT
#define EVENT

#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

class Event 
{
  private: 
    int code;
    char * intitule;

  public:
    // Constructeurs
    Event();
    Event(int, const char *);
    Event(const Event &);

    // Destructeur
    ~Event();

    // Set
    void setCode(int);
    void setIntitule(const char *);

    // Get
    int getCode() const;
    const char *getIntitule() const;

    // Autres méthodes
    void Affiche () const;
};
#endif