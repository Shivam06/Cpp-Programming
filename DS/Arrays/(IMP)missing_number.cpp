#include "helper_functions.cpp"

void change_neg_to_zero(vi& v) {

	tr (v, itr) {
		if (*itr < 0) {
			*itr = 0;
		}
	}
}

int missingNumber(vi& v) {

	change_neg_to_zero(v);

	int i = 0, n = v.size(); 

	while (i < n) {

		if (v[i] <= 0 || v[i] > n) {
			//cout << "Skipping" << endl;
			i++;
			continue;
		}

		int new_idx = v[i]-1;

		// This check is important for cases where value 
		// being swapped and the value being swapped to are the same.
		if (v[new_idx] < 0) {
			i++;
			continue;
		}

		if (i != new_idx)
			swap(v[i], v[new_idx]);
		v[new_idx]*=-1;

	}

	tr(v, itr) {
		if (*itr >= 0) {
			return (itr - v.begin() + 1);
		}
	}

	return v.size()+1;
}

int main() {
	
	vi v{{33, -50, 18, -34, -4, -1, -13, -29, 9, -47, 37, -29, -8, -7, 25, 27, -40, 12, 36, 20, 47, 43, -33, 11, -22, -26, -33, 16, 8, 9, 16, 43, 9, 36, -41, 7, -15, -4, -20, 45, -48, -33, -34, 46, -37, 42, 24, -27, -44
}};
	cout << missingNumber(v) << endl;
	return 0;
}