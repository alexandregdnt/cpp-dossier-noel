#include "Horaire.h"

Horaire::Horaire()
{
	#ifdef DEBUG
    cout << "Horaire : constructeur par defaut" << endl;
    #endif

    setProfesseur(ListeTriee<Professeur>());
    setGroupe(ListeTriee<Groupe>());
    setLocal(ListeTriee<Local>());
    setCourss(ListeTriee<Cours>());
}

Horaire::~Horaire()
{
	#ifdef DEBUG
    cout << "Horaire : destructeur" << code << endl;
    #endif

}

ListeTriee<Professeur> Horaire::getProfesseur() const
{
	return professeurs;
}

void Horaire::setProfesseur(ListeTriee<Professeur> p)
{
	professeurs = p;
}

void Horaire::ajouteProfesseur(const char* nom,const char* prenom)
{
	Planifiable::idCourant++;

    Professeur tmp(Planifiable::idCourant, nom, prenom);
    
    professeurs.insere(tmp);
}

void Horaire::afficheProfesseurs()
{
    ListeTriee<Professeur> l(getProfesseur());
    Iterateur<Professeur> it(l);

    for(it.reset(); !it.end(); it++)
        cout << " " << (Professeur)it << endl;
}

void Horaire::supprimeProfesseurParIndice(int ind)
{
    if(professeurs.getNombreElements() > 0)
    {
        professeurs.retire(ind);
    }
}

void Horaire::supprimeProfesseurParId(int id)
{
    ListeTriee<Professeur> l(getProfesseur());
    Iterateur<Professeur> it(l);
    int indice = 0;
    
    it.reset();
    Professeur p = (Professeur)it;
    
    while(!it.end() && p.getId() != id)
    {
        it++;
        indice++;
        if(!it.end())
            p = (Professeur)it;
    }
    
    if(!it.end())
    {
        professeurs.retire(indice);
    }
}

ListeTriee<Groupe> Horaire::getGroupe() const
{
    return groupes;
}

void Horaire::setGroupe(ListeTriee<Groupe> g)
{
    groupes = g;
}

void Horaire::ajouteGroupe(int numero)
{
    Planifiable::idCourant++;

    Groupe tmp(Planifiable::idCourant, numero);
    
    groupes.insere(tmp);
}

void Horaire::afficheGroupes()
{
    ListeTriee<Groupe> l(getGroupe());
    Iterateur<Groupe> it(l);

    for(it.reset(); !it.end(); it++)
        cout << " " << (Groupe)it << endl;
}

void Horaire::supprimeGroupeParIndice(int ind)
{
    if(groupes.getNombreElements() > 0)
    {
        groupes.retire(ind);
    }
}

void Horaire::supprimeGroupeParId(int id)
{
    ListeTriee<Groupe> l(getGroupe());
    Iterateur<Groupe> it(l);
    int indice = 0;

    it.reset();
    Groupe g = (Groupe)it;
    while(!it.end() && g.getId() != id)
    {
        it++;
        indice++;
        if(!it.end())
            g = (Groupe)it;
    }

    if(g.getId() == id)
    {
        groupes.retire(indice);
    }
}

ListeTriee<Local> Horaire::getLocal() const
{
    return locaux;
}

void Horaire::setLocal(ListeTriee<Local> l)
{
    locaux = l;
}

void Horaire::ajouteLocal(const char* nom)
{
    Planifiable::idCourant++;

    Local tmp(Planifiable::idCourant, nom);
    
    locaux.insere(tmp);
}

void Horaire::afficheLocaux()
{
    ListeTriee<Local> l(getLocal());
    Iterateur<Local> it(l);

    for(it.reset(); !it.end(); it++)
        cout << " " << (Local)it << endl;
}

void Horaire::supprimeLocalParIndice(int ind)
{
    if(locaux.getNombreElements() > 0)
    {
        locaux.retire(ind);
    }
}

void Horaire::supprimeLocalParId(int id)
{
    ListeTriee<Local> l(getLocal());
    Iterateur<Local> it(l);
    int indice = 0;

    it.reset();
    Local local = (Local)it;
    while(!it.end() && local.getId() != id)
    {
        it++;
        indice++;
        if(!it.end())
            local = (Local)it;
    }

    if(local.getId() == id)
    {
        locaux.retire(indice);
    }
}
ListeTriee<Cours> Horaire::getCourss() const
{
    return courss;
}

void Horaire::setCourss(ListeTriee<Cours> c)
{
    courss = c;
}

bool Horaire::professeurDisponible(int id,const Timing& timing)
{
    bool resultat = true;
    printf("testprof1\n");
    ListeTriee<Cours> l(getCourss());
    Iterateur<Cours> it(l);
    printf("testprof2\n");
    it.reset();
    printf("testprof2.1\n");
    Cours c = (Cours)it;
    printf("testprof2.2\n");
    while(!it.end() && resultat != false)
    {
        it++;
        printf("testprofx\n");
        if(c.getIdProfesseur() == id)
            resultat = intersecte(c.getTiming(), timing);
        
        if(!it.end())
            c = (Cours)it;
    }
    printf("testprof3\n");
    return resultat;
}

