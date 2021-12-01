#include <stdlib.h>
#include <iostream>
using namespace std;
#include <time.h>

#include "Classes/Professeur.h"
#include "Classes/Groupe.h"
#include "Classes/Local.h"

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();
void Essai5();

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
      default : fini = true ; break;
    }
  }

  return 0;
}

int Menu()
{
  cout << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 4 ----------------------------------------------------------" << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  cout << " 1. Test de la classe Professeur" << endl;
  cout << " 2. Test de la classe Groupe" << endl;
  cout << " 3. Test de la classe Local" << endl;
  cout << " 4. Heritage et virtualite : Test de la methode virtuelles Txt()" << endl;
  cout << " 5. Test du downcasting et du dynamic-cast" << endl;
  cout << " 6. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

/***********************************************************************************************/
// A FAIRE : la classe abstraite Planifiable qui contient les methodes VIRTUELLES PURES Txt() et Tuple()
//           la classe Professeur qui herite de Planifiable et qui contient le nom (char*) et le prenom (char*) d'un professeur
//           l'operateur << de Professeur
//           l'operateur d'affectation (=) de Professeur
void Essai1()
{
  cout << endl << "----- 1.1 Test du constructeur par defaut de Professeur ------------------------" << endl;
  Professeur p1;
  cout << "--> Voici p1 : " << p1 << endl;
 
  cout << endl << "----- 1.2 Test du constructeur d'initialisation de Professeur ------------------" << endl;
  Professeur p2(4,"Wagner","Jean-Marc");
  cout << "--> Voici p2 : " << p2 << endl;

  cout << endl << "----- 1.3 Test du constructeur de copie de Professeur --------------------------" << endl;
  Professeur p3(p2);
  cout << "--> Voici p3 : " << p3 << endl;

  cout << endl << "----- 1.4 Test des getXXX() et setXXX() de Professeur --------------------------" << endl;
  p3.setNom("Quettier");
  p3.setPrenom("Patrick");
  cout << "Nom    : " << p3.getNom() << endl;
  cout << "Prenom : " << p3.getPrenom() << endl;
  cout << "id     : " << p3.getId() << endl;

  cout << endl << "----- 1.5 Test des methodes virtuelles de Professeur ---------------------------" << endl;
  cout << "Txt   : " << p3.Txt() << endl;
  cout << "Tuple : " << p3.Tuple() << endl;

  cout << endl << "----- 1.6 Test de l'operateur = de Professeur ----------------------------------" << endl;
  p1 = p3;
  cout << "--> Voici p1 (apres affectation) : " << p1 << endl;
}

/***********************************************************************************************/
// A FAIRE : la classe Groupe qui herite de Planifiable, contenant en plus un numero (int)
//           les methodes virtuelles Txt() et Tuple()
//           l'operateur << de Groupe
//           l'operateur d'affectation (=) de Groupe

void Essai2()
{
  cout << endl << "----- 2.1 Test du constructeur par defaut --------------------------------------" << endl;
  Groupe g1;
  cout << "--> Voici g1 : " << g1 << endl;

  cout << endl << "----- 2.2 Test du constructeur d'initialisation de Groupe ----------------------" << endl;
  Groupe g2(2,2201);
  cout << "--> Voici g2 : " << g2 << endl;

  cout << endl << "----- 2.3 Test du constructeur de copie de Groupe ------------------------------" << endl;
  Groupe g3(g2);
  cout << "--> Voici g3 : " << g3 << endl;

  cout << endl << "----- 2.4 Test des getXXX() et setXXX() de Groupe ------------------------------" << endl;
  g3.setNumero(2225);
  cout << "Numero : " << g3.getNumero() << endl;
  cout << "id     : " << g3.getId() << endl;

  cout << endl << "----- 2.5 Test des methodes virtuelles de Groupe -------------------------------" << endl;
  cout << "Txt   : " << g3.Txt() << endl;
  cout << "Tuple : " << g3.Tuple() << endl;

  cout << endl << "----- 2.6 Test de l'operateur = de Groupe --------------------------------------" << endl;
  g1 = g3;
  cout << "--> Voici g1 (apres affectation) : " << g1 << endl;
}

/***********************************************************************************************/
// A FAIRE : la classe Local qui herite de Planifiable, contenant en plus un nom (char*)
//           les methodes virtuelles Txt() et Tuple()
//           l'operateur << de Local
//           l'operateur d'affectation (=) de Local

void Essai3()
{
  cout << endl << "----- 3.1 Test du constructeur par defaut --------------------------------------" << endl;
  Local l1;
  cout << "--> Voici l1 : " << l1 << endl;

  cout << endl << "----- 3.2 Test du constructeur d'initialisation de Local -----------------------" << endl;
  Local l2(11,"AN");
  cout << "--> Voici l2 : " << l2 << endl;

  cout << endl << "----- 3.3 Test du constructeur de copie de Local -------------------------------" << endl;
  Local l3(l2);
  cout << "--> Voici l3 : " << l3 << endl;

  cout << endl << "----- 3.4 Test des getXXX() et setXXX() de Local -------------------------------" << endl;
  l3.setNom("PV3");
  cout << "Nom : " << l3.getNom() << endl;
  cout << "id  : " << l3.getId() << endl;

  cout << endl << "----- 3.5 Test des methodes virtuelles de Local --------------------------------" << endl;
  cout << "Txt   : " << l3.Txt() << endl;
  cout << "Tuple : " << l3.Tuple() << endl;

  cout << endl << "----- 3.6 Test de l'operateur = de Local ---------------------------------------" << endl;
  l1 = l3;
  cout << "--> Voici l1 (apres affectation) : " << l1 << endl;
}

/******************************************************************************************/
// A FAIRE : normalement rien...
//           juste comprendre et tester le code ci-dessous

void Essai4()
{
  srand((unsigned)time(NULL));

  cout << endl << "----- 4.1 Allocation dynamique de planifiables ---------------------------------" << endl;
  Planifiable* planifiable[10];

  for (int i=0 ; i<10 ; i++)   // Tracez vos constructeurs !!!
  {
    cout << "planifiable[" << i << "] : ";
    int n = rand()%3;
    switch(n)
    {
      case 0 : planifiable[i] = new Professeur(1,"Vilvens","Claude");
               cout << "Professeur" << endl;
               break;

      case 1 : planifiable[i] = new Groupe(2,2225);
               cout << "Groupe" << endl;
               break;

      case 2 : planifiable[i] = new Local(3,"LE0");
               cout << "Local" << endl;
               break;
    }
  }

  cout << endl << "----- 4.2 Test de la methode VIRTUELLE Txt() -----------------------------------" << endl;
  for (int i=0 ; i<4 ; i++) {
    cout << "planifiable[" << i << "] : " << planifiable[i]->Txt() << endl;
    cout << "planifiable[" << i << "] : " << planifiable[i]->Tuple() << endl;
  }

  cout << endl << "----- 4.4 Liberation memoire ---------------------------------------------------" << endl;
  for (int i=0 ; i<4 ; i++) delete planifiable[i];  // Tout se passe-t-il comme vous voulez ?
  // Pour etre plus precis, quid des destructeurs et de la virtualite ?
}

/*********************************************************************************************/
// A FAIRE : normalement rien dans vos classes...
//           juste comprendre et tester le code ci-dessous

void Essai5()
{
  srand((unsigned)time(NULL));

  cout << endl << "----- 5.1 Allocation dynamique de planifiables ---------------------------------" << endl;
  Planifiable* planifiable[10];

  for (int i=0 ; i<10 ; i++)   // Tracez vos constructeurs !!!
  {
    cout << "planifiable[" << i << "] : ";
    int n = rand()%3;
    switch(n)
    {
      case 0 : planifiable[i] = new Professeur(1,"Leonard","Anne");
               cout << "Professeur" << endl;
               break;

      case 1 : planifiable[i] = new Groupe(2,2222);
               cout << "Groupe" << endl;
               break;

      case 2 : planifiable[i] = new Local(3,"PV11");
               cout << "Local" << endl;
               break;
    }
  }

  cout << endl << "----- 5.2 Test du downcasting et dynamic-cast ----------------------------------" << endl;
  for (int i=0 ; i<10 ; i++)
  {
    cout << "planifiable[" << i << "] ";
    Professeur* pProfesseur = dynamic_cast<Professeur*>(planifiable[i]);
    if (pProfesseur != NULL) cout << "est un Professeur : " << pProfesseur->getNom() << " " << pProfesseur->getPrenom() << endl;
    Groupe* pGroupe = dynamic_cast<Groupe*>(planifiable[i]);
    if (pGroupe != NULL) cout << "est un Groupe : " << pGroupe->getNumero() << endl;
    Local* pLocal = dynamic_cast<Local*>(planifiable[i]);
    if (pLocal != NULL) cout << "est un Local : " << pLocal->getNom() << endl;
  }

  cout << endl << "----- 5.3 Liberation memoire ---------------------------------------------------" << endl;
  for (int i=0 ; i<10 ; i++) delete planifiable[i];
}
