#include "../../helper_functions.cpp"
#include<unordered_map>
struct Node {

	int data;
	Node* next;
	Node* arb;

	Node(int x) {
		this->data = x;
		this->next = NULL;
		this->arb = NULL;
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
	int count = 0;
	while (head != NULL && count < 100) {
		cout << head->data << " ";
		head = head->next;
		count++;
	}
	cout << endl;
}

// O(N) Space and O(N) Time Complexity.
Node* copyLL(Node* head) {

	unordered_map<Node*, Node*> M;
    Node* temp = head;
    Node* head2 = NULL;
    Node* temp2 = NULL;
    while (temp != NULL) {
        Node* t = new Node(temp->data);
        if (head2 == NULL) {
            head2 = t;
            temp2 = t;
        } else {
            temp2->next = t;
            temp2 = t;
        }
        M[temp] = temp2;
        temp = temp->next;
    }
    
    temp = head;
    temp2 = head2;
    
    while (temp != NULL) {
        if (temp->arb != NULL) {
            temp2->arb = M[temp->arb];
        }
        temp = temp->next;
        temp2 = temp2->next;
    }
    
    return head2;
}

Node* copyLL2(Node* head) {

	Node* temp = head;
	while (temp != NULL) {
		Node* t = new Node(temp->data);
		Node* next = temp->next;
		temp->next = t;
		t->next = next;
		temp = next;
	}

	Node* copy = head->next;
	temp = head;

	while (temp != NULL) {
		if (temp->arb != NULL) {
			temp->next->arb = temp->arb->next;
		}
		temp = temp->next->next;
	}

	temp = head;
	while (temp != NULL) {
		if (temp->next == NULL)
			break;
		temp->next = temp->next->next;
	}

	Node* temp2 = copy;
	while (temp2 != NULL) {
		if (temp2->next == NULL) 
			break;
		temp2->next = temp2->next->next;
	}

	return copy;
}

int main() {

	vi v{{1,2,3,4,5}};
	Node* head = inputLL(v);
	head->arb = head->next->next;
	head->next->arb = head;
	//printLL(head);
	Node* copy = copyLL2(head);
	printLL(copy);
	cout << copy->arb->data << endl;
	return 0;
}