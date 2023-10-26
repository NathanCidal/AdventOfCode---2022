#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node{
    Node * prev;
    string nome;
    string tipo;
    vector <Node *> childs;

    Node(string n = "/", string t = "(dir)"){
        this->nome = n;
        prev = nullptr;
        this->tipo = t;
    }
};

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
                            //Nesse caso, oque recebeu em string vai ser o peso do arquivo (quickStr2)
                            //E o tipe vira o nome dele (quickStr2)
                            cin >> quickStr2;
                            create = new Node(quickStr1, quickStr2);
                            create->prev = atual;
                            atual->childs.push_back(create);
                            continue;
                        }
                    }
                }
            }
        }
    }

    Node * imprime = atual;
    for(int i = 0; i < atual->childs.size(); i++){
        cout << atual->childs[i]->nome << " " << atual->childs[i]->tipo << endl;
    }

    return 0;
}