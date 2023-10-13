#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct SuperString{
	string s;
};

int main(){

	SuperString str[9];

	for(int i = 0; i < 9; i++){
		cout << "Insira a String da Stack[" << i+1 << "]: ";
		getline(cin, str[i].s);
	}

	for(int i = 0; i < 9; i++){
		cout << i + 1 << ": " << str[i].s << endl;
	}

	string cmd;
	string trash;

	int quantidade;
	int moverDe;
	int moverPara;

	string aux;
	string removedor;

	while(true){
		cin >> cmd;
		aux = "";
		removedor = "";
		if(cmd == "move"){
			cin >> quantidade >> trash >> moverDe >> trash >> moverPara;
			moverDe -= 1;
			moverPara -= 1;

			for(int i = 0; i < quantidade; i++){
				aux += str[moverDe].s[i];
			}

			aux += str[moverPara].s;
			str[moverPara].s = aux;

			for(int i = quantidade; i < str[moverDe].s.length(); i++){
				removedor += str[moverDe].s[i];
			}	
			

			
			cout << removedor << endl;
			str[moverDe].s = removedor;
		}else{
			break;
		}
	}

		for(int i = 0; i < 9; i++){
			cout << i + 1 << ": " << str[i].s << endl;
		}

	
	

	return 0;
}