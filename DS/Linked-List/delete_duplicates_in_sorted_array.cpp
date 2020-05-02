#include "basics.cpp"

void delete_duplicates(Node* head) {
	
	int x = INT_MIN;
	Node* temp = head;
	
	Node* prev = NULL;
	while (temp != NULL) {
		if (temp->data == x) {
			prev->next = delete_node(temp);
			continue;
		}

		prev = temp;
		x = temp->data;
		temp = temp->next;
	}
}

int main() {
	vi v{{2,2,4,5}};
	Node* head = inputLL(v);
	delete_duplicates(head);
	//delete_node(head);
	printLL(head);
}