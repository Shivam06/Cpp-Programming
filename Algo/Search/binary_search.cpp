#include "../../helper_functions.cpp"

template<typename T> int binary_search (vector<T>& v, int start, int end, T x) {
	
	if (start > end) {
		return -1;
	}

	int mid = (start + end)/2;

	if (v[mid] == x)
		return 1;

	if (v[mid] > x) {
		return binary_search(v, start, mid-1, x);
	} else {
		return binary_search(v, mid+1, end, x);
	}
} 

template<typename T> int binary_search(vector<T>& v, T x) {
	return binary_search(v, 0, v.size()-1, x);	
}

int main() {
	
	vi v{{9,4,2,4,6,1,3}};
	sort(all(v));

	int x = 6;

	if (binary_search(all(v), x)) {
		cout << "Present" << endl;
	} else {
		cout << "Not Present" << endl;
	}


	cout << binary_search(v, x) << endl;

}