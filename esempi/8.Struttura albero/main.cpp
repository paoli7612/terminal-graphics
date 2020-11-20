#include "tree.cpp"
#include "../../lib_ita/draw.h"

#define NODE_W 6
#define NODE_H 4

void show_node(Node* node, int x, int y){
	if (node == NULL) return;
	cambia_colore(VERDE);
	disegna_rettangolo(x, y, x + NODE_W, y + NODE_H, DOPPIO);
	cambia_colore(BIANCO);
	vai_a(x+NODE_W/2, y+NODE_H/2);
	printf("%c",node->letter);
	show_node(node->left, x-NODE_W-(y), y+NODE_H+3);
	show_node(node->right, x+NODE_W+(y), y+NODE_H+3);
}

void show_tree(Node* root){
	show_node(root, 100,3);
}

int main(){	
	terminale_massimizza_fullscreen();
	
	Node* root = newNode('A');
	root->left = newNode('B');
	root->left->left = newNode('D');
	root->left->right = newNode('E');
	root->right = newNode('C');
	root->right->left = newNode('F');
	root->right->right = newNode('G');
	root->left->left->left = newNode('H');
	root->right->left->right = newNode('I');
	root->right->right->left = newNode('J');
	show_tree(root);
	vai_a(1,28);
	cout << endl << "order" << endl;
	show_order(root);
	cout << endl << "preorder" << endl;
	show_preorder(root);
	cout << endl << "postorder" << endl;
	show_postorder(root);
	
}
