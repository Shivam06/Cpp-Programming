#include "basics.cpp"

Node* reverseLL(Node* head) {
	
	Node* temp = head;
	Node* pre = NULL;

	while (temp != NULL) {
		Node* next = temp->next;
		temp->next = pre;
		pre = temp;
		temp = next;
	}

	return pre;
}

int main() {

	vvi vv;
	vv.push_back({{2,5,3,9,10}});
	vv.push_back({{1,9,5,2,3}});
	vv.push_back({1});
	tr(vv, itr) {
		vi v = *itr;
		Node* head = inputLL(v);
		head = reverseLL(head);
		printLL(head); 
	}
	return 0;
}