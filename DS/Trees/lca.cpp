#include "trees.cpp"

Node* lca(Node* root ,int n1 ,int n2 )
{
   if (root == NULL)
        return NULL;
    
    if (root->data == n1 || root->data == n2) {
        return root;
    }
    
    Node* left = lca(root->left, n1, n2);
    Node* right = lca(root->right, n1, n2);
    
    if (left != NULL && right != NULL)
        return root;
    
    return left != NULL? left: right;
}

int main() {
	Node* head = default_input();
	Node* lca2 = lca(head, 50, 60);
	if (lca2 == NULL) {
		cout << "NULL";
	} else {
		cout << lca2->data << endl;
	}
}