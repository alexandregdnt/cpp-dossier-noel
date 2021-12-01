cmake_minimum_required(VERSION 3.20)
project(Etape_5)

set(CMAKE_CXX_STANDARD 14)

include_directories(Classes)

add_executable(Etape_5
        Classes/Event.cpp
        Classes/Event.h
        Classes/Exception.cpp
        Classes/Exception.h
        Classes/Temps.cpp
        Classes/Temps.h
        Classes/TempsException.cpp
        Classes/TempsException.h
        Classes/Timing.cpp
        Classes/Timing.h
        Classes/TimingException.cpp
        Classes/TimingException.h
        Functions.cpp
        Functions.h
        Test5.cpp)
