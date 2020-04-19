#include<iostream>
#include "helper_functions.cpp"
using namespace std;

int max_e = 1;

bool compare_function(int a, int b) {

	if (a%max_e == b%max_e) {
		return a/max_e < b/max_e;
	}
	return a%max_e < b%max_e;
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

	int maxDiff = -1;  
  
    rloop(i, n-2) {
       int diff = v[i+1] - v[i];
       maxDiff = max(maxDiff, diff);
       v[i] = max(v[i+1], v[i]);
    }

	return maxDiff;
}

int main() {

	vi v{5,3,4,4,3,2};
	cout << max_diff(v) << endl;
	return 0;
}