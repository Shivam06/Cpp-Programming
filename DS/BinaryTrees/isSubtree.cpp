#include "trees.cpp"

bool isSame(Node* T, Node* S) {
    if (T == NULL || S == NULL) {
        return T == NULL && S == NULL;
    }
    
    if (T->data != S->data) {
        return false;
    }
    
    return isSame(T->left, S->left) && isSame(T->right, S->right);
}


/*you are required to
complete this function */
bool isSubTree(Node* T, Node* S) {
    
    if (S == NULL) {
        return true;
    }
    
    if (T == NULL) {
        return false;
    }   
    
    return isSame(T, S) || isSubTree(T->left, S) || isSubTree(T->right, S);
}

int main() {
    Node* T = default_input();
    Node* S = new Node(20);
    S->right = new Node(40);
    cout << isSubTree(T, S) << endl;

    S->right = new Node(30);
    cout << isSubTree(T, S) << endl;
}