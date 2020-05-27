#include "trees.cpp"

void level_order(Node* head) {

	queue<Node*> q;
	q.push(head);

	while (!q.empty()) {
		int size = q.size();
		bool notNull = false;
		while (size) {

			Node* temp = q.front();
			q.pop();

			if (temp == NULL) {
				size--;
				continue;
			}

			notNull = true;
			cout << temp->data << " ";
			q.push(temp->left);
			q.push(temp->right);
			size--;
		}

		if (notNull)
		cout <<"$ ";
	}
}

int main() {
	Node* head = default_input();
	level_order(head);
}