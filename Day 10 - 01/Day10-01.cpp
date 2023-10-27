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

	while(true){
		cin >> comando;

		if(comando == ".") break;

		jaAddNessa = false;
		//Comando noop é só 1 ciclo
		if(comando == "noop"){
			ciclo++;

			if((ciclo == 20) || (ciclo == 60) || (ciclo == 100) || (ciclo == 140) || (ciclo == 180) || (ciclo == 220)) soma += ciclo * registrador; 
			//cout << "Ciclo: " << ciclo << " Registrador: " << registrador << endl;
		}
		
		//Comando addx é 2 ciclos que ocorre nele
		if(comando == "addx"){
			cin >> valor;
			//cout << "Ciclo: " << ciclo << " Registrador: " << registrador << endl;
			ciclo++;
			if((ciclo == 20) || (ciclo == 60) || (ciclo == 100) || (ciclo == 140) || (ciclo == 180) || (ciclo == 220)) soma += ciclo * registrador; 
			//cout << "Ciclo: " << ciclo << " Registrador: " << registrador << endl;
			ciclo++;
			if((ciclo == 20) || (ciclo == 60) || (ciclo == 100) || (ciclo == 140) || (ciclo == 180) || (ciclo == 220)) soma += ciclo * registrador; 
			//cout << "Ciclo: " << ciclo << " Registrador: " << registrador << endl;

			registrador += valor;
		}
	}

	cout << soma << endl;
	
	return 0;
}