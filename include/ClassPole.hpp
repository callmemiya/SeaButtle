// Copyright 2018 Your Name <your_email>
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
    Pole();
    Pole(std::vector<std::vector<int>> m);
    void clear();
    void print();
};

#endif // INCLUDE_CLASSPOLE_HPP_
