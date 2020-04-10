#include<iostream>
using namespace std;

#define all(c) c.begin(), c.end()
#define tr(c, itr) for (auto itr = c.begin(); itr != c.end(); itr++)
#define present(c, e) c.find(all(c), e) != c.end()
#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef pair<int, int> ii;

struct Node {
	int a;
};

	
// In C++ array parameter works via pass by reference by default.
// When you are passing arr in a function,
// the new arr formed is reference of the original
// arr. Since arr variable is reference to the first element of the arrays.
void insert_in_array(int arr[], int size, int element) {
	arr[size-1] = element;
}

void test_pass_by_value(int a) {
	a = 3;
}

void test_pass_by_value2(Node n) {
	n.a = 4;
}

void test_pass_by_ref(int& a) {
	a = 3;
}

void test_pass_by_ref2(int* a) {
	*a = 5;
}

void test_pass_by_ref3(Node* n) {
	n->a = 6;
}

int main() {

	const int size = 4;
	int arr[size] = {1,2,3,0};

	insert_in_array(arr, size, 6);

	loop(i, size) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;

	int a = 6;
	cout << "original value " << a << endl;
	test_pass_by_value(a);
	cout << "test_pass_by_value " << a << endl << endl;

	cout << "original value " << a << endl;
	test_pass_by_ref(a);
	cout << "test_pass_by_ref " << a << endl << endl;

	cout << "original value " << a << endl;
	int* aptr = &a;
	test_pass_by_ref2(aptr);
	cout << "test_pass_by_ref2 " << a << endl << endl;

	Node node;
	node.a = 3;

	cout << "original value " << a << endl;
	test_pass_by_value2(node);
	cout << "test_pass_by_value2 " << node.a << endl << endl;

	Node* nodePtr = &node;
	cout << "original value " << a << endl;
	test_pass_by_ref3(nodePtr);
	cout << "test_pass_by_value2 " << node.a << endl << endl;
	return 0;
}