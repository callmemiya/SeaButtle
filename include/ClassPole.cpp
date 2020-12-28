// Copyright 2018 Your Name <your_email>

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
