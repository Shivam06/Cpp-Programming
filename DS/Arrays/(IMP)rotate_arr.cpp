#include<iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
        
    return gcd (b, a%b);
}

// Rotate anti-clockwise
void rotateArr(int arr[], int d, int n){
    
    int c = n - (d%n);
    for (int i = 0; i < gcd(n,c); i++) {
        
        int temp = arr[i];
        int idx = (i + c)%n;
        while (idx != i) {
            swap(temp, arr[idx]);
            idx = (idx + c)%n;
        }
        
        swap(temp, arr[idx]);
    }
    
}

void print_arr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int d = 3;
	int n = 12;
	rotateArr(arr, d, n);

	print_arr(arr, n);
}