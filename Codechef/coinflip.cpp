#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	
	for (int i = 0; i < T; i++) {
	    
	    int G;
	    cin>>G;
	    
	    for (int j = 0; j < G; j++) {
	        int I, N, Q;
	        cin>>I;
	        cin>>N;
	        cin>>Q;
	        
	        if (N%2==0 || I == Q) {
	            cout << N/2 << endl;
	            continue;
	        }
	        
	        cout << N/2 + 1 << endl;
	    }
	}
	return 0;
}
