#include "trees.cpp"

int diameter_helper(Node* head, int& dia) {
    
    if (head == NULL) {
        return 0;
    }
    
    int left_h = diameter_helper(head->left, dia);
    int right_h = diameter_helper(head->right, dia);
    
    if (dia < left_h + right_h + 1) {
        dia = left_h + right_h + 1;
    }
    
    return max(left_h, right_h) + 1;
}

int diameter_helper_2(Node* head, int& h) {
    
    if (head == NULL) {
        h = 0;
        return 0;
    }
        
    int left_d = diameter_helper_2(head->left, h);
    int left_height = h;
    int right_d = diameter_helper_2(head->right, h);
    int right_height = h;
    
    h = max(left_height, right_height) + 1;
    return max(max(left_d, right_d), left_height + right_height + 1);
}
 
/* Computes the diameter of binary tree with given root.  */
int diameter(Node* node) {
    int diameter = 0;
    return diameter_helper_2(node, diameter);
}

int main() {
    Node* head = default_input();
    cout << diameter(head) << endl;
}