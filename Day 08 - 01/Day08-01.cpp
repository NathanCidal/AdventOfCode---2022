#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
	ifstream arq;
	arq.open("input.txt", ios::in);

	if(arq.is_open() == false){ cerr << "> ERRO AO ABRIR ARQUIVO"; return 1; }

	string str;
	int map[100][100];

	//Primeiro é a linha
	//Segundo é a coluna

	int tamCol = 0, tamLin = 0;

	bool firstSize = false;
	while(getline(arq, str)){
		if(firstSize == false){
			tamCol = str.length();
			firstSize = true;
		}

		for(int x = 0; x < tamCol; x++){
			//cout << str[x] - '0' << endl;
			map[tamLin][x] = str[x] - '0';
		}
		tamLin++;
	}

	int visiveis = 0;
	bool escondido = true;

	bool escE = true;
	bool escD = true;
	bool escC = true;
	bool escB = true;

	//cout << tamCol << " " << tamLin << endl;

	for(int y = 0; y < tamLin; y++){
		for(int x = 0; x < tamCol; x++){
			if((x - 1 < 0) || (x + 1 >= tamCol) || (y - 1 < 0) || (y + 1 >= tamLin)){
				cout << map[y][x];
				visiveis++;
				continue;
			}
				
			escE = false;
			escD = false;
			escC = false;
			escB = false;
	
			for(int i = 0; i < x; i++){
				if(map[y][i] >= map[y][x]){
					escE = true;
					break;
				}
			}

			for(int i = x + 1; i < tamCol; i++){
				if(map[y][i] >= map[y][x]){
					escD = true;
					break;
				}
			}

			for(int i = 0; i < y; i++){
				if(map[i][x] >= map[y][x]){
					escC = true;
					break;
				}
			}

			for(int i = y+1; i < tamLin; i++){
				if(map[i][x] >= map[y][x]){
					escB = true;
					break;
				}
			}

			if(escB && escC && escD && escE){
				cout << "X";
				continue;
			}else{
				cout << map[y][x];
				visiveis++;
			}
		}
		cout << endl;
	}

	for(int y = 0; y < tamLin; y++){
		for(int x = 0; x < tamCol; x++){
			//cout << map[y][x];
		}
		//cout << endl;
	}

	cout << "Visiveis = " << visiveis<< endl;

	arq.close();
	return 0;	
}