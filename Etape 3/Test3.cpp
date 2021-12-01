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
void Essai5();
void Essai6();
void Essai7();

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
  cout << " 1. Tests de l'operateur = de la classe Temps" << endl;
  cout << " 2. Tests de l'operateur + de la classe Temps" << endl;
  cout << " 3. Tests de l'operateur - de la classe Temps" << endl;
  cout << " 4. Tests des operateurs < > == de la classe Temps" << endl;
  cout << " 5. Test des operateurs << et >> de la classe Temps" << endl;
  cout << " 6. Tests des operateurs de pre/post in(de)crementation de la classe Temps" << endl;
  cout << " 7. Tests des operateurs < > == de la classe Timing" << endl;
  cout << " 8. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

/*******************************************************************************************************/
/*** Tests des operateurs = de la classe Temps *********************************************************/
/*******************************************************************************************************/
void Essai1()
{
  cout << "********************************************************************" << endl;
  cout << "(1) ***** Test de l'operateur d'affectation de Temps ***************" << endl;
  cout << "********************************************************************" << endl;
  {
    Temps h1(8,20);
    cout << "h1 (avant affectation) : ";
    h1.Affiche();
    Temps h2;
    cout << " >>>>> h2 = h1;" << endl;
    h2 = h1;
    cout << "h2 : ";
    h2.Affiche();
    cout << " h1 (apres affectation) : ";
    h1.Affiche();
  }
}

/*******************************************************************************************************/
/*** Tests des operateurs + de la classe Temps *********************************************************/
/*******************************************************************************************************/
void Essai2()
{
  cout << endl << "********************************************************************" << endl;
  cout <<         "(1) ***** Test de l'operateur (Temps + int) ************************" << endl;
  cout <<         "********************************************************************" << endl;
  {
    Temps h(13,30);
    cout << "h (avant) : ";
    h.Affiche();
    Temps h2;
    cout << ">>>>> h2 = h + 10;" << endl;
    h2 = h + 10;
    cout << "h2 : ";
    h2.Affiche();
    cout << ">>>>> h2 = h2 + 30;" << endl;
    h2 = h2 + 30;
    cout << "h2 : ";
    h2.Affiche();
    cout << "h (apres) : "; // h ne doit pas etre modifie !!!!
    h.Affiche();
  }

  cout << endl << "********************************************************************" << endl;
  cout <<         "(2) ***** Test de l'operateur (int + Temps) ************************" << endl;
  cout <<         "********************************************************************" << endl;
  {
    Temps h(13,30);
    cout << "h (avant) : ";
    h.Affiche();
    Temps h2;
    cout << ">>>>> h2 = 10 + h;" << endl;
    h2 = 10 + h;
    cout << "h2 : ";
    h2.Affiche();
    cout << ">>>>> h2 = 30 + h2;" << endl;
    h2 = 30 + h2;
    cout << "h2 : ";
    h2.Affiche();
    cout << "h (apres) : "; // h ne doit pas etre modifie !!!!
    h.Affiche();
  }

  cout << endl << "********************************************************************" << endl;
  cout <<         "(3) ***** Test de l'operateur (Temps + Temps) **********************" << endl;
  cout <<         "********************************************************************" << endl;
  {
    Temps debut(13,30);
    cout << "debut : ";
    debut.Affiche();
    Temps inter;
    cout << ">>>>> inter = debut + Temps(90);" << endl;
    inter = debut + Temps(90);
    cout << "inter : ";
    inter.Affiche();
    Temps fin;
    cout << ">>>>> fin = inter + Temps(1,20);" << endl;
    fin = inter + Temps(1,20);
    cout << "fin : ";
    fin.Affiche();
  }
}

/*******************************************************************************************************/
/*** Tests de l'operateur - de la classe Temps *********************************************************/
/*******************************************************************************************************/
void Essai3()
{
  cout << endl << "********************************************************************" << endl;
  cout <<         "(1) ***** Test de l'operateur (Temps - int) ************************" << endl;
  cout <<         "********************************************************************" << endl;
  {
    Temps h(16,50);
    cout << "h (avant) : ";
    h.Affiche();
    Temps h2;
    cout << ">>>>> h2 = h - 30;" << endl;
    h2 = h - 30;
    cout << "h2 : ";
    h2.Affiche();
    cout << ">>>>> h2 = h2 - 70;" << endl;
    h2 = h2 - 70;
    cout << "h2 : ";
    h2.Affiche();
    cout << "h (apres) : "; // h ne doit pas etre modifie !!!!
    h.Affiche();
  }

  cout << endl << "********************************************************************" << endl;
  cout <<         "(2) ***** Test de l'operateur (int - Temps) ************************" << endl;
  cout <<         "********************************************************************" << endl;
  {
    Temps d(1,20);
    cout << "d : ";
    d.Affiche();
    Temps duree;
    cout << ">>>>> duree = 120 - d;" << endl;
    duree = 120 - d;
    cout << "duree : ";
    duree.Affiche();
  }

  cout << endl << "********************************************************************" << endl;
  cout <<         "(3) ***** Test de l'operateur (Temps - Temps) **********************" << endl;
  cout <<         "********************************************************************" << endl;
  {
    Temps debut(10,20);
    Temps fin(12,10);
    cout << "debut : ";
    debut.Affiche();
    cout << "fin   : ";
    fin.Affiche();
    Temps duree;
    cout << ">>>>> duree = fin - debut;" << endl;
    duree = fin - debut;
    cout << "duree : ";
    duree.Affiche();
    cout << endl << endl;
  }
}

