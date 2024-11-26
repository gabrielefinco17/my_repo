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
