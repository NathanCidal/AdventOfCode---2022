#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
	string value01str;
	string value02str;
	string value03str;
	string value04str;
	string aux;
	ifstream arq;
	arq.open("input.txt", ios::in);
	if(arq.is_open() == false){ cerr << "> ERRO AO ABRIR ARQUIVO" << endl; return 1; }

	int save = 0;
	int contador = 0;

	int v1,v2,v3,v4;

	while(getline(arq, aux)){
		for(int i = 0; i < aux.length(); i++){
			if(aux[i] == '-'){
				save = i;
				break;
			}else{
				value01str += aux[i];
			}
		}

		for(int i = save + 1; i < aux.length(); i++){
			if(aux[i] == ','){
				save = i;
				break;
			}else{
				value02str += aux[i];
			}
		}

		for(int i = save + 1; i < aux.length(); i++){
			if(aux[i] == '-'){
				save = i;
				break;
			}else{
				value03str += aux[i];
			}
		}

		for(int i = save + 1; i < aux.length(); i++){
			value04str += aux[i];
		}

		v1 = stoi(value01str);
		v2 = stoi(value02str);
		v3 = stoi(value03str);
		v4 = stoi(value04str);

		cout << v1 << " " << v2 << " " << v3 << " " << v4 << endl;

		if((v1 >= v3 && v2 <= v4) || (v3 >= v1 && v4 <= v2) ){
			contador++;
		}

		value01str = "";
		value02str = "";
		value03str = "";
		value04str = "";
	}	

	arq.close();
	cout << contador << endl;

	return 0;
}	