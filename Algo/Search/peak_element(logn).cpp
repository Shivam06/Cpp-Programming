#include "../../helper_functions.cpp"

// Find peak element in an unsorted array.
// Peak means - v[peak] >= v[peak+1] and v[peak] > v[peak-1]
// Corner elements can be a peak as well.

int peak_element(vi& v, int start, int end) {
	int mid = (start + end)/2;

	if (start > end) {
		return -1;
	}

	if ((mid + 1 > v.size()-1 || v[mid] >= v[mid+1]) && (mid  - 1 < 0 || v[mid] >= v[mid-1])) {
		return v[mid];
	}

	int prev = INT_MIN, next = INT_MIN;
	if (mid + 1 <= v.size()-1){
		next = v[mid+1];
	}
	if (mid-1 >= 0) {
		prev = v[mid - 1];
	}

	if (next > prev)
		return peak_element(v,mid+1,end);
	
	return peak_element(v,start, mid-1);
}

int peak_element(vi& v) {
	if (v.size() == 1)
		return v[0];
	return peak_element(v, 0, v.size()-1);
}

int main() {
	vvi v;
	v.push_back({1, 2, 3, 4, 5});
	v.push_back({5,4,3,2,1});
	v.push_back({1,1,1,1,1});
	v.push_back({1,2,3});
	v.push_back({3,4});
	tr(v, itr) {
		cout << peak_element(*itr) << endl;
	}
	return 0;
}