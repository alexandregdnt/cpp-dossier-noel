#include <stdlib.h>
#include <iostream>
#include <time.h>

#include "Classes/Temps.h"
#include "Classes/Timing.h"
#include "Classes/TempsException.h"
#include "Classes/TimingException.h"
#include "Classes/Event.h"

using namespace std;

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();
void Essai5();
void Essai6();
void Essai7();
void Essai8();
void Essai9();
void Essai10();
void Essai11();
void Essai12();

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
      case 5 : Essai5(); break;
      case 6 : Essai6(); break;
      case 7 : Essai7(); break;
      case 8 : Essai8(); break;
      case 9 : Essai9(); break;
      case 10 : Essai10(); break;
      case 11 : Essai11(); break;
      case 12 : Essai12(); break;
      default : fini = true ; break;
    }
  }

  return 0;
}

int Menu()
{
  cout << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 5 ---------------------------------------------------------" << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << " 1. Test des constructeurs, setXXX() de la classe Temps" << endl;
  cout << " 2. Test de l'operateur d'extraction (>>) de la classe Temps" << endl;
  cout << " 3. Test de l'operateur (Temps + int) de la classe Temps" << endl;
  cout << " 4. Test de l'operateur (int + Temps) de la classe Temps" << endl;
  cout << " 5. Test de l'operateur (Temps - int) de la classe Temps" << endl;
  cout << " 6. Test de l'operateur (int - Temps) de la classe Temps" << endl;
  cout << " 7. Test de l'operateur (Temps + Temps) de la classe Temps" << endl;
  cout << " 8. Test de l'operateur (Temps - Temps) de la classe Temps" << endl;
  cout << " 9. Test de l'operateur ++ de la classe Temps" << endl;
  cout << "10. Test de l'operateur -- de la classe Temps" << endl;
  cout << "11. Test de la methode setJour() de la classe Timing" << endl;
  cout << "12. Gestion de plusieurs exceptions simultanement" << endl;
  cout << "13. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

/**********************************************************************************************/
// ATTENTION !!!!
// Les methodes de vos classes NE doivent PAS contenir de TRY{...} CATCH{...} mais
// uniquement des THROW !!! Donc, votre classe lance une exception (une erreur) mais
// ce n'est pas elle qui la traite. C'est l'application qui utilise votre classe
// qui doit traiter les exceptions. C'est donc uniquement dans le main (ou les fonctions appelees)
// que l'on trouve des try...catch 
/**********************************************************************************************/
void Essai1()
{
  cout << "----- 1. Test des constructeurs, setXXX() de la classe Temps --------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee et le code de l'erreur

  // REMPLACER LES //... PAR TRY/CATCH

  try
  {
    int heure,minute;
    cout << "Entrez l'heure h1 :" << endl;
    cout << "Heure  : "; cin >> heure; cin.ignore();
    cout << "Minute : "; cin >> minute; cin.ignore();
    Temps h1(heure,minute); // !!!
    cout << "--> h1 = " << h1 << endl << endl;

    cout << "On modifie l'heure de h1 : " << endl;
    cout << "Nouvelle heure : "; cin >> heure; 
    h1.setHeure(heure); // !!!
    cout << "--> h1 = " << h1 << endl << endl;

    cout << "On modifie les minutes de h1 : " << endl;
    cout << "Nouvelles minutes : "; cin >> minute; 
    h1.setMinute(minute); // !!!
    cout << "--> h1 = " << h1 << endl << endl;

    cout << "Entrez la duree d1 : " << endl;
    int minutes;
    cout << "Duree en minutes : "; cin >> minutes; cin.ignore();
    Temps d1(minutes); // !!!
    cout << "--> d1 = " << d1 << endl << endl;    
  }
  catch (TempsException &e) {
      cout << endl << endl << e;
  }

  cout << endl;
}

/**********************************************************************************************/
void Essai2()
{
  cout << "----- 2. Test de l'operateur d'extraction (>>) de la classe Temps --------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee et le code de l'erreur

  // REMPLACER LES //... PAR TRY/CATCH

  try
  {
    cout << "Entrez l'heure h2 : " << endl;
    Temps h2;
    cin >> h2; // !!!
    cout << "--> h2 = " << h2 << endl << endl;
  }
  catch (TempsException &e) {
      cout << endl << endl << e;
  }

  cout << endl;
}

/**********************************************************************************************/
void Essai3()
{
  cout << "----- 3. Test de l'operateur (Temps + int) de la classe Temps --------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee et le code de l'erreur

  try
  {
    Temps h(15,30);
    cout << "h = Temps(15,30)" << endl;
    int duree;
    cout << "Entrez une duree en minutes : "; cin >> duree;
    h = h + duree;
    cout << "Apres addition (h = h + duree) --> " << h << endl << endl; 
  }
  catch (TempsException &e) {
      cout << endl << endl << e;
  }
  
  cout << endl;
}

/**********************************************************************************************/
void Essai4()
{
  cout << "----- 4. Test de l'operateur (int + Temps) de la classe Temps --------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee et le code de l'erreur

  try
  {
    Temps h(15,30);
    cout << "h = Temps(15,30)" << endl;
    int duree;
    cout << "Entrez une duree en minutes : "; cin >> duree;
    h = duree + h;
    cout << "Apres addition (h = duree + h) --> " << h << endl << endl; 
  }
  catch (TempsException &e) {
      cout << endl << endl << e;
  }
  
  cout << endl;
}

/**********************************************************************************************/
void Essai5()
{
  cout << "----- 5. Test de l'operateur (Temps - int) de la classe Temps --------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee et le code de l'erreur

  try
  {
    Temps h(1,30);
    cout << "h = Temps(1,30)" << endl;
    int duree;
    cout << "Entrez une duree en minutes : "; cin >> duree;
    h = h - duree;
    cout << "Apres soustraction (h = h - duree) --> " << h << endl << endl; 
  }
  catch (TempsException &e) {
      cout << endl << endl << e;
  }
  
  cout << endl;
}

/**********************************************************************************************/
void Essai6()
{
  cout << "----- 6. Test de l'operateur (int - Temps) de la classe Temps --------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee et le code de l'erreur

  try
  {
    Temps h(1,30);
    cout << "h = Temps(1,30)" << endl;
    int duree;
    cout << "Entrez une duree en minutes : "; cin >> duree;
    h = duree - h;
    cout << "Apres soustraction (h = duree - h) --> " << h << endl << endl; 
  }
  catch (TempsException &e) {
      cout << endl << endl << e;
  }
  
  cout << endl;
}

/**********************************************************************************************/
void Essai7()
{
  cout << "----- 7. Test de l'operateur (Temps + Temps) de la classe Temps --------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee et le code de l'erreur

  try
  {
    Temps h1(22,30);
    cout << "h1 = Temps(22,30)" << endl;
    int duree;
    cout << "Entrez une duree en minutes : "; cin >> duree;
    Temps d(duree);
    cout << "d = " << d << endl;
    h1 = h1 + d;
    cout << "Apres addtion (h1 = h1 + d) --> " << h1 << endl << endl; 
  }
  catch (TempsException &e) {
      cout << endl << endl << e;
  }
  
  cout << endl;
}

/**********************************************************************************************/
void Essai8()
{
  cout << "----- 8. Test de l'operateur (Temps - Temps) de la classe Temps --------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee et le code de l'erreur

  try
  {
    Temps d(120);
    cout << "d = " << d << endl;
    Temps h1;
    cout << "Entrez l'heure h1 : "; cin >> h1;
    h1 = h1 - d;
    cout << "Apres soustraction (h1 = h1 - d) --> " << h1 << endl << endl; 
  }
  catch (TempsException &e) {
      cout << endl << endl << e;
  }

  cout << endl;
}

/**********************************************************************************************/
void Essai9()
{
  cout << "----- 9. Test de l'operateur ++ de la classe Temps --------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee et le code de l'erreur

  try
  {
    Temps h;
    cout << "Entrez l'heure h = "; cin >> h;
    h++;
    ++h;
    cout << "Apres incrementation (h++) --> " << h << endl << endl; 
  }
  catch (TempsException &e) {
      cout << endl << endl << e;
  }
  
  cout << endl;
}

/**********************************************************************************************/
void Essai10()
{
  cout << "----- 10. Test de l'operateur -- de la classe Temps --------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee et le code de l'erreur

  try
  {
    Temps h;
    cout << "Entrez l'heure h = "; cin >> h;
    h--;
    --h;
    cout << "Apres decrementation (h--) --> " << h << endl << endl; 
  }
  catch (TempsException &e) {
      cout << endl << endl << e;
  }
  
  cout << endl;
}

/**********************************************************************************************/
void Essai11()
{
  cout << "----- 11. Test de la methode setJour() de la classe Timing --------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee et le code de l'erreur

  try
  {
    Timing t;
    char jour[80];
    cout << "Entrez le jour = ";
    cin.getline(jour,80,'\n');
    t.setJour(jour);
    t.Affiche();
  }
  catch (TimingException &e) {
      cout << endl << endl << e;
  }
  
  cout << endl;
}

/**********************************************************************************************/
void Essai12()
{
  cout << "----- 12. Gestion de plusieurs exceptions simultanement ---" << endl;
  // A COMPLETER : Traitez TOUTES les exceptions susceptible d'etre lancee par le bloc de code suivant (try...catch)

  try
  {
    Timing t;
    char jour[80];
    Temps heure;
    int d;
    cout << "Encodez un timing :" << endl;
    cout << "Jour = ";
    cin.getline(jour,80,'\n');
    t.setJour(jour);
    cout << "Heure = ";
    cin >> heure;
    t.setHeure(heure);
    cout << "Duree en minutes = ";
    cin >> d;
    cin.ignore();
    t.setDuree(Temps(d));
    cout << endl << "Timing encode : ";
    t.Affiche();
    cout << endl;
    Event e(1,"Theorie C++");
    cout << "Voici un Event non planifie : ";
    e.Affiche();
    cout << "Voulez-vous planifier cet Event (o/n) ? ";
    char ch;
    cin >> ch;
    cin.ignore();
    if (ch == 'o') e.setTiming(t);
    cout << "Voici le Timing de l'Event planifie : ";
    e.getTiming().Affiche();  // !!!
  }
  catch (TempsException &e) {
      cout << endl << endl << e;
  }
  catch (TimingException &e) {
      cout << endl << endl << e;
  }
}
