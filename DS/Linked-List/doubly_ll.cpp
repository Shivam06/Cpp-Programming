#include "../../helper_functions.cpp"

#define next(n) n = n->next;
#define nnext(n,h) Dnode* n = h->next;

struct Dnode {
	int data;
	Dnode* next;
	Dnode* prev;

	Dnode(int x) {
		data = x;
		next = NULL;
		prev = NULL;
	}
};

pair<Dnode*, Dnode*> inputLL(vi& v) {
	Dnode* head = NULL;
	Dnode* temp = head;
	
	tr(v, itr) {

		int num = *itr;

		if (head == NULL) {
			//cout << *itr << " ";
			
			head = new Dnode(num);
			temp = head;
			continue;
		}

		Dnode* next = new Dnode(num);
		temp->next = next;
		next->prev = temp;
		temp = next;
	}

	return make_pair(head, temp);
}

void fprintLL(Dnode* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;	
	}
	cout << endl;
}

void bprintLL(Dnode* tail) {
	while (tail != NULL) {
		cout << tail->data << " ";
		tail = tail->prev;
	}
	cout << endl;
}

void add(Dnode* head, int pos, int x) {

	Dnode* temp = head;
	int idx = 0;
	while (idx < pos) {
		next(temp);
		idx++;
	}

	nnext(nxt, temp);
	Dnode* newDnode = new Dnode(x);
	newDnode->prev = temp;
	temp->next = newDnode;
	newDnode->next= nxt;
	if (nxt != NULL)
		nxt->prev = newDnode;

}

int main() {

	vi v{{1, 2, 3, 4, 5}};
	pair<Dnode*, Dnode*> dnodes = inputLL(v);
	Dnode* head = dnodes.first;
	Dnode* tail = dnodes.second;
	fprintLL(head);
	bprintLL(tail);
	add(head, 2, 3);
	fprintLL(head);
	return 0; 
}