#include "trees.cpp"

void right_view_itr(Node* root) {
	if (root == NULL) {
       return;
   }
   
   queue<Node*> q;
   q.push(root);
   
   while (!q.empty()) {
    
        int size = q.size();
        while (size) {
           Node* temp = q.front();
           if (size == 1) {
               cout << temp->data << " ";
           }
           q.pop();
           if (temp->left != NULL) 
                q.push(temp->left);
           if (temp->right != NULL)
                q.push(temp->right);
           size--;
       }
   }
}

void right_view_rec_helper(Node* root, int level, int& max_level) {

	if (root == NULL)
		return;

	if (level > max_level) {
		cout << root->data << " ";
		max_level = level;
	}
	right_view_rec_helper(root->right, level+1, max_level);
	right_view_rec_helper(root->left, level+1,max_level);
}

void right_view_rec(Node* root) {
	int level = 0;
	int max_level = 0;
	cout << root->data << " ";
	right_view_rec_helper(root, level, max_level);
}

int main() {
	Node* head = default_input();
	right_view_itr(head);
	cout << endl;
	right_view_rec(head);
	return 0;
}