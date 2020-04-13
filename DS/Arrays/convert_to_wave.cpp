#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> vi;
#define tr(c, itr) for(auto itr = c.begin(); itr != c.end(); itr++)

template<typename T> void printC(vector<T>& v) {
	tr(v, itr) {
		cout << *itr << " ";
	} 
	cout << endl;
} 

template<typename T> void convertToWave(vector<T>& v){
    
    int n = v.size();

    if (n == 1) {
        return;
    }
    
    int i = 0;
    while (i < n-1) {
        swap(v[i], v[i+1]);
        i+=2;
    }

}

int main() {
	vi v{{1, 2, 3, 4, 5, 6, 7, 8}};
	convertToWave(v);
	printC(v);
}
