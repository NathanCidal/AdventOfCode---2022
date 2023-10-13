#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Node{
	string s;
	int tam;
	Node * next;

	Node(string s){
		this->s = s;
		tam = s.length();
		next = nullptr;
	}
};

int main(){
	ifstream arq;
	arq.open("input.txt", ios::in);
	if(arq.is_open() == false){ cerr << "> ERRO AO ABRIR ARQUIVO" << endl; return 1; }
	string aux;

	Node * head = nullptr;
	Node * auxiliar;

	int contaSaco = 0;

	while(getline(arq, aux)){
		auxiliar = new Node(aux);

		if(head == nullptr){
			head = auxiliar;
		}else{
			auxiliar->next = head;
			head = auxiliar;
		}
		contaSaco++;
	}
	arq.close();

	Node * print = head;
	/*while(print != nullptr){
		cout << print->s << endl;
		print = print->next;
	}*/

	
	bool achou = false;
	int contador = 0;
	char array[900];
	
	cout << "------Verifying------"<< endl;

	print = head;
	while(print != nullptr){
		for(int i = 0; i <= (print->tam) / 2; i++){
			//cout << print->s[i] << " " << print->s[i + ((print->tam) / 2)] << endl;

			if(achou == true){
				achou = false;
				break;
			}
		
	
			for(int j = ((print->tam) / 2); j < print->tam; j++){
				if(print->s[i] == print->s[j]){
					//cout << "Achou: " << print->s[i] << endl;
					array[contador] = print->s[i];
					contador++;
					achou = true;
					break;
				}
			}
		}	

		print = print->next;
	}

	int somador = 0;
	for(int i = 0; i < contador; i++){
		//cout << array[i] << " "; 

		if(array[i] > 96){
			somador += array[i] - 96;
		}

		if(array[i] > 64 && array[i] < 97){
			somador += array[i] - 38;
		}
	}
	cout << endl;

	//cout << "Quantidade de itens iguais: " << contador << " - Quantidade de sacos: " << contaSaco << endl;

	cout << "Total Sum = " << somador << endl;	

	while(head != nullptr){
		Node * del = head;
		head = head->next;
		delete del;		
	}
		
	return 0;
}
