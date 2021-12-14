#include <stdlib.h>
#include <iostream>
using namespace std;
#include "Classes/Temps.h"
#include "Classes/Timing.h"
#include "Classes/Event.h"

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();

int main(int argc,char* argv[])
{
  int choix;
  bool fini = false;
  
  while(!fini)
  {
    if (argc == 2) { choix = atoi(argv[1]); fini = true; }
    else choix = Menu();
    switch(choix)
    {
      case 1 : Essai1(); break;
      case 2 : Essai2(); break;
      case 3 : Essai3(); break;
      case 4 : Essai4(); break;
      default : fini = true ; break;
    }
  }

  return 0;
}

/*******************************************************************************************************/
int Menu()
{
  cout << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TESTS 2 -------------------------------------------------------------------" << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << " 1. Tests de la classe Temps" << endl;
  cout << " 2. Tests de la classe Timing (Agregation par valeur avec un objet Temps)" << endl;
  cout << " 3. Tests de la classe Event (Agregation par reference avec un objet Timing)" << endl;
  cout << " 4. Tests des variables statiques utiles" << endl;
  cout << " 5. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  return ch;
}

/*******************************************************************************************************/
/*** Tests de la classe Temps **************************************************************************/
/*******************************************************************************************************/
void Essai1()
{
  cout << endl << "(1) ***** Test du constructeur par defaut de Temps *****************************" << endl;
  {
    Temps heure;
    heure.Affiche();
    cout << endl;
  }

  cout << endl << "(2) **** Test des setters/getters **********************************************" << endl;
  {
    Temps heure;
    heure.Affiche();
    cout << endl;
    heure.setHeure(9);
    heure.setMinute(20);
    heure.Affiche();
    cout << endl << "heure : " << heure.getHeure() << endl;
    cout << "Minute : " << heure.getMinute() << endl;
  }

  cout << endl << "(3) ***** Test du constructeur d'initialisation de Temps (heure) ***************" << endl;
  {
    Temps h(8,5);
    h.Affiche();
    cout << endl;
  }

  cout << endl << "(4) ***** Test du constructeur d'initialisation de Temps (duree) ***************" << endl;
  {
    Temps d(135);
    d.Affiche();
    cout << endl;
  }

  cout << endl << "(5) ***** Test du constructeur de copie de Temps *******************************" << endl;
  {
    Temps h1(10,30);
    h1.Affiche();
    cout << endl << "Copie : " ;
    Temps h2(h1);
    h2.Affiche();
    cout << endl;
  }
}

/*******************************************************************************************************/
/*** Tests de la classe Timing (Agregation par valeur avec un objet Temps) *****************************/
/*******************************************************************************************************/
void Essai2()
{
  cout << endl << "(1) ***** Test du constructeur par defaut de Timing ****************************" << endl;
  {
    Timing t;
    t.Affiche();
    cout << endl;
  }

  cout << endl << "(2) **** Test des setters/getters **********************************************" << endl;
  {
    Timing t;
    t.setJour("Mardi");
    t.setHeure(Temps(8,20));
    t.setDuree(Temps(90));
    t.Affiche();
    cout << endl;
    cout << "Jour  : " << t.getJour() << endl;
    cout << "Heure : ";
    t.getHeure().Affiche();
    cout << endl;
    cout << "Duree : ";
    t.getDuree().Affiche();
    cout << endl;
  }

  cout << endl << "(3) ***** Test du constructeur d'initialisation de Timing **********************" << endl;
  {
    Timing t("Vendredi",Temps(13,30),Temps(120));
    t.Affiche();
    cout << endl;
  }

  cout << endl << "(4) ***** Test du constructeur de copie de Timing ******************************" << endl;
  {
    Temps h1(13,0);
    Timing t1("Mercredi",Temps(10,30),Temps(120));
    cout << "t1 (AVANT) : ";
    t1.Affiche();
    cout << endl;
    {   
      Timing t2(t1);
      cout << "t2 : ";
      t2.Affiche();
      cout << endl;
      t2.setHeure(h1);
      t2.setJour("jeudi");
      cout << "t2 : ";
      t2.Affiche();
      cout << endl;
    }
    cout << "t1 (APRES) : ";
    t1.Affiche();
    cout << endl << endl;
  }
}

