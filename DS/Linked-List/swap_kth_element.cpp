#include "basics.cpp"

void swap_kth_node(Node* head, int k) {
	
	Node* fk = head, *rk = head;

	Node* slow = head, *fast = head;
	int i = 1;
	while (i < k) {
		fast = fast->next;
		if (fast == NULL)
			return;
		i++;
	}

	fk = fast;

	while (fast->next != NULL) {
		fast = fast->next;
		slow = slow->next;
	}

	rk = slow;
	//cout << rk->data << endl;
	int temp = fk->data;
	fk->data = rk->data;
	rk->data = temp;
}

int main() {

	vi v{{715, 601, 895, 385, 506}};
	Node* n1 = inputLL(v);
	swap_kth_node(n1, 2);
	printLL(n1);
	return 0;
}