 #include "Event.h"

 int Event::codeCourant = 0;

	Event::Event()
  {
    #ifdef DEBUG
    cout << "Event : constructeur par defaut" << endl;
    #endif
    
    code = -1;
    intitule = NULL;
    timing = NULL;

    codeCourant++;
  }

  Event::Event(int c, const char* i, Timing t)
  {
    #ifdef DEBUG
    cout << "Event : constructeur d'initialisation complet" << endl;
    #endif
    
    setCode(c);
    
    intitule = NULL;
    setIntitule(i);

    timing = NULL;
    setTiming(t);

    codeCourant++;
  }

  Event::Event(int c, const char* i)
  {
    #ifdef DEBUG
    cout << "Event : constructeur d'initialisation partiel" << endl;
    #endif
    
    setCode(c);
    
    intitule = NULL;
    setIntitule(i);

    timing = NULL;

    codeCourant++;
  }

  Event::Event(Event& e)
  {
    #ifdef DEBUG
    cout << "Event : constructeur de copie" << endl;
    #endif

    setCode(e.getCode());
    
    intitule = NULL;
    setIntitule(e.getIntitule());
    
    timing = NULL;
    setTiming(e.getTiming());

    codeCourant++;
  }
    
  Event::~Event()
  {
    #ifdef DEBUG
    cout << "Event : destructeur" << code << endl;
    #endif

    if(intitule)
      delete intitule;
    if(timing)
      delete timing;

    codeCourant--;
  }

  int Event::getCode() const
  {
    return code;
  }

  const char* Event::getIntitule() const
  {
    return intitule;
  }

  Timing Event::getTiming() const
  {
    if(!timing)
      throw(TimingException("L'événement n’a pas été planifié !", TimingException::AUCUN_TIMING));
    return Timing(*timing);
  }

  void Event::setCode(int c)
  {
    if(c < 1)
      return;
    code = c; 
  }

  void Event::setIntitule(const char* i)
  {
    if(i == NULL)
      return;
    if(intitule)
      delete intitule;
    intitule = new char[strlen(i) + 1];
    strcpy(intitule, i);
  }

  void Event::setTiming(const Timing& t)
  {
    if(timing)
      delete timing;
    timing = new Timing(t);
  }

  void Event::Affiche() const
  {
    cout << "Event : code " << code << " , intitule : ";
    if(intitule)
      cout << intitule << endl;
    else
      cout << "/" << endl;
    cout << "Timing : ";
    if(timing) 
      timing->Affiche();
    else 
      cout << "/" << endl;
  }

  void Event::Save(ofstream& fichier) const
  {
    if(fichier.is_open())
    {
      int code = getCode();

      char *inti = new char[strlen(getIntitule()) + 1];
      strcpy(inti, getIntitule());
      int taille = strlen(inti);

      Timing t = getTiming();

      fichier.write((char *)&code, sizeof(int));
      fichier.write((char *)&taille, sizeof(int));
      fichier.write((char *)inti, taille);

      t.Save(fichier);

      if(inti)
        delete inti;
    }  
  }

  void Event::Load(ifstream& fichier)
  {
    if(fichier.is_open())
    {
      int code, taille;
      Timing t;

      fichier.read((char *)&code, sizeof(int));
    
      fichier.read((char *)&taille, sizeof(int));
      char *inti = new char[taille + 1];
      fichier.read((char *)inti, taille);

      t.Load(fichier);

      setCode(code);
      setIntitule(inti);
      setTiming(t);

      if(inti)
        delete inti;
    }
    
  }

