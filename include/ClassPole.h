// Copyright 2018 Your Name <your_email>
#pragma once
#ifndef INCLUDE_CLASSPOLE_HPP_
#define INCLUDE_CLASSPOLE_HPP_

#include <iostream>
#include <iomanip>
#include <vector>
#include <random>

class Pole{
public:
    std::vector<std::vector<int>> pole;
    int shots[10][10];
    int AdrKor[5][10];
    extern Pole();
    explicit Pole(std::vector<std::vector<int>> m);
    extern void clear();
    extern void print();
};


extern void kill_or_not(Pole& m, Pole& n);

//#include "ClassPole.cpp"

#endif // INCLUDE_CLASSPOLE_HPP_
