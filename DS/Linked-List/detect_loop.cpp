#include "basics.cpp"

bool detect_loop(Node* head) {
	Node* slow = head;
	Node* fast = head;

	while (fast!=NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow==fast)
			return true;
	}

	return false;
}

int main() {

	Node* head = new Node(1);
	Node* temp = head;
	temp->next = new Node(2);
	temp = temp->next;
	temp->next = new Node(3);
	temp = temp->next;
	temp->next = new Node(4);
	temp = temp->next;

	cout << detect_loop(head) << endl;

	temp->next = head;

	cout << detect_loop(head) << endl;

	head = new Node(1);
	head->next = head;

	cout << detect_loop(head) << endl;
}