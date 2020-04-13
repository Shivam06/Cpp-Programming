#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> vi;
#define tr(c, itr) for (auto itr = c.begin(); itr != c.end(); itr++)
#define loop(i, n) for (int i = 0; i < n; i++)

template<typename T> void printC(vector<T>& v) {
	tr(v, itr) {
		cout << *itr << " ";
	} 
	cout << endl;
} 

void frequencies_of_limited_range2(vi v) {
	
	int n = v.size();
	loop(i, n) { v[i]--; }
	loop(i, n) { v[v[i]%n] += n; }
	loop(i, n) { cout << v[i]/n << " "; }
 }

void frequencies_of_limited_range(vi v) {
	int n = v.size();
	int i = 0;

	while(i < n) {
		if (v[i] <= 0) {
			i++;
			continue;
		}

		int element_idx = v[i]-1;
		if (v[element_idx] < 0) {
			v[element_idx]--;
			v[i] = 0;
			i++;
			continue;
		}
		else {
			v[i] = v[element_idx];
			v[element_idx] = -1;

			continue;
		}
	}

	tr(v, itr) {
		*itr = -1*(*itr);
	}
	printC(v);
}

int main() {
	vi v{{4,5,2,5,1}};
	cout << "Output: " << endl;
	frequencies_of_limited_range2(v);
	cout << "Original Array: " << endl;
	printC(v);
	return 0;
}