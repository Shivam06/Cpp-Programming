#include "../../helper_functions.cpp"

// Given sorted rotated array, find the minimum element in the array.
// IMP - All elements are distinct.

int minimum_sorted_rotated(vi& v, int start, int end, int end_element) {

	if (start > end)
		return -1;

	int mid = (start+end)/2;

	if ((mid <= 0 || v[mid] < v[mid-1]) && (mid >= v.size()-1 || v[mid] < v[mid+1]))
		return v[mid];

	if (v[mid] < end_element) {
		return minimum_sorted_rotated(v, start, mid - 1, end_element);
	} else {
		return minimum_sorted_rotated(v, mid+1, end, end_element);
	}
}

int minimum_sorted_rotated(vi& v) {

	int start = 0;
	int end = v.size() - 1;

	if (end < 1) 
		return v[end];

	if (v[end-1] > v[end] && v[end] < v[start])
		return v[end];

	 return minimum_sorted_rotated(v, start, end-1, v[end]);
}

int main() {
	vvi v;
	v.push_back({12,1,2,3,4,5});
	v.push_back({12,13,14,1,2,3,4,5});
	v.push_back({3,4,5,6,7,8,9,1,2});
	tr(v, itr) {
		cout << minimum_sorted_rotated(*itr) << endl;
	}
	return 0;
}