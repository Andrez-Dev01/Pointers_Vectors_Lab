cmake_minimum_required(VERSION 4.1)
project(Pointers)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pointers main.cpp
        Inventory.cpp
        Book.cpp)
