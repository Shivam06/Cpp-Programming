#include "../../helper_functions.cpp"


int main() {
	vi v{{4,9,7,2,3,10}};

	auto itr = find(all(v), 3);
	if (itr == v.end()) {
		cout << -1 << endl;
	} else {
		cout << itr - v.begin() << endl;
	}
	return 0;
}