/*******************************************************************************************************/
/*** Tests de la classe Event (Agregation par reference d'un objet Timing) *****************************/
/*******************************************************************************************************/
void Essai3()
{
  cout << endl << "(1) ***** Test constructeur par defaut + Affiche *******************************" << endl;
  {
    Event event;
    event.Affiche();
    cout << endl;
  } 

  cout << endl << "(2) ***** Test des setters et getters ******************************************" << endl;
  {
    Event event;
    event.setCode(1);
    event.setIntitule("Resto avec Denys (Merci Denys :)");
    event.setTiming(Timing("Mardi",Temps(20,0),Temps(180)));
    event.Affiche();
    cout << endl;
    cout << "Code        = " << event.getCode() << endl;
    cout << "Intitule    = " << event.getIntitule() << endl;
    cout << "Timing      = ";
    event.getTiming().Affiche();
    cout << endl;
  }

  cout << endl << "(3) ***** Test du constructeur d'initialisation ********************************" << endl;
  {
    Event event(2,"Cinema avec les potos");
    event.setTiming(Timing("Vendredi",Temps(19,30),Temps(150)));
    event.Affiche();
    cout << endl;
  }

  cout << endl << "(4) ***** Test du constructeur de copie ****************************************" << endl;
  {
    Event event1(1,"Labo C++");
    event1.setTiming(Timing("Lundi",Temps(8,20),Temps(90)));
    cout << "event1 (AVANT) : ";
    event1.Affiche();
    cout << endl;
    {   
      Event event2(event1);
      cout << "event2 : ";
      event2.Affiche();
      cout << endl;
      event2.setTiming(Timing("Jeudi",Temps(13,30),Temps(90)));
      cout << "event2 : ";
      event2.Affiche();
      cout << endl;
    } // de nouveau, les {} assurent que event2 sera detruit avant la suite
    cout << "event1 (APRES) : ";
    event1.Affiche();
    cout << endl << endl;
  }
}

/*******************************************************************************************************/
/*** Tests des variables statiques utiles **************************************************************/
/*******************************************************************************************************/
void Essai4()
{
  cout << endl << "(1) ***** Tests de base des jours de la semaine ********************************" << endl;
  cout << "Premier jour de la semaine : " << Timing::LUNDI << endl;
  // ne pas oublier les autres jours de la semaine...
  cout << "Dernier jour de la semaine : " << Timing::DIMANCHE << endl << endl;
  
  cout << endl << "(2) ***** Tests de base de la variable Event::idCourant ************************" << endl;
  cout << "Event::codeCourant = " << Event::codeCourant << endl;
  Event::codeCourant++;
  cout << "Event::codeCourant = " << Event::codeCourant << endl << endl;

  cout << endl << "(3) ***** Creation d'evenements ************************************************" << endl;
  Event::codeCourant = 1;

  Event e1(Event::codeCourant,"Theorie C++");
  e1.setTiming(Timing(Timing::MARDI,Temps(8,20),Temps(90)));
  Event::codeCourant++;
  cout << "e1 : ";
  e1.Affiche();
  cout << endl;
  cout << "Event::codeCourant = " << Event::codeCourant << endl;
  cout << "e1.codeCourant = " << e1.codeCourant << endl << endl;

  Event e2(Event::codeCourant,"Labo C++");
  e2.setTiming(Timing(Timing::MERCREDI,Temps(13,30),Temps(120)));
  e2.codeCourant++;
  cout << "e2 : ";
  e2.Affiche();
  cout << endl;
  cout << "Event::codeCourant = " << Event::codeCourant << endl;
  cout << "e1.codeCourant = " << e1.codeCourant << endl;
  cout << "e2.codeCourant = " << e2.codeCourant << endl << endl;

  Event e3(Event::codeCourant,"Labo UNIX");
  e3.setTiming(Timing(Timing::JEUDI,Temps(10,30),Temps(120)));
  Event::codeCourant++;
  cout << "e3 : ";
  e3.Affiche();
  cout << endl;
  cout << "Event::codeCourant = " << Event::codeCourant << endl;
  cout << "e1.codeCourant = " << e1.codeCourant << endl;
  cout << "e2.codeCourant = " << e2.codeCourant << endl;
  cout << "e3.codeCourant = " << e3.codeCourant << endl << endl;
}
