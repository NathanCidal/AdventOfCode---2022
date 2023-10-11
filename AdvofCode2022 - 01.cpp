/*
    Advent of Code 2022 - 01
    @nathancidal
    11/10/2023
*/

#include <iostream>
#include <fstream>

using namespace std;

#define ll long long

int main(){
    int v[900];
    ifstream arq;
    arq.open("i.txt", ios::in);
    if(arq.is_open() == false) return 1;

    string aux;
    int i = 0;
    int contador = 0;
    while(getline(arq, aux)){
        if(aux.empty()){
            v[i] = contador;
            contador = 0;
            i++;
        }else{
            contador += stoi(aux);
        }
    }

    int m = 0;
    for(int j = 0; j < i; j++){
        if(v[j] > v[m]){
            m = j;
        }
    }

    cout << m << " " << v[m] << endl;
    return 0;
}