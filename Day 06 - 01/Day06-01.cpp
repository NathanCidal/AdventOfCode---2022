#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
	ifstream arq;
	arq.open("input.txt", ios::in);
	if(arq.is_open() == false){ cerr << "> ERRO AO ABRIR ARQUIVO"; return 1; }

	int tamanhoC = 4;
	string str;
	getline(arq, str);
	arq.close();
	
	tamanhoC = tamanhoC - 1;
	bool diff = false;
	int pos = 0;
	char * auxiliar;
	int auxCont = 0;
	for(int i = tamanhoC;	i < str.length(); i++){

		cout << "str (I)[" << i << "]: " << str[i] << endl;

		auxiliar = new char[tamanhoC + 1];
		auxCont = 0;
		diff = true;

		//Coloca tudo nesse novoArray
		for(int j = i - tamanhoC; j < tamanhoC + i; j++){
			auxiliar[auxCont] = str[j];
			auxCont++;
		}

		//Verifica dentro do Array
		for(int j = 0; j < tamanhoC + 1; j++){

			if(diff == false){
				break;
			}
	
			cout << "Array[" << j << "]: " << auxiliar[j] << endl;
			for(int k = j + 1; k < tamanhoC+1; k++){
				cout << "K: " << str[k] << " J:" << str[j];
				if(auxiliar[j] == auxiliar[k]){
					//cout << " - E uma decepcao" << endl;
					diff = false;
					break;
				}
				cout << endl;
			}
			
		}
		delete[] auxiliar;

		if(diff == true){
			pos = i + 1;
			break;
		}
	}

	cout << "Position is: " << pos << endl;
 

	return 0;

}