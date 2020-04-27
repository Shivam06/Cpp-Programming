#include "../../helper_functions.cpp"

int floor(vi& v, int start, int end, int x) {
	
	int mid = (start + end)/2;

	if (start > end)
	{
		return -1;
	}

	if (v[mid] > x) {
		return floor(v, start, mid-1, x);
	}
	else {
		if (v[mid] == x || mid + 1 > v.size()-1 || v[mid + 1] > x) 
			return mid;
		else 
			return floor(v, mid+1, end, x);
	}
}

int floor(vi& v, int x) {
	return floor(v, 0, v.size()-1, x);
}

int main() {

	vi v{{1,2,3,4,6}};
	cout << floor(v,0) << endl;
	
	return 0;	
}