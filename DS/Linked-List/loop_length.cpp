#include "basics.cpp"

Node* find_meeting_point(Node* head) {
	Node* slow = head;
	Node* fast = head;

	while (fast!=NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow==fast)
			return slow;
	}

	return NULL;
}

int loop_length(Node* head) {
	Node* m = find_meeting_point(head);

	if (m == NULL)
		return 0;

	while (m != head) {
		m = m->next;
		head = head->next;
	}

	int count = 0;
	Node* temp = head;
	do {
		temp = temp->next;
		count++;
	} while (temp != head);

	return count;
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

	cout << loop_length(head) << endl;

	temp->next = head;

	cout << loop_length(head) << endl;

	head = new Node(1);
	head->next = head;

	cout << loop_length(head) << endl;

	return 0;
}