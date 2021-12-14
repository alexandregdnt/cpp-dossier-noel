.SILENT:
COMP = g++ -DDEBUG

Test4: Test4.cpp Classes/Planifiable.o Classes/Professeur.o Classes/Groupe.o Classes/Local.o
	${COMP} Test4.cpp -o Test4 Classes/Planifiable.o Classes/Professeur.o Classes/Groupe.o Classes/Local.o

Classes/Planifiable.o: Classes/Planifiable.cpp
	${COMP} Classes/Planifiable.cpp -c -o Classes/Planifiable.o

Classes/Professeur.o: Classes/Professeur.cpp
	${COMP} Classes/Professeur.cpp -c -o Classes/Professeur.o

Classes/Groupe.o: Classes/Groupe.cpp
	${COMP} Classes/Groupe.cpp -c -o Classes/Groupe.o

Classes/Local.o: Classes/Local.cpp
	${COMP} Classes/Local.cpp -c -o Classes/Local.o