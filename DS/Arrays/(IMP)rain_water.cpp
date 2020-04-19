#include "helper_functions.cpp"

// Time - O(n)
// Space - O(n)
// Can be optimized more - 
// 1. Use the concept of storing 2 elements at the same index.
// 2. Some other ways as well on GFG.
int max_rain_water(vi& v) {
	
	int n = v.size();
	vi vc(v.size(), 0);

	int maxl = 0;
	loop(i, n) {
		if (v[i] > maxl) {
			maxl = v[i];
		}
		vc[i] = maxl;
	}

	int maxR = 0;
	int sum = 0;
	rloop(i, n-1) {
		if (v[i] > maxR) {
			maxR = v[i];
		}
		vc[i] = min(maxR, vc[i]);
		sum += (vc[i] - v[i]);
	}

	return sum;
}
 
int main() {
	vi v{7, 4, 0, 9};
	cout << max_rain_water(v) << endl;
}



