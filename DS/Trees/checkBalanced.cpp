#include "trees.cpp"

int isBalancedHelper(Node* root, bool& balanced) {
    if (root == NULL) {
        return -1;
    }
    
    if (!balanced)
        return -1;
    
    int leftH = isBalancedHelper(root->left, balanced) + 1;
    int rightH = isBalancedHelper(root->right, balanced) + 1;
    if (abs(leftH - rightH) > 1) 
        balanced = false;
    return max(leftH, rightH);
}

// This function should return tree if passed  tree 
// is balanced, else false. 
bool isBalanced(Node *root)
{
    bool balanced = true;
    isBalancedHelper(root, balanced);
    return balanced;
}

int main() {
    Node* head = default_input();
    cout << isBalanced(head) << endl;
}