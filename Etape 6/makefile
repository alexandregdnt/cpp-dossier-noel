.SILENT:
COMP = g++ -DDEBUG

all: createBuild Test6

createBuild:
	echo "Creation du répertoire build"
	rm -rf build
	mkdir build
	mkdir build/Classes
	mkdir build/Libraries

Test6: src/Test6.cpp Classes/Event.o Classes/Temps.o Classes/Timing.o Classes/Exception.o Classes/TempsException.o Classes/TimingException.o Classes/Planifiable.o Classes/Professeur.o Classes/Groupe.o Classes/Local.o Classes/Liste.o Classes/ListeTriee.o Classes/Iterateur.o Libraries/Functions.o
	echo "Creation Test6"
	${COMP} src/Test6.cpp -o build/Test6 build/Classes/Liste.o build/Classes/Event.o build/Classes/Temps.o build/Classes/Timing.o build/Classes/Exception.o build/Classes/TempsException.o build/Classes/TimingException.o build/Classes/Planifiable.o build/Classes/Professeur.o build/Classes/Groupe.o build/Classes/Local.o build/Classes/Liste.o build/Classes/ListeTriee.o build/Classes/Iterateur.o build/Libraries/Functions.o

Classes/Event.o: src/Classes/Event.cpp
	echo "Creation Event.o"
	${COMP} src/Classes/Event.cpp -c -o build/Classes/Event.o

Classes/Temps.o: src/Classes/Temps.cpp
	echo "Creation Temps.o"
	${COMP} src/Classes/Temps.cpp -c -o build/Classes/Temps.o

Classes/Timing.o: src/Classes/Timing.cpp
	echo "Creation Timing.o"
	${COMP} src/Classes/Timing.cpp -c -o build/Classes/Timing.o

Classes/Exception.o: src/Classes/Exception.cpp
	echo "Creation Exception.o"
	${COMP} src/Classes/Exception.cpp -c -o build/Classes/Exception.o

Classes/TempsException.o: src/Classes/TempsException.cpp
	echo "Creation TempsException.o"
	${COMP} src/Classes/TempsException.cpp -c -o build/Classes/TempsException.o

Classes/TimingException.o: src/Classes/TimingException.cpp
	echo "Creation TimingException.o"
	${COMP} src/Classes/TimingException.cpp -c -o build/Classes/TimingException.o

Classes/Planifiable.o: src/Classes/Planifiable.cpp
	echo "Creation Planifiable.o"
	${COMP} src/Classes/Planifiable.cpp -c -o build/Classes/Planifiable.o

Classes/Professeur.o: src/Classes/Professeur.cpp
	echo "Creation Professeur.o"
	${COMP} src/Classes/Professeur.cpp -c -o build/Classes/Professeur.o

Classes/Groupe.o: src/Classes/Groupe.cpp
	echo "Creation Groupe.o"
	${COMP} src/Classes/Groupe.cpp -c -o build/Classes/Groupe.o

Classes/Local.o: src/Classes/Local.cpp
	echo "Creation Local.o"
	${COMP} src/Classes/Local.cpp -c -o build/Classes/Local.o

Classes/Liste.o: src/Classes/Liste.cpp
	echo "Creation Liste.o"
	${COMP} src/Classes/Liste.cpp -c -o build/Classes/Liste.o

Classes/ListeTriee.o: src/Classes/ListeTriee.cpp
	echo "Creation ListeTriee.o"
	${COMP} src/Classes/ListeTriee.cpp -c -o build/Classes/ListeTriee.o

Classes/Iterateur.o: src/Classes/Iterateur.cpp
	echo "Creation Iterateur.o"
	${COMP} src/Classes/Iterateur.cpp -c -o build/Classes/Iterateur.o

Libraries/Functions.o: src/Libraries/Functions.cpp
	echo "Creation Functions.o"
	${COMP} src/Libraries/Functions.cpp -c -o build/Libraries/Functions.o

clear:
	echo "Suppression des fichiers compilés"
	rm -rf build
