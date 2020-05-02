#include "basics.cpp"

bool check_identical(Node* h1, Node* h2) {

	Node* t1 = h1, *t2 = h2;

	while (t1 != NULL && t2 != NULL) {
		if (t1->data != t2->data)
			return false;

		next(t1);
		next(t2);
	}

	return (t1 == NULL && t2 == NULL);
}

int main() {
	vi v1{{1,2,3,4,5}};
	vi v2{{1,2,3,4,5}};
	Node* h1 = inputLL(v1);
	Node* h2 = inputLL(v2);
	cout << check_identical(h1, h2) << endl;
}