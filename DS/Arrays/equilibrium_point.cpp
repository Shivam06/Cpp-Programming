#include<iostream>
using namespace std;

int equilibriumPoint(long long a[], int n) {
    long long total_sum = 0;
    
    for (int i = 0; i < n; i++) {
        total_sum += a[i];
    }
    
    long long left_sum = 0;
    for (int i = 0; i < n; i++) {
        if (left_sum == total_sum - left_sum - a[i]) {
            return i+1;
        }
        left_sum += a[i];
    }
    
    return -1;
}

int main() {

	long long arr[] = {1, 3, 5, 2, 2};
	int size = sizeof(arr)/sizeof(long long);

	cout << equilibriumPoint(arr, size) << endl;
	return 0;
}