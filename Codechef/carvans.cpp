#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    
    for (int i = 0; i < T; i++) {
        
        int N;
        cin>>N;
        int min = INT_MAX;
        int count = 0;
        for (int j = 0; j < N; j++) {
            int num;
            cin>>num;
            if (num > min)
                continue;
            count++;
            min = num;
        }
        
        cout << count << endl;
    }
	return 0;
}
