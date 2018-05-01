// tree

#include <iostream>

using namespace std;

struct Node{
	char letter = '*';
	Node* left = NULL;
	Node* right = NULL;
};

Node* newNode(char letter){
	Node* node = new Node;
	node->letter = letter;
	return node;
}

void show_order(Node* root){
	if (root == NULL) return;	
	show_order(root->left);
	cout << root->letter << " ";
	show_order(root->right);	
}

void show_preorder(Node* root){
	if (root == NULL) return;
	cout << root->letter << " ";
	show_preorder(root->left);
	show_preorder(root->right);
}

void show_postorder(Node* root){
	if (root == NULL) return;
	show_postorder(root->left);
	show_postorder(root->right);
	cout << root->letter << " ";
}

