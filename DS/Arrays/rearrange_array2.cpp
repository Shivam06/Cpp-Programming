#include<iostream>
#include "helper_functions.cpp"
using namespace std;

void arrange(vi& v) {
    int n = v.size();
    long long max_e = *max_element(all(v)) + 1;
    
    for (int i = 0; i < n; i++) {
        int orig_idx = v[i];
        v[i] = v[i] + (v[orig_idx]%max_e)*max_e;
    }
    
    loop(i, n) {
        v[i]= v[i]/max_e;
    }
}

int main() {
	vi v{4, 0, 2, 1, 3};
	arrange(v);
	print_container(v);
}