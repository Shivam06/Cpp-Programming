#include<iostream>
#include "helper_functions.cpp"
using namespace std;

int max_e = 1;

bool compare_function(int a, int b) {
	return a%max_e <= b%max_e;
}

int max_diff(vi v) {

	int n = v.size();
	max_e = *max_element(all(v))+1;

	loop(i, n) {
		v[i] = v[i] + max_e*i;
	}

	sort(all(v), compare_function);

	
	loop(i, n) {
		v[i] = v[i]/max_e;
	}

	//print_container(v);

	int max_diff = 0;


	int temp[n];
	temp[n-1] = v[n-1];

	rloop(i, n-2) {
		temp[i] = max(v[i], temp[i+1]);
	}

	int ans = INT_MIN;
	loop(i, n) {
		ans = max(ans, temp[i] - v[i]);
	}

	return ans;
}

int main() {

	vi v{3,4,4,3,5};
	cout << max_diff(v) << endl;
	//print_container(v);
	return 0;
}