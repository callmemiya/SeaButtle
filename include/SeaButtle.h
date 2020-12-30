#pragma once
#ifndef SeaButtle_h
#define SeaButtle_h

#include <iostream>
#include <iomanip>
#include <vector>
//#include "ClassPole.h"

class Pole;

extern Pole PoleIgroka;
extern Pole PoleComp;

extern int poiskAdresa(int row, int col, int pal, int polog, int user);

extern void pointKor(int row, int col, int pal, int polog, int user);

extern int read(char y);

extern void pointKorablVruchnuy();

extern void pointHardPC();

extern void pointKorablPC(int pal, int colum);

extern void pointKorabl(int pal, int colum);

extern int find_korPC(int x, int y);

extern int find_korIg(int x, int y);

extern void kill_or_not(Pole& m, Pole& n);

extern int Pobeda();

extern void printpole();

extern void HodIgroka();

extern void HodPC();

#endif /* SeaButtle_h */
