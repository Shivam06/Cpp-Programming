#include "trees.cpp"

int getMaxWidth(Node* root)
{
    queue<Node*> q;
    int max_width = 0;
    if (root != NULL) {
        q.push(root);
        max_width = 1;
    }

    while(!q.empty()) {
        
        int size = q.size();
        //cout << "size " << size <<endl;
        max_width = max(max_width, size);
        
        while (size) {
            Node* temp = q.front();
            q.pop();
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
            }
            size--;
        }
     }
     
     return max_width;
}

int main() {
	Node* head = default_input();
	cout << getMaxWidth(head) << endl;
}
