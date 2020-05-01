#include "../../helper_functions.cpp"

#define next(h) h = h->next;

struct Node {
	int data;
	Node* next;

	Node(int x) {
		data = x;
		next = NULL;
	}
};


Node* inputLL(vi& v) {
	Node* head = NULL;
	Node* temp = head;
	
	tr(v, itr) {

		int num = *itr;

		if (head == NULL) {
			//cout << *itr << " ";
			
			head = new Node(num);
			temp = head;
			continue;
		}

		temp->next = new Node(num);
		temp = temp->next;
	}

	return head;
}

void printLL(Node* head) {
	while (head != NULL) {
		cout << head->data << endl;
		next(head);
	}
}

int len(Node* head) {
	
	int count = 0;
	while (head != NULL) {
		count++;
		head = next(head);
		
	}

	return count;
}

int main() {

	vi v{{1,2,3,4,5}};
	Node* head = inputLL(v);
	printLL(head);
	cout << "Lenght is " << len(head) << endl;
}