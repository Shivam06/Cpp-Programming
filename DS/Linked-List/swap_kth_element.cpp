#include "basics.cpp"

Node* swap_kth_node(Node* head, int k, int num) {
	
	Node* fk = head, *rk = head;
	Node* pre_fk = NULL, *pre_rk = NULL;
	Node* slow = head, *fast = head;
	int i = 1;
	while (i < k) {
		pre_rk = fast;
		fast = fast->next;
		if (fast == NULL)
			return NULL;
		i++;
	}

	rk = fast;

	while (fast->next != NULL) {
		fast = fast->next;
		pre_fk = slow;
		slow = slow->next;
	}

	fk = slow;

	if (k > num/2) {
		Node* temp;
		Node* pre_temp = pre_rk;
		temp = rk;

		pre_rk = pre_fk;
		rk = fk;
		pre_fk = pre_temp;
		fk = temp;
	}

	if (pre_rk == NULL) {
		head = fk;
	} else {
		pre_rk->next = fk;
	}

	Node* fk_next = fk->next;
	if (rk->next != fk) {
		fk->next = rk->next;
		pre_fk->next = rk;
	}
	else 
		fk->next = rk;

	rk->next = fk_next;
	return head;
}

int main() {

	vi v{{1,2,3,4}};
	Node* n1 = inputLL(v);
	n1 = swap_kth_node(n1, 4, 4);
	printLL(n1);
	return 0;
}