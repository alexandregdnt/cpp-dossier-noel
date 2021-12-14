#ifndef TEMPS
#define TEMPS

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

#include"TempsException.h"

class Temps
{
    private :
      int heure;
      int minute;

    public :
      //CONSTRUCTEUR
      Temps();
      Temps(int heure, int minute);
      Temps(int duree);
      Temps(const Temps& t);

      //DESTRUCTEUR
      ~Temps();

      //GETTEUR
      int getHeure() const;
      int getMinute() const;

      //SETTEUR
      void setHeure(int h);
      void setMinute(int m);

      //AFFICHAGE
      void Affiche() const;

      //OPERATEUR
      Temps& operator=(const Temps& t);
      Temps operator+(int d);
      Temps operator+(const Temps& t);
      friend Temps operator+(int d, const Temps t);
      Temps operator-(int d);
      Temps operator-(const Temps& t);
      friend Temps operator-(int d, const Temps t);
      int operator>(const Temps& t) const;
      int operator<(const Temps& t) const;
      int operator==(const Temps& t) const;
      friend ostream& operator<<(ostream& s, const Temps& t);
      friend istream& operator>>(istream& s, Temps& t);
      Temps operator++();
      Temps operator++(int i);
      Temps operator--();
      Temps operator--(int i);

      //METHODE
      void Save(ofstream& fichier) const;
      void Load(ifstream& fichier); 
};

#endif

