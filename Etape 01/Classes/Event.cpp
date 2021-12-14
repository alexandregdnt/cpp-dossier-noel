#include "Event.h"

// Constructeur
Event::Event() {
  #ifdef DEBUG
  cout << "Event: constructeur par défaut" << endl;
  #endif
  code = -1;
  intitule = NULL;
}

Event::Event(int c, const char *i) {
  #ifdef DEBUG
  cout << "Event: constructeur d'initialisation" << endl;
  #endif
  code = -1;
  intitule = NULL;

  setCode(c);
  setIntitule(i);
}

Event::Event(const Event &event) {
  code = -1;
  intitule = NULL;
  
  setCode(event.getCode());
  setIntitule(event.getIntitule());
}

// Destructeur
Event::~Event() {
  #ifdef DEBUG
  cout << "Event: destructeur " << code << endl;
  #endif
  if (intitule)
    delete intitule;
}

// Set
void Event::setCode(int c)
{
  if (c < 1) return;
  code = c;
}
void Event::setIntitule(const char *i)
{
  if (i == NULL) return;
  if (intitule) delete intitule;

  intitule = new char[strlen(i)+1];
  strcpy(intitule, i);
}

// Get
int Event::getCode() const 
{
  return code;
}
const char *Event::getIntitule() const 
{
  return intitule;
}

// Autres méthodes
void Event::Affiche () const {
  cout << "Event: code: " << code << ", intitule: ";
  if (intitule)
    cout << intitule << endl;
  else
    cout << "/" << endl;
}