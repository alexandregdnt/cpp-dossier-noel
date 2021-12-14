cmake_minimum_required(VERSION 3.20)
project(Etape_6)

set(CMAKE_CXX_STANDARD 14)

include_directories(
        src
        src/Classes
        src/Libraries
)

add_executable(Etape_6
        src/Classes/Event.cpp
        src/Classes/Event.h
        src/Classes/Exception.cpp
        src/Classes/Exception.h
        src/Classes/Groupe.cpp
        src/Classes/Groupe.h
        src/Classes/Iterateur.cpp
        src/Classes/Iterateur.h
        src/Classes/Liste.cpp
        src/Classes/Liste.h
        src/Classes/ListeTriee.cpp
        src/Classes/ListeTriee.h
        src/Classes/Local.cpp
        src/Classes/Local.h
        src/Classes/Planifiable.cpp
        src/Classes/Planifiable.h
        src/Classes/Professeur.cpp
        src/Classes/Professeur.h
        src/Classes/Temps.cpp
        src/Classes/Temps.h
        src/Classes/TempsException.cpp
        src/Classes/TempsException.h
        src/Classes/Timing.cpp
        src/Classes/Timing.h
        src/Classes/TimingException.cpp
        src/Classes/TimingException.h
        src/Libraries/Functions.cpp
        src/Libraries/Functions.h
        src/Test6.cpp)