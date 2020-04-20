#include "helper_functions.cpp"

int involved_i = 0;
int generic_kadane(vi& v, int start, int increment) {

	int max_e = INT_MIN, sum = 0, max_sum = 0, n = v.size(), i = start;

	do {
		if (v[i] > max_e) 
			max_e = v[i];

		if (sum + v[i] < 0) {
			cout << "Skipping " << i << endl;
			sum = 0;
			i = (i + increment)%n;
			continue;
		}

		sum = sum + v[i];
		cout << "Adding " << v[i] << endl;
		if (sum > max_sum) {
			max_sum = sum;
			involved_i = i;
		}
		if (increment == -1 && i == 0) {
			i = n-1;
		} else {
			i = (i + increment)%n;
		}
		continue;
	} while (i != start);

	if (max_e < 0)
		return max_e;

	return max_sum;
}


int max_circular_subarray_sum(vi& v) {

	int max_idx = max_element(all(v)) - v.begin();
	int n = v.size();
	int sum = generic_kadane(v, involved_i, 1);
	if (sum < 0)
		return sum;

	cout <<involved_i <<endl;

	cout << "first sum " << sum;
	cout << endl << "Next sum" << endl;

	int rsum = generic_kadane(v, involved_i, -1);
	cout <<"Second sum " << rsum << endl;
	return max(sum, rsum);
}

int main() {

	vvi v2;
	//v2.push_back({{12, -5, 4, -8, 11}});
	//v2.push_back({{10, -3, -4, 7, 6, 5, -4, -1}});
	v2.push_back({{686,577,715,593,135,186,292,449,221,162,-173,490,-141,563,726,340,226,-28,536,11,168,367,229,582,330,662,-77,-133,-65,729,602,-178,-142,-131,-33,193,256,-189,-158,29,173,221,719,584,337,-2,124,115,170,213,326,-109,780,756,673,662,-30,796,81,105,725,-116,127,136,305,646,529,113,657,-76,695,382,345,614,167,234,164,-157,550,-113,608,76,-22,588
}});

	tr(v2, itr) {
		cout << max_circular_subarray_sum(*itr) << endl;
	}
	
	//cout << generic_kadane(v, v.size()-1, 1) << endl;
	return 0;
}