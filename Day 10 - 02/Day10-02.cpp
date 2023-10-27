#include <iostream>
#include <string>
#define ll long long

using namespace std;

int main(){
	
	string comando;
	int valor;

	ll int ciclo = 0;
	ll int registrador = 1;
	
	ll int soma = 0;
	bool jaAddNessa = false;

	int v1 = 0;
	int v2 = 0;
	int v3 = 0;

	while(true){
		cin >> comando;

		if(comando == ".") break;

		jaAddNessa = false;
		//Comando noop é só 1 ciclo

		/*		--Template--

		if((registrador == ciclo % 40) || (registrador == (ciclo+1) % 40) || (registrador == (ciclo-1) % 40)) cout << "#";
		else cout << ".";

		*/

		if(comando == "noop"){

			if((registrador == ciclo % 40) || (registrador == (ciclo+1) % 40) || (registrador == (ciclo-1) % 40)) cout << "#";
			else cout << ".";
			ciclo++;
			if(ciclo % 40 == 0) cout << endl;
		}
		
		//Comando addx é 2 ciclos que ocorre nele
		if(comando == "addx"){
			cin >> valor;

			for(int i = 0; i < 2; i++){
				if((registrador == ciclo % 40) || (registrador == (ciclo+1) % 40) || (registrador == (ciclo-1) % 40)) cout << "#";
				else cout << ".";	
				ciclo++;
				if(ciclo % 40 == 0) cout << endl;
			}

			registrador += valor;
		}
	}

	//cout << soma << endl;
	
	return 0;
}