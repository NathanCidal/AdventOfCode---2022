#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Node{
	Node * next;
	char c;
	Node(char c){
		this->c = c;
		next = nullptr;
	}
	~Node(){
		//cout << "> Destruindo Nodo(" << c << ")" << endl;
	}
};

class Stack{
	private:
		
	public:
		Node * stack;
		Stack(){
			stack = nullptr;
		}
		~Stack(){
			while(stack != nullptr){
				Node * aux = stack;
				stack = stack->next;
				delete aux;
			}
		}
		void push(Node * e){
			if(stack == nullptr){
				stack = e;
			}else{
				e->next = stack;
				stack = e;
			}
		}

		Node * pop(){
			if(stack == nullptr) return nullptr;
			Node * aux = stack;
			stack = stack->next;
			aux->next = nullptr;
			return aux;
		}
		
		Node * head(){
			if(stack == nullptr) return nullptr;
			return stack;
		}

};

int main(){

	//Criação de Stacks
	Stack * pilha[10];
	for(int i = 0; i < 10; i++){
		pilha[i] = new Stack();	
	}
	
	string cmd;
	char c;
	string lixo;

	int qual = 0;
	int quantidade;
	int moverDe;
	int moverPara;

	Node * auxiliar;
	bool truth = true;

	while(truth){
		cin >> cmd;

		if(cmd == "add"){
				cin >> c;
				cin >> qual;
				auxiliar = new Node(c);

				qual = qual - 1;

				if(pilha[qual]->stack == nullptr){
					pilha[qual]->stack = auxiliar;
				}else{
					auxiliar->next = pilha[qual]->stack;
					pilha[qual]->stack = auxiliar;
				}

		}else{
			if(cmd == "move"){
				cin >> quantidade >> lixo >> moverDe >> lixo >> moverPara;
				moverDe = moverDe - 1;
				moverPara = moverPara - 1;

				for(int i = 0; i < quantidade; i++){
					pilha[moverPara]->push(pilha[moverDe]->pop());
				}
			}else{
				truth = false;
				break;
			}
			  
		}
	}

	for(int i = 0; i < 10; i++){
		Node * aux = pilha[i]->stack;
		while(aux != nullptr){
			cout << aux->c;
			aux = aux->next;
		}
		cout << endl;
	}
	

	//Desalocando os Stacks
	for(int i = 0; i < 10; i++){
		cout << "Desalocando da Stack: " << i << endl;
		delete pilha[i];
		cout << endl;
	}


	return 0;
}