#include "basics.cpp"

Node* remove_the_loop(Node* head) {

	Node* fast = head, *slow = head;
	if (slow == NULL || slow->next == NULL)
		return head;

	Node* pre = NULL;
	do {
		pre = slow;
		slow = slow->next;
		fast = fast->next->next;
	} while (slow != fast && fast != NULL && fast->next != NULL);

	if (slow != fast) 
		return head;

	cout << "Loop found!" << endl;

	slow = head;

	while (slow != fast) {
		pre = fast;
		slow = slow->next;
		fast = fast->next;
	}

	pre->next = NULL;

	return head;

}

int main() {
	Node* head = new Node(2);
	Node* temp = head;
	temp->next = new Node(3);
	temp = temp->next;
	temp->next = new Node(10);
	temp = temp->next;
	Node* meet = temp;
	temp->next = new Node(12);
	temp = temp->next;
	temp->next = new Node(5);
	temp = temp->next;
	temp->next = new Node(7);
	temp = temp->next;
	temp->next = meet;
	printLL(head);

	remove_the_loop(head);

	printLL(head);
}