bool Horaire::groupeDisponible(int id,const Timing& timing)
{
    bool resultat = true;

    ListeTriee<Cours> l(getCourss());
    Iterateur<Cours> it(l);
    
    it.reset();
    Cours c = (Cours)it;
    while(!it.end() && resultat != false)
    {
        it++;
        
        if(c.contientIdGroupe(id))
            resultat = intersecte(c.getTiming(), timing);
        
        if(!it.end())
            c = (Cours)it;
    }

    return resultat;
}

bool Horaire::localDisponible(int id,const Timing& timing)
{
    bool resultat = true;

    ListeTriee<Cours> l(getCourss());
    Iterateur<Cours> it(l);
    
    it.reset();
    Cours c = (Cours)it;
    while(!it.end() && resultat != false)
    {
        it++;
        
        if(c.getIdLocal() == id)
            resultat = intersecte(c.getTiming(), timing);
        
        if(!it.end())
            c = (Cours)it;
    }

    return resultat;
}

void Horaire::planifie(Cours& c,const Timing& t)
{
    printf("testplanifie1\n");
    if(!professeurDisponible(c.getIdProfesseur(),t))
    {
        throw(TimingException("Professeur non disponible !", TimingException::AUCUN_TIMING));
    }
    printf("testplanifie2\n");
    if(!localDisponible(c.getIdLocal(),t))
    {
        throw(TimingException("Local non disponible !", TimingException::AUCUN_TIMING));
    }
    printf("testplanifie3\n");
    Liste<int> l(c.idGroupes);
    Iterateur<int> it(l);
    it.reset();
    int id = (int)it;
    printf("testplanifie4\n");
    while(!it.end())
    {
        if(!groupeDisponible(id, t))
        {
            throw(TimingException("Groupe non disponible !", TimingException::AUCUN_TIMING));
        }
        it++;
    }
    printf("testplanifie5\n");
    c.setTiming(t);

    Planifiable::idCourant++;
    printf("testplanifie6\n");
    Cours tmp(Planifiable::idCourant, c.getIntitule(), c.getTiming(), c.getIdProfesseur(), c.getIdLocal(), c.idGroupes);
    
    courss.insere(tmp);
    printf("testplanifie7\n");
}

bool Horaire::intersecte(const Timing& t1, const Timing& t2)
{
    bool resultat = true;

    if(strcmp(t1.getJour(), t2.getJour()) == 0)
    {
        if((t1.getHeure() + t1.getDuree()) < t2.getHeure() || (t2.getHeure() + t2.getDuree()) < t1.getHeure())
            resultat = false;
    }
    else
    {
        resultat = false;
    }
    
    return resultat;
}

void Horaire::supprimeCoursParCode(int code)
{
    ListeTriee<Cours> l(getCourss());
    Iterateur<Cours> it(l);
    int indice = 0;

    it.reset();
    Cours c = (Cours)it;
    while(!it.end() && c.getCode() != code)
    {
        it++;
        indice++;
        if(!it.end())
            c = (Cours)it;
    }

    if(c.getCode() == code)
    {
        courss.retire(indice);
    }
}

const char* Horaire::getTuple(const Cours& c)
{
    char jour[20];
    char heure[10];
    char duree[10];
    char local[10];
    char prof[50];
    char groupes[100];

    sprintf(jour, "%s", c.getTiming().getJour());
    sprintf(heure, "%dh%d", c.getTiming().getHeure().getHeure(), c.getTiming().getHeure().getMinute());
    sprintf(duree, "%dh%d", c.getTiming().getDuree().getHeure(), c.getTiming().getDuree().getMinute());

    ListeTriee<Professeur> l(getProfesseur());
    Iterateur<Professeur> it(l);
    it.reset();
    Professeur p = (Professeur)it;
    while(!it.end() && p.getId() != c.getIdProfesseur())
    {
        it++;
        if(!it.end())
            p = (Professeur)it;
    }
    if(p.getId() == c.getIdProfesseur())
    {
        sprintf(prof, "%s %s", p.getNom(), p.getPrenom());
    }
    else
    {
        sprintf(prof, "//");
    }

    ListeTriee<Local> l1(getLocal());
    Iterateur<Local> it1(l1);
    it1.reset();
    Local lo = (Local)it1;
    while(!it1.end() && lo.getId() != c.getIdLocal())
    {
        it1++;
        if(!it1.end())
            lo = (Local)it1;
    }
    if(lo.getId() == c.getIdLocal())
    {
        sprintf(local, "%s", lo.getNom());
    }
    else
    {
        sprintf(local, "//");
    }

    Liste<int> l2(c.idGroupes);
    Iterateur<int> it2(l2);
    it2.reset();
    int g = (int)it2;
    char tmp[10];
    while(!it2.end())
    {
        sprintf(tmp, "G%d", g);
        strcat(groupes, tmp);
        g = (int)it2;
        it2++;
    }

    sprintf(tuple, "%d;%s;%s;%s;%s;%s;%s;%s", c.getCode(), jour, heure, duree, local, c.getIntitule(), prof, groupes);

    return tuple;
}












