COMP = g++

Test1: Test1.cpp Classes/Event.o
	${COMP} Test1.cpp -o Test1 Classes/Event.o

Classes/Event.o: Classes/Event.cpp
	${COMP} Classes/Event.cpp -DDEBUG -c -o Classes/Event.o