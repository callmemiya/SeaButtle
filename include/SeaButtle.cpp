// Copyright 2018 Your Name <your_email>
#include "SeaButtle.h"
#include "ClassPole.h"

unsigned int seed = time(NULL);

int poiskAdresa(int row, int col, int pal, int polog, int user){
    if (polog == 1){
        int m = 0, f = pal;
        if (row - 1 >= 0) m--;
        if (row + pal < 10) f++;
        for (int i = m; i < f; i++){
            if (user == 1){
                if (PoleIgroka.pole[row + i][col] != 0) return 0;
                if (col + 1 < 10){
                    if (PoleIgroka.pole[row + i][col + 1] != 0) return 0;
                }
                if (col - 1 >= 0){
                    if (PoleIgroka.pole[row + i][col - 1] != 0) return 0;
                }
            } else {
                if (PoleComp.pole[row + i][col] != 0) return 0;
                if (col + 1 < 10){
                    if (PoleComp.pole[row + i][col + 1] != 0) return 0;
                }
                if (col - 1 >= 0){
                    if (PoleComp.pole[row + i][col - 1] != 0) return 0;
                }
            }
        }
        return 1;
    } else{
        int m = 0, f = pal;
        if (col - 1 >= 0) m--;
        if (col + pal < 10) f++;
        for (int i = m; i < f; i++){
            if (user == 1){
                if (PoleIgroka.pole[row][col+i] != 0) return 0;
                if (row - 1 >= 0){
                    if (PoleIgroka.pole[row - 1][col+i] != 0) return 0;
                }
                if (row + 1 < 10){
                    if (PoleIgroka.pole[row + 1][col+i] != 0) return 0;
                }
            } else {
                if (PoleComp.pole[row][col+i] != 0) return 0;
                if (row - 1 >= 0){
                    if (PoleComp.pole[row - 1][col+i] != 0) return 0;
                }
                if (row + 1 < 10){
                    if (PoleComp.pole[row + 1][col+i] != 0) return 0;
                }
            }
        }
        return 1;
    }
}

void pointKor(int row, int col, int pal, int polog, int user){
    if (polog == 1){
        for (int i = 0; i < pal; i++){
            if (user == 1) PoleIgroka.pole[row + i][col] = 1;
            else
                PoleComp.pole[row + i][col] = 1;
        }
    } else{
        for (int i = 0; i < pal; i++){
            if (user == 1) PoleIgroka.pole[row][col + i] = 1;
            else
                PoleComp.pole[row][col + i] = 1;
        }
    }
}

int read(char y){
    int y1 = -1;
    switch (y){
        case 'A':
            y1 = 1;
            break;
        case 'B':
            y1 = 2;
            break;
        case 'C':
            y1 = 3;
            break;
        case 'D':
            y1 = 4;
            break;
        case 'E':
            y1 = 5;
            break;
        case 'F':
            y1 = 6;
            break;
        case 'G':
            y1 = 7;
            break;
        case 'H':
            y1 = 8;
            break;
        case 'I':
            y1 = 9;
            break;
        case 'J':
            y1 = 10;
            break;
        case 'a':
            y1 = 1;
            break;
        case 'b':
            y1 = 2;
            break;
        case 'c':
            y1 = 3;
            break;
        case 'd':
            y1 = 4;
            break;
        case 'e':
            y1 = 5;
            break;
        case 'f':
            y1 = 6;
            break;
        case 'g':
            y1 = 7;
            break;
        case 'h':
            y1 = 8;
            break;
        case 'i':
            y1 = 9;
            break;
        case 'j':
            y1 = 10;
            break;
        default: y1 = -1;
    }
    return y1;
}

void pointKorablVruchnuy(){
    int x, y, polog;
    do {
        std::cout <<"Введите корректно координаты начала"
        << "четырехпалубного корабля: X и Y" <<std::endl;
        do{
            char y1;
            std::cin >> y1 >> x;
            y = read(y1);
            if (x < 1 || y < 1 || x > 10 || y > 10)
                std::cout << "Координаты введены некорректно,"
                <<" проверьте правильность написания." <<std::endl;
        }while(x < 1 || y < 1 || x > 10 || y > 10);
        std::cout <<"Выберите расположение:" <<std::endl
        <<" Вертикальное - 1" <<std::endl <<" Горизонтальное - 2"
        <<std::endl;
        do{
            std::cin >> polog;
            if (polog != 1 && polog != 2) std::cout
                <<"Расположение корабля может быть только "
                << "вертикальное(1) или горизонтальное(2)." <<std::endl;
        }while (polog != 1 && polog != 2);
    }while(!poiskAdresa(x - 1, y - 1, 4, polog, 1));
    PoleIgroka.AdrKor[0][0] = x - 1;
    PoleIgroka.AdrKor[1][0] = y - 1;
    PoleIgroka.AdrKor[2][0] = polog;
    PoleIgroka.AdrKor[3][0] = 4;
    pointKor(x - 1, y - 1, 4, polog, 1);
    PoleIgroka.print();
    for (int i = 0; i < 2; i++){
        do{
            std::cout << "Введите корректно координаты"
            << " начала трёхпалубного корабля: X и Y" << std::endl;
            do{
                char y1;
                std::cin >> y1 >> x;
                y = read(y1);
                if (x < 1 || y < 1 || x > 10 || y > 10)
                    std::cout <<"Координаты введены некорректно, "
                    << "проверьте правильность написания." << std::endl;
            }while(x < 1 || y < 1 || x > 10 || y > 10);
            std::cout << "Выберите расположение:" << std::endl
            << " Вертикальное - 1" << std::endl << " Горизонтальное - 2"
            << std::endl;
            do{
                std::cin >> polog;
                if (polog != 1 && polog != 2)
                    std::cout << "Расположение корабля может быть"
                    << " только вертикальное(1) или горизонтальное(2)."
                    << std::endl;
            }while (polog != 1 && polog != 2);
        }while(!poiskAdresa(x - 1, y - 1, 3, polog, 1));
        PoleIgroka.AdrKor[0][1 + i] = x - 1;
        PoleIgroka.AdrKor[1][1 + i] = y - 1;
        PoleIgroka.AdrKor[2][1 + i] = polog;
        PoleIgroka.AdrKor[3][1 + i] = 3;
        pointKor(x - 1, y - 1, 3, polog, 1);
        PoleIgroka.print();
    }
    for (int i = 0; i < 3; i++){
        do{
            std::cout << "Введите корректно координаты"
            << " начала двухпалубного корабля: X и Y" << std::endl;
            do{
                char y1;
                std::cin >> y1 >> x;
                y = read(y1);
                if (x < 1 || y < 1 || x > 10 || y > 10)
                    std::cout <<"Координаты введены некорректно,"
                    << " проверьте правильность написания." <<std::endl;
            }while(x < 1 || y < 1 || x > 10 || y > 10);
            std::cout << "Выберите расположение:" << std::endl
            <<" Вертикальное - 1" << std::endl <<" Горизонтальное - 2"
            << std::endl;
            do{
                std::cin >> polog;
                if (polog != 1 && polog != 2)
                    std::cout << "Расположение корабля может быть"
                    << " только вертикальное(1) или горизонтальное(2)."
                    << std::endl;
            }while (polog != 1 && polog != 2);
        }while(!poiskAdresa(x - 1, y - 1, 2, polog, 1));
        PoleIgroka.AdrKor[0][2 + i] = x - 1;
        PoleIgroka.AdrKor[1][2 + i] = y - 1;
        PoleIgroka.AdrKor[2][2 + i] = polog;
        PoleIgroka.AdrKor[3][2 + i] = 2;
        pointKor(x - 1, y - 1, 2, polog, 1);
        PoleIgroka.print();
    }
    for (int i = 0; i < 4; i++){
        do{
            std::cout << "Введите корректно координаты"
            << " начала однопалубного корабля: X и Y" <<std::endl;
            do{
                char y1;
                std::cin >> y1 >> x;
                y = read(y1);
                if (x < 1 || y < 1 || x > 10 || y > 10)
                    std::cout << "Координаты введены некорректно,"
                    << " проверьте правильность написания." <<std::endl;
            }while(x < 1 || y < 1 || x > 10 || y > 10);
        }while(!poiskAdresa(x - 1, y - 1, 1, 1, 1));
        PoleIgroka.AdrKor[0][6 + i] = x - 1;
        PoleIgroka.AdrKor[1][6 + i] = y - 1;
        PoleIgroka.AdrKor[2][6 + i] = 1;
        PoleIgroka.AdrKor[3][6 + i] = 1;
        pointKor(x - 1, y - 1, 1, polog, 1);
        PoleIgroka.print();
    }
}

