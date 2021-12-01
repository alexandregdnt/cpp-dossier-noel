cmake_minimum_required(VERSION 3.20)
project(Etape_6)

set(CMAKE_CXX_STANDARD 14)

include_directories(
        Classes
        Libraries
)

add_executable(Etape_6
        Classes/Event.cpp
        Classes/Event.h
        Classes/Exception.cpp
        Classes/Exception.h
        Classes/Groupe.cpp
        Classes/Groupe.h
        Classes/Iterateur.cpp
        Classes/Iterateur.h
        Classes/Liste.cpp
        Classes/Liste.h
        Classes/ListeTriee.cpp
        Classes/ListeTriee.h
        Classes/Local.cpp
        Classes/Local.h
        Classes/Planifiable.cpp
        Classes/Planifiable.h
        Classes/Professeur.cpp
        Classes/Professeur.h
        Classes/Temps.cpp
        Classes/Temps.h
        Classes/TempsException.cpp
        Classes/TempsException.h
        Classes/Timing.cpp
        Classes/Timing.h
        Classes/TimingException.cpp
        Classes/TimingException.h
        Libraries/Functions.cpp
        Libraries/Functions.h
        Test6.cpp)