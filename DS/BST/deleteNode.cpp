#include "traversals.cpp"

Node* pop_max(Node* root, int& val) {
    
    if (root->right == NULL) {
        val = root->data;
        Node* temp = root;
        delete root;
        return temp->left;
    }
    
    root->right = pop_max(root->right, val);
    return root;
}

// Return the root of the modified BST after deleting the node with value X
Node *deleteNode(Node *root,  int X)
{
    if (root == NULL)
        return root;
        
    if (root->data > X) {
        root->left = deleteNode(root->left, X);
    } else if (root->data < X) {
        root->right = deleteNode(root->right, X);
    } else {
        if (root->left == NULL && root->right == NULL) {
            return NULL;
        }
        if (root->left != NULL && root->right == NULL) {
            Node* temp = root;
            root = root->left;
            delete temp;
            return root;
        }
        if (root->right != NULL && root->left == NULL) {
            Node* temp = root;
            root = root->right;
            delete temp;
            return root;
        }
        
        Node* temp = root;
        Node* temp_right = root->right;
        Node* temp_left = root->left;
        int max_val = 0;
        temp_left = pop_max(temp_left, max_val); 
        Node* new_root = new Node(max_val);
        new_root->right = temp_right;
        new_root->left = temp_left;
        delete temp;
        return new_root;
    }
    
    return root;
}

int main() {
	Node* root = default_input();
	inorder(root);
	cout << endl;
	root = deleteNode(root, 10);
	inorder(root);
}