#include "traversals.cpp"
#include<queue>

struct LLNode {
	int data;
	LLNode* next;

	LLNode(int x) {
		this->data = x;
		this->next = NULL;
	}
};

void convert(LLNode *head, Node *&root) {
    
    queue<Node*> q;
    if (head == NULL) {
        root = NULL;
        return;
    }
    
    root = new Node(head->data);
    q.push(root);
    
    while (head->next != NULL) {
        Node* temp = q.front();
        q.pop();
        head = head->next;
        temp->left = new Node(head->data);
        q.push(temp->left);
        
        if (head->next == NULL)
            break;
            
        head = head->next;
        temp->right = new Node(head->data);
        q.push(temp->right);
    }
}

int main() {
	LLNode* head = new LLNode(3);
	head->next = new LLNode(4);
	head->next->next = new LLNode(5);
	head->next->next->next = new LLNode(6);
	Node* tree = NULL;
	convert(head, tree);
	inorder(tree);
}