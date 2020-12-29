cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(buttlelib)

add_library(buttle STATIC ClassPole.cpp SeaButtle.cpp)