#include "helper_functions.cpp"

int kadane(vi& v) {

	int sum = 0, max_sum = 0, max_e = INT_MIN, n = v.size();
	loop(i, n) {
		if (v[i] > max_e) {
			max_e = v[i];
		}

		if (sum + v[i] <= 0) {
			sum = 0;
			continue;
		}

		sum += v[i];
		if (sum > max_sum) {
			max_sum = sum;
		}
	}

	if (max_e < 0) { return max_e; }
	
	return max_sum;
}

int main() {

	vi v{{-1, -3, -1, -2, 0}};
	cout << kadane(v) << endl;
	return 0;
}