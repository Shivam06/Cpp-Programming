#include "../../helper_functions.cpp"

#define next(h) h = h->next;
#define nnext(n,h) Node* n = h->next;

struct Node {
	int data;
	Node* next;

	Node(int x) {
		data = x;
		next = NULL;
	}
};

Node* find_middle(Node* head) {
	Node* slow = head, *fast = head;
	if (head == NULL)
		return head;

	while (fast->next != NULL && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

void add(Node* head, int x) {
	Node* newNode = new Node(x);
	nnext(nxt, head);
	head->next = newNode;
	newNode->next = nxt;
}

Node* delete_node(Node*& head) {
	if (head == NULL)
		return head;

	if(head->next == NULL) {
		Node* temp = head;
		head = NULL;
		delete temp;
		return head;
	}

	head->data = head->next->data;
	Node* temp = head->next;
	head->next = head->next->next;
	delete temp;
	return head;
}

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
		cout << head->data << " ";
		next(head);
	}
	cout << endl;
}

int length(Node* head) {
	
	int count = 0;
	while (head != NULL) {
		count++;
		head = next(head);
		
	}

	return count;
}

// int main() {

// 	vi v{{1,2,3,4,5}};
// 	Node* head = inputLL(v);
// 	printLL(head);
// 	cout << "Lenght is " << len(head) << endl;
// }