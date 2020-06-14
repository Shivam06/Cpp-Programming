#include "trees.cpp"

void printSpiral(Node *root)
{ 
    queue<Node*> q;
    int dir = 0;
    if (root != NULL) {
        cout << root->data << " ";
        q.push(root);
    }

    while (!q.empty()) {
        stack<Node*> s;
        int size = q.size();
        
        while (size) {
            Node* temp = q.front();
            q.pop();
            if (dir%2==1) {
                s.push(temp->left);
                s.push(temp->right);
            } else {
                s.push(temp->right);
                s.push(temp->left);
            }
            size--;
        }
        
        while (!s.empty()) {
            if (s.top() != NULL) {
                q.push(s.top());
                cout << s.top()->data << " ";
            }
            s.pop();
        }
        
        dir++;
    }
    
}

int main() {
	Node* head = default_input();
	printSpiral(head);
}
