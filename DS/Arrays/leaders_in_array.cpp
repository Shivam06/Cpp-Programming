#include<iostream>
#include "helper_functions.cpp"
using namespace std;

vector<int> leaders(int arr[], int n){
    
    vi output;
    int max = 0;
    
    for (int i = n-1; i >= 0; i--) {
        
        if (arr[i] < max)
            continue;
    
        pb(output, arr[i]);
        max = arr[i];
    }
    
    reverse(output.begin(), output.end());
    return output;
}


int main() {
	int arr[] = {1, 5, 3, 4};
	vi output = leaders(arr, 4);
	print_container(output);
	return 0;
}
