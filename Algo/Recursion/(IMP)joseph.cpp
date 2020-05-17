#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;

	Node(int x) {
		this->data = x;
		this->next = NULL;
	}
};

// Recursive solution
int josephus(int n, int k)
{
    return n == 1? 1: (josephus(n-1, k) + k-1)%n + 1;
}

int josephus_itr(int n, int k) {
	// create circular linked list.
	Node* head = new Node(1);
	Node* temp = head;
	int i = 2; 
	while (i <= n) {
		temp->next = new Node(i++);
		temp = temp->next;
	}
	temp->next = head;

	while (head->next != head) {
		int c = 1;
		while (c < k) {
			head = head->next;
			c++;
		}

		Node* temp = head->next;
		head->data = temp->data;
		head->next = temp->next;
		delete temp;
	}

	return head->data;
}


int main() {
	cout << josephus_itr(6, 2) << endl;
	return 0;
}