#include <iostream>
#include <fstream>
using namespace std;

#include "Temps.h"
#include "Timing.h"
#include "Event.h"

int  Menu();
void Essai1();
void Essai2();
void Essai3();

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
      default : fini = true ; break;
    }
  }

  return 0;
}

int Menu()
{
  cout << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 7 ---------------------------------------------------------" << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << " 1. Test des methodes Save et Load de la classe Temps" << endl;
  cout << " 2. Test des mathodes Save et Load de la classe Timing" << endl;
  cout << " 3. Test des methodes Save et Load de la classe Event" << endl;
  cout << " 4. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

/*********************************************************************************************/
void Essai1()  // Attention : utilisez les flux bytes (read et write) !!!!
{
  cout << "----- 1. Test des methodes Save et Load de la classe Temps ------" << endl;
  
  Temps h(8,20);
  h.Affiche();
  cout << endl;

  cout << "----- Sauvegarde de l'heure dans le fichier H.dat -----" << endl;
  ofstream fichier1("H.dat",ios::out);
  h.Save(fichier1);
  fichier1.close();

  cout << "----- Chargement de l'heure situee dans le fichier H.dat -----" << endl;
  ifstream fichier2("H.dat",ios::in);
  Temps t2;
  t2.Load(fichier2);
  fichier2.close();
  t2.Affiche();
  cout << endl;
}

/*********************************************************************************************/
void Essai2()  // Attention : utilisez les flux bytes (read et write) !!!!
{
  cout << "----- 2. Test des methodes Save et Load de la classe Timing ------" << endl;
  
  Timing t(Timing::MARDI,Temps(10,30),Temps(120));
  t.Affiche();
  cout << endl;

  cout << "----- Sauvegarde du timing dans le fichier T.dat -----" << endl;
  ofstream fichier1("T.dat",ios::out);
  t.Save(fichier1);
  fichier1.close();

  cout << "----- Chargement du timing situe dans le fichier T.dat -----" << endl;
  ifstream fichier2("T.dat",ios::in);
  Timing t2;
  t2.Load(fichier2);
  fichier2.close();
  t2.Affiche();
  cout << endl;
}

/*********************************************************************************************/
void Essai3()  // Attention : utilisez les flux bytes (read et write) !!!!
{
  cout << "----- 3. Test des methodes Save et Load de la classe Event ------" << endl;

  Event e(1,"Labo C++");
  e.setTiming(Timing(Timing::MARDI,Temps(10,30),Temps(120)));
  e.Affiche();

  cout << "----- Sauvegarde de l'event dans le fichier E.dat -----" << endl;
  ofstream fichier1("E.dat",ios::out);
  e.Save(fichier1);
  fichier1.close();

  cout << "----- Chargement de l'event situe dans le fichier E.dat -----" << endl;
  ifstream fichier2("E.dat",ios::in);
  Event e2;
  e2.Load(fichier2);
  fichier2.close();
  e2.Affiche();
  cout << endl;
}

