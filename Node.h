#include <iostream>
#include <cmath>
using namespace std;

class Node
{
private:
    int data, weight;
    Node* lchild;
    Node* rchild;

public:
    Node (){}
    Node (int key)
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
    
    
    
    void preOrder(Node* node)
    {
        
        if(node==NULL) return;
        
        cout << this->data << " ";
        preOrder(this->lchild);
        preOrder(this->rchild);
        
    }

    
    
    void postOrder(Node* node)
    {
        
        if(node==NULL) return;
        
        postOrder(this->lchild);
        postOrder(this->rchild);
        cout << this->data << " ";
        
    }

    
    
    Node* deleteNode(int num){

        Node *current = this;
        Node *parent = this;
        Node *temp = this;
        
        bool check {true};
        
        do{
            if(current==nullptr){
                
                cout << "Node not found!" << endl;
                check = false;
                
            }
            
            if(current->data==num){
                
                if(current->lchild==nullptr && current->rchild==nullptr){
                    
                    if(current->data==parent->lchild->data){
                        
                        delete current;
                        current = nullptr;
                        parent->lchild = nullptr;
                        check = false;
                        return parent;
                        
                    }else{
                        
                        delete current;
                        current = nullptr;
                        parent->rchild = nullptr;
                        check = false;
                        return parent;
                        
                    }
                    
                }else if(current->lchild==nullptr){
                    
                    temp = current->rchild;
                    current->data = temp->data;
                    current->lchild = temp->lchild;
                    current->rchild = temp->rchild;
                    delete temp;
                    temp = nullptr;
                    check = false;
                    return this;
                    
                } else if(current->rchild==nullptr){
                    
                    temp = current->lchild;
                    current->data = temp->data;
                    current->lchild = temp->lchild;
                    current->rchild = temp->rchild;
                    delete temp;
                    temp = nullptr;
                    check = false;
                    return this;
                    
                }
                
            } else if(num<current->data) {
                
                parent = current;
                current = current->lchild;
                
            } else {
                
                parent = current;
                current = current->rchild;
                
            }
            
        }while(check);
    
        return current;

    }

    
    friend ostream& operator << (ostream& os, const Node* n){
        
        os << "Parent: " << n->data << endl;
        
        os << "Left Child: ";
        if (n->lchild == nullptr) {
            os << "NULL" << endl;
        }else{
            os << n->lchild->data << endl;
        }
        
        os << "Right Child: ";
        if (n->rchild == nullptr) {
            os << "NULL" << endl;
        }else{
            os << n->rchild->data << endl;
        }
        
        return os;
    }
    
    
    friend istream& operator >> (istream& is, Node*& n){
        n = new Node();
        int a{0};
        cout << "Please insert data... ";
        
        while(!(is>>a)){
            cout << "Invalid data, try again... ";
            is.clear();
            is.ignore(40, '\n');
        }

        (*n).data = a;
        (*n).lchild = nullptr;
        (*n).rchild = nullptr;
        (*n).weight = 1;
        
        return is;
    }
};
