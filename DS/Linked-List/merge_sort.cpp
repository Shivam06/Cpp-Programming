#include "basics.cpp"

void merge(Node*& h1, Node* h2) {

	Node* t1 = h1, *t2 = h2;
	Node* p1 = NULL, *p2 = NULL;

	while (t1 != NULL && t2 != NULL) {

		if (t1->data > t2->data) {

			Node* temp2 = t2->next;
			if (p1 != NULL) { 
				p1->next = t2;
			} else {
				h1 = t2;
			}
			t2->next = t1;
			p1 = t2;
			t2 = temp2;
			continue;
		}

		p1 = t1;
		t1 = t1->next;
	}

	if (t2 != NULL) {
		p1->next = t2;
	}
}

void merge_sort(Node*& head) {

	if (head == NULL || head->next == NULL)
		return;

	Node* mid = find_middle(head);
	Node* mid_next = mid->next;
	//cout << mid_next->data << endl;
	mid->next = NULL;

	merge_sort(head);

	merge_sort(mid_next);

	//cout << head->data << " " << mid_next->data <<endl;
	merge(head, mid_next);
}

int main() {
	vi v{{12,10,4,2,1,5}};
	Node* head = inputLL(v);
	merge_sort(head);
	printLL(head);

	// vi v1{2};
	// vi v2{1};
	// Node* h1 = inputLL(v1);
	// Node* h2 = inputLL(v2);
	// merge(h1, h2);
	// printLL(h1);
}