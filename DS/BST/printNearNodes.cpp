#include "traversals.cpp"

vector<int> printNearNodes(Node *root, int low, int high)
{
    vector<int> v;
   	
   	stack<Node*> s;
	Node* cur = root;

	do {
		while (cur != NULL) {
			s.push(cur);
			cur = cur->left;
		}

		cur = s.top();
		s.pop();
		if (cur->data > high) {
			break;
		}

		if (cur->data >= low && cur->data <= high) {
			v.push_back(cur->data);
		}

		cur = cur->right;
	} while (cur != NULL || !s.empty());
    
    return v;
}

int main() {
	Node* root = default_input();
	inorder_itr(root);

	
	cout << endl;
	vector<int> v = printNearNodes(root, 5,10);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}