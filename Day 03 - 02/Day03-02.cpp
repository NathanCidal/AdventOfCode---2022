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
		for(int i = 0; i < print->tam; i++){
			if(achou == true){
				break;
			}

			for(int j = 0; j < print->next->tam; j++){

				if(achou == true){
					break;
				}

				for(int k = 0; k < print->next->next->tam; k++){
					//cout << "Primeiro = " << print->s[i] << " - Segundo = " << print->next->s[j] << " - Terceiro = " << print->next->next->s[k] << endl;

					if(print->s[i] == print->next->s[j] && print->next->s[j] == print->next->next->s[k]){
						achou = true;
						array[contador] = print->s[i];
						contador++;
						break;
					}
				}
			}
		}
		
		achou = false;
		print = print->next->next->next;
	}

	cout << endl;

	int somador = 0;
	for(int i = 0; i < contador; i++){
		cout << array[i] << " "; 

		if(array[i] > 96){
			somador += array[i] - 96;
		}

		if(array[i] > 64 && array[i] < 97){
			somador += array[i] - 38;
		}	
	}
	cout << endl << endl;

	//cout << "Quantidade de itens iguais: " << contador << " - Quantidade de sacos: " << contaSaco << endl;

	cout << "Total Sum = " << somador << endl;	

	while(head != nullptr){
		Node * del = head;
		head = head->next;
		delete del;		
	}
		
	return 0;
}
