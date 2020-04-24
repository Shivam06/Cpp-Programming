#include "../../helper_functions.cpp"

// Find cout of 1s in non increasing binary array.

template<typename T> int reverse_upper_bound_idx(vector<T>& v, int start, int end, T x) {
	
	int mid = (start + end)/2;

	if (start > end) 
		return -1;

	if (v[mid] == x) {
		if (mid == end || v[mid] != v[mid + 1]) {
			return mid;
		}

		return reverse_upper_bound_idx(v, mid + 1, end, x);
	}

	if (v[mid] > x) {
		return reverse_upper_bound_idx(v, mid + 1, end, x);
	} else {
		return reverse_upper_bound_idx(v, start, mid-1, x);
	}
}

int count_of_one(vi& v) {
	return reverse_upper_bound_idx(v, 0, v.size()-1, 1) + 1;
}

int main() {

	vi v{{0,0}};
	cout << count_of_one(v) << endl;
}