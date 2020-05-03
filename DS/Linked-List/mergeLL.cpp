#include "basics.cpp"

Node* mergeLL(Node* h1, Node* h2) {

	Node* t1, *p1, *t2, *p2;
	t1 = h1, t2 = h2, p1 = NULL, p2 = NULL;

	while (t1 != NULL && t2 != NULL) {

		if (t1->data > t2->data) {
			Node* temp2 = t2->next;
			if (p1 == NULL) {
				h1 = t2;
			} else {
				p1->next = t2;
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

	return h1;
}

int main() {

	vi v1{{1,4,8,9}};
	vi v2{{0,5,6,10}};
	Node* h1 = inputLL(v1);
	Node* h2 = inputLL(v2);
	h1 = mergeLL(h1, h2);
	printLL(h1);
	return 0;
}