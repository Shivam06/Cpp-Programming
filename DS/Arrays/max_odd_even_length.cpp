#include "helper_functions.cpp"

int max_odd_even_len(vi& v) {

	int len = 1, max_len = 1, n = v.size();
	loop(i, n-1) {
		if (v[i]%2 == v[i+1]%2) {
			len = 1;
			continue;
		}

		len += 1;
		if (len > max_len) {
			max_len = len;
		}
	}

	return max_len;
}

int main() {
	vi v{{10, 12, 14, 7, 8}};
	cout << max_odd_even_len(v) << endl;
	return 0;
}