/*******************************************************************************************************/
/*** Test des operateurs < > == de la classe Temps *****************************************************/
/*******************************************************************************************************/
void Essai4()
{
  cout << "**********************************************************************" << endl;
  cout << "***** Test des operateurs < > == de la classe Temps ******************" << endl;
  cout << "**********************************************************************" << endl;

  Temps h1(9,35);
  cout << "h1 : ";
  h1.Affiche();

  Temps h2(12, 29);
  cout << "h2 : ";
  h2.Affiche();

  cout << "Comparaison des heures : ";
  if (h1 < h2) cout << "h1 < h2" << endl;
  if (h1 > h2) cout << "h1 > h2" << endl;
  if (h1 == h2) cout << "h1 == h2" << endl;
  cout << endl;
}

/*******************************************************************************************************/
/*** Test des operateurs << et >> de la classe Temps ***************************************************/
/*******************************************************************************************************/
void Essai5()
{
  cout << "**********************************************************************" << endl;
  cout << "********* Test des operateurs << et >> de la classe Temps ************" << endl;
  cout << "**********************************************************************" << endl;
  Temps h;
  cout << "Saisissez une heure : ";
  cin >> h;
  cout << endl << "Voici l'heure que vous avez encodee : ";
  h.Affiche();
  cout << endl << endl;
}

/*******************************************************************************************************/
/*** Tests des operateurs de pre/post in(de)crementation de la classe Temps ****************************/
/*******************************************************************************************************/
void Essai6()
{
  cout << "**********************************************************************" << endl;
  cout << "(1) ***** Test de l'operateur de pre-incrementation ******************" << endl;
  cout << "**********************************************************************" << endl;
  Temps h1(8,50);
  cout << "h1   : " << h1 << endl;
  cout << "++h1 : " << ++h1 << endl;  // Si tout va bien, h1 est incremente avant d'etre affiche !
  cout << "h1   : " << h1 << endl << endl;

  cout << "**********************************************************************" << endl;
  cout << "(2) ***** Test de l'operateur de post-incrementation *****************" << endl;
  cout << "**********************************************************************" << endl;
  Temps h2(14,40);
  cout << "h2   : " << h2 << endl;
  cout << "h2++ : " << h2++ << endl;  // Si tout va bien, h2 est incremente apres avoir ete affiche !
  cout << "h2   : " << h2 << endl << endl;

  cout << "**********************************************************************" << endl;
  cout << "(3) ***** Test de l'operateur de pre-decrementation ******************" << endl;
  cout << "**********************************************************************" << endl;
  Temps h3(10,20);
  cout << "h3   : " << h3 << endl;
  cout << "--h3 : " << --h3 << endl;  // Si tout va bien, h3 est decremente avant d'etre affiche !
  cout << "h3   : " << h3 << endl << endl;

  cout << "**********************************************************************" << endl;
  cout << "(4) ***** Test de l'operateur de post-decrementation *****************" << endl;
  cout << "**********************************************************************" << endl;
  Temps h4(17,10);
  cout << "h4   : " << h4 << endl;
  cout << "h4-- : " << h4-- << endl;  // Si tout va bien, h4 est decremente apres avoir ete affiche !
  cout << "h4   : " << h4 << endl << endl;
}

/*******************************************************************************************************/
/*** Test des operateurs < > == de la classe Timing ****************************************************/
/*******************************************************************************************************/
void Essai7()
{
  cout << "**********************************************************************" << endl;
  cout << "********* Test des operateurs < > == de la classe Timing *************" << endl;
  cout << "**********************************************************************" << endl;
  Timing ref(Timing::MERCREDI,Temps(10,0),Temps(2,0));
  cout << "ref : ";
  ref.Affiche();
  cout << endl << endl;

  Timing h1(Timing::VENDREDI,Temps(9,0),Temps(1,0));
  cout << "h1  : ";
  h1.Affiche();
  cout << endl;
  if (h1 < ref) cout << "h1 < ref" << endl;
  if (h1 > ref) cout << "h1 > ref" << endl ;
  if (h1 == ref) cout << "h1 == ref" << endl ;
  cout << endl;

  Timing h2(Timing::MERCREDI,Temps(9,0),Temps(2,0));
  cout << "h2  : ";
  h2.Affiche();
  cout << endl;
  if (h2 < ref) cout << "h2 < ref" << endl;
  if (h2 > ref) cout << "h2 > ref" << endl;
  if (h2 == ref) cout << "h2 == ref" << endl;
  cout << endl;

  Timing h3(Timing::MERCREDI,Temps(10,0),Temps(3,0));
  cout << "h3  : ";
  h3.Affiche();
  cout << endl;
  if (h3 < ref) cout << "h3 < ref" << endl;
  if (h3 > ref) cout << "h3 > ref" << endl;
  if (h3 == ref) cout << "h3 == ref" << endl;
  cout << endl;

  Timing h4(Timing::MERCREDI,Temps(10,0),Temps(2,0));
  cout << "h4  : ";
  h4.Affiche();
  cout << endl;
  if (h4 < ref) cout << "h4 < ref" << endl;
  if (h4 > ref) cout << "h4 > ref" << endl;
  if (h4 == ref) cout << "h4 == ref" << endl;
  cout << endl;
}
