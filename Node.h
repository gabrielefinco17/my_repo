#include <iostream>
#include <cmath>
using namespace std;

class Node
{
    int value, weight;
    Node* left;
    Node* right;

public:
    Node(int key)
    {
        value = key;
        weight = 1;
        left = nullptr;
        right = nullptr;
    }
    
    Node* r_insert (int num)
    {
        if(this->value == num)
        {
            this->weight ++;
            return this;
        }
        if(num < this->value)
        {
            if(this->left == nullptr){
                this->left = new Node (num);
            }else{
                this->left->r_insert(num);
            }
        }else{
            if(this->right == nullptr){
                this->right = new Node (num);
            }else{
                this->right->r_insert(num);
            }
        }
        return this;
    }
    
    void inOrder()
    {
        if(this->left != nullptr) this->left->inOrder();
            
        cout << this->value << " ";
        
        if(this->right != nullptr) this->right->inOrder();
    }
};
