.SILENT:
COMP = g++

Test5: Test5.cpp Classes/Event.o Classes/Temps.o Classes/Timing.o Classes/Exception.o Classes/TempsException.o Classes/TimingException.o Functions.o
	echo Creation Test5
	${COMP} Test5.cpp -o Test5 Classes/Event.o Classes/Temps.o Classes/Timing.o Classes/Exception.o Classes/TempsException.o Classes/TimingException.o Functions.o

Classes/Event.o: Classes/Event.cpp
	echo Creation Event.o
	${COMP} Classes/Event.cpp -c -o Classes/Event.o

Classes/Temps.o: Classes/Temps.cpp
	echo Creation Temps.o
	${COMP} Classes/Temps.cpp -c -o Classes/Temps.o

Classes/Timing.o: Classes/Timing.cpp
	echo Creation Timing.o
	${COMP} Classes/Timing.cpp -c -o Classes/Timing.o

Classes/Exception.o: Classes/Exception.cpp
	echo Creation Exception.o
	${COMP} Classes/Exception.cpp -c -o Classes/Exception.o

Classes/TempsException.o: Classes/TempsException.cpp
	echo Creation TempsException.o
	${COMP} Classes/TempsException.cpp -c -o Classes/TempsException.o

Classes/TimingException.o: Classes/TimingException.cpp
	echo Creation TimingException.o
	${COMP} Classes/TimingException.cpp -c -o Classes/TimingException.o

Functions.o: Functions.cpp
	echo Creation Functions.o
	${COMP} Functions.cpp -c -o Functions.o