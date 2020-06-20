#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int trailing_zeros(int N) {
    int orig = 0;
    
    int power = 1;
    while (1) {
        int ans = N/pow(5,power++);
        if (ans == 0)
            break;
        orig += ans;
    }
    
    return orig;
}

int main() {
	int T;
	cin>>T;
	
	for (int i = 0; i < T; i++) {
	    int N;
	    cin>>N;
	    cout << trailing_zeros(N) << endl;
	}
	return 0;
}
