#include <stdlib.h>
#include <iostream>
using namespace std;

#include "Horaire.h"

int main()
{
  // Creation du dessin
  Horaire h;
  
  // Ajout de professeurs
  h.ajouteProfesseur("Wagner","Jean-Marc");   // id = 1
  h.ajouteProfesseur("Quettier","Patrick");   // id = 2
  h.ajouteProfesseur("Leonard","Anne");       // id = 3
  h.ajouteProfesseur("Vilvens","Claude");     // id = 4

  // Ajout de groupes
  h.ajouteGroupe(2201);                       // id = 5
  h.ajouteGroupe(2221);                       // id = 6
  h.ajouteGroupe(2225);                       // id = 7
  h.ajouteGroupe(2202);                       // id = 8
  h.ajouteGroupe(2226);                       // id = 9

  // Ajout de locaux
  h.ajouteLocal("LP01");                      // id = 10
  h.ajouteLocal("AN");                        // id = 11
  h.ajouteLocal("PV12");                      // id = 12
  h.ajouteLocal("PV11");                      // id = 13
  h.ajouteLocal("LE0");                       // id = 14

  // Affichage
  cout << "////////// Avant ///////////////////////////////////////////////////////////////////////" << endl;
  h.afficheProfesseurs();
  h.afficheGroupes();
  h.afficheLocaux();

  // Suppression par indice
  h.supprimeProfesseurParIndice(1);
  h.supprimeGroupeParIndice(1);
  h.supprimeLocalParIndice(1);

  // Affichage
  cout << "////////// Apres suppression par indice (1) ////////////////////////////////////////////" << endl;
  h.afficheProfesseurs();
  h.afficheGroupes();
  h.afficheLocaux();

  // Suppression par id
  h.supprimeProfesseurParId(4);
  h.supprimeGroupeParId(7);
  h.supprimeLocalParId(11);

  // Affichage
  cout << "////////// Apres suppression par id ////////////////////////////////////////////////////" << endl;
  h.afficheProfesseurs();
  h.afficheGroupes();
  h.afficheLocaux();

  return 0;
}

