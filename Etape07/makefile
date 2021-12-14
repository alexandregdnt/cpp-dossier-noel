.SILENT:

GPP = g++ -Wall 
CLASSES = Classes
OBJS = $(CLASSES)/Event.o $(CLASSES)/Temps.o $(CLASSES)/Timing.o $(CLASSES)/Planifiable.o $(CLASSES)/Professeur.o $(CLASSES)/Groupe.o $(CLASSES)/Local.o $(CLASSES)/Exception.o $(CLASSES)/TempsException.o $(CLASSES)/TimingException.o $(CLASSES)/Liste.o $(CLASSES)/ListeTriee.o $(CLASSES)/Iterateur.o
PROGRAMS = Test7

Test7:	Test7.cpp $(CLASSES)/Event.o $(CLASSES)/Temps.o $(CLASSES)/Timing.o $(CLASSES)/Planifiable.o $(CLASSES)/Professeur.o $(CLASSES)/Groupe.o $(CLASSES)/Local.o $(CLASSES)/Exception.o $(CLASSES)/TempsException.o $(CLASSES)/TimingException.o $(CLASSES)/Liste.o $(CLASSES)/ListeTriee.o $(CLASSES)/Iterateur.o
	$(GPP) -I $(CLASSES) -o Test7 Test7.cpp $(CLASSES)/Event.o $(CLASSES)/Temps.o $(CLASSES)/Timing.o $(CLASSES)/Planifiable.o $(CLASSES)/Professeur.o $(CLASSES)/Groupe.o $(CLASSES)/Local.o $(CLASSES)/Exception.o $(CLASSES)/TempsException.o $(CLASSES)/TimingException.o $(CLASSES)/Liste.o $(CLASSES)/ListeTriee.o $(CLASSES)/Iterateur.o

$(CLASSES)/Event.o:	$(CLASSES)/Event.cpp 
	$(GPP) -I $(CLASSES) -o $(CLASSES)/Event.o $(CLASSES)/Event.cpp -c

$(CLASSES)/Temps.o:	$(CLASSES)/Temps.cpp 
	$(GPP) -I $(CLASSES) -o $(CLASSES)/Temps.o $(CLASSES)/Temps.cpp -c

$(CLASSES)/Timing.o:	$(CLASSES)/Timing.cpp 
	$(GPP) -I $(CLASSES) -o $(CLASSES)/Timing.o $(CLASSES)/Timing.cpp -c

$(CLASSES)/Planifiable.o:	$(CLASSES)/Planifiable.cpp
	$(GPP) -I $(CLASSES) -o $(CLASSES)/Planifiable.o $(CLASSES)/Planifiable.cpp -c

$(CLASSES)/Professeur.o:	$(CLASSES)/Professeur.cpp
	$(GPP) -I $(CLASSES) -o $(CLASSES)/Professeur.o $(CLASSES)/Professeur.cpp -c

$(CLASSES)/Groupe.o:	$(CLASSES)/Groupe.cpp
	$(GPP) -I $(CLASSES) -o $(CLASSES)/Groupe.o $(CLASSES)/Groupe.cpp -c

$(CLASSES)/Local.o:	$(CLASSES)/Local.cpp
	$(GPP) -I $(CLASSES) -o $(CLASSES)/Local.o $(CLASSES)/Local.cpp -c

$(CLASSES)/Exception.o:	$(CLASSES)/Exception.cpp
	$(GPP) -I $(CLASSES) -o $(CLASSES)/Exception.o $(CLASSES)/Exception.cpp -c

$(CLASSES)/TempsException.o:	$(CLASSES)/TempsException.cpp
	$(GPP) -I $(CLASSES) -o $(CLASSES)/TempsException.o $(CLASSES)/TempsException.cpp -c

$(CLASSES)/TimingException.o:	$(CLASSES)/TimingException.cpp
	$(GPP) -I $(CLASSES) -o $(CLASSES)/TimingException.o $(CLASSES)/TimingException.cpp -c

$(CLASSES)/Liste.o:	$(CLASSES)/Liste.cpp
	$(GPP) -I $(CLASSES) -o $(CLASSES)/Liste.o $(CLASSES)/Liste.cpp -c

$(CLASSES)/ListeTriee.o:	$(CLASSES)/ListeTriee.cpp
	$(GPP) -I $(CLASSES) -o $(CLASSES)/ListeTriee.o $(CLASSES)/ListeTriee.cpp -c

$(CLASSES)/Iterateur.o:	$(CLASSES)/Iterateur.cpp
	$(GPP) -I $(CLASSES) -o $(CLASSES)/Iterateur.o $(CLASSES)/Iterateur.cpp -c



clean:	
	rm -f $(OBJS) core
clobber:	clean
	rm -f $(PROGRAMS)

