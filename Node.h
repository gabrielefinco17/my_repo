#include <iostream>
#include <cmath>
using namespace std;

class Node
{
    int data, weight;
    Node* lchild;
    Node* rchild;

public:
    Node(int key)
    {
        data = key;
        weight = 1;
        lchild = nullptr;
        rchild = nullptr;
    }
    
    bool searchI(int k){
        Node *father = this;
        Node *current = this;
        bool check {true};
            do{
                if(current==NULL){
                    cout << "Node not found!!" << endl;
                    return false;
                    check = false;
                }
                if(current->data==k){
                    cout << "Node found!!" << endl;
                    return true;
                    check = false;
                }
                if(k<current->data){
                    father = current;
                    current = current->lchild;
                    check = true;
                } else {
                    father = current;
                    current = current->rchild;
                    check = true;
                }
            }while(check);

            return true;

    }
    
    bool searchR(int num){
        bool check {true};
        do{
           if(this==NULL){
               cout << "node not found" << endl;
               return false;
               check = false;
           }
           if(this->data==num){
               cout << "node found" << endl;
               return true;
               check = false;
           }
           if(num<this->data){
               return this->lchild->searchR(num);
           } else {
               return this->rchild->searchR(num);
           }
        }while(check);

        return true;
    }

    Node* insertI(int num){
        Node *current = this;
        Node *father = this;
        bool check {true};
        do{
            if(current==NULL){
                if(num<father->data){
                    father->lchild = new Node(num);
                    return this;
                    check = false;
                } else {
                    father->rchild = new Node(num);
                    return this;
                    check = false;
                }
            }
            if(current->data==num){
                current->weight++;
                return current;
                check = false;
            }
            if(num<current->data){
                father = current;
                current = current->lchild;
            } else {
                father = current;
                current = current->rchild;
            }
        }while(check);
        
        return this;
    }

    
    Node* insertR (int num)
    {
        if(this->data == num)
        {
            this->weight ++;
            return this;
        }
        if(num < this->data)
        {
            if(this->lchild == nullptr){
                this->lchild = new Node (num);
            }else{
                this->lchild->insertR(num);
            }
        }else{
            if(this->rchild == nullptr){
                this->rchild = new Node (num);
            }else{
                this->rchild->insertR(num);
            }
        }
        return this;
    }
    
    void inOrder()
    {
        if(this->lchild != nullptr) this->lchild->inOrder();
            
        cout << this->data << " ";
        
        if(this->rchild != nullptr) this->rchild->inOrder();
    }
};
