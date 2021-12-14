#ifndef EVENT
#define EVENT

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Timing.h"
using namespace std;

class Event
{
  private :
    int code;
    char *intitule;
    Timing* timing;
  
  public :
    //VARIABLE
    static int codeCourant;

    //CONSTRUCTEUR
    Event();
    Event(int code, const char* intitule, Timing timing);
    Event(int c, const char* i);
    Event(Event& e);
    
    //DESTRUCTEUR
    ~Event();
    
    //SETTEUR
    void setCode(int code);
    void setIntitule(const char* i);
    void setTiming(const Timing& t);
    
    //GETTEUR
    int getCode() const;
    const char* getIntitule() const;
    Timing getTiming() const;

    //AFFICHAGE
    void Affiche() const;

    //METHODE
    void Save(ofstream& fichier) const;
    void Load(ifstream& fichier);
};

#endif