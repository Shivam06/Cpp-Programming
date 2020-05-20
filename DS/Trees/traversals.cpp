#include "trees.cpp"

void preorder(Node* head) {

	if (head == NULL)
		return;

	cout << head->data << " ";
	preorder(head->left);
	preorder(head->right);
}

void inorder(Node* head) {

	if (head == NULL)
		return;

	inorder(head->left);
	cout << head->data << " ";
	inorder(head->right);
}

void postorder(Node* head) {
	if (head == NULL)
		return;

	postorder(head->left);
	postorder(head->right);
	cout << head->data << " ";
}

void preorder_itr(Node* head) {

	stack<Node*> s;
	s.push(head);

	while (!s.empty()) {
		Node* temp = s.top();
		s.pop();
		if (temp == NULL)
			continue;

		cout << temp->data << " ";
		s.push(temp->right);
		s.push(temp->left);
	}

}

int main() {
	Node* head = default_input();
	cout << "PREODER RECURSIVE: "<<endl;
	preorder(head);
	cout << endl;
	cout << "PREORDER ITERATIVE: " << endl;
	preorder_itr(head);
	cout << endl;
	cout << "INORDER: " << endl;
	inorder(head);
	cout << endl;
	cout << "POSTORDER: " << endl;
	postorder(head);
	cout << endl;
}