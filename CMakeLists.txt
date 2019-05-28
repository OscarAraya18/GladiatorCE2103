cmake_minimum_required(VERSION 3.13)
project(GladiatorCE2103)

set(CMAKE_CXX_STANDARD 14)

SET(CMAKE_CXX_FLAGS -pthread)

include_directories(. include/rapidjson)

add_subdirectory(lib/googletest-master)

include_directories(lib/googletest-master/googletest/include)

include_directories(lib/googletest-master/googlemock/include)

add_executable(GladiatorCE2103 main.cpp estructurasLogicas/ManejadorArchivos.cpp estructurasLogicas/ManejadorArchivos.h estructurasLogicas/ListaEnlazada.cpp estructurasLogicas/ListaEnlazada.h estructurasLogicas/Nodo.cpp estructurasLogicas/Nodo.h estructurasLogicas/Matriz.cpp estructurasLogicas/Matriz.h estructurasLogicas/NodoMatriz.cpp estructurasLogicas/NodoMatriz.h entidades/TorreEnemiga.cpp entidades/TorreEnemiga.h comunicacion/server.cpp comunicacion/server.h comunicacion/transformer.cpp comunicacion/transformer.h logica/Algoritmo.cpp logica/Algoritmo.h logica/AStar.cpp logica/AStar.h Backtraking/Backtraking.cpp Backtraking/Backtraking.h Tests/BacktrackingTest.cpp Tests/aStarTest.cpp Tests/GeneticoTest.cpp Tests/matrizTest.cpp)

target_link_libraries(GladiatorCE2103 gtest gtest_main)
