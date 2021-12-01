cmake_minimum_required(VERSION 3.20)
project(Etape_4)

set(CMAKE_CXX_STANDARD 14)

include_directories(Classes)

add_executable(Etape_4
        Classes/Groupe.cpp
        Classes/Groupe.h
        Classes/Local.cpp
        Classes/Local.h
        Classes/Planifiable.cpp
        Classes/Planifiable.h
        Classes/Professeur.cpp
        Classes/Professeur.h
        Test4.cpp)
