.SILENT:
COMP = g++ -DDEBUG

all: Test6

Test6: Test6.cpp Classes/Event.o Classes/Temps.o Classes/Timing.o Classes/Exception.o Classes/TempsException.o Classes/TimingException.o Classes/Planifiable.o Classes/Professeur.o Classes/Groupe.o Classes/Local.o Classes/Liste.o Classes/ListeTriee.o Classes/Iterateur.o Libraries/Functions.o
	echo "Creation Test6"
	${COMP} Test6.cpp -o Test6 Classes/Liste.o Classes/Event.o Classes/Temps.o Classes/Timing.o Classes/Exception.o Classes/TempsException.o Classes/TimingException.o Classes/Planifiable.o Classes/Professeur.o Classes/Groupe.o Classes/Local.o Classes/Liste.o Classes/ListeTriee.o Classes/Iterateur.o Libraries/Functions.o

Classes/Event.o: Classes/Event.cpp
	echo "Creation Event.o"
	${COMP} Classes/Event.cpp -c -o Classes/Event.o

Classes/Temps.o: Classes/Temps.cpp
	echo "Creation Temps.o"
	${COMP} Classes/Temps.cpp -c -o Classes/Temps.o

Classes/Timing.o: Classes/Timing.cpp
	echo "Creation Timing.o"
	${COMP} Classes/Timing.cpp -c -o Classes/Timing.o

Classes/Exception.o: Classes/Exception.cpp
	echo "Creation Exception.o"
	${COMP} Classes/Exception.cpp -c -o Classes/Exception.o

Classes/TempsException.o: Classes/TempsException.cpp
	echo "Creation TempsException.o"
	${COMP} Classes/TempsException.cpp -c -o Classes/TempsException.o

Classes/TimingException.o: Classes/TimingException.cpp
	echo "Creation TimingException.o"
	${COMP} Classes/TimingException.cpp -c -o Classes/TimingException.o

Classes/Planifiable.o: Classes/Planifiable.cpp
	echo "Creation Planifiable.o"
	${COMP} Classes/Planifiable.cpp -c -o Classes/Planifiable.o

Classes/Professeur.o: Classes/Professeur.cpp
	echo "Creation Professeur.o"
	${COMP} Classes/Professeur.cpp -c -o Classes/Professeur.o

Classes/Groupe.o: Classes/Groupe.cpp
	echo "Creation Groupe.o"
	${COMP} Classes/Groupe.cpp -c -o Classes/Groupe.o

Classes/Local.o: Classes/Local.cpp
	echo "Creation Local.o"
	${COMP} Classes/Local.cpp -c -o Classes/Local.o

Classes/Liste.o: Classes/Liste.cpp
	echo "Creation Liste.o"
	${COMP} Classes/Liste.cpp -c -o Classes/Liste.o

Classes/ListeTriee.o: Classes/ListeTriee.cpp
	echo "Creation ListeTriee.o"
	${COMP} Classes/ListeTriee.cpp -c -o Classes/ListeTriee.o

Classes/Iterateur.o: Classes/Iterateur.cpp
	echo "Creation Iterateur.o"
	${COMP} Classes/Iterateur.cpp -c -o Classes/Iterateur.o

Libraries/Functions.o: Libraries/Functions.cpp
	echo "Creation Functions.o"
	${COMP} Libraries/Functions.cpp -c -o Libraries/Functions.o

clear:
	echo "Suppression des fichiers compilés"
	rm -f Test6 *.o Classes/*.o Libraries/*.o
