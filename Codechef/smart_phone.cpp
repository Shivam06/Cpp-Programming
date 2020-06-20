#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	
	int N;
	cin>>N;
	vector<long long> v;
	for (int i = 0; i < N; i++) {
	    long long num;
	    cin>>num;
	    v.push_back(num);
	}
	
	sort(v.begin(), v.end());
	
	long long max_val = 0;
	
	for (int i = 0; i < v.size(); i++) {
	    long long val = v[i]*(v.size()-i);
	    if (val > max_val) {
	        max_val = val;
	    }
	}
	
	cout << max_val << endl;
	return 0;
}
