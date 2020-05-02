#include "basics.cpp"

void insert_in_middle(Node* head, int x) {

	add(find_middle(head), x);
}

int main() {
	vi v{{1,2,3,4,5}};
	Node* head = inputLL(v);
	insert_in_middle(head, 10);
	printLL(head);
}