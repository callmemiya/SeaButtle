#ifndef ClassPole_hpp
#define ClassPole_hpp

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

#endif /* ClassPole_hpp */
