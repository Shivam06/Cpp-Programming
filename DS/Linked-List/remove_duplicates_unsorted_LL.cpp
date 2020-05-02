#include "basics.cpp"
#include<unordered_map>

void remove_duplicates(Node* head) {

	unordered_map<int, bool> M;

	Node* temp = head;
	Node* prev = NULL;
	while (temp != NULL) {

		if (M.find(temp->data) != M.end()) {
			prev->next = delete_node(temp);
			continue;
		}

		M[temp->data] = true;
		prev = temp;
		temp = temp->next;
	}
}

int main() {
	vi v{{2,2}};
	Node* head = inputLL(v);
	remove_duplicates(head);
	printLL(head);
}