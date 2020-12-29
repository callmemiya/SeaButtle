// Copyright 2018 Your Name <your_email>
#pragma once
#include "ClassPole.h"

Pole::Pole(){
    pole.resize(10);
    for (int i = 0; i < 10; i++){
        pole[i].resize(10);
    }
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            pole[i][j] = 0;
        }
    }
    for (int i = 0; i < 10; i++){
        AdrKor[0][i] = 0;
        AdrKor[1][i] = 0;
        AdrKor[2][i] = 0;
        AdrKor[3][i] = 0;
        AdrKor[4][i] = 0;
    }
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            shots[i][j] = 0;
        }
    }
}

Pole::Pole(std::vector<std::vector<int>> m){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            m[i][j] = 0;
        }
    }
    for (int i = 0; i < 10; i++){
        AdrKor[0][i] = 0;
        AdrKor[1][i] = 0;
        AdrKor[2][i] = 0;
        AdrKor[3][i] = 0;
        AdrKor[4][i] = 0;
    }
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            shots[i][j] = 0;
        }
    }
    pole = m;
}

void Pole::clear(){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            pole[i][j] = 0;
        }
    }
}

void Pole::print(){
    std::cout <<"   | A | B | C | D | E | F | G | H | I | J |" <<std::endl;
    std::cout <<"--------------------------------------------" <<std::endl;
    for (int i = 0; i < 10 ; i++){
        std::cout <<std::setfill(' ') <<std::setw(2) << i+1;
        std::cout << " | ";
        for (int j = 0; j < 10; j++){
            if (pole[i][j] == 0) std::cout <<" ";
            else
                std::cout << pole[i][j];
            std::cout <<" | ";
        }
        std::cout <<std::endl;
        std::cout <<std::setfill('-') <<std::setw(44) <<"-" <<std::endl;
    }
}

void kill_or_not(Pole& m, Pole& n){
    for (int i = 0; i < 10; i++){
        int l = 0;
        for (int j = 0; j < m.AdrKor[3][i]; j++){
            if (m.AdrKor[2][i] == 1){
                if (n.shots[m.AdrKor[0][i] + j][m.AdrKor[1][i]] == 2) l++;
            } else if (m.AdrKor[2][i] == 2){
                if (n.shots[m.AdrKor[0][i]][m.AdrKor[1][i] + j] == 2) l++;
            }
        }
        if (l > 0) m.AdrKor[4][i] = 1;
        if (l == m.AdrKor[3][i]) {
            m.AdrKor[4][i] = 2;
            for (int k = 0; k < m.AdrKor[3][i]; k++){
                if (m.AdrKor[2][i] == 1){
                    n.shots[m.AdrKor[0][i] + k][m.AdrKor[1][i]] = 3;
                } else if (m.AdrKor[2][i] == 2){
                    n.shots[m.AdrKor[0][i]][m.AdrKor[1][i] + k] = 3;
                }
            }
        }
    }
}
