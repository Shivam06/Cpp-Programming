#include "helper_functions.cpp"

bool is_ascending(vi& v, int n) {
	int count_inc = 0;
	int count_dec = 0;
	loop(i, n-1) {
		if (v[i] < v[i+1])
			count_inc++;
		else
			count_dec++;
	}

	return count_inc > count_dec;
}

bool is_sorted_rotated(vi& v) {

	int n = v.size();
	if (n == 2)
		return false;
	
	int inflex = -1;
	int decreasing = !is_ascending(v,n);

	if (is_ascending(v, n)) {
		inflex = min_element(all(v)) - v.begin();
	} else {
		inflex = max_element(all(v)) - v.begin();
	}

	//cout << inflex << endl;

	if (inflex == 0) 
		return false;

	int i = inflex;

	do {
		if ((v[i%n] - v[(i+1)%n])*decreasing < 0) {
			return false;
		}

		i++;
		
	} while ((i+1)%n != inflex);
	
	return true;
}

int main() {
	vi v{{30,20,10,50,15,35}};
	cout << is_sorted_rotated(v) << endl;
}