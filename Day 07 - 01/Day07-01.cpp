#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Node{
	int size = 0;		//Store the file size
	string name;			//Store the file name
	string type;			//Store if it is a file or a dir
	Node * parent;			//Store it current Dir
	vector <Node *> childs;		//Store this Node childs

	Node(string t, string n){
		this->name = n;	
		this->type = t;
		parent = nullptr;
		//cout << "> Criando Nodo(" << this->name << ")..." << endl;

		if(t != "dir"){
			this->size = stoi(t);
			this->type = "file";
		}else{
			this->size = 0;
		}
	}

	~Node(){
		for(int i = 0; i < childs.size(); i++){
			if(childs[i] != nullptr) delete childs[i];
		}

		//cout << "> Deletando Nodo(" << this->name << ")..." << endl;
	}
};

//There are 2 categories: file and dir

class DirLinkedTree{
	private:
		Node * head;
		Node * atual;
	public:
		DirLinkedTree(){ head = nullptr; atual = nullptr; }
		~DirLinkedTree(){ if(head != nullptr) delete head; }
		bool isEmpty()const{ return head == nullptr; }
		Node * returnHead(){ return head;   }
		Node * returnAtual(){ return atual; }
		
		bool setExterior(){ if(head == nullptr){ return false; } atual = head; return true;}
		bool goBack(){ if(head == nullptr){ return false; } atual = atual->parent; return true;}

		void goFoward(string n = " "){
			for(int i = 0; i < atual->childs.size(); i++){
				if(atual->childs[i]->name == n && atual->childs[i]->type == "dir"){
					atual = atual->childs[i];
					return;
				}
			}
		}

		void addNode(Node * newNode){
			//cout << "> Adicionando Nodo..." << endl;

			if(head == nullptr){
				atual = head = newNode;
				return;
			}

			if(atual != nullptr) atual->childs.push_back(newNode);
			newNode->parent = atual;
			Node * aux = atual;

			while(aux != nullptr){
				aux->size += newNode->size;
				//cout << aux->name << " - " << aux->type << " - " << aux->size << endl;
				aux = aux->parent;
			}	
		}

		string imprime(Node * aux){
			if(aux == nullptr) return " ";
			stringstream ss;
			ss << "- " << aux->name << " (dir) [size = " << aux->size << "] { ";
			for(int i = 0; i < aux->childs.size(); i++){
				if(i != 0) ss << " - ";
				ss << aux->childs[i]->name;
				if(aux->childs[i]->type == "dir") ss << " (dir)";
			}
			ss << " }" << endl;

			for(int i = 0; i < aux->childs.size(); i++){
				if(aux->childs[i]->type == "dir") ss << imprime(aux->childs[i]);
			}

			return ss.str();
		}

		string imprimeTudo(){
			stringstream ss;	
			ss << endl;
			ss << imprime(head);
			return ss.str();
		}

		int retornaSizeEspecificado(Node * aux, int maxSize){
			if(aux == nullptr) return 0;
			long long int v = 0;
			
			if(aux->size <= maxSize) v += aux->size;
			
			for(int i = 0; i < aux->childs.size(); i++){
				if(aux->childs[i]->type == "dir"){
					v += retornaSizeEspecificado(aux->childs[i], maxSize);
				}
			}
			
			return v;
		}
};

int main(){		
	string estiloComando;
    	string comando;

    	string nomeAuxiliar;
    	string tipoAuxiliar;
	
	
	DirLinkedTree * tree = new DirLinkedTree();
	Node * atual;
	Node * create;

	bool addingMode = false;

	while(true){
        	cin >> comando;

		if(comando == "$"){
			addingMode = false;
			cin >> estiloComando;
			
			//ir para diretório ou sair
			if(estiloComando == "cd"){
				cin >> nomeAuxiliar;
				
				if(nomeAuxiliar == "/"){
					if(tree->isEmpty() == true){
						create = new Node("dir", "/");
						tree->addNode(create);
					}else{
						tree->setExterior();
					}
				}else{
					if(nomeAuxiliar == ".."){
						tree->goBack();
					}else{
						tree->goFoward(nomeAuxiliar);
					
					}
				}
			}

	
			//Adicionando arquivos novos
			if(estiloComando == "ls"){
				addingMode = true;
			}
		}else{
			if(comando == "."){
				break;
			}else{
				if(addingMode == true){
					//cout << "---Estou adicionando---" << endl;
					cin >> nomeAuxiliar;
					create = new Node(comando, nomeAuxiliar);
					tree->addNode(create);
				}
			}
			
		}
        }
	cout << tree->imprimeTudo() << endl;

	long long int n;
	n = tree->retornaSizeEspecificado(tree->returnHead(), 100000);
	cout << n << endl;
	
		
	return 0;
}
