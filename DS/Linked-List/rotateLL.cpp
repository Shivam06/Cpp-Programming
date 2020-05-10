#include "basics.cpp"

Node* rotateLL(Node* head, int k) {

	int count = 1;
	Node* temp = head;
	while (count < k) {
		temp = temp->next;
		count++;
	}

	if (temp->next == NULL)
		return head;


	Node* new_head = temp->next;
	temp->next = NULL;
	temp = new_head;

	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = head;
	return new_head;
}

int main() {

	vi v{{2, 4, 7, 8, 9}};
	Node* head = inputLL(v);
	printLL(head);
	int k = 3;
	head = rotateLL(head, k);
	printLL(head);
	return 0;
}