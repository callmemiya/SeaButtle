#ifndef SeaButtle_h
#define SeaButtle_h
#include "ClassPole.hpp"
#include "SeaButtle.cpp"
#include <iostream>
#include <iomanip>
#include <vector>

extern Pole PoleIgroka;
extern Pole PoleComp;

int poiskAdresa(int row, int col, int pal, int polog, int user);

void pointKor(int row, int col, int pal, int polog, int user);

int read(char y);

void pointKorablVruchnuy();

void pointHardPC();

void pointKorablPC(int pal, int colum);

void pointKorabl(int pal, int colum);

int find_korPC(int x, int y);

int find_korIg(int x, int y);

int Pobeda();

void kill_or_not(Pole& m, Pole& n);

void printpole();

void HodIgroka();

void HodPC();

#endif /* SeaButtle_h */
