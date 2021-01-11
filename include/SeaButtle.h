#pragma once
#ifndef SeaButtle_h
#define SeaButtle_h

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

Pole PoleIgroka;
Pole PoleComp;

int poiskAdresa(int row, int col, int pal, int polog, int user);

void pointKor(int row, int col, int pal, int polog, int user);

int read(char y);

void pointKorablVruchnuy();

void pointHardPC();

void pointKorablPC(int pal, int colum);

void pointKorabl(int pal, int colum);

int find_korPC(int x, int y);

int find_korIg(int x, int y);

void kill_or_not(Pole& m, Pole& n);

int Pobeda();

void printpole();

void HodIgroka();

void HodPC();

#include <SeaButtle.cpp>

#endif /* SeaButtle_h */
