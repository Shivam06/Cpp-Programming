#include "helper_functions.cpp"


int kadane(vi& v) {

	int sum = 0, max_sum = 0, max_e = INT_MIN, n = v.size();
	loop(i, n) {
		if (v[i] > max_e) {
			max_e = v[i];
		}

		if (sum + v[i] <= 0) {
			sum = 0;
			continue;
		}

		sum += v[i];
		if (sum > max_sum) {
			max_sum = sum;
		}
	}

	if (max_e < 0) { return max_e; }
	
	return max_sum;
}


int max_circular_subarray_sum(vi& v) {

	int non_wrapping_sum = kadane(v);
	if (non_wrapping_sum < 0)
		return non_wrapping_sum;

	int array_sum = 0;
	loop(i, v.size()) {
		array_sum += v[i];
		v[i]*=-1;
	}

	int wrapping_sum = array_sum + kadane(v);
	return max(wrapping_sum, non_wrapping_sum);
}

int main() {

	vvi v2;
	v2.push_back({{12, -5, 4, -8, 11}});
	v2.push_back({{10, -3, -4, 7, 6, 5, -4, -1}});
	v2.push_back({{686,577,715,593,135,186,292,449,221,162,-173,490,-141,563,726,340,226,-28,536,11,168,367,229,582,330,662,-77,-133,-65,729,602,-178,-142,-131,-33,193,256,-189,-158,29,173,221,719,584,337,-2,124,115,170,213,326,-109,780,756,673,662,-30,796,81,105,725,-116,127,136,305,646,529,113,657,-76,695,382,345,614,167,234,164,-157,550,-113,608,76,-22,588
}});

	tr(v2, itr) {
		cout << max_circular_subarray_sum(*itr) << endl;
	}
	
	//cout << generic_kadane(v, v.size()-1, 1) << endl;
	return 0;
}