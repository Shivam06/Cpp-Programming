#include "trees.cpp"

void width(Node* root, int dir, int x, int& min, int& max) {
    
    if (root == NULL) {
        return;
    }
    
    if (dir == 0) {
        // Nothing
    } else if (dir > 0) {
        x++;
        max = x > max? x: max;
    } else {
        x--;
        min = x < min? x: min;
    }
    
    width(root->left, -1, x, min, max);
    width(root->right, 1, x, min, max);
}

// your task is to complete this functionh
// function should return the width of the tree
int verticalWidth(Node* root)
{
    if (root == NULL)
        return 0;
        
    int min = 0, max = 0, x = 0;
    width(root, 0, x, min, max);
    return max - min + 1;
}

int main() {
	Node* head = default_input();
	cout << verticalWidth(head) << endl;
	return 0;
}