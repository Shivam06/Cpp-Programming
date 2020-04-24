#include "../../helper_functions.cpp"

long long square_root(long long start, long long end, int n) {

	long long mid = (start + end)/2;

	if (mid*mid == n || (mid*mid < n && (mid+1)*(mid+1) > n)) {
		return mid;
	}

	if (mid*mid < n) {
		return square_root(mid + 1, end, n);
	}
	else {
		return square_root(start, mid - 1, n);
	}
}

long long square_root(long long num) {

	if (num <= 1)
		return num;

	return square_root(0, num/2 + 1, num);
}

int main() {
	vi v{{31, 24, 80, 100, 27}};

	tr (v, itr) {
		cout << square_root(*itr) << endl;
	}
	return 0;
}