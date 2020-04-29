#include "../../helper_functions.cpp"

int repeated_element(vi& v, int start, int end) {

	if (start > end)
		return -1;

	int mid = (start + end)/2;

	if ((mid-1>=0 && v[mid-1]==v[mid]) || (mid+1<v.size() && v[mid+1] == v[mid])) {
		return mid;
	}

	if (v[end] - v[mid] < end - mid) {
		return repeated_element(v, mid + 1, end);
	} else {
		return repeated_element(v, start, mid - 1);
	}
}

ii count_only_repeated(vi& v) {
	int x = repeated_element(v, 0, v.size() - 1);

	auto li = lower_bound(v.begin(), v.begin() + x, v[x]);
	auto ui = upper_bound(v.begin() + x, v.end(), v[x]);

	return make_pair(v[x], ui - li);
}

int main() {
	vi v{{1,2,3,3,3,4}};
	ii p = count_only_repeated(v);
	cout << p.first << " " << p.second << endl;
}