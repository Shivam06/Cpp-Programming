#include<iostream>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

void insert_at_idx(int arr[], int size, int idx, int val) {
	for (int i = size-1; i > idx; i--) {
		arr[i] = arr[i-1];
	}
	arr[idx] = val;
}

int main() {

	int arr[5] = {1,2,3,4,0};
	insert_at_idx(arr, 5, 2, 90);

	loop(i, 5) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}