#include "basics.cpp"

int intersection_point(Node* first, Node* second) {

	int c1 = length(first), c2 = length(second);
	if (c2 > c1) {
		Node* temp = first;
		first = second;
		second = temp;
	}

	Node* temp_first = first;
	Node* temp_second = second;

	int diff = abs(c1 - c2);

	int d = 0;
	while (d < diff) {
		temp_first = temp_first->next;
		d++;
	}

	while (temp_first != NULL && temp_second != NULL) {
		if (temp_second == temp_first) {
			return temp_second->data;
		}
		temp_second = temp_second->next;
		temp_first = temp_first->next;
	}

	return -1;
}

int main() {
	vi v{{10,20,5,10}};
	Node* head = inputLL(v);
	Node* meet = head->next->next;

	vi v2{{30,40,50}};
	Node* head2 = inputLL(v2);
	Node* temp = head2;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = meet;
	cout << intersection_point(head, head2);
}