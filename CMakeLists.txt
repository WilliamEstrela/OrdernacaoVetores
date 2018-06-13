cmake_minimum_required(VERSION 3.10)
project(ordenacao)

set(CMAKE_CXX_STANDARD 11)

add_executable(ordenacao
        BoubleSort/treinando/bolha.cpp
        BoubleSort/BoubleSort.cpp
        BoubleSortPlus/BoubleSortPlus.cpp
        Quick/Quick.cpp
        SelectionSort/Selection.cpp
        SelectionSort/SelectionTeste.cpp)
