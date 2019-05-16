cmake_minimum_required(VERSION 3.13)
project(GladiatorCE2103)

set(CMAKE_CXX_STANDARD 14)

SET(CMAKE_CXX_FLAGS -pthread)

include_directories(. include/rapidjson)
add_executable(GladiatorCE2103 main.cpp estructurasLogicas/ManejadorArchivos.cpp estructurasLogicas/ManejadorArchivos.h estructurasLogicas/ListaEnlazada.cpp estructurasLogicas/ListaEnlazada.h estructurasLogicas/Nodo.cpp estructurasLogicas/Nodo.h estructurasLogicas/Matriz.cpp estructurasLogicas/Matriz.h estructurasLogicas/NodoMatriz.cpp estructurasLogicas/NodoMatriz.h entidades/TorreEnemiga.cpp entidades/TorreEnemiga.h comunicacion/server.cpp comunicacion/server.h comunicacion/transformer.cpp comunicacion/transformer.h logica/Algoritmo.cpp logica/Algoritmo.h logica/AStar.cpp logica/AStar.h Backtraking/Backtraking.cpp Backtraking/Backtraking.h)