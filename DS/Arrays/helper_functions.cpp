#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

#define all(c) c.begin(), c.end()
#define present(c, e) (c.find(e) != c.end())
#define tr(c, itr) for (auto itr = c.begin(); itr != c.end(); itr++)
#define loop(i, n) for (int i = 0; i < n; i++)
#define rloop(i, n) for (int i = n; i>=0; i--)
#define pb(c, e) c.push_back(e)

template<typename T> void print_container(T c) {
	
	tr (c, itr) {
		cout << *itr << " ";
	}
	cout << endl;
} 

// int main() {
// 	vi v{{1, 5, 3, 2}};
// 	printC(v);
// }