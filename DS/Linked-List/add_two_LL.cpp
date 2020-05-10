#include "basics.cpp"

Node* reverse(Node* head, int& count) {
	Node * prev = NULL;
	Node* temp = head;

	while (temp != NULL) {
		count++;
		Node* next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}

	head = prev;
	return head;
}

Node* add_two_LL(Node* first, Node* second) {

	int c1 = 0, c2 = 0;
	first = reverse(first, c1);
	second = reverse(second, c2);
	//cout << c1 << " " << c2 << endl;

	if (c2 > c1) {
		Node* temp = first;
		first = second;
		second = temp;
	}
	// First is bigger now.

	bool carry = false;

	Node* temp_f = first;
	Node* temp_s = second;

	Node* pre = NULL;
	while (temp_s != NULL) {

		int sum = temp_s->data + temp_f->data + int(carry);
		//cout << int(carry) << " " << sum << endl;
		temp_f->data = sum%10;
		carry = sum/10;
		pre = temp_f;
		temp_s = temp_s->next;
		temp_f = temp_f->next;
	}


	if (temp_f != NULL) {
		//cout << " Not null " << endl; 
		while (carry) {
			int sum = temp_f->data + int(carry);
			temp_f->data = sum%10;
			carry = sum/10;
			temp_f = temp_f->next;
		}
	} else if (carry) {
		//cout << " NULL " << endl;
		pre->next = new Node(carry);
	}

	//printLL(first);
	int c3 = 0;
	return reverse(first, c3);
}

int main() {

	vi v1{9};
	vi v2{{8,7}};
	Node* first = inputLL(v1);
	Node* second = inputLL(v2);

	Node* output = add_two_LL(first, second);
	printLL(output);
}