#include "../../helper_functions.cpp"

int water_trapped(vi& v, int minI, int maxI) {
	return (max(0, maxI - minI - 1) * min(v[minI], v[maxI]));
}

int max_water_trapped(vi& v) {
	
	int minI = 0, maxI = v.size() - 1, max = 0;

	while (minI < maxI) {
		int w = water_trapped(v, minI, maxI);
		if (w > max)
			max = w;

		if (v[minI] < v[maxI]) {
			minI++;
		} else {
			maxI--;
		}
	}

	return max;
}

int main() {
	vi v{{2, 1, 3, 4, 6, 5}};
	cout << max_water_trapped(v) << endl;
	return 0;
}