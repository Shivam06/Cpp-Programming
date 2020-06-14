#include "trees.cpp"

Node* LCA(Node *root, int n1, int n2)
{
    if (root == NULL || root->data == n1 || root->data == n2 || (root->data > n1 && root->data < n2)
        || (root->data < n1 && root->data > n2)) {
        return root;
    } else if (root->data < n1) {
        return LCA(root->right, n1, n2);
    } else {
        return LCA(root->left, n1, n2);
    }
}


int main() {
	Node* root = default_input();
	Node* lca = LCA(root, 12, 20);
	cout << lca->data << endl;
}