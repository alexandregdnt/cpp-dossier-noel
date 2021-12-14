.SILENT:
COMP = g++

Test3: Test3.cpp Classes/Event.o Classes/Temps.o Classes/Timing.o
	${COMP} Test3.cpp -o Test3 Classes/Event.o Classes/Temps.o Classes/Timing.o

Classes/Event.o: Classes/Event.cpp
	${COMP} Classes/Event.cpp -c -o Classes/Event.o

Classes/Temps.o: Classes/Temps.cpp
	${COMP} Classes/Temps.cpp -c -o Classes/Temps.o

Classes/Timing.o: Classes/Timing.cpp
	${COMP} Classes/Timing.cpp -c -o Classes/Timing.o