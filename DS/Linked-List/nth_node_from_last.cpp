#include "basics.cpp"

Node* nth_node_from_end(Node* head, int k) {

	int len = length(head);
	if (k > len)
		return NULL;
	int fk = len - k;

	int i = 0;
	Node* temp = head;
	while (i < fk) {
		temp = temp->next;
		i++;
	}

	return temp;
}

int getNthFromLast(Node *head, int n)
{
	Node* node = nth_node_from_end(head, n);
    return node == NULL? -1: node->data;
}

int main() {

	vi v1{{1, 2, 3, 4, 5, 6, 7, 8, 9}};
	Node* n1 = inputLL(v1);
	cout << getNthFromLast(n1, 10) << endl;

	return 0;
}