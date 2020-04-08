#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<int, int> vii;
typedef pair<int, int> ii;

#define all(c) c.begin(), c.end()
#define present(c, e) c.find(e) != c.end()
#define tr(c, itr) for (auto itr = c.begin(); itr != c.end(); itr++)

template<typename T> void printContainer(T c) {
	tr(c, itr) {
		cout << *itr << " ";
	}
	cout << endl;
}

bool greaterInt(int a, int b) {
	return a > b;
}

int main() {
	vi v{{1,8,2}};
	printContainer(v);
	cout << endl;

	sort(all(v));
	printContainer(v);
	sort(all(v), greater<int>());
	printContainer(v);
	sort(all(v), greaterInt);
	printContainer(v);
	cout << endl;

	// Remember - Set/ Map has methods - find and count which takes less time than fundtion
	// std::find and std::count.
	cout << count(all(v), 1) << endl;

	while (next_permutation(all(v))) {
		printContainer(v);
	}
	cout << endl;

	cout << *max_element(all(v)) << endl;
	cout << *min_element(all(v)) << endl;
	cout << max(1,3) << endl;

	return 0;
}