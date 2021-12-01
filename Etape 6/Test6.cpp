#include <stdlib.h>
#include <iostream>
#include <time.h>

#include "Classes/Temps.h"
#include "Classes/Timing.h"
#include "Classes/Liste.h"
#include "Classes/Professeur.h"
#include "Classes/ListeTriee.h"
#include "Classes/Iterateur.h"

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
      default : fini = true ; break;
    }
  }

  return 0;
}

int Menu()
{
  cout << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 6 ---------------------------------------------------------" << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << " 1. Test du template Liste avec des entiers" << endl;
  cout << " 2. Test du template Liste avec des objets de la classe Professeur" << endl;
  cout << " 3. Test du template ListeTriee avec des entiers" << endl;
  cout << " 4. Test du template ListeTriee avec des objets de la classe Professeur" << endl;
  cout << " 5. Test de l'iterateur avec une Liste d'entiers" << endl;
  cout << " 6. Test de l'iterateur avec une Liste de Professeurs" << endl;
  cout << " 7. Test de l'iterateur avec une Liste triee d'entiers" << endl;
  cout << " 8. Test de l'iterateur avec une Liste triee de Professeurs" << endl;
  cout << " 9. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

/*******************************************************************************************************/
void Essai1()
{
  cout << "----- 1. Test du template Liste avec des entiers --------------------------------------------" << endl;
  cout << "----- 1.1 Creation et gestion d'une Liste ---------------------------------------------------" << endl;

  Liste<int> liste;
  liste.Affiche();                                       // --> ()
  cout << endl;

  cout << "Liste Vide ? " << liste.estVide() << endl;
  cout << "On insere 3,-2,5,-1,0 et 17..." << endl;
  liste.insere(3);
  liste.insere(-2);
  liste.insere(5);
  liste.insere(-1);
  liste.insere(0);
  liste.insere(17);
  cout << "Liste Vide ? " << liste.estVide() << endl;
  liste.Affiche();                                       // --> (3 -2 5 -1 0 17)
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl;

  cout << "----- 1.2 On retire des elements de la Liste ------------------------------------------------" << endl;
  cout << "On retire l'element d'indice 4 (0)  : " << liste.retire(4) << endl;
  liste.Affiche();
  cout << "On retire l'element d'indice 0 (3)  : " << liste.retire(0) << endl;
  liste.Affiche();
  cout << "On retire l'element d'indice 3 (17) : " << liste.retire(3) << endl;
  liste.Affiche();

  cout << "----- 1.3 Test du constructeur de copie -----------------------------------------------------" << endl;
  {
    Liste<int> liste2(liste);
    cout << "----> Voici la copie :" << endl;
    liste2.Affiche();
    cout << "----> On insere 50 dans la copie :" << endl; 
    liste2.insere(50);
    liste2.Affiche();
    cout << "----> Destruction de la copie..." << endl;
  }
  cout << endl << "Et revoici la liste de depart : " << endl;
  liste.Affiche();
  cout << endl;

  cout << "----- 1.4 Test de l'operateur = -------------------------------------------------------------" << endl;
  {
    Liste<int> liste3;
    liste3 = liste;
    cout << "----> Voici le resultat de l'operateur = :" << endl;
    liste3.Affiche();
    cout << "----> On insere 50 dans la nouvelle liste :" << endl; 
    liste3.insere(50);
    liste3.Affiche();
    cout << "----> Destruction de la nouvelle liste..." << endl;
  }
  cout << endl << "Et revoici la liste de depart : " << endl;
  liste.Affiche();
  cout << endl;
}

/*********************************************************************************************/
void Essai2()
{
  cout << "----- 2. Test du template Liste avec des objets de la classe Professeur --------------" << endl;
  cout << "Creation  d'une Liste..." << endl;
  Liste<Professeur> liste;
  liste.Affiche();                                    
  cout << endl;

  cout << "On insere Professeur(1,\"Wagner\",\"Jean-Marc\")..." << endl;
  liste.insere(Professeur(1,"Wagner","Jean-Marc"));
  liste.Affiche();

  cout << "On insere p(2,\"Leonard\",\"Anne\")..." << endl;
  Professeur p(2,"Leonard","Anne");
  liste.insere(p);
  liste.Affiche();

  cout << "On insere new Professeur(3,\"Quettier\",\"Patrick\")..." << endl;
  Professeur *ptr = new Professeur(3,"Quettier","Patrick");
  liste.insere(*ptr);
  delete ptr;
  liste.Affiche();
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl << endl;

  cout << endl;
}

/*******************************************************************************************************/
void Essai3()
{
    /*
  cout << "----- 3. Test du template ListeTriee avec des entiers ---------------------------------------" << endl;
  cout << "----- 3.1 Creation et gestion d'une Liste triee ---------------------------------------------" << endl;

  ListeTriee<int> liste;
  liste.Affiche();                                       // --> ()
  cout << endl;

  cout << "Liste Vide ? " << liste.estVide() << endl;
  cout << "On insere 3,-2,5,-1,0 et 17..." << endl;
  liste.insere(3);
  liste.insere(-2);
  liste.insere(5);
  liste.insere(-1);
  liste.insere(0);
  liste.insere(17);
  cout << "Liste Vide ? " << liste.estVide() << endl;
  liste.Affiche();                                       // --> (-2 -1 0 3 5 17)
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl << endl;

  cout << "----- 3.2 On retire des elements de la Liste ------------------------------------------------" << endl;
  cout << "On retire l'element d'indice 4 (5)  : " << liste.retire(4) << endl;
  liste.Affiche();
  cout << "On retire l'element d'indice 0 (-2)  : " << liste.retire(0) << endl;
  liste.Affiche();
  cout << "On retire l'element d'indice 3 (17) : " << liste.retire(3) << endl;
  liste.Affiche();
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl;
  cout << endl;
     */
}

/*******************************************************************************************************/
void Essai4()
{
    /*
  cout << "----- 4. Test du template ListeTriee avec des objets de la classe Professeur ---------------" << endl;
  cout << "Creation  d'une Liste triee..." << endl;
  ListeTriee<Professeur> liste;
  liste.Affiche();                                       
  cout << endl;

  cout << "On insere quelques professeurs..." << endl;
  liste.insere(Professeur(1,"Wagner","Jean-Marc"));
  liste.insere(Professeur(2,"Leonard","Anne"));
  liste.insere(Professeur(3,"Quettier","Patrick"));
  liste.insere(Professeur(4,"Vilvens","Claude"));
  liste.insere(Professeur(5,"Charlet","Christophe"));
  liste.insere(Professeur(6,"Quettier","Sophie"));
  liste.Affiche();
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl;
  cout << endl;
     */
}

/*******************************************************************************************************/
void Essai5()
{
    /*
  cout << "----- 5. Test de l'iterateur avec une Liste d'entiers ------------------------" << endl;
  cout << "Creation  d'une Liste..." << endl;
  Liste<int> liste;

  cout << "On insere 3,-2,5,-1 et 0..." << endl;
  liste.insere(3);
  liste.insere(-2);
  liste.insere(5);
  liste.insere(-1);
  liste.insere(0);

  cout << "On affiche grace a un iterateur..." << endl;
  Iterateur<int> it(liste);
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (int)it << endl;
  cout << endl;

  cout << "On supprime l'element d'indice 1 et on re-affiche grace a l'iterateur..." << endl;
  liste.retire(1);
  it.reset();
  while (!it.end())
  {
    cout << " " << (int)it << endl;
    it++;
  }
     */
}

/*******************************************************************************************************/
void Essai6()
{
    /*
  cout << "----- 6. Test de l'iterateur avec une Liste de Professeurs ---------------------" << endl;
  cout << "Creation  d'une Liste..." << endl;
  Liste<Professeur> liste;
  
  cout << "On insere quelques professeurs..." << endl;
  liste.insere(Professeur(1,"Wagner","Jean-Marc"));
  liste.insere(Professeur(2,"Leonard","Anne"));
  liste.insere(Professeur(3,"Quettier","Patrick"));
  liste.insere(Professeur(4,"Vilvens","Claude"));
  liste.insere(Professeur(5,"Charlet","Christophe"));
  liste.insere(Professeur(6,"Quettier","Sophie"));

  cout << "On affiche grace a un iterateur..." << endl;
  Iterateur<Professeur> it(liste);
  for (it.reset() ; !it.end() ; it++)
  {
    Professeur p = (Professeur)it;
    cout << " " << p << " >> Tuple = " << p.Tuple() << endl;
  }
  cout << endl;

  cout << "On supprime l'element d'indice 1 et on re-affiche grace a l'iterateur..." << endl;
  liste.retire(1);
  it.reset();
  while (!it.end())
  {
    cout << " " << (Professeur)it << endl;
    it++;
  }
     */
}

/*******************************************************************************************************/
void Essai7()
{
 /*
  cout << "----- 7. Test de l'iterateur avec une ListeTriee d'entiers ------------------------" << endl;
  cout << "Creation  d'une Liste triee..." << endl;
  ListeTriee<int> liste;

  cout << "On insere 3,-2,5,-1 et 0..." << endl;
  liste.insere(3);
  liste.insere(-2);
  liste.insere(5);
  liste.insere(-1);
  liste.insere(0);

  cout << "On affiche grace a un iterateur..." << endl;
  Iterateur<int> it(liste);
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (int)it << endl;
  cout << endl;

  cout << "On supprime l'element d'indice 1 et on re-affiche grace a l'iterateur..." << endl;
  liste.retire(1);
  it.reset();
  while (!it.end())
  {
    cout << " " << (int)it << endl;
    it++;
  }
  */
}

/*******************************************************************************************************/
void Essai8()
{
    /*

  cout << "----- 8. Test de l'iterateur avec une ListeTriee de Professeurs ---------------------" << endl;
  cout << "Creation  d'une Liste triee..." << endl;
  ListeTriee<Professeur> liste;
  
  cout << "On insere quelques professeurs..." << endl;
  liste.insere(Professeur(1,"Wagner","Jean-Marc"));
  liste.insere(Professeur(2,"Leonard","Anne"));
  liste.insere(Professeur(3,"Quettier","Patrick"));
  liste.insere(Professeur(4,"Vilvens","Claude"));
  liste.insere(Professeur(5,"Charlet","Christophe"));
  liste.insere(Professeur(6,"Quettier","Sophie"));

  cout << "On affiche grace a un iterateur..." << endl;
  Iterateur<Professeur> it(liste);
  for (it.reset() ; !it.end() ; it++)
  {
    Professeur p = (Professeur)it;
    cout << " " << p << " >> Tuple = " << p.Tuple() << endl;
  }
  cout << endl;

  cout << "On supprime l'element d'indice 1 et on re-affiche grace a l'iterateur..." << endl;
  liste.retire(1);
  it.reset();
  while (!it.end())
  {
    cout << " " << (Professeur)it << endl;
    it++;
  }
     */
}
