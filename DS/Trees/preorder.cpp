#include<iostream>
#include<vector>
#include<stack>
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

void preorder(Node* head) {

	if (head == NULL)
		return;

	cout << head->data << " ";
	preorder(head->left);
	preorder(head->right);
}

void preorder_itr(Node* head) {

	stack<Node*> s;
	s.push(head);

	while (!s.empty()) {
		Node* temp = s.top();
		s.pop();
		if (temp == NULL)
			continue;

		cout << temp->data << " ";
		s.push(temp->right);
		s.push(temp->left);
	}

}

int main() {

	Node* head = new Node(10);
	head->left = new Node(20);
	head->right = new Node(30);
	head->left->right = new Node(40);
	head->right->left = new Node(50);
	head->right->right = new Node(60);

	preorder(head);
	cout << endl;
	preorder_itr(head);
}