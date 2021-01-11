// Copyright 2018 Your Name <your_email>
#include <gtest/gtest.h>
#include "SeaButtle.h"
#include <vector>

TEST(SeaButtle, Poisk){
  int i = poiskAdresa(0, 0, 4, 1, 1);
  EXPECT_EQ(i, 1);
  pointKor(0, 0,4, 1, 1);
  int k = poiskAdresa(0, 0, 4, 1, 1);
  EXPECT_EQ(k, 0);
}

TEST(SeaButtle, FindKor){
  pointKor(3, 4, 2, 2, 1);
  int l = find_korIg(3, 5);
  EXPECT_EQ(l, 1);
  EXPECT_EQ(PoleIgroka.pole[3][4], 1);
  EXPECT_EQ(PoleIgroka.pole[3][5], 1);
  EXPECT_EQ(PoleIgroka.pole[3][3], 0);
  EXPECT_EQ(PoleIgroka.pole[3][6], 0);
}

TEST(SeaButtle, Read){
  EXPECT_EQ(read('c'), 3);
  EXPECT_EQ(read('F'), 6);
  EXPECT_EQ(read('M'), -1);
}

TEST(SeaButtle, Status){
  int m[10] = {0, 0, 1, 1, 1, 0, 0, 0, 0, 1};
  EXPECT_EQ(find_korIg(3, 2), 1);
  for (int i = 0; i < 10; i++){
    PoleIgroka.pole[3][i] = m[i];
  }
  PoleComp.shots[3][2] = 2;
  PoleComp.shots[3][3] = 2;
  PoleComp.shots[3][4] = 2;
  PoleIgroka.AdrKor[0][1] = 3;
  PoleIgroka.AdrKor[1][1] = 2;
  PoleIgroka.AdrKor[2][1] = 2;
  PoleIgroka.AdrKor[3][1] = 3;
  kill_or_not(PoleIgroka, PoleComp);
  EXPECT_EQ(find_korIg(3, 2), 3);
  EXPECT_EQ(PoleComp.shots[3][2], 3);
  EXPECT_EQ(PoleComp.shots[3][3], 3);
  EXPECT_EQ(PoleComp.shots[3][4], 3);
}

TEST(SeaButtle, Pobeda){
  for (int i = 0; i < 10; i++){
    PoleIgroka.AdrKor[4][i] = 1;
  }
  EXPECT_EQ(Pobeda(), 0);
  for (int i = 0; i < 10; i++){
    PoleIgroka.AdrKor[4][i] = 2;
  }
  EXPECT_EQ(Pobeda(), 2);
  for (int i = 0; i < 10; i++){
    PoleIgroka.AdrKor[4][i] = 1;
    PoleComp.AdrKor[4][i] = 2;
  }
  EXPECT_EQ(Pobeda(), 1);
}