.SILENT:

GPP = g++ -Wall 
CLASSES = Classes
OBJS = *.o $(CLASSES)/*.o
PROGRAMS = ApplicHoraire

ApplicHoraire:	$(CLASSES)/Event.o $(CLASSES)/Temps.o $(CLASSES)/Timing.o $(CLASSES)/Planifiable.o $(CLASSES)/Professeur.o $(CLASSES)/Groupe.o $(CLASSES)/Local.o $(CLASSES)/Exception.o $(CLASSES)/TempsException.o $(CLASSES)/TimingException.o $(CLASSES)/Liste.o $(CLASSES)/ListeTriee.o $(CLASSES)/Iterateur.o $(CLASSES)/Cours.o $(CLASSES)/Horaire.o main.o applichorairewindow.o moc_applichorairewindow.o
		echo Creation de ApplicHoraire
		g++ -Wl,-O1 -o ApplicHoraire $(CLASSES)/Event.o $(CLASSES)/Temps.o $(CLASSES)/Timing.o $(CLASSES)/Planifiable.o $(CLASSES)/Professeur.o $(CLASSES)/Groupe.o $(CLASSES)/Local.o $(CLASSES)/Exception.o $(CLASSES)/TempsException.o $(CLASSES)/TimingException.o $(CLASSES)/Liste.o $(CLASSES)/ListeTriee.o $(CLASSES)/Iterateur.o $(CLASSES)/Cours.o $(CLASSES)/Horaire.o main.o applichorairewindow.o moc_applichorairewindow.o   /usr/lib64/libQt5Widgets.so /usr/lib64/libQt5Gui.so /usr/lib64/libQt5Core.so /usr/lib64/libGL.so -lpthread 

main.o:	main.cpp 
		echo Creation de main.o
		g++ -c -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -o main.o main.cpp

applichorairewindow.o:	applichorairewindow.cpp applichorairewindow.h ui_applichorairewindow.h
		echo Creation de applichorairewindow.o
		g++ -c -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -o applichorairewindow.o applichorairewindow.cpp

moc_applichorairewindow.o:	moc_applichorairewindow.cpp applichorairewindow.h
		echo Creation de moc_applichorairewindow.o
		g++ -c -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -o moc_applichorairewindow.o moc_applichorairewindow.cpp





$(CLASSES)/Event.o:	$(CLASSES)/Event.cpp $(CLASSES)/Event.h
	$(GPP) -I $(CLASSES) -o $(CLASSES)/Event.o $(CLASSES)/Event.cpp -c

$(CLASSES)/Temps.o:	$(CLASSES)/Temps.cpp $(CLASSES)/Temps.h
	$(GPP) -I $(CLASSES) -o $(CLASSES)/Temps.o $(CLASSES)/Temps.cpp -c

$(CLASSES)/Timing.o:	$(CLASSES)/Timing.cpp $(CLASSES)/Timing.h
	$(GPP) -I $(CLASSES) -o $(CLASSES)/Timing.o $(CLASSES)/Timing.cpp -c

$(CLASSES)/Planifiable.o:	$(CLASSES)/Planifiable.cpp $(CLASSES)/Planifiable.h
	$(GPP) -I $(CLASSES) -o $(CLASSES)/Planifiable.o $(CLASSES)/Planifiable.cpp -c

$(CLASSES)/Professeur.o:	$(CLASSES)/Professeur.cpp $(CLASSES)/Professeur.h
	$(GPP) -I $(CLASSES) -o $(CLASSES)/Professeur.o $(CLASSES)/Professeur.cpp -c

$(CLASSES)/Groupe.o:	$(CLASSES)/Groupe.cpp $(CLASSES)/Groupe.h
	$(GPP) -I $(CLASSES) -o $(CLASSES)/Groupe.o $(CLASSES)/Groupe.cpp -c

$(CLASSES)/Local.o:	$(CLASSES)/Local.cpp $(CLASSES)/Local.h
	$(GPP) -I $(CLASSES) -o $(CLASSES)/Local.o $(CLASSES)/Local.cpp -c

$(CLASSES)/Exception.o:	$(CLASSES)/Exception.cpp $(CLASSES)/Exception.h
	$(GPP) -I $(CLASSES) -o $(CLASSES)/Exception.o $(CLASSES)/Exception.cpp -c

$(CLASSES)/TempsException.o:	$(CLASSES)/TempsException.cpp $(CLASSES)/TempsException.h
	$(GPP) -I $(CLASSES) -o $(CLASSES)/TempsException.o $(CLASSES)/TempsException.cpp -c

$(CLASSES)/TimingException.o:	$(CLASSES)/TimingException.cpp $(CLASSES)/TimingException.h
	$(GPP) -I $(CLASSES) -o $(CLASSES)/TimingException.o $(CLASSES)/TimingException.cpp -c

$(CLASSES)/Liste.o:	$(CLASSES)/Liste.cpp $(CLASSES)/Liste.h
	$(GPP) -I $(CLASSES) -o $(CLASSES)/Liste.o $(CLASSES)/Liste.cpp -c

$(CLASSES)/ListeTriee.o:	$(CLASSES)/ListeTriee.cpp $(CLASSES)/ListeTriee.h
	$(GPP) -I $(CLASSES) -o $(CLASSES)/ListeTriee.o $(CLASSES)/ListeTriee.cpp -c

$(CLASSES)/Iterateur.o:	$(CLASSES)/Iterateur.cpp $(CLASSES)/Iterateur.h
	$(GPP) -I $(CLASSES) -o $(CLASSES)/Iterateur.o $(CLASSES)/Iterateur.cpp -c

$(CLASSES)/Cours.o:	$(CLASSES)/Cours.cpp $(CLASSES)/Cours.h
	$(GPP) -I $(CLASSES) -o $(CLASSES)/Cours.o $(CLASSES)/Cours.cpp -c

$(CLASSES)/Horaire.o:	$(CLASSES)/Horaire.cpp $(CLASSES)/Horaire.h
	$(GPP) -I $(CLASSES) -o $(CLASSES)/Horaire.o $(CLASSES)/Horaire.cpp -c

clean:	
	rm -f $(OBJS) core
clobber:	clean
	rm -f $(PROGRAMS)

