#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef vector<int> vi;

#define tr(c, itr) for (auto itr = c.begin(); itr != c.end(); itr++)
#define all(c) c.begin(), c.end()

void reverse_in_grp(vi& v, int k) {
	int idx = 0;
	int n = v.size();

	while (idx < n) {
		reverse(v.begin() + idx, v.begin() + min(n, idx + k));
		idx = idx + k;
	}
}

int main() {

	vi v{{1,3,7,9,2,5,6,8}};

	reverse_in_grp(v, 3);
	tr(v, itr) {
		cout << *itr << " ";
	}
	return 0;
}