void pointHardFirst(){
    int m[3][10] = {{1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
        {1, 1, 0, 1, 1, 1, 1, 0, 1, 1},
        {1, 1, 0, 1, 1, 0, 1, 1, 1, 1}};
    int f[3][10] = {{1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 0, 1, 1, 1},
        {1, 1, 0, 1, 1, 1, 0, 1, 1, 1}};
    int rndm = rand_r(&seed) % 4;
    if (rndm == 0){
        int l = rand_r(&seed) % 3;
        int j = rand_r(&seed) % 3;
        if (l == 0){
            PoleComp.AdrKor[0][0] = 0;
            PoleComp.AdrKor[1][0] = 0;
            PoleComp.AdrKor[2][0] = 2;
            PoleComp.AdrKor[3][0] = 4;
            PoleComp.AdrKor[0][3] = 0;
            PoleComp.AdrKor[1][3] = 5;
            PoleComp.AdrKor[2][3] = 2;
            PoleComp.AdrKor[3][3] = 2;
            PoleComp.AdrKor[0][4] = 0;
            PoleComp.AdrKor[1][4] = 8;
            PoleComp.AdrKor[2][4] = 2;
            PoleComp.AdrKor[3][4] = 2;
        }else if (l == 1){
            PoleComp.AdrKor[0][3] = 0;
            PoleComp.AdrKor[1][3] = 0;
            PoleComp.AdrKor[2][3] = 2;
            PoleComp.AdrKor[3][3] = 2;
            PoleComp.AdrKor[0][0] = 0;
            PoleComp.AdrKor[1][0] = 3;
            PoleComp.AdrKor[2][0] = 2;
            PoleComp.AdrKor[3][0] = 4;
            PoleComp.AdrKor[0][4] = 0;
            PoleComp.AdrKor[1][4] = 8;
            PoleComp.AdrKor[2][4] = 2;
            PoleComp.AdrKor[3][4] = 2;
        } else {
            PoleComp.AdrKor[0][3] = 0;
            PoleComp.AdrKor[1][3] = 0;
            PoleComp.AdrKor[2][3] = 2;
            PoleComp.AdrKor[3][3] = 2;
            PoleComp.AdrKor[0][4] = 0;
            PoleComp.AdrKor[1][4] = 3;
            PoleComp.AdrKor[2][4] = 2;
            PoleComp.AdrKor[3][4] = 2;
            PoleComp.AdrKor[0][0] = 0;
            PoleComp.AdrKor[1][0] = 6;
            PoleComp.AdrKor[2][0] = 2;
            PoleComp.AdrKor[3][0] = 4;
        }
        if (j == 0){
            PoleComp.AdrKor[0][1] = 9;
            PoleComp.AdrKor[1][1] = 0;
            PoleComp.AdrKor[2][1] = 2;
            PoleComp.AdrKor[3][1] = 3;
            PoleComp.AdrKor[0][2] = 9;
            PoleComp.AdrKor[1][2] = 4;
            PoleComp.AdrKor[2][2] = 2;
            PoleComp.AdrKor[3][2] = 3;
            PoleComp.AdrKor[0][5] = 9;
            PoleComp.AdrKor[1][5] = 8;
            PoleComp.AdrKor[2][5] = 2;
            PoleComp.AdrKor[3][5] = 2;
        } else if (j == 1){
            PoleComp.AdrKor[0][1] = 9;
            PoleComp.AdrKor[1][1] = 0;
            PoleComp.AdrKor[2][1] = 2;
            PoleComp.AdrKor[3][1] = 3;
            PoleComp.AdrKor[0][5] = 9;
            PoleComp.AdrKor[1][5] = 4;
            PoleComp.AdrKor[2][5] = 2;
            PoleComp.AdrKor[3][5] = 2;
            PoleComp.AdrKor[0][2] = 9;
            PoleComp.AdrKor[1][2] = 7;
            PoleComp.AdrKor[2][2] = 2;
            PoleComp.AdrKor[3][2] = 3;
        } else {
            PoleComp.AdrKor[0][5] = 9;
            PoleComp.AdrKor[1][5] = 0;
            PoleComp.AdrKor[2][5] = 2;
            PoleComp.AdrKor[3][5] = 2;
            PoleComp.AdrKor[0][1] = 9;
            PoleComp.AdrKor[1][1] = 3;
            PoleComp.AdrKor[2][1] = 2;
            PoleComp.AdrKor[3][1] = 3;
            PoleComp.AdrKor[0][2] = 9;
            PoleComp.AdrKor[1][2] = 7;
            PoleComp.AdrKor[2][2] = 2;
            PoleComp.AdrKor[3][2] = 3;
        }
        for (int i = 0; i < 10; i++){
            PoleComp.pole[0][i] = m[l][i];
            PoleComp.pole[9][i] = f[j][i];
        }
    } else if (rndm == 1){
        int j = rand_r(&seed) % 3;
        int l = rand_r(&seed) % 3;
        if (l == 0){
            PoleComp.AdrKor[0][0] = 9;
            PoleComp.AdrKor[1][0] = 0;
            PoleComp.AdrKor[2][0] = 2;
            PoleComp.AdrKor[3][0] = 4;
            PoleComp.AdrKor[0][3] = 9;
            PoleComp.AdrKor[1][3] = 5;
            PoleComp.AdrKor[2][3] = 2;
            PoleComp.AdrKor[3][3] = 2;
            PoleComp.AdrKor[0][4] = 9;
            PoleComp.AdrKor[1][4] = 8;
            PoleComp.AdrKor[2][4] = 2;
            PoleComp.AdrKor[3][4] = 2;
        }else if (l == 1){
            PoleComp.AdrKor[0][3] = 9;
            PoleComp.AdrKor[1][3] = 0;
            PoleComp.AdrKor[2][3] = 2;
            PoleComp.AdrKor[3][3] = 2;
            PoleComp.AdrKor[0][0] = 9;
            PoleComp.AdrKor[1][0] = 3;
            PoleComp.AdrKor[2][0] = 2;
            PoleComp.AdrKor[3][0] = 4;
            PoleComp.AdrKor[0][4] = 9;
            PoleComp.AdrKor[1][4] = 8;
            PoleComp.AdrKor[2][4] = 2;
            PoleComp.AdrKor[3][4] = 2;
        } else {
            PoleComp.AdrKor[0][3] = 9;
            PoleComp.AdrKor[1][3] = 0;
            PoleComp.AdrKor[2][3] = 2;
            PoleComp.AdrKor[3][3] = 2;
            PoleComp.AdrKor[0][4] = 9;
            PoleComp.AdrKor[1][4] = 3;
            PoleComp.AdrKor[2][4] = 2;
            PoleComp.AdrKor[3][4] = 2;
            PoleComp.AdrKor[0][0] = 9;
            PoleComp.AdrKor[1][0] = 6;
            PoleComp.AdrKor[2][0] = 2;
            PoleComp.AdrKor[3][0] = 4;
        }
        if (j == 0){
            PoleComp.AdrKor[0][1] = 0;
            PoleComp.AdrKor[1][1] = 0;
            PoleComp.AdrKor[2][1] = 2;
            PoleComp.AdrKor[3][1] = 3;
            PoleComp.AdrKor[0][2] = 0;
            PoleComp.AdrKor[1][2] = 4;
            PoleComp.AdrKor[2][2] = 2;
            PoleComp.AdrKor[3][2] = 3;
            PoleComp.AdrKor[0][5] = 0;
            PoleComp.AdrKor[1][5] = 8;
            PoleComp.AdrKor[2][5] = 2;
            PoleComp.AdrKor[3][5] = 2;
        } else if (j == 1){
            PoleComp.AdrKor[0][1] = 0;
            PoleComp.AdrKor[1][1] = 0;
            PoleComp.AdrKor[2][1] = 2;
            PoleComp.AdrKor[3][1] = 3;
            PoleComp.AdrKor[0][5] = 0;
            PoleComp.AdrKor[1][5] = 4;
            PoleComp.AdrKor[2][5] = 2;
            PoleComp.AdrKor[3][5] = 2;
            PoleComp.AdrKor[0][2] = 0;
            PoleComp.AdrKor[1][2] = 7;
            PoleComp.AdrKor[2][2] = 2;
            PoleComp.AdrKor[3][2] = 3;
        } else {
            PoleComp.AdrKor[0][5] = 0;
            PoleComp.AdrKor[1][5] = 0;
            PoleComp.AdrKor[2][5] = 2;
            PoleComp.AdrKor[3][5] = 2;
            PoleComp.AdrKor[0][1] = 0;
            PoleComp.AdrKor[1][1] = 3;
            PoleComp.AdrKor[2][1] = 2;
            PoleComp.AdrKor[3][1] = 3;
            PoleComp.AdrKor[0][2] = 0;
            PoleComp.AdrKor[1][2] = 7;
            PoleComp.AdrKor[2][2] = 2;
            PoleComp.AdrKor[3][2] = 3;
        }
        for (int i = 0; i < 10; i++){
            PoleComp.pole[9][i] = m[l][i];
            PoleComp.pole[0][i] = f[j][i];
        }
    } else if (rndm == 2){
        int l = rand_r(&seed) % 3;
        int j = rand_r(&seed) % 3;
        if (l == 0){
            PoleComp.AdrKor[0][0] = 0;
            PoleComp.AdrKor[1][0] = 0;
            PoleComp.AdrKor[2][0] = 1;
            PoleComp.AdrKor[3][0] = 4;
            PoleComp.AdrKor[0][3] = 5;
            PoleComp.AdrKor[1][3] = 0;
            PoleComp.AdrKor[2][3] = 1;
            PoleComp.AdrKor[3][3] = 2;
            PoleComp.AdrKor[0][4] = 8;
            PoleComp.AdrKor[1][4] = 0;
            PoleComp.AdrKor[2][4] = 1;
            PoleComp.AdrKor[3][4] = 2;
        } else if (l == 1){
            PoleComp.AdrKor[0][3] = 0;
            PoleComp.AdrKor[1][3] = 0;
            PoleComp.AdrKor[2][3] = 1;
            PoleComp.AdrKor[3][3] = 2;
            PoleComp.AdrKor[0][0] = 3;
            PoleComp.AdrKor[1][0] = 0;
            PoleComp.AdrKor[2][0] = 1;
            PoleComp.AdrKor[3][0] = 4;
            PoleComp.AdrKor[0][4] = 8;
            PoleComp.AdrKor[1][4] = 0;
            PoleComp.AdrKor[2][4] = 1;
            PoleComp.AdrKor[3][4] = 2;
        } else {
            PoleComp.AdrKor[0][3] = 0;
            PoleComp.AdrKor[1][3] = 0;
            PoleComp.AdrKor[2][3] = 1;
            PoleComp.AdrKor[3][3] = 2;
            PoleComp.AdrKor[0][4] = 3;
            PoleComp.AdrKor[1][4] = 0;
            PoleComp.AdrKor[2][4] = 1;
            PoleComp.AdrKor[3][4] = 2;
            PoleComp.AdrKor[0][0] = 6;
            PoleComp.AdrKor[1][0] = 0;
            PoleComp.AdrKor[2][0] = 1;
            PoleComp.AdrKor[3][0] = 4;
        }
        if (j == 0){
            PoleComp.AdrKor[0][1] = 0;
            PoleComp.AdrKor[1][1] = 9;
            PoleComp.AdrKor[2][1] = 1;
            PoleComp.AdrKor[3][1] = 3;
            PoleComp.AdrKor[0][2] = 4;
            PoleComp.AdrKor[1][2] = 9;
            PoleComp.AdrKor[2][2] = 1;
            PoleComp.AdrKor[3][2] = 3;
            PoleComp.AdrKor[0][5] = 8;
            PoleComp.AdrKor[1][5] = 9;
            PoleComp.AdrKor[2][5] = 1;
            PoleComp.AdrKor[3][5] = 2;
        } else if (j == 1){
            PoleComp.AdrKor[0][1] = 0;
            PoleComp.AdrKor[1][1] = 9;
            PoleComp.AdrKor[2][1] = 1;
            PoleComp.AdrKor[3][1] = 3;
            PoleComp.AdrKor[0][5] = 4;
            PoleComp.AdrKor[1][5] = 9;
            PoleComp.AdrKor[2][5] = 1;
            PoleComp.AdrKor[3][5] = 2;
            PoleComp.AdrKor[0][2] = 7;
            PoleComp.AdrKor[1][2] = 9;
            PoleComp.AdrKor[2][2] = 1;
            PoleComp.AdrKor[3][2] = 3;
        } else {
            PoleComp.AdrKor[0][5] = 0;
            PoleComp.AdrKor[1][5] = 9;
            PoleComp.AdrKor[2][5] = 1;
            PoleComp.AdrKor[3][5] = 2;
            PoleComp.AdrKor[0][1] = 3;
            PoleComp.AdrKor[1][1] = 9;
            PoleComp.AdrKor[2][1] = 1;
            PoleComp.AdrKor[3][1] = 3;
            PoleComp.AdrKor[0][2] = 7;
            PoleComp.AdrKor[1][2] = 9;
            PoleComp.AdrKor[2][2] = 1;
            PoleComp.AdrKor[3][2] = 3;
        }
        for (int i = 0; i < 10; i++){
            PoleComp.pole[i][0] = m[l][i];
            PoleComp.pole[i][9] = f[j][i];
        }
    } else {
        int j = rand_r(&seed) % 3;
        int l = rand_r(&seed) % 3;
        if (l == 0){
            PoleComp.AdrKor[0][0] = 0;
            PoleComp.AdrKor[1][0] = 9;
            PoleComp.AdrKor[2][0] = 1;
            PoleComp.AdrKor[3][0] = 4;
            PoleComp.AdrKor[0][3] = 5;
            PoleComp.AdrKor[1][3] = 9;
            PoleComp.AdrKor[2][3] = 1;
            PoleComp.AdrKor[3][3] = 2;
            PoleComp.AdrKor[0][4] = 8;
            PoleComp.AdrKor[1][4] = 9;
            PoleComp.AdrKor[2][4] = 1;
            PoleComp.AdrKor[3][4] = 2;
        } else if (l == 1){
            PoleComp.AdrKor[0][3] = 0;
            PoleComp.AdrKor[1][3] = 9;
            PoleComp.AdrKor[2][3] = 1;
            PoleComp.AdrKor[3][3] = 2;
            PoleComp.AdrKor[0][0] = 3;
            PoleComp.AdrKor[1][0] = 9;
            PoleComp.AdrKor[2][0] = 1;
            PoleComp.AdrKor[3][0] = 4;
            PoleComp.AdrKor[0][4] = 8;
            PoleComp.AdrKor[1][4] = 9;
            PoleComp.AdrKor[2][4] = 1;
            PoleComp.AdrKor[3][4] = 2;
        } else {
            PoleComp.AdrKor[0][3] = 0;
            PoleComp.AdrKor[1][3] = 9;
            PoleComp.AdrKor[2][3] = 1;
            PoleComp.AdrKor[3][3] = 2;
            PoleComp.AdrKor[0][4] = 3;
            PoleComp.AdrKor[1][4] = 9;
            PoleComp.AdrKor[2][4] = 1;
            PoleComp.AdrKor[3][4] = 2;
            PoleComp.AdrKor[0][0] = 6;
            PoleComp.AdrKor[1][0] = 9;
            PoleComp.AdrKor[2][0] = 1;
            PoleComp.AdrKor[3][0] = 4;
        }
        if (j == 0){
            PoleComp.AdrKor[0][1] = 0;
            PoleComp.AdrKor[1][1] = 0;
            PoleComp.AdrKor[2][1] = 1;
            PoleComp.AdrKor[3][1] = 3;
            PoleComp.AdrKor[0][2] = 4;
            PoleComp.AdrKor[1][2] = 0;
            PoleComp.AdrKor[2][2] = 1;
            PoleComp.AdrKor[3][2] = 3;
            PoleComp.AdrKor[0][5] = 8;
            PoleComp.AdrKor[1][5] = 0;
            PoleComp.AdrKor[2][5] = 1;
            PoleComp.AdrKor[3][5] = 2;
        } else if (j == 1){
            PoleComp.AdrKor[0][1] = 0;
            PoleComp.AdrKor[1][1] = 0;
            PoleComp.AdrKor[2][1] = 1;
            PoleComp.AdrKor[3][1] = 3;
            PoleComp.AdrKor[0][5] = 4;
            PoleComp.AdrKor[1][5] = 0;
            PoleComp.AdrKor[2][5] = 1;
            PoleComp.AdrKor[3][5] = 2;
            PoleComp.AdrKor[0][2] = 7;
            PoleComp.AdrKor[1][2] = 0;
            PoleComp.AdrKor[2][2] = 1;
            PoleComp.AdrKor[3][2] = 3;
        } else {
            PoleComp.AdrKor[0][5] = 0;
            PoleComp.AdrKor[1][5] = 0;
            PoleComp.AdrKor[2][5] = 1;
            PoleComp.AdrKor[3][5] = 2;
            PoleComp.AdrKor[0][1] = 3;
            PoleComp.AdrKor[1][1] = 0;
            PoleComp.AdrKor[2][1] = 1;
            PoleComp.AdrKor[3][1] = 3;
            PoleComp.AdrKor[0][2] = 7;
            PoleComp.AdrKor[1][2] = 0;
            PoleComp.AdrKor[2][2] = 1;
            PoleComp.AdrKor[3][2] = 3;
        }
        for (int i = 0; i < 10; i++){
            PoleComp.pole[i][9] = m[l][i];
            PoleComp.pole[i][0] = f[j][i];
        }
    }
}

void pointHardThird(){
    int n[4][10] = {{1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}};
    int rndm = rand_r(&seed) % 4;
    if (rndm == 0){
        PoleComp.AdrKor[0][0] = 0;
        PoleComp.AdrKor[1][0] = 0;
        PoleComp.AdrKor[2][0] = 2;
        PoleComp.AdrKor[3][0] = 4;
        PoleComp.AdrKor[0][1] = 0;
        PoleComp.AdrKor[1][1] = 5;
        PoleComp.AdrKor[2][1] = 2;
        PoleComp.AdrKor[3][1] = 3;
        PoleComp.AdrKor[0][2] = 2;
        PoleComp.AdrKor[1][2] = 0;
        PoleComp.AdrKor[2][2] = 1;
        PoleComp.AdrKor[3][2] = 3;
        PoleComp.AdrKor[0][3] = 0;
        PoleComp.AdrKor[1][3] = 9;
        PoleComp.AdrKor[2][3] = 1;
        PoleComp.AdrKor[3][3] = 2;
        PoleComp.AdrKor[0][4] = 6;
        PoleComp.AdrKor[1][4] = 0;
        PoleComp.AdrKor[2][4] = 1;
        PoleComp.AdrKor[3][4] = 2;
        PoleComp.AdrKor[0][5] = 9;
        PoleComp.AdrKor[1][5] = 0;
        PoleComp.AdrKor[2][5] = 2;
        PoleComp.AdrKor[3][5] = 2;
        for (int i = 0; i < 10; i++){
            PoleComp.pole[0][i] = n[0][i];
            PoleComp.pole[1][i] = n[1][i];
            PoleComp.pole[i][0] = n[2][i];
            PoleComp.pole[i][1] = n[3][i];
        }
    } else if (rndm == 1){
        PoleComp.AdrKor[0][0] = 0;
        PoleComp.AdrKor[1][0] = 9;
        PoleComp.AdrKor[2][0] = 1;
        PoleComp.AdrKor[3][0] = 4;
        PoleComp.AdrKor[0][1] = 0;
        PoleComp.AdrKor[1][1] = 5;
        PoleComp.AdrKor[2][1] = 2;
        PoleComp.AdrKor[3][1] = 3;
        PoleComp.AdrKor[0][2] = 5;
        PoleComp.AdrKor[1][2] = 9;
        PoleComp.AdrKor[2][2] = 1;
        PoleComp.AdrKor[3][2] = 3;
        PoleComp.AdrKor[0][3] = 0;
        PoleComp.AdrKor[1][3] = 0;
        PoleComp.AdrKor[2][3] = 1;
        PoleComp.AdrKor[3][3] = 2;
        PoleComp.AdrKor[0][4] = 0;
        PoleComp.AdrKor[1][4] = 2;
        PoleComp.AdrKor[2][4] = 2;
        PoleComp.AdrKor[3][4] = 2;
        PoleComp.AdrKor[0][5] = 9;
        PoleComp.AdrKor[1][5] = 8;
        PoleComp.AdrKor[2][5] = 2;
        PoleComp.AdrKor[3][5] = 2;
        for (int i = 0; i < 10; i++){
            PoleComp.pole[0][i] = n[2][9 - i];
            PoleComp.pole[1][i] = n[3][9 - i];
            PoleComp.pole[i][9] = n[0][i];
            PoleComp.pole[i][8] = n[1][i];
        }
    } else if (rndm == 2){
        PoleComp.AdrKor[0][0] = 9;
        PoleComp.AdrKor[1][0] = 6;
        PoleComp.AdrKor[2][0] = 2;
        PoleComp.AdrKor[3][0] = 4;
        PoleComp.AdrKor[0][1] = 9;
        PoleComp.AdrKor[1][1] = 2;
        PoleComp.AdrKor[2][1] = 2;
        PoleComp.AdrKor[3][1] = 3;
        PoleComp.AdrKor[0][2] = 5;
        PoleComp.AdrKor[1][2] = 9;
        PoleComp.AdrKor[2][2] = 1;
        PoleComp.AdrKor[3][2] = 3;
        PoleComp.AdrKor[0][3] = 8;
        PoleComp.AdrKor[1][3] = 0;
        PoleComp.AdrKor[2][3] = 1;
        PoleComp.AdrKor[3][3] = 2;
        PoleComp.AdrKor[0][4] = 0;
        PoleComp.AdrKor[1][4] = 8;
        PoleComp.AdrKor[2][4] = 2;
        PoleComp.AdrKor[3][4] = 2;
        PoleComp.AdrKor[0][5] = 2;
        PoleComp.AdrKor[1][5] = 9;
        PoleComp.AdrKor[2][5] = 1;
        PoleComp.AdrKor[3][5] = 2;
        for (int i = 0; i < 10; i++){
            PoleComp.pole[9][i] = n[0][9 - i];
            PoleComp.pole[8][i] = n[1][9 - i];
            PoleComp.pole[i][9] = n[2][9 - i];
            PoleComp.pole[i][8] = n[3][9 - i];
        }
    } else {
        PoleComp.AdrKor[0][0] = 6;
        PoleComp.AdrKor[1][0] = 0;
        PoleComp.AdrKor[2][0] = 1;
        PoleComp.AdrKor[3][0] = 4;
        PoleComp.AdrKor[0][1] = 2;
        PoleComp.AdrKor[1][1] = 0;
        PoleComp.AdrKor[2][1] = 1;
        PoleComp.AdrKor[3][1] = 3;
        PoleComp.AdrKor[0][2] = 9;
        PoleComp.AdrKor[1][2] = 2;
        PoleComp.AdrKor[2][2] = 2;
        PoleComp.AdrKor[3][2] = 3;
        PoleComp.AdrKor[0][3] = 0;
        PoleComp.AdrKor[1][3] = 0;
        PoleComp.AdrKor[2][3] = 2;
        PoleComp.AdrKor[3][3] = 2;
        PoleComp.AdrKor[0][4] = 9;
        PoleComp.AdrKor[1][4] = 6;
        PoleComp.AdrKor[2][4] = 2;
        PoleComp.AdrKor[3][4] = 2;
        PoleComp.AdrKor[0][5] = 8;
        PoleComp.AdrKor[1][5] = 9;
        PoleComp.AdrKor[2][5] = 1;
        PoleComp.AdrKor[3][5] = 2;
        for (int i = 0; i < 10; i++){
            PoleComp.pole[9][i] = n[2][i];
            PoleComp.pole[8][i] = n[3][i];
            PoleComp.pole[i][0] = n[0][9 - i];
            PoleComp.pole[i][1] = n[1][9 - i];
        }
    }
}

void pointHardPC(){
    int m[3][10] = {{1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
        {1, 1, 0, 1, 1, 1, 1, 0, 1, 1},
        {1, 1, 0, 1, 1, 0, 1, 1, 1, 1}};
    int f[3][10] = {{1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 0, 1, 1, 1},
        {1, 1, 0, 1, 1, 1, 0, 1, 1, 1}};
    int rnd = rand_r(&seed) % 3;
    if (rnd == 0){
        pointHardFirst();
    } else if (rnd == 1){
        int rndm = rand_r(&seed) % 4;
        if (rndm == 0){
            int l = rand_r(&seed) % 3;
            int j = rand_r(&seed) % 3;
            if (l == 0){
                PoleComp.AdrKor[0][0] = 0;
                PoleComp.AdrKor[1][0] = 0;
                PoleComp.AdrKor[2][0] = 1;
                PoleComp.AdrKor[3][0] = 4;
                PoleComp.AdrKor[0][3] = 5;
                PoleComp.AdrKor[1][3] = 0;
                PoleComp.AdrKor[2][3] = 1;
                PoleComp.AdrKor[3][3] = 2;
                PoleComp.AdrKor[0][4] = 8;
                PoleComp.AdrKor[1][4] = 0;
                PoleComp.AdrKor[2][4] = 1;
                PoleComp.AdrKor[3][4] = 2;
            } else if (l == 1){
                PoleComp.AdrKor[0][3] = 0;
                PoleComp.AdrKor[1][3] = 0;
                PoleComp.AdrKor[2][3] = 1;
                PoleComp.AdrKor[3][3] = 2;
                PoleComp.AdrKor[0][0] = 3;
                PoleComp.AdrKor[1][0] = 0;
                PoleComp.AdrKor[2][0] = 1;
                PoleComp.AdrKor[3][0] = 4;
                PoleComp.AdrKor[0][4] = 8;
                PoleComp.AdrKor[1][4] = 0;
                PoleComp.AdrKor[2][4] = 1;
                PoleComp.AdrKor[3][4] = 2;
            } else {
                PoleComp.AdrKor[0][3] = 0;
                PoleComp.AdrKor[1][3] = 0;
                PoleComp.AdrKor[2][3] = 1;
                PoleComp.AdrKor[3][3] = 2;
                PoleComp.AdrKor[0][4] = 3;
                PoleComp.AdrKor[1][4] = 0;
                PoleComp.AdrKor[2][4] = 1;
                PoleComp.AdrKor[3][4] = 2;
                PoleComp.AdrKor[0][0] = 6;
                PoleComp.AdrKor[1][0] = 0;
                PoleComp.AdrKor[2][0] = 1;
                PoleComp.AdrKor[3][0] = 4;
            }
            if (j == 0){
                PoleComp.AdrKor[0][1] = 0;
                PoleComp.AdrKor[1][1] = 2;
                PoleComp.AdrKor[2][1] = 1;
                PoleComp.AdrKor[3][1] = 3;
                PoleComp.AdrKor[0][2] = 4;
                PoleComp.AdrKor[1][2] = 2;
                PoleComp.AdrKor[2][2] = 1;
                PoleComp.AdrKor[3][2] = 3;
                PoleComp.AdrKor[0][5] = 8;
                PoleComp.AdrKor[1][5] = 2;
                PoleComp.AdrKor[2][5] = 1;
                PoleComp.AdrKor[3][5] = 2;
            } else if (j == 1){
                PoleComp.AdrKor[0][1] = 0;
                PoleComp.AdrKor[1][1] = 2;
                PoleComp.AdrKor[2][1] = 1;
                PoleComp.AdrKor[3][1] = 3;
                PoleComp.AdrKor[0][5] = 4;
                PoleComp.AdrKor[1][5] = 2;
                PoleComp.AdrKor[2][5] = 1;
                PoleComp.AdrKor[3][5] = 2;
                PoleComp.AdrKor[0][2] = 7;
                PoleComp.AdrKor[1][2] = 2;
                PoleComp.AdrKor[2][2] = 1;
                PoleComp.AdrKor[3][2] = 3;
            } else {
                PoleComp.AdrKor[0][5] = 0;
                PoleComp.AdrKor[1][5] = 2;
                PoleComp.AdrKor[2][5] = 1;
                PoleComp.AdrKor[3][5] = 2;
                PoleComp.AdrKor[0][1] = 3;
                PoleComp.AdrKor[1][1] = 2;
                PoleComp.AdrKor[2][1] = 1;
                PoleComp.AdrKor[3][1] = 3;
                PoleComp.AdrKor[0][2] = 7;
                PoleComp.AdrKor[1][2] = 2;
                PoleComp.AdrKor[2][2] = 1;
                PoleComp.AdrKor[3][2] = 3;
            }
            for (int i = 0; i < 10; i++){
                PoleComp.pole[i][0] = m[l][i];
                PoleComp.pole[i][2] = f[j][i];
            }
        } else if (rndm == 1){
            int l = rand_r(&seed) % 3;
            int j = rand_r(&seed) % 3;
            if (l == 0){
                PoleComp.AdrKor[0][0] = 0;
                PoleComp.AdrKor[1][0] = 9;
                PoleComp.AdrKor[2][0] = 1;
                PoleComp.AdrKor[3][0] = 4;
                PoleComp.AdrKor[0][3] = 5;
                PoleComp.AdrKor[1][3] = 9;
                PoleComp.AdrKor[2][3] = 1;
                PoleComp.AdrKor[3][3] = 2;
                PoleComp.AdrKor[0][4] = 8;
                PoleComp.AdrKor[1][4] = 9;
                PoleComp.AdrKor[2][4] = 1;
                PoleComp.AdrKor[3][4] = 2;
            } else if (l == 1){
                PoleComp.AdrKor[0][3] = 0;
                PoleComp.AdrKor[1][3] = 9;
                PoleComp.AdrKor[2][3] = 1;
                PoleComp.AdrKor[3][3] = 2;
                PoleComp.AdrKor[0][0] = 3;
                PoleComp.AdrKor[1][0] = 9;
                PoleComp.AdrKor[2][0] = 1;
                PoleComp.AdrKor[3][0] = 4;
                PoleComp.AdrKor[0][4] = 8;
                PoleComp.AdrKor[1][4] = 9;
                PoleComp.AdrKor[2][4] = 1;
                PoleComp.AdrKor[3][4] = 2;
            } else {
                PoleComp.AdrKor[0][3] = 0;
                PoleComp.AdrKor[1][3] = 9;
                PoleComp.AdrKor[2][3] = 1;
                PoleComp.AdrKor[3][3] = 2;
                PoleComp.AdrKor[0][4] = 3;
                PoleComp.AdrKor[1][4] = 9;
                PoleComp.AdrKor[2][4] = 1;
                PoleComp.AdrKor[3][4] = 2;
                PoleComp.AdrKor[0][0] = 6;
                PoleComp.AdrKor[1][0] = 9;
                PoleComp.AdrKor[2][0] = 1;
                PoleComp.AdrKor[3][0] = 4;
            }
            if (j == 0){
                PoleComp.AdrKor[0][1] = 0;
                PoleComp.AdrKor[1][1] = 7;
                PoleComp.AdrKor[2][1] = 1;
                PoleComp.AdrKor[3][1] = 3;
                PoleComp.AdrKor[0][2] = 4;
                PoleComp.AdrKor[1][2] = 7;
                PoleComp.AdrKor[2][2] = 1;
                PoleComp.AdrKor[3][2] = 3;
                PoleComp.AdrKor[0][5] = 8;
                PoleComp.AdrKor[1][5] = 7;
                PoleComp.AdrKor[2][5] = 1;
                PoleComp.AdrKor[3][5] = 2;
            } else if (j == 1){
                PoleComp.AdrKor[0][1] = 0;
                PoleComp.AdrKor[1][1] = 7;
                PoleComp.AdrKor[2][1] = 1;
                PoleComp.AdrKor[3][1] = 3;
                PoleComp.AdrKor[0][5] = 4;
                PoleComp.AdrKor[1][5] = 7;
                PoleComp.AdrKor[2][5] = 1;
                PoleComp.AdrKor[3][5] = 2;
                PoleComp.AdrKor[0][2] = 7;
                PoleComp.AdrKor[1][2] = 7;
                PoleComp.AdrKor[2][2] = 1;
                PoleComp.AdrKor[3][2] = 3;
            } else {
                PoleComp.AdrKor[0][5] = 0;
                PoleComp.AdrKor[1][5] = 7;
                PoleComp.AdrKor[2][5] = 1;
                PoleComp.AdrKor[3][5] = 2;
                PoleComp.AdrKor[0][1] = 3;
                PoleComp.AdrKor[1][1] = 7;
                PoleComp.AdrKor[2][1] = 1;
                PoleComp.AdrKor[3][1] = 3;
                PoleComp.AdrKor[0][2] = 7;
                PoleComp.AdrKor[1][2] = 7;
                PoleComp.AdrKor[2][2] = 1;
                PoleComp.AdrKor[3][2] = 3;
            }
            for (int i = 0; i < 10; i++){
                PoleComp.pole[i][9] = m[l][i];
                PoleComp.pole[i][7] = f[j][i];
            }
        } else if (rndm == 2){
            int l = rand_r(&seed) % 3;
            int j = rand_r(&seed) % 3;
            if (l == 0){
                PoleComp.AdrKor[0][0] = 0;
                PoleComp.AdrKor[1][0] = 0;
                PoleComp.AdrKor[2][0] = 2;
                PoleComp.AdrKor[3][0] = 4;
                PoleComp.AdrKor[0][3] = 0;
                PoleComp.AdrKor[1][3] = 5;
                PoleComp.AdrKor[2][3] = 2;
                PoleComp.AdrKor[3][3] = 2;
                PoleComp.AdrKor[0][4] = 0;
                PoleComp.AdrKor[1][4] = 8;
                PoleComp.AdrKor[2][4] = 2;
                PoleComp.AdrKor[3][4] = 2;
            } else if (l == 1){
                PoleComp.AdrKor[0][3] = 0;
                PoleComp.AdrKor[1][3] = 0;
                PoleComp.AdrKor[2][3] = 2;
                PoleComp.AdrKor[3][3] = 2;
                PoleComp.AdrKor[0][0] = 0;
                PoleComp.AdrKor[1][0] = 3;
                PoleComp.AdrKor[2][0] = 2;
                PoleComp.AdrKor[3][0] = 4;
                PoleComp.AdrKor[0][4] = 0;
                PoleComp.AdrKor[1][4] = 8;
                PoleComp.AdrKor[2][4] = 2;
                PoleComp.AdrKor[3][4] = 2;
            } else {
                PoleComp.AdrKor[0][3] = 0;
                PoleComp.AdrKor[1][3] = 0;
                PoleComp.AdrKor[2][3] = 2;
                PoleComp.AdrKor[3][3] = 2;
                PoleComp.AdrKor[0][4] = 0;
                PoleComp.AdrKor[1][4] = 3;
                PoleComp.AdrKor[2][4] = 2;
                PoleComp.AdrKor[3][4] = 2;
                PoleComp.AdrKor[0][0] = 0;
                PoleComp.AdrKor[1][0] = 6;
                PoleComp.AdrKor[2][0] = 2;
                PoleComp.AdrKor[3][0] = 4;
            }
            if (j == 0){
                PoleComp.AdrKor[0][1] = 2;
                PoleComp.AdrKor[1][1] = 0;
                PoleComp.AdrKor[2][1] = 2;
                PoleComp.AdrKor[3][1] = 3;
                PoleComp.AdrKor[0][2] = 2;
                PoleComp.AdrKor[1][2] = 4;
                PoleComp.AdrKor[2][2] = 2;
                PoleComp.AdrKor[3][2] = 3;
                PoleComp.AdrKor[0][5] = 2;
                PoleComp.AdrKor[1][5] = 8;
                PoleComp.AdrKor[2][5] = 2;
                PoleComp.AdrKor[3][5] = 2;
            } else if (j == 1){
                PoleComp.AdrKor[0][1] = 2;
                PoleComp.AdrKor[1][1] = 0;
                PoleComp.AdrKor[2][1] = 2;
                PoleComp.AdrKor[3][1] = 3;
                PoleComp.AdrKor[0][5] = 2;
                PoleComp.AdrKor[1][5] = 4;
                PoleComp.AdrKor[2][5] = 2;
                PoleComp.AdrKor[3][5] = 2;
                PoleComp.AdrKor[0][2] = 2;
                PoleComp.AdrKor[1][2] = 7;
                PoleComp.AdrKor[2][2] = 2;
                PoleComp.AdrKor[3][2] = 3;
            } else {
                PoleComp.AdrKor[0][5] = 2;
                PoleComp.AdrKor[1][5] = 0;
                PoleComp.AdrKor[2][5] = 2;
                PoleComp.AdrKor[3][5] = 2;
                PoleComp.AdrKor[0][1] = 2;
                PoleComp.AdrKor[1][1] = 3;
                PoleComp.AdrKor[2][1] = 2;
                PoleComp.AdrKor[3][1] = 3;
                PoleComp.AdrKor[0][2] = 2;
                PoleComp.AdrKor[1][2] = 7;
                PoleComp.AdrKor[2][2] = 2;
                PoleComp.AdrKor[3][2] = 3;
            }
            for (int i = 0; i < 10; i++){
                PoleComp.pole[0][i] = m[l][i];
                PoleComp.pole[2][i] = f[j][i];
            }
        } else {
            int l = rand_r(&seed) % 3;
            int j = rand_r(&seed) % 3;
            if (l == 0){
                PoleComp.AdrKor[0][0] = 9;
                PoleComp.AdrKor[1][0] = 0;
                PoleComp.AdrKor[2][0] = 2;
                PoleComp.AdrKor[3][0] = 4;
                PoleComp.AdrKor[0][3] = 9;
                PoleComp.AdrKor[1][3] = 5;
                PoleComp.AdrKor[2][3] = 2;
                PoleComp.AdrKor[3][3] = 2;
                PoleComp.AdrKor[0][4] = 9;
                PoleComp.AdrKor[1][4] = 8;
                PoleComp.AdrKor[2][4] = 2;
                PoleComp.AdrKor[3][4] = 2;
            } else if (l == 1){
                PoleComp.AdrKor[0][3] = 9;
                PoleComp.AdrKor[1][3] = 0;
                PoleComp.AdrKor[2][3] = 2;
                PoleComp.AdrKor[3][3] = 2;
                PoleComp.AdrKor[0][0] = 9;
                PoleComp.AdrKor[1][0] = 3;
                PoleComp.AdrKor[2][0] = 2;
                PoleComp.AdrKor[3][0] = 4;
                PoleComp.AdrKor[0][4] = 9;
                PoleComp.AdrKor[1][4] = 8;
                PoleComp.AdrKor[2][4] = 2;
                PoleComp.AdrKor[3][4] = 2;
            } else {
                PoleComp.AdrKor[0][3] = 9;
                PoleComp.AdrKor[1][3] = 0;
                PoleComp.AdrKor[2][3] = 2;
                PoleComp.AdrKor[3][3] = 2;
                PoleComp.AdrKor[0][4] = 9;
                PoleComp.AdrKor[1][4] = 3;
                PoleComp.AdrKor[2][4] = 2;
                PoleComp.AdrKor[3][4] = 2;
                PoleComp.AdrKor[0][0] = 9;
                PoleComp.AdrKor[1][0] = 6;
                PoleComp.AdrKor[2][0] = 2;
                PoleComp.AdrKor[3][0] = 4;
            }
            if (j == 0){
                PoleComp.AdrKor[0][1] = 7;
                PoleComp.AdrKor[1][1] = 0;
                PoleComp.AdrKor[2][1] = 2;
                PoleComp.AdrKor[3][1] = 3;
                PoleComp.AdrKor[0][2] = 7;
                PoleComp.AdrKor[1][2] = 4;
                PoleComp.AdrKor[2][2] = 2;
                PoleComp.AdrKor[3][2] = 3;
                PoleComp.AdrKor[0][5] = 7;
                PoleComp.AdrKor[1][5] = 8;
                PoleComp.AdrKor[2][5] = 2;
                PoleComp.AdrKor[3][5] = 2;
            } else if (j == 1){
                PoleComp.AdrKor[0][1] = 7;
                PoleComp.AdrKor[1][1] = 0;
                PoleComp.AdrKor[2][1] = 2;
                PoleComp.AdrKor[3][1] = 3;
                PoleComp.AdrKor[0][5] = 7;
                PoleComp.AdrKor[1][5] = 4;
                PoleComp.AdrKor[2][5] = 2;
                PoleComp.AdrKor[3][5] = 2;
                PoleComp.AdrKor[0][2] = 7;
                PoleComp.AdrKor[1][2] = 7;
                PoleComp.AdrKor[2][2] = 2;
                PoleComp.AdrKor[3][2] = 3;
            } else {
                PoleComp.AdrKor[0][5] = 7;
                PoleComp.AdrKor[1][5] = 0;
                PoleComp.AdrKor[2][5] = 2;
                PoleComp.AdrKor[3][5] = 2;
                PoleComp.AdrKor[0][1] = 7;
                PoleComp.AdrKor[1][1] = 3;
                PoleComp.AdrKor[2][1] = 2;
                PoleComp.AdrKor[3][1] = 3;
                PoleComp.AdrKor[0][2] = 7;
                PoleComp.AdrKor[1][2] = 7;
                PoleComp.AdrKor[2][2] = 2;
                PoleComp.AdrKor[3][2] = 3;
            }
            for (int i = 0; i < 10; i++){
                PoleComp.pole[9][i] = m[l][i];
                PoleComp.pole[7][i] = f[j][i];
            }
        }
    } else {
        pointHardThird();
    }
    for (int i = 6; i < 10; i++){
        int row, col;
        do{
            do{
                row = rand_r(&seed) % 10;
            }while (row + 1 > 10);
            col = rand_r(&seed) % 10;
        }while (!poiskAdresa(row, col, 1, 1, 2));
        pointKor(row, col, 1, 1, 2);
        PoleComp.AdrKor[0][i] = row;
        PoleComp.AdrKor[1][i] = col;
        PoleComp.AdrKor[2][i] = 1;
        PoleComp.AdrKor[3][i] = 1;
    }
}

void pointKorablPC(int pal, int colum){
    if (pal == 0){
            return;
    }
    for (int j = 1; j <= colum; j++){
        int row = 0, col = 0;
        int polog = 1 + rand_r(&seed) % 2;
        if (polog == 1){
            do{
                do{
                    row = rand_r(&seed) % 10;
                }while (row + pal > 10);
                col = rand_r(&seed) % 10;
            }while (!poiskAdresa(row, col, pal, polog, 2));
        } else {
            do{
                do{
                    col = rand_r(&seed) % 10;
                }while(col + pal > 10);
                row = rand_r(&seed) % 10;
            }while (!poiskAdresa(row, col, pal, polog, 2));
        }
        switch (polog){
        case 1:
            pointKor(row, col, pal, polog, 2);
            if (pal == 4){
                PoleComp.AdrKor[0][0] = row;
                PoleComp.AdrKor[1][0] = col;
                PoleComp.AdrKor[2][0] = 1;
                PoleComp.AdrKor[3][0] = pal;
            }else if (pal == 3 && j == 1){
                PoleComp.AdrKor[0][1] = row;
                PoleComp.AdrKor[1][1] = col;
                PoleComp.AdrKor[2][1] = 1;
                PoleComp.AdrKor[3][1] = pal;
            }else if (pal == 3 && j == 2){
                PoleComp.AdrKor[0][2] = row;
                PoleComp.AdrKor[1][2] = col;
                PoleComp.AdrKor[2][2] = 1;
                PoleComp.AdrKor[3][2] = pal;
            }else if (pal == 2 && j == 1){
                PoleComp.AdrKor[0][3] = row;
                PoleComp.AdrKor[1][3] = col;
                PoleComp.AdrKor[2][3] = 1;
                PoleComp.AdrKor[3][3] = pal;
            }else if (pal == 2 && j == 2){
                PoleComp.AdrKor[0][4] = row;
                PoleComp.AdrKor[1][4] = col;
                PoleComp.AdrKor[2][4] = 1;
                PoleComp.AdrKor[3][4] = pal;
            }else if (pal == 2 && j == 3){
                PoleComp.AdrKor[0][5] = row;
                PoleComp.AdrKor[1][5] = col;
                PoleComp.AdrKor[2][5] = 1;
                PoleComp.AdrKor[3][5] = pal;
            }else if (pal == 1){
                if (j == 1) {
                    PoleComp.AdrKor[0][6] = row;
                    PoleComp.AdrKor[1][6] = col;
                    PoleComp.AdrKor[2][6] = 1;
                    PoleComp.AdrKor[3][6] = pal;
                }else if (j == 2) {
                    PoleComp.AdrKor[0][7] = row;
                    PoleComp.AdrKor[1][7] = col;
                    PoleComp.AdrKor[2][7] = 1;
                    PoleComp.AdrKor[3][7] = pal;
                }else if (j == 3) {
                    PoleComp.AdrKor[0][8] = row;
                    PoleComp.AdrKor[1][8] = col;
                    PoleComp.AdrKor[2][8] = 1;
                    PoleComp.AdrKor[3][8] = pal;
                }else {
                    PoleComp.AdrKor[0][9] = row;
                    PoleComp.AdrKor[1][9] = col;
                    PoleComp.AdrKor[2][9] = 1;
                    PoleComp.AdrKor[3][9] = pal;
                }
            }
            break;
        case 2:
            pointKor(row, col, pal, polog, 2);
            if (pal == 4){
                PoleComp.AdrKor[0][0] = row;
                PoleComp.AdrKor[1][0] = col;
                PoleComp.AdrKor[2][0] = 2;
                PoleComp.AdrKor[3][0] = pal;
            }else if (pal == 3 && j == 1){
                PoleComp.AdrKor[0][1] = row;
                PoleComp.AdrKor[1][1] = col;
                PoleComp.AdrKor[2][1] = 2;
                PoleComp.AdrKor[3][1] = pal;
            }else if (pal == 3 && j == 2){
                PoleComp.AdrKor[0][2] = row;
                PoleComp.AdrKor[1][2] = col;
                PoleComp.AdrKor[2][2] = 2;
                PoleComp.AdrKor[3][2] = pal;
            }else if (pal == 2 && j == 1){
                PoleComp.AdrKor[0][3] = row;
                PoleComp.AdrKor[1][3] = col;
                PoleComp.AdrKor[2][3] = 2;
                PoleComp.AdrKor[3][3] = pal;
            }else if (pal == 2 && j == 2){
                PoleComp.AdrKor[0][4] = row;
                PoleComp.AdrKor[1][4] = col;
                PoleComp.AdrKor[2][4] = 2;
                PoleComp.AdrKor[3][4] = pal;
            }else if (pal == 2 && j == 3){
                PoleComp.AdrKor[0][5] = row;
                PoleComp.AdrKor[1][5] = col;
                PoleComp.AdrKor[2][5] = 2;
                PoleComp.AdrKor[3][5] = pal;
            }else if (pal == 1){
                if (j == 1) {
                    PoleComp.AdrKor[0][6] = row;
                    PoleComp.AdrKor[1][6] = col;
                    PoleComp.AdrKor[2][6] = 2;
                    PoleComp.AdrKor[3][6] = pal;
                }else if (j == 2) {
                    PoleComp.AdrKor[0][7] = row;
                    PoleComp.AdrKor[1][7] = col;
                    PoleComp.AdrKor[2][7] = 2;
                    PoleComp.AdrKor[3][7] = pal;
                }else if (j == 3) {
                    PoleComp.AdrKor[0][8] = row;
                    PoleComp.AdrKor[1][8] = col;
                    PoleComp.AdrKor[2][8] = 2;
                    PoleComp.AdrKor[3][8] = pal;
                }else {
                    PoleComp.AdrKor[0][9] = row;
                    PoleComp.AdrKor[1][9] = col;
                    PoleComp.AdrKor[2][9] = 2;
                    PoleComp.AdrKor[3][9] = pal;
                }
            }
            break;
        }
    }
    pointKorablPC(pal-1, colum+1);
}

void pointKorabl(int pal, int colum){
    if (pal == 0)
        return;
    for (int j = 1; j <= colum; j++){
        int row, col;
        int polog = 1 + rand_r(&seed) % 2;
        if (polog == 1){
            do{
                do{
                    row = rand_r(&seed) % 10;
                }while (row + pal > 10);
                col = rand_r(&seed) % 10;
            }while (!poiskAdresa(row, col, pal, polog, 1));
        } else {
            do{
                do{
                    col = rand_r(&seed) % 10;
                }while(col + pal > 10);
                row = rand_r(&seed) % 10;
            }while (!poiskAdresa(row, col, pal, polog, 1));
        }
        switch (polog){
        case 1:
            pointKor(row, col, pal, polog, 1);
            if (pal == 4){
                PoleIgroka.AdrKor[0][0] = row;
                PoleIgroka.AdrKor[1][0] = col;
                PoleIgroka.AdrKor[2][0] = 1;
                PoleIgroka.AdrKor[3][0] = pal;
            }else if (pal == 3 && j == 1){
                PoleIgroka.AdrKor[0][1] = row;
                PoleIgroka.AdrKor[1][1] = col;
                PoleIgroka.AdrKor[2][1] = 1;
                PoleIgroka.AdrKor[3][1] = pal;
            }else if (pal == 3 && j == 2){
                PoleIgroka.AdrKor[0][2] = row;
                PoleIgroka.AdrKor[1][2] = col;
                PoleIgroka.AdrKor[2][2] = 1;
                PoleIgroka.AdrKor[3][2] = pal;
            }else if (pal == 2 && j == 1){
                PoleIgroka.AdrKor[0][3] = row;
                PoleIgroka.AdrKor[1][3] = col;
                PoleIgroka.AdrKor[2][3] = 1;
                PoleIgroka.AdrKor[3][3] = pal;
            }else if (pal == 2 && j == 2){
                PoleIgroka.AdrKor[0][4] = row;
                PoleIgroka.AdrKor[1][4] = col;
                PoleIgroka.AdrKor[2][4] = 1;
                PoleIgroka.AdrKor[3][4] = pal;
            }else if (pal == 2 && j == 3){
                PoleIgroka.AdrKor[0][5] = row;
                PoleIgroka.AdrKor[1][5] = col;
                PoleIgroka.AdrKor[2][5] = 1;
                PoleIgroka.AdrKor[3][5] = pal;
            }else if (pal == 1){
                if (j == 1) {
                    PoleIgroka.AdrKor[0][6] = row;
                    PoleIgroka.AdrKor[1][6] = col;
                    PoleIgroka.AdrKor[2][6] = 1;
                    PoleIgroka.AdrKor[3][6] = pal;
                }else if (j == 2) {
                    PoleIgroka.AdrKor[0][7] = row;
                    PoleIgroka.AdrKor[1][7] = col;
                    PoleIgroka.AdrKor[2][7] = 1;
                    PoleIgroka.AdrKor[3][7] = pal;
                }else if (j == 3) {
                    PoleIgroka.AdrKor[0][8] = row;
                    PoleIgroka.AdrKor[1][8] = col;
                    PoleIgroka.AdrKor[2][8] = 1;
                    PoleIgroka.AdrKor[3][8] = pal;
                }else {
                    PoleIgroka.AdrKor[0][9] = row;
                    PoleIgroka.AdrKor[1][9] = col;
                    PoleIgroka.AdrKor[2][9] = 1;
                    PoleIgroka.AdrKor[3][9] = pal;
                }
            }
            break;
        case 2:
            pointKor(row, col, pal, polog, 1);
            if (pal == 4){
                PoleIgroka.AdrKor[0][0] = row;
                PoleIgroka.AdrKor[1][0] = col;
                PoleIgroka.AdrKor[2][0] = 2;
                PoleIgroka.AdrKor[3][0] = pal;
            }else if (pal == 3 && j == 1){
                PoleIgroka.AdrKor[0][1] = row;
                PoleIgroka.AdrKor[1][1] = col;
                PoleIgroka.AdrKor[2][1] = 2;
                PoleIgroka.AdrKor[3][1] = pal;
            }else if (pal == 3 && j == 2){
                PoleIgroka.AdrKor[0][2] = row;
                PoleIgroka.AdrKor[1][2] = col;
                PoleIgroka.AdrKor[2][2] = 2;
                PoleIgroka.AdrKor[3][2] = pal;
            }else if (pal == 2 && j == 1){
                PoleIgroka.AdrKor[0][3] = row;
                PoleIgroka.AdrKor[1][3] = col;
                PoleIgroka.AdrKor[2][3] = 2;
                PoleIgroka.AdrKor[3][3] = pal;
            }else if (pal == 2 && j == 2){
                PoleIgroka.AdrKor[0][4] = row;
                PoleIgroka.AdrKor[1][4] = col;
                PoleIgroka.AdrKor[2][4] = 2;
                PoleIgroka.AdrKor[3][4] = pal;
            }else if (pal == 2 && j == 3){
                PoleIgroka.AdrKor[0][5] = row;
                PoleIgroka.AdrKor[1][5] = col;
                PoleIgroka.AdrKor[2][5] = 2;
                PoleIgroka.AdrKor[3][5] = pal;
            }else if (pal == 1){
                if (j == 1) {
                    PoleIgroka.AdrKor[0][6] = row;
                    PoleIgroka.AdrKor[1][6] = col;
                    PoleIgroka.AdrKor[2][6] = 2;
                    PoleIgroka.AdrKor[3][6] = pal;
                }else if (j == 2) {
                    PoleIgroka.AdrKor[0][7] = row;
                    PoleIgroka.AdrKor[1][7] = col;
                    PoleIgroka.AdrKor[2][7] = 2;
                    PoleIgroka.AdrKor[3][7] = pal;
                }else if (j == 3) {
                    PoleIgroka.AdrKor[0][8] = row;
                    PoleIgroka.AdrKor[1][8] = col;
                    PoleIgroka.AdrKor[2][8] = 2;
                    PoleIgroka.AdrKor[3][8] = pal;
                }else {
                    PoleIgroka.AdrKor[0][9] = row;
                    PoleIgroka.AdrKor[1][9] = col;
                    PoleIgroka.AdrKor[2][9] = 2;
                    PoleIgroka.AdrKor[3][9] = pal;
                }
            }
            break;
        }
    }
    pointKorabl(pal-1, colum+1);
}

int find_korPC(int x, int y){
    int status = 1;
    int kor = -1;
    if (x > 0 && PoleComp.pole[x][y] == 1){
        if (PoleComp.pole[x - 1][y] == 1){
            x--;
            if (x > 0){
                if (PoleComp.pole[x - 1][y] == 1) x--;
            }
            if (x > 0){
                if (PoleComp.pole[x - 1][y] == 1) x--;
            }
        } else if (y > 0){
            if (PoleComp.pole[x][y - 1] == 1){
                y--;
                if (y > 0){
                    if (PoleComp.pole[x][y - 1] == 1) y--;
                }
                if (y > 0){
                    if (PoleComp.pole[x][y - 1] == 1) y--;
                }
            }
        }
    } else if (y > 0 && PoleComp.pole[x][y] == 1){
        if (PoleComp.pole[x][y - 1] == 1){
            y--;
            if (y > 0){
                if (PoleComp.pole[x][y - 1] == 1) y--;
            }
            if (y > 0){
                if (PoleComp.pole[x][y - 1] == 1) y--;
            }
        }
    }
    for (int i = 0; i < 10; i++){
        if (PoleComp.AdrKor[0][i] == x && PoleComp.AdrKor[1][i] == y){
            kor = i;
        }
    }
    if (PoleComp.AdrKor[4][kor] == 1) status = 2;
    if (PoleComp.AdrKor[4][kor] == 2) status = 3;
    if (status == 3){
        if (PoleComp.AdrKor[2][kor] == 1){//вертикаль
            int x1 = PoleComp.AdrKor[0][kor];
            int y1 = PoleComp.AdrKor[1][kor];
            for (int i = 0; i < PoleComp.AdrKor[3][kor]; i++){
                PoleIgroka.shots[x1 + i][y1] = 3;
            }
            int s1 = 0;
            int s2 = PoleComp.AdrKor[3][kor];
            if (x1 > 0) {
                PoleIgroka.shots[x1 - 1][y1] = 4;
                s1--;
            }
            if (x1 + PoleComp.AdrKor[3][kor] - 1 < 9) {
                PoleIgroka.shots[x1 + PoleComp.AdrKor[3][kor]][y1] = 4;
                s2++;
            }
            for (int i = s1; i < s2; i++){
                if (y1 > 0){
                    PoleIgroka.shots[x1 + i][y1 - 1] = 4;
                }
                if (y1 < 9){
                    PoleIgroka.shots[x1 + i][y1 + 1] = 4;
                }
            }
        } else if (PoleComp.AdrKor[2][kor] == 2){//горизонталь
            int x1 = PoleComp.AdrKor[0][kor];
            int y1 = PoleComp.AdrKor[1][kor];
            for (int i = 0; i < PoleComp.AdrKor[3][kor]; i++){
                PoleIgroka.shots[x1][y1 + i] = 3;
            }
            int s1 = 0;
            int s2 = PoleComp.AdrKor[3][kor];
            if (y1 > 0){
                PoleIgroka.shots[x1][y1 - 1] = 4;
                s1--;
            }
            if (y1 + PoleComp.AdrKor[3][kor] - 1 < 9){
                PoleIgroka.shots[x1][y1 + PoleComp.AdrKor[3][kor]] = 4;
                s2++;
            }
            for (int i = s1; i < s2; i++){
                if (x1 > 0){
                    PoleIgroka.shots[x - 1][y + i] = 4;
                }
                if (x1 < 9){
                    PoleIgroka.shots[x + 1][y + i] = 4;
                }
            }
        }
    }
    return status;
}

int find_korIg(int x, int y){
    int status = 1;
    if (PoleIgroka.pole[x][y] == 0) return status;
    int kor = -1;
    if (x > 0){
        if (PoleIgroka.pole[x - 1][y] == 1){
            x--;
            if (x > 0){
                if (PoleIgroka.pole[x - 1][y] == 1) x--;
            }
            if (x > 0){
                if (PoleIgroka.pole[x - 1][y] == 1) x--;
            }
        } else if (y > 0){
            if (PoleIgroka.pole[x][y - 1] == 1){
                x--;
                if (y > 0){
                    if (PoleIgroka.pole[x][y - 1] == 1) y--;
                }
                if (y > 0){
                    if (PoleIgroka.pole[x][y - 1] == 1) y--;
                }
            }
        }
    } else if (y > 0){
        if (PoleIgroka.pole[x][y - 1] == 1){
            y--;
            if (y > 0){
                if (PoleIgroka.pole[x][y - 1] == 1) y--;
            }
            if (y > 0){
                if (PoleIgroka.pole[x][y - 1] == 1) y--;
            }
        }
    }
    for (int i = 0; i < 10; i++){
        if (PoleIgroka.AdrKor[0][i] == x && PoleIgroka.AdrKor[1][i] == y){
            kor = i;
        }
    }
    if (PoleIgroka.AdrKor[4][kor] == 2) status = 3;
    if (PoleIgroka.AdrKor[4][kor] == 1) status = 2;
    if (status == 3){
        if (PoleIgroka.AdrKor[2][kor] == 1){
            int x1 = PoleIgroka.AdrKor[0][kor];
            int y1 = PoleIgroka.AdrKor[1][kor];
            for (int i = 0; i < PoleIgroka.AdrKor[3][kor]; i++){
                PoleComp.shots[x1 + i][y1] = 3;
            }
            int s1 = 0;
            int s2 = PoleIgroka.AdrKor[3][kor];
            if (x1 > 0) {
                PoleComp.shots[x1 - 1][y1] = 4;
                s1--;
            }
            if (x1 + PoleIgroka.AdrKor[3][kor] - 1 < 9) {
                PoleComp.shots[x1 + PoleIgroka.AdrKor[3][kor]][y1] = 4;
                s2++;
            }
            for (int i = s1; i < s2; i++){
                if (y1 > 0){
                    PoleComp.shots[x1 + i][y1 - 1] = 4;
                }
                if (y1 < 9){
                    PoleComp.shots[x1 + i][y1 + 1] = 4;
                }
            }
        } else if (PoleIgroka.AdrKor[2][kor] == 2){
            int x1 = PoleIgroka.AdrKor[0][kor];
            int y1 = PoleIgroka.AdrKor[1][kor];
            for (int i = 0; i < PoleIgroka.AdrKor[3][kor]; i++){
                PoleComp.shots[x1][y1 + i] = 3;
            }
            int s1 = 0;
            int s2 = PoleIgroka.AdrKor[3][kor];
            if (y1 > 0){
                PoleComp.shots[x1][y1 - 1] = 4;
                s1--;
            }
            if (y1 + PoleIgroka.AdrKor[3][kor] - 1 < 9){
                PoleComp.shots[x1][y1 + PoleIgroka.AdrKor[3][kor]] = 4;
                s2++;
            }
            for (int i = s1; i < s2; i++){
                if (x1 > 0){
                    PoleComp.shots[x1 - 1][y1 + i] = 4;
                }
                if (x1 < 9){
                    PoleComp.shots[x1 + 1][y1 + i] = 4;
                }
            }
        }
    }
    return status;
}

int Pobeda(){
    int ig = 10, pc = 10;
    for (int j = 0; j < 10; j++){
        if (PoleIgroka.AdrKor[4][j] == 2) ig--;
        if (PoleComp.AdrKor[4][j] == 2) pc--;
    }
    if (ig == 0) return 2;
    if (pc == 0) return 1;
    else
        return 0;
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

void printpole(){
    std::cout << "   | A | B | C | D | E | F | G | H | I | J |";
    std::cout << std::setfill(' ') << std::setw(11) << " ";
    std::cout << "   | A | B | C | D | E | F | G | H | I | J |";
    std::cout << std::endl;
    std::cout << std::setfill('-') << std::setw(44) << "-";
    std::cout << std::setfill(' ') << std::setw(11) << " ";
    std::cout << std::setfill('-') << std::setw(44) << "-";
    std::cout << std::endl;
    for (int i = 0; i < 10 ; i++){
        std::cout << std::setfill(' ') << std::setw(2) << i+1;
        std::cout << " | ";
        for (int j = 0; j < 10; j++){
            if (PoleIgroka.pole[i][j] == 0) {
                if (PoleComp.shots[i][j] == 1) std::cout << "*";
                else
                    std::cout << " ";
            } else if (PoleIgroka.pole[i][j] == 1){
                if (PoleComp.shots[i][j] == 2 || PoleComp.shots[i][j] == 3)
                    std::cout << "X";
                else
                    std::cout << "1";
            }
            std::cout << " | ";
        }
        std::cout << std::setfill(' ') << std::setw(10) << " ";
        std::cout << std::setw(2) << i + 1;
        std::cout << " | ";
        for (int j = 0; j < 10; j++){
            if (PoleIgroka.shots[i][j] == 2 || PoleIgroka.shots[i][j] == 3)
                std::cout <<"X";
            else if (PoleIgroka.shots[i][j] == 1) std::cout <<"*";
            else if (PoleIgroka.shots[i][j] == 4) std::cout <<".";
            else if (PoleIgroka.shots[i][j] == 0) std::cout <<" ";
            std::cout <<" | ";
        }
        std::cout <<std::endl;
        std::cout <<std::setfill('-') <<std::setw(44) <<"-";
        std::cout <<std::setfill(' ') <<std::setw(11) <<" ";
        std::cout <<std::setfill('-') <<std::setw(44) <<"-" <<std::endl;
    }
}

void HodPC();

void HodIgroka(){
    if (Pobeda() != 0){
        if (Pobeda() == 1) std::cout <<"Вы выиграли! Поздравляю!";
        if (Pobeda() == 2) std::cout <<"К сожалению, выиграл компьютер."
            << " Не расстраивайте, вы можете взять реванш!";
        return;
    }
    int status = 1;
    int x = -1, y = -1;
    printpole();
    do{
        char y1;
        std::cout << "Ваш ход. \n Введите координаты выстрела: ";
        std::cin >> y1 >> x;
        y = read(y1);
        if (x >= 1 && x <= 10 && y >= 1 && y <= 10){
            if (PoleIgroka.shots[x - 1][y - 1] != 0) {
                std::cout << "Вы уже стреляли по этим координатам"
                << std::endl;
                x = -1;
                y = -1;
            }
        }
        if (x < 0 || y < 0 || x > 10 || y > 10){
            x = -1;
            y = -1;
            std::cout << "\n Вы ввели неверные координаты. \n";
        }
    }while(x == -1 || y == -1 || x > 10 || y > 10);
    if (PoleComp.pole[x - 1][y - 1] == 1) PoleIgroka.shots[x - 1][y - 1] = 2;
    else if (PoleComp.pole[x - 1][y - 1] == 0)
        PoleIgroka.shots[x - 1][y - 1] = 1;
    kill_or_not(PoleComp, PoleIgroka);
    if (PoleComp.pole[x - 1][y - 1] == 1) status = find_korPC(x - 1, y - 1);
    if (status == 1){
        std::cout << "Мимо" << std::endl;
        HodPC();
    } else if (status == 2){
        std::cout << "Корабль ранен" << std::endl;
        HodIgroka();
    } else if (status == 3){
        std::cout << "Корабль потоплен" << std::endl;
        HodIgroka();
    }
}

void pr(int y){
    switch (y){
        case 0:
            std::cout << 'A';
            break;
        case 1:
            std::cout << 'B';
            break;
        case 2:
            std::cout << 'C';
            break;
        case 3:
            std::cout << 'D';
            break;
        case 4:
            std::cout << 'E';
            break;
        case 5:
            std::cout << 'F';
            break;
        case 6:
            std::cout << 'G';
            break;
        case 7:
            std::cout << 'H';
            break;
        case 8:
            std::cout << 'I';
            break;
        case 9:
            std::cout << 'J';
            break;
    }
}

int HodPCFirst(int x, int y){
    x--;
    if (x > 0){
        if (PoleComp.shots[x - 1][y] == 2) x--;
    }
    if (x > 0){
        if (PoleComp.shots[x - 1][y] == 0){
            x--;
            if (PoleIgroka.pole[x][y] == 1)
                PoleComp.shots[x][y] = 2;
            else
                PoleComp.shots[x][y] = 1;
        } else {
            while (PoleComp.shots[x][y] == 2) x++;
            if (PoleIgroka.pole[x][y] == 1)
                PoleComp.shots[x][y] = 2;
            else
                PoleComp.shots[x][y] = 1;
        }
    } else {
        while (PoleComp.shots[x][y] == 2) x++;
        if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
        else
            PoleComp.shots[x][y] = 1;
    }
    return x;
}

void HodPC(){
    if (Pobeda() != 0){
        if (Pobeda() == 1) std::cout << "Вы выиграли! Поздравляю!";
        if (Pobeda() == 2) std::cout << "К сожалению, выиграл компьютер."
            << " Не расстраивайте, вы можете взять реванш!";
        return;
    }
    std::cout << "Mой черёд! \n";
    int x = -1, y = -1;
    int hurt[2][10];
    for (int i = 0; i < 10; i++) hurt[0][i] = -1;
    for (int i = 0; i < 10; i++) hurt[1][i] = -1;
    int k = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (PoleComp.shots[i][j] == 2){
                hurt[0][k] = i;
                hurt[1][k] = j;
                k++;
            }
        }
    }
    if (hurt[0][0] != -1 && hurt[1][0] != -1){
        x = hurt[0][0];
        y = hurt[1][0];
    }
    int status = 1;
    if (x != -1 && y != -1){
        if (x == 0){
            if (y == 0){
                if (PoleComp.shots[x + 1][y] == 0 &&
                    PoleComp.shots[x][y + 1] != 2){
                    if (PoleIgroka.pole[x + 1][y] == 1)
                        PoleComp.shots[x + 1][y] = 2;
                    else
                        PoleComp.shots[x + 1][y] = 1;
                    x++;
                } else if (PoleComp.shots[x + 1][y] == 2){
                    x++;
                    if (PoleComp.shots[x + 1][y] == 2){
                        x++;
                    }
                    x++;
                    if (PoleIgroka.pole[x][y] == 1)
                        PoleComp.shots[x][y] = 2;
                    else
                        PoleComp.shots[x][y] = 1;
                } else if (PoleComp.shots[x][y + 1] == 0 &&
                           PoleComp.shots[x + 1][y] != 2){
                    if (PoleIgroka.pole[x][y + 1] == 1)
                        PoleComp.shots[x][y + 1] = 2;
                    else
                        PoleComp.shots[x][y + 1] = 1;
                    y++;
                } else if (PoleComp.shots[x][y + 1] == 2){
                    y++;
                    if (PoleComp.shots[x][y + 1] == 2) y++;
                    y++;
                    if (PoleIgroka.pole[x][y] == 1)
                        PoleComp.shots[x][y] = 2;
                    else
                        PoleComp.shots[x][y] = 1;
                }
            } else if (y == 9){
                if (PoleComp.shots[x + 1][y] == 0 &&
                    PoleComp.shots[x][y - 1] != 2){
                    if (PoleIgroka.pole[x + 1][y] == 1)
                        PoleComp.shots[x + 1][y] = 2;
                    else
                        PoleComp.shots[x + 1][y] = 1;
                    x++;
                } else if (PoleComp.shots[x + 1][y] == 2){
                    x++;
                    if (PoleComp.shots[x + 1][y] == 2){
                        x++;
                    }
                    x++;
                    if (PoleIgroka.pole[x][y] == 1)
                        PoleComp.shots[x][y] = 2;
                    else
                        PoleComp.shots[x][y] = 1;
                } else if (PoleComp.shots[x][y - 1] == 0 &&
                           PoleComp.shots[x + 1][y] != 2){
                    if (PoleIgroka.pole[x][y - 1] == 1)
                        PoleComp.shots[x][y - 1] = 2;
                    else
                        PoleComp.shots[x][y - 1] = 1;
                    y--;
                } else if (PoleComp.shots[x][y - 1] == 2){
                    y--;
                    if (PoleComp.shots[x][y - 1] == 2) y--;
                    y--;
                    if (PoleIgroka.pole[x][y] == 1)
                        PoleComp.shots[x][y] = 2;
                    else
                        PoleComp.shots[x][y] = 1;
                }
            } else if (PoleComp.shots[x][y - 1] == 0 &&
                       PoleComp.shots[x + 1][y] != 2){
                if (PoleIgroka.pole[x][y - 1] == 1)
                    PoleComp.shots[x][y - 1] = 2;
                else
                    PoleComp.shots[x][y - 1] = 1;
                y--;
            } else if (PoleComp.shots[x][y - 1] == 2){
                y--;
                if (y > 0){
                    if (PoleComp.shots[x][y - 1] == 2) y--;
                }
                if (y > 0) {
                    if (PoleComp.shots[x][y - 1] == 0){
                        y--;
                        if (PoleIgroka.pole[x][y] == 1)
                            PoleComp.shots[x][y] = 2;
                        else
                            PoleComp.shots[x][y] = 1;
                    } else if (PoleComp.shots[x][y - 1] == 1){
                            if (PoleComp.shots[x][y + 1] == 2) y++;
                        if (y < 9){
                            if (PoleComp.shots[x][y + 1] == 2) y++;
                        }
                        y++;
                        if (PoleIgroka.pole[x][y] == 1)
                            PoleComp.shots[x][y] = 2;
                        else
                            PoleComp.shots[x][y] = 1;
                    }
                } else {
                    while (PoleComp.shots[x][y] == 2) y++;
                    if (PoleIgroka.pole[x][y] == 1)
                        PoleComp.shots[x][y] = 2;
                    else
                        PoleComp.shots[x][y] = 1;
                }
            } else if (PoleComp.shots[x][y - 1] == 1 &&
                       PoleComp.shots[x][y + 1] == 1){
                if (PoleComp.shots[x + 1][y] == 2) x++;
                if (PoleComp.shots[x + 1][y] == 2) x++;
                x++;
                if (PoleIgroka.pole[x][y] == 1)
                    PoleComp.shots[x][y] = 2;
                else
                    PoleComp.shots[x][y] = 1;
            } else if (PoleComp.shots[x][y - 1] == 1 &&
                       PoleComp.shots[x + 1][y] != 2){
                if (PoleComp.shots[x][y + 1] == 2) y++;
                if (y < 9) {
                    if (PoleComp.shots[x][y + 1] == 2) y++;
                }
                y++;
                if (PoleIgroka.pole[x][y] == 1)
                    PoleComp.shots[x][y] = 2;
                else
                    PoleComp.shots[x][y] = 1;
            } else if (PoleComp.shots[x + 1][y] == 2){
                x++;
                if (PoleComp.shots[x + 1][y] == 2) x++;
                x++;
                if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
                else
                    PoleComp.shots[x][y] = 1;
            } else if (PoleComp.shots[x + 1][y] == 0){
                x++;
                if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
                else
                    PoleComp.shots[x][y] = 1;
            }
        } else if (x == 9){
            if (y == 0){
                if (PoleComp.shots[x - 1][y] == 0 &&
                    PoleComp.shots[x][y + 1] != 2){
                    x--;
                    if (PoleIgroka.pole[x][y] == 1)
                        PoleComp.shots[x][y] = 2;
                    else
                        PoleComp.shots[x][y] = 1;
                } else if (PoleComp.shots[x - 1][y] == 2){
                    x--;
                    if (PoleComp.shots[x - 1][y] == 2){
                        x--;
                    }
                    x--;
                    if (PoleIgroka.pole[x][y] == 1)
                        PoleComp.shots[x][y] = 2;
                    else
                        PoleComp.shots[x][y] = 1;
                } else if (PoleComp.shots[x][y + 1] == 0){
                    y++;
                    if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
                    else
                        PoleComp.shots[x][y] = 1;
                } else if (PoleComp.shots[x][y + 1] == 2){
                    y++;
                    if (PoleComp.shots[x][y + 1] == 2) y++;
                    y++;
                    if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
                    else
                        PoleComp.shots[x][y] = 1;
                }
            } else if (y == 9){
                if (PoleComp.shots[x - 1][y] == 0 &&
                    PoleComp.shots[x][y - 1] != 2){
                    x--;
                    if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
                    else
                        PoleComp.shots[x][y] = 1;
                } else if (PoleComp.shots[x - 1][y] == 2){
                    x--;
                    if (PoleComp.shots[x - 1][y] == 2){
                        x--;
                    }
                    x--;
                    if (PoleIgroka.pole[x][y] == 1)
                        PoleComp.shots[x][y] = 2;
                    else
                        PoleComp.shots[x][y] = 1;
                } else if (PoleComp.shots[x][y - 1] == 0){
                    y--;
                    if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
                    else
                        PoleComp.shots[x][y] = 1;
                } else if (PoleComp.shots[x][y - 1] == 2){
                    y--;
                    if (PoleComp.shots[x][y - 1] == 2) y--;
                    y--;
                    if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
                    else
                        PoleComp.shots[x][y] = 1;
                }
            } else {
                if (PoleComp.shots[x][y - 1] == 0 &&
                    PoleComp.shots[x - 1][y] != 2){
                    y--;
                    if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
                    else
                        PoleComp.shots[x][y] = 1;
                } else if (PoleComp.shots[x][y - 1] == 2){
                    y--;
                    if (y > 0){
                        if (PoleComp.shots[x][y - 1] == 2) y--;
                    }
                    if (y > 0){
                        if (PoleComp.shots[x][y - 1] == 0){
                            y--;
                            if (PoleIgroka.pole[x][y] == 1)
                                PoleComp.shots[x][y] = 2;
                            else
                                PoleComp.shots[x][y] = 1;
                        } else {
                            if (y < 9){
                                if (PoleComp.shots[x][y + 1] == 2) y++;
                            }
                            if (y < 9){
                                if (PoleComp.shots[x][y + 1] == 2) y++;
                            }
                            y++;
                            if (PoleIgroka.pole[x][y] == 1)
                                PoleComp.shots[x][y] = 2;
                            else
                                PoleComp.shots[x][y] = 1;
                        }
                    } else {
                        while (PoleComp.shots[x][y] == 2) y++;
                        if (PoleIgroka.pole[x][y] == 1)
                            PoleComp.shots[x][y] = 2;
                        else
                            PoleComp.shots[x][y] = 1;
                    }
                } else if (PoleComp.shots[x][y - 1] == 1 &&
                           PoleComp.shots[x][y + 1] == 1){
                    if (PoleComp.shots[x - 1][y] == 2) x--;
                    if (PoleComp.shots[x - 1][y] == 2) x--;
                    x--;
                    if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
                    else
                        PoleComp.shots[x][y] = 1;
                } else if (PoleComp.shots[x][y - 1] == 1 &&
                           PoleComp.shots[x - 1][y] != 2){
                    if (PoleComp.shots[x][y + 1] == 2) y++;
                    if (y < 9) {
                        if (PoleComp.shots[x][y + 1] == 2) y++;
                    }
                    y++;
                    if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
                    else
                        PoleComp.shots[x][y] = 1;
                } else if (PoleComp.shots[x - 1][y] == 2){
                    x--;
                    if (PoleComp.shots[x - 1][y] == 2) x--;
                    x--;
                    if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
                    else
                        PoleComp.shots[x][y] = 1;
                } else if (PoleComp.shots[x - 1][y] == 0){
                    x--;
                    if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
                    else
                        PoleComp.shots[x][y] = 1;
                }
            }
        } else if (y == 0 && x > 0 && x < 9){
            if (PoleComp.shots[x - 1][y] == 2){
                x = HodPCFirst(x, y);
            } else if (PoleComp.shots[x - 1][y] == 1 &&
                       PoleComp.shots[x + 1][y] == 1){
                if (PoleComp.shots[x][y + 1] == 2) y++;
                if (PoleComp.shots[x][y + 1] == 2) y++;
                y++;
                if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
                else
                    PoleComp.shots[x][y] = 1;
            } else if (PoleComp.shots[x - 1][y] == 1 &&
                       PoleComp.shots[x][y + 1] != 2){
                if (PoleComp.shots[x + 1][y] == 2) x++;
                if (x < 9){
                    if (PoleComp.shots[x + 1][y] == 2) x++;
                }
                x++;
                if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
                else
                    PoleComp.shots[x][y] = 1;
            } else if (PoleComp.shots[x - 1][y] == 0 &&
                       PoleComp.shots[x][y + 1] != 2){
                x--;
                if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
                else
                    PoleComp.shots[x][y] = 1;
            } else if (PoleComp.shots[x][y + 1] == 2){
                y++;
                if (PoleComp.shots[x][y + 1] == 2) y++;
                y++;
                if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
                else
                    PoleComp.shots[x][y] = 1;
            } else if (PoleComp.shots[x][y + 1] == 0){
                y++;
                if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
                else
                    PoleComp.shots[x][y] = 1;
            }
        } else if (y == 9 && x > 0 && x < 9){
            if (PoleComp.shots[x - 1][y] == 2){
                x = HodPCFirst(x, y);
            } else if (PoleComp.shots[x - 1][y] == 1 &&
                       PoleComp.shots[x + 1][y] == 1){
                if (PoleComp.shots[x][y - 1] == 2) y--;
                if (PoleComp.shots[x][y - 1] == 2) y--;
                y--;
                if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
                else
                    PoleComp.shots[x][y] = 1;
            } else if (PoleComp.shots[x - 1][y] == 1 &&
                       PoleComp.shots[x][y - 1] != 2){
                if (PoleComp.shots[x + 1][y] == 2) x++;
                if (x < 9){
                    if (PoleComp.shots[x + 1][y] == 2) x++;
                }
                x++;
                if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
                else
                    PoleComp.shots[x][y] = 1;
            } else if (PoleComp.shots[x - 1][y] == 0 &&
                       PoleComp.shots[x][y - 1] != 2){
                x--;
                if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
                else
                    PoleComp.shots[x][y] = 1;
            } else if (PoleComp.shots[x][y - 1] == 2){
                y--;
                if (PoleComp.shots[x][y - 1] == 2) y--;
                y--;
                if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
                else
                    PoleComp.shots[x][y] = 1;
            } else if (PoleComp.shots[x][y - 1] == 0){
                y--;
                if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
                else
                    PoleComp.shots[x][y] = 1;
            }
        } else {
            if (PoleComp.shots[x][y - 1] != 2 &&
                PoleComp.shots[x][y + 1] != 2 &&
                !((PoleComp.shots[x - 1][y] == 1 ||
                   PoleComp.shots[x - 1][y] == 4)
                  && (PoleComp.shots[x + 1][y] == 1 ||
                      PoleComp.shots[x + 1][y] == 4))){
                if (PoleComp.shots[x - 1][y] == 2){
                    x--;
                    if (x > 0){
                        if (PoleComp.shots[x - 1][y] == 2) x--;
                    }
                    if (x > 0){
                        if (PoleComp.shots[x - 1][y] == 0){
                            x--;
                            if (PoleIgroka.pole[x][y] == 1)
                                PoleComp.shots[x][y] = 2;
                            else
                                PoleComp.shots[x][y] = 1;
                        } else {
                            while (PoleComp.shots[x][y] == 2) x++;
                            if (PoleIgroka.pole[x][y] == 1)
                                PoleComp.shots[x][y] = 2;
                            else
                                PoleComp.shots[x][y] = 1;
                        }
                    } else {
                        while (PoleComp.shots[x][y] == 2) x++;
                        if (PoleIgroka.pole[x][y] == 1)
                            PoleComp.shots[x][y] = 2;
                        else
                            PoleComp.shots[x][y] = 1;
                    }
                } else if (PoleComp.shots[x - 1][y] == 0){
                    x--;
                    if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
                    else
                        PoleComp.shots[x][y] = 1;
                } else {
                    while (PoleComp.shots[x][y] == 2) x++;
                    if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
                    else
                        PoleComp.shots[x][y] = 1;
                }
            } else {
                if (PoleComp.shots[x][y - 1] == 2){
                    y--;
                    if (y > 0){
                        if (PoleComp.shots[x][y - 1] == 2) y--;
                    }
                    if (y > 0){
                        if (PoleComp.shots[x][y - 1] == 0){
                            y--;
                            if (PoleIgroka.pole[x][y] == 1)
                                PoleComp.shots[x][y] = 2;
                            else
                                PoleComp.shots[x][y] = 1;
                        } else {
                            while (PoleComp.shots[x][y] == 2) y++;
                            if (PoleIgroka.pole[x][y] == 1)
                                PoleComp.shots[x][y] = 2;
                            else
                                PoleComp.shots[x][y] = 1;
                        }
                    } else {
                        while (PoleComp.shots[x][y] == 2) y++;
                        if (PoleIgroka.pole[x][y] == 1)
                            PoleComp.shots[x][y] = 2;
                        else
                            PoleComp.shots[x][y] = 1;
                    }
                } else if (PoleComp.shots[x][y - 1] == 0){
                    y--;
                    if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
                    else
                        PoleComp.shots[x][y] = 1;
                } else {
                    while (PoleComp.shots[x][y] == 2) y++;
                    if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
                    else
                        PoleComp.shots[x][y] = 1;
                }
            }
        }
    }else {
        do{
            x = rand_r(&seed) % 10;
            y = rand_r(&seed) % 10;
        }while (PoleComp.shots[x][y] != 0);
        if (PoleIgroka.pole[x][y] == 1) PoleComp.shots[x][y] = 2;
        else
            PoleComp.shots[x][y] = 1;
    }
    std::cout << std::endl;
    pr(y);
    std::cout << " " << x + 1;
    kill_or_not(PoleIgroka, PoleComp);
    if (PoleIgroka.pole[x][y] == 1) status = find_korIg(x, y);
    if (status == 1){
        std::cout << "\n Черт, я промахнулся" << std::endl;
        HodIgroka();
    } else if (status == 2){
        std::cout << "\n Корабль ранен" << std::endl;
        HodPC();
    } else if (status == 3){
        std::cout << "\n Корабль потоплен" << std::endl;
        HodPC();
    }
}

