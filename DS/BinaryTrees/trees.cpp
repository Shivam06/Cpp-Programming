#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data; 
		this->left = NULL;
		this->right = NULL;
	}
};


Node* default_input() {
	Node* head = new Node(10);
	head->left = new Node(20);
	head->right = new Node(30);
	head->left->right = new Node(40);
	head->right->left = new Node(50);
	head->right->right = new Node(60);
	return head;
}