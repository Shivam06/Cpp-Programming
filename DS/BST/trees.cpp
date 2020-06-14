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
	head->left = new Node(5);
	head->right = new Node(15);
	head->left->right = new Node(8);
	head->right->left = new Node(12);
	head->right->right = new Node(20);
	return head;
}