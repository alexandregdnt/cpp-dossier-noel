#ifndef HORAIRE
#define HORAIRE

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Timing.h"
#include"TempsException.h"
#include"TimingException.h"
#include "Planifiable.h"
#include "Professeur.h"
#include "Groupe.h"
#include "Local.h"
#include "Liste.h"
#include "ListeTriee.h"
#include "Iterateur.h"
#include "Cours.h"
using namespace std;

class Horaire 
{ 
  private : 
    ListeTriee<Professeur> professeurs; 
    ListeTriee<Groupe>     groupes; 
    ListeTriee<Local>      locaux;
    ListeTriee<Cours>      courss;

    char tuple[400]; 
 
  public: 
    Horaire(); 
    ~Horaire(); 
 
    ListeTriee<Professeur> getProfesseur() const;
    void setProfesseur(ListeTriee<Professeur> p);
    void ajouteProfesseur(const char* nom,const char* prenom); 
    void afficheProfesseurs(); 
    void supprimeProfesseurParIndice(int ind); 
    void supprimeProfesseurParId(int id); 
    
    ListeTriee<Groupe> getGroupe() const;
    void setGroupe(ListeTriee<Groupe> g);
    void ajouteGroupe(int numero); 
    void afficheGroupes(); 
    void supprimeGroupeParIndice(int ind); 
    void supprimeGroupeParId(int id); 
    
    ListeTriee<Local> getLocal() const;
    void setLocal(ListeTriee<Local> l);
    void ajouteLocal(const char* nom); 
    void afficheLocaux(); 
    void supprimeLocalParIndice(int ind); 
    void supprimeLocalParId(int id);

    ListeTriee<Cours> getCourss() const;
    void setCourss(ListeTriee<Cours> c);
    bool professeurDisponible(int id,const Timing& timing); 
    bool groupeDisponible(int  id,const  Timing&  timing);
    bool localDisponible(int id,const Timing& timing);
    void planifie(Cours& c,const Timing& t);
    bool intersecte(const Timing& t1, const Timing& t2);
    void supprimeCoursParCode(int code);
    const char* getTuple(const Cours& c);
};

#endif