#include <iostream>
#include<set>
#include<vector>
using namespace std;

#define all(c) c.begin(),c.end() 
#define tr(c, itr) \
for (auto itr = c.begin(); itr!=c.end(); itr++)
#define present(c, element) c.find(element) != c.end()


template< typename T > void printContainer(T v) {
	tr(v, itr) {
		cout << *itr << " ";
	}
	cout << endl;
}

int main() {

	vector<int> v{{1,3,2,5,4,10,8,7}};
	printContainer(v);

	set<int> s(all(v));
	printContainer(s);

	s.insert(6);
	printContainer(s);

	// Finding an element.
	int data = 11;
	if (present(s, data)) {
		cout << data << " is present." << endl;
	}
	else {
		cout << data <<" is not present." << endl;
	}

	s.erase(3);
	printContainer(s);

	auto itr1 = s.find(2);
	auto itr2 = s.find(11);
	if (itr1 != s.end()) {
		s.erase(itr1, itr2);
	}
	printContainer(s);
	return 0;
}
