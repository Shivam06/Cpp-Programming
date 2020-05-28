#include "trees.cpp"


void leftView(Node *root)
{
   if (root == NULL) {
       return;
   }
   
   queue<Node*> q;
   q.push(root);
   
   while (!q.empty()) {
       cout << q.front()->data << " ";
       int size = q.size();
       while (size) {
           Node* temp = q.front();
           q.pop();
           if (temp->left != NULL) 
                q.push(temp->left);
           if (temp->right != NULL)
                q.push(temp->right);
           size--;
       }
   }
}

int main() {
	Node* root = default_input();
	leftView(root);
}