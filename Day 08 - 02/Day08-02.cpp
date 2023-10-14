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

	int maiorP = 0;

	int p1 = 0;
	int p2 = 0;
	int p3 = 0;
	int p4 = 0;
	int p = 0;

	cout << tamCol << " " << tamLin << endl;

	for(int y = 0; y < tamLin; y++){
		for(int x = 0; x < tamCol; x++){
			p = 1;
			p1 = 0;
			p2 = 0;
			p3 = 0;
			p4 = 0;

				for(int i = x - 1; i >= 0; i--){
					if(map[y][i] < map[y][x]){
						p1++;
					}else{
						p1++;
						break;
					}
				}
				p *= p1;
				//cout << map[y][x] << "- Esquerda : " << p1 << endl;

				for(int i = x + 1; i < tamCol; i++){
					if(map[y][i] < map[y][x]){
						p2++;
					}else{
						p2++;
						break;
					}
					
				}
				//cout << map[y][x] << "- Direita : " << p2 << endl;
				p *= p2;

				for(int	i = y - 1; i >= 0; i--){
					if(map[i][x] < map[y][x]){
						p3++;
					}else{
						p3++;
						break;
					}
				}
				//cout << map[y][x] << "- Cima: " << p3 << endl;
				p *= p3;

				for(int	i = y + 1; i < tamLin; i++){
					if(map[i][x] < map[y][x]){
						p4++;
					}else{
						p4++;
						break;
					}
				}
				//cout << map[y][x] << "- Baixo: " << p4 << endl;
				p *= p4;
				
			if(p > maiorP){
				maiorP = p;
				continue;
			}
			
		}
	}

	cout << maiorP << endl;

	for(int y = 0; y < tamLin; y++){
		for(int x = 0; x < tamCol; x++){
			//cout << map[y][x];
		}
		//cout << endl;
	}

	arq.close();
	return 0;	
}