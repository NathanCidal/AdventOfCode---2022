#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Node{
    Node * prev;
    string nome;
    string tipo;
    int size;
    vector <Node *> childs;

    Node(string n = "/", string t = "(dir)"){
        this->nome = n;
        prev = nullptr;
        this->tipo = t;

        if(t != "(dir)" && t != "dir"){
            size = stoi(t);
        }else{
            size = 0;
        }
    }
};

string imprimeTudo(Node * nodo){
    if(nodo == nullptr) return "";
    stringstream ss;
    for(int i = 0; i < nodo->childs.size(); i++){
       ss << " -" << nodo->childs[i]->nome << " " << nodo->childs[i]->tipo << " " << endl;
    }

    for(int i = 0; i < nodo->childs.size(); i++){
       ss << imprimeTudo(nodo->childs[i]);
    }

    return ss.str();
}

int obtemSizeDir(Node * dir){
    if(dir->tipo != "(dir)" && dir->tipo != "dir") return dir->size;

    long long int sizeAtual = dir->size;
    long long int sizeD = 0;
    cout << dir->nome << endl << " -" << endl;
    for(int i = 0; i < dir->childs.size(); i++){
        sizeD += obtemSizeDir(dir->childs[i]);
    }

    return sizeAtual + sizeD;
}


int main(){
    string estiloComando;
    string comando;
    string nomeAuxiliar;
    string tipoAuxiliar;

    Node * atual;
    Node * head = nullptr;
    Node * create;
    while(true){
        cin >> comando;
        if(comando == ".") break;

        if(comando == "$"){
            //Vamos entrar num comando
            cin >> estiloComando;

            if(estiloComando == "cd"){
                cin >> nomeAuxiliar;

                if(nomeAuxiliar == "/"){
                    if(head == nullptr){
                        head = new Node("/", "(dir)");
                        atual = head;
                    }else{
                        atual = head;
                    }
                }else{
                    if(nomeAuxiliar == ".."){
                        if(atual->prev != nullptr) atual = atual->prev;
                    }else{
                        //Método de Busca
                        for(int i = 0; i < atual->childs.size(); i++){
                            if(atual->childs[i]->nome == nomeAuxiliar){
                                atual = atual->childs[i];
                                break;
                            }   
                        }
                    }
                }
            }
        
            if(estiloComando == "ls"){
                string quickStr1;   //Nome do novo comando
                string quickStr2;   //Nome para o coisa
                string quickStr3;

                while(true){
                    cin >> quickStr1;
                    if(quickStr1 == "dir"){
                        cin >> quickStr2;
                        create = new Node(quickStr2, "(dir)");
                        create->prev = atual;
                        atual->childs.push_back(create);
                        continue;
                    }else{
                        if(quickStr1 == "$"){
                            cin >> quickStr2;

                            if(quickStr2 == "cd"){
                                cin >> quickStr3;

                                if(quickStr3 == ".."){
                                    if(atual->prev != nullptr) atual = atual->prev;
                                    break;
                                }else{
                                    if(quickStr3 == "/"){
                                        atual = head;
                                        break;
                                    }else{
                                        for(int i = 0; i < atual->childs.size(); i++){
                                            if(atual->childs[i]->nome == quickStr3){
                                                atual = atual->childs[i];
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                }
                            }
                        }else{
                            //Nesse caso, oque recebeu em string vai ser o peso do arquivo (quickStr1)
                            //E o tipe vira o nome dele (quickStr2)
                            cin >> quickStr2;
                            quickStr3 = quickStr1;
                            quickStr1 = quickStr2;
                            quickStr2 = quickStr3;
                            create = new Node(quickStr1, quickStr2);
                            create->size = stoi(quickStr2);
                            create->prev = atual;
                            atual->childs.push_back(create);
                            continue;
                        }
                    }
                }
            }
        }
    }

    //Gera Peso para arquivos

    Node * imprime = head;

    vector <int> v;
    long long int n = obtemSizeDir(head);
    cout << n << endl;

    return 0;
}
