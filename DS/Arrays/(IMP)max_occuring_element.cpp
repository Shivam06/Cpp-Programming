#include<iostream>
#include<map>
#include<vector>
using namespace std;

#define present(c, e) (c.find(e) != c.end())
#define tr(c, itr) for (auto itr = c.begin(); itr != c.end(); itr++)

typedef vector<int> vi;

int find_max_occuring_element(vi& L, vi& R) {
	
	map<int, int> M;
	int n = L.size();
	for (int i = 0; i < n; i++) {
		if (!present(M, L[i])) {
			M[L[i]] = 0;
		}
		M[L[i]] += 1;

		if (!present(M, R[i]+1)) {
			M[R[i] + 1] = 0;
		}
		M[R[i] + 1] -= 1; 
	}

	int max_occuring_element;
	int prefix_sum = 0;
	int sum = 0;
	tr(M, itr) {
		sum += (*itr).second;
		if (sum > prefix_sum) {
			prefix_sum = sum;
			max_occuring_element = (*itr).first;
		}
	}

	return max_occuring_element;
}

int main() {

	vi L{{1, 5, 9, 13, 21}};
	vi R{{15, 8, 12, 20, 30}};

	cout << find_max_occuring_element(L, R) << endl;
	return 0;
}