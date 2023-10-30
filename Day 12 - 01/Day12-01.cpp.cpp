#include <iostream>
#include <fstream>
#include <vector>

#define big 1000

using namespace std;

struct Node{
    char info;
    int posX;
    int posY;
    bool foi[4];

    vector <Node*> childs;
    Node * parent;
    Node(int posX, int posY){
        this->posX = posX;
        this->posY = posY;
        parent = nullptr;
        for(int i = 0; i < 4; i++){
            foi[i] = false;
        }
    }
};

bool verifyPast(Node * aux, int posXd, int posYd){
    Node * v = aux;
    while(v != nullptr){
        if(v->posX == posXd && v->posY == posYd){
            return false;
        }
    }
    return true;
}


int main(){
    //Implementação pra receber o mapa
    int sizeX = 0;
    int sizeY = 0;

    //Open file
    ifstream arq;
    arq.open("input.txt", ios::in);
    if(!arq.is_open()) return 1;

    string aux[big];
    getline(arq, aux[sizeY]);
    sizeX = aux[sizeY].length();
    sizeY++;

    while(getline(arq, aux[sizeY])){
        sizeY++;
    }

    int posIx, posIy;
    int posFx, posFy;

    for(int i = 0; i < sizeY; i++){
        for(int j = 0; j < sizeX; j++){
            cout << aux[i][j];

            if(aux[i][j] == 'S'){
                posIx = j;
                posIy = i;
            }

            if(aux[i][j] == 'E'){
                posFx = j;
                posFy = i;
            }
        }
        cout << endl;
    }

    Node * head = new Node(posIx, posIy);
    Node * tail;                                //Preciso de um tail pra verificar se ja nao passamos por isso
    Node * auxiliar1;
    Node * auxiliar2;
    Node * auxiliar3;
    Node * auxiliar4;

    tail = head;
    bool quickCheck = false;

    while(true){
        quickCheck = false;
        if(head == nullptr){
            break;
        }else{
            auxiliar1 = new Node(head->posX + 1, head->posY);
            auxiliar2 = new Node(head->posX - 1, head->posY);
            auxiliar3 = new Node(head->posX, head->posY + 1);
            auxiliar4 = new Node(head->posX, head->posY - 1);

            //F0 = direita, F1 = esquerda, F2 = cima, F3 = baixo

            if(auxiliar1->info == tail->info || auxiliar1->info == tail->info + 1){
                quickCheck = verifyPast(head, head->posX + 1, head->posY);
                if(quickCheck == true){
                    tail->childs.push_back(auxiliar1);
                    auxiliar1->foi[1] = true;
                    tail->foi[0] = true;
                }
            }else{
                tail->foi[0] == true;
            }

            if(auxiliar2->info == tail->info || auxiliar2->info == tail->info + 1){
                quickCheck = verifyPast(head, head->posX - 1, head->posY);
                if(quickCheck == true){
                    tail->childs.push_back(auxiliar2);
                }
            }else{
                tail->foi[1] == true;
            }

            if(auxiliar3->info == tail->info || auxiliar3->info == tail->info + 1){
                quickCheck = verifyPast(head, head->posX, head->posY + 1);
                if(quickCheck == true){
                    tail->childs.push_back(auxiliar3);
                }
            }else{
                tail->foi[2] == true;
            }

            if(auxiliar4->info == tail->info || auxiliar4->info == tail->info + 1){
                quickCheck = verifyPast(head, head->posX, head->posY - 1);
                if(quickCheck == true){
                    tail->childs.push_back(auxiliar4);
                }
            }else{
                tail->foi[3] == true;
            }

            if((tail->childs.size() == 0) || tail->foi[0] == true && tail->foi[1] == true && tail->foi[2] == true && tail->foi[3] == true){
                tail = tail->parent;
            }

        }
    }
    

    


    arq.close();    //Close File

    return 0;
}