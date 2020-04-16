#include<iostream>
#include "helper_functions.cpp"
using namespace std;


void rearrange_array(vi& v) {
	
	int n = v.size();

	int max_value = *max_element(all(v)) + 1;
	int max_idx = n-1;
	int min_idx = 0;

	for (int i = 0; i < n; i++) {
		
		if (i%2==0) {
			v[i] = v[i] + (v[max_idx]%max_value)*max_value;
			max_idx--;
			continue;
		}

		v[i] = v[i] + (v[min_idx]%max_value)*max_value;
		min_idx++;
	}

	for (int i = 0; i < n; i++) {
		v[i] = v[i]/=max_value;
	}
}

int main() {

	vi v{1,2,3,4,5,6};

	rearrange_array(v);

	print_container(v);
	return 0;
}