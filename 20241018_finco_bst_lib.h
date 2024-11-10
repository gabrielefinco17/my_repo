{\rtf1\ansi\ansicpg1252\cocoartf2818
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #include <iostream>\
#include <cmath>\
using namespace std;\
\
\
struct Node\
\{\
    int value, weight;\
    Node* left;\
    Node* right;\
    \
    Node(int key)\
    \{\
        value = key;\
        weight = 1;\
        left = nullptr;\
        right = nullptr;\
    \}\
\};\
\
\
\
Node* r_insert (Node* n, int num)\
\{\
    if(n==nullptr)\
    \{\
        return new Node (num);\
    \}\
    if(n->value == num)\
    \{\
        n->weight ++;\
        return n;\
    \}\
    if(num < n->value)\
    \{\
        n->left = r_insert (n->left, num); \
    \}else\{\
        n->right = r_insert (n->right, num);\
    \}\
    return n;\
\}\
\
\
Node* it_insert (Node* n, int num)\
\{\
    Node* current = n;\
    Node* father\{nullptr\};\
    \
    while(current!=nullptr)\
    \{\
        if(current->value==num)\{\
            current->weight++;\
            return n;\
        \}\
        if(current->value<num)\{\
			father = current;\
             current = current->right;\
        \}else\{\
			father = current;\
             current = current->left;\
        \}\
    \}\
    current = new Node(num);\
    if(current->value>father->value)\
    \{\
        father->right=current;\
    \}else\{\
        father->left=current;\
    \}\
    return n;\
\}\
  \
void inOrder(Node* node)\
\{\
    if(node==NULL) return;\
    \
    inOrder(node->left);\
    cout << node->value << " ";\
    inOrder(node->right);\
\}\
\
\
void preOrder(Node* node)\
\{\
    if(node==NULL) return;\
    \
	cout << node->value << " ";\
    preOrder(node->left);\
    preOrder(node->right);\
\}\
\
void postOrder(Node* node)\
\{\
    if(node==NULL) return;\
    \
    postOrder(node->left);\
    postOrder(node->right);\
	cout << node->value << " ";\
\}\
\
\
\
int height(Node* node)\
\{\
    if(node == NULL) return 0;\
    int l = height(node->left);\
    int r = height(node->right);\
    \
    return max(l,r)+1;\
\}\
  \
  \
bool r_search(Node* node, int num)\
\{\
	if(node==nullptr)\
	\{\
		return false;\
	\}\
	if(num==node->value)\
	\{\
		return true;\
	\}\
	if(num>node->value)\
	\{\
		return r_search(node->right, num);\
	\}\
	if(num<node->value)\
	\{\
		return r_search(node->left, num);\
	\}\
	return false;\
\}\
\
bool it_search(Node* node, int num)\
\{\
	while(node!=nullptr)\
	\{\
		if(node->value==num)\
		\{\
			return true;\
		\}\
		if(node->value>num)\
		\{\
			node=node->left;\
		\}else\{\
			node=node->right;\
		\}\
	\}\
	return false;\
\}\
\
bool N_delete(Node* node, int num)\
\{\
	if(node==nullptr)\
	\{\
		return false;\
	\}\
	\
	while(node!=nullptr)\
	\{\
		if(node->value==num)\
		\{\
			if(node->left==nullptr && node->right==nullptr)\
			\{\
				delete node;\
				return true;\
			\}else if(node->left!=nullptr && node->right==nullptr)\{\
				node->value=node->left->value;\
				delete node->left;\
				node->left=nullptr;\
				return true;\
			\}else if(node->left==nullptr && node->right!=nullptr)\{\
				node->value=node->right->value;\
				delete node->right;\
				node->right=nullptr;\
				return true;\
			\}\
			return false;\
		\}\
		if(node->value>num)\
		\{\
			node=node->left;\
		\}else\{\
			node=node->right;\
		\}\
	\}\
	return false;\
\}\
\
/*bool bst(Node* node)\
\{\
	if(node==nullptr) return true;\
    \
    bst(node->left);\
    \
    bst(node->right);\
\}*/}