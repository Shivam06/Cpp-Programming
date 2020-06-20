#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int T;
	cin>>T;
	string s;
	for (int i = 0; i < T; i++) {
	    cin>>s;
	    unordered_map<char, int> M;
	    
	    if (s.length() <= 1) {
	        cout << "YES" << endl;
	        continue;
	    }
	    
	    int mid = s.length()/2;
	    for (int i = 0; i < mid; i++) {
	        if (M.find(s[i]) == M.end()) {
	            M[s[i]] = 0;
	        }
	        M[s[i]]++;
	    }
	    
	    if (s.length()%2 == 1)
	        mid+=1;
	    bool flag =true;
	    for (int i = mid; i < s.length(); i++) {

	        if (M.find(s[i]) == M.end() || M[s[i]] <= 0) {
	            flag = false;
	            break;
	        }
	                
	        M[s[i]]--;
	    }
	    
	    if (flag) {
	        cout << "YES" << endl;
	        continue;
	    }
	    
	    cout << "NO" << endl;
	}
	return 0;
}
