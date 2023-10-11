/*
    Advent of Code 2022 - 02.1
    @nathancidal
    11/10/2023
*/

#include <iostream>
#include <fstream>

using namespace std;

//A = Rock, B = Paper, C = Scizor
//X = Rock, Y = Paper, Z = Scizor
int vencedorComp(char p1, char p2){
    if(p1 == 'A'){
        if(p2 == 'X') return 0;
        if(p2 == 'Y') return 1;
        if(p2 == 'Z') return -1;
    }

    if(p1 == 'B'){
        if(p2 == 'X') return -1;
        if(p2 == 'Y') return 0;
        if(p2 == 'Z') return 1;
    }

    if(p1 == 'C'){
        if(p2 == 'X') return 1;
        if(p2 == 'Y') return -1;
        if(p2 == 'Z') return 0;
    }

    return 0;
}

int main(){
    ifstream arq;
    arq.open("input.txt", ios::in);
    if(arq.is_open() == false) return 1;
    char p2, p1;
    int pontos1 = 0, pontos2 = 0;
    int result = 0;

    while(arq >> p2 >> p1){
        if(p1 == 'X') pontos1 += 1;
        else if(p1 == 'Y') pontos1 += 2;
        else pontos1 += 3;

        result = vencedorComp(p2, p1);
        cout << p2 << " " << p1 << endl;
        cout << "Resultado desse Round = " << result << endl;

        if(result == 1) pontos1 += 6;
        if(result == 0) pontos1 += 3;
        if(result == -1) pontos1 += 0;
    }

    cout << pontos1 << endl;

    return 0;
}