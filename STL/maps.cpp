#include<iostream>
#include<map>
using namespace std;

#define present(c, e) c.find(e) != c.end()
#define tr(c, itr) \
for (auto itr = c.begin(); itr != c.end(); itr++)
#define all(c) c.begin(), c.end()

template< typename T > void printContainer(T v) {
	tr(v, itr) {
		cout << *itr << " ";
	}
	cout << endl;
}

template<typename T1, typename T2> void printMap(map<T1,T2> m) {
	tr(m, itr) {
		cout << (*itr).first << " " << (*itr).second << endl;
	}
}

int main() {

	map<string, string> m;
	m["shivam"] = "megha";
	m["pradeep"] = "neelam";
	m["anant"] = "sonia";

	tr(m, itr) {
		cout << (*itr).first << " " << (*itr).second << endl;
	}
	cout << endl;

	if (present(m, "shivam")) {
		cout << "Present" << endl;
		cout << "Related to " << m["shivam"] << endl; // Won't work if map is constant.
		cout << "Related to " << m.find("shivam")->second << endl; // Will work even if m is constant.
	}
	cout << endl;

	m.erase("shivam");
	printMap(m);
	cout << endl;

	m["jiten"] = "neha";
	auto itr = m.find("jiten");
	auto itr1 = itr--;
	auto itr2 = itr++; // ++ and -- works with set, map and vector.
	cout << itr1->first << " " << itr2->first << endl;
	return 